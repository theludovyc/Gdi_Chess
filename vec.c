struct Vec{
	unsigned char x;
	unsigned char y;
};
typedef struct Vec Vec;

void Vec_set(Vec *v, unsigned char x, unsigned char y){
	(*v).x = x;
	(*v).y = y;
}

void Vec_setX(Vec *v, unsigned char x){
	(*v).x = x;
}

void Vec_setY(Vec *v, unsigned char y){
	(*v).y = y;
}

void Vec_addX(Vec *v, unsigned char x){
	if((255-(*v).x)>=x){
		(*v).x += x;
		return;
	}
}

void Vec_addY(Vec *v, unsigned char y){
	if((255-(*v).y)>=y){
		(*v).y += y;
		return;
	}
}

void Vec_subX(Vec *v, unsigned char x){
	if((*v).x>=x){
		(*v).x-=x;
		return;
	}
}

void Vec_subY(Vec *v, unsigned char y){
	if((*v).y>=y){
		(*v).y-=y;
		return;
	}
}

unsigned char Vec_equal0(Vec v, unsigned char x, unsigned char y){
	if(v.x == x && v.y == y){
		return 1;
	}

	return 0;
}

unsigned char Vec_equal(Vec v, Vec v1){
	if(v.x == v1.x && v.y == v1.y){
		return 1;
	}
	return 0;
}