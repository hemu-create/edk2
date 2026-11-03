/* SPDX-License-Identifier: MIT */
/*
 * Clean-room register constants derived from public Apple Silicon documentation
 * and Linux device-tree bindings.  These are register offsets and masks only;
 * no implementation code from GPL-licensed drivers is included.
 */

#ifndef WINM_REGISTERS_H
#define WINM_REGISTERS_H

#define WINM_AIC_BASE 0x2D1000000ULL

#define AIC_INFO 0x0004
#define AIC_INFO_NR_IRQ 0x0000FFFFU
#define AIC_CONFIG 0x0010
#define AIC_WHOAMI 0x2000
#define AIC_EVENT 0x2004
#define AIC_EVENT_DIE 0xFF000000U
#define AIC_EVENT_TYPE 0x00FF0000U
#define AIC_EVENT_NUM 0x0000FFFFU
#define AIC_IPI_SEND 0x2008
#define AIC_IPI_ACK 0x200C
#define AIC_IPI_MASK_SET 0x2024
#define AIC_IPI_MASK_CLR 0x2028
#define AIC_TARGET_CPU 0x3000
#define AIC_SW_GEN_SET 0x4000
#define AIC_SW_GEN_CLR 0x4080
#define AIC_MASK_SET 0x4100
#define AIC_MASK_CLR 0x4180
#define AIC_HW_IRQ_MON 0x4200

#define AIC_CPU_IPI_SET(cpu) (0x5008U + ((cpu) << 7))
#define AIC_CPU_IPI_CLR(cpu) (0x500CU + ((cpu) << 7))
#define AIC_CPU_IPI_MASK_SET(cpu) (0x5024U + ((cpu) << 7))
#define AIC_CPU_IPI_MASK_CLR(cpu) (0x5028U + ((cpu) << 7))

#define AIC_MAX_IRQ 0x400U

#define AIC2_VERSION 0x0000
#define AIC2_INFO1 0x0004
#define AIC2_INFO2 0x0008
#define AIC2_INFO3 0x000C
#define AIC2_RESET 0x0010
#define AIC2_CONFIG 0x0014

#define WINM_DART_BASE 0x2FA808000ULL

#define DART_PARAMS1 0x00
#define DART_PARAMS1_PAGE_SHIFT 24
#define DART_PARAMS2 0x04
#define DART_T8020_STREAM_COMMAND 0x20
#define DART_T8020_STREAM_SELECT 0x34
#define DART_T8020_ERROR 0x40
#define DART_T8020_ERROR_ADDR_LO 0x50
#define DART_T8020_ERROR_ADDR_HI 0x54
#define DART_T8020_CONFIG 0x60
#define DART_T8020_STREAMS_ENABLE 0xFC
#define DART_T8020_TCR 0x100
#define DART_T8020_TTBR 0x200
#define DART_T8110_PARAMS3 0x08
#define DART_T8110_PARAMS4 0x0C
#define DART_T8110_TLB_CMD 0x80
#define DART_T8110_ERROR 0x100

#define WINM_NVME_BASE 0x27BCC0000ULL

#define NVME_REG_CAP 0x00
#define NVME_REG_VS 0x08
#define NVME_REG_CC 0x14
#define NVME_REG_CSTS 0x1C
#define NVME_REG_AQA 0x24
#define NVME_REG_ASQ 0x28
#define NVME_REG_ACQ 0x30

#endif
