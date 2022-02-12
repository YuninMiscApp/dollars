#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

//输出颜色
#define COLOUR_NONE		"\e[0m"
#define COLOUR_BLACK	"\e[0;30m"
#define COLOUR_L_BLACK	"\e[1;30m"
#define COLOUR_RED		"\e[0;31m"
#define COLOUR_L_RED	"\e[1;31m"
#define COLOUR_GREEN	"\e[0;32m"
#define COLOUR_L_GREEN	"\e[1;32m"
#define COLOUR_BROWN	"\e[0;33m"
#define COLOUR_YELLOW	"\e[1;33m"
#define COLOUR_BLUE		"\e[0;34m"
#define COLOUR_L_BLUE	"\e[1;34m"
#define COLOUR_PURPLE	"\e[0;35m"
#define COLOUR_L_PURPLE	"\e[1;35m"
#define COLOUR_CYAN		"\e[0;36m"
#define COLOUR_L_CYAN	"\e[1;36m"
#define COLOUR_GRAY		"\e[0;37m"
#define COLOUR_WHITE	"\e[1;37m"


#define _MLOG_(_c_,_file_,_line_,args...)  ({\
	printf("%s[%s,%d]:",_c_,_file_,_line_);\
	printf(args);\
	printf("%s\n",COLOUR_NONE);\
})

#define MLOGV(args...)	_MLOG_(COLOUR_NONE, __FILE__, __LINE__, args)
#define MLOGD(args...)	_MLOG_(COLOUR_WHITE, __FILE__, __LINE__, args)
#define MLOGI(args...)	_MLOG_(COLOUR_L_CYAN, __FILE__, __LINE__, args)
#define MLOGM(args...)	_MLOG_(COLOUR_L_GREEN, __FILE__, __LINE__, args)
#define MLOGW(args...)	_MLOG_(COLOUR_YELLOW, __FILE__, __LINE__, args)
#define MLOGE(args...)	_MLOG_(COLOUR_L_RED, __FILE__, __LINE__, args)
#define MLOGF(args...)	_MLOG_(COLOUR_RED, __FILE__, __LINE__, args)


int
main(int argc, char *argv[])
{
	double price = 0;
	if (argc != 2) {
		MLOGE("Usage: %s <lowest price>\n", argv[0]);
		return -1;
	}
	price = 1.0/3;
	MLOGD("price:%lf\n",price);
	return 0;
}
























