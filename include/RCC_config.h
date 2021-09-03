/*  Autour  : fatma                          */
/*  Date    : 30 march 2021                  */														
/*  version : V1                             */

#ifndef RCC_CONFIG_H
#define RCC_CONFIG_H


          /* Options for Clock Types */
/* RCC_HSE_CRYSTAL    
   RCC_HSE_RC         
   RCC_HSI            
   RCC_PLL  */

#define RCC_CLOCK_TYPES       RCC_HSE_CRYSTAL 


/* if your options is RCC_PLL please select one options */

          /* PLL Options */
/*   RCC_PLL_HSI_DIV_2	             
     RCC_PLL_HSE_CRYSTAL_DIV_2        
     RCC_PLL_HSE_RC_DIV_2             
     RCC_PLL_HSE_CRYSTAL              
     RCC_PLL_HSE_RC     */

#define RCC_PLL_CLOCK      RCC_PLL_HSE_CRYSTAL_DIV_2	 


/* you must chose your mutiplication when PLL is disabled */
     /* RCC_PLL_CLOCK_2
        RCC_PLL_CLOCK_3
        RCC_PLL_CLOCK_4
        RCC_PLL_CLOCK_5
        RCC_PLL_CLOCK_6
        RCC_PLL_CLOCK_7
        RCC_PLL_CLOCK_8
        RCC_PLL_CLOCK_9
        RCC_PLL_CLOCK_10
        RCC_PLL_CLOCK_11
        RCC_PLL_CLOCK_12
        RCC_PLL_CLOCK_13
        RCC_PLL_CLOCK_14
        RCC_PLL_CLOCK_15
        RCC_PLL_CLOCK_16          */

#define RCC_PLL_MULTI     RCC_PLL_CLOCK_2
		



#endif
