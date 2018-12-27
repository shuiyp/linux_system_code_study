#include <stdio.h>

/*
	时间换空间
	问题：
	在一个由自然数 1-1000中某些数字所组成的数组中，每个数字可能出现零次或者多次。
	设计一个算法，找出出现次数最多的数字
*/

void search (int a[], int len)
{
	int sp[1000] = {0};
	int i = 0;
	int max = 0;

	for (i = 0; i < len; i++)
	{//遍历数组，求出每一个数字出现的次数，然后记录下来
		int index = a[i] - 1;

		sp[index]++;
	}

	for (i = 0; i < 1000; i++)
	{//扫描数组求出最大数
		if (max < sp[i])
		{
			max = sp[i];
		}
	}

	for (i = 0; i < 1000; i++)
	{// 打印数字最多的
		if (max == sp[i])
		{
			printf("数字出现次数最多的是 %d, 一共出现了 %d 次\n", i+1, sp[i]);
		}
	}
}


int main (int argc, char *argv[])
{
	int array[] = {1, 1, 3, 4, 5, 6, 6, 6, 2, 3};

	printf("sizeof(array)/sizeof(*array) = %ld\n", sizeof(array)/sizeof(*array));
	printf("sizeof(array)/sizeof(int) = %ld\n", sizeof(array)/sizeof(int));

	search(array, sizeof(array)/sizeof(*array));

	return 0;
}