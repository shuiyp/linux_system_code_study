#include <stdio.h>
#include <unistd.h>
#include <time.h>



// char *ctime(const time_t *timep)  // 将时间转换为字符串格式
// struct tm *gmtime(const time_t *timep)  // 将时间转化为格林威治时间， 以 tm 结构存储
// char *asctime(const struct tm *tm)  // 将时间转化为字符格式
// struct tm *localtime(const time_t *clock)  // 将时间转化为本地时间

// struct tm
//{
//	int tm_sec;     /* seconds (0 - 60) */
//   	int tm_min;     /* minutes (0 - 59) */
//   	int tm_hour;    /* hours (0 - 23) */
//	int tm_mday;    /* day of month (1 - 31) */
//    int tm_mon;     /* month of year (0 - 11) */
//    int tm_year;    /* year - 1900 */
//    int tm_wday;    /* day of week (Sunday = 0) */
//    int tm_yday;    /* day of year (0 - 365) */
//    int tm_isdst;   /* is summer time in effect? */
//    char *tm_zone;  /* abbreviation of timezone name */
//    long tm_gmtoff; /* offset from UTC in seconds */
//};


int main (int agrc, char *agrv[])
{
	time_t utc_time;
	struct tm *tblock;

	time(&utc_time);
	printf("UTC time is : %ld\n", utc_time);
	
	sleep(1);
	utc_time = time(NULL);
	printf("UTC time is : %ld\n", utc_time);

	sleep(1);
	utc_time = time(NULL);
	printf("ctime/timep is %s\n", ctime(&utc_time));

	sleep(1);
	utc_time = time(NULL);
	tblock = gmtime(&utc_time);// 这个时间个格林威治时间 不是本地时间
	printf("gmtime tm_sec = %d, tm_min = %d, tm_hour = %d, tm_mday = %d, tm_mon = %d, tm_year = %d, tm_wday = %d, tm_yday = %d\n", 
		    tblock->tm_sec, tblock->tm_min, tblock->tm_hour, tblock->tm_mday, tblock->tm_mon, tblock->tm_year, tblock->tm_wday, tblock->tm_yday);

	sleep(1);
	utc_time = time(NULL);
	printf("localtime is %s\n", asctime(localtime(&utc_time) ) );
}