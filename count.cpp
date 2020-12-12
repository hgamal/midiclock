#include <stdio.h>
#include <time.h>
#include <sys/time.h>
#include <string.h>


unsigned long utime()
{

	struct timeval tp;
	gettimeofday(&tp, NULL);
	return tp.tv_sec * 1000000 + tp.tv_usec;
}


int main(int ac, char **av)
{
	char buffer[64];

	unsigned long x = utime();
	int count = 0;
	while(char *p = fgets(buffer, sizeof(buffer), stdin)) {
		int c = strlen(p);
		if (c>1)
			buffer[c-1] = '\0';

		if (strcmp(p, "F8") == 0) {
			if (++count == 24) {
				count = 0;
				unsigned long y = utime();
				printf("%lu       \r", 60000000UL / (y-x));
				fflush(stdout);
				x = y;
			}

		}
	}

	return 0;
}
