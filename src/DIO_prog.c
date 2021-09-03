/*  Autour  : fatma                          */
/*  Date    : 12 April 2021                   */														
/*  version : V2                             */

#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "RCC_interface.h"
#include "DIO_interface.h"
#include "DIO_private.h"
#include "DIO_config.h"


void GPIO_voidSetPinDirection(u8 Copy_u8Port, u8 Copy_u8Pin, u8 Copy_u8Mode)
{
	
	switch (Copy_u8Port)
	{
	case GPIOA:
		if(Copy_u8Pin<=7)
		{
			DIOA_CRL &=~((0b1111) << (Copy_u8Pin*4));
			DIOA_CRL |= ((Copy_u8Mode) << (Copy_u8Pin*4));
		}
		else if(Copy_u8Pin<16)
		{
			Copy_u8Pin = Copy_u8Pin-8;
			DIOA_CRH &=~((0b1111) << (Copy_u8Pin*4));
			DIOA_CRH |= ((Copy_u8Mode) << (Copy_u8Pin*4));
		}
		break;
		
	case GPIOB:
		if(Copy_u8Pin<=7)
		{
			DIOB_CRL &=~((0b1111) << (Copy_u8Pin*4));
			DIOB_CRL |= ((Copy_u8Mode) << (Copy_u8Pin*4));
		}
		else if(Copy_u8Pin<16)
		{
			Copy_u8Pin = Copy_u8Pin-8;
			DIOB_CRH &=~((0b1111) << (Copy_u8Pin*4));
			DIOB_CRH |= ((Copy_u8Mode) << (Copy_u8Pin*4));
		}
		break;		

	case GPIOC:
		if(Copy_u8Pin<=7)
		{
			DIOC_CRL &=~((0b1111) << (Copy_u8Pin*4));
			DIOC_CRL |= ((Copy_u8Mode) << (Copy_u8Pin*4));
		}
		else if(Copy_u8Pin<16)
		{
			Copy_u8Pin = Copy_u8Pin-8;
			DIOC_CRH &=~((0b1111) << (Copy_u8Pin*4));
			DIOC_CRH |= ((Copy_u8Mode) << (Copy_u8Pin*4));
		}
		break;	
	default:
break;	
	}
}



void GPIO_voidSetPinValue(u8 Copy_u8Port, u8 Copy_u8Pin, u8 Copy_u8Value)
{
	switch(Copy_u8Port)
	{
		case GPIOA:
			if( Copy_u8Value == HIGH)
		      SET_BIT(DIOA_ODR ,Copy_u8Pin);
		  
	        else if( Copy_u8Value == LOW)
		      CLR_BIT(DIOA_ODR ,Copy_u8Pin);
		  
	     break;


	    case GPIOB:
	        if( Copy_u8Value == HIGH)
	          SET_BIT(DIOB_ODR ,Copy_u8Pin);
		  
	        else if( Copy_u8Value == LOW)
	          CLR_BIT(DIOB_ODR ,Copy_u8Pin);
		  
	    break;	

	    case GPIOC:
	        if( Copy_u8Value == HIGH)
	          SET_BIT(DIOC_ODR ,Copy_u8Pin);
		  
	        else if( Copy_u8Value == LOW)
	          CLR_BIT(DIOC_ODR ,Copy_u8Pin);
		  
	    break;		
	
	}	
	
}
 
 
   /* Set pin value with BSR &BRR register */
/*
void GPIO_VoidSetPinValue(u8 Copy_u8Port, u8 Copy_u8Pin, u8 Copy_u8Value){
switch(Copy_u8Port)
{
   case GPIOA :
		if( Copy_u8Value == HIGH ){

		DIOA_BSR = (1 << (Copy_u8Pin));

		}else if( Copy_u8Value == LOW ){

			DIOA_BRR  = (1 << (Copy_u8Pin) );
		}
		break;

   case GPIOB:
		if( Copy_u8Value == HIGH ){

			DIOB_BSR = (1 << (Copy_u8Pin));

		}else if( Copy_u8Value == LOW ){
			DIOB_BRR  = (1 << (Copy_u8Pin) );
		}
		break;
   case GPIOC:
		if( Copy_u8Value == HIGH ){

			DIOC_BSR = (1 << (Copy_u8Pin));

		}else if( Copy_u8Value == LOW ){
			DIOC_BRR  = (1 << (Copy_u8Pin) );
		}
		break;
}

}*/


u8 GPIO_U8GetPinValue(u8 Copy_u8Port, u8 Copy_u8Pin)
{
	u8 LOC_u8Result = 0 ;
		switch(Copy_u8Port)
	{
		case GPIOA:
			
		     LOC_u8Result = GET_BIT(DIOA_IDR ,Copy_u8Pin);
		  
	     break;


	    case GPIOB:
		     LOC_u8Result = GET_BIT(DIOB_IDR ,Copy_u8Pin);
		  
	    break;	

	    case GPIOC:
		     LOC_u8Result = GET_BIT(DIOC_IDR ,Copy_u8Pin);
		  
	     break;	
	
	}
	
	return LOC_u8Result;
}


void GPIO_VoidSetPortDirection(u8 Copy_u8Port, u8 Copy_u8Mode)
{
	switch (Copy_u8Port)
	{
	case GPIOA:
	  DIOA_CRL =0x00000000;
      DIOA_CRH =0x00000000;	
        for(int Copy_u8Pin=0; Copy_u8Pin<=7; Copy_u8Pin++)
            {
                DIOA_CRL |= ( (Copy_u8Mode) << (Copy_u8Pin*4) );
                DIOA_CRH |= ( (Copy_u8Mode) << (Copy_u8Pin*4) );
            }
		break;
		
	case GPIOB:
	  DIOB_CRL =0x00000000;
      DIOB_CRH =0x00000000;		
        for(int Copy_u8Pin=0; Copy_u8Pin<=7; Copy_u8Pin++)
            {
                DIOB_CRL |= ( (Copy_u8Mode) << (Copy_u8Pin*4) );
                DIOB_CRH |= ( (Copy_u8Mode) << (Copy_u8Pin*4) );
            }
		break;		

	case GPIOC:
	  DIOC_CRL =0x00000000;
      DIOC_CRH =0x00000000;	
        for(int Copy_u8Pin=0; Copy_u8Pin<=7; Copy_u8Pin++)
            {
                DIOC_CRL |= ( (Copy_u8Mode) << (Copy_u8Pin*4) );
                DIOC_CRH |= ( (Copy_u8Mode) << (Copy_u8Pin*4) );
            }
		break;	
	default:
break;	
	}
}



void GPIO_voidSetPortValue(u8 Copy_u8Port,u8 Copy_u8Value)
{
	switch(Copy_u8Port)
    {
        case GPIOA:
			DIOA_ODR=Copy_u8Value;
		break;

        case GPIOB:
			DIOB_ODR=Copy_u8Value;
		break;
		
        case GPIOC:
			DIOC_ODR=Copy_u8Value;
		break;
}
}


 u32  GPIO_VoidLockMode(u8 Copy_u8Port, u8 Copy_u8Pin)
{
	u32 LOC_u32RegRead=0 ;
	
	switch(Copy_u8Port)
	{
	   case GPIOA :   
	   /* LOCK key writing sequence:
          Write 1 in Lock key without change LCK[15:0]*/
		   LOC_u32RegRead = (1<<16)|(1<<Copy_u8Pin);
		   DIOA_LCKR = LOC_u32RegRead;

		   /* Write 1 in PORTA lock bit while Lock key is ZERO*/
		   DIOA_LCKR =(1<<Copy_u8Pin);

		   /* Write 1 in Lock key without change LCK[15:0]*/
		   DIOA_LCKR = LOC_u32RegRead;
		   
		   /* Read Lock key*/
		   LOC_u32RegRead = DIOA_LCKR;
			break;


	   case GPIOB:
		   /* LOCK key writing sequence:
	          Write 1 in Lock key without change LCK[15:0]*/
			   LOC_u32RegRead = (1<<16)|(1<<Copy_u8Pin);
			   DIOB_LCKR = LOC_u32RegRead;

			   /* Write 1 in PORTB lock bit while Lock key is ZERO*/
			   DIOB_LCKR =(1<<Copy_u8Pin);

			   /* Write 1 in Lock key without change LCK[15:0]*/
			   DIOB_LCKR = LOC_u32RegRead;

			   /* Read Lock key*/
			   LOC_u32RegRead = DIOB_LCKR;
				break;
			
	   case GPIOC:
		   /* LOCK key writing sequence:
	          Write 1 in Lock key without change LCK[15:0]*/
			   LOC_u32RegRead = (1<<16)|(1<<Copy_u8Pin);
			   DIOC_LCKR = LOC_u32RegRead;

			   /* Write 1 in PORTC lock bit while Lock key is ZERO*/
			   DIOC_LCKR =(1<<Copy_u8Pin);

			   /* Write 1 in Lock key without change LCK[15:0]*/
			   DIOC_LCKR = LOC_u32RegRead;

			   /* Read Lock key*/
			   LOC_u32RegRead = DIOC_LCKR;
				break;
	}

	return LOC_u32RegRead;
}


