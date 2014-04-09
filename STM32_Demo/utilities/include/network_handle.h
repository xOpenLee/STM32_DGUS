#ifndef __Uart5__h
#define __Uart5__h
#include "stdint.h"

extern   unsigned char   F_RX1_Right ;
extern   uint16_t		  rx1BufIndex ;
extern   uint8_t		  F_RX1_VAILD ;
extern   long  		    CrcValue ;
extern   uint8_t		  F_RX1_SYNC ;


/*******************************************
这个结构体是定义9种餐品的定义
设置餐品的时候定义的一个结构体 与服务器对比

********************************/
typedef struct
{
	
	unsigned char MealID[4];
	unsigned char MaelName[20];
	unsigned char MealNum[2];
	unsigned char MealPreace[4];
	unsigned char MealType[4];
	
}Meal_struction;
extern	Meal_struction  	Meal[9];


/*******************************************
这个结构体是用户选择取餐的时候需要定义的
********************************/
typedef struct
{
 unsigned char 	 MealID[4] ;        /*餐品的ID*/
 unsigned char   MealNo ;           /*餐品的数量*/
 unsigned char   DealBalance[6];	/*支付金额*/
 unsigned char   PayType;	        /*支付方式*/
 unsigned char   MealPrice[6];       /*餐品的价格*/
 unsigned char   Change[6] ;        /*应该找回多少钱*/
 unsigned char   RemainMealNum[2] ; /*剩余餐品数*/
 unsigned char   MealName; 

}CustomerSel__struction ;
extern CustomerSel__struction CustomerSel;


extern unsigned char  F_RX1_Right;
extern unsigned char  rx1Buf[512];	  //发送数据给服务器，服务器返回数据存在这个buffer

void Uart5_Configuration(void);
void Uart5Send(unsigned char *p,unsigned char lenght);


unsigned char SignInFun(void);
unsigned char MealDataCompareFun(void);
unsigned char SignOutFun(void);/*退签*/
unsigned char StatusUploadingFun(void);/*状态上送*/
unsigned char EchoFun(void);/*回响测试*/
unsigned char TakeMealsFun(unsigned char *SendBuffer);/*取餐设置*/
unsigned char MealUploadingFun(void);/*上送餐品数据*/
unsigned char ClearingFun(void);/*结算命令*/
void  EchoFuntion(void (*fptr)(void)) ;
unsigned char 	Resend(unsigned char *p,long lenght);
#endif

