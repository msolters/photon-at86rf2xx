/*
 * Copyright (C) 2013 Alaeddine Weslati <alaeddine.weslati@inria.fr>
 * Copyright (C) 2015 Freie Universität Berlin
 *
 * This file is subject to the terms and conditions of the GNU Lesser General
 * Public License v2.1. See the file LICENSE in the top level directory for more
 * details.
 */

/**
 * @{
 *
 * @file
 * @brief       Internal interfaces for AT86RF2xx drivers
 *
 * @author      Alaeddine Weslati <alaeddine.weslati@inria.fr>
 * @author      Thomas Eichinger <thomas.eichinger@fu-berlin.de>
 * @author      Hauke Petersen <hauke.petersen@fu-berlin.de>
 * @author      Mark Solters <msolters@gmail.com>
 */

#ifndef AT86RF2XX_INTERNAL_H_
#define AT86RF2XX_INTERNAL_H_

#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @brief   Transition time from SLEEP to TRX_OFF in us, refer figure 7-4, p.42.
 *          For different environments refer figure 13-13, p.201
 */
#define AT86RF2XX_WAKEUP_DELAY          (300U)

/**
 * @brief   Minimum reset pulse width, refer p.190
 */
#define AT86RF2XX_RESET_PULSE_WIDTH     (1U)

/**
 * @brief   Transition time to TRX_OFF after reset pulse in us, refer
 *          figure 7-8, p. 44.
 */
#define AT86RF2XX_RESET_DELAY           (26U)

/**
 * @brief   Read from a register at address `addr` from device `dev`.
 *
 * @param[in] addr      address of the register to read
 *
 * @return              the value of the specified register
 */
uint8_t at86rf2xx_reg_read(const uint8_t addr);

/**
 * @brief   Write to a register at address `addr` from device `dev`.
 *
 * @param[in] addr      address of the register to write
 * @param[in] value     value to write to the given register
 */
void at86rf2xx_reg_write(const uint8_t addr,
                         const uint8_t value);

/**
 * @brief   Read a chunk of data from the SRAM of the given device
 *
 * @param[in]  offset   starting address to read from [valid 0x00-0x7f]
 * @param[out] data     buffer to read data into
 * @param[in]  len      number of bytes to read from SRAM
 */
void at86rf2xx_sram_read(const uint8_t offset,
                         uint8_t *data,
                         const size_t len);

/**
 * @brief   Write a chunk of data into the SRAM of the given device
 *
 * @param[in] offset    address in the SRAM to write to [valid 0x00-0x7f]
 * @param[in] data      data to copy into SRAM
 * @param[in] len       number of bytes to write to SRAM
 */
void at86rf2xx_sram_write(const uint8_t offset,
                          const uint8_t *data,
                          const size_t len);

/**
 * @brief   Read the internal frame buffer of the given device
 *
 * Reading the frame buffer returns some extra bytes that are not accessible
 * through reading the RAM directly.
 *
 * @param[out] data     buffer to copy the data to
 * @param[in]  len      number of bytes to read from the frame buffer
 */
void at86rf2xx_fb_read(uint8_t *data, const size_t len);

/**
 * @brief   Cancel ongoing transactions and switch to TRX_OFF state
 *
 */
void at86rf2xx_force_trx_off();

/**
 * @brief   Convenience function for reading the status of the given device
 *
 * @return              internal status of the given device
 */
uint8_t at86rf2xx_get_status();

/**
 * @brief   Make sure that device is not sleeping
 *
 */
void at86rf2xx_assert_awake();

/**
 * @brief   Trigger a hardware reset
 *
 */
void at86rf2xx_hardware_reset();


#ifdef __cplusplus
}
#endif

#endif /* AT86RF2XX_INTERNAL_H_ */
/** @} */