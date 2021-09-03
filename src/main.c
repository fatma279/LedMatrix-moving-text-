/***************************************************/
/* Author  : fatma                                 */
/* Date    : 20 august 2021                         */
/* version : V02                                   */
/***************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "RCC_interface.h"
#include "DIO_interface.h"
#include "STK_interface.h"
#include "LEDMRX_interface.h"


u8 Data[40]={0, 0, 126, 18, 18, 2, 0, 0,                    //f
		    0, 124, 18, 18, 18, 124, 0, 0,                  //a
			0, 4, 126, 68, 0, 0, 0, 0,                      //t
			60, 2, 2, 60, 2, 2, 60, 0,                      //m
		    0, 124, 18, 18, 18, 124, 0, 0                   //a
};
void main(void)
{
	 RCC_voidInitSysClock();
	 RCC_voidEnablePeripheralClock( RCC_APB2, RCC_PORTA);
	 RCC_voidEnablePeripheralClock( RCC_APB2, RCC_PORTB);
	 STK_voidInit();
	// MSTK_voidSetBusyWait(2 );
	 HLEDMRX_voidInit();
	 while(1){
	 HLEDMRX_voidDisplay(Data);
	 }

}
