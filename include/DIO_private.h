/*  Autour  : fatma                          */
/*  Date    : 9 April 2021                   */														
/*  version : V1                             */

#ifndef DIO_PRIVATE_H
#define DIO_PRIVATE_H

         /* Register Definitions PORT A */
#define DIOA_CRL           *((volatile u32 *)0x40010800)
#define DIOA_CRH           *((volatile u32 *)0x40010804)
#define DIOA_IDR           *((volatile u32 *)0x40010808)
#define DIOA_ODR           *((volatile u32 *)0x4001080c)
#define DIOA_BSRR          *((volatile u32 *)0x40010810)
#define DIOA_BRR           *((volatile u32 *)0x40010814)
#define DIOA_LCKR          *((volatile u32 *)0x40010818)


         /* Register Definitions PORT B */
#define DIOB_CRL           *((volatile u32 *)0x40010c00)
#define DIOB_CRH           *((volatile u32 *)0x40010c04)
#define DIOB_IDR           *((volatile u32 *)0x40010c08)
#define DIOB_ODR           *((volatile u32 *)0x40010c0c)
#define DIOB_BSRR          *((volatile u32 *)0x40010c10)
#define DIOB_BRR           *((volatile u32 *)0x40010c14)
#define DIOB_LCKR          *((volatile u32 *)0x40010c18)


         /* Register Definitions PORT C */
#define DIOC_CRL           *((volatile u32 *)0x40011000)
#define DIOC_CRH           *((volatile u32 *)0x40011004)
#define DIOC_IDR           *((volatile u32 *)0x40011008)
#define DIOC_ODR           *((volatile u32 *)0x4001100c)
#define DIOC_BSRR          *((volatile u32 *)0x40011010)
#define DIOC_BRR           *((volatile u32 *)0x40011014)
#define DIOC_LCKR          *((volatile u32 *)0x40011018)












#endif
