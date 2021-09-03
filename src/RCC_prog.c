/*  Autour  : fatma                          */
/*  Date    : 30 march 2021                  */														
/*  version : V1                             */

#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "RCC_interface.h"
#include "RCC_private.h"
#include "RCC_config.h"


void RCC_voidInitSysClock()
{
	#if RCC_CLOCK_TYPES == RCC_HSE_CRYSTAL 
	  RCC_CR = 0x00010000;       /* Enable HSE with no bypass */
      RCC_CFGR= 0x00000001;
		
		
	#elif RCC_CLOCK_TYPES == RCC_HSE_RC
	  RCC_CR = 0x00050000;      /* Enable HSE with bypass */
      RCC_CFGR= 0x00000001;	
     
	 
    #elif RCC_CLOCK_TYPES == RCC_HSI 	
	  RCC_CR = 0x00000081;      /* Enable HSI + Trimming = 0 (default = 16)*/
      RCC_CFGR= 0x00000000;	
     
	 
    #elif RCC_CLOCK_TYPES == RCC_PLL	
    
    	 #if  RCC_PLL_CLOCK == RCC_PLL_HSI_DIV_2
               RCC_CFGR= 0x00000002;                    /*HSI divided by 2 and PLL selected as system clock */
               RCC_CFGR |= (RCC_PLL_MULTI << 18);		/*set the multiplication factor for PLL*/		   
		       RCC_CR = 0x01000081;                     /* enable PLL_HSI +Trimming = 0 */
			   			  
			   
		 #elif  RCC_PLL_CLOCK == RCC_PLL_HSE_CRYSTAL_DIV_2  
               RCC_CFGR= 0x00030002;                    /*HSE divided by 2 and PLL selected as system clock */
               RCC_CFGR |= (RCC_PLL_MULTI << 18);		/*set the multiplication factor for PLL*/		   
		       RCC_CR = 0x01010000;                     /* enable PLL_HSE with no bybass */		 
		 
		 
      	 #elif  RCC_PLL_CLOCK == RCC_PLL_HSE_RC_DIV_2 
               RCC_CFGR= 0x00030002;                    /*HSE divided by 2 and PLL selected as system clock */
               RCC_CFGR |= (RCC_PLL_MULTI << 18);		/*set the multiplication factor for PLL*/		   
		       RCC_CR = 0x01050000;                     /* enable PLL_HSE with bybass */	

			   
		 #elif  RCC_PLL_CLOCK == RCC_PLL_HSE_CRYSTAL 
               RCC_CFGR= 0x00010002;                    /*HSE and PLL selected as system clock */
               RCC_CFGR |= (RCC_PLL_MULTI << 18);		/*set the multiplication factor for PLL*/		   
		       RCC_CR = 0x01010000;                     /* enable PLL_HSE with no bybass */

			   
		 #elif  RCC_PLL_CLOCK == RCC_PLL_HSE_RC  
               RCC_CFGR= 0x00010002;                    /*HSE and PLL selected as system clock */
               RCC_CFGR |= (RCC_PLL_MULTI << 18);		/*set the multiplication factor for PLL*/		   
		       RCC_CR = 0x01050000;                     /* enable PLL_HSE with bybass */
			   
			   
         #endif          
        
                   
      #endif  
         

}



void RCC_voidEnablePeripheralClock(u8 Copy_u8busId, u8 Copy_u8PerId)
{
	if (Copy_u8PerId <= 31)
	{
			switch(Copy_u8busId)
			{
				case RCC_AHP:     SET_BIT(RCC_AHBENR ,Copy_u8PerId );   break;
				case RCC_APB1:    SET_BIT(RCC_APB2ENR ,Copy_u8PerId );  break;
				case RCC_APB2:    SET_BIT(RCC_APB2ENR ,Copy_u8PerId );  break;
				
			}
	}
			
}



void RCC_voidDisablePeripheralClock(u8 Copy_u8busId, u8 Copy_u8PerId)
{
	if (Copy_u8PerId <= 31)
	{
			switch(Copy_u8busId)
			{
				case RCC_AHP:     CLR_BIT(RCC_AHBENR ,Copy_u8PerId );   break;
				case RCC_APB1:    CLR_BIT(RCC_APB2ENR ,Copy_u8PerId );  break;
				case RCC_APB2:    CLR_BIT(RCC_APB2ENR ,Copy_u8PerId );  break;
				
			}
	}
			
}
