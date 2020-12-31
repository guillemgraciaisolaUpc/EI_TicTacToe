#include <Wire.h>
#include <Adafruit_SSD1306.h>

// Buttons
#define down_   2
#define up_     3
#define right_  4
#define left_   5
#define accept_ 6

// Display
#define xpixels_  128
#define ypixels_  64
Adafruit_SSD1306 display(xpixels_, ypixels_, &Wire, -1);

// Game
#define rows_     5
#define columns_  6
int tabletop [rows_][columns_];
int player_victories;
int AI_victories;

// Misc
#define WIN_   1000
#define LOSS_ -1000

#define INIT_   0
#define START_  1
#define PLAYER_ 2
#define AI_     3
int state;
int x;
int y;

struct legalMove {
  int posx;
  int posy;
};
legalMove legalMoves [rows_ * columns_];

void setup() {
  Serial.begin(9600);

  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);
  display.clearDisplay();
  display.setTextColor(WHITE);
  display.display();

  pinMode(up_, INPUT);
  pinMode(down_, INPUT);
  pinMode(right_, INPUT);
  pinMode(left_, INPUT);
  pinMode(accept_, INPUT);

  state = INIT_;
}

void loop() {
  switch (state) {
    case INIT_:
      player_victories = 0;
      AI_victories = 0;
      x = 0;
      y = 0;

      //Serial.println("PLAYER -- X");
      //Serial.println("AI -- O");
      display.setCursor(20, 16);
      display.println("PLAYER -- X");
      display.setCursor(20, 26);
      display.println("AI -- O");
      display.display();
      delay(1500);

      state = START_;
      break;

    case START_:
      initTabletop(*tabletop, rows_, columns_);
      printGame(*tabletop, rows_, columns_);
      if (random(100) < 50) {
        state = PLAYER_;
      } else {
        state = AI_;
      }
      break;

    case PLAYER_:
      if (digitalRead(up_) == HIGH) {
        if (y == 0) {
          y = rows_ - 1;
        } else {
          y -= 1;
        }
        moveCursor(*tabletop, rows_, columns_, x, y);
        delay(200);
      } else if (digitalRead(down_) == HIGH) {
        if (y == (rows_ - 1)) {
          y = 0;
        } else {
          y += 1;
        }
        moveCursor(*tabletop, rows_, columns_, x, y);
        delay(200);
      } else if (digitalRead(right_) == HIGH) {
        if (x == (columns_ - 1)) {
          x = 0;
        } else {
          x += 1;
        }
        moveCursor(*tabletop, rows_, columns_, x, y);
        delay(200);
      } else if (digitalRead(left_) == HIGH) {
        if (x == 0) {
          x = columns_ - 1;
        } else {
          x -= 1;
        }
        moveCursor(*tabletop, rows_, columns_, x, y);
        delay(200);
      }

      if (digitalRead(accept_) == HIGH) {
        if (getValue(*tabletop, rows_, columns_, x, y) != 32) {
          display.setCursor(90, 20);
          display.println("SQUARE");
          display.setCursor(90, 40);
          display.println("TAKEN");
          display.display();
        } else {
          placeX(*tabletop, rows_, columns_, x, y);
          printGame(*tabletop, rows_, columns_);
          if (detWiner(*tabletop, rows_, columns_, 'X') == false) {
            state = AI_;
          } else if (boardIsFull(*tabletop, rows_, columns_) == true) {
            display.setCursor(90, 20);
            display.println("TIES!");
            display.display();
            delay(2000);
            state = START_;
          } else {
            player_victories ++;
            display.setCursor(90, 20);
            display.println("PLAYER");
            display.setCursor(90, 40);
            display.println("WINS");
            display.display();
            delay(2000);
            state = START_;
          }
        }
      }
      break;

    case AI_:
      delay(500);
      MinMaxAB(*tabletop, rows_, columns_, 0, LOSS_, WIN_);
      if (detWiner(*tabletop, rows_, columns_, 'O') == false) {
        state = PLAYER_;
      } else if (boardIsFull(*tabletop, rows_, columns_) == true) {
        display.setCursor(90, 20);
        display.println("TIES!");
        display.display();
        delay(2000);
        state = START_;
      } else {
        AI_victories ++;
        display.setCursor(90, 20);
        display.println("AI");
        display.setCursor(90, 40);
        display.println("WINS");
        display.display();
        delay(2000);
        state = START_;
      }
      break;
  }
}

// returns square value
char getValue(int *a, int rows, int columns, int x, int y) {
  return a[y * columns + x];
}

// Initialize blank tabletop
void initTabletop(int *a, int rows, int columns) {
  for (int i = 0; i < rows; ++i) {
    for (int j = 0; j < columns; ++j) {
      a[i * columns + j] = ' ';
    }
  }
}

// Prints tabletop
void printGame(int *a, int rows, int columns) {
  display.clearDisplay();
  display.setCursor(0, 0);
  display.print("PLAYER: ");
  display.print(player_victories);
  display.setCursor(80, 0);
  display.print("AI: ");
  display.print(AI_victories);

  for (int i = 0; i < rows; ++i) {
    display.setCursor(0, (i * 10) + 16);
    display.print ("|");
    for (int j = 0; j < columns; ++j) {
      //Serial.print ((char) a[i * columns + j]);
      //Serial.print ("|");

      display.print((char) a[i * columns + j]);
      display.print("|");
    }
    //Serial.println();
    display.println();  
  }
  display.display();
  //Serial.println();
  //Serial.println();
}

// moves cursor
void moveCursor(int *a, int rows, int columns, int x, int y) {
  int val = a[y * columns + x];
  a[y * columns + x] = '_';
  printGame(a, rows, columns);
  a[y * columns + x] = val;
}

// places X
void placeX(int *a, int rows, int columns, int x, int y) {
  a[y * columns + x] = 'X';
}

// places O
void placeO(int *a, int rows, int columns, int x, int y) {
  a[y * columns + x] = 'O';
}

boolean boardIsFull(int *a, int rows, int columns) {
  for (int i = 0; i < rows; ++i) {
    for (int j = 0; j < columns; ++j) {
      if (a[i * columns + j] == ' ') {
        return false;
      }
    }
  }
  return true;
}

// determines winner
boolean detWiner(int *a, int rows, int columns, char marker) {
  for (int i = 0; i < rows; ++i) {
    for (int j = 0; j < columns; ++j) {
      if (a[i * columns + j] == marker) {
        //look right
        if (a[i * columns + (j + 1)] == marker) {
          //look right
          if (a[i * columns + (j + 2)] == marker) {
            return true;
          }
          //look left
          else if (a[i * columns + (j - 1)] == marker) {
            return true;
          }
        }
        //look left
        else if (a[i * columns + (j - 1)] == marker) {
          //look left
          if (a[i * columns + (j - 2)] == marker) {
            return true;
          }
        }
        //look down
        else if (a[(i + 1)*columns + j] == marker) {
          //look down
          if (a[(i + 2)*columns + j] == marker) {
            return true;
          }
          //look up
          else if (a[(i - 1)*columns + j] == marker) {
            return true;
          }
        }
        //look up
        else if (a[(i - 1)*columns + j] == marker) {
          //look up
          if (a[(i - 2)*columns + j] == marker) {
            return true;
          }
        }
        //look diagonal down
        else if (a[(i - 1)*columns + (j - 1)] == marker) {
          if (a[(i + 1)*columns + (j + 1)] == marker) {
            return true;
          }
        }
        //look diagonal up
        else if (a[(i + 1)*columns + (j - 1)] == marker) {
          if (a[(i - 1)*columns + (j + 1)] == marker) {
            return true;
          }
        }
      }
    }
  }
  return false;
}

// MinMax algorithm with Alpha Beta pruning
void MinMaxAB(int *a, int rows, int columns, int depth, int alpha, int beta) {
  //Init best move
  int bestScore;
  //If leaf node hit, return the best score and move
  if (boardIsFull(a, rows, columns) == true || detWiner(a, rows, columns, 'X') == true || detWiner(a, rows, columns, 'O') == true) {
    
  }
  //Algorithm
  for (int i = 0; i < getLegalMoves(a, rows, columns); i++) {
    int currentx = legalMoves[i].posx;
    int currenty = legalMoves[i].posy;
  }
}

int getLegalMoves(int *a, int rows, int columns) {
  int count = 0;
  for (int i = 0; i < rows; ++i) {
    for (int j = 0; j < columns; ++j) {
      if (a[i * columns + j] == ' ') {
        legalMoves[count].posx = j;
        legalMoves[count].posy = i;
        count ++;
      }
    }
  }
  return count;
}

//https://github.com/GeorgeSeif/Tic-Tac-Toe-AI/blob/master/Source.cpp
//https://stackabuse.com/minimax-and-alpha-beta-pruning-in-python/
