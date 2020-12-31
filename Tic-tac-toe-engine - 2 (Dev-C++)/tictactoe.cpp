#include <stdio.h>
#include <stdlib.h>
#define MPLAYER 'o'
#define N  6  /* N*N board */
#define NM 30
#define FLOAT_MAX 1000.0
int p=0;
char win3 ( char * board )
{

 if  ( ( board[0]=='x' )&& ( board[1]=='x' ) && ( board[2]=='x' ) ) return 'x';
 if  ( ( board[0]=='x' )&& ( board[3]=='x' ) && ( board[6]=='x' ) ) return 'x';
 if  ( ( board[0]=='x' )&& ( board[4]=='x' ) && ( board[8]=='x' ) ) return 'x';
 if  ( ( board[1]=='x' )&& ( board[4]=='x' ) && ( board[7]=='x' ) ) return 'x';
 if  ( ( board[2]=='x' )&& ( board[4]=='x' ) && ( board[6]=='x' ) ) return 'x';
 if  ( ( board[2]=='x' )&& ( board[5]=='x' ) && ( board[8]=='x' ) ) return 'x';
 if  ( ( board[3]=='x' )&& ( board[4]=='x' ) && ( board[5]=='x' ) ) return 'x';
 if  ( ( board[6]=='x' )&& ( board[7]=='x' ) && ( board[8]=='x' ) ) return 'x';

 if  ( ( board[0]=='o' )&& ( board[1]=='o' ) && ( board[2]=='o' ) ) return 'o';
 if  ( ( board[0]=='o' )&& ( board[3]=='o' ) && ( board[6]=='o' ) ) return 'o';
 if  ( ( board[0]=='o' )&& ( board[4]=='o' ) && ( board[8]=='o' ) ) return 'o';
 if  ( ( board[1]=='o' )&& ( board[4]=='o' ) && ( board[7]=='o' ) ) return 'o';
 if  ( ( board[2]=='o' )&& ( board[4]=='o' ) && ( board[6]=='o' ) ) return 'o';
 if  ( ( board[2]=='o' )&& ( board[5]=='o' ) && ( board[8]=='o' ) ) return 'o';
 if  ( ( board[3]=='o' )&& ( board[4]=='o' ) && ( board[5]=='o' ) ) return 'o';
 if  ( ( board[6]=='o' )&& ( board[7]=='o' ) && ( board[8]=='o' ) ) return 'o';

 return '*';
}
char win6 ( char * board)
{
   if  ( ( board[0 ]=='x' )&& ( board[6 ]=='x' ) && ( board[12]=='x' ) ) return 'x';
   if  ( ( board[6 ]=='x' )&& ( board[12]=='x' ) && ( board[18]=='x' ) ) return 'x';
   if  ( ( board[12]=='x' )&& ( board[18]=='x' ) && ( board[24]=='x' ) ) return 'x';
   if  ( ( board[1 ]=='x' )&& ( board[7 ]=='x' ) && ( board[13]=='x' ) ) return 'x';
   if  ( ( board[7 ]=='x' )&& ( board[13]=='x' ) && ( board[19]=='x' ) ) return 'x';
   if  ( ( board[13]=='x' )&& ( board[19]=='x' ) && ( board[25]=='x' ) ) return 'x';
   if  ( ( board[2 ]=='x' )&& ( board[8 ]=='x' ) && ( board[14]=='x' ) ) return 'x';
   if  ( ( board[8 ]=='x' )&& ( board[14]=='x' ) && ( board[20]=='x' ) ) return 'x';
   if  ( ( board[14]=='x' )&& ( board[20]=='x' ) && ( board[26]=='x' ) ) return 'x';
   if  ( ( board[3 ]=='x' )&& ( board[9 ]=='x' ) && ( board[15]=='x' ) ) return 'x';
   if  ( ( board[9 ]=='x' )&& ( board[15]=='x' ) && ( board[21]=='x' ) ) return 'x';
   if  ( ( board[15]=='x' )&& ( board[21]=='x' ) && ( board[27]=='x' ) ) return 'x';
   if  ( ( board[4 ]=='x' )&& ( board[10]=='x' ) && ( board[16]=='x' ) ) return 'x';
   if  ( ( board[10]=='x' )&& ( board[16]=='x' ) && ( board[22]=='x' ) ) return 'x';
   if  ( ( board[16]=='x' )&& ( board[22]=='x' ) && ( board[28]=='x' ) ) return 'x';
   if  ( ( board[5 ]=='x' )&& ( board[11]=='x' ) && ( board[17]=='x' ) ) return 'x';
   if  ( ( board[11]=='x' )&& ( board[17]=='x' ) && ( board[23]=='x' ) ) return 'x';
   if  ( ( board[17]=='x' )&& ( board[23]=='x' ) && ( board[29]=='x' ) ) return 'x';
   if  ( ( board[0 ]=='x' )&& ( board[1 ]=='x' ) && ( board[2 ]=='x' ) ) return 'x';
   if  ( ( board[1 ]=='x' )&& ( board[2 ]=='x' ) && ( board[3 ]=='x' ) ) return 'x';
   if  ( ( board[2 ]=='x' )&& ( board[3 ]=='x' ) && ( board[4 ]=='x' ) ) return 'x';
   if  ( ( board[3 ]=='x' )&& ( board[4 ]=='x' ) && ( board[5 ]=='x' ) ) return 'x';
   if  ( ( board[6 ]=='x' )&& ( board[7 ]=='x' ) && ( board[8 ]=='x' ) ) return 'x';
   if  ( ( board[7 ]=='x' )&& ( board[8 ]=='x' ) && ( board[9 ]=='x' ) ) return 'x';
   if  ( ( board[8 ]=='x' )&& ( board[9 ]=='x' ) && ( board[10]=='x' ) ) return 'x';
   if  ( ( board[9 ]=='x' )&& ( board[10]=='x' ) && ( board[11]=='x' ) ) return 'x';
   if  ( ( board[12]=='x' )&& ( board[13]=='x' ) && ( board[14]=='x' ) ) return 'x';
   if  ( ( board[13]=='x' )&& ( board[14]=='x' ) && ( board[15]=='x' ) ) return 'x';
   if  ( ( board[14]=='x' )&& ( board[15]=='x' ) && ( board[16]=='x' ) ) return 'x';
   if  ( ( board[15]=='x' )&& ( board[16]=='x' ) && ( board[17]=='x' ) ) return 'x';
   if  ( ( board[18]=='x' )&& ( board[19]=='x' ) && ( board[20]=='x' ) ) return 'x';
   if  ( ( board[19]=='x' )&& ( board[20]=='x' ) && ( board[21]=='x' ) ) return 'x';
   if  ( ( board[20]=='x' )&& ( board[21]=='x' ) && ( board[22]=='x' ) ) return 'x';
   if  ( ( board[21]=='x' )&& ( board[22]=='x' ) && ( board[23]=='x' ) ) return 'x';
   if  ( ( board[24]=='x' )&& ( board[25]=='x' ) && ( board[26]=='x' ) ) return 'x';
   if  ( ( board[25]=='x' )&& ( board[26]=='x' ) && ( board[27]=='x' ) ) return 'x';
   if  ( ( board[26]=='x' )&& ( board[27]=='x' ) && ( board[28]=='x' ) ) return 'x';
   if  ( ( board[27]=='x' )&& ( board[28]=='x' ) && ( board[29]=='x' ) ) return 'x';
   if  ( ( board[12]=='x' )&& ( board[19]=='x' ) && ( board[26]=='x' ) ) return 'x';
   if  ( ( board[6 ]=='x' )&& ( board[13]=='x' ) && ( board[20]=='x' ) ) return 'x';
   if  ( ( board[13]=='x' )&& ( board[20]=='x' ) && ( board[27]=='x' ) ) return 'x';
   if  ( ( board[0 ]=='x' )&& ( board[7 ]=='x' ) && ( board[14]=='x' ) ) return 'x';
   if  ( ( board[7 ]=='x' )&& ( board[14]=='x' ) && ( board[21]=='x' ) ) return 'x';
   if  ( ( board[14]=='x' )&& ( board[21]=='x' ) && ( board[28]=='x' ) ) return 'x';
   if  ( ( board[1 ]=='x' )&& ( board[8 ]=='x' ) && ( board[15]=='x' ) ) return 'x';
   if  ( ( board[8 ]=='x' )&& ( board[15]=='x' ) && ( board[22]=='x' ) ) return 'x';
   if  ( ( board[15]=='x' )&& ( board[22]=='x' ) && ( board[29]=='x' ) ) return 'x';
   if  ( ( board[2 ]=='x' )&& ( board[9 ]=='x' ) && ( board[16]=='x' ) ) return 'x';
   if  ( ( board[9 ]=='x' )&& ( board[16]=='x' ) && ( board[23]=='x' ) ) return 'x';
   if  ( ( board[3 ]=='x' )&& ( board[10]=='x' ) && ( board[17]=='x' ) ) return 'x';
   if  ( ( board[2 ]=='x' )&& ( board[7 ]=='x' ) && ( board[12]=='x' ) ) return 'x';
   if  ( ( board[8 ]=='x' )&& ( board[13]=='x' ) && ( board[18]=='x' ) ) return 'x';
   if  ( ( board[3 ]=='x' )&& ( board[8 ]=='x' ) && ( board[13]=='x' ) ) return 'x';
   if  ( ( board[14]=='x' )&& ( board[19]=='x' ) && ( board[24]=='x' ) ) return 'x';
   if  ( ( board[9 ]=='x' )&& ( board[14]=='x' ) && ( board[19]=='x' ) ) return 'x';
   if  ( ( board[14]=='x' )&& ( board[4 ]=='x' ) && ( board[9 ]=='x' ) ) return 'x';
   if  ( ( board[5 ]=='x' )&& ( board[10]=='x' ) && ( board[15]=='x' ) ) return 'x';
   if  ( ( board[10]=='x' )&& ( board[15]=='x' ) && ( board[20]=='x' ) ) return 'x';
   if  ( ( board[15]=='x' )&& ( board[20]=='x' ) && ( board[25]=='x' ) ) return 'x';
   if  ( ( board[16]=='x' )&& ( board[21]=='x' ) && ( board[26]=='x' ) ) return 'x';
   if  ( ( board[11]=='x' )&& ( board[16]=='x' ) && ( board[21]=='x' ) ) return 'x';
   if  ( ( board[17]=='x' )&& ( board[22]=='x' ) && ( board[27]=='x' ) ) return 'x';


   if  ( ( board[0 ]=='o' )&& ( board[6 ]=='o' ) && ( board[12]=='o' ) ) return 'o';
   if  ( ( board[6 ]=='o' )&& ( board[12]=='o' ) && ( board[18]=='o' ) ) return 'o';
   if  ( ( board[12]=='o' )&& ( board[18]=='o' ) && ( board[24]=='o' ) ) return 'o';
   if  ( ( board[1 ]=='o' )&& ( board[7 ]=='o' ) && ( board[13]=='o' ) ) return 'o';
   if  ( ( board[7 ]=='o' )&& ( board[13]=='o' ) && ( board[19]=='o' ) ) return 'o';
   if  ( ( board[13]=='o' )&& ( board[19]=='o' ) && ( board[25]=='o' ) ) return 'o';
   if  ( ( board[2 ]=='o' )&& ( board[8 ]=='o' ) && ( board[14]=='o' ) ) return 'o';
   if  ( ( board[8 ]=='o' )&& ( board[14]=='o' ) && ( board[20]=='o' ) ) return 'o';
   if  ( ( board[14]=='o' )&& ( board[20]=='o' ) && ( board[26]=='o' ) ) return 'o';
   if  ( ( board[3 ]=='o' )&& ( board[9 ]=='o' ) && ( board[15]=='o' ) ) return 'o';
   if  ( ( board[9 ]=='o' )&& ( board[15]=='o' ) && ( board[21]=='o' ) ) return 'o';
   if  ( ( board[15]=='o' )&& ( board[21]=='o' ) && ( board[27]=='o' ) ) return 'o';
   if  ( ( board[4 ]=='o' )&& ( board[10]=='o' ) && ( board[16]=='o' ) ) return 'o';
   if  ( ( board[10]=='o' )&& ( board[16]=='o' ) && ( board[22]=='o' ) ) return 'o';
   if  ( ( board[16]=='o' )&& ( board[22]=='o' ) && ( board[28]=='o' ) ) return 'o';
   if  ( ( board[5 ]=='o' )&& ( board[11]=='o' ) && ( board[17]=='o' ) ) return 'o';
   if  ( ( board[11]=='o' )&& ( board[17]=='o' ) && ( board[23]=='o' ) ) return 'o';
   if  ( ( board[17]=='o' )&& ( board[23]=='o' ) && ( board[29]=='o' ) ) return 'o';
   if  ( ( board[0 ]=='o' )&& ( board[1 ]=='o' ) && ( board[2 ]=='o' ) ) return 'o';
   if  ( ( board[1 ]=='o' )&& ( board[2 ]=='o' ) && ( board[3 ]=='o' ) ) return 'o';
   if  ( ( board[2 ]=='o' )&& ( board[3 ]=='o' ) && ( board[4 ]=='o' ) ) return 'o';
   if  ( ( board[3 ]=='o' )&& ( board[4 ]=='o' ) && ( board[5 ]=='o' ) ) return 'o';
   if  ( ( board[6 ]=='o' )&& ( board[7 ]=='o' ) && ( board[8 ]=='o' ) ) return 'o';
   if  ( ( board[7 ]=='o' )&& ( board[8 ]=='o' ) && ( board[9 ]=='o' ) ) return 'o';
   if  ( ( board[8 ]=='o' )&& ( board[9 ]=='o' ) && ( board[10]=='o' ) ) return 'o';
   if  ( ( board[9 ]=='o' )&& ( board[10]=='o' ) && ( board[11]=='o' ) ) return 'o';
   if  ( ( board[12]=='o' )&& ( board[13]=='o' ) && ( board[14]=='o' ) ) return 'o';
   if  ( ( board[13]=='o' )&& ( board[14]=='o' ) && ( board[15]=='o' ) ) return 'o';
   if  ( ( board[14]=='o' )&& ( board[15]=='o' ) && ( board[16]=='o' ) ) return 'o';
   if  ( ( board[15]=='o' )&& ( board[16]=='o' ) && ( board[17]=='o' ) ) return 'o';
   if  ( ( board[18]=='o' )&& ( board[19]=='o' ) && ( board[20]=='o' ) ) return 'o';
   if  ( ( board[19]=='o' )&& ( board[20]=='o' ) && ( board[21]=='o' ) ) return 'o';
   if  ( ( board[20]=='o' )&& ( board[21]=='o' ) && ( board[22]=='o' ) ) return 'o';
   if  ( ( board[21]=='o' )&& ( board[22]=='o' ) && ( board[23]=='o' ) ) return 'o';
   if  ( ( board[24]=='o' )&& ( board[25]=='o' ) && ( board[26]=='o' ) ) return 'o';
   if  ( ( board[25]=='o' )&& ( board[26]=='o' ) && ( board[27]=='o' ) ) return 'o';
   if  ( ( board[26]=='o' )&& ( board[27]=='o' ) && ( board[28]=='o' ) ) return 'o';
   if  ( ( board[27]=='o' )&& ( board[28]=='o' ) && ( board[29]=='o' ) ) return 'o';
   if  ( ( board[12]=='o' )&& ( board[19]=='o' ) && ( board[26]=='o' ) ) return 'o';
   if  ( ( board[6 ]=='o' )&& ( board[13]=='o' ) && ( board[20]=='o' ) ) return 'o';
   if  ( ( board[13]=='o' )&& ( board[20]=='o' ) && ( board[27]=='o' ) ) return 'o';
   if  ( ( board[0] =='o' )&& ( board[7 ]=='o' ) && ( board[14]=='o' ) ) return 'o';
   if  ( ( board[7 ]=='o' )&& ( board[14]=='o' ) && ( board[21]=='o' ) ) return 'o';
   if  ( ( board[14]=='o' )&& ( board[21]=='o' ) && ( board[28]=='o' ) ) return 'o';
   if  ( ( board[1 ]=='o' )&& ( board[8 ]=='o' ) && ( board[15]=='o' ) ) return 'o';
   if  ( ( board[8 ]=='o' )&& ( board[15]=='o' ) && ( board[22]=='o' ) ) return 'o';
   if  ( ( board[15]=='o' )&& ( board[22]=='o' ) && ( board[29]=='o' ) ) return 'o';
   if  ( ( board[2 ]=='o' )&& ( board[9 ]=='o' ) && ( board[16]=='o' ) ) return 'o';
   if  ( ( board[9 ]=='o' )&& ( board[16]=='o' ) && ( board[23]=='o' ) ) return 'o';
   if  ( ( board[3 ]=='o' )&& ( board[10]=='o' ) && ( board[17]=='o' ) ) return 'o';
   if  ( ( board[2 ]=='o' )&& ( board[7 ]=='o' ) && ( board[12]=='o' ) ) return 'o';
   if  ( ( board[8 ]=='o' )&& ( board[13]=='o' ) && ( board[18]=='o' ) ) return 'o';
   if  ( ( board[3 ]=='o' )&& ( board[8 ]=='o' ) && ( board[13]=='o' ) ) return 'o';
   if  ( ( board[14]=='o' )&& ( board[19]=='o' ) && ( board[24]=='o' ) ) return 'o';
   if  ( ( board[9 ]=='o' )&& ( board[14]=='o' ) && ( board[19]=='o' ) ) return 'o';
   if  ( ( board[14]=='o' )&& ( board[4 ]=='o' ) && ( board[9 ]=='o' ) ) return 'o';
   if  ( ( board[5 ]=='o' )&& ( board[10]=='o' ) && ( board[15]=='o' ) ) return 'o';
   if  ( ( board[10]=='o' )&& ( board[15]=='o' ) && ( board[20]=='o' ) ) return 'o';
   if  ( ( board[15]=='o' )&& ( board[20]=='o' ) && ( board[25]=='o' ) ) return 'o';
   if  ( ( board[16]=='o' )&& ( board[21]=='o' ) && ( board[26]=='o' ) ) return 'o';
   if  ( ( board[11]=='o' )&& ( board[16]=='o' ) && ( board[21]=='o' ) ) return 'o';
   if  ( ( board[17]=='o' )&& ( board[22]=='o' ) && ( board[27]=='o' ) ) return 'o';

return '*';
}

char win ( char * board )
{
 if (N==3) return win3( board );
 if (N==6) return win6( board );
 
}

char turn (char player)
{
   if (player=='o') return 'x';
   else return 'o';
}

int my_deterministic_move ( char *board, char player, int free)
{
   int i;

   if ( (free) ) {
    while (board[i]!='*') i++;
    return i;
   }
   return -1;
}

int my_random_move ( char *board, char player, int free)
{
   int i, j;
   int random_pos;
   j=rand() % free;   
   if ( free ) {
    // jump to random_pos-th free position 
        while (board[j]!='*') {
        	j=rand() % free;
		}
    return j;
   }
   return -1;
}


int my_minmax_move ( char *board, char player, int level, int free, float *cost, int max, int mvs)
{
   	char new_board[NM];
   	int op=0;
   	float sign=(max)?-1.0:1.0;
   	(*cost) = sign * FLOAT_MAX;
   	float max_cost, levelf=((float) level);
   	int new_move[NM];
   	float cost_paths[NM];
   	char new_player;
   	char winner;
   	int i=0, j=0, k=0,h=0,g=40;
   	float value;
   	int MAX_LEVEL = 5 + mvs; // dynamic prunning
   
   	for (i=0; i< NM; i++){
    	new_board[i]= board[i];
   	}
   
   	for (i = 0; i < free; i++) {
   	
      	if (i)  { /* restart last position */
         	new_board[j] = '*';
         	j++;
      	}
      
      	while (new_board[j] != '*') j++;
      	new_move[i] = j;
     	new_board[j] = player;
      	winner=win (new_board);
      
      	switch (winner) {
         	case 'o':// If the machine player wins Eval(movei, levelj)+= k1/f(levelj) 
            	(*cost) += 1/level; 
            	if (level == 1) g=j;
         		break;
         	case 'x':// If the machine player losses Eval (movei, levelj)-= k2/f(levelj)             
            	(*cost)-= 3/level;
            	if (level == 2) p=j;
         		break;
         	case '*':// If not a final position, obtain Eval from evaluating the next level
            	new_player=turn (player);
           	 	if (level == MAX_LEVEL){ //if depth tree is enough, stop increasing levels 
               		(*cost)=0; break;
            	} else {
            		value = sign * FLOAT_MAX;
            		my_minmax_move ( new_board, new_player, level+1, free-1, &value, (max)?0:1, mvs);
            	}
         		break;
      	}
      
      	if (max) {if (value>(*cost)) (*cost)=value;}
      	else     {if (value<(*cost)) (*cost)=value;}
      
	  	if (level == 1) {
         	cost_paths[i] = value; 
      	} 
 	}

   	max_cost = cost_paths[0]; //search which position has the highest value

   	for(k=0; k<free; k++){
      	if (cost_paths[k]>= max_cost){
        	op=new_move[k];

         	if(cost_paths[k]== cost_paths[0]) h++;
         	max_cost= cost_paths[k];
      	}
   	}

	if (h==free)	op=my_random_move(board,player,free); 
	if(p!=40&&p>=0)	op=p; 
	if(g!=40&&g>=0)	op=g;
   	return op;
}

void move (char *board, char player, int free, int move)
{
  int i;
  float cost;
  int max;
  if (player=='x') {  /* your turn */
        do {
        fprintf (stdout, "\nChoose a free square: ");
        fscanf(stdin, "%d",&i);
      i--;
   } while (board[i]!='*');

  }
  else {   /* my turn */
   fprintf (stdout, "\nNow is my turn. Let think perfectly...\n\n");
   p=40;
   i=my_minmax_move (board, player, 1, free, &cost, 1, move);
   fprintf (stdout, "\nI choose the square %d\n", i+1);
  }
  board[i]=player;
}


void display (char *board)
{
  int i;
  fprintf (stdout, "\nThe board is...\n ");
  fprintf (stdout,"\n");
  if (N==3) {
        for (i=0; i<3; i++)fprintf(stdout, " %c |", (board[i]=='*')? 49+i:board[i]);
        fprintf (stdout, "\n------------\n");
        for (i=3; i<6; i++) fprintf(stdout, " %c |", (board[i]=='*')? 49+i:board[i]);
        fprintf (stdout, "\n------------\n");
        for (i=6; i<9; i++) fprintf(stdout, " %c |", (board[i]=='*')? 49+i :board[i]);
  }
  if (N==4) {
        for (i=0; i<4; i++)fprintf(stdout, " %c |", (board[i]=='*')? 49+i:board[i]);
        fprintf (stdout, "\n----------------\n");
        for (i=4; i<8; i++) fprintf(stdout, " %c |", (board[i]=='*')? 49+i:board[i]);
        fprintf (stdout, "\n----------------\n");
        for (i=8; i<12; i++) fprintf(stdout, " %c |", (board[i]=='*')? 49+i :board[i]);
        fprintf (stdout, "\n----------------\n");
        for (i=12; i<16; i++) fprintf(stdout, " %c |", (board[i]=='*')? 49+i :board[i]);
        fprintf (stdout, "\n----------------\n");

  }
  if (N==6) {
         for (i=0; i<6; i++) fprintf(stdout, " %c%c |", (board[i]=='*')? 49+i:board[i], 255);
        fprintf (stdout, "\n------------------------------\n");
        for (i=6; i<9; i++) fprintf(stdout, " %c%c |", (board[i]=='*')? 49+i:board[i],255);
        for (i=9; i<12; i++) fprintf(stdout, " %c%c |", (board[i]=='*')? 49:255, (board[i] == '*')? 39+i:board[i]);
        fprintf (stdout, "\n------------------------------\n");
        for (i=12; i<18; i++) fprintf(stdout, " %c%c |", (board[i]=='*')? 49:255, (board[i] == '*')? 39+i:board[i]);
        fprintf (stdout, "\n------------------------------\n");
        for (i=18; i<19; i++) fprintf(stdout, " %c%c |", (board[i]=='*')? 49:255, (board[i] == '*')? 39+i:board[i]);
        for (i=19; i<24; i++) fprintf(stdout, " %c%c |", (board[i]=='*')? 50:255, (board[i] == '*')? 29+i:board[i]);
        fprintf (stdout, "\n------------------------------\n");
        for (i=24; i<29; i++) fprintf(stdout, " %c%c |", (board[i]=='*')? 50:255, (board[i] == '*')? 29+i:board[i]);
        fprintf(stdout, " %c%c |", (board[i]=='*')? 51:255, (board[i] == '*')? 19+i:board[i]);
        fprintf (stdout, "\n------------------------------\n");
  }
  fprintf (stdout,"\n\n");
}


main ()
{
   char board [NM];   /* Board */
   char player;      /* Current player */
   int i;
   char winner;
   char key;
   int free;         /* No. of free squares */
   int mvs=0;
   int gana=0;
   fprintf (stdout,"\nYour (almost) perfect tic-tac-toe player.\n");
   fprintf (stdout,"\nby Guillem Gracia I Sola\n");
   do {
        for (i=0; i<NM; ++i) board[i]='*';
        winner=player='*';

        while (player=='*') {
                fprintf (stdout, "\nWho starts (1=me)(2=you)? : ");
                fscanf(stdin, "%d",&i);

         switch (i) {
                case 1: player='o';break;
                case 2: player='x'; break;
         };
       }
       display( board );

       for (free=NM; ((free>0) && (winner=='*')); free--) {
        move( board, player, free, mvs);
        display( board );
        player = turn ( player );
        winner= win ( board );
        if (player=='o' && gana){ mvs= mvs + 1; gana=0;} //Increase the prunning in 1 every 2 'o' turns
        else if (player == 'o' && gana!=1) gana=1;
       }

      switch (winner) {
        case 'o': fprintf(stdout, "\n I won effortlessly!\n"); break;
        case 'x': fprintf(stdout, "\n This would be impossible if I was not almost perfect! You won!\n"); break;
        case '*': fprintf(stdout, "\n Draw!\n"); break;
      };
      fprintf (stdout, "\nAnother (y/n)?");
      fscanf(stdin, "%c",&key);
      fscanf(stdin, "%c",&key);
      mvs=0;
      gana=0;
   } while ( ( key!='n' ) && ( key!='N' ) );

}

