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
#include <linux/module.h>
#include <linux/uaccess.h>
#include "vvsensor.h"
#include "../native/sensor/sensor_common.h"

int32_t sensor_reset(void *dev);
int32_t sensor_set_clk(void *dev, uint32_t clk);
int32_t sensor_get_clk(void *dev, uint32_t *pclk);
int32_t sensor_set_power(void *dev, uint32_t power);
int32_t sensor_get_power(void *dev, uint32_t *ppower);

int32_t sensor_reset(void *dev)
{
	int ret = 0;
	struct vvcam_sensor_dev *psensor_dev = (struct vvcam_sensor_dev *)dev;

    if (gpio_is_valid(psensor_dev->rst_pin)) {
		gpio_direction_output(psensor_dev->rst_pin, 0);
    }

    if (gpio_is_valid(psensor_dev->pdn_pin)) {
		gpio_direction_output(psensor_dev->pdn_pin, 0);
	}

    udelay(10000);

	if (gpio_is_valid(psensor_dev->rst_pin)) {
		gpio_direction_output(psensor_dev->rst_pin, 1);
    }

    if (gpio_is_valid(psensor_dev->pdn_pin)) {
		gpio_direction_output(psensor_dev->pdn_pin, 1);
	}

	udelay(psensor_dev->pdn_delay_us);
	return 0;
}

int32_t sensor_set_clk(void *dev, uint32_t clk)
{
	return 0;
}

int32_t sensor_get_clk(void *dev, uint32_t *pclk)
{
	return 0;
}

int32_t sensor_set_power(void *dev, uint32_t power)
{
	int ret = 0, i = 0, set_volt = 0;

	struct vvcam_sensor_dev *psensor_dev = (struct vvcam_sensor_dev *)dev;
	printk("sensor_set_power enter, power=%d\n", power);

	if (psensor_dev->regulators.num <= 0) {
		printk("no regulator for %s", psensor_dev->sensor_name);
		return -ENODEV;
	}

	for (i = 0; i < psensor_dev->regulators.num; i++) {
		if (gpio_is_valid(psensor_dev->rst_pin)) {
			gpio_direction_output(psensor_dev->rst_pin, 0); // make sure reset is low before power up
		}
		if (gpio_is_valid(psensor_dev->pdn_pin)) {
			gpio_direction_output(psensor_dev->pdn_pin, 0);
		}
		if (power == 1) {
			if(psensor_dev->regulators.supply[i] == NULL) {
				psensor_dev->regulators.supply[i] = devm_regulator_get(psensor_dev->dev, psensor_dev->regulators.name[i]);
			}

			if(psensor_dev->regulators.voltage[i] != 0) {
				ret = regulator_set_voltage_tol(psensor_dev->regulators.supply[i], psensor_dev->regulators.voltage[i], 0);
				if(ret != 0){
					pr_err("fail to set voltage to %s\n", psensor_dev->regulators.name[i] );
					return -1;
				}
				set_volt = regulator_get_voltage(psensor_dev->regulators.supply[i]);
				pr_info("%s set regulator %s to %d uV\n",psensor_dev->sensor_name, psensor_dev->regulators.name[i], set_volt );
			}
			ret = regulator_enable(psensor_dev->regulators.supply[i]);
		} else if (power == 0) {
			if (psensor_dev->regulators.supply[i] == NULL) {
				pr_info("the supply already is null\n");
				return 0;
			}
			pr_info("%s disable regulator %s \n",psensor_dev->sensor_name, psensor_dev->regulators.name[i] );
			ret = regulator_disable(psensor_dev->regulators.supply[i]);
			if (ret == 0) {
				devm_regulator_put(psensor_dev->regulators.supply[i]);
				psensor_dev->regulators.supply[i] = NULL;
			}
		} else {
			return -1;
		}
		if (ret)
			return ret;
		udelay(psensor_dev->regulators.delay_us[i]);
	}
	return 0;
}

int32_t sensor_get_power(void *dev, uint32_t *ppower)
{
	return 0;
}

