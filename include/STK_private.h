/*    Author  :  FATMA            */
/*    Date    :  22 july 2021    */
/*    version :  V1             */

#ifndef STK_PRIVATE_H
#define STK_PRIVATE_H


typedef struct
{
	volatile u32 CTRL  ;
	volatile u32 LOAD  ;
	volatile u32 VAL   ;
	volatile u32 CALIB;
}STK_Type;

#define     STK    ((STK_Type*)0xE000E010)

/* Clock source selection*/
#define     STK_SRC_AHB           0
#define     STK_SRC_AHB_8         1

/*interval mode selection*/
#define     STK_SINGLE_INTERVAL    0
#define     STK_PERIOD_INTERVAL    1




/* Define Callback Global Variable */
static void(*STK_CallBack)(void);

/* Define Variable for interval mode */
static u8 STK_u8ModeOfInterval;
















#endif
