#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>

void DrawPixel(int x, int y, int color);
int return_bg(int offset_color);
int return_ball(int offset_color);
int return_redbrick(int offset_color);
int return_bluebrick(int offset_color);
int return_greenbrick(int offset_color);
int return_border1(int offset_color);
int return_border2(int offset_color);
int return_whitebrick(int offset_color);
int return_paddle(int offset_color);
int return_upleftedge(int offset_color);
int return_uprightedge(int offset_color);
int return_bottomleftedge(int offset_color);
int return_bottomrightedge(int offset_color);
int return_gameinterface(int offset_color);
int return_quitgame(int offset_color);
int return_quitgame2(int offset_color);
int return_startgame(int offset_color);
int return_startgame2(int offset_color);

 void moveball(int startx, int starty);
 void drawgameinterface(int x, int y, int lx, int ly);
 void drawstart(int x, int y, int lx, int ly) ;
 void drawstart2(int x, int y, int lx, int ly)  ;
 void initialize_gamearray();


//int originx=500;
//int originy=100;
int originx=50;
int originy=50;

int width_bg=960;
int height_bg=640;

int background = 000000377;

int startbrick_y=90;

// one ball is one element size 32x32
// one brick is three element size
// one paddle is 4 element size
// one value pack is 2 element size?


int width_ball=32; 
int height_ball=32; 
int width_paddle=128; 
int height_paddle=32; 
int width_brick=96; 
int height_brick=32; 
int width_Vborder=32; 
int height_Vborder=160; 
int width_Hborder=160; 
int height_Hborder=32; 

int width_bggame=960; 
int height_bggame=640;

int paddlegap=64;		//paddle distance from bottom
int brickgap=32;		//distance of bricks from the top

int paddlex;
int paddley;
int ballx;
int bally;
int miny[10];
int gamestate=0;
int gamearray[20][30];

// Size of ball is 20x20
void drawball(int x, int y, int lx, int ly){
	int offset_color=0;
	int color=0;
	for (int i=0;i<ly;i++){
		for (int j=0; j<lx; j++){
			color=return_ball(offset_color);
			DrawPixel(x+j,y+i,color);
			offset_color+=4;
		}
	}
	// assign memory value
	int indexx=convert_x(x);
	int indexy=convert_y(y);
	gamearray[indexy][indexx]=2;
	
}

void clearball(int x, int y, int lx, int ly){
	
	
	int offset_color=0;
	int color=0;

	for (int i=0;i<ly;i++){
		for (int j=0; j<lx; j++){
			color=background;
			DrawPixel(x+j,y+i,color);
			offset_color+=4;
		}
	}
		// assign memory value
	int indexx=convert_x(x);
	int indexy=convert_y(y);
	gamearray[indexy][indexx]=0;
	
}


void drawslowball(int x, int y, int lx, int ly){
	int offset_color=0;
	int color=0;
	for (int i=0;i<ly;i++){
		for (int j=0; j<lx; j++){
			color=return_bigpaddle(offset_color);
			DrawPixel(x+j,y+i,color);
			offset_color+=4;
		}
	}
	
}

void clearslowball(int x, int y, int lx, int ly){
	
	int offset_color=0;
	int color=0;

	for (int i=0;i<ly;i++){
		for (int j=0; j<lx; j++){
			color=background;
			DrawPixel(x+j,y+i,color);
			offset_color+=4;
		}
	}
	
}

// size of paddle is 80x20
void drawpaddle(int x, int y, int lx, int ly){

	int offset_color=0;
	int color=0;

	for (int i=0;i<ly;i++){
		for (int j=0; j<lx; j++){
			color=return_paddle(offset_color);
			DrawPixel(x+j,y+i,color);
			offset_color+=4;
		}
	}
		// assign memory value
	int indexx=convert_x(x);
	int indexy=convert_y(y);
	gamearray[indexy][indexx]=10;
	gamearray[indexy][indexx+1]=11;
	gamearray[indexy][indexx+2]=11;
	gamearray[indexy][indexx+3]=10;
}

void clearpaddle(int x, int y, int lx, int ly){
	
	//	te();
		
	int offset_color=0;
	int color=0;

	for (int i=0;i<ly;i++){
		for (int j=0; j<lx; j++){
			//color=background;
			color =background;
			DrawPixel(x+j,y+i,color);
			offset_color+=4;
		}
	}
		// assign memory value
	int indexx=convert_x(x);
	int indexy=convert_y(y);
	for (int i=0; i<4; i++){
		gamearray[indexy][indexx+i]=0;
	}
	
}


void drawredbrick(int x, int y, int lx, int ly){
	
	//	te();
		
	int offset_color=0;
	int color=0;

	for (int i=0;i<ly;i++){
		for (int j=0; j<lx; j++){
			color=return_redbrick(offset_color);
			DrawPixel(x+j,y+i,color);
			offset_color+=4;
		}
	}
		// assign memory value
	int indexx=convert_x(x);
	int indexy=convert_y(y);
	for (int i=0; i<3; i++){
		gamearray[indexy][indexx+i]=8;
	}
}

void drawgreenbrick(int x, int y, int lx, int ly){
	
	//	te();
		
	int offset_color=0;
	int color=0;

	for (int i=0;i<ly;i++){
		for (int j=0; j<lx; j++){
			color=return_greenbrick(offset_color);
			DrawPixel(x+j,y+i,color);
			offset_color+=4;
		}
	}
		// assign memory value
	int indexx=convert_x(x);
	int indexy=convert_y(y);
	for (int i=0; i<3; i++){
		gamearray[indexy][indexx+i]=7;
	}
}


void drawbluebrick(int x, int y, int lx, int ly){
	
	//	te();
		
	int offset_color=0;
	int color=0;

	for (int i=0;i<ly;i++){
		for (int j=0; j<lx; j++){
			color=return_bluebrick(offset_color);
			DrawPixel(x+j,y+i,color);
			offset_color+=4;
		}
	}
		// assign memory value
	int indexx=convert_x(x);
	int indexy=convert_y(y);
	for (int i=0; i<3; i++){
		gamearray[indexy][indexx+i]=9;
	}
}

void drawwhitebrick(int x, int y, int lx, int ly){
	
	//	te();
		
	int offset_color=0;
	int color=0;

	for (int i=0;i<ly;i++){
		for (int j=0; j<lx; j++){
			color=return_whitebrick(offset_color);
			DrawPixel(x+j,y+i,color);
			offset_color+=4;
		}
	}
		// assign memory value
	int indexx=convert_x(x);
	int indexy=convert_y(y);
	for (int i=0; i<3; i++){
		gamearray[indexy][indexx+i]=6;
	}
}

void clearbrick(int x, int y, int lx, int ly){
	
	//	te();
		
	int offset_color=0;
	int color=0;

	for (int i=0;i<ly;i++){
		for (int j=0; j<lx; j++){
			//color=return_whitebrick(offset_color);
			color = background;
			DrawPixel(x+j,y+i,color);
			offset_color+=4;
		}
	}
		// assign memory value
	int indexx=convert_x(x);
	int indexy=convert_y(y);
	for (int i=0; i<3; i++){
		gamearray[indexy][indexx+i]=0;
	}
}

// Size of border is 100x20
void drawborderV(int x, int y, int lx, int ly){
	
	//	te();
		
	int offset_color=0;
	int color=0;

	for (int i=0;i<ly;i++){
		for (int j=0; j<lx; j++){
			color=return_border1(offset_color);
			DrawPixel(x+j,y+i,color);
			offset_color+=4;
		}
	}
	
}

// Size of border is 20x100
void drawborderH(int x, int y, int lx, int ly){
	
	//	te();
		
	int offset_color=0;
	int color=0;

	for (int i=0;i<ly;i++){
		for (int j=0; j<lx; j++){
			color=return_border2(offset_color);
			DrawPixel(x+j,y+i,color);
			offset_color+=4;
		}
	}
	
}


// Size of background is 20x20
void drawbg(int x, int y, int lx, int ly){
	
	//	te();
		
	int offset_color=0;
	int color=0;

	for (int i=0;i<ly;i++){
		for (int j=0; j<lx; j++){
			color=background;
			DrawPixel(x+j,y+i,color);
			offset_color+=4;
		}
	}
	
}

void draw_totalback(int startx, int starty, int lx, int ly, int increase){
	
	int startx1=startx;
	int starty1=starty;

	
	for (int j=0; j<20;j++){
		for (int i =0; i<30; i++){
			drawbg(startx1,starty1,lx,ly);
			
			startx1+=increase;
			
		}
		startx1=startx;
		
		starty1+=increase;
		
	}
}

void drawredb(int startx, int starty, int lx, int ly){
	int increase=0;
	for (int i=0; i<10;i++){
		drawredbrick(startx+increase,starty,lx,ly);
		increase+=lx;
	}
}

void drawgreenb(int startx, int starty, int lx, int ly){
	int increase=0;
	for (int i=1; i<11;i++){
		drawgreenbrick(startx+increase,starty,lx,ly);
		increase+=lx;
	}
}

void drawblueb(int startx, int starty, int lx, int ly){
	int increase=0;
	for (int i=1; i<11;i++){
		drawbluebrick(startx+increase,starty,lx,ly);
		increase+=lx;
	}
}

void drawwhiteb(int startx, int starty, int lx, int ly){
	int increase=0;
	for (int i=1; i<11;i++){
		drawwhitebrick(startx+increase,starty,lx,ly);
		increase+=lx;
	}
}

// Draw border Vertical
void drabdV(int startx, int starty, int lx, int ly){
	int increase=0;
	for (int i=0; i<4;i++){
		drawborderV(startx,starty+increase,lx,ly);
		increase+=ly;
	}
}

void drabdH(int startx, int starty, int lx, int ly){
	int increase=0;
	for (int i=1; i<7;i++){
		drawborderH(startx+increase,starty,lx,ly);
		increase+=lx;
	}
}

void leftmove(int speed){
	clearpaddle(paddlex,paddley,width_paddle,height_paddle);
	if (paddlex>originx) {
		if (speed==0) 	paddlex-=1;
		if (speed==1)	paddlex-=5;
		if (speed==2)	paddlex-=10;
		if (speed==3)	paddlex-=20;
	}
	if (paddlex<originx) paddlex=originx;
	drawpaddle(paddlex,paddley,width_paddle,height_paddle);
}

void rightmove(int speed){
	clearpaddle(paddlex,paddley,width_paddle,height_paddle);
	if (paddlex<(originx+width_bg-width_paddle)) {
		if (speed==0) 	paddlex+=1;
		if (speed==1)	paddlex+=5;
		if (speed==2)	paddlex+=10;
		if (speed==3)	paddlex+=20;	
	}
	if (paddlex>(originx+width_bggame-width_paddle)) paddlex=originx+width_bggame-width_paddle;
	drawpaddle(paddlex,paddley,width_paddle,height_paddle);
}

void drawedge1(int x, int y, int lx, int ly){
 	int offset_color=0;
 	int color=0;
 
 	for (int i=0;i<ly;i++){
 		for (int j=0; j<lx; j++){
 			color=return_upleftedge(offset_color);
 			DrawPixel(x+j,y+i,color);
 			offset_color+=4;
 		}
 	}
 	
 }
 
 
 void drawedge2(int x, int y, int lx, int ly){
 	int offset_color=0;
 	int color=0;
 	for (int i=0;i<ly;i++){
 		for (int j=0; j<lx; j++){
 			color=return_uprightedge(offset_color);
 			DrawPixel(x+j,y+i,color);
 			offset_color+=4;
 		}
 	}
 	
 }
 
 void drawedge3(int x, int y, int lx, int ly){
 	
 	int offset_color=0;
 	int color=0;
 
 	for (int i=0;i<ly;i++){
 		for (int j=0; j<lx; j++){
 			color=return_bottomleftedge(offset_color);
 			DrawPixel(x+j,y+i,color);
 			offset_color+=4;
 		}
 	}
 	
 }
 
 void drawedge4(int x, int y, int lx, int ly){
 	
 	int offset_color=0;
 	int color=0;
 
 	for (int i=0;i<ly;i++){
 		for (int j=0; j<lx; j++){
 			color=return_bottomrightedge(offset_color);
 			DrawPixel(x+j,y+i,color);
 			offset_color+=4;
 		}
 	}
 	
 }
 

void initialize_ymin(){
	for(int i=0; i<10; i++){
		miny[i]=originy+brickgap+height_brick*3;
		printf("min %d",miny[i]);
	}
	printf("\n");
}

// Convert from x and y in the real table to the 
int convert_x(int x){
	return ((x-originx)/32);
}

int convert_y(int y){
	return ((y-originx)/32);
}
void printmemory(){
	for(int i=0; i<20; i++){
		for (int j=0; j<30; j++){
			printf("%d ",gamearray[i][j]);
		}
		printf("\n");
	}
}

void draw(){
	
	
	initialize_gamearray();
	paddlex=originx+width_bggame/2-width_paddle/2;
	
	paddley=originy+height_bggame-paddlegap;
	ballx=originx+width_bggame/2-width_ball/2;
	bally=paddley-32;
	// pivot point is originx, originy meaning 0,0
	
	
	draw_totalback(originx,originy,32,32,32);
	


	drawredb(originx,originy+brickgap,width_brick,height_brick);				//draw red bricks	
	drawgreenb(originx,originy+brickgap+height_brick,width_brick,height_brick);	//draw green bricks
	drawwhiteb(originx,originy+brickgap+2*height_brick,width_brick,height_brick);//draw white bricks
	
	drawpaddle(paddlex,paddley,width_paddle,height_paddle);						//draw paddle @ start position
	drawball(ballx,bally,width_ball,height_ball);								//draw ball @ start position

	drabdH(originx,originy-height_Hborder,width_Hborder,height_Hborder);	//top border
	drabdV(originx-width_Vborder,originy,width_Vborder,height_Vborder);		//left border

	drabdH(originx,originy+height_bggame,width_Hborder,height_Hborder);		//bottom border
	drabdV(originx+width_bggame,originy,width_Vborder,height_Vborder);		//right border
	
	drawedge1(originx-32,originy-32,32,32);		
 	drawedge2(originx+width_bggame,originy-32,32,32);
 	drawedge3(originx-32,originy+height_bggame,32,32);
 	drawedge4(originx+width_bggame,originy+height_bggame,32,32);
	

	int button=0xFFFF;
	int check=0;
	int read=0;
	int count=0;
	int previousbutton=0;
	int speed=0;
	int startball=0;

	
	initialize_ymin();
	

	printmemory();


	while(gamestate==0){
		
		//printf("State %d\n",gamestate);

		while (check==0){
			// if B button is pressed- ball release
			//printf("State %d startball=%d check=%d\n",gamestate, startball, check);
			read=readSnes();
			if (read==65534){
				startball=1;
				
			}
			if (startball==1){

						//printf("In moving ball\n");
						moveball(ballx,bally);
						if(gamestate==1) check=1;

					
					//if (read != 65535) printf("%d\n",read);
					// left button
					if (read==65471){
						check=1;
						// speed is used to check if the button is pressed repeatedly
						speed=0;
						leftmove(speed);
						read=0xFFFF;
						speed=0;
					}
					// right button is clicked
					else if (read==65407){
						check=1;
						// speed is used to check if the button is pressed repeatedly
						speed=0;
						rightmove(speed);
						read=0xFFFF;
						speed=0;
					}

					// If A and right move is pressed
					else if (read==65151){
						if (previousbutton==read){
							count++;
							if ((count>=10) && (count<=20)) speed=1;
							if ((count>20)&& (count<=30)) speed=2;
							if (count>30)	speed=3;
						}
						if (previousbutton!=read) {
							count=0;
						}

						rightmove(speed);
						read=0xFFFF;
						speed=0;
						previousbutton=65151;	
					}
					// If A and left move is pressed
					else if (read==65215){
						if (previousbutton==read){
							count++;
							if ((count>=10) && (count<=20)) speed=1;
							if ((count>20)&& (count<=30)) speed=2;
							if (count>30)	speed=3;
						}
						if (previousbutton!=read) {
							count=0;
						}

						leftmove(speed);
						read=0xFFFF;
						speed=0;
						previousbutton=65215;	
					}

					delay(5);
						
			}

			
		}
		check=0;
	}
	
	
	//A- 65279
	//B- 65534
	//Select- 65531
	// Start-65527
	// up pad
	// down pad
	
	
}
