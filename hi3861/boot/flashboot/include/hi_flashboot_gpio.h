/*
 * Copyright (c) 2020 HiSilicon (Shanghai) Technologies CO., LIMITED.
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#ifndef __BSP_GPIO_H__
#define __BSP_GPIO_H__
#include<hi_boot_rom.h>
#define hi_io_val_set(cond, id, reg_val) \
        if (cond) \
        { \
            (reg_val) |= (hi_u16)(1 << (id)); \
        } \
        else \
        { \
            (reg_val) &= ~(hi_u16)(1 << (id)); \
        }

#define hi_io_dir_get(cond, id, val_addr) \
        if ((cond) & (hi_u16)(1 << (id))) \
        { \
            *(val_addr) = HI_GPIO_DIR_OUT; \
        } \
        else \
        { \
            *(val_addr) = HI_GPIO_DIR_IN; \
        }

#define hi_io_val_get(cond, id, val_addr) \
        if((cond) & (hi_u16)(1 << (id))) \
        { \
            *(val_addr) = HI_GPIO_VALUE1; \
        } \
        else \
        { \
            *(val_addr) = HI_GPIO_VALUE0; \
        }

/**
* @ingroup iot_gpio
*
* I/O level. CNcomment:GPIO��ƽ״̬��CNend
*/
typedef enum {
    HI_GPIO_VALUE0 = 0,      /**< Low level.CNcomment:�͵�ƽCNend*/
    HI_GPIO_VALUE1           /**< High level.CNcomment:�ߵ�ƽCNend*/
} hi_gpio_value;

/**
* @ingroup iot_gpio
*
* I/O direction. CNcomment:GPIO����CNend
*/
typedef enum {
    HI_GPIO_DIR_IN = 0,       /**< Input.CNcomment:���뷽��CNend*/
    HI_GPIO_DIR_OUT           /**< Output.CNcomment:�������CNend*/
} hi_gpio_dir;

/**
* @ingroup  iot_gpio
* @brief  Gets the direction of a single I/O pin.CNcomment:��ȡĳ��GPIO�ܽŷ���CNend
*
* @par ����:
*           Gets the direction of a single I/O pin.CNcomment:��ȡĳ��GPIO�ܽŷ���CNend
*
* @attention None
* @param  id    [IN]  type #hi_gpio_idx��I/O index.CNcomment:GPIO������CNend
* @param  dir   [OUT] type #hi_gpio_dir*��I/O direction.CNcomment:GPIO����CNend
*
* @retval #0       Success.
* @retval #Other   Failure. For details, see hi_errno.h.
* @par ����:
*           @li hi_gpio.h��Describes GPIO APIs.CNcomment:�ļ���������GPIO��ؽӿڡ�CNend
* @see  hi_gpio_set_dir
*/
hi_u32 hi_gpio_get_dir(hi_gpio_idx id, hi_gpio_dir *dir);

/**
* @ingroup  iot_gpio
* @brief  Sets the direction of a single I/O pin.CNcomment:����ĳ��GPIO�ܽŷ���CNend
*
* @par ����:
*           Sets the direction of a single I/O pin.CNcomment:����ĳ��GPIO�ܽŷ���CNend
*
* @attention None
* @param  id [IN]    type #hi_gpio_idx��I/O index.CNcomment:GPIO������CNend
* @param  dir   [IN] type #hi_gpio_dir��I/O direction.CNcomment:GPIO����CNend
*
* @retval #0       Success.
* @retval #Other   Failure. For details, see hi_errno.h.
* @par ����:
*           @li hi_gpio.h��Describes GPIO APIs.CNcomment:�ļ���������GPIO��ؽӿڡ�CNend
* @see  hi_gpio_get_dir
*/
hi_u32 hi_gpio_set_dir(hi_gpio_idx id, hi_gpio_dir dir);

/**
* @ingroup  iot_gpio
* @brief  Obtains the input level of a single I/O pin.CNcomment:��ȡĳ��IO�ܽ������ƽ״̬��CNend
*
* @par ����:
*           Obtains the input level of a single I/O pin.CNcomment:��ȡĳ��IO�ܽ������ƽ״̬��CNend
*
* @attention None
* @param  id  [IN]  type #hi_gpio_idx��I/O index.CNcomment:GPIO������CNend
* @param  val [OUT] type #hi_gpio_value*��Output value.CNcomment:���ֵ��CNend
*                 @li 0��low level.CNcomment:�͵�ƽ��CNend
*                 @li 1��high level.CNcomment:�ߵ�ƽ��CNend
*
* @retval #0       Success.
* @retval #Other   Failure. For details, see hi_errno.h.
* @par ����:
*           @li hi_gpio.h��Describes GPIO APIs.CNcomment:�ļ���������GPIO��ؽӿڡ�CNend
* @see  None
*/
hi_u32 hi_gpio_get_input_val(hi_gpio_idx id, hi_gpio_value *val);

/**
* @ingroup  iot_gpio
* @brief  Obtains the input level of a single I/O pin.CNcomment:��ȡĳ��IO�ܽ������ƽ״̬��CNend
*
* @par ����:
*           Obtains the input level of a single I/O pin.CNcomment:��ȡĳ��IO�ܽ������ƽ״̬��CNend
*
* @attention None
* @param  id  [IN]  type #hi_gpio_idx��I/O index.CNcomment:GPIO������CNend
* @param  val [OUT] type #hi_gpio_value*��Output value.CNcomment:���ֵ��CNend
*                 @li 0��low level.CNcomment:�͵�ƽ��CNend
*                 @li 1��high level.CNcomment:�ߵ�ƽ��CNend
*
* @retval #0       Success.
* @retval #Other   Failure. For details, see hi_errno.h.
* @par ����:
*           @li hi_gpio.h��Describes GPIO APIs.CNcomment:�ļ���������GPIO��ؽӿڡ�CNend
* @see  hi_gpio_set_ouput_val��
*/
hi_u32 hi_gpio_get_output_val(hi_gpio_idx id, hi_gpio_value* val);

/**
* @ingroup  iot_gpio
* @brief  Sets the output level of a single I/O pin.CNcomment:���õ���GPIO�ܽ������ƽ״̬��CNend
*
* @par ����:
*           Sets the output level of a single I/O pin.CNcomment:���õ���GPIO�ܽ������ƽ״̬��CNend
*
* @attention None
*
* @param  id [IN]    type #hi_gpio_idx��I/O index.CNcomment:GPIO������CNend
* @param  val [IN] type #hi_gpio_value��output value. CNcomment:���ֵ��CNend
*                 @li 0��low level.CNcomment:�͵�ƽ��CNend
*                 @li 1��high level.CNcomment:�ߵ�ƽ��CNend
*
* @retval #0       Success.
* @retval #Other   Failure. For details, see hi_errno.h.
* @par ����:
*           @li hi_gpio.h��Describes GPIO APIs.CNcomment:�ļ���������GPIO��ؽӿڡ�CNend
* @see  hi_gpio_get_input_val��
*/
hi_u32 hi_gpio_set_output_val(hi_gpio_idx id, hi_gpio_value val);

#endif
