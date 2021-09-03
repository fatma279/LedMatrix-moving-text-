/*  Autour  : fatma                          */
/*  Date    : 30 march 2021                  */														
/*  version : V1                             */

#ifndef RCC_INTERFACE_H
#define RCC_INTERFACE_H

/*  Bus Id  */
#define RCC_AHP        0
#define RCC_APB1       1
#define RCC_APB2       2

/*     Peripheral Clock Enable For APB2 Bus        */
#define RCC_PORTA       2
#define RCC_PORTB       3
#define RCC_PORTC       4


void RCC_voidInitSysClock();

void RCC_voidEnablePeripheralClock(u8 Copy_u8busId, u8 Copy_perId);

void RCC_voidDisablePeripheralClock(u8 Copy_u8busId, u8 Copy_perId);












#endif
