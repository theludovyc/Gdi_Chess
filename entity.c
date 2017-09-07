/*
type:
0: case
1: pion
2: roi
3: dame
4: fou
5: cavalier
6: tour

col:
0: rouge
1: blanc
*/

struct Entity{
	unsigned char tycol;
};
typedef struct Entity Entity;

void Entity_set(Entity *e, uchar type, uchar col){
	(*e).tycol = (type<<4)|col;
}

uchar Entity_getCol(Entity e){
	return (e.tycol&0x0F);
}

uchar Entity_getType(Entity e){
	return (e.tycol>>4);
}

void Entity_draw(HDC memHdc, Entity e, uchar posX, uchar posY){
	uchar symbol;

	switch(Entity_getType(e)){
		case 0:
			symbol='.';
		break;

		case 1:
			symbol='p';
		break;

		case 2:
			symbol='r';
		break;

		case 3:
			symbol='d';
		break;

		case 4:
			symbol='f';
		break;

		case 5:
			symbol='c';
		break;

		case 6:
			symbol='t';
		break;
	}

	switch(Entity_getCol(e)){
		case 0:
			SetTextColor(memHdc, RGB(255,255,255));
		break;

		case 1:
			SetTextColor(memHdc, RGB(255,0,0));
		break;
	}

	drawChar(memHdc, posX*10+10, posY*13+13, symbol);
}