/*
*********************************************************************************************************
*                                               uC/OS-II
*                                         The Real-Time Kernel
*
*
*                             (c) Copyright 1992-2007, Micrium, Weston, FL
*                                          All Rights Reserved
*
*                                         Renesas V850E2M Port
*
* File      : OS_CPU_C.C
* Version   : V2.90
* By        : Fernando J. Flores
*
* For       : Renesas V850E2M
* Toolchain : IAR EWV850 v3.71
*
*********************************************************************************************************
*/

#define  OS_CPU_GLOBALS
/*#include "OSAdapter_IF.h"*/

/*$PAGE*/
/*
*********************************************************************************************************
*                                             LOCAL CONSTANTS
*********************************************************************************************************
*/
#define  V850ES_EIPSW_EN                0x00000000u
#define  V850ES_CTPC                    0x00000000u
#define  V850ES_CTPSW                   0x00000000u
/*
*********************************************************************************************************
*                                          LOCAL VARIABLES
*********************************************************************************************************
*/

#if OS_TMR_EN > 0
static  INT16U  OSTmrCtr;
#endif

/*
*********************************************************************************************************
*                                       OS INITIALIZATION HOOK
*                                            (BEGINNING)
*
* Description: This function is called by OSInit() at the beginning of OSInit().
*
* Arguments  : none
*
* Note(s)    : 1) Interrupts should be disabled during this call.
*********************************************************************************************************
*/
#if OS_CPU_HOOKS_EN > 0u
void  OSInitHookBegin (void)
{
#if(OS_TMR_EN > 0)
    OSTmrCtr = 0u;
#endif
}
#endif

/*
*********************************************************************************************************
*                                       OS INITIALIZATION HOOK
*                                               (END)
*
* Description: This function is called by OSInit() at the end of OSInit().
*
* Arguments  : none
*
* Note(s)    : 1) Interrupts should be disabled during this call.
*********************************************************************************************************
*/
#if OS_CPU_HOOKS_EN > 0u
void  OSInitHookEnd (void)
{
}
#endif

/*
*********************************************************************************************************
*                                          TASK CREATION HOOK
*
* Description: This function is called when a task is created.
*
* Arguments  : ptcb   is a pointer to the task control block of the task being created.
*
* Note(s)    : 1) Interrupts are disabled during this call.
*********************************************************************************************************
*/
#if OS_CPU_HOOKS_EN > 0u
void  OSTaskCreateHook (OS_TCB *ptcb)
{
#if OS_APP_HOOKS_EN > 0
    App_TaskCreateHook(ptcb);
#else
    (void)ptcb;                                                         /* Prevent compiler warning                                 */
#endif
}
#endif

/*
*********************************************************************************************************
*                                           TASK DELETION HOOK
*
* Description: This function is called when a task is deleted.
*
* Arguments  : ptcb   is a pointer to the task control block of the task being deleted.
*
* Note(s)    : 1) Interrupts are disabled during this call.
*********************************************************************************************************
*/
#if OS_CPU_HOOKS_EN > 0u
void  OSTaskDelHook (OS_TCB *ptcb)
{
#if OS_APP_HOOKS_EN > 0
    App_TaskDelHook(ptcb);
#else
    (void)ptcb;                                                         /* Prevent compiler warning                                 */
#endif
}
#endif

/*
*********************************************************************************************************
*                                             IDLE TASK HOOK
*
* Description: This function is called by the idle task.  This hook has been added to allow you to do
*              such things as STOP the CPU to conserve power.
*
* Arguments  : none
*
* Note(s)    : 1) Interrupts are enabled during this call.
*********************************************************************************************************
*/
#if OS_CPU_HOOKS_EN > 0u
void  OSTaskIdleHook (void)
{
#if OS_APP_HOOKS_EN > 0
    App_TaskIdleHook();
#endif
}
#endif

/*
*********************************************************************************************************
*                                            TASK RETURN HOOK
*
* Description: This function is called if a task accidentally returns.  In other words, a task should
*              either be an infinite loop or delete itself when done.
*
* Arguments  : ptcb      is a pointer to the task control block of the task that is returning.
*
* Note(s)    : none
*********************************************************************************************************
*/

#if OS_CPU_HOOKS_EN > 0u
void  OSTaskReturnHook (OS_TCB  *ptcb)
{
#if OS_APP_HOOKS_EN > 0u
    App_TaskReturnHook(ptcb);
#else
    (void)ptcb;
#endif
}
#endif

/*
*********************************************************************************************************
*                                           STATISTIC TASK HOOK
*
* Description: This function is called every second by uC/OS-II's statistics task.  This allows your
*              application to add functionality to the statistics task.
*
* Arguments  : none
*********************************************************************************************************
*/

#if OS_CPU_HOOKS_EN > 0u
void  OSTaskStatHook (void)
{
#if OS_APP_HOOKS_EN > 0u
   App_TaskStatHook();
#endif
}
#endif

/*
*********************************************************************************************************
*                                        INITIALIZE A TASK'S STACK
*
* Description: This function is called by either OSTaskCreate() or OSTaskCreateExt() to initialize the
*              stack frame of the task being created.  This function is highly processor specific.
*
* Arguments  : task          is a pointer to the task code
*
*              p_arg         is a pointer to a user supplied data area that will be passed to the task
*                            when the task first executes.
*
*              ptos          is a pointer to the top of stack.  It is assumed that 'ptos' points to
*                            a 'free' entry on the task stack.  If OS_STK_GROWTH is set to 1 then
*                            'ptos' will contain the HIGHEST valid address of the stack.  Similarly, if
*                            OS_STK_GROWTH is set to 0, the 'ptos' will contains the LOWEST valid address
*                            of the stack.
*
*              opt           specifies options that can be used to alter the behavior of OSTaskStkInit().
*                            (see uCOS_II.H for OS_TASK_OPT_xxx).
*
* Returns    : Always returns the location of the new top-of-stack once the processor registers have
*              been placed on the stack in the proper order.
*
* Note(s)    : 1) Interrupts are enabled when your task starts executing.
*              2) All tasks run in Thread mode, using process stack.
*
*********************************************************************************************************
*/
#if (COMPILER==CBPLUS)
OS_STK *OSTaskStkInit (void (*task)(void *p_arg), void *p_arg, OS_STK *ptos, INT16U opt)
{
    OS_STK *stk;


    opt      = opt;                                        /* 'opt' is not used, prevent warning.                       */
    stk      = ptos;                                       /* Load stack pointer.                                       */
    *(stk) =(CPU_STK)V850ES_CTPSW;       /* CTPSW.                                                     */
    *(--stk) =(CPU_STK)V850ES_CTPC;        /* CTPC.                                                      */
    *(--stk) =(CPU_STK)V850ES_EIPSW_EN;    /* EIPSW interrupt enable                                     */
    *(--stk) =(CPU_STK)task;             /* EIPC                                                       */
    *(--stk) =(CPU_STK)OS_TaskReturn;      /* r31 Link Pointer (LP). to pass return address of function  */
    *(--stk) =(CPU_STK)0x30303030;         /* r30 Element Pointer (EP).                                  */
    *(--stk) =(CPU_STK)0x29292929;         /* r29 Used as area for register variable                     */
    *(--stk) =(CPU_STK)0x28282828;         /* r28                                                        */
    *(--stk) =(CPU_STK)0x27272727;         /* r27                                                        */
    *(--stk) =(CPU_STK)0x26262626;         /* r26                                                        */
    *(--stk) =(CPU_STK)0x25252525;         /* r25                                                        */
    *(--stk) =(CPU_STK)0x24242424;         /* r24                                                        */
    *(--stk) =(CPU_STK)0x23232323;         /* r23                                                        */
    *(--stk) =(CPU_STK)0x22222222;         /* r22                                                        */
    *(--stk) =(CPU_STK)0x21212121;         /* r21                                                        */
    *(--stk) =(CPU_STK)0x20202020;         /* r20 Used as area for register variable                     */
    *(--stk) =(CPU_STK)0x19191919;         /* r19 Working register                                       */
    *(--stk) =(CPU_STK)0x18181818;         /* r18 Working register                                       */
    *(--stk) =(CPU_STK)0x17171717;         /* r17 Working register                                       */
    *(--stk) =(CPU_STK)0x16161616;         /* r16 Working register                                       */
    *(--stk) =(CPU_STK)0x15151515;         /* r15 Working register                                       */
    *(--stk) =(CPU_STK)0x14141414;         /* r14 Working register                                       */
    *(--stk) =(CPU_STK)0x13131313;         /* r13 Working register                                       */
    *(--stk) =(CPU_STK)0x12121212;         /* r12 Working register                                       */
    *(--stk) =(CPU_STK)0x11111111;         /* r11 Working register                                       */
    *(--stk) =(CPU_STK)0x10101010;         /* r10 Function return value                                  */
    *(--stk) =(CPU_STK)0x09090909;         /* r9  Argument register                                      */
    *(--stk) =(CPU_STK)0x08080808;         /* r8  Argument register                                      */
    *(--stk) =(CPU_STK)0x07070707;         /* r7  Argument register                                      */
    *(--stk) =(CPU_STK)p_arg;                 /* r6  Argument register                                      */
    *(--stk) =(CPU_STK)0x02020202;         /* r2                                                         */
    *(--stk) =(CPU_STK)0x01010101;         /* r1  Assembler-reserved.Used for address generation         */
    return (stk);
}
#elif (COMPILER==IAR)
OS_STK *OSTaskStkInit (void (*task)(void *p_arg), void *p_arg, OS_STK *ptos, INT16U opt)
{
    OS_STK *stk;


    opt      = opt;                                        /* 'opt' is not used, prevent warning.                       */
    stk      = ptos;                                       /* Load stack pointer.                                       */
    *(stk)   =(INT32U)V850ES_EIPSW_EN;                     /* EIPSW interrupt enable                                    */
    *(--stk) =(INT32U)task;                                /* EIPC                                                      */
    *(--stk) =(INT32U)OS_TaskReturn;                       /* r31 Link Pointer (LP). to pass return address of function */
    *(--stk) =(INT32U)0x29292929;                          /* r29                                                       */
    *(--stk) =(INT32U)0x28282828;                          /* r28                                                       */
    *(--stk) =(INT32U)0x27272727;                          /* r27                                                       */
    *(--stk) =(INT32U)0x26262626;                          /* r26                                                       */
    *(--stk) =(INT32U)0x24242424;                          /* r24                                                       */
    *(--stk) =(INT32U)0x23232323;                          /* r23                                                       */
    *(--stk) =(INT32U)0x22222222;                          /* r22                                                       */
    *(--stk) =(INT32U)0x21212121;                          /* r21                                                       */
    *(--stk) =(INT32U)0x20202020;                          /* r20                                                       */
    *(--stk) =(INT32U)0x19191919;                          /* r19                                                       */
    *(--stk) =(INT32U)0x18181818;                          /* r18                                                       */
    *(--stk) =(INT32U)0x17171717;                          /* r17                                                       */
    *(--stk) =(INT32U)0x16161616;                          /* r16                                                       */
    *(--stk) =(INT32U)0x15151515;                          /* r15                                                       */
    *(--stk) =(INT32U)0x14141414;                          /* r14                                                       */
    *(--stk) =(INT32U)0x13131313;                          /* r13                                                       */
    *(--stk) =(INT32U)0x12121212;                          /* r12                                                       */
    *(--stk) =(INT32U)0x11111111;                          /* r11                                                       */
    *(--stk) =(INT32U)0x10101010;                          /* r10                                                       */
    *(--stk) =(INT32U)0x09090909;                          /* r9                                                        */
    *(--stk) =(INT32U)0x08080808;                          /* r8                                                        */
    *(--stk) =(INT32U)0x07070707;                          /* r7                                                        */
    *(--stk) =(INT32U)0x06060606;                          /* r6                                                        */
    *(--stk) =(INT32U)0x05050505;                          /* r5                                                        */
    *(--stk) =(INT32U)0x02020202;                          /* r2                                                        */
    *(--stk) =(INT32U)p_arg;                               /* r1  Argument register/ return value                       */

    return (stk);
}
#endif
/*
*********************************************************************************************************
*                                           TASK SWITCH HOOK
*
* Description: This function is called when a task switch is performed.  This allows you to perform other
*              operations during a context switch.
*
* Arguments  : none
*
* Note(s)    : 1) Interrupts are disabled during this call.
*              2) It is assumed that the global pointer 'OSTCBHighRdy' points to the TCB of the task that
*                 will be 'switched in' (i.e. the highest priority task) and, 'OSTCBCur' points to the
*                 task being switched out (i.e. the preempted task).
*********************************************************************************************************
*/

#if (OS_CPU_HOOKS_EN > 0u) && (OS_TASK_SW_HOOK_EN > 0u)
void  OSTaskSwHook (void)
{
#if OS_APP_HOOKS_EN > 0u
    App_TaskSwHook();
#endif    
}
#endif

/*
*********************************************************************************************************
*                                           OS_TCBInit() HOOK
*
* Description: This function is called by OS_TCBInit() after setting up most of the TCB.
*
* Arguments  : ptcb    is a pointer to the TCB of the task being created.
*
* Note(s)    : 1) Interrupts may or may not be ENABLED during this call.
*********************************************************************************************************
*/
#if OS_CPU_HOOKS_EN > 0u
void  OSTCBInitHook (OS_TCB *ptcb)
{
#if OS_APP_HOOKS_EN > 0u
    App_TCBInitHook(ptcb);
#else
    (void)ptcb;                                            /* Prevent compiler warning                 */
#endif
}
#endif
