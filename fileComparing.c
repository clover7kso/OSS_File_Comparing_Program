#include <stdio.h>
#include <sys.types.h>
#include <sys.stat.h>
#include <unistd.h>
#include <time.h>

struct stat stat1, stat2;
struct tm *time1, *time2;

void filestat1(void);
void filestat2(void);
void filetime1(void);
void filetime2(void);
void sizecmp(void);
void blockcmp(void);
void datecmp(void);
void timecmp(void);

int main(void)
{
	filestat1();
	filestat2();
	filetime1();
	filetime2();
	sizecmp();
	blockcmp();
	datecmp();
	timecmp();
}

void filestat1(void)
{
	stat("text1", &stat1);
}

void filestat2(void)
{
	stat("text2", &stat2);
}

void filetime1(void)
{
	time1 = *localtime(&stat1.st_mtime);
}

void filetime2(void)
{
	time2 = *localtime(&stat2.st_mtime);
}

void sizecmp(void)
{
}

void blockcmp(void)
{
}

void datecmp(void)
{
	if(time1.tm_mon>time2.tm_mon)
   	{
      		printf("text2 date is earlier\n");
   	}
   	else if(time2.tm_mon>time1.tm_mon)
   	{
      		printf("text1 date is earlier\n");
   	}
   	else
   	{
      		if(time1.tm_mday>time2.tm_mday)
      		{
         		printf("text2 date is earlier\n");
      		}
      		else if(time2.tm_mday>time1.tm_mday)
      		{
         		printf("text1 date is earlier\n");
      		}
      		else
      		{
         		printf("same date\n");
      		}
   	}
}

void timecmp(void)
{
	if(time1.tm_hour>time2.tm_hour)
   	{
      		printf("text2 time is earlier\n");
   	}
   	else if(time2.tm_hour>time1.tm_hour)
   	{
      		printf("text1 time is earlier\n");
   	}
   	else
   	{
      		if(time1.tm_min>time2.tm_min)
      		{
         		printf("text2 time is earlier\n");
      		}
      		else if(time2.tm_min>time1.tm_min)
      		{
         		printf("text1 time is earlier\n");
      		}
      		else
      		{
         		printf("same time\n");
      		}
   	}
}

