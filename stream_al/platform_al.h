/* ----------------------------------------------------------------------
 * Project:      CMSIS Stream
 * Title:        xxx.c
 * Description:  
 *
 * $Date:        15 February 2023
 * $Revision:    V0.0.1
 * -------------------------------------------------------------------- */
/*
 * Copyright (C) 2010-2023 ARM Limited or its affiliates. All rights reserved.
 *
 * SPDX-License-Identifier: Apache-2.0
 *
 * Licensed under the Apache License, Version 2.0 (the License); you may
 * not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an AS IS BASIS, WITHOUT
 * WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
* 
 */
#ifndef platform_al_H
#define platform_al_H

/*------------------------*/
#include "platform_computer.h"

//#include "platform_arduino_nano33.h"
/*------------------------*/

extern uint32_t WR_BYTE_AND_CHECK_MP_(uint8_t *pt8b, uint8_t code);

#define PACK_PARAM_AL3(a,b) ((a)<<24 | (b))
#define UNPACK_PARAM_AL3_SIZE(c) ((c)&0x00FFFFFFL)
#define UNPACK_PARAM_AL3_FWIDX(c) (((uint32_t)c)>>24)

extern void platform_al(uint32_t command, uint8_t *ptr1, uint8_t *ptr2, uint32_t data3);
 
extern int32_t extract_sensor_field (const uint8_t *platform_bit_fields, 
                              const int32_t *settings,
                              uint8_t setting_line,
                              uint8_t index);




#endif /* #ifndef platform_al_H */