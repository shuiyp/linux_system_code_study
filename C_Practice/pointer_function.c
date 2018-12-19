#include <stdio.h>


long *ReadNum (int x)
{
	long numBuf[5] = { 0, 1, 2, 3, 4 };

	if (x < 0)
	{
		return &numBuf[0];
	}
	if (x > 5)
	{
		return &numBuf[4];
	}
	return &numBuf[x];
}

int main (int argc, char *argv[])
{
	int i = 0;

	printf("This is pointer function example!\n");

	for (i = 0; i < 5; i++) {
		printf("int *ReadNum function return value is %ld\n", *ReadNum(i) );
	}
	
	for (i = 0; i < 5; i++) {
		printf("int *ReadNum function return address is %ld\n", ReadNum(i) );
	}
}
