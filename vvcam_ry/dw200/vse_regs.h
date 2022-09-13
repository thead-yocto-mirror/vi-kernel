/****************************************************************************
 *
 * The MIT License (MIT)
 *
 * Copyright (c) 2020 VeriSilicon Holdings Co., Ltd.
 *
 * Permission is hereby granted, free of charge, to any person obtaining a
 * copy of this software and associated documentation files (the "Software"),
 * to deal in the Software without restriction, including without limitation
 * the rights to use, copy, modify, merge, publish, distribute, sublicense,
 * and/or sell copies of the Software, and to permit persons to whom the
 * Software is furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
 * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
 * DEALINGS IN THE SOFTWARE.
 *
 *****************************************************************************
 *
 * The GPL License (GPL)
 *
 * Copyright (c) 2020 VeriSilicon Holdings Co., Ltd.
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 2
 * of the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program;
 *
 *****************************************************************************
 *
 * Note: This software is released under dual MIT and GPL licenses. A
 * recipient may use this file under the terms of either the MIT license or
 * GPL License. If you wish to use only one license not the other, you can
 * indicate your decision by deleting one of the above license notices in your
 * version of this file.
 *
 *****************************************************************************/
#ifndef _VSE_REGS_H_
#define _VSE_REGS_H_

/* product identification */
#define VSE_REG_ID	0x00000000
#define VSE_REG_CTRL	0x00000004

#define VSE_CONTROL_ENABLE_RAM_CLK 17
#define VSE_CONTROL_AUTO_UPDATE_BIT 16
#define VSE_CONTROL_CONFIG_UPDATE_BIT 15
#define VSE_CONTROL_DMA_FRAME_START_BIT 14
#define VSE_CONTROL_INPUT_SELECT_SHIFT 11
#define VSE_CONTROL_INPUT_SELECT (7 << 11)
#define VSE_CONTROL_INPUT_FORMAT_SHIFT 9
#define VSE_CONTROL_INPUT_FORMAT (3 << 9)
#define VSE_CONTROL_SOFT_RESET_BIT   8
#define VSE_CONTROL_PATH2_ENABLE_BIT 2
#define VSE_CONTROL_PATH1_ENABLE_BIT 1
#define VSE_CONTROL_PATH0_ENABLE_BIT 0

/* input size 28:16 height, 12:0 width */
#define VSE_REG_IN_SIZE		0x00000008
#define VSE_REG_CTRL_SHD		0x0000000C
#define VSE_REG_RSZ0_CTL				  0x00000400
#define VSE_REG_RSZ1_CTL				  0x00000500
#define VSE_REG_RSZ2_CTL				  0x00000600
#define VSE_RSZBASE(c) ((c) == 0 ? VSE_REG_RSZ0_CTL : ((c) == 1 ? VSE_REG_RSZ1_CTL : VSE_REG_RSZ2_CTL))
#define VSE_RSZ_SCALE_HY		0x00000004
#define VSE_RSZ_SCALE_HCB		0x00000008
#define VSE_RSZ_SCALE_HCR		0x0000000C
#define VSE_RSZ_SCALE_VY		0x00000010
#define VSE_RSZ_SCALE_VC		0x00000014
#define VSE_RSZ_PHASE_HY		0x00000018
#define VSE_RSZ_PHASE_HC		0x0000001C
#define VSE_RSZ_PHASE_VY		0x00000020
#define VSE_RSZ_PHASE_VC		0x00000024
#define VSE_RSZ_SCALE_LUT_ADDR	0x00000028
#define VSE_RSZ_SCALE_LUT		0x0000002C
#define VSE_RSZ_CTRL_SHD		0x00000030
#define VSE_RSZ_SCALE_HY_SHD	0x00000034
#define VSE_RSZ_SCALE_HCB_SHD	0x00000038
#define VSE_RSZ_SCALE_HCR_SHD	0x0000003C
#define VSE_RSZ_SCALE_VY_SHD	0x00000040
#define VSE_RSZ_SCALE_VC_SHD	0x00000044
#define VSE_RSZ_PHASE_HY_SHD	0x00000048
#define VSE_RSZ_PHASE_HC_SHD	0x0000004C
#define VSE_RSZ_PHASE_VY_SHD	0x00000050
#define VSE_RSZ_PHASE_VC_SHD	0x00000054
#define VSE_RSZ_CROP_XDIR		0x00000058
#define VSE_RSZ_CROP_YDIR		0x0000005C
#define VSE_RSZ_CROP_XDIR_SHD	0x00000060
#define VSE_RSZ_CROP_YDIR_SHD	0x00000064
#define VSE_RSZ_FRAME_RATE		0x00000068
#define VSE_REG_FORMAT_CONV_CTRL	0x0000006C
#define VSE_REG_HBLANK_VALUE	0x000001A0

#define VSE_REG_VBLANK_VALUE	0x000001A4
#define VSE_REG_VSYNC_WIDTH		0x000001A8
#define VSE_REG_HSYNC_PREAMBLE	0x000001AC
#define VSE_REG_MI_CTRL				   0x00000800
#define VSE_REG_MI_CTRL_SHD			   0x00000804
#define VSE_REG_MI_PATH_0				 0x00000810
#define VSE_REG_MI_PATH_1				 0x000008b0
#define VSE_REG_MI_PATH_2				 0x00000950
#define VSE_MI_BASE(c) ((c) == 0 ? VSE_REG_MI_PATH_0 : ((c) == 1 ? VSE_REG_MI_PATH_1 : VSE_REG_MI_PATH_2))
#define VSE_REG_MI_FMT					0x00000004

#define VSE_REG_MI_Y_BASE_ADDR_INIT		0x00000014
#define VSE_REG_MI_Y_SIZE_INIT			0x00000018
#define VSE_REG_MI_Y_OFFSET_COUNT_INIT	0x0000001C
#define VSE_REG_MI_Y_LENGTH				0x00000020
#define VSE_REG_MI_Y_PIC_WIDTH			0x00000024
#define VSE_REG_MI_Y_PIC_HEIGHT			0x00000028
#define VSE_REG_MI_Y_PIC_SIZE			0x0000002C

#define VSE_REG_MI_CB_BASE_ADDR_INIT	0x00000030
#define VSE_REG_MI_CB_SIZE_INIT			0x00000034
#define VSE_REG_MI_CB_OFFSET_COUNT_INIT	0x00000038
#define VSE_REG_MI_CR_BASE_ADDR_INIT	0x0000003C
#define VSE_REG_MI_CR_SIZE_INIT			0x00000040
#define VSE_REG_MI_CR_OFFSET_COUNT_INIT	0x00000044
#define VSE_REG_MI_Y_BASE_ADDR_INIT2	0x00000048
#define VSE_REG_MI_CB_BASE_ADDR_INIT2	0x0000004C
#define VSE_REG_MI_CR_BASE_ADDR_INIT2	0x00000050
#define VSE_REG_MI_Y_OFFS_CNT_START		0x00000054
#define VSE_REG_MI_CB_OFFS_CNT_START	0x00000058
#define VSE_REG_MI_CR_OFFS_CNT_START	0x0000005C
#define VSE_REG_MI_Y_BASE_ADDR_SHD		0x00000060
#define VSE_REG_MI_Y_SIZE_SHD			0x00000064
#define VSE_REG_MI_Y_OFFS_COUNT_SHD		0x00000068
#define VSE_REG_MI_CB_BASE_ADDR_SHD		0x0000006C
#define VSE_REG_MI_CB_SIZE_SHD			0x00000070
#define VSE_REG_MI_CB_OFFS_COUNT_SHD	0x00000074
#define VSE_REG_MI_CR_BASE_ADDR_SHD		0x00000078
#define VSE_REG_MI_CR_SIZE_SHD			0x0000007C
#define VSE_REG_MI_CR_OFFS_COUNT_SHD	0x00000080
#define VSE_REG_MI_STATUS_CLR			0x00000084
#define VSE_REG_MI_CTRL_STATUS			0x00000088
#define VSE_REG_MI_Y_IRQ_OFFS_INIT		0x0000008C
#define VSE_REG_MI_Y_IRQ_OFFS_SHD		0x00000090
#define VSE_REG_DMA_CTRL				   0x000009E8
#define VSE_REG_DMA_FORMAT				 0x000009EC
#define VSE_REG_DMA_Y_PIC_WIDTH			0x000009F0
#define VSE_REG_DMA_Y_PIC_HEIGHT		   0x000009F4
#define VSE_REG_DMA_Y_PIC_STRIDE		   0x000009F8
#define VSE_REG_Y_PIC_START_ADDR		   0x000009FC
#define VSE_REG_CB_PIC_START_ADDR		  0x00000A00
#define VSE_REG_CR_PIC_START_ADDR		  0x00000A04
#define VSE_REG_Y_START_ADDR_SHD		   0x00000A08
#define VSE_REG_CB_START_ADDR_SHD		  0x00000A0C
#define VSE_REG_CR_START_ADDR_SHD		  0x00000A10
#define VSE_REG_DMA_STATUS				 0x00000A14
#define VSE_REG_MI0_BUS_CONFIG			 0x00000A20
#define VSE_REG_MI0_BUS_ID				 0x00000A24
#define VSE_REG_MI0_BUS_TIME_OUT		   0x00000A28
#define VSE_REG_MI0_AXI_STATUS			 0x00000A2C

#define VSE_REG_MI1_BUS_CONFIG			 0x00000A30
#define VSE_REG_MI1_BUS_ID				 0x00000A34
#define VSE_REG_MI1_BUS_TIME_OUT		   0x00000A38
#define VSE_REG_MI1_AXI_STATUS			 0x00000A3C

#define VSE_REG_MI_IMSC					0x00000A40
#define VSE_REG_MI_IMSC1				   0x00000A44
#define VSE_REG_MI_ISR					 0x00000A48
#define VSE_REG_MI_ISR1					0x00000A4C
#define VSE_REG_MI_MSI					 0x00000A50
#define VSE_REG_MI_MSI1					0x00000A54
#define VSE_REG_MI_ICR					 0x00000A58
#define VSE_REG_MI_ICR1					0x00000A5C
#define VSE_REG_MI_RIS					 0x00000A60
#define VSE_REG_MI_RIS1					0x00000A64

#define VSE_FORMAT_CONV_ENABLE_PACK_SHIFT 10
#define VSE_FORMAT_CONV_ENABLE_PACK (1 << 10)
#define VSE_FORMAT_CONV_EXPAND_8TO10_METHOD_SHIFT 9
#define VSE_FORMAT_CONV_EXPAND_8TO10_METHOD (1 << 9)
#define VSE_FORMAT_CONV_EXPAND_8TO10_ENABLE_SHIFT 8
#define VSE_FORMAT_CONV_EXPAND_8TO10_ENABLE (1 << 8)
#define VSE_FORMAT_CONV_CONFIG_422NOCO_SHIFT 7
#define VSE_FORMAT_CONV_CONFIG_422NOCO (1 << 7)
#define VSE_FORMAT_CONV_CBCR_FULL_SHIFT 6
#define VSE_FORMAT_CONV_CBCR_FULL  (1 << 6)
#define VSE_FORMAT_CONV_Y_FULL_SHIFT 5
#define VSE_FORMAT_CONV_Y_FULL  (1 << 5)
#define VSE_FORMAT_CONV_OUTPUT_FORMAT_SHIFT 2
#define VSE_FORMAT_CONV_OUTPUT_FORMAT  (7 << 2)
#define VSE_FORMAT_CONV_INPUT_FORMAT_SHIFT 0
#define VSE_FORMAT_CONV_INPUT_FORMAT  (3)

/* slice of VSE_REG_RSZ0_CTL */
#define VSE_RESIZE_CONTROL_AUTO_UPDATE_BIT		10
#define VSE_RESIZE_CONTROL_CONFIG_UPDATE_BIT	9
#define VSE_RESIZE_CONTROL_CROP_ENABLE_BIT		8
#define VSE_RESIZE_CONTROL_SCALE_VCUP_BIT		7
#define VSE_RESIZE_CONTROL_SCALE_VYUP_BIT		6
#define VSE_RESIZE_CONTROL_SCALE_HCUP_BIT		5
#define VSE_RESIZE_CONTROL_SCALE_HYUP_BIT		4
#define VSE_RESIZE_CONTROL_SCALE_VC_ENABLE_BIT	3
#define VSE_RESIZE_CONTROL_SCALE_VY_ENABLE_BIT	2
#define VSE_RESIZE_CONTROL_SCALE_HC_ENABLE_BIT	1
#define VSE_RESIZE_CONTROL_SCALE_HY_ENABLE_BIT	0

/* slice of VSE_REG_MI_FMT */
#define VSE_RD_IMG_HSIZE_BN_SHIFT    16
#define VSE_RD_IMG_HSIZE_BN    (0x3fff<<16)
#define VSE_MI_FORMAT_WA_MSB_EN_SHIFT 10
#define VSE_MI_FORMAT_WA_MSB_EN (1<<10)
#define VSE_MI_FORMAT_WORD_ALIGNED_SHIFT 9
#define VSE_MI_FORMAT_WORD_ALIGNED (1<<9)
#define VSE_MI_FORMAT_WR_YUV_NVY_SHIFT 7
#define VSE_MI_FORMAT_WR_YUV_NVY (3 << 7)
#define VSE_MI_FORMAT_WR_YUV_N21_SHIFT 6
#define VSE_MI_FORMAT_WR_YUV_N21 (1 << 6)
#define VSE_MI_FORMAT_WR_FMT_ALIGNED_SHIFT 5
#define VSE_MI_FORMAT_WR_FMT_ALIGNED (1 << 5)
#define VSE_MI_FORMAT_WR_YUV_STR_SHIFT 3
#define VSE_MI_FORMAT_WR_YUV_STR (3 << 3)
#define VSE_MI_FORMAT_WR_YUV_FMT_SHIFT 1
#define VSE_MI_FORMAT_WR_YUV_FMT (3 << 1)
#define VSE_MI_FORMAT_WR_YUV_10BIT_SHIFT 0
#define VSE_MI_FORMAT_WR_YUV_10BIT (1)

/* slice of VSE_REG_MI_CTRL */
#define VSE_MI_CONTROL_RDMA_START_BIT		4
#define VSE_MI_CONTROL_RDMA_ENABLE_BIT		3
#define VSE_MI_CONTROL_MI2_PATH_ENABLE_BIT	2
#define VSE_MI_CONTROL_MI1_PATH_ENABLE_BIT	1
#define VSE_MI_CONTROL_MI0_PATH_ENABLE_BIT	0

/* slice of VSE_REG_MI_PATH */
#define VSE_MI_PATH_INIT_OFFSET_EN_BIT		5
#define VSE_MI_PATH_INIT_BASE_EN_BIT		4
#define VSE_MI_PATH_CONFIG_UPDATE_BIT		3
#define VSE_MI_PATH_ENABLE_SKIP_BIT			2
#define VSE_MI_PATH_AUTO_UPDATE_BIT			1
#define VSE_MI_PATH_ENABLE_PINGPONG_BIT		0

#define VSE_MI_ISR_STATUS_DMA_YCBCR_READY_BIT	12
#define VSE_MI_ISR_STATUS_WRAP_MI2_CR_BIT		11
#define VSE_MI_ISR_STATUS_WRAP_MI2_CB_BIT		10
#define VSE_MI_ISR_STATUS_WRAP_MI2_Y_BIT		9
#define VSE_MI_ISR_STATUS_WRAP_MI1_CR_BIT		8
#define VSE_MI_ISR_STATUS_WRAP_MI1_CB_BIT		7
#define VSE_MI_ISR_STATUS_WRAP_MI1_Y_BIT		6
#define VSE_MI_ISR_STATUS_WRAP_MI0_CR_BIT		5
#define VSE_MI_ISR_STATUS_WRAP_MI0_CB_BIT		4
#define VSE_MI_ISR_STATUS_WRAP_MI0_Y_BIT		3
#define VSE_MI_ISR_STATUS_MI2_FRAME_END_BIT		2
#define VSE_MI_ISR_STATUS_MI1_FRAME_END_BIT		1
#define VSE_MI_ISR_STATUS_MI0_FRAME_END_BIT		0

#define VSE_MI_ISR_ERROR_MI2_BUS_ERROR_BIT		5
#define VSE_MI_ISR_ERROR_MI2_BUS_TIMEOUT_BIT	4
#define VSE_MI_ISR_ERROR_MI1_BUS_ERROR_BIT		3
#define VSE_MI_ISR_ERROR_MI1_BUS_TIMEOUT_BIT	2
#define VSE_MI_ISR_ERROR_MI0_BUS_ERROR_BIT		1
#define VSE_MI_ISR_ERROR_MI0_BUS_TIMEOUT_BIT	0

#define VSE_MI_BUS_CONFIG_WR_SWAP_V_SHIFT   16
#define VSE_MI_BUS_CONFIG_WR_SWAP_V (0XF << 16)
#define VSE_MI_BUS_CONFIG_WR_SWAP_U_SHIFT   12
#define VSE_MI_BUS_CONFIG_WR_SWAP_U (0XF << 12)
#define VSE_MI_BUS_CONFIG_WR_SWAP_Y_SHIFT   8
#define VSE_MI_BUS_CONFIG_WR_SWAP_Y (0XF << 8)
#define VSE_MI_BUS_CONFIG_RD_ISSUE_CAP_SHIFT   6
#define VSE_MI_BUS_CONFIG_RD_ISSUE_CAP (0X3 << 6)
#define VSE_MI_BUS_CONFIG_WR_ISSUE_CAP_SHIFT   4
#define VSE_MI_BUS_CONFIG_WR_ISSUE_CAP (0X3 << 4)
#define VSE_MI_BUS_CONFIG_RD_BURST_LEN_SHIFT   2
#define VSE_MI_BUS_CONFIG_RD_BURST_LEN (0X3 << 2)
#define VSE_MI_BUS_CONFIG_WR_BURST_LEN_SHIFT   0
#define VSE_MI_BUS_CONFIG_WR_BURST_LEN (0X3 << 0)

#ifndef REG_GET_MASK
#define REG_GET_MASK(reg, mask)\
	(((reg) & (mask)) >> (mask##_SHIFT))

#define REG_SET_MASK(reg, mask, value)\
	{\
		((reg) = (((reg) & ~(mask)) | (((value) << (mask##_SHIFT)) & (mask))));\
	}

#define REG_GET_BIT(reg, shift)\
	(((reg) & 1) >> shift)

#define REG_SET_BIT(reg, shift, value)\
	{\
		((reg) = (((reg) & ~(1 << (shift))) | (((value) & 1) << (shift))));\
	}
#endif

#endif /* _VSE_REGS_H_ */
