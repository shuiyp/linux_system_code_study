#include <stdio.h>


int max (int x, int y)
{
	if (x > y) {
		return x;
	}
	return y;
}

int (*pFunc)(int, int);// 指向函数指针变量的定义形式

int funcB (int b)
{
	printf("funcB: %d\n", b);
	return 0;
}

int funcC (int c)
{
	printf("funcC: %d\n", c);
	return 0;
}

int funcA (int a, int (*pCallFunc)(int) )
{
	int PA = 3;
	int PB = 4;
	
	printf("This is funcA function!\n");
	pCallFunc(a);
	pCallFunc(PA);
	pCallFunc(PB);

	return 0;
}

int main (int argc, char *argv[])
{
	int max_val = 0;

	printf("This is function pointer example!\n");

	max_val = max(5, 6);
	printf("max function excute value is %d\n", max_val);

	// 这是通常用的方法，我们也可以定义一个函数指针，通过指针来调用这个函数
	pFunc = max;// 将函数的入口地址赋给函数指针变量
	max_val = pFunc(7, 8);
	printf("*pFunc function excute value is %d\n", max_val);

	// 回调函数
	// 函数指针变量常见的用途之一是把指针作为参数传递到其它函数，指向函数的指针也可以作为参数，以实现函数地址的传递
	funcB(10);
	funcA(20, funcB);
	funcA(30, funcC);

	system("pause");
	return 0;
}