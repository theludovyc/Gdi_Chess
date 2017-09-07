#define uchar unsigned char
#define uint unsigned int

#define null NULL

unsigned int getStringLength(const char *c){
	unsigned int i = 0;

	while(c[i] != '\0'){
		i++;
	}

	return i;
}