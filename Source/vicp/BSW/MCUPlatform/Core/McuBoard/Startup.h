/*
*********************************************************************************************************
*                                     MICIRUM BOARD SUPPORT PACKAGE
*
*                             (c) Copyright 2010; Micrium, Inc.; Weston, FL
*
*               All rights reserved.  Protected by international copyright laws.
*               Knowledge of the source code may NOT be used to develop a similar product.
*               Please help us continue to provide the Embedded community with the finest
*               software available.  Your honesty is greatly appreciated.
*********************************************************************************************************
*/

/*
*********************************************************************************************************
*
*                                        BOARD SUPPORT PACKAGE
*
*                                     Renesas V850E2/Fx4 uD70F4010
*                                              on the
*
*                                         AB-050-FX4-NONE-V1
*                                         Evaluation Board
*
* Filename      : bsp.h
* Version       : V1.00
* Programmer(s) : FF
*********************************************************************************************************
*/

/*
*********************************************************************************************************
*                                                 MODULE
*
* Note(s) : (1) This header file is protected from multiple pre-processor inclusion through use of the
*               BSP present pre-processor macro definition.
*********************************************************************************************************
*/

#ifndef  _STARTUP_H
#define  _STARTUP_H


/*
*********************************************************************************************************
*                                                 EXTERNS
*********************************************************************************************************
*/


/*
*********************************************************************************************************
*                                              INCLUDE FILES
*********************************************************************************************************
*/

/*============================================================================
* Includes
============================================================================*/



/*============================================================================
* Defines
============================================================================*/
/*#include <CompilerDef.h>*/

#include "cpu_cfg.h"
#include "Define.h"
#include "cpu.h"
/*
*********************************************************************************************************
*                                                DEFINES
*********************************************************************************************************
*/
#define  BSP_PLL0_OUT_FREQ_HZ                 80000000u         /* PLL 0 frequency                          */

#define  BSP_OSC_STAB_NORMAL                         0u
#define  BSP_OSC_STAB_SHORT                          1u

#define  BSP_PLL_ID_00                               0u
#define  BSP_PLL_ID_01                               1u
#define  BSP_PLL_ID_02                               2u

/*
*********************************************************************************************************
*                                      REGISTER & BIT FIELD DEFINES
*********************************************************************************************************
*/


/*
*********************************************************************************************************
*                                               INT DEFINES
*********************************************************************************************************
*/
/*V850E2--3580*/




/*
*********************************************************************************************************
*                                               DATA TYPES
*********************************************************************************************************
*/

/*
*********************************************************************************************************
*                                            GLOBAL VARIABLES
*********************************************************************************************************
*/


/*
*********************************************************************************************************
*                                                 MACRO'S
*********************************************************************************************************
*/
void delay_us(U16 period);
void delay_10us(void);
void delay_50us(void);
void delay_100us(void);
void hardware_reset(void);
/*
*********************************************************************************************************
*                                             MODULE END
*********************************************************************************************************
*/


#endif                                                          /* End of module include.                               */
