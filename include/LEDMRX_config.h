/***************************************************/
/* Author  : fatma                                 */
/* Date    : 7 august 2021                         */
/* version : V02                                   */
/***************************************************/
 #ifndef LEDMRX_config_H
 #define LEDMRX_config_H
 
 /* Please write pin pair port,pin */
 
#define LEDMRX_ROW0_PIN       GPIOA,0
#define LEDMRX_ROW1_PIN       GPIOA,1
#define LEDMRX_ROW2_PIN       GPIOA,2
#define LEDMRX_ROW3_PIN       GPIOA,3
#define LEDMRX_ROW4_PIN       GPIOA,4
#define LEDMRX_ROW5_PIN       GPIOA,5
#define LEDMRX_ROW6_PIN       GPIOA,6
#define LEDMRX_ROW7_PIN       GPIOA,7

 u8 LEDMRX_ROW_PIN[8][2]={{LEDMRX_ROW0_PIN},{LEDMRX_ROW1_PIN},{LEDMRX_ROW2_PIN},{LEDMRX_ROW3_PIN},
		                     {LEDMRX_ROW4_PIN},{LEDMRX_ROW5_PIN},{LEDMRX_ROW6_PIN},{LEDMRX_ROW7_PIN}};
 /* Please write pin pair port,pin */
 
#define LEDMRX_COL0_PIN       GPIOB,0
#define LEDMRX_COL1_PIN       GPIOB,1
#define LEDMRX_COL2_PIN       GPIOB,5
#define LEDMRX_COL3_PIN       GPIOB,6
#define LEDMRX_COL4_PIN       GPIOB,7
#define LEDMRX_COL5_PIN       GPIOB,8
#define LEDMRX_COL6_PIN       GPIOB,9
#define LEDMRX_COL7_PIN       GPIOB,10

 u8 LEDMRX_COL_PIN [8][2]={{LEDMRX_COL0_PIN} ,{LEDMRX_COL1_PIN},{LEDMRX_COL2_PIN} ,{LEDMRX_COL3_PIN},
		                 {LEDMRX_COL4_PIN} ,{LEDMRX_COL5_PIN} ,{LEDMRX_COL6_PIN} ,{LEDMRX_COL7_PIN} };
 
 #endif


