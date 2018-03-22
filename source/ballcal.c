 // 
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

int originx;
int originy;

int width_bg;
int height_bg;

int startbrick_y;
int width_ball;
int height_ball;
int width_paddle;
int height_paddle;
int width_brick;
int height_brick;
int width_Vborder;
int height_Vborder;
int width_Hborder;
int height_Hborder;

int width_bggame;
int height_bggame;

int paddlegap;
int brickgap;


int prevslowballx;
int prevslowbally;
int slowballx;
int slowbally;

int paddlex;
int paddley;
int prevballx;
int prevbally;
int ballx;
int bally;
int stop=0;
int dx=2;
int dy=2;
int miny[10];
int gamestate;
int width_gameover=256;
int height_gameover=256;
/* To represent the memory of the tile of the game
 =0: no element
= 10: paddle outside; 11 paddle inside
= 2 ball
= 3 value pack 1
= 4 value pack 2

= 6 brick 1 ( the easiest to break) - white brick
= 7 brick 2 ( the medium harness) - hit one time become 1 -green brick
= 8 brick 3 (the hardest) - hit one time, the level is reduced by one-- red brick
= 9 the brick boundary


* */
int gamearray[20][30];



void drawball(int x, int y, int lx, int ly);
void clearball(int x, int y, int lx, int ly);
void clearbrick(int x, int y, int lx, int ly);
void DrawPixel(int x, int y, int color);
void drawgreenbrick(int x, int y, int lx, int ly);
void drawwhitebrick(int x, int y, int lx, int ly);
void printmemory();
int convert_x(int x);
int convert_y(int y);
  
  void initialize_gamearray(){
	  for (int i=0;i<20; i++){
		  for (int j=0; j<30;j++)
		  {
			  gamearray[i][j]=0;
			  if ((i==0) || (i==19)) gamearray[i][j]=9;
			  if (i==18) gamearray[i][j]=11;
		  }
	  }
  }
 // return 0 if none of the point violate; return 1 if the next point violate
  void drawgameover(int x, int y, int lx, int ly){
 	
 	int offset_color=0;
 	int color=0;
 
 	for (int i=0;i<ly;i++){
 		for (int j=0; j<lx; j++){
 			color=return_gameover(offset_color);
 			DrawPixel(x+j,y+i,color);
 			offset_color+=4;
 		}
 	}
 	
 }
int reversex(int indexx){
	int a=indexx/3;
	return (originx+a*96);
 }
int reversey(int indexy){
	 
	return (originy+indexy*32);
 }
 // Draw the ball movement
 void moveball(int startx, int starty){
	
		
		clearball(prevballx,prevbally,width_ball,height_ball);
		drawball(ballx,bally,width_ball,height_ball);
<<<<<<< HEAD
		//printmemory();

		
		int xball_in=convert_x(ballx);
		int yball_in=convert_y(bally);
		int next_xball;
		int next_yball;
		if (dx<0) next_xball=convert_x(ballx+dx);
		if (dx>0) next_xball=convert_x(ballx+dx+width_ball);
		if (dy<0) next_yball=convert_y(bally+dy);
		if (dy>0) next_yball=convert_y(bally+dy+height_ball);

		if ((next_xball<=0) || (next_xball>29)) {
			printf(" touch left x index=%d y index=%d \n",next_xball,next_yball);
=======
		
		if ((ballx+dx>originx+width_bggame-width_ball) ||(ballx+dx<originx)){
>>>>>>> 157f5236c3db418e5e87fdef8682f13005305fa5
			dx=-dx;
		}
		if ((next_yball >17)&&(gamearray[next_yball][next_xball]==0)){
				gamestate=1;
				printf("STOP\n");
				drawgameover(originx+width_bg/2-width_gameover/2,originy+height_bg/2-height_gameover/2,width_gameover,height_gameover);
		}
		if(gamearray[next_yball][next_xball]==6){
			printf("Touch brick\n");

			int a=reversex(next_xball);
			int b=reversey(next_yball);
			printf(" index=%d  indey=%d\n",a,b);
			 clearbrick(reversex(next_xball),reversey(next_yball),width_brick,height_brick);
			 dy=-dy;
		}
		if(gamearray[next_yball][next_xball]==7){
			clearbrick(reversex(next_xball),reversey(next_yball),width_brick,height_brick);
			drawwhitebrick(reversex(next_xball),reversey(next_yball),width_brick,height_brick);//draw white bricks
			 dy=-dy;
		}
		if(gamearray[yball_in][next_xball]==8){
			 clearbrick(reversex(next_xball),reversey(next_yball),width_brick,height_brick);
			drawgreenbrick(reversex(next_xball),reversey(next_yball),width_brick,height_brick);	//draw green bricks
			dy=-dy;
		}
		if((gamearray[next_yball][next_xball]==9) && (next_yball==0)){
			dy=-dy;
		}
		if((gamearray[next_yball][next_xball]==9) && (next_yball>17)){
				
				gamestate=1;
				printf("STOP\n");
				drawgameover(originx+width_bg/2-width_gameover/2,originy+height_bg/2-height_gameover/2,width_gameover,height_gameover);
		}
		// at the edge of the paddle
		if (gamearray[next_yball][next_xball]==10)
			{
				printf("In edge\n");
				dy=-2;
				
			}
<<<<<<< HEAD
			// at middle of the paddle
		if (gamearray[next_yball][next_xball]==11){
				printf("In middle\n");
				dy=-4;

		}

=======
			clearbrick(brickx,bricky,width_brick,height_brick);
						

				slowballx = brickx;
				slowbally,prevslowbally = bricky;
				printf("BRICK X: %d\n", brickx);
				printf("BRICK Y: %d\n", bricky);

			
		}
		clearslowball(slowballx,prevslowbally,width_brick,height_brick);
		drawslowball(slowballx,slowbally,width_brick,height_brick);
		prevslowbally= slowbally;
		slowbally += 1;
>>>>>>> 157f5236c3db418e5e87fdef8682f13005305fa5
		
		delay(5);
		prevballx = ballx;
		prevbally = bally;
		ballx+=dx;
		bally+=dy;
	
 }
