// this file will be used to test functions in screen.c

#include <stdio.h>
#include <unistd.h>
#include "screen.h"
#include "comm.h"
//#include "sound.h"

int main(void){
	Position cur = getscreensize();   // get screensize
	char postdata[100];
	//sprintf(postdata, "row=%d&col=%d",cur.row, cur.col);
	sprintf(postdata, "row=%d&col=%d&id=e1800915", cur.row, cur.col);
	//printf("%s\n", postdata);
	sendpost(URL, postdata);
	gotoXY(1,1);
	printf("Screen size: row=%d, col=%d\n", cur.row, cur.col);
	printf("Today we will make some animation. Press any key to continue\n");
	getchar();    // wait for the user to press a key
	getchar();
	int ff,bb;
	float step = (float)cur.col/cur.row;
	for (int i=1; i<=cur.row; i++) {
	//for(int i=1; i<21; i++){
	
		ff = (i+1)%8+BLACK;
		bb = (i+2)%8+BLACK;
		setcolors(ff, bg(bb));
        clearscreen();
        drawrect(10, 10, 5, 30);
        //gotoXY(21-i, (i-1)*4+1);
        gotoXY(cur.row-i, (i-1)*step+1);
        
        printf("HELLO\n");
		usleep(250000);  
		//sleep(1); 
	}
	getchar();
	resetcolors();
	clearscreen();
	printf("color is set back to default\n");
	getchar();
	//FILE *fp = fopen("test.wav", "r"); // open the file in read-only
	//WAVheader h = readwavhdr(fp);
	//fclose(fp);
	//displaywavhdr(h);

/*
	setfgcolor(CYAN);
	gotoXY(14, 35);
	printf("HELLO, WORLD!\n");
	getchar();    // wait for the user too press a key
	drawbar(30, 30);
	drawbar(50, 30);
	getchar();     // after drawing bars, wait for a key
	resetcolor();
	printf("This text is displayed in default color\n");

*/
}
