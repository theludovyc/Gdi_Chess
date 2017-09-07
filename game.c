#include <stdio.h>
#include <stdlib.h>

#include "helper.c"
#include "drawHelper.c"
#include "vec.c"
#include "entity.c"

#define platX 8
#define playY 8

#define  tab_Entity_lenght 64
static Entity tab_Entity[tab_Entity_lenght];

static uchar affKey = 0;

static uchar buffer[4];
static uchar buffer_index = 0;

static const char *info;
static uchar affInfo = 0;

static uchar instError = 0;

static uchar playerCol = 0;

/*
0 't','c','f','r','d','f','c','t',
8 'p','p','p','p','p','p','p','p',
16 '.','.','.','.','.','.','.','.',
24 '.','.','.','.','.','.','.','.',
32 '.','.','.','.','.','.','.','.',
40 '.','.','.','.','.','.','.','.',
48 'p','p','p','p','p','p','p','p',
56 't','c','f','d','r','f','c','t'
*/

void init(){
	Entity_set(&tab_Entity[0], 6, 0);
	Entity_set(&tab_Entity[1], 5, 0);
	Entity_set(&tab_Entity[2], 4, 0);
	Entity_set(&tab_Entity[3], 2, 0);
	Entity_set(&tab_Entity[4], 3, 0);
	Entity_set(&tab_Entity[5], 4, 0);
	Entity_set(&tab_Entity[6], 5, 0);
	Entity_set(&tab_Entity[7], 6, 0);


	uchar col = 0;

	for(uint i=0; i<8; i++){
		Entity_set(&tab_Entity[8+i], 1, 0);

		for(uint j=0; j<4; j++){
			if(j%2==0){
				if(i%2==0){
					col=0;
				}else{
					col=1;
				}
			}else{
				if(i%2==0){
					col=1;
				}else{
					col=0;
				}
			}

			Entity_set(&tab_Entity[((j+2)*platX)+i], 0, col);
		}

		Entity_set(&tab_Entity[48+i], 1, 1);
	}

	Entity_set(&tab_Entity[56], 6, 1);
	Entity_set(&tab_Entity[57], 5, 1);
	Entity_set(&tab_Entity[58], 4, 1);
	Entity_set(&tab_Entity[59], 2, 1);
	Entity_set(&tab_Entity[60], 3, 1);
	Entity_set(&tab_Entity[61], 4, 1);
	Entity_set(&tab_Entity[62], 5, 1);
	Entity_set(&tab_Entity[63], 6, 1);
}

void onUp(){

}

void onDown(){

}

void onLeft(){

}

void onRight(){

}

void onHelp(){

}

uchar chekInstError(uchar uc){
	uchar index = buffer[0]*playY+(uc);

	if(Entity_getType(tab_Entity[index])==0){
		affInfo=1;
		info="C'est une case !";
		instError = 1;
		return 1;
	}else if(Entity_getCol(tab_Entity[index])!=playerCol){
		affInfo = 1;
		info="Ce n'est pas votre pion!";
		instError = 1;
		return 1;
	}

	return 0;
}

void onKey(uchar wParam){
	if(wParam==0x08){
		if(buffer_index>0){
			instError = 0;
			buffer_index--;
		}
		return;
	}else if(wParam==0x0D){
		if(buffer_index==4){
			uchar index_target = buffer[2]*playY+buffer[3];
			uchar index_base = buffer[0]*playY+buffer[1];
			uchar col;

			tab_Entity[index_target] = tab_Entity[index_base];

			if(buffer[0]%2==0){
				if(buffer[1]%2==0){
					col=0;
				}else{
					col=1;
				}
			}else{
				if(buffer[1]%2==0){
					col=1;
				}else{
					col=0;
				}
			}
				
			Entity_set(&tab_Entity[index_base], 0, col);

			affInfo=1;
			info="nouveau tour!";

			playerCol=!playerCol;

			buffer_index=0;
		}
	}else{
		if(wParam>=49 && wParam<=49+7){
			if(buffer_index==1){
				buffer[buffer_index]=wParam-49;
				buffer_index++;

				if(chekInstError(wParam-49)){
					return;
				}
			}else if(buffer_index == 2){
				if(instError>0){
					instError=0;
					buffer[buffer_index-1]=wParam-49;

					if(chekInstError(wParam-49)){
						return;
					}
				}
			}else if(buffer_index == 3){
				buffer[buffer_index]=wParam-49;
				buffer_index++;
			}
		}else if(wParam>=65 && wParam<=65+7){
			if(instError>0){
				instError = 0;
				buffer_index=0;
			}

			if(buffer_index == 0){
				buffer[buffer_index]=wParam-65;
				buffer_index++;
			}else if(buffer_index == 2){
				buffer[buffer_index]=wParam-65;
				buffer_index++;
			}
		}else{
			affKey=wParam;
		}
	}
}

void draw(HDC memHdc){
	SetTextColor(memHdc, RGB(128, 128, 128));
	for(uint i=0; i<8; i++){
		drawChar(memHdc, 10+i*10, 0, '0'+i+1);
		drawChar(memHdc, 0, 13+i*13, 'a'+i);
	}

	for(uint j=0; j<playY; j++){
		for(uint i=0; i<platX; i++){
			Entity_draw(memHdc, tab_Entity[(j*platX)+i], i, j);
		}
	}

	SetTextColor(memHdc, RGB(255, 255, 255));
	if(buffer_index>3){
		drawChar(memHdc, 3*10, 13*10, buffer[3]+49);
	}

	if(buffer_index>2){
		drawChar(memHdc, 2*10, 13*10, buffer[2]+97);
	}

	if(buffer_index>1){
		drawChar(memHdc, 1*10, 13*10, buffer[1]+49);
	}

	if(buffer_index>0){
		drawChar(memHdc, 0*10, 13*10, buffer[0]+97);
	}

	if(affInfo>0){
		drawString(memHdc, 0, 13*11, info);
		affInfo=0;
	}

	if(affKey > 0){
		drawBin(memHdc, 0, 0, affKey);
		affKey = 0;
	}
}