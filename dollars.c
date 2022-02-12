#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

int
main(int argc, char *argv[])
{
	double price = 0;
	if (argc != 2) {
		printf("Usage: %s <lowest price>\n", argv[0]);
		return -1;
	}
	price = 1.0/3;
	printf("price:%lf\n",price);
	return 0;
}
























