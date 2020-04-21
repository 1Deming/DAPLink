/**
 * @file    stm32f103rb.c
 * @brief   board ID for the STM32 NUCLEO-F103RB board
 *
 * DAPLink Interface Firmware
 * Copyright (c) 2009-2019, ARM Limited, All Rights Reserved
 * SPDX-License-Identifier: Apache-2.0
 *
 * Licensed under the Apache License, Version 2.0 (the "License"); you may
 * not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS, WITHOUT
 * WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#include "target_family.h"
#include "target_board.h"

#define USEL152
//#define USEL031

//modified this file content can use for other MCU

#ifdef USEL152
board_info_t g_board_info = {
    .info_version = kBoardInfoVersion,
    .board_id = "0712",
    .family_id = kStub_HWReset_FamilyID,
    .target_cfg = &l152_target_device,        
};
#endif


#ifdef USEL031
board_info_t g_board_info = {
    .info_version = kBoardInfoVersion,
    .board_id = "0724",
    .family_id = kStub_HWReset_FamilyID,
    .target_cfg = &l031_target_device,
};
#endif
