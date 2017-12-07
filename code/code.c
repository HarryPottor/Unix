#include "apue.h"

static void charatatime(char *);

int main(int argc, char const *argv[])
{
	pid_t pid;
	if ((pid = fork()) < 0)
	{
		err_sys("fork error");
	}
	else if (pid == 0)
	{
		charatatime("output from child\n");
	}
	else 
	{
		charatatime("OUTPUT FROM PARENT\n");
	}

	return 0;
}


static void charatatime(char* str)
{
	char* ptr = str;
	int c;
	setbuf(stdout, NULL);
	for (ptr = str; (c = *ptr++) != 0;)
	{
		putc(c, stdout);
	}
}