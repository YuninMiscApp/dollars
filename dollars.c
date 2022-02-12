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

#define MLOGV(args...)	_MLOG_(COLOUR_NONE   , __FILE__, __LINE__, args)
#define MLOGD(args...)	_MLOG_(COLOUR_WHITE  , __FILE__, __LINE__, args)
#define MLOGI(args...)	_MLOG_(COLOUR_L_CYAN , __FILE__, __LINE__, args)
#define MLOGM(args...)	_MLOG_(COLOUR_L_GREEN, __FILE__, __LINE__, args)
#define MLOGW(args...)	_MLOG_(COLOUR_YELLOW , __FILE__, __LINE__, args)
#define MLOGE(args...)	_MLOG_(COLOUR_L_RED  , __FILE__, __LINE__, args)
#define MLOGF(args...)	_MLOG_(COLOUR_RED    , __FILE__, __LINE__, args)

#define MPRINT(args...) printf(args)

/***********************************
 * 目标价：T
 * 下跌系数：fall
 * 上涨系数：rise
 * 双头系数：double
 * 爆发系数：outburst
 * 回调系数: callback
 ********************************
 * T(fall1) = Val * 0.7
 * T(fall2) = Val * 0.49
 * T(fall3) = Val * 0.343
 * T(r1) = Val * 1.7
 * T(r2) = Val * 2.2
 * T(OB1) = Val * 4.45
 * T(OB2) = Val * 5.76
 * T(CB1)=Val * 0.95
 * T(CB2)=Val * 0.88
***********************************/

#define BR_FALL1 0.7
#define BR_FALL2 0.49
#define BR_FALL3 0.343
#define BR_FALL4 0.168

#define BR_RISE1 1.7
#define BR_RISE2 2.2

#define BR_OB1 4.45
#define BR_OB2 5.76

#define BR_CB1 0.95
#define BR_CB2 0.88


////////////////////////////////////////////////////

void wave_double_model(double price)
{
	double W1_r1,W1_f1,W1_r2,W1_r3;
	double W2base;
	double W2_r1,W2_f1,W2_r2;
	double Slump1,Slump2,Slump3;
	
	//第一波主升浪 wave
	W1_r1 = price * BR_RISE1;    //第一波放量拉高
	W1_f1 = W1_r1 * BR_FALL1;	 //第一波回调
	W1_r2 = W1_f1 * BR_RISE1;	 //第二波拉高
	W1_r3 = W1_r2 * BR_RISE2;    //第三波快速拉高冲顶,并伴随着放量
	
	//第二波主升浪,走出双头模型,M头顶
	W2base = W1_r3 * BR_FALL2;   //双头前的,第一波大的回调,然后盘整.
	W2_r1 = W2base * BR_RISE1;	 //第二波放量拉高
	W2_f1 = W2_r1 * BR_CB1;	     //第二波轻微回调或横盘整理(1周左右)
	W2_r2 = W2base * BR_RISE2;    //第二波快速拉高冲顶,并伴随着放量
	
	//暴跌
	Slump1 = W2_r2*BR_FALL2;
	Slump2 = W2_r2*BR_FALL3;
	Slump3 = W2_r2*BR_FALL4;
	
	MLOGW("[The first wave]:  (%lf) -> (%lf) -> (%lf) -> (%lf) -> (%lf) ",price,W1_r1,W1_f1,W1_r2,W1_r3);
	MLOGW("[The second wave]: (%lf) -> (%lf) -> (%lf) -> (%lf)",W2base,W2_r1,W2_f1,W2_r2);
	MLOGM("[The slump]: (%lf) -> (%lf) -> (%lf)",Slump1,Slump2,Slump3);
}

int
main(int argc, char *argv[])
{
	double price = 0;
	
	if (argc != 2) {
		MLOGE("Usage: %s <lowest price>\n", argv[0]);
		return -1;
	}
	price = atof(argv[1]);
	MPRINT("price=%lf, Tmin=%lf, Tmax=%lf\n",price,price*BR_OB1,price*BR_OB2);
	//
	wave_double_model(price);
	
	return 0;
}
























