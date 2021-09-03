/*  Autour  : fatma                          */
/*  Date    : 30 march 2021                  */														
/*  version : V1                             */

#ifndef RCC_PRIVATE_H
#define RCC_PRIVATE_H


         /* Register Definitions */
#define RCC_CR         *((volatile u32 *)0x40021000)
#define RCC_CFGR       *((volatile u32 *)0x40021004)
#define RCC_CIR        *((volatile u32 *)0x40021008)
#define RCC_APB2RSTR   *((volatile u32 *)0x4002100C)
#define RCC_APB1RSTR   *((volatile u32 *)0x40021010)
#define RCC_AHBENR     *((volatile u32 *)0x40021014)
#define RCC_APB2ENR    *((volatile u32 *)0x40021018)
#define RCC_APB1ENR    *((volatile u32 *)0x4002101C)
#define RCC_BDCR       *((volatile u32 *)0x40021020)
#define RCC_CSR        *((volatile u32 *)0x40021024)




          /* Clock Types */
#define RCC_HSE_CRYSTAL    0
#define RCC_HSE_RC         1
#define RCC_HSI            2
#define RCC_PLL            3



          /* PLL Options */
#define RCC_PLL_HSI_DIV_2	             0
#define RCC_PLL_HSE_CRYSTAL_DIV_2        1
#define RCC_PLL_HSE_RC_DIV_2             2
#define RCC_PLL_HSE_CRYSTAL              3
#define RCC_PLL_HSE_RC                   4



	  /* multiplication optins */
	  
#define RCC_PLL_CLOCK_2        0b0000
#define RCC_PLL_CLOCK_3        0b0001
#define RCC_PLL_CLOCK_4        0b0010
#define RCC_PLL_CLOCK_5        0b0011
#define RCC_PLL_CLOCK_6        0b0100
#define RCC_PLL_CLOCK_7        0b0101
#define RCC_PLL_CLOCK_8        0b0110
#define RCC_PLL_CLOCK_9        0b0111
#define RCC_PLL_CLOCK_10       0b1000
#define RCC_PLL_CLOCK_11       0b1001
#define RCC_PLL_CLOCK_12       0b1010
#define RCC_PLL_CLOCK_13       0b1011
#define RCC_PLL_CLOCK_14       0b1100
#define RCC_PLL_CLOCK_15       0b1110
#define RCC_PLL_CLOCK_16       0b1111





		  
#endif
