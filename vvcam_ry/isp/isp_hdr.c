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
#ifdef __KERNEL__
#include <linux/io.h>
#include <linux/module.h>
#endif
#include "mrv_all_bits.h"
#include "isp_ioctl.h"
#include "isp_types.h"

extern MrvAllRegister_t *all_regs;

int isp_s_hdr(struct isp_ic_dev *dev)
{
	struct isp_hdr_context *hdr = &dev->hdr;
	u32 isp_stitching_ctrl =
	    isp_read_reg(dev, REG_ADDR(isp_stitching_ctrl));
	u32 val;
	int i;

	isp_info("enter %s\n", __func__);

	val = 0;
#if 0
	REG_SET_SLICE(val, STITCHING_FRAME_WIDTH, hdr->width);
	isp_write_reg(dev, REG_ADDR(isp_stitching_frame_width), val);

	val = 0;
	REG_SET_SLICE(val, STITCHING_FRAME_HEIGHT, hdr->height);
	isp_write_reg(dev, REG_ADDR(isp_stitching_frame_height), val);

	val = 0;
	REG_SET_SLICE(val, STITCHING_L_BIT_DEPTH, hdr->l_bit_dep);
	REG_SET_SLICE(val, STITCHING_S_BIT_DEPTH, hdr->s_bit_dep);
	REG_SET_SLICE(val, STITCHING_VS_BIT_DEPTH, hdr->vs_bit_dep);
	REG_SET_SLICE(val, STITCHING_LS_BIT_DEPTH, hdr->ls_bit_dep);
	isp_write_reg(dev, REG_ADDR(isp_stitching_exposure_bit), val);

	val = 0;
	REG_SET_SLICE(val, STITCHING_COLOR_WEIGHT_0, hdr->weight0);
	REG_SET_SLICE(val, STITCHING_COLOR_WEIGHT_1, hdr->weight1);
	REG_SET_SLICE(val, STITCHING_COLOR_WEIGHT_2, hdr->weight2);
	isp_write_reg(dev, REG_ADDR(isp_stitching_color_weight), val);

	val = 0;
	REG_SET_SLICE(val, STITCHING_TRANS_RANGE_START_LINEAR,
		      hdr->start_linear);
	REG_SET_SLICE(val, STITCHING_TRANS_RANGE_NORM_FACTOR_MUL_LINEAR,
		      hdr->norm_factor_mul_linear);
	isp_write_reg(dev, REG_ADDR(isp_stitching_trans_range_linear), val);

	val = 0;
	REG_SET_SLICE(val, STITCHING_TRANS_RANGE_START_NONLINEAR,
		      hdr->start_nonlinear);
	REG_SET_SLICE(val, STITCHING_TRANS_RANGE_NORM_FACTOR_MUL_NONLINEAR,
		      hdr->norm_factor_mul_nonlinear);
	isp_write_reg(dev, REG_ADDR(isp_stitching_trans_range_nonlinear), val);

	val = 0;
	REG_SET_SLICE(val, STITCHING_DUMMY_HBLANK, hdr->dummy_hblank);
	REG_SET_SLICE(val, STITCHING_OUT_HBLANK, hdr->out_hblank);
	isp_write_reg(dev, REG_ADDR(isp_stitching_out_hblank), val);

	val = 0;
	REG_SET_SLICE(val, STITCHING_OUT_VBLANK, hdr->out_vblank);
	isp_write_reg(dev, REG_ADDR(isp_stitching_out_vblank), val);

	val = 0;
	REG_SET_SLICE(val, STITCHING_LONG_EXPOSURE_TIME, hdr->long_exp);
	isp_write_reg(dev, REG_ADDR(isp_stitching_long_exposure), val);

	val = 0;
	REG_SET_SLICE(val, STITCHING_SHORT_EXPOSURE_TIME, hdr->short_exp);
	isp_write_reg(dev, REG_ADDR(isp_stitching_short_exposure), val);

	val = 0;
	REG_SET_SLICE(val, STITCHING_VERY_SHORT_EXPOSURE_TIME,
		      hdr->very_short_exp);
	isp_write_reg(dev, REG_ADDR(isp_stitching_very_short_exposure), val);

	val = 0;
	REG_SET_SLICE(val, STITCHING_LONG_EXPOSURE_TIME, hdr->long_exp);
	isp_write_reg(dev, REG_ADDR(isp_stitching_long_exposure), val);
#endif
	val = 0;
	REG_SET_SLICE(val, STITCHING_RATIO_LONG_SHORT_1, hdr->ls1);
	REG_SET_SLICE(val, STITCHING_RATIO_LONG_SHORT_0, hdr->ls0);
	isp_write_reg(dev, REG_ADDR(isp_stitching_ratio_ls), val);

	val = 0;
	REG_SET_SLICE(val, STITCHING_RATIO_VERYSHORT_SHORT_1, hdr->vs1);
	REG_SET_SLICE(val, STITCHING_RATIO_VERYSHORT_SHORT_0, hdr->vs0);
	isp_write_reg(dev, REG_ADDR(isp_stitching_ratio_vs), val);

	val = 0;
	REG_SET_SLICE(val, STITCHING_SHORT_EXTEND_BIT, hdr->ext_bit);
	REG_SET_SLICE(val, STITCHING_VERYSHORT_VALID_THRESH, hdr->valid_thresh);
	REG_SET_SLICE(val, STITCHING_VERYSHORT_OFFSET_VAL, hdr->offset_val);
	isp_write_reg(dev, REG_ADDR(isp_stitching_sat_level), val);

	for (i = 0; i < 5; i++) {
		val = 0;
		REG_SET_SLICE(val, STITCHING_COMPRESS_LUT_2,
			      hdr->compress_lut[i * 3 + 2]);
		REG_SET_SLICE(val, STITCHING_COMPRESS_LUT_1,
			      hdr->compress_lut[i * 3 + 1]);
		REG_SET_SLICE(val, STITCHING_COMPRESS_LUT_0,
			      hdr->compress_lut[i * 3]);
		isp_write_reg(dev,
			      REG_ADDR(isp_stitching_compress_lut_0) + i * 4,
			      val);
	}
	val = 0;
	REG_SET_SLICE(val, STITCHING_LONG_SAT_THRESH, hdr->sat_thresh);
	REG_SET_SLICE(val, STITCHING_LONG_SAT_COMBINE_WEIGHT,
		      hdr->combine_weight);
	isp_write_reg(dev, REG_ADDR(isp_stitching_long_sat_params), val);

	REG_SET_SLICE(isp_stitching_ctrl, STITCHING_COMBINE_ENABLE_BIT, 1);
	REG_SET_SLICE(isp_stitching_ctrl, STITCHING_CFG_UPD, 1);
	REG_SET_SLICE(isp_stitching_ctrl, STITCHING_COMBINATION_MODE, 1);
	isp_write_reg(dev, REG_ADDR(isp_stitching_ctrl), 0x4c0221);

	return 0;
}

int isp_s_hdr_wb(struct isp_ic_dev *dev)
{
	struct isp_hdr_context *hdr = &dev->hdr;
	u32 val = 0;
	u32 isp_stitching_ctrl =
	    isp_read_reg(dev, REG_ADDR(isp_stitching_ctrl));

	isp_info("enter %s\n", __func__);
	REG_SET_SLICE(val, STITCHING_EXP0_AWB_GAIN_GR, hdr->gr);
	REG_SET_SLICE(val, STITCHING_EXP0_AWB_GAIN_GB, hdr->gb);
	isp_write_reg(dev, REG_ADDR(isp_stitching_exp0_awb_gain_g), val);
	isp_write_reg(dev, REG_ADDR(isp_stitching_exp1_awb_gain_g), val);
	isp_write_reg(dev, REG_ADDR(isp_stitching_exp2_awb_gain_g), val);

	val = 0;
	REG_SET_SLICE(val, STITCHING_EXP0_AWB_GAIN_R, hdr->r);
	REG_SET_SLICE(val, STITCHING_EXP0_AWB_GAIN_B, hdr->b);
	isp_write_reg(dev, REG_ADDR(isp_stitching_exp0_awb_gain_rb), val);
	isp_write_reg(dev, REG_ADDR(isp_stitching_exp1_awb_gain_rb), val);
	isp_write_reg(dev, REG_ADDR(isp_stitching_exp2_awb_gain_rb), val);
	REG_SET_SLICE(isp_stitching_ctrl, STITCHING_CFG_UPD, 1);
	isp_write_reg(dev, REG_ADDR(isp_stitching_ctrl), 0x4c0221);

	return 0;
}

int isp_s_hdr_bls(struct isp_ic_dev *dev)
{
	struct isp_hdr_context *hdr = &dev->hdr;
	u32 isp_stitching_ctrl =
	    isp_read_reg(dev, REG_ADDR(isp_stitching_ctrl));
	u32 val = 0;
	int i;

	isp_info("enter %s\n", __func__);

	for (i = 0; i < 12; i++) {
		val = 0;
		REG_SET_SLICE(val, STITCHING_BLS_EXP_0_A, hdr->bls[i % 4]);
		isp_write_reg(dev, REG_ADDR(isp_stitching_bls_exp_0_a) + i * 4,
			      val);
	}
	REG_SET_SLICE(isp_stitching_ctrl, STITCHING_CFG_UPD, 1);
	isp_write_reg(dev, REG_ADDR(isp_stitching_ctrl), 0x4c0221);

	return 0;
}

int isp_enable_hdr(struct isp_ic_dev *dev)
{
	u32 addr, isp_stitching_ctrl;
	u32 dpcl;
	int val = 0;

	isp_info("enter %s\n", __func__);
	addr = REG_ADDR(isp_stitching_ctrl);
	isp_stitching_ctrl = isp_read_reg(dev, addr);
	REG_SET_SLICE(val, STITCHING_FRAME_WIDTH, dev->ctx.acqWindow.width);
	isp_write_reg(dev, REG_ADDR(isp_stitching_frame_width), val);
	val = 0;
	REG_SET_SLICE(val, STITCHING_FRAME_HEIGHT, dev->ctx.acqWindow.height);
	isp_write_reg(dev, REG_ADDR(isp_stitching_frame_height), val);

	REG_SET_SLICE(isp_stitching_ctrl, STITCHING_COMBINE_ENABLE_BIT, 0);
	isp_write_reg(dev, addr, isp_stitching_ctrl);
	dpcl = isp_read_reg(dev, REG_ADDR(vi_dpcl));
	REG_SET_SLICE(dpcl, MRV_IF_SELECT, MRV_IF_SELECT_HDR);
	isp_write_reg(dev, REG_ADDR(vi_dpcl), dpcl);
	dev->mux.if_select = MRV_IF_SELECT_HDR;
	return 0;
}

int isp_disable_hdr(struct isp_ic_dev *dev)
{
	u32 addr, isp_stitching_ctrl = 0;

	isp_info("enter %s\n", __func__);
	addr = REG_ADDR(isp_stitching_ctrl);
	isp_stitching_ctrl = isp_read_reg(dev, addr);
	REG_SET_SLICE(isp_stitching_ctrl, STITCHING_COMBINE_ENABLE_BIT, 1);
	isp_write_reg(dev, addr, isp_stitching_ctrl);
	return 0;
}
