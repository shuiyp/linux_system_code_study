#include <stdio.h>
#include <time.h>



// char *ctime(const time_t *timep)  // 将时间转换为字符串格式
// struct tm *gmtime(const time_t *timep)  // 将时间转化为格林威治时间， 以 tm 结构存储
// char *asctime(const struct tm *tm)  // 将时间转化为字符格式
// struct tm *localtime(const time_t *clock)  // 将时间转化为本地时间

int main (int agrc, char *agrv[])
{
	time_t utc_time;
	struct tm *tblock;

	time(&utc_time);
	printf("UTC time is : 0x%x\n", utc_time);
	
	sleep(1);
	
	utc_time = time(NULL);
	printf("UTC time is : 0x%x\n", utc_time);

	sleep(1);
	printf("ctime/timep is %s\n", ctime(&utc_time));

	tblock = gmtime(&utc_time);
}