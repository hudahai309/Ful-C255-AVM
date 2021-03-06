/***********************************************************************
*   Copyright (C) Huizhou Desay SV Automotive Co., Ltd.				   *
*				  All Rights Reserved.          					   *
*   Department : RN R&D SW1      									   *
*   AUTHOR	   : Shao Guangxian										   *
************************************************************************
* Object        :
* Module        :
* Instance      :
* Description   :
 file: D:/AutoSar generated code/tcbpost.h 
 automatically generated by genRH850.exe, Version: 1.06 
 Configuration file: D:/PROJECT/VICP/OIL/OIL CFG/BASELINE_EXTEND_EVENT_NOOSTM.oil 
 Generation time: Mon May 16 15:29:05 2016 
 Unlimited license CBD1500834 for Huizhou Desay SV Automotive, Product License, Instrument Panel 
 Implementation: RH850_D1M 
 Version of general code: 9.01.04 
 MISRA RULE 19.15 not violated: The QAC-Tool states a violation of rule 19.15 with message 0883,
 but there is a double include prevention and therefore the message is considered to be wrong. 
*-----------------------------------------------------------------------
* Version:
* Date:
* Author:
***********************************************************************/
/*-History--------------------------------------------------------------
* Version       Date    Name    Changes and comments
*-----------------------------------------------------------------------
* 0.1	   Jan 02,2016    Initial version
*-----------------------------------------------------------------------
* 0.2	   Dec 20,2016   ShangQiuju Add config file according using hw.
 ----------------------------------------------------------------------
* 0.3          Dec 21,2016    PEI Jingli    Add ds03h hw version selection.
 ----------------------------------------------------------------------
* 0.4    	   Jan 16,2017    RenWeimin  Add test code. Use TAUJ1I3 for capture.
*----------------------------------------------------------------------
* 0.5          Jan 24,2017    ZhangJie     Fix Coverity warning.
* ----------------------------------------------------------------------
* 0.6          Feb 07,2017    ZhangJie     Change CAN ISR from channel 0 to 2.
*----------------------------------------------------------------------
* 0.7    	   Mar 22,2017    ZhangJie    Add TAUJ1I0 for system tick counter.
*----------------------------------------------------------------------
* 0.8    	   Apr 04,2017    PEI Jingli  Delete test code.
*----------------------------------------------------------------------
* 0.9    	   Apr 13,2017    PEI Jingli  Fix intp-isr.
*=====================================================================*/

#if ! defined __TCBPOST_H__   /* PRQA S 0883 EOF */ 
#define __TCBPOST_H__
#if defined USE_QUOTE_INCLUDES
 #include "vrm.h"
#else
 #include <vrm.h>
#endif

#define osdVrmGenMajRelNum 1
#define osdVrmGenMinRelNum 6
#if defined USE_QUOTE_INCLUDES
 #include "vrm.h"
#else
 #include <vrm.h>
#endif
#include "os.h"

#define osClearTimerInterruptPoint(cnt) 
#define osHandleCounterInterrupt(cnt) 
#define osSetTimerInterruptPoint(cnt, time) osdFALSE
#define osInsertMinHeap(newItem, h, cnt) 
#define osGetCurrentTime(cnt) osCounter[cnt]


/*--------------------------------------------------------------------------*/
/*    alarms                                                                */
/*--------------------------------------------------------------------------*/
#if (osdNumberOfAlarms + osdNumberOfScheduleTables>0)
   extern osqTcbRAM1 volatile osqTcbRAM2 TickType osqTcbRAM3 osAlarmTime[osdNumberOfAlarms + osdNumberOfScheduleTables];
#else
   extern osqTcbRAM1 volatile osqTcbRAM2 TickType osqTcbRAM3 osAlarmTime[1];
#endif
#if (osdNumberOfAlarms > 0)
      extern osqTcbRAM1 volatile osqTcbRAM2 osuint8 osqTcbRAM3 osAlarmActivated[osdNumberOfAlarms];
#else
      extern osqTcbRAM1 volatile osqTcbRAM2 osuint8 osqTcbRAM3 osAlarmActivated[1];
#endif


#if (osdNumberOfAlarms > 0)
   extern osqTcbRAM1 volatile osqTcbRAM2 TickType osqTcbRAM3 osAlarmCycleTime[osdNumberOfAlarms];
#else
   extern osqTcbRAM1 volatile osqTcbRAM2 TickType osqTcbRAM3 osAlarmCycleTime[1];
#endif

#if (osdNumberOfCounters > 0)   
   extern osqROM0 osqROM1 const osqROM2 osHeapType osqROM3 oskAlarmHeaps[0];
   extern osqROM0 osqROM1 const osqROM2 osAlarmIndexType osqROM3 oskAlarmHeapSize[0];
#endif

#if (osdNumberOfAlarms > 0)   
      extern osqROM0 osqROM1 const osqROM2 TickType osqROM3 oskStaticAlarmTime[osdNumberOfAlarms];
      extern osqROM0 osqROM1 const osqROM2 TickType osqROM3 oskStaticAlarmCycleTime[osdNumberOfAlarms];
#else 
      osqROM0 extern osqROM1 const osqROM2 TickType osqROM3 oskStaticAlarmTime[1];
      osqROM0 extern osqROM1 const osqROM2 TickType osqROM3 oskStaticAlarmCycleTime[1];
#endif

#if (osdNumberOfAlarms > 0)
      osqROM0 extern osqROM1 const osqROM2 TaskType osqROM3 oskAlarmTask[osdNumberOfAlarms];
      #if (osdNumberOfAlarmSetEvent > 0)
         osqROM0 extern osqROM1 const osqROM2 EventMaskType osqROM3 oskAlarmEvent[osdNumberOfAlarms];
      #else
         osqROM0 extern osqROM1 const osqROM2 EventMaskType osqROM3 oskAlarmEvent[1];
      #endif
      osqROM0 extern osqROM1 const osqROM2 osuint8 osqROM3 oskAlarmAction[osdNumberOfAlarms];
      #if (osdNumberOfAlarmCallback > 0)
         osqROM0 extern osqROM1 const osqROM2 osAlarmCallbackType osqROM3 oskAlarmCallback[osdNumberOfAlarms];
      #else
         osqROM0 extern osAlarmCallbackType osqROM1 const osqROM2 osqROM3 oskAlarmCallback[1];
      #endif
      #if (osdNumberOfAlarmIncrementCounter > 0)
         osqROM0 extern osqROM1 const osqROM2 CounterType osqROM3 oskAlarmIncrementCounterID[osdNumberOfAlarms];
      #else
         osqROM0 extern osqROM1 const osqROM2 CounterType osqROM3 oskAlarmIncrementCounterID[1];
      #endif
#else /*if (osdNumberOfAlarms > 0)*/
      osqROM0 extern osqROM1 const osqROM2 TaskType osqROM3 oskAlarmTask[1];
      osqROM0 extern osqROM1 const osqROM2 EventMaskType osqROM3 oskAlarmEvent[1];
      osqROM0 extern osqROM1 const osqROM2 osuint8 osqROM3 oskAlarmAction[1];
      osqROM0 extern osAlarmCallbackType osqROM1 const osqROM2 osqROM3 oskAlarmCallback[1];
      osqROM0 extern osqROM1 const osqROM2 CounterType osqROM3 oskAlarmIncrementCounterID[1];
#endif /*if (osdNumberOfAlarms > 0)*/


/* Schedule Tables */ 

#if (osdNumberOfScheduleTables > 0)
extern osqROM0 osqROM1 const osqROM2 CounterType osqROM3 oskCounterOfST[osdNumberOfScheduleTables];
extern osqROM0 osqROM1 const osqROM2 TickType osqROM3 oskSTMaxAllowed[osdNumberOfScheduleTables];
extern osqROM0 osqROM1 const osqROM2 TickType osqROM3 oskScheduleTableInitialOffset[osdNumberOfScheduleTables];
extern osqROM0 osqROM1 const osqROM2 TickType osqROM3 oskAutostartScheduleTableOffset[osdNumberOfScheduleTables];
extern osqROM0 osqROM1 const osqROM2 TickType osqROM3 oskPrecision[osdNumberOfScheduleTables];
extern osqROM0 osqROM1 const osqROM2 osSTIndexType osqROM3 oskSTStartIndex[osdNumberOfScheduleTables];
extern osqROM0 osqROM1 const osqROM2 osuint8 osqROM3 oskScheduleTableAutoStart      [osdNumberOfScheduleTables];
extern osqROM0 osqROM1 const osqROM2 osuint8 osqROM3 oskScheduleTableAutoStartType  [osdNumberOfScheduleTables];
osqRAM0 extern osqRAM1 volatile osqRAM2 osSTIndexType           osqRAM3 osSTCurrentIndex[osdNumberOfScheduleTables];
osqRAM0 extern osqRAM1 volatile osqRAM2 ScheduleTableStatusType osqRAM3 osSTState[osdNumberOfScheduleTables];
osqRAM0 extern osqRAM1 volatile osqRAM2 ScheduleTableType       osqRAM3 osSTNextTable[osdNumberOfScheduleTables];
#else
extern osqROM0 osqROM1 const osqROM2 CounterType    osqROM3 oskCounterOfST                 [1];
extern osqROM0 osqROM1 const osqROM2 TickType       osqROM3 oskSTMaxAllowed                [1];
extern osqROM0 osqROM1 const osqROM2 osSTOffsetType osqROM3 oskScheduleTableInitialOffset  [1];
extern osqROM0 osqROM1 const osqROM2 TickType       osqROM3 oskAutostartScheduleTableOffset[1];
extern osqROM0 osqROM1 const osqROM2 TickType       osqROM3 oskPrecision                   [1];
extern osqROM0 osqROM1 const osqROM2 osSTIndexType  osqROM3 oskSTStartIndex                [1];
extern osqROM0 osqROM1 const osqROM2 osuint8        osqROM3 oskScheduleTableAutoStart      [1];
extern osqROM0 osqROM1 const osqROM2 osuint8        osqROM3 oskScheduleTableAutoStartType  [1];
osqRAM0 extern osqRAM1 volatile osqRAM2 osSTIndexType           osqRAM3 osSTCurrentIndex[1];
osqRAM0 extern osqRAM1 volatile osqRAM2 ScheduleTableStatusType osqRAM3 osSTState[1];
osqRAM0 extern osqRAM1 volatile osqRAM2 ScheduleTableType       osqRAM3 osSTNextTable[1];
#endif /* (osdNumberOfScheduleTables > 0) */

/* Counters */

/* Holds all counter values. Use this array only for write access.
For read access use osGetCurrentTime(). Size = #Counter */
extern osqTcbRAM1 volatile osqTcbRAM2 TickType osqTcbRAM3 osCounter[1];

/* Holds the maximum allowed value of all counters. Size = #Counter */
osqROM0 extern osqROM1 const osqROM2 TickType osqROM3 oskCounterMaxAllowedValue[1];

/* Size = #Counter */
osqROM0 extern osqROM1 const osqROM2 TickType osqROM3 oskCounterInternalMaximumValue[1];

/* Size = #Counter */
osqROM0 extern osqROM1 const osqROM2 TickType osqROM3 oskCounterHalfrange[1];

/* Size = #Counter */
osqROM0 extern osqROM1 const osqROM2 TickType osqROM3 oskCounterTicksPerBase[1];

/* Defines the minimum time between two counter actions. Size = #Counter */
osqROM0 extern osqROM1 const osqROM2 TickType osqROM3 oskCounterMinCycle[1];

/* The counters' reload values. Size = #Counter */
osqROM0 extern osqROM1 const osqROM2 TickType osqROM3 oskCounterReloadValue[1];

/* The id of the core, this counter is assigned too. Size = #Counter */
osqROM0 extern osqROM1 const osqROM2 CoreIdType osqROM3 oskCounterCoreId[1];

/* The half allowed maximum value of high resolution counter. Size = #HiResCounter */
osqROM0 extern osqROM1 const osqROM2 TickType osqROM3 oskCounterHiResMaxHardwareValueHalf[1];

/* Timer mask; n LSbs set, where n = timer bit width. Size = #HiResCounter */
osqROM0 extern osqROM1 const osqROM2 TickType osqROM3 oskHiResTimerBitMask[1];

/* The half allowed maximum value of high resolution timer. Size = #HiResCounter */
osqROM0 extern osqROM1 const osqROM2 TickType osqROM3 oskHWTimerSemiCount[1];

/* The minimum time between two high resolution timer interrupts. Size = #HiResCounter */
osqROM0 extern osqROM1 const osqROM2 TickType osqROM3 oskMinTimeBetweenTimerIrqs[1];

/* Holds the last time of a high resolution timer interrupt. Size = #HiResCounter */
extern osqTcbRAM1 volatile osqTcbRAM2 TickType osqTcbRAM3 osLastHighResTimerIrq[1];

/* Holds the time of the next allowed high resolution interrupt. Size = #HiResCounter */
extern osqTcbRAM1 volatile osqTcbRAM2 TickType osqTcbRAM3 osNextAllowedTimerInt[1];

#define osReleaseHiResTimerISR(counterId) 

#define osTriggerHiResTimerISR(counterId) 

#define osGetHWTimerCounterValue(counterId) 0

#define osSetHWTimerDeltaValue(counterId,timeToSet) 

#define osSetHWTimerCompareValue(counterId,timeToSet) 
#if ((CC == BCC2) || (CC == ECC2))
   #if (osdNumberOfAllTasks > 0)
      extern volatile osqTcbRAM1 osqTcbRAM2 osActivationCountType osqTcbRAM3 osTcbActivationCount[osdNumberOfAllTasks];
   #else
      extern volatile osqTcbRAM1 osqTcbRAM2 osActivationCountType osqTcbRAM3 osTcbActivationCount[1];
   #endif
#endif

extern osqTcbRAM1 osqTcbRAM2 osCtrlVarType osqTcbRAM3 osCtrlVarsCore0;
   extern osqTcbRAM1 volatile osqTcbRAM2 EventMaskType osqTcbRAM3 osTcbWaitEventMask[osdNumberOfExtendedTasks];



#if ((osdSC == SC3) || (osdSC == SC4))
   extern osqTcbRAM1 volatile osqTcbRAM2 ApplicationStateType osqTcbRAM3 osApplicationState [osdNumberOfApplications];
#endif



#if (osdNumberOfAllTasks > 0)
  osqROM0 extern osqROM1 const osqROM2 osTaskFlagType osqROM3 oskTcbTaskFlags[osdNumberOfAllTasks];
#if (osdNumberOfExtendedTasks > 0) || osdLib
   extern osqTcbRAM1 volatile osqTcbRAM2 EventMaskType osqTcbRAM3 osTcbSetEventMask[osdNumberOfExtendedTasks];
#endif
#else
   #if STATUS_LEVEL == EXTENDED_STATUS
      osqROM0 extern osqROM1 const osqROM2 osTaskFlagType osqROM3 oskTcbTaskFlags[1];
   #endif
#if (osdNumberOfExtendedTasks > 0) || osdLib
      extern osqTcbRAM1 volatile osqTcbRAM2 EventMaskType osqTcbRAM3 osTcbSetEventMask[1];
#endif                                                 
#endif

#if (osdNumberOfAllTasks > 0)
   extern osqTcbRAM1 volatile osqTcbRAM2 osTaskStateType osqTcbRAM3 osTcbTaskState[osdNumberOfAllTasks];
   #if osdORTIDebug
    extern osqTcbRAM1 osqTcbRAM2 osPrioType osqTcbRAM3 osTcbActualPrio[osdNumberOfAllTasks];
    extern osqTcbRAM1 osqTcbRAM2 osuint8 osqTcbRAM3 osTcbORTIServiceId[osdNumberOfAllTasks];
   #endif
   #if STATUS_LEVEL == EXTENDED_STATUS
    #if (osdNumberOfInternalResources > 0) || (osdNumberOfInterruptResources > 0)
     extern osqTcbRAM1 osqTcbRAM2 osuint8 osqTcbRAM3 osTcbResourceCounter[osdNumberOfAllTasks];
    #endif
   #endif

#else
   extern osqTcbRAM1 volatile osqTcbRAM2 osTaskStateType osqTcbRAM3 osTcbTaskState[1];
   #if osdORTIDebug
   extern osqTcbRAM1 osqTcbRAM2 osPrioType osqTcbRAM3 osTcbActualPrio[1];
   extern osqTcbRAM1 osqTcbRAM2 osuint8 osqTcbRAM3 osTcbORTIServiceId[1];
   #endif

   #if STATUS_LEVEL == EXTENDED_STATUS
   #if (osdNumberOfInternalResources > 0) || (osdNumberOfInterruptResources > 0)
   extern osqTcbRAM1 osqTcbRAM2 osuint8 osqTcbRAM3 osTcbResourceCounter[1];
   #endif
   #endif
#endif

/* Resources */

#if (osdNumberOfAllResources > 0)
   #if ((!defined(osdGetResourceNotUsed)) || (!defined(osdReleaseResourceNotUsed)))
      extern osqTcbRAM1 osqTcbRAM2 osPrioType osqTcbRAM3 osResSavedPrio[osdNumberOfAllResources];
   #endif
   #if STATUS_LEVEL == EXTENDED_STATUS && ((!defined(osdGetResourceNotUsed)) || (!defined(osdReleaseResourceNotUsed)))
      extern osqTcbRAM1 osqTcbRAM2 osResCounterType osqTcbRAM3 osResOccupationCounter[osdNumberOfAllResources];
   #endif
   #if ((STATUS_LEVEL == EXTENDED_STATUS) && osdEnableAssertions && ((!defined(osdGetResourceNotUsed)) || (!defined(osdReleaseResourceNotUsed)))) || osdORTIDebug
      extern osqTcbRAM1 osqTcbRAM2 TaskType osqTcbRAM3 osResActualTask[osdNumberOfAllResources];
   #endif
   
   #if (!defined(osdGetResourceNotUsed)) || (!defined(osdReleaseResourceNotUsed))
      extern osqROM0 osqROM1 const osqROM2 osPrioType osqROM3 oskResCeilingPrio[osdNumberOfAllResources];
   #endif
#else
   #if ((!defined(osdGetResourceNotUsed)) || (!defined(osdReleaseResourceNotUsed)))
      extern osqTcbRAM1 osqTcbRAM2 osPrioType osqTcbRAM3 osResSavedPrio[1];
   #endif
   #if STATUS_LEVEL == EXTENDED_STATUS && ((!defined(osdGetResourceNotUsed)) || (!defined(osdReleaseResourceNotUsed)))
      extern osqTcbRAM1 osqTcbRAM2 osResCounterType osqTcbRAM3 osResOccupationCounter[1];
   #endif
   #if ((STATUS_LEVEL == EXTENDED_STATUS) && osdEnableAssertions && ((!defined(osdGetResourceNotUsed)) || (!defined(osdReleaseResourceNotUsed)))) || osdORTIDebug
      extern osqTcbRAM1 osqTcbRAM2 TaskType osqTcbRAM3 osResActualTask[1];
   #endif
   
   #if (!defined(osdGetResourceNotUsed)) || (!defined(osdReleaseResourceNotUsed))
   extern osqROM0 osqROM1 const osqROM2 osPrioType osqROM3 oskResCeilingPrio[1];
   #endif
#endif
#if (!defined(osdGetResourceNotUsed)) || (!defined(osdReleaseResourceNotUsed))
 #if (osdNumberOfTaskResources > 0)
   #if (osdRTSize > 1)
      extern osqROM0 osqROM1 const osqROM2 osPrioOffsetType osqROM3 oskResCeilingPrioOffset[osdNumberOfTaskResources];
   #endif
   extern osqROM0 osqROM1 const osqROM2 osPrioFlagType osqROM3 oskResCeilingPrioMask[osdNumberOfTaskResources];
 #else
   #if (osdRTSize > 1)
      extern osqROM0 osqROM1 const osqROM2 osPrioOffsetType osqROM3 oskResCeilingPrioOffset[1];
   #endif
   extern osqROM0 osqROM1 const osqROM2 osPrioFlagType osqROM3 oskResCeilingPrioMask[1];
 #endif
#endif /* (!defined(osdGetResourceNotUsed)) || (!defined(osdReleaseResourceNotUsed)) */

#if (osdNumberOfInternalResources > 0)
   extern osqROM0 osqROM1 const osqROM2 osPrioType osqROM3 oskResInternalCeilingPrio[osdNumberOfAllTasks];
   extern osqROM0 osqROM1 const osqROM2 osPrioFlagType osqROM3 oskResInternalCeilingPrioMask[osdNumberOfAllTasks];
   #if (osdRTSize > 1)
      extern osqROM0 osqROM1 const osqROM2 osPrioOffsetType osqROM3 oskResInternalCeilingPrioOffset[osdNumberOfAllTasks];
   #endif
#endif
#if (osdNumberOfSemaphores > 0)
   extern osqTcbRAM1 osqTcbRAM2 osuint8 osqTcbRAM3 osSemaphoreState[osdNumberOfSemaphores];
   #if (osdNumberOfExtendedTasks == 0) && osdLib
   extern osqTcbRAM1 volatile osqTcbRAM2 osSemaphoreType osqTcbRAM3 osTcbWaitForSemaphore[1];
   #else
   extern osqTcbRAM1 volatile osqTcbRAM2 osSemaphoreType osqTcbRAM3 osTcbWaitForSemaphore[osdNumberOfExtendedTasks];
   #endif
   #if (osdKillTaskIsrPossible || (osdSC== SC3) || (osdSC== SC4))
      extern osqTcbRAM1 volatile osqTcbRAM2 TaskType osqTcbRAM3 osSemaOwner[osdNumberOfSemaphores];
   #endif
#endif

#if osdLib
   #define osrRTSize                     oskRTSize 
   #define osrNumberOfPriorities         oskNumberOfPriorities
   #define osrNumberOfAppModes           oskNumberOfAppModes
   #define osrNumberOfAllTasks           oskNumberOfAllTasks
   #define osrNumberOfAllResources       oskNumberOfAllResources
   #define osrNumberOfTaskResources      oskNumberOfTaskResources
   #define osrNumberOfInterruptResources oskNumberOfInterruptResources
   #define osrNumberOfInternalResources  oskNumberOfInternalResources
   #define osrNumberOfExtendedTasks      oskNumberOfExtendedTasks
   #define osrNumberOfAlarms             oskNumberOfAlarms
   #define osrNumberOfScheduleTables     oskNumberOfScheduleTables
   #define osrNumberOfSemaphores         oskNumberOfSemaphores
   #define osrSystemTimer                oskSystemTimer
   #define osrNumberOfCounters           oskNumberOfCounters

   extern const osRTSizeType               oskRTSize;
   extern const osAppModeIndexType         oskNumberOfAppModes;
   extern const osTaskIndexType            oskNumberOfAllTasks;
   extern const osTaskIndexType            oskNumberOfExtendedTasks;
   extern const osPrioType                 oskNumberOfPriorities;
   extern const osResourceIndexType        oskNumberOfAllResources;
   extern const osResourceIndexType        oskNumberOfTaskResources;
   extern const osResourceIndexType        oskNumberOfInterruptResources;
   extern const osResourceIndexType        oskNumberOfInternalResources;

   extern const osAlarmIndexType           oskNumberOfAlarms;

   extern const ScheduleTableType          oskNumberOfScheduleTables;
   extern const osSemaphoreType            oskNumberOfSemaphores;
   extern const CounterType                oskSystemTimer;
   extern const CounterType                oskNumberOfCounters;

   extern const TickType oskMaxAllowedValue;
   extern const TickType oskTicksPerBase;
   extern const TickType oskMinCycle;
   extern const osuint8 oskAlarmAutoStart[];

   extern const osuint8 oskTcbAutoStart[];


   extern const osVersionVariantCodingType oskLibVersionVariant;

#else
   #define osrRTSize                      osdRTSize 
   #define osrNumberOfPriorities          osdNumberOfPriorities 
   #define osrNumberOfAppModes            osdNumberOfAppModes
   #define osrNumberOfAllTasks            osdNumberOfAllTasks
   #define osrNumberOfAllResources        osdNumberOfAllResources
   #define osrNumberOfTaskResources       osdNumberOfTaskResources
   #define osrNumberOfInterruptResources  osdNumberOfInterruptResources
   #define osrNumberOfInternalResources   osdNumberOfInternalResources
   #define osrNumberOfExtendedTasks       osdNumberOfExtendedTasks
   #define osrNumberOfAlarms              osdNumberOfAlarms
   #define osrNumberOfScheduleTables      osdNumberOfScheduleTables
   #define osrNumberOfSemaphores          osdNumberOfSemaphores
   #define osrNumberOfCounters            osdNumberOfCounters
   /* in source code variant map hook routines directly to user functions */
#endif

osqROM0 extern osStackPtrType osqROM1 const osqROM2 osqROM3  oskSystemStackTop;

/* End of invariant part */
#if (osdKillTaskIsrPossible || (osdSC == SC3) || (osdSC == SC4))
#if (osdNumberOfCat2ISRs > 0)
   extern osqTcbRAM1 osqTcbRAM2 osResourceIndexType osqTcbRAM3 osIcbLockedResource[osdNumberOfCat2ISRs];
#else
   extern osqTcbRAM1 osqTcbRAM2 osResourceIndexType osqTcbRAM3 osIcbLockedResource[1];
#endif
#endif

/* Tasks */ 
#define SystemSwitchHigh ((TaskType)0)
#define FastCyclic ((TaskType)1)
#define EventTask ((TaskType)2)
#define SlowCyclic ((TaskType)3)
#define SlowJob ((TaskType)4)
#define SystemSwitchLow ((TaskType)5)
#define ResetTask ((TaskType)6)

/* Task function prototypes */ 
void SystemSwitchHighfunc(void);
void FastCyclicfunc(void);
void EventTaskfunc(void);
void SlowCyclicfunc(void);
void SlowJobfunc(void);
void SystemSwitchLowfunc(void);
/*void ResetTaskfunc(void);*/
extern void InitTaskEntry(void);
/*
extern void SysCycle_FastTaskEntry(void);
extern void SysEvt_TaskEntry(void);
extern void SysCycle_SlowTaskEntry(void);
extern void SysJob_TaskEntry(void);
extern void SysSwitch_LowTaskEntry(void);
extern void SysSwitch_HighTaskEntry(void);
extern void InitTaskEntry(void *p_arg);
*/

osqROM0 extern osqROM1 const osqROM2 osTaskFlagType osqROM3 oskTcbTaskFlags[osdNumberOfAllTasks];
osqROM0 extern osqROM1 const osqROM2 osPrioFlagType osqROM3 oskTcbReadyPrioMask[osdNumberOfAllTasks];
#if (osdRTSize > 1)
osqROM0 extern osqROM1 const osqROM2 osPrioOffsetType osqROM3 oskTcbReadyPrioOffset[osdNumberOfAllTasks];
#endif /* (osdRTSize > 1) */
osqROM0 extern osqROM1 const osqROM2 osPrioType osqROM3 oskTcbHomePrio[osdNumberOfAllTasks];
#if (CC == BCC2) || (CC == ECC2)
osqROM0 extern osqROM1 const osqROM2 osActivationCountType osqROM3 oskTcbAllowedActivations[osdNumberOfAllTasks];
#endif /* (CC == BCC2) || (CC == ECC2) */

/* ISRs */ 

/* ISR categories */ 
#define osdIsrISR_CAN1ERRCat 2
#define osdIsrISR_CAN1RECCat 2
#define osdIsrISR_CAN1TRXCat 2
#define osdIsrISR_CANGERRCat 2
#define osdIsrISR_CANGRECCCat 2
#define osdIsrISR_TAUB0I0Cat 2
#define osdIsrISR_TAUD0I15Cat 2
#define osdIsrISR_TAUJ0I0Cat 2
#define osdIsrISR_TAUJ1I0Cat 2
#define osdIsrISR_WDTA0Cat 2
#define osdIsrosTrapDispatcher_c0Cat 1

/* ISR IDs */ 
#define ISR_CAN1ERR ((ISRType)0)
#define ISR_INTP10 ((ISRType)1)
#define ISR_CAN1TRX ((ISRType)2)
#define ISR_CANGERR ((ISRType)3)
#define ISR_CANGRECC ((ISRType)4)
#define ISR_TAUB0I0 ((ISRType)5)
#define ISR_TAUD0I15 ((ISRType)6)
#define ISR_TAUJ0I0 ((ISRType)7)
#define ISR_TAUJ1I0 ((ISRType)8)
#define ISR_WDTA0 ((ISRType)9)
#define ISR_IIC0RI ((ISRType)10)
#define ISR_IIC0TI ((ISRType)11)
#define ISR_IIC0TEI ((ISRType)12)
#define ISR_IIC0EE ((ISRType)13)
#define ISR_ADCA0_INTSG1 ((ISRType)14)
#define ISR_CSIH1IR ((ISRType)15)
#define ISR_CSIH1IC ((ISRType)16)

#define ISR_UART0_Tx ((ISRType)17)
#define ISR_UART0_Rx ((ISRType)18)
#define ISR_UART0_Error ((ISRType)19)
#define ISR_OSTM0 ((ISRType)20)

#define ISR_CSIH0IR ((ISRType)21)
#define ISR_CSIH0IC ((ISRType)22)
#define ISR_CSIH0IRE ((ISRType)23)
#define ISR_CSIH1IRE ((ISRType)24)
#define ISR_TAUD0I6 ((ISRType)25)
#define ISR_TAUJ1I2 ((ISRType)26)

#define ISR_INTP6	((ISRType) 27)
#define ISR_TAUD0I2	((ISRType)28)
#define ISR_UART3_Tx ((ISRType)29)
#define ISR_UART3_Rx ((ISRType)30)
#define ISR_UART3_Error ((ISRType)31)
#define ISR_INTP3	((ISRType)32)
#define ISR_TAUB0I11 ((ISRType)33)
#define ISR_UART2_Tx ((ISRType)34)
#define ISR_UART2_Rx ((ISRType)35)
#define ISR_UART2_Error ((ISRType)36)



#if ((osdSC== SC3) || (osdSC== SC4))
#endif

/* ISR function prototypes */ 
void CanIsrStatus_1func(void);
void CanIsrWakeup_1func(void);
void CanIsrTx_1func(void);
void CanIsrGlobalStatusfunc(void);
void CanIsrRxFifofunc(void);
void ISR_TAUB0I0func(void);
void ISR_TAUD0I15func(void);
void ISR_TAUJ0I0func(void);
void ISR_TAUJ1I0func(void);
void ISR_WDTA0func(void);
void osTrapDispatcher_c0(void);

void ISR_CAN1ERR_CAT2(void);
void ISR_CAN1REC_CAT2(void);
void ISR_CAN1TRX_CAT2(void);
void ISR_CANGERR_CAT2(void);
void ISR_CANGRECC_CAT2(void);
void ISR_TAUB0I0_CAT2(void);
void ISR_TAUD0I15_CAT2(void);
void ISR_TAUJ0I0_CAT2(void);
void ISR_TAUJ1I0_CAT2(void);
void ISR_WDTA0_CAT2(void);
void ISR_IIC0RIfunc(void);
void ISR_IIC0TIfunc(void);
void ISR_IIC0TEIfunc(void);
void ISR_IIC0EEfunc(void);
void ISR_ADCA0_INTSG1func(void);
void CSIH1_Rx_handler(void);
void CSIH1_Tx_handler(void);
void UART0_Tx_Handler(void);
void UART0_Rx_Handler(void);
void UART0_Error_Handler(void);
void ISR_OSTM0func(void);


void CSIH0_Rx_handler();
void CSIH0_Tx_handler(void);
void CSIH0_Error_handler(void);
void CSIH1_Error_handler(void);
void ISR_TAUD0I6func(void);
void ISR_TAUJ1I2func(void);
void ISR_TAUD0I2_handler(void);
void ISR_INTP6_Handler(void);

void UART3_Tx_Handler(void);
void UART3_Rx_Handler(void);
void UART3_Error_Handler(void);
void ISR_INTP3_Handler(void);
void ISR_TAUB0I11func(void);
void UART2_Tx_Handler(void);
void UART2_Rx_Handler(void);
void UART2_Error_Handler(void);



#if (osdNumberOfAlarms > 0)
 osqROM0 extern osqROM1 const osqROM2 osuint8 osqROM3 oskAlarmAutoStart[osdNumberOfAlarms];
#endif

#if (osdNumberOfAlarms > 0)
extern osqROM0 osqROM1 const osqROM2 osuint8 osqROM3 oskAlarmAutoStartType  [osdNumberOfAlarms];
#endif

#if (osdNumberOfAllTasks > 0)
 osqROM0 extern osqROM1 const osqROM2 osuint8 osqROM3 oskTcbAutoStart[osdNumberOfAllTasks];
#endif

#define osdNumberOfAppModes 1
#define OSDEFAULTAPPMODE 1
/* Events */ 
#define EventTskEvt ((EventMaskType)(0x01))
#define FastCycEvt ((EventMaskType)(0x01))
#define SlowCycEvt ((EventMaskType)(0x01))
#define SlowJobEvt ((EventMaskType)(0x01))
#define SysSwitchHiEvt ((EventMaskType)(0x01))
#define SysSwitchLoEvt ((EventMaskType)(0x01))
/* Alarms */ 
/* prototypes for alarm callback functions */

#pragma ghs startdata
/* MISRA RULE 8.12 VIOLATION: (2 times) The compiler requires the [] notation and the size of the 
   sections is unknown at generation time. No problem because the symbols are never used as arrays. */
extern osuint32 osExceptionVectorTable_c0[]; /* PRQA S 3684 */
extern osuint32 osEIINTVectorTable_c0[]; /* PRQA S 3684 */
#pragma ghs enddata

#if (osdKillTaskIsrPossible || (osdSC== SC3) || (osdSC== SC4))
#if (osdNumberOfAllTasks > 0)
   extern osqTcbRAM1 osqTcbRAM2 osResourceIndexType osqTcbRAM3 osTcbLockedResource[osdNumberOfAllTasks];
#else
   extern osqTcbRAM1 osqTcbRAM2 osResourceIndexType osqTcbRAM3 osTcbLockedResource[1];
#endif
#endif
/* Resources */



#if (STATUS_LEVEL == EXTENDED_STATUS) && osdEnableAssertions
 #if ((!defined(osdGetResourceNotUsed)) || (!defined(osdReleaseResourceNotUsed)))
osqROM0 extern osqROM1 const osqROM2 osResAccessMaskType osqROM3 oskResAccessMask[1][1];


 #endif /* ((!defined(osdGetResourceNotUsed)) || (!defined(osdReleaseResourceNotUsed))) */
#endif /* (STATUS_LEVEL == EXTENDED_STATUS) && osdEnableAssertions */

#if (osdKillTaskIsrPossible || (osdSC == SC3) || (osdSC == SC4))
#if (osdNumberOfAllResources > 0)
   extern osqTcbRAM1 osqTcbRAM2 osResourceIndexType osqTcbRAM3 osResNextLockedResource[osdNumberOfAllResources];
#else
   extern osqTcbRAM1 osqTcbRAM2 osResourceIndexType osqTcbRAM3 osResNextLockedResource[1];
#endif
#endif


#if ((osdSC== SC3) || (osdSC== SC4))
#endif


/* END OF D:\AutoSar generated code\tcb.h */

#endif /* ! defined __TCBPOST_H__ */
