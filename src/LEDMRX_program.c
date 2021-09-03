/***************************************************/
/* Author  : fatma                                 */
/* Date    : 7 august 2021                         */
/* version : V02                                   */
/***************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "DIO_interface.h"
#include "STK_interface.h"

#include "LEDMRX_interface.h"
#include "LEDMRX_private.h"
#include "LEDMRX_config.h"


 void HLEDMRX_voidInit(void)
 {
		for(int iteration =0; iteration<8; iteration++)
		{
			/* Set Row direction */
		     GPIO_voidSetPinDirection(LEDMRX_ROW_PIN[iteration][0],LEDMRX_ROW_PIN[iteration][1], OUTPUT_SPEED_2MHZ_PP);
		     /* Set Column direction */
		     GPIO_voidSetPinDirection(LEDMRX_COL_PIN[iteration][0],LEDMRX_COL_PIN[iteration][1], OUTPUT_SPEED_2MHZ_PP);
		}

	 }
	 
	 
	 
void HLEDMRX_voidDisplay(u8 *Copy_u8Data)
{
	for(u8 j=0; j<39 ;j++)		//i<39
	{
		for(u8 i=0; i<50;i++)  //speed
		{

	 /*  show the 8 column together*/
	for(u8 iteration=0; iteration<8; iteration++)
	{
	    /* Disable all columns */
	    DisableAllCols();

	    /* (j+iteration) to show the next 8 column together in the array, starting from j*/
	     SetRowValue(Copy_u8Data[j+iteration]);

		/* Enable the desire column */
	     GPIO_voidSetPinValue(LEDMRX_COL_PIN[iteration][0],LEDMRX_COL_PIN[iteration][1], LOW);

		 STK_voidSetBusyWait(2500); //2.5 mse
	}
		}
	}
}


static void DisableAllCols(void)
{
	/* Disable all columns */
	for(u8 iteration=0; iteration<8; iteration++)
	{
	 GPIO_voidSetPinValue(LEDMRX_COL_PIN[iteration][0],LEDMRX_COL_PIN[iteration][1], HIGH);
	}
}


static void SetRowValue(u8 Copy_u8Value)
{
	u8 Local_u8BIT;

	for(int iteration=0; iteration<8; iteration++)
	{
		/* Get bit value in desire Row */
		Local_u8BIT = GET_BIT(Copy_u8Value,iteration);

		/*Set value in desire LEDMRX row */
		GPIO_voidSetPinValue(LEDMRX_ROW_PIN[iteration][0],LEDMRX_ROW_PIN[iteration][1], Local_u8BIT);
	}

}
