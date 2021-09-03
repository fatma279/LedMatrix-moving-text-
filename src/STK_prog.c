/*    Author  :  FATMA            */
/*    Date    :  22 july 2021    */
/*    version :  V1             */

#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "STK_interface.h"
#include "STK_private.h"
#include "STK_config.h"




void STK_voidInit(void)
{
	#if STK_CLK_SRC == STK_SRC_AHB
	
    /* Disable STK - Disable STK Interrupt - Set clock source AHB */
	STK -> CTRL = 0x00000004;
	
    #else
		
    /* Disable STK - Disable STK Interrupt - Set clock source AHB/8 */
	STK -> CTRL = 0;
    #endif
}


void STK_voidSetBusyWait( u32 Copy_u32Ticks )
{
	STK -> LOAD = Copy_u32Ticks;
	
	//Enable SYSTICK
	SET_BIT(STK -> CTRL, 0);
	
	// Read COUNT FLAG
	while((GET_BIT(STK -> CTRL,16)) == 0);
	
	//Stop timer
	STK -> LOAD = 0;
	STK -> VAL  = 0;
}


void STK_voidSetIntervalSingle  ( u32 Copy_u32Ticks, void (*Copy_ptr)(void) )
{
	/* Load ticks to load register */
	STK -> LOAD = Copy_u32Ticks;
	
	/* Start Timer (Enable SYSTICK) */
	SET_BIT(STK->CTRL, 0);
	
	/* Save CallBack */
	STK_CallBack = Copy_ptr;
	
	/* Set Mode*/
	STK_u8ModeOfInterval = STK_SINGLE_INTERVAL;
	
	/* Enable STK Interrupt */
	SET_BIT(STK->CTRL, 1);
}


void STK_voidSetIntervalPeriodic( u32 Copy_u32Ticks, void (*Copy_ptr)(void) )
{
	/* Load ticks to load register */
	STK -> LOAD = Copy_u32Ticks;
	
	/* Start Timer (Enable SYSTICK) */
	SET_BIT(STK->CTRL, 0);
	
	/* Save CallBack */
	STK_CallBack = Copy_ptr;
	
	/* Set Mode */
	STK_u8ModeOfInterval = STK_PERIOD_INTERVAL;
	
	/* Enable STK Interrupt */
	SET_BIT(STK->CTRL, 1);
}

void STK_voidStopInterval(void)
{
	/* Disable STK Interrupt */
	CLR_BIT(STK->CTRL, 1);
	
	/* Stop Timer */
	SET_BIT(STK->CTRL, 0);
	STK -> LOAD = 0;
	STK -> VAL  = 0;
}


u32  STK_u32GetElapsedTime(void)
{
	u32 Local_u32ElapsedTime;
	
	/*The time that passed*/
	Local_u32ElapsedTime = (STK -> LOAD) - (STK -> VAL) ;
	
	return Local_u32ElapsedTime;
}



u32  STK_u32GetRemainingTime(void)
{
	u32 Local_u32RemainingTime;
	
	/*the remaining time*/
	Local_u32RemainingTime = STK -> VAL;
	
	return Local_u32RemainingTime;
}


void SysTick_Handler(void)
{
	u8 Local_u8Temporary = 0;
	
	if (STK_u8ModeOfInterval == STK_SINGLE_INTERVAL)
	{
		/* Disable STK Interrupt */
		CLR_BIT(STK->CTRL, 1);
	
		/* Stop Timer */
		SET_BIT(STK->CTRL, 0);
		STK -> LOAD = 0;
		STK -> VAL  = 0;
	}
	
	/* Callback notification */
	STK_CallBack();
	
	/* Clear interrupt flag */
	Local_u8Temporary = GET_BIT(STK->CTRL,16);
}
