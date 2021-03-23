/**
 ****************************************************************************************
 *
 * @file custom_config_ram.h
 *
 * @brief Board Support Package. User Configuration file for execution from RAM.
 *
 * Copyright (C) 2017-2019 Dialog Semiconductor.
 * This computer program includes Confidential, Proprietary Information
 * of Dialog Semiconductor. All Rights Reserved.
 *
 ****************************************************************************************
 */

#ifndef CUSTOM_CONFIG_RAM_H_
#define CUSTOM_CONFIG_RAM_H_

#include "bsp_definitions.h"


/* Enable retarget functionality */
#define CONFIG_RETARGET

/*
 * UART2 (HW_UART2) is the default selected UART block. If needed, use the
 * following macro to change to UART1 (HW_UART1) serial block:
 *
 * #define CONFIG_RETARGET_UART  HW_UART1
 */

#define dg_configUSE_LP_CLK                     LP_CLK_32768
#define dg_configCODE_LOCATION                  NON_VOLATILE_IS_NONE

#define dg_configEMULATE_OTP_COPY               (0)

#define dg_configUSE_WDOG                       (0)

#define dg_configFLASH_CONNECTED_TO             (FLASH_IS_NOT_CONNECTED)

#define dg_configBATTERY_TYPE                   (BATTERY_TYPE_LIMN2O4)
#define dg_configBATTERY_CHARGE_CURRENT         (2)     // 30mA
#define dg_configBATTERY_PRECHARGE_CURRENT      (20)    // 2.1mA
#define dg_configBATTERY_CHARGE_NTC             (1)     // disabled

#define dg_configUSE_USB                        (0)
#define dg_configUSE_USB_CHARGER                (0)
#define dg_configALLOW_CHARGING_NOT_ENUM        (1)

#define dg_configUSE_SW_CURSOR                  (1)

#define dg_configRF_ENABLE_RECALIBRATION        (0)

/* BLE not enabled (note that P0_12 used by sensor board conflicts with CMAC debug interface) */
#define dg_configENABLE_CMAC_DEBUGGER           (0)

/*************************************************************************************************\
 * FreeRTOS specific config
 */
#define OS_FREERTOS                             /* Define this to use FreeRTOS */
#define configTOTAL_HEAP_SIZE                   30000   /* This is the FreeRTOS Total Heap Size */

/*************************************************************************************************\
 * Peripheral specific config
 */
#define dg_configUSE_SNC_HW_SPI                 (1)
#define dg_configSPI_ADAPTER                    (1)
#define dg_configUSE_HW_SPI                     (1)
#define dg_configUSE_SNC_HW_GPIO                (1)
#define dg_configUSE_HW_SENSOR_NODE             (1)
#define dg_configUSE_HW_SENSOR_NODE_EMU         (0)
#define dg_configUSE_SNC_QUEUES                 (1)
#define dg_configUSE_SNC_DEBUGGER               (1)

#define dg_configFLASH_ADAPTER                  (0)
#define dg_configNVMS_ADAPTER                   (0)
#define dg_configNVMS_VES                       (0)

#define dg_configSNC_ADAPTER                    (1)

/* Include bsp default values */
#include "bsp_defaults.h"
/* Include middleware default values */
#include "middleware_defaults.h"

#endif /* CUSTOM_CONFIG_RAM_H_ */