/*
 * Copyright (C) 2015  Freie Universität Berlin
 *
 * This file is subject to the terms and conditions of the GNU Lesser
 * General Public License v2.1. See the file LICENSE in the top level
 * directory for more details.
 */

/**
 * @defgroup    net_ieee802154 IEEE802.15.4
 * @ingroup     net
 * @brief       IEEE802.15.4 header definitions and utility functions
 * @{
 *
 * @file
 * @brief       IEEE 802.14.4 header definitions
 *
 * @author      Hauke Petersen <hauke.petersen@fu-berlin.de>
 */

#ifndef IEEE802154_H_
#define IEEE802154_H_

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @brief IEEE802.15.4 FCF field definitions
 * @{
 */
#define IEEE802154_MAX_HDR_LEN              (23U)
#define IEEE802154_FCF_LEN                  (2U)
#define IEEE802154_FCS_LEN                  (2U)

#define IEEE802154_FCF_TYPE_MASK            (0x07)
#define IEEE802154_FCF_TYPE_BEACON          (0x00)
#define IEEE802154_FCF_TYPE_DATA            (0x01)
#define IEEE802154_FCF_TYPE_ACK             (0x02)
#define IEEE802154_FCF_TYPE_MACCMD          (0x03)

#define IEEE802154_FCF_SECURITY_EN          (0x08)
#define IEEE802154_FCF_FRAME_PEND           (0x10)
#define IEEE802154_FCF_ACK_REQ              (0x20)
#define IEEE802154_FCF_PAN_COMP             (0x40)

#define IEEE802154_FCF_DST_ADDR_MASK        (0x0c)
#define IEEE802154_FCF_DST_ADDR_VOID        (0x00)
#define IEEE802154_FCF_DST_ADDR_SHORT       (0x08)
#define IEEE802154_FCF_DST_ADDR_LONG        (0x0c)

#define IEEE802154_FCF_VERS_V0              (0x00)
#define IEEE802154_FCF_VERS_V1              (0x10)

#define IEEE802154_FCF_SRC_ADDR_MASK        (0xc0)
#define IEEE802154_FCF_SRC_ADDR_VOID        (0x00)
#define IEEE802154_FCF_SRC_ADDR_SHORT       (0x80)
#define IEEE802154_FCF_SRC_ADDR_LONG        (0xc0)
/** @} */

#ifdef __cplusplus
}
#endif

#endif /* IEEE802154_H_ */
/** @} */
