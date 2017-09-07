void drawChar(HDC memHdc, unsigned int posX, unsigned int posY, const char c){
	TextOut(memHdc,posX,posY,&c,1);
}

void drawBin(HDC memHdc, unsigned int posX, unsigned int posY, unsigned char c){
	unsigned int i;

	if(c>127){
		c-=128;
		
		drawChar(memHdc, posX, posY, '1');

		if(c==0){
			for(i=0;i<7;i++){
				drawChar(memHdc, posX+(10*(i+1)), posY, '0');
			}
			return;
		}
	}else{
		drawChar(memHdc, posX, posY, '0');
	}

	if(c>63){
		c-=64;

		drawChar(memHdc, posX+10, posY, '1');

		if(c==0){
			for(i=0;i<6;i++){
				drawChar(memHdc, posX+(10*(i+2)), posY, '0');
			}
			return;
		}
	}else{
		drawChar(memHdc, posX+10, posY, '0');
	}

	if(c>31){
		c-=32;

		drawChar(memHdc, posX+20, posY, '1');

		if(c==0){
			for(i=0;i<5;i++){
				drawChar(memHdc, posX+(10*(i+3)), posY, '0');
			}
			return;
		}
	}else{
		drawChar(memHdc, posX+20, posY, '0');
	}

	if(c>15){
		c-=16;

		drawChar(memHdc, posX+30, posY, '1');

		if(c==0){
			for(i=0;i<4;i++){
				drawChar(memHdc, posX+(10*(i+4)), posY, '0');
			}
			return;
		}
	}else{
		drawChar(memHdc, posX+30, posY, '0');
	}

	if(c>7){
		c-=8;

		drawChar(memHdc, posX+40, posY, '1');

		if(c==0){
			for(i=0;i<3;i++){
				drawChar(memHdc, posX+(10*(i+5)), posY, '0');
			}
			return;
		}
	}else{
		drawChar(memHdc, posX+40, posY, '0');
	}

	if(c>3){
		c-=4;

		drawChar(memHdc, posX+50, posY, '1');

		if(c==0){
			for(i=0;i<2;i++){
				drawChar(memHdc, posX+(10*(i+6)), posY, '0');
			}
			return;
		}
	}else{
		drawChar(memHdc, posX+50, posY, '0');
	}

	if(c>1){
		c-=2;

		drawChar(memHdc, posX+60, posY, '1');

		if(c==0){
			for(i=0;i<1;i++){
				drawChar(memHdc, posX+(10*(i+7)), posY, '0');
			}
			return;
		}
	}else{
		drawChar(memHdc, posX+60, posY, '0');
	}

	if(c>0){
		c-=1;

		drawChar(memHdc, posX+70, posY, '1');

		return;
	}else{
		drawChar(memHdc, posX+70, posY, '0');
	}
}

void drawString(HDC memHdc, unsigned int posX, unsigned int posY, const char *c){
	TextOut(memHdc, posX, posY, c, getStringLength(c));
}