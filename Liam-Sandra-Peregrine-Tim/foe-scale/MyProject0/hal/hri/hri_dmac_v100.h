/**
 * \file
 *
 * \brief SAM DMAC
 *
 * Copyright (C) 2014 Atmel Corporation. All rights reserved.
 *
 * \asf_license_start
 *
 * \page License
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 * 1. Redistributions of source code must retain the above copyright notice,
 *    this list of conditions and the following disclaimer.
 *
 * 2. Redistributions in binary form must reproduce the above copyright notice,
 *    this list of conditions and the following disclaimer in the documentation
 *    and/or other materials provided with the distribution.
 *
 * 3. The name of Atmel may not be used to endorse or promote products derived
 *    from this software without specific prior written permission.
 *
 * 4. This software may only be redistributed and used in connection with an
 *    Atmel microcontroller product.
 *
 * THIS SOFTWARE IS PROVIDED BY ATMEL "AS IS" AND ANY EXPRESS OR IMPLIED
 * WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NON-INFRINGEMENT ARE
 * EXPRESSLY AND SPECIFICALLY DISCLAIMED. IN NO EVENT SHALL ATMEL BE LIABLE FOR
 * ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS
 * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT,
 * STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN
 * ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 *
 * \asf_license_stop
 */

#ifndef _HRI_DMAC_V100_H_INCLUDED
#define _HRI_DMAC_V100_H_INCLUDED

#include <hal_atomic.h>

#if !defined(DISABLE_DMAC_CRITICAL_SECTIONS)
#  define DMAC_CRITICAL_SECTION_ENTER() CRITICAL_SECTION_ENTER()
#  define DMAC_CRITICAL_SECTION_LEAVE() CRITICAL_SECTION_LEAVE()
#else
#  define DMAC_CRITICAL_SECTION_ENTER()
#  define DMAC_CRITICAL_SECTION_LEAVE()
#endif

typedef uint16_t hri_dmac_ctrl_reg_t;
typedef uint16_t hri_dmac_crcctrl_reg_t;
typedef uint32_t hri_dmac_crcdatain_reg_t;
typedef uint32_t hri_dmac_crcchksum_reg_t;
typedef uint8_t hri_dmac_crcstatus_reg_t;
typedef uint8_t hri_dmac_dbgctrl_reg_t;
typedef uint32_t hri_dmac_swtrigctrl_reg_t;
typedef uint32_t hri_dmac_prictrl0_reg_t;
typedef uint16_t hri_dmac_intpend_reg_t;
typedef uint32_t hri_dmac_intstatus_reg_t;
typedef uint32_t hri_dmac_busych_reg_t;
typedef uint32_t hri_dmac_pendch_reg_t;
typedef uint32_t hri_dmac_active_reg_t;
typedef uint32_t hri_dmac_baseaddr_reg_t;
typedef uint32_t hri_dmac_wrbaddr_reg_t;
typedef uint8_t hri_dmac_chid_reg_t;
typedef uint8_t hri_dmac_chctrla_reg_t;
typedef uint32_t hri_dmac_chctrlb_reg_t;
typedef uint8_t hri_dmac_chinten_reg_t;
typedef uint8_t hri_dmac_chintflag_reg_t;
typedef uint8_t hri_dmac_chstatus_reg_t;


static inline void hri_dmac_set_CTRL_SWRST_bit(void *const hw)
{
	DMAC_CRITICAL_SECTION_ENTER()
	((Dmac *)hw)->CTRL.reg |= DMAC_CTRL_SWRST;

	DMAC_CRITICAL_SECTION_LEAVE()
}

static inline void hri_dmac_set_CTRL_DMAENABLE_bit(void *const hw)
{
	DMAC_CRITICAL_SECTION_ENTER()
	((Dmac *)hw)->CTRL.reg |= DMAC_CTRL_DMAENABLE;

	DMAC_CRITICAL_SECTION_LEAVE()
}

static inline void hri_dmac_write_CTRL_DMAENABLE_bit(void *const hw, const bool value)
{
	DMAC_CRITICAL_SECTION_ENTER()
	((Dmac *)hw)->CTRL.reg &= ~DMAC_CTRL_DMAENABLE;
	((Dmac *)hw)->CTRL.reg = value << DMAC_CTRL_DMAENABLE_Pos;

	DMAC_CRITICAL_SECTION_LEAVE()
}

static inline void hri_dmac_clear_CTRL_DMAENABLE_bit(void *const hw)
{
	DMAC_CRITICAL_SECTION_ENTER()
	((Dmac *)hw)->CTRL.reg &= ~DMAC_CTRL_DMAENABLE;

	DMAC_CRITICAL_SECTION_LEAVE()
}

static inline bool hri_dmac_get_CTRL_DMAENABLE_bit(const void *const hw)
{
	uint16_t tmp;

	DMAC_CRITICAL_SECTION_ENTER()
	tmp = ((const Dmac *)hw)->CTRL.reg;
	tmp = (tmp & DMAC_CTRL_DMAENABLE) >> DMAC_CTRL_DMAENABLE_Pos;

	DMAC_CRITICAL_SECTION_LEAVE()

	return (bool)tmp;
}

static inline void hri_dmac_toggle_CTRL_DMAENABLE_bit(void *const hw)
{
	DMAC_CRITICAL_SECTION_ENTER()
	((Dmac *)hw)->CTRL.reg ^= DMAC_CTRL_DMAENABLE;

	DMAC_CRITICAL_SECTION_LEAVE()
}

static inline void hri_dmac_set_CTRL_CRCENABLE_bit(void *const hw)
{
	DMAC_CRITICAL_SECTION_ENTER()
	((Dmac *)hw)->CTRL.reg |= DMAC_CTRL_CRCENABLE;

	DMAC_CRITICAL_SECTION_LEAVE()
}

static inline void hri_dmac_write_CTRL_CRCENABLE_bit(void *const hw, const bool value)
{
	DMAC_CRITICAL_SECTION_ENTER()
	((Dmac *)hw)->CTRL.reg &= ~DMAC_CTRL_CRCENABLE;
	((Dmac *)hw)->CTRL.reg = value << DMAC_CTRL_CRCENABLE_Pos;

	DMAC_CRITICAL_SECTION_LEAVE()
}

static inline void hri_dmac_clear_CTRL_CRCENABLE_bit(void *const hw)
{
	DMAC_CRITICAL_SECTION_ENTER()
	((Dmac *)hw)->CTRL.reg &= ~DMAC_CTRL_CRCENABLE;

	DMAC_CRITICAL_SECTION_LEAVE()
}

static inline bool hri_dmac_get_CTRL_CRCENABLE_bit(const void *const hw)
{
	uint16_t tmp;

	DMAC_CRITICAL_SECTION_ENTER()
	tmp = ((const Dmac *)hw)->CTRL.reg;
	tmp = (tmp & DMAC_CTRL_CRCENABLE) >> DMAC_CTRL_CRCENABLE_Pos;

	DMAC_CRITICAL_SECTION_LEAVE()

	return (bool)tmp;
}

static inline void hri_dmac_toggle_CTRL_CRCENABLE_bit(void *const hw)
{
	DMAC_CRITICAL_SECTION_ENTER()
	((Dmac *)hw)->CTRL.reg ^= DMAC_CTRL_CRCENABLE;

	DMAC_CRITICAL_SECTION_LEAVE()
}

static inline void hri_dmac_set_CTRL_LVLEN0_bit(void *const hw)
{
	DMAC_CRITICAL_SECTION_ENTER()
	((Dmac *)hw)->CTRL.reg |= DMAC_CTRL_LVLEN0;

	DMAC_CRITICAL_SECTION_LEAVE()
}

static inline void hri_dmac_write_CTRL_LVLEN0_bit(void *const hw, const bool value)
{
	DMAC_CRITICAL_SECTION_ENTER()
	((Dmac *)hw)->CTRL.reg &= ~DMAC_CTRL_LVLEN0;
	((Dmac *)hw)->CTRL.reg = value << DMAC_CTRL_LVLEN0_Pos;

	DMAC_CRITICAL_SECTION_LEAVE()
}

static inline void hri_dmac_clear_CTRL_LVLEN0_bit(void *const hw)
{
	DMAC_CRITICAL_SECTION_ENTER()
	((Dmac *)hw)->CTRL.reg &= ~DMAC_CTRL_LVLEN0;

	DMAC_CRITICAL_SECTION_LEAVE()
}

static inline bool hri_dmac_get_CTRL_LVLEN0_bit(const void *const hw)
{
	uint16_t tmp;

	DMAC_CRITICAL_SECTION_ENTER()
	tmp = ((const Dmac *)hw)->CTRL.reg;
	tmp = (tmp & DMAC_CTRL_LVLEN0) >> DMAC_CTRL_LVLEN0_Pos;

	DMAC_CRITICAL_SECTION_LEAVE()

	return (bool)tmp;
}

static inline void hri_dmac_toggle_CTRL_LVLEN0_bit(void *const hw)
{
	DMAC_CRITICAL_SECTION_ENTER()
	((Dmac *)hw)->CTRL.reg ^= DMAC_CTRL_LVLEN0;

	DMAC_CRITICAL_SECTION_LEAVE()
}

static inline void hri_dmac_set_CTRL_LVLEN1_bit(void *const hw)
{
	DMAC_CRITICAL_SECTION_ENTER()
	((Dmac *)hw)->CTRL.reg |= DMAC_CTRL_LVLEN1;

	DMAC_CRITICAL_SECTION_LEAVE()
}

static inline void hri_dmac_write_CTRL_LVLEN1_bit(void *const hw, const bool value)
{
	DMAC_CRITICAL_SECTION_ENTER()
	((Dmac *)hw)->CTRL.reg &= ~DMAC_CTRL_LVLEN1;
	((Dmac *)hw)->CTRL.reg = value << DMAC_CTRL_LVLEN1_Pos;

	DMAC_CRITICAL_SECTION_LEAVE()
}

static inline void hri_dmac_clear_CTRL_LVLEN1_bit(void *const hw)
{
	DMAC_CRITICAL_SECTION_ENTER()
	((Dmac *)hw)->CTRL.reg &= ~DMAC_CTRL_LVLEN1;

	DMAC_CRITICAL_SECTION_LEAVE()
}

static inline bool hri_dmac_get_CTRL_LVLEN1_bit(const void *const hw)
{
	uint16_t tmp;

	DMAC_CRITICAL_SECTION_ENTER()
	tmp = ((const Dmac *)hw)->CTRL.reg;
	tmp = (tmp & DMAC_CTRL_LVLEN1) >> DMAC_CTRL_LVLEN1_Pos;

	DMAC_CRITICAL_SECTION_LEAVE()

	return (bool)tmp;
}

static inline void hri_dmac_toggle_CTRL_LVLEN1_bit(void *const hw)
{
	DMAC_CRITICAL_SECTION_ENTER()
	((Dmac *)hw)->CTRL.reg ^= DMAC_CTRL_LVLEN1;

	DMAC_CRITICAL_SECTION_LEAVE()
}

static inline void hri_dmac_set_CTRL_LVLEN2_bit(void *const hw)
{
	DMAC_CRITICAL_SECTION_ENTER()
	((Dmac *)hw)->CTRL.reg |= DMAC_CTRL_LVLEN2;

	DMAC_CRITICAL_SECTION_LEAVE()
}

static inline void hri_dmac_write_CTRL_LVLEN2_bit(void *const hw, const bool value)
{
	DMAC_CRITICAL_SECTION_ENTER()
	((Dmac *)hw)->CTRL.reg &= ~DMAC_CTRL_LVLEN2;
	((Dmac *)hw)->CTRL.reg = value << DMAC_CTRL_LVLEN2_Pos;

	DMAC_CRITICAL_SECTION_LEAVE()
}

static inline void hri_dmac_clear_CTRL_LVLEN2_bit(void *const hw)
{
	DMAC_CRITICAL_SECTION_ENTER()
	((Dmac *)hw)->CTRL.reg &= ~DMAC_CTRL_LVLEN2;

	DMAC_CRITICAL_SECTION_LEAVE()
}

static inline bool hri_dmac_get_CTRL_LVLEN2_bit(const void *const hw)
{
	uint16_t tmp;

	DMAC_CRITICAL_SECTION_ENTER()
	tmp = ((const Dmac *)hw)->CTRL.reg;
	tmp = (tmp & DMAC_CTRL_LVLEN2) >> DMAC_CTRL_LVLEN2_Pos;

	DMAC_CRITICAL_SECTION_LEAVE()

	return (bool)tmp;
}

static inline void hri_dmac_toggle_CTRL_LVLEN2_bit(void *const hw)
{
	DMAC_CRITICAL_SECTION_ENTER()
	((Dmac *)hw)->CTRL.reg ^= DMAC_CTRL_LVLEN2;

	DMAC_CRITICAL_SECTION_LEAVE()
}

static inline void hri_dmac_set_CTRL_LVLEN3_bit(void *const hw)
{
	DMAC_CRITICAL_SECTION_ENTER()
	((Dmac *)hw)->CTRL.reg |= DMAC_CTRL_LVLEN3;

	DMAC_CRITICAL_SECTION_LEAVE()
}

static inline void hri_dmac_write_CTRL_LVLEN3_bit(void *const hw, const bool value)
{
	DMAC_CRITICAL_SECTION_ENTER()
	((Dmac *)hw)->CTRL.reg &= ~DMAC_CTRL_LVLEN3;
	((Dmac *)hw)->CTRL.reg = value << DMAC_CTRL_LVLEN3_Pos;

	DMAC_CRITICAL_SECTION_LEAVE()
}

static inline void hri_dmac_clear_CTRL_LVLEN3_bit(void *const hw)
{
	DMAC_CRITICAL_SECTION_ENTER()
	((Dmac *)hw)->CTRL.reg &= ~DMAC_CTRL_LVLEN3;

	DMAC_CRITICAL_SECTION_LEAVE()
}

static inline bool hri_dmac_get_CTRL_LVLEN3_bit(const void *const hw)
{
	uint16_t tmp;

	DMAC_CRITICAL_SECTION_ENTER()
	tmp = ((const Dmac *)hw)->CTRL.reg;
	tmp = (tmp & DMAC_CTRL_LVLEN3) >> DMAC_CTRL_LVLEN3_Pos;

	DMAC_CRITICAL_SECTION_LEAVE()

	return (bool)tmp;
}

static inline void hri_dmac_toggle_CTRL_LVLEN3_bit(void *const hw)
{
	DMAC_CRITICAL_SECTION_ENTER()
	((Dmac *)hw)->CTRL.reg ^= DMAC_CTRL_LVLEN3;

	DMAC_CRITICAL_SECTION_LEAVE()
}

static inline void hri_dmac_clear_CRCSTATUS_CRCBUSY_bit(void *const hw)
{
	((Dmac *)hw)->CRCSTATUS.reg = DMAC_CRCSTATUS_CRCBUSY;
}

static inline bool hri_dmac_get_CRCSTATUS_CRCBUSY_bit(const void *const hw)
{
	return (((const Dmac *)hw)->CRCSTATUS.reg & DMAC_CRCSTATUS_CRCBUSY) >> DMAC_CRCSTATUS_CRCBUSY_Pos;
}

static inline void hri_dmac_clear_CRCSTATUS_CRCZERO_bit(void *const hw)
{
	((Dmac *)hw)->CRCSTATUS.reg = DMAC_CRCSTATUS_CRCZERO;
}

static inline bool hri_dmac_get_CRCSTATUS_CRCZERO_bit(const void *const hw)
{
	return (((const Dmac *)hw)->CRCSTATUS.reg & DMAC_CRCSTATUS_CRCZERO) >> DMAC_CRCSTATUS_CRCZERO_Pos;
}

static inline void hri_dmac_set_DBGCTRL_DBGRUN_bit(void *const hw)
{
	DMAC_CRITICAL_SECTION_ENTER()
	((Dmac *)hw)->DBGCTRL.reg |= DMAC_DBGCTRL_DBGRUN;

	DMAC_CRITICAL_SECTION_LEAVE()
}

static inline void hri_dmac_write_DBGCTRL_DBGRUN_bit(void *const hw, const bool value)
{
	DMAC_CRITICAL_SECTION_ENTER()
	((Dmac *)hw)->DBGCTRL.reg &= ~DMAC_DBGCTRL_DBGRUN;
	((Dmac *)hw)->DBGCTRL.reg = value << DMAC_DBGCTRL_DBGRUN_Pos;

	DMAC_CRITICAL_SECTION_LEAVE()
}

static inline void hri_dmac_clear_DBGCTRL_DBGRUN_bit(void *const hw)
{
	DMAC_CRITICAL_SECTION_ENTER()
	((Dmac *)hw)->DBGCTRL.reg &= ~DMAC_DBGCTRL_DBGRUN;

	DMAC_CRITICAL_SECTION_LEAVE()
}

static inline bool hri_dmac_get_DBGCTRL_DBGRUN_bit(const void *const hw)
{
	uint8_t tmp;

	DMAC_CRITICAL_SECTION_ENTER()
	tmp = ((const Dmac *)hw)->DBGCTRL.reg;
	tmp = (tmp & DMAC_DBGCTRL_DBGRUN) >> DMAC_DBGCTRL_DBGRUN_Pos;

	DMAC_CRITICAL_SECTION_LEAVE()

	return (bool)tmp;
}

static inline void hri_dmac_toggle_DBGCTRL_DBGRUN_bit(void *const hw)
{
	DMAC_CRITICAL_SECTION_ENTER()
	((Dmac *)hw)->DBGCTRL.reg ^= DMAC_DBGCTRL_DBGRUN;

	DMAC_CRITICAL_SECTION_LEAVE()
}

static inline void hri_dmac_set_SWTRIGCTRL_SWTRIG0_bit(void *const hw)
{
	DMAC_CRITICAL_SECTION_ENTER()
	((Dmac *)hw)->SWTRIGCTRL.reg |= DMAC_SWTRIGCTRL_SWTRIG0;

	DMAC_CRITICAL_SECTION_LEAVE()
}

static inline void hri_dmac_write_SWTRIGCTRL_SWTRIG0_bit(void *const hw, const bool value)
{
	DMAC_CRITICAL_SECTION_ENTER()
	((Dmac *)hw)->SWTRIGCTRL.reg &= ~DMAC_SWTRIGCTRL_SWTRIG0;
	((Dmac *)hw)->SWTRIGCTRL.reg = value << DMAC_SWTRIGCTRL_SWTRIG0_Pos;

	DMAC_CRITICAL_SECTION_LEAVE()
}

static inline void hri_dmac_clear_SWTRIGCTRL_SWTRIG0_bit(void *const hw)
{
	DMAC_CRITICAL_SECTION_ENTER()
	((Dmac *)hw)->SWTRIGCTRL.reg &= ~DMAC_SWTRIGCTRL_SWTRIG0;

	DMAC_CRITICAL_SECTION_LEAVE()
}

static inline bool hri_dmac_get_SWTRIGCTRL_SWTRIG0_bit(const void *const hw)
{
	uint32_t tmp;

	DMAC_CRITICAL_SECTION_ENTER()
	tmp = ((const Dmac *)hw)->SWTRIGCTRL.reg;
	tmp = (tmp & DMAC_SWTRIGCTRL_SWTRIG0) >> DMAC_SWTRIGCTRL_SWTRIG0_Pos;

	DMAC_CRITICAL_SECTION_LEAVE()

	return (bool)tmp;
}

static inline void hri_dmac_toggle_SWTRIGCTRL_SWTRIG0_bit(void *const hw)
{
	DMAC_CRITICAL_SECTION_ENTER()
	((Dmac *)hw)->SWTRIGCTRL.reg ^= DMAC_SWTRIGCTRL_SWTRIG0;

	DMAC_CRITICAL_SECTION_LEAVE()
}

static inline void hri_dmac_set_SWTRIGCTRL_SWTRIG1_bit(void *const hw)
{
	DMAC_CRITICAL_SECTION_ENTER()
	((Dmac *)hw)->SWTRIGCTRL.reg |= DMAC_SWTRIGCTRL_SWTRIG1;

	DMAC_CRITICAL_SECTION_LEAVE()
}

static inline void hri_dmac_write_SWTRIGCTRL_SWTRIG1_bit(void *const hw, const bool value)
{
	DMAC_CRITICAL_SECTION_ENTER()
	((Dmac *)hw)->SWTRIGCTRL.reg &= ~DMAC_SWTRIGCTRL_SWTRIG1;
	((Dmac *)hw)->SWTRIGCTRL.reg = value << DMAC_SWTRIGCTRL_SWTRIG1_Pos;

	DMAC_CRITICAL_SECTION_LEAVE()
}

static inline void hri_dmac_clear_SWTRIGCTRL_SWTRIG1_bit(void *const hw)
{
	DMAC_CRITICAL_SECTION_ENTER()
	((Dmac *)hw)->SWTRIGCTRL.reg &= ~DMAC_SWTRIGCTRL_SWTRIG1;

	DMAC_CRITICAL_SECTION_LEAVE()
}

static inline bool hri_dmac_get_SWTRIGCTRL_SWTRIG1_bit(const void *const hw)
{
	uint32_t tmp;

	DMAC_CRITICAL_SECTION_ENTER()
	tmp = ((const Dmac *)hw)->SWTRIGCTRL.reg;
	tmp = (tmp & DMAC_SWTRIGCTRL_SWTRIG1) >> DMAC_SWTRIGCTRL_SWTRIG1_Pos;

	DMAC_CRITICAL_SECTION_LEAVE()

	return (bool)tmp;
}

static inline void hri_dmac_toggle_SWTRIGCTRL_SWTRIG1_bit(void *const hw)
{
	DMAC_CRITICAL_SECTION_ENTER()
	((Dmac *)hw)->SWTRIGCTRL.reg ^= DMAC_SWTRIGCTRL_SWTRIG1;

	DMAC_CRITICAL_SECTION_LEAVE()
}

static inline void hri_dmac_set_SWTRIGCTRL_SWTRIG2_bit(void *const hw)
{
	DMAC_CRITICAL_SECTION_ENTER()
	((Dmac *)hw)->SWTRIGCTRL.reg |= DMAC_SWTRIGCTRL_SWTRIG2;

	DMAC_CRITICAL_SECTION_LEAVE()
}

static inline void hri_dmac_write_SWTRIGCTRL_SWTRIG2_bit(void *const hw, const bool value)
{
	DMAC_CRITICAL_SECTION_ENTER()
	((Dmac *)hw)->SWTRIGCTRL.reg &= ~DMAC_SWTRIGCTRL_SWTRIG2;
	((Dmac *)hw)->SWTRIGCTRL.reg = value << DMAC_SWTRIGCTRL_SWTRIG2_Pos;

	DMAC_CRITICAL_SECTION_LEAVE()
}

static inline void hri_dmac_clear_SWTRIGCTRL_SWTRIG2_bit(void *const hw)
{
	DMAC_CRITICAL_SECTION_ENTER()
	((Dmac *)hw)->SWTRIGCTRL.reg &= ~DMAC_SWTRIGCTRL_SWTRIG2;

	DMAC_CRITICAL_SECTION_LEAVE()
}

static inline bool hri_dmac_get_SWTRIGCTRL_SWTRIG2_bit(const void *const hw)
{
	uint32_t tmp;

	DMAC_CRITICAL_SECTION_ENTER()
	tmp = ((const Dmac *)hw)->SWTRIGCTRL.reg;
	tmp = (tmp & DMAC_SWTRIGCTRL_SWTRIG2) >> DMAC_SWTRIGCTRL_SWTRIG2_Pos;

	DMAC_CRITICAL_SECTION_LEAVE()

	return (bool)tmp;
}

static inline void hri_dmac_toggle_SWTRIGCTRL_SWTRIG2_bit(void *const hw)
{
	DMAC_CRITICAL_SECTION_ENTER()
	((Dmac *)hw)->SWTRIGCTRL.reg ^= DMAC_SWTRIGCTRL_SWTRIG2;

	DMAC_CRITICAL_SECTION_LEAVE()
}

static inline void hri_dmac_set_SWTRIGCTRL_SWTRIG3_bit(void *const hw)
{
	DMAC_CRITICAL_SECTION_ENTER()
	((Dmac *)hw)->SWTRIGCTRL.reg |= DMAC_SWTRIGCTRL_SWTRIG3;

	DMAC_CRITICAL_SECTION_LEAVE()
}

static inline void hri_dmac_write_SWTRIGCTRL_SWTRIG3_bit(void *const hw, const bool value)
{
	DMAC_CRITICAL_SECTION_ENTER()
	((Dmac *)hw)->SWTRIGCTRL.reg &= ~DMAC_SWTRIGCTRL_SWTRIG3;
	((Dmac *)hw)->SWTRIGCTRL.reg = value << DMAC_SWTRIGCTRL_SWTRIG3_Pos;

	DMAC_CRITICAL_SECTION_LEAVE()
}

static inline void hri_dmac_clear_SWTRIGCTRL_SWTRIG3_bit(void *const hw)
{
	DMAC_CRITICAL_SECTION_ENTER()
	((Dmac *)hw)->SWTRIGCTRL.reg &= ~DMAC_SWTRIGCTRL_SWTRIG3;

	DMAC_CRITICAL_SECTION_LEAVE()
}

static inline bool hri_dmac_get_SWTRIGCTRL_SWTRIG3_bit(const void *const hw)
{
	uint32_t tmp;

	DMAC_CRITICAL_SECTION_ENTER()
	tmp = ((const Dmac *)hw)->SWTRIGCTRL.reg;
	tmp = (tmp & DMAC_SWTRIGCTRL_SWTRIG3) >> DMAC_SWTRIGCTRL_SWTRIG3_Pos;

	DMAC_CRITICAL_SECTION_LEAVE()

	return (bool)tmp;
}

static inline void hri_dmac_toggle_SWTRIGCTRL_SWTRIG3_bit(void *const hw)
{
	DMAC_CRITICAL_SECTION_ENTER()
	((Dmac *)hw)->SWTRIGCTRL.reg ^= DMAC_SWTRIGCTRL_SWTRIG3;

	DMAC_CRITICAL_SECTION_LEAVE()
}

static inline void hri_dmac_set_SWTRIGCTRL_SWTRIG4_bit(void *const hw)
{
	DMAC_CRITICAL_SECTION_ENTER()
	((Dmac *)hw)->SWTRIGCTRL.reg |= DMAC_SWTRIGCTRL_SWTRIG4;

	DMAC_CRITICAL_SECTION_LEAVE()
}

static inline void hri_dmac_write_SWTRIGCTRL_SWTRIG4_bit(void *const hw, const bool value)
{
	DMAC_CRITICAL_SECTION_ENTER()
	((Dmac *)hw)->SWTRIGCTRL.reg &= ~DMAC_SWTRIGCTRL_SWTRIG4;
	((Dmac *)hw)->SWTRIGCTRL.reg = value << DMAC_SWTRIGCTRL_SWTRIG4_Pos;

	DMAC_CRITICAL_SECTION_LEAVE()
}

static inline void hri_dmac_clear_SWTRIGCTRL_SWTRIG4_bit(void *const hw)
{
	DMAC_CRITICAL_SECTION_ENTER()
	((Dmac *)hw)->SWTRIGCTRL.reg &= ~DMAC_SWTRIGCTRL_SWTRIG4;

	DMAC_CRITICAL_SECTION_LEAVE()
}

static inline bool hri_dmac_get_SWTRIGCTRL_SWTRIG4_bit(const void *const hw)
{
	uint32_t tmp;

	DMAC_CRITICAL_SECTION_ENTER()
	tmp = ((const Dmac *)hw)->SWTRIGCTRL.reg;
	tmp = (tmp & DMAC_SWTRIGCTRL_SWTRIG4) >> DMAC_SWTRIGCTRL_SWTRIG4_Pos;

	DMAC_CRITICAL_SECTION_LEAVE()

	return (bool)tmp;
}

static inline void hri_dmac_toggle_SWTRIGCTRL_SWTRIG4_bit(void *const hw)
{
	DMAC_CRITICAL_SECTION_ENTER()
	((Dmac *)hw)->SWTRIGCTRL.reg ^= DMAC_SWTRIGCTRL_SWTRIG4;

	DMAC_CRITICAL_SECTION_LEAVE()
}

static inline void hri_dmac_set_SWTRIGCTRL_SWTRIG5_bit(void *const hw)
{
	DMAC_CRITICAL_SECTION_ENTER()
	((Dmac *)hw)->SWTRIGCTRL.reg |= DMAC_SWTRIGCTRL_SWTRIG5;

	DMAC_CRITICAL_SECTION_LEAVE()
}

static inline void hri_dmac_write_SWTRIGCTRL_SWTRIG5_bit(void *const hw, const bool value)
{
	DMAC_CRITICAL_SECTION_ENTER()
	((Dmac *)hw)->SWTRIGCTRL.reg &= ~DMAC_SWTRIGCTRL_SWTRIG5;
	((Dmac *)hw)->SWTRIGCTRL.reg = value << DMAC_SWTRIGCTRL_SWTRIG5_Pos;

	DMAC_CRITICAL_SECTION_LEAVE()
}

static inline void hri_dmac_clear_SWTRIGCTRL_SWTRIG5_bit(void *const hw)
{
	DMAC_CRITICAL_SECTION_ENTER()
	((Dmac *)hw)->SWTRIGCTRL.reg &= ~DMAC_SWTRIGCTRL_SWTRIG5;

	DMAC_CRITICAL_SECTION_LEAVE()
}

static inline bool hri_dmac_get_SWTRIGCTRL_SWTRIG5_bit(const void *const hw)
{
	uint32_t tmp;

	DMAC_CRITICAL_SECTION_ENTER()
	tmp = ((const Dmac *)hw)->SWTRIGCTRL.reg;
	tmp = (tmp & DMAC_SWTRIGCTRL_SWTRIG5) >> DMAC_SWTRIGCTRL_SWTRIG5_Pos;

	DMAC_CRITICAL_SECTION_LEAVE()

	return (bool)tmp;
}

static inline void hri_dmac_toggle_SWTRIGCTRL_SWTRIG5_bit(void *const hw)
{
	DMAC_CRITICAL_SECTION_ENTER()
	((Dmac *)hw)->SWTRIGCTRL.reg ^= DMAC_SWTRIGCTRL_SWTRIG5;

	DMAC_CRITICAL_SECTION_LEAVE()
}

static inline void hri_dmac_set_SWTRIGCTRL_SWTRIG6_bit(void *const hw)
{
	DMAC_CRITICAL_SECTION_ENTER()
	((Dmac *)hw)->SWTRIGCTRL.reg |= DMAC_SWTRIGCTRL_SWTRIG6;

	DMAC_CRITICAL_SECTION_LEAVE()
}

static inline void hri_dmac_write_SWTRIGCTRL_SWTRIG6_bit(void *const hw, const bool value)
{
	DMAC_CRITICAL_SECTION_ENTER()
	((Dmac *)hw)->SWTRIGCTRL.reg &= ~DMAC_SWTRIGCTRL_SWTRIG6;
	((Dmac *)hw)->SWTRIGCTRL.reg = value << DMAC_SWTRIGCTRL_SWTRIG6_Pos;

	DMAC_CRITICAL_SECTION_LEAVE()
}

static inline void hri_dmac_clear_SWTRIGCTRL_SWTRIG6_bit(void *const hw)
{
	DMAC_CRITICAL_SECTION_ENTER()
	((Dmac *)hw)->SWTRIGCTRL.reg &= ~DMAC_SWTRIGCTRL_SWTRIG6;

	DMAC_CRITICAL_SECTION_LEAVE()
}

static inline bool hri_dmac_get_SWTRIGCTRL_SWTRIG6_bit(const void *const hw)
{
	uint32_t tmp;

	DMAC_CRITICAL_SECTION_ENTER()
	tmp = ((const Dmac *)hw)->SWTRIGCTRL.reg;
	tmp = (tmp & DMAC_SWTRIGCTRL_SWTRIG6) >> DMAC_SWTRIGCTRL_SWTRIG6_Pos;

	DMAC_CRITICAL_SECTION_LEAVE()

	return (bool)tmp;
}

static inline void hri_dmac_toggle_SWTRIGCTRL_SWTRIG6_bit(void *const hw)
{
	DMAC_CRITICAL_SECTION_ENTER()
	((Dmac *)hw)->SWTRIGCTRL.reg ^= DMAC_SWTRIGCTRL_SWTRIG6;

	DMAC_CRITICAL_SECTION_LEAVE()
}

static inline void hri_dmac_set_SWTRIGCTRL_SWTRIG7_bit(void *const hw)
{
	DMAC_CRITICAL_SECTION_ENTER()
	((Dmac *)hw)->SWTRIGCTRL.reg |= DMAC_SWTRIGCTRL_SWTRIG7;

	DMAC_CRITICAL_SECTION_LEAVE()
}

static inline void hri_dmac_write_SWTRIGCTRL_SWTRIG7_bit(void *const hw, const bool value)
{
	DMAC_CRITICAL_SECTION_ENTER()
	((Dmac *)hw)->SWTRIGCTRL.reg &= ~DMAC_SWTRIGCTRL_SWTRIG7;
	((Dmac *)hw)->SWTRIGCTRL.reg = value << DMAC_SWTRIGCTRL_SWTRIG7_Pos;

	DMAC_CRITICAL_SECTION_LEAVE()
}

static inline void hri_dmac_clear_SWTRIGCTRL_SWTRIG7_bit(void *const hw)
{
	DMAC_CRITICAL_SECTION_ENTER()
	((Dmac *)hw)->SWTRIGCTRL.reg &= ~DMAC_SWTRIGCTRL_SWTRIG7;

	DMAC_CRITICAL_SECTION_LEAVE()
}

static inline bool hri_dmac_get_SWTRIGCTRL_SWTRIG7_bit(const void *const hw)
{
	uint32_t tmp;

	DMAC_CRITICAL_SECTION_ENTER()
	tmp = ((const Dmac *)hw)->SWTRIGCTRL.reg;
	tmp = (tmp & DMAC_SWTRIGCTRL_SWTRIG7) >> DMAC_SWTRIGCTRL_SWTRIG7_Pos;

	DMAC_CRITICAL_SECTION_LEAVE()

	return (bool)tmp;
}

static inline void hri_dmac_toggle_SWTRIGCTRL_SWTRIG7_bit(void *const hw)
{
	DMAC_CRITICAL_SECTION_ENTER()
	((Dmac *)hw)->SWTRIGCTRL.reg ^= DMAC_SWTRIGCTRL_SWTRIG7;

	DMAC_CRITICAL_SECTION_LEAVE()
}

static inline void hri_dmac_set_SWTRIGCTRL_SWTRIG8_bit(void *const hw)
{
	DMAC_CRITICAL_SECTION_ENTER()
	((Dmac *)hw)->SWTRIGCTRL.reg |= DMAC_SWTRIGCTRL_SWTRIG8;

	DMAC_CRITICAL_SECTION_LEAVE()
}

static inline void hri_dmac_write_SWTRIGCTRL_SWTRIG8_bit(void *const hw, const bool value)
{
	DMAC_CRITICAL_SECTION_ENTER()
	((Dmac *)hw)->SWTRIGCTRL.reg &= ~DMAC_SWTRIGCTRL_SWTRIG8;
	((Dmac *)hw)->SWTRIGCTRL.reg = value << DMAC_SWTRIGCTRL_SWTRIG8_Pos;

	DMAC_CRITICAL_SECTION_LEAVE()
}

static inline void hri_dmac_clear_SWTRIGCTRL_SWTRIG8_bit(void *const hw)
{
	DMAC_CRITICAL_SECTION_ENTER()
	((Dmac *)hw)->SWTRIGCTRL.reg &= ~DMAC_SWTRIGCTRL_SWTRIG8;

	DMAC_CRITICAL_SECTION_LEAVE()
}

static inline bool hri_dmac_get_SWTRIGCTRL_SWTRIG8_bit(const void *const hw)
{
	uint32_t tmp;

	DMAC_CRITICAL_SECTION_ENTER()
	tmp = ((const Dmac *)hw)->SWTRIGCTRL.reg;
	tmp = (tmp & DMAC_SWTRIGCTRL_SWTRIG8) >> DMAC_SWTRIGCTRL_SWTRIG8_Pos;

	DMAC_CRITICAL_SECTION_LEAVE()

	return (bool)tmp;
}

static inline void hri_dmac_toggle_SWTRIGCTRL_SWTRIG8_bit(void *const hw)
{
	DMAC_CRITICAL_SECTION_ENTER()
	((Dmac *)hw)->SWTRIGCTRL.reg ^= DMAC_SWTRIGCTRL_SWTRIG8;

	DMAC_CRITICAL_SECTION_LEAVE()
}

static inline void hri_dmac_set_SWTRIGCTRL_SWTRIG9_bit(void *const hw)
{
	DMAC_CRITICAL_SECTION_ENTER()
	((Dmac *)hw)->SWTRIGCTRL.reg |= DMAC_SWTRIGCTRL_SWTRIG9;

	DMAC_CRITICAL_SECTION_LEAVE()
}

static inline void hri_dmac_write_SWTRIGCTRL_SWTRIG9_bit(void *const hw, const bool value)
{
	DMAC_CRITICAL_SECTION_ENTER()
	((Dmac *)hw)->SWTRIGCTRL.reg &= ~DMAC_SWTRIGCTRL_SWTRIG9;
	((Dmac *)hw)->SWTRIGCTRL.reg = value << DMAC_SWTRIGCTRL_SWTRIG9_Pos;

	DMAC_CRITICAL_SECTION_LEAVE()
}

static inline void hri_dmac_clear_SWTRIGCTRL_SWTRIG9_bit(void *const hw)
{
	DMAC_CRITICAL_SECTION_ENTER()
	((Dmac *)hw)->SWTRIGCTRL.reg &= ~DMAC_SWTRIGCTRL_SWTRIG9;

	DMAC_CRITICAL_SECTION_LEAVE()
}

static inline bool hri_dmac_get_SWTRIGCTRL_SWTRIG9_bit(const void *const hw)
{
	uint32_t tmp;

	DMAC_CRITICAL_SECTION_ENTER()
	tmp = ((const Dmac *)hw)->SWTRIGCTRL.reg;
	tmp = (tmp & DMAC_SWTRIGCTRL_SWTRIG9) >> DMAC_SWTRIGCTRL_SWTRIG9_Pos;

	DMAC_CRITICAL_SECTION_LEAVE()

	return (bool)tmp;
}

static inline void hri_dmac_toggle_SWTRIGCTRL_SWTRIG9_bit(void *const hw)
{
	DMAC_CRITICAL_SECTION_ENTER()
	((Dmac *)hw)->SWTRIGCTRL.reg ^= DMAC_SWTRIGCTRL_SWTRIG9;

	DMAC_CRITICAL_SECTION_LEAVE()
}

static inline void hri_dmac_set_SWTRIGCTRL_SWTRIG10_bit(void *const hw)
{
	DMAC_CRITICAL_SECTION_ENTER()
	((Dmac *)hw)->SWTRIGCTRL.reg |= DMAC_SWTRIGCTRL_SWTRIG10;

	DMAC_CRITICAL_SECTION_LEAVE()
}

static inline void hri_dmac_write_SWTRIGCTRL_SWTRIG10_bit(void *const hw, const bool value)
{
	DMAC_CRITICAL_SECTION_ENTER()
	((Dmac *)hw)->SWTRIGCTRL.reg &= ~DMAC_SWTRIGCTRL_SWTRIG10;
	((Dmac *)hw)->SWTRIGCTRL.reg = value << DMAC_SWTRIGCTRL_SWTRIG10_Pos;

	DMAC_CRITICAL_SECTION_LEAVE()
}

static inline void hri_dmac_clear_SWTRIGCTRL_SWTRIG10_bit(void *const hw)
{
	DMAC_CRITICAL_SECTION_ENTER()
	((Dmac *)hw)->SWTRIGCTRL.reg &= ~DMAC_SWTRIGCTRL_SWTRIG10;

	DMAC_CRITICAL_SECTION_LEAVE()
}

static inline bool hri_dmac_get_SWTRIGCTRL_SWTRIG10_bit(const void *const hw)
{
	uint32_t tmp;

	DMAC_CRITICAL_SECTION_ENTER()
	tmp = ((const Dmac *)hw)->SWTRIGCTRL.reg;
	tmp = (tmp & DMAC_SWTRIGCTRL_SWTRIG10) >> DMAC_SWTRIGCTRL_SWTRIG10_Pos;

	DMAC_CRITICAL_SECTION_LEAVE()

	return (bool)tmp;
}

static inline void hri_dmac_toggle_SWTRIGCTRL_SWTRIG10_bit(void *const hw)
{
	DMAC_CRITICAL_SECTION_ENTER()
	((Dmac *)hw)->SWTRIGCTRL.reg ^= DMAC_SWTRIGCTRL_SWTRIG10;

	DMAC_CRITICAL_SECTION_LEAVE()
}

static inline void hri_dmac_set_SWTRIGCTRL_SWTRIG11_bit(void *const hw)
{
	DMAC_CRITICAL_SECTION_ENTER()
	((Dmac *)hw)->SWTRIGCTRL.reg |= DMAC_SWTRIGCTRL_SWTRIG11;

	DMAC_CRITICAL_SECTION_LEAVE()
}

static inline void hri_dmac_write_SWTRIGCTRL_SWTRIG11_bit(void *const hw, const bool value)
{
	DMAC_CRITICAL_SECTION_ENTER()
	((Dmac *)hw)->SWTRIGCTRL.reg &= ~DMAC_SWTRIGCTRL_SWTRIG11;
	((Dmac *)hw)->SWTRIGCTRL.reg = value << DMAC_SWTRIGCTRL_SWTRIG11_Pos;

	DMAC_CRITICAL_SECTION_LEAVE()
}

static inline void hri_dmac_clear_SWTRIGCTRL_SWTRIG11_bit(void *const hw)
{
	DMAC_CRITICAL_SECTION_ENTER()
	((Dmac *)hw)->SWTRIGCTRL.reg &= ~DMAC_SWTRIGCTRL_SWTRIG11;

	DMAC_CRITICAL_SECTION_LEAVE()
}

static inline bool hri_dmac_get_SWTRIGCTRL_SWTRIG11_bit(const void *const hw)
{
	uint32_t tmp;

	DMAC_CRITICAL_SECTION_ENTER()
	tmp = ((const Dmac *)hw)->SWTRIGCTRL.reg;
	tmp = (tmp & DMAC_SWTRIGCTRL_SWTRIG11) >> DMAC_SWTRIGCTRL_SWTRIG11_Pos;

	DMAC_CRITICAL_SECTION_LEAVE()

	return (bool)tmp;
}

static inline void hri_dmac_toggle_SWTRIGCTRL_SWTRIG11_bit(void *const hw)
{
	DMAC_CRITICAL_SECTION_ENTER()
	((Dmac *)hw)->SWTRIGCTRL.reg ^= DMAC_SWTRIGCTRL_SWTRIG11;

	DMAC_CRITICAL_SECTION_LEAVE()
}

static inline void hri_dmac_set_PRICTRL0_RRLVLEN0_bit(void *const hw)
{
	DMAC_CRITICAL_SECTION_ENTER()
	((Dmac *)hw)->PRICTRL0.reg |= DMAC_PRICTRL0_RRLVLEN0;

	DMAC_CRITICAL_SECTION_LEAVE()
}

static inline void hri_dmac_write_PRICTRL0_RRLVLEN0_bit(void *const hw, const bool value)
{
	DMAC_CRITICAL_SECTION_ENTER()
	((Dmac *)hw)->PRICTRL0.reg &= ~DMAC_PRICTRL0_RRLVLEN0;
	((Dmac *)hw)->PRICTRL0.reg = value << DMAC_PRICTRL0_RRLVLEN0_Pos;

	DMAC_CRITICAL_SECTION_LEAVE()
}

static inline void hri_dmac_clear_PRICTRL0_RRLVLEN0_bit(void *const hw)
{
	DMAC_CRITICAL_SECTION_ENTER()
	((Dmac *)hw)->PRICTRL0.reg &= ~DMAC_PRICTRL0_RRLVLEN0;

	DMAC_CRITICAL_SECTION_LEAVE()
}

static inline bool hri_dmac_get_PRICTRL0_RRLVLEN0_bit(const void *const hw)
{
	uint32_t tmp;

	DMAC_CRITICAL_SECTION_ENTER()
	tmp = ((const Dmac *)hw)->PRICTRL0.reg;
	tmp = (tmp & DMAC_PRICTRL0_RRLVLEN0) >> DMAC_PRICTRL0_RRLVLEN0_Pos;

	DMAC_CRITICAL_SECTION_LEAVE()

	return (bool)tmp;
}

static inline void hri_dmac_toggle_PRICTRL0_RRLVLEN0_bit(void *const hw)
{
	DMAC_CRITICAL_SECTION_ENTER()
	((Dmac *)hw)->PRICTRL0.reg ^= DMAC_PRICTRL0_RRLVLEN0;

	DMAC_CRITICAL_SECTION_LEAVE()
}

static inline void hri_dmac_set_PRICTRL0_RRLVLEN1_bit(void *const hw)
{
	DMAC_CRITICAL_SECTION_ENTER()
	((Dmac *)hw)->PRICTRL0.reg |= DMAC_PRICTRL0_RRLVLEN1;

	DMAC_CRITICAL_SECTION_LEAVE()
}

static inline void hri_dmac_write_PRICTRL0_RRLVLEN1_bit(void *const hw, const bool value)
{
	DMAC_CRITICAL_SECTION_ENTER()
	((Dmac *)hw)->PRICTRL0.reg &= ~DMAC_PRICTRL0_RRLVLEN1;
	((Dmac *)hw)->PRICTRL0.reg = value << DMAC_PRICTRL0_RRLVLEN1_Pos;

	DMAC_CRITICAL_SECTION_LEAVE()
}

static inline void hri_dmac_clear_PRICTRL0_RRLVLEN1_bit(void *const hw)
{
	DMAC_CRITICAL_SECTION_ENTER()
	((Dmac *)hw)->PRICTRL0.reg &= ~DMAC_PRICTRL0_RRLVLEN1;

	DMAC_CRITICAL_SECTION_LEAVE()
}

static inline bool hri_dmac_get_PRICTRL0_RRLVLEN1_bit(const void *const hw)
{
	uint32_t tmp;

	DMAC_CRITICAL_SECTION_ENTER()
	tmp = ((const Dmac *)hw)->PRICTRL0.reg;
	tmp = (tmp & DMAC_PRICTRL0_RRLVLEN1) >> DMAC_PRICTRL0_RRLVLEN1_Pos;

	DMAC_CRITICAL_SECTION_LEAVE()

	return (bool)tmp;
}

static inline void hri_dmac_toggle_PRICTRL0_RRLVLEN1_bit(void *const hw)
{
	DMAC_CRITICAL_SECTION_ENTER()
	((Dmac *)hw)->PRICTRL0.reg ^= DMAC_PRICTRL0_RRLVLEN1;

	DMAC_CRITICAL_SECTION_LEAVE()
}

static inline void hri_dmac_set_PRICTRL0_RRLVLEN2_bit(void *const hw)
{
	DMAC_CRITICAL_SECTION_ENTER()
	((Dmac *)hw)->PRICTRL0.reg |= DMAC_PRICTRL0_RRLVLEN2;

	DMAC_CRITICAL_SECTION_LEAVE()
}

static inline void hri_dmac_write_PRICTRL0_RRLVLEN2_bit(void *const hw, const bool value)
{
	DMAC_CRITICAL_SECTION_ENTER()
	((Dmac *)hw)->PRICTRL0.reg &= ~DMAC_PRICTRL0_RRLVLEN2;
	((Dmac *)hw)->PRICTRL0.reg = value << DMAC_PRICTRL0_RRLVLEN2_Pos;

	DMAC_CRITICAL_SECTION_LEAVE()
}

static inline void hri_dmac_clear_PRICTRL0_RRLVLEN2_bit(void *const hw)
{
	DMAC_CRITICAL_SECTION_ENTER()
	((Dmac *)hw)->PRICTRL0.reg &= ~DMAC_PRICTRL0_RRLVLEN2;

	DMAC_CRITICAL_SECTION_LEAVE()
}

static inline bool hri_dmac_get_PRICTRL0_RRLVLEN2_bit(const void *const hw)
{
	uint32_t tmp;

	DMAC_CRITICAL_SECTION_ENTER()
	tmp = ((const Dmac *)hw)->PRICTRL0.reg;
	tmp = (tmp & DMAC_PRICTRL0_RRLVLEN2) >> DMAC_PRICTRL0_RRLVLEN2_Pos;

	DMAC_CRITICAL_SECTION_LEAVE()

	return (bool)tmp;
}

static inline void hri_dmac_toggle_PRICTRL0_RRLVLEN2_bit(void *const hw)
{
	DMAC_CRITICAL_SECTION_ENTER()
	((Dmac *)hw)->PRICTRL0.reg ^= DMAC_PRICTRL0_RRLVLEN2;

	DMAC_CRITICAL_SECTION_LEAVE()
}

static inline void hri_dmac_set_PRICTRL0_RRLVLEN3_bit(void *const hw)
{
	DMAC_CRITICAL_SECTION_ENTER()
	((Dmac *)hw)->PRICTRL0.reg |= DMAC_PRICTRL0_RRLVLEN3;

	DMAC_CRITICAL_SECTION_LEAVE()
}

static inline void hri_dmac_write_PRICTRL0_RRLVLEN3_bit(void *const hw, const bool value)
{
	DMAC_CRITICAL_SECTION_ENTER()
	((Dmac *)hw)->PRICTRL0.reg &= ~DMAC_PRICTRL0_RRLVLEN3;
	((Dmac *)hw)->PRICTRL0.reg = value << DMAC_PRICTRL0_RRLVLEN3_Pos;

	DMAC_CRITICAL_SECTION_LEAVE()
}

static inline void hri_dmac_clear_PRICTRL0_RRLVLEN3_bit(void *const hw)
{
	DMAC_CRITICAL_SECTION_ENTER()
	((Dmac *)hw)->PRICTRL0.reg &= ~DMAC_PRICTRL0_RRLVLEN3;

	DMAC_CRITICAL_SECTION_LEAVE()
}

static inline bool hri_dmac_get_PRICTRL0_RRLVLEN3_bit(const void *const hw)
{
	uint32_t tmp;

	DMAC_CRITICAL_SECTION_ENTER()
	tmp = ((const Dmac *)hw)->PRICTRL0.reg;
	tmp = (tmp & DMAC_PRICTRL0_RRLVLEN3) >> DMAC_PRICTRL0_RRLVLEN3_Pos;

	DMAC_CRITICAL_SECTION_LEAVE()

	return (bool)tmp;
}

static inline void hri_dmac_toggle_PRICTRL0_RRLVLEN3_bit(void *const hw)
{
	DMAC_CRITICAL_SECTION_ENTER()
	((Dmac *)hw)->PRICTRL0.reg ^= DMAC_PRICTRL0_RRLVLEN3;

	DMAC_CRITICAL_SECTION_LEAVE()
}

static inline void hri_dmac_set_INTPEND_TERR_bit(void *const hw)
{
	DMAC_CRITICAL_SECTION_ENTER()
	((Dmac *)hw)->INTPEND.reg |= DMAC_INTPEND_TERR;

	DMAC_CRITICAL_SECTION_LEAVE()
}

static inline void hri_dmac_write_INTPEND_TERR_bit(void *const hw, const bool value)
{
	DMAC_CRITICAL_SECTION_ENTER()
	((Dmac *)hw)->INTPEND.reg &= ~DMAC_INTPEND_TERR;
	((Dmac *)hw)->INTPEND.reg = value << DMAC_INTPEND_TERR_Pos;

	DMAC_CRITICAL_SECTION_LEAVE()
}

static inline void hri_dmac_clear_INTPEND_TERR_bit(void *const hw)
{
	DMAC_CRITICAL_SECTION_ENTER()
	((Dmac *)hw)->INTPEND.reg &= ~DMAC_INTPEND_TERR;

	DMAC_CRITICAL_SECTION_LEAVE()
}

static inline bool hri_dmac_get_INTPEND_TERR_bit(const void *const hw)
{
	uint16_t tmp;

	DMAC_CRITICAL_SECTION_ENTER()
	tmp = ((const Dmac *)hw)->INTPEND.reg;
	tmp = (tmp & DMAC_INTPEND_TERR) >> DMAC_INTPEND_TERR_Pos;

	DMAC_CRITICAL_SECTION_LEAVE()

	return (bool)tmp;
}

static inline void hri_dmac_toggle_INTPEND_TERR_bit(void *const hw)
{
	DMAC_CRITICAL_SECTION_ENTER()
	((Dmac *)hw)->INTPEND.reg ^= DMAC_INTPEND_TERR;

	DMAC_CRITICAL_SECTION_LEAVE()
}

static inline void hri_dmac_set_INTPEND_TCMPL_bit(void *const hw)
{
	DMAC_CRITICAL_SECTION_ENTER()
	((Dmac *)hw)->INTPEND.reg |= DMAC_INTPEND_TCMPL;

	DMAC_CRITICAL_SECTION_LEAVE()
}

static inline void hri_dmac_write_INTPEND_TCMPL_bit(void *const hw, const bool value)
{
	DMAC_CRITICAL_SECTION_ENTER()
	((Dmac *)hw)->INTPEND.reg &= ~DMAC_INTPEND_TCMPL;
	((Dmac *)hw)->INTPEND.reg = value << DMAC_INTPEND_TCMPL_Pos;

	DMAC_CRITICAL_SECTION_LEAVE()
}

static inline void hri_dmac_clear_INTPEND_TCMPL_bit(void *const hw)
{
	DMAC_CRITICAL_SECTION_ENTER()
	((Dmac *)hw)->INTPEND.reg &= ~DMAC_INTPEND_TCMPL;

	DMAC_CRITICAL_SECTION_LEAVE()
}

static inline bool hri_dmac_get_INTPEND_TCMPL_bit(const void *const hw)
{
	uint16_t tmp;

	DMAC_CRITICAL_SECTION_ENTER()
	tmp = ((const Dmac *)hw)->INTPEND.reg;
	tmp = (tmp & DMAC_INTPEND_TCMPL) >> DMAC_INTPEND_TCMPL_Pos;

	DMAC_CRITICAL_SECTION_LEAVE()

	return (bool)tmp;
}

static inline void hri_dmac_toggle_INTPEND_TCMPL_bit(void *const hw)
{
	DMAC_CRITICAL_SECTION_ENTER()
	((Dmac *)hw)->INTPEND.reg ^= DMAC_INTPEND_TCMPL;

	DMAC_CRITICAL_SECTION_LEAVE()
}

static inline void hri_dmac_set_INTPEND_SUSP_bit(void *const hw)
{
	DMAC_CRITICAL_SECTION_ENTER()
	((Dmac *)hw)->INTPEND.reg |= DMAC_INTPEND_SUSP;

	DMAC_CRITICAL_SECTION_LEAVE()
}

static inline void hri_dmac_write_INTPEND_SUSP_bit(void *const hw, const bool value)
{
	DMAC_CRITICAL_SECTION_ENTER()
	((Dmac *)hw)->INTPEND.reg &= ~DMAC_INTPEND_SUSP;
	((Dmac *)hw)->INTPEND.reg = value << DMAC_INTPEND_SUSP_Pos;

	DMAC_CRITICAL_SECTION_LEAVE()
}

static inline void hri_dmac_clear_INTPEND_SUSP_bit(void *const hw)
{
	DMAC_CRITICAL_SECTION_ENTER()
	((Dmac *)hw)->INTPEND.reg &= ~DMAC_INTPEND_SUSP;

	DMAC_CRITICAL_SECTION_LEAVE()
}

static inline bool hri_dmac_get_INTPEND_SUSP_bit(const void *const hw)
{
	uint16_t tmp;

	DMAC_CRITICAL_SECTION_ENTER()
	tmp = ((const Dmac *)hw)->INTPEND.reg;
	tmp = (tmp & DMAC_INTPEND_SUSP) >> DMAC_INTPEND_SUSP_Pos;

	DMAC_CRITICAL_SECTION_LEAVE()

	return (bool)tmp;
}

static inline void hri_dmac_toggle_INTPEND_SUSP_bit(void *const hw)
{
	DMAC_CRITICAL_SECTION_ENTER()
	((Dmac *)hw)->INTPEND.reg ^= DMAC_INTPEND_SUSP;

	DMAC_CRITICAL_SECTION_LEAVE()
}

static inline void hri_dmac_set_INTPEND_FERR_bit(void *const hw)
{
	DMAC_CRITICAL_SECTION_ENTER()
	((Dmac *)hw)->INTPEND.reg |= DMAC_INTPEND_FERR;

	DMAC_CRITICAL_SECTION_LEAVE()
}

static inline void hri_dmac_write_INTPEND_FERR_bit(void *const hw, const bool value)
{
	DMAC_CRITICAL_SECTION_ENTER()
	((Dmac *)hw)->INTPEND.reg &= ~DMAC_INTPEND_FERR;
	((Dmac *)hw)->INTPEND.reg = value << DMAC_INTPEND_FERR_Pos;

	DMAC_CRITICAL_SECTION_LEAVE()
}

static inline void hri_dmac_clear_INTPEND_FERR_bit(void *const hw)
{
	DMAC_CRITICAL_SECTION_ENTER()
	((Dmac *)hw)->INTPEND.reg &= ~DMAC_INTPEND_FERR;

	DMAC_CRITICAL_SECTION_LEAVE()
}

static inline bool hri_dmac_get_INTPEND_FERR_bit(const void *const hw)
{
	uint16_t tmp;

	DMAC_CRITICAL_SECTION_ENTER()
	tmp = ((const Dmac *)hw)->INTPEND.reg;
	tmp = (tmp & DMAC_INTPEND_FERR) >> DMAC_INTPEND_FERR_Pos;

	DMAC_CRITICAL_SECTION_LEAVE()

	return (bool)tmp;
}

static inline void hri_dmac_toggle_INTPEND_FERR_bit(void *const hw)
{
	DMAC_CRITICAL_SECTION_ENTER()
	((Dmac *)hw)->INTPEND.reg ^= DMAC_INTPEND_FERR;

	DMAC_CRITICAL_SECTION_LEAVE()
}

static inline void hri_dmac_set_INTPEND_BUSY_bit(void *const hw)
{
	DMAC_CRITICAL_SECTION_ENTER()
	((Dmac *)hw)->INTPEND.reg |= DMAC_INTPEND_BUSY;

	DMAC_CRITICAL_SECTION_LEAVE()
}

static inline void hri_dmac_write_INTPEND_BUSY_bit(void *const hw, const bool value)
{
	DMAC_CRITICAL_SECTION_ENTER()
	((Dmac *)hw)->INTPEND.reg &= ~DMAC_INTPEND_BUSY;
	((Dmac *)hw)->INTPEND.reg = value << DMAC_INTPEND_BUSY_Pos;

	DMAC_CRITICAL_SECTION_LEAVE()
}

static inline void hri_dmac_clear_INTPEND_BUSY_bit(void *const hw)
{
	DMAC_CRITICAL_SECTION_ENTER()
	((Dmac *)hw)->INTPEND.reg &= ~DMAC_INTPEND_BUSY;

	DMAC_CRITICAL_SECTION_LEAVE()
}

static inline bool hri_dmac_get_INTPEND_BUSY_bit(const void *const hw)
{
	uint16_t tmp;

	DMAC_CRITICAL_SECTION_ENTER()
	tmp = ((const Dmac *)hw)->INTPEND.reg;
	tmp = (tmp & DMAC_INTPEND_BUSY) >> DMAC_INTPEND_BUSY_Pos;

	DMAC_CRITICAL_SECTION_LEAVE()

	return (bool)tmp;
}

static inline void hri_dmac_toggle_INTPEND_BUSY_bit(void *const hw)
{
	DMAC_CRITICAL_SECTION_ENTER()
	((Dmac *)hw)->INTPEND.reg ^= DMAC_INTPEND_BUSY;

	DMAC_CRITICAL_SECTION_LEAVE()
}

static inline void hri_dmac_set_INTPEND_PEND_bit(void *const hw)
{
	DMAC_CRITICAL_SECTION_ENTER()
	((Dmac *)hw)->INTPEND.reg |= DMAC_INTPEND_PEND;

	DMAC_CRITICAL_SECTION_LEAVE()
}

static inline void hri_dmac_write_INTPEND_PEND_bit(void *const hw, const bool value)
{
	DMAC_CRITICAL_SECTION_ENTER()
	((Dmac *)hw)->INTPEND.reg &= ~DMAC_INTPEND_PEND;
	((Dmac *)hw)->INTPEND.reg = value << DMAC_INTPEND_PEND_Pos;

	DMAC_CRITICAL_SECTION_LEAVE()
}

static inline void hri_dmac_clear_INTPEND_PEND_bit(void *const hw)
{
	DMAC_CRITICAL_SECTION_ENTER()
	((Dmac *)hw)->INTPEND.reg &= ~DMAC_INTPEND_PEND;

	DMAC_CRITICAL_SECTION_LEAVE()
}

static inline bool hri_dmac_get_INTPEND_PEND_bit(const void *const hw)
{
	uint16_t tmp;

	DMAC_CRITICAL_SECTION_ENTER()
	tmp = ((const Dmac *)hw)->INTPEND.reg;
	tmp = (tmp & DMAC_INTPEND_PEND) >> DMAC_INTPEND_PEND_Pos;

	DMAC_CRITICAL_SECTION_LEAVE()

	return (bool)tmp;
}

static inline void hri_dmac_toggle_INTPEND_PEND_bit(void *const hw)
{
	DMAC_CRITICAL_SECTION_ENTER()
	((Dmac *)hw)->INTPEND.reg ^= DMAC_INTPEND_PEND;

	DMAC_CRITICAL_SECTION_LEAVE()
}

static inline bool hri_dmac_get_INTSTATUS_CHINT0_bit(const void *const hw)
{
	return (((const Dmac *)hw)->INTSTATUS.reg & DMAC_INTSTATUS_CHINT0) >> DMAC_INTSTATUS_CHINT0_Pos;
}

static inline bool hri_dmac_get_INTSTATUS_CHINT1_bit(const void *const hw)
{
	return (((const Dmac *)hw)->INTSTATUS.reg & DMAC_INTSTATUS_CHINT1) >> DMAC_INTSTATUS_CHINT1_Pos;
}

static inline bool hri_dmac_get_INTSTATUS_CHINT2_bit(const void *const hw)
{
	return (((const Dmac *)hw)->INTSTATUS.reg & DMAC_INTSTATUS_CHINT2) >> DMAC_INTSTATUS_CHINT2_Pos;
}

static inline bool hri_dmac_get_INTSTATUS_CHINT3_bit(const void *const hw)
{
	return (((const Dmac *)hw)->INTSTATUS.reg & DMAC_INTSTATUS_CHINT3) >> DMAC_INTSTATUS_CHINT3_Pos;
}

static inline bool hri_dmac_get_INTSTATUS_CHINT4_bit(const void *const hw)
{
	return (((const Dmac *)hw)->INTSTATUS.reg & DMAC_INTSTATUS_CHINT4) >> DMAC_INTSTATUS_CHINT4_Pos;
}

static inline bool hri_dmac_get_INTSTATUS_CHINT5_bit(const void *const hw)
{
	return (((const Dmac *)hw)->INTSTATUS.reg & DMAC_INTSTATUS_CHINT5) >> DMAC_INTSTATUS_CHINT5_Pos;
}

static inline bool hri_dmac_get_INTSTATUS_CHINT6_bit(const void *const hw)
{
	return (((const Dmac *)hw)->INTSTATUS.reg & DMAC_INTSTATUS_CHINT6) >> DMAC_INTSTATUS_CHINT6_Pos;
}

static inline bool hri_dmac_get_INTSTATUS_CHINT7_bit(const void *const hw)
{
	return (((const Dmac *)hw)->INTSTATUS.reg & DMAC_INTSTATUS_CHINT7) >> DMAC_INTSTATUS_CHINT7_Pos;
}

static inline bool hri_dmac_get_INTSTATUS_CHINT8_bit(const void *const hw)
{
	return (((const Dmac *)hw)->INTSTATUS.reg & DMAC_INTSTATUS_CHINT8) >> DMAC_INTSTATUS_CHINT8_Pos;
}

static inline bool hri_dmac_get_INTSTATUS_CHINT9_bit(const void *const hw)
{
	return (((const Dmac *)hw)->INTSTATUS.reg & DMAC_INTSTATUS_CHINT9) >> DMAC_INTSTATUS_CHINT9_Pos;
}

static inline bool hri_dmac_get_INTSTATUS_CHINT10_bit(const void *const hw)
{
	return (((const Dmac *)hw)->INTSTATUS.reg & DMAC_INTSTATUS_CHINT10) >> DMAC_INTSTATUS_CHINT10_Pos;
}

static inline bool hri_dmac_get_INTSTATUS_CHINT11_bit(const void *const hw)
{
	return (((const Dmac *)hw)->INTSTATUS.reg & DMAC_INTSTATUS_CHINT11) >> DMAC_INTSTATUS_CHINT11_Pos;
}

static inline bool hri_dmac_get_BUSYCH_BUSYCH0_bit(const void *const hw)
{
	uint32_t tmp;

	DMAC_CRITICAL_SECTION_ENTER()
	tmp = ((const Dmac *)hw)->BUSYCH.reg;
	tmp = (tmp & DMAC_BUSYCH_BUSYCH0) >> DMAC_BUSYCH_BUSYCH0_Pos;

	DMAC_CRITICAL_SECTION_LEAVE()

	return (bool)tmp;
}

static inline bool hri_dmac_get_BUSYCH_BUSYCH1_bit(const void *const hw)
{
	uint32_t tmp;

	DMAC_CRITICAL_SECTION_ENTER()
	tmp = ((const Dmac *)hw)->BUSYCH.reg;
	tmp = (tmp & DMAC_BUSYCH_BUSYCH1) >> DMAC_BUSYCH_BUSYCH1_Pos;

	DMAC_CRITICAL_SECTION_LEAVE()

	return (bool)tmp;
}

static inline bool hri_dmac_get_BUSYCH_BUSYCH2_bit(const void *const hw)
{
	uint32_t tmp;

	DMAC_CRITICAL_SECTION_ENTER()
	tmp = ((const Dmac *)hw)->BUSYCH.reg;
	tmp = (tmp & DMAC_BUSYCH_BUSYCH2) >> DMAC_BUSYCH_BUSYCH2_Pos;

	DMAC_CRITICAL_SECTION_LEAVE()

	return (bool)tmp;
}

static inline bool hri_dmac_get_BUSYCH_BUSYCH3_bit(const void *const hw)
{
	uint32_t tmp;

	DMAC_CRITICAL_SECTION_ENTER()
	tmp = ((const Dmac *)hw)->BUSYCH.reg;
	tmp = (tmp & DMAC_BUSYCH_BUSYCH3) >> DMAC_BUSYCH_BUSYCH3_Pos;

	DMAC_CRITICAL_SECTION_LEAVE()

	return (bool)tmp;
}

static inline bool hri_dmac_get_BUSYCH_BUSYCH4_bit(const void *const hw)
{
	uint32_t tmp;

	DMAC_CRITICAL_SECTION_ENTER()
	tmp = ((const Dmac *)hw)->BUSYCH.reg;
	tmp = (tmp & DMAC_BUSYCH_BUSYCH4) >> DMAC_BUSYCH_BUSYCH4_Pos;

	DMAC_CRITICAL_SECTION_LEAVE()

	return (bool)tmp;
}

static inline bool hri_dmac_get_BUSYCH_BUSYCH5_bit(const void *const hw)
{
	uint32_t tmp;

	DMAC_CRITICAL_SECTION_ENTER()
	tmp = ((const Dmac *)hw)->BUSYCH.reg;
	tmp = (tmp & DMAC_BUSYCH_BUSYCH5) >> DMAC_BUSYCH_BUSYCH5_Pos;

	DMAC_CRITICAL_SECTION_LEAVE()

	return (bool)tmp;
}

static inline bool hri_dmac_get_BUSYCH_BUSYCH6_bit(const void *const hw)
{
	uint32_t tmp;

	DMAC_CRITICAL_SECTION_ENTER()
	tmp = ((const Dmac *)hw)->BUSYCH.reg;
	tmp = (tmp & DMAC_BUSYCH_BUSYCH6) >> DMAC_BUSYCH_BUSYCH6_Pos;

	DMAC_CRITICAL_SECTION_LEAVE()

	return (bool)tmp;
}

static inline bool hri_dmac_get_BUSYCH_BUSYCH7_bit(const void *const hw)
{
	uint32_t tmp;

	DMAC_CRITICAL_SECTION_ENTER()
	tmp = ((const Dmac *)hw)->BUSYCH.reg;
	tmp = (tmp & DMAC_BUSYCH_BUSYCH7) >> DMAC_BUSYCH_BUSYCH7_Pos;

	DMAC_CRITICAL_SECTION_LEAVE()

	return (bool)tmp;
}

static inline bool hri_dmac_get_BUSYCH_BUSYCH8_bit(const void *const hw)
{
	uint32_t tmp;

	DMAC_CRITICAL_SECTION_ENTER()
	tmp = ((const Dmac *)hw)->BUSYCH.reg;
	tmp = (tmp & DMAC_BUSYCH_BUSYCH8) >> DMAC_BUSYCH_BUSYCH8_Pos;

	DMAC_CRITICAL_SECTION_LEAVE()

	return (bool)tmp;
}

static inline bool hri_dmac_get_BUSYCH_BUSYCH9_bit(const void *const hw)
{
	uint32_t tmp;

	DMAC_CRITICAL_SECTION_ENTER()
	tmp = ((const Dmac *)hw)->BUSYCH.reg;
	tmp = (tmp & DMAC_BUSYCH_BUSYCH9) >> DMAC_BUSYCH_BUSYCH9_Pos;

	DMAC_CRITICAL_SECTION_LEAVE()

	return (bool)tmp;
}

static inline bool hri_dmac_get_BUSYCH_BUSYCH10_bit(const void *const hw)
{
	uint32_t tmp;

	DMAC_CRITICAL_SECTION_ENTER()
	tmp = ((const Dmac *)hw)->BUSYCH.reg;
	tmp = (tmp & DMAC_BUSYCH_BUSYCH10) >> DMAC_BUSYCH_BUSYCH10_Pos;

	DMAC_CRITICAL_SECTION_LEAVE()

	return (bool)tmp;
}

static inline bool hri_dmac_get_BUSYCH_BUSYCH11_bit(const void *const hw)
{
	uint32_t tmp;

	DMAC_CRITICAL_SECTION_ENTER()
	tmp = ((const Dmac *)hw)->BUSYCH.reg;
	tmp = (tmp & DMAC_BUSYCH_BUSYCH11) >> DMAC_BUSYCH_BUSYCH11_Pos;

	DMAC_CRITICAL_SECTION_LEAVE()

	return (bool)tmp;
}

static inline bool hri_dmac_get_PENDCH_PENDCH0_bit(const void *const hw)
{
	uint32_t tmp;

	DMAC_CRITICAL_SECTION_ENTER()
	tmp = ((const Dmac *)hw)->PENDCH.reg;
	tmp = (tmp & DMAC_PENDCH_PENDCH0) >> DMAC_PENDCH_PENDCH0_Pos;

	DMAC_CRITICAL_SECTION_LEAVE()

	return (bool)tmp;
}

static inline bool hri_dmac_get_PENDCH_PENDCH1_bit(const void *const hw)
{
	uint32_t tmp;

	DMAC_CRITICAL_SECTION_ENTER()
	tmp = ((const Dmac *)hw)->PENDCH.reg;
	tmp = (tmp & DMAC_PENDCH_PENDCH1) >> DMAC_PENDCH_PENDCH1_Pos;

	DMAC_CRITICAL_SECTION_LEAVE()

	return (bool)tmp;
}

static inline bool hri_dmac_get_PENDCH_PENDCH2_bit(const void *const hw)
{
	uint32_t tmp;

	DMAC_CRITICAL_SECTION_ENTER()
	tmp = ((const Dmac *)hw)->PENDCH.reg;
	tmp = (tmp & DMAC_PENDCH_PENDCH2) >> DMAC_PENDCH_PENDCH2_Pos;

	DMAC_CRITICAL_SECTION_LEAVE()

	return (bool)tmp;
}

static inline bool hri_dmac_get_PENDCH_PENDCH3_bit(const void *const hw)
{
	uint32_t tmp;

	DMAC_CRITICAL_SECTION_ENTER()
	tmp = ((const Dmac *)hw)->PENDCH.reg;
	tmp = (tmp & DMAC_PENDCH_PENDCH3) >> DMAC_PENDCH_PENDCH3_Pos;

	DMAC_CRITICAL_SECTION_LEAVE()

	return (bool)tmp;
}

static inline bool hri_dmac_get_PENDCH_PENDCH4_bit(const void *const hw)
{
	uint32_t tmp;

	DMAC_CRITICAL_SECTION_ENTER()
	tmp = ((const Dmac *)hw)->PENDCH.reg;
	tmp = (tmp & DMAC_PENDCH_PENDCH4) >> DMAC_PENDCH_PENDCH4_Pos;

	DMAC_CRITICAL_SECTION_LEAVE()

	return (bool)tmp;
}

static inline bool hri_dmac_get_PENDCH_PENDCH5_bit(const void *const hw)
{
	uint32_t tmp;

	DMAC_CRITICAL_SECTION_ENTER()
	tmp = ((const Dmac *)hw)->PENDCH.reg;
	tmp = (tmp & DMAC_PENDCH_PENDCH5) >> DMAC_PENDCH_PENDCH5_Pos;

	DMAC_CRITICAL_SECTION_LEAVE()

	return (bool)tmp;
}

static inline bool hri_dmac_get_PENDCH_PENDCH6_bit(const void *const hw)
{
	uint32_t tmp;

	DMAC_CRITICAL_SECTION_ENTER()
	tmp = ((const Dmac *)hw)->PENDCH.reg;
	tmp = (tmp & DMAC_PENDCH_PENDCH6) >> DMAC_PENDCH_PENDCH6_Pos;

	DMAC_CRITICAL_SECTION_LEAVE()

	return (bool)tmp;
}

static inline bool hri_dmac_get_PENDCH_PENDCH7_bit(const void *const hw)
{
	uint32_t tmp;

	DMAC_CRITICAL_SECTION_ENTER()
	tmp = ((const Dmac *)hw)->PENDCH.reg;
	tmp = (tmp & DMAC_PENDCH_PENDCH7) >> DMAC_PENDCH_PENDCH7_Pos;

	DMAC_CRITICAL_SECTION_LEAVE()

	return (bool)tmp;
}

static inline bool hri_dmac_get_PENDCH_PENDCH8_bit(const void *const hw)
{
	uint32_t tmp;

	DMAC_CRITICAL_SECTION_ENTER()
	tmp = ((const Dmac *)hw)->PENDCH.reg;
	tmp = (tmp & DMAC_PENDCH_PENDCH8) >> DMAC_PENDCH_PENDCH8_Pos;

	DMAC_CRITICAL_SECTION_LEAVE()

	return (bool)tmp;
}

static inline bool hri_dmac_get_PENDCH_PENDCH9_bit(const void *const hw)
{
	uint32_t tmp;

	DMAC_CRITICAL_SECTION_ENTER()
	tmp = ((const Dmac *)hw)->PENDCH.reg;
	tmp = (tmp & DMAC_PENDCH_PENDCH9) >> DMAC_PENDCH_PENDCH9_Pos;

	DMAC_CRITICAL_SECTION_LEAVE()

	return (bool)tmp;
}

static inline bool hri_dmac_get_PENDCH_PENDCH10_bit(const void *const hw)
{
	uint32_t tmp;

	DMAC_CRITICAL_SECTION_ENTER()
	tmp = ((const Dmac *)hw)->PENDCH.reg;
	tmp = (tmp & DMAC_PENDCH_PENDCH10) >> DMAC_PENDCH_PENDCH10_Pos;

	DMAC_CRITICAL_SECTION_LEAVE()

	return (bool)tmp;
}

static inline bool hri_dmac_get_PENDCH_PENDCH11_bit(const void *const hw)
{
	uint32_t tmp;

	DMAC_CRITICAL_SECTION_ENTER()
	tmp = ((const Dmac *)hw)->PENDCH.reg;
	tmp = (tmp & DMAC_PENDCH_PENDCH11) >> DMAC_PENDCH_PENDCH11_Pos;

	DMAC_CRITICAL_SECTION_LEAVE()

	return (bool)tmp;
}

static inline bool hri_dmac_get_ACTIVE_LVLEX0_bit(const void *const hw)
{
	uint32_t tmp;

	DMAC_CRITICAL_SECTION_ENTER()
	tmp = ((const Dmac *)hw)->ACTIVE.reg;
	tmp = (tmp & DMAC_ACTIVE_LVLEX0) >> DMAC_ACTIVE_LVLEX0_Pos;

	DMAC_CRITICAL_SECTION_LEAVE()

	return (bool)tmp;
}

static inline bool hri_dmac_get_ACTIVE_LVLEX1_bit(const void *const hw)
{
	uint32_t tmp;

	DMAC_CRITICAL_SECTION_ENTER()
	tmp = ((const Dmac *)hw)->ACTIVE.reg;
	tmp = (tmp & DMAC_ACTIVE_LVLEX1) >> DMAC_ACTIVE_LVLEX1_Pos;

	DMAC_CRITICAL_SECTION_LEAVE()

	return (bool)tmp;
}

static inline bool hri_dmac_get_ACTIVE_LVLEX2_bit(const void *const hw)
{
	uint32_t tmp;

	DMAC_CRITICAL_SECTION_ENTER()
	tmp = ((const Dmac *)hw)->ACTIVE.reg;
	tmp = (tmp & DMAC_ACTIVE_LVLEX2) >> DMAC_ACTIVE_LVLEX2_Pos;

	DMAC_CRITICAL_SECTION_LEAVE()

	return (bool)tmp;
}

static inline bool hri_dmac_get_ACTIVE_LVLEX3_bit(const void *const hw)
{
	uint32_t tmp;

	DMAC_CRITICAL_SECTION_ENTER()
	tmp = ((const Dmac *)hw)->ACTIVE.reg;
	tmp = (tmp & DMAC_ACTIVE_LVLEX3) >> DMAC_ACTIVE_LVLEX3_Pos;

	DMAC_CRITICAL_SECTION_LEAVE()

	return (bool)tmp;
}

static inline bool hri_dmac_get_ACTIVE_ABUSY_bit(const void *const hw)
{
	uint32_t tmp;

	DMAC_CRITICAL_SECTION_ENTER()
	tmp = ((const Dmac *)hw)->ACTIVE.reg;
	tmp = (tmp & DMAC_ACTIVE_ABUSY) >> DMAC_ACTIVE_ABUSY_Pos;

	DMAC_CRITICAL_SECTION_LEAVE()

	return (bool)tmp;
}

static inline void hri_dmac_set_CHCTRLA_SWRST_bit(void *const hw)
{
	DMAC_CRITICAL_SECTION_ENTER()
	((Dmac *)hw)->CHCTRLA.reg |= DMAC_CHCTRLA_SWRST;

	DMAC_CRITICAL_SECTION_LEAVE()
}

static inline void hri_dmac_set_CHCTRLA_ENABLE_bit(void *const hw)
{
	DMAC_CRITICAL_SECTION_ENTER()
	((Dmac *)hw)->CHCTRLA.reg |= DMAC_CHCTRLA_ENABLE;

	DMAC_CRITICAL_SECTION_LEAVE()
}

static inline void hri_dmac_write_CHCTRLA_ENABLE_bit(void *const hw, const bool value)
{
	DMAC_CRITICAL_SECTION_ENTER()
	((Dmac *)hw)->CHCTRLA.reg &= ~DMAC_CHCTRLA_ENABLE;
	((Dmac *)hw)->CHCTRLA.reg = value << DMAC_CHCTRLA_ENABLE_Pos;

	DMAC_CRITICAL_SECTION_LEAVE()
}

static inline void hri_dmac_clear_CHCTRLA_ENABLE_bit(void *const hw)
{
	DMAC_CRITICAL_SECTION_ENTER()
	((Dmac *)hw)->CHCTRLA.reg &= ~DMAC_CHCTRLA_ENABLE;

	DMAC_CRITICAL_SECTION_LEAVE()
}

static inline bool hri_dmac_get_CHCTRLA_ENABLE_bit(const void *const hw)
{
	uint8_t tmp;

	DMAC_CRITICAL_SECTION_ENTER()
	tmp = ((const Dmac *)hw)->CHCTRLA.reg;
	tmp = (tmp & DMAC_CHCTRLA_ENABLE) >> DMAC_CHCTRLA_ENABLE_Pos;

	DMAC_CRITICAL_SECTION_LEAVE()

	return (bool)tmp;
}

static inline void hri_dmac_toggle_CHCTRLA_ENABLE_bit(void *const hw)
{
	DMAC_CRITICAL_SECTION_ENTER()
	((Dmac *)hw)->CHCTRLA.reg ^= DMAC_CHCTRLA_ENABLE;

	DMAC_CRITICAL_SECTION_LEAVE()
}

static inline void hri_dmac_set_CHCTRLB_EVIE_bit(void *const hw)
{
	DMAC_CRITICAL_SECTION_ENTER()
	((Dmac *)hw)->CHCTRLB.reg |= DMAC_CHCTRLB_EVIE;

	DMAC_CRITICAL_SECTION_LEAVE()
}

static inline void hri_dmac_write_CHCTRLB_EVIE_bit(void *const hw, const bool value)
{
	DMAC_CRITICAL_SECTION_ENTER()
	((Dmac *)hw)->CHCTRLB.reg &= ~DMAC_CHCTRLB_EVIE;
	((Dmac *)hw)->CHCTRLB.reg = value << DMAC_CHCTRLB_EVIE_Pos;

	DMAC_CRITICAL_SECTION_LEAVE()
}

static inline void hri_dmac_clear_CHCTRLB_EVIE_bit(void *const hw)
{
	DMAC_CRITICAL_SECTION_ENTER()
	((Dmac *)hw)->CHCTRLB.reg &= ~DMAC_CHCTRLB_EVIE;

	DMAC_CRITICAL_SECTION_LEAVE()
}

static inline bool hri_dmac_get_CHCTRLB_EVIE_bit(const void *const hw)
{
	uint32_t tmp;

	DMAC_CRITICAL_SECTION_ENTER()
	tmp = ((const Dmac *)hw)->CHCTRLB.reg;
	tmp = (tmp & DMAC_CHCTRLB_EVIE) >> DMAC_CHCTRLB_EVIE_Pos;

	DMAC_CRITICAL_SECTION_LEAVE()

	return (bool)tmp;
}

static inline void hri_dmac_toggle_CHCTRLB_EVIE_bit(void *const hw)
{
	DMAC_CRITICAL_SECTION_ENTER()
	((Dmac *)hw)->CHCTRLB.reg ^= DMAC_CHCTRLB_EVIE;

	DMAC_CRITICAL_SECTION_LEAVE()
}

static inline void hri_dmac_set_CHCTRLB_EVOE_bit(void *const hw)
{
	DMAC_CRITICAL_SECTION_ENTER()
	((Dmac *)hw)->CHCTRLB.reg |= DMAC_CHCTRLB_EVOE;

	DMAC_CRITICAL_SECTION_LEAVE()
}

static inline void hri_dmac_write_CHCTRLB_EVOE_bit(void *const hw, const bool value)
{
	DMAC_CRITICAL_SECTION_ENTER()
	((Dmac *)hw)->CHCTRLB.reg &= ~DMAC_CHCTRLB_EVOE;
	((Dmac *)hw)->CHCTRLB.reg = value << DMAC_CHCTRLB_EVOE_Pos;

	DMAC_CRITICAL_SECTION_LEAVE()
}

static inline void hri_dmac_clear_CHCTRLB_EVOE_bit(void *const hw)
{
	DMAC_CRITICAL_SECTION_ENTER()
	((Dmac *)hw)->CHCTRLB.reg &= ~DMAC_CHCTRLB_EVOE;

	DMAC_CRITICAL_SECTION_LEAVE()
}

static inline bool hri_dmac_get_CHCTRLB_EVOE_bit(const void *const hw)
{
	uint32_t tmp;

	DMAC_CRITICAL_SECTION_ENTER()
	tmp = ((const Dmac *)hw)->CHCTRLB.reg;
	tmp = (tmp & DMAC_CHCTRLB_EVOE) >> DMAC_CHCTRLB_EVOE_Pos;

	DMAC_CRITICAL_SECTION_LEAVE()

	return (bool)tmp;
}

static inline void hri_dmac_toggle_CHCTRLB_EVOE_bit(void *const hw)
{
	DMAC_CRITICAL_SECTION_ENTER()
	((Dmac *)hw)->CHCTRLB.reg ^= DMAC_CHCTRLB_EVOE;

	DMAC_CRITICAL_SECTION_LEAVE()
}

static inline void hri_dmac_clear_CHINTEN_TERR_bit(void *const hw)
{
	((Dmac *)hw)->CHINTENCLR.reg = DMAC_CHINTENCLR_TERR;
}

static inline void hri_dmac_clear_CHINTEN_TCMPL_bit(void *const hw)
{
	((Dmac *)hw)->CHINTENCLR.reg = DMAC_CHINTENCLR_TCMPL;
}

static inline void hri_dmac_clear_CHINTEN_SUSP_bit(void *const hw)
{
	((Dmac *)hw)->CHINTENCLR.reg = DMAC_CHINTENCLR_SUSP;
}

static inline void hri_dmac_set_CHINTEN_TERR_bit(void *const hw)
{
	((Dmac *)hw)->CHINTENSET.reg = DMAC_CHINTENSET_TERR;
}

static inline void hri_dmac_write_CHINTEN_TERR_bit(void *const hw, const bool value)
{
	DMAC_CRITICAL_SECTION_ENTER()

	((Dmac *)hw)->CHINTENCLR.reg = DMAC_CHINTENSET_TERR;
	((Dmac *)hw)->CHINTENSET.reg = value << DMAC_CHINTENSET_TERR_Pos;
	DMAC_CRITICAL_SECTION_LEAVE()
}

static inline bool hri_dmac_get_CHINTEN_TERR_bit(const void *const hw)
{
	return (((const Dmac *)hw)->CHINTENSET.reg & DMAC_CHINTENSET_TERR) >> DMAC_CHINTENSET_TERR_Pos;
}

static inline void hri_dmac_set_CHINTEN_TCMPL_bit(void *const hw)
{
	((Dmac *)hw)->CHINTENSET.reg = DMAC_CHINTENSET_TCMPL;
}

static inline void hri_dmac_write_CHINTEN_TCMPL_bit(void *const hw, const bool value)
{
	DMAC_CRITICAL_SECTION_ENTER()

	((Dmac *)hw)->CHINTENCLR.reg = DMAC_CHINTENSET_TCMPL;
	((Dmac *)hw)->CHINTENSET.reg = value << DMAC_CHINTENSET_TCMPL_Pos;
	DMAC_CRITICAL_SECTION_LEAVE()
}

static inline bool hri_dmac_get_CHINTEN_TCMPL_bit(const void *const hw)
{
	return (((const Dmac *)hw)->CHINTENSET.reg & DMAC_CHINTENSET_TCMPL) >> DMAC_CHINTENSET_TCMPL_Pos;
}

static inline void hri_dmac_set_CHINTEN_SUSP_bit(void *const hw)
{
	((Dmac *)hw)->CHINTENSET.reg = DMAC_CHINTENSET_SUSP;
}

static inline void hri_dmac_write_CHINTEN_SUSP_bit(void *const hw, const bool value)
{
	DMAC_CRITICAL_SECTION_ENTER()

	((Dmac *)hw)->CHINTENCLR.reg = DMAC_CHINTENSET_SUSP;
	((Dmac *)hw)->CHINTENSET.reg = value << DMAC_CHINTENSET_SUSP_Pos;
	DMAC_CRITICAL_SECTION_LEAVE()
}

static inline bool hri_dmac_get_CHINTEN_SUSP_bit(const void *const hw)
{
	return (((const Dmac *)hw)->CHINTENSET.reg & DMAC_CHINTENSET_SUSP) >> DMAC_CHINTENSET_SUSP_Pos;
}

static inline void hri_dmac_clear_interrupt_TERR_bit(void *const hw)
{
	((Dmac *)hw)->CHINTFLAG.reg = DMAC_CHINTFLAG_TERR;
}

static inline bool hri_dmac_get_interrupt_TERR_bit(const void *const hw)
{
	return (((const Dmac *)hw)->CHINTFLAG.reg & DMAC_CHINTFLAG_TERR) >> DMAC_CHINTFLAG_TERR_Pos;
}

static inline void hri_dmac_clear_interrupt_TCMPL_bit(void *const hw)
{
	((Dmac *)hw)->CHINTFLAG.reg = DMAC_CHINTFLAG_TCMPL;
}

static inline bool hri_dmac_get_interrupt_TCMPL_bit(const void *const hw)
{
	return (((const Dmac *)hw)->CHINTFLAG.reg & DMAC_CHINTFLAG_TCMPL) >> DMAC_CHINTFLAG_TCMPL_Pos;
}

static inline void hri_dmac_clear_interrupt_SUSP_bit(void *const hw)
{
	((Dmac *)hw)->CHINTFLAG.reg = DMAC_CHINTFLAG_SUSP;
}

static inline bool hri_dmac_get_interrupt_SUSP_bit(const void *const hw)
{
	return (((const Dmac *)hw)->CHINTFLAG.reg & DMAC_CHINTFLAG_SUSP) >> DMAC_CHINTFLAG_SUSP_Pos;
}

static inline bool hri_dmac_get_CHSTATUS_PEND_bit(const void *const hw)
{
	return (((const Dmac *)hw)->CHSTATUS.reg & DMAC_CHSTATUS_PEND) >> DMAC_CHSTATUS_PEND_Pos;
}

static inline bool hri_dmac_get_CHSTATUS_BUSY_bit(const void *const hw)
{
	return (((const Dmac *)hw)->CHSTATUS.reg & DMAC_CHSTATUS_BUSY) >> DMAC_CHSTATUS_BUSY_Pos;
}

static inline bool hri_dmac_get_CHSTATUS_FERR_bit(const void *const hw)
{
	return (((const Dmac *)hw)->CHSTATUS.reg & DMAC_CHSTATUS_FERR) >> DMAC_CHSTATUS_FERR_Pos;
}


static inline void hri_dmac_set_CRCCTRL_CRCBEATSIZE_bf(void *const hw, const hri_dmac_crcctrl_reg_t mask)
{
	DMAC_CRITICAL_SECTION_ENTER()
	((Dmac *)hw)->CRCCTRL.reg |= DMAC_CRCCTRL_CRCBEATSIZE(mask);
	DMAC_CRITICAL_SECTION_LEAVE()
}

static inline void hri_dmac_write_CRCCTRL_CRCBEATSIZE_bf(void *const hw, const hri_dmac_crcctrl_reg_t data)
{
	uint16_t tmp;

	DMAC_CRITICAL_SECTION_ENTER()
	tmp = ((Dmac *)hw)->CRCCTRL.reg;
	tmp &= ~DMAC_CRCCTRL_CRCBEATSIZE_Msk;
	tmp |= DMAC_CRCCTRL_CRCBEATSIZE(data);
	((Dmac *)hw)->CRCCTRL.reg = tmp;
	DMAC_CRITICAL_SECTION_LEAVE()
}

static inline void hri_dmac_clear_CRCCTRL_CRCBEATSIZE_bf(void *const hw, const hri_dmac_crcctrl_reg_t mask)
{
	DMAC_CRITICAL_SECTION_ENTER()
	((Dmac *)hw)->CRCCTRL.reg &= ~DMAC_CRCCTRL_CRCBEATSIZE(mask);
	DMAC_CRITICAL_SECTION_LEAVE()
}

static inline hri_dmac_crcctrl_reg_t hri_dmac_get_CRCCTRL_CRCBEATSIZE_bf(const void *const hw, const hri_dmac_crcctrl_reg_t mask)
{
	uint16_t tmp;

	DMAC_CRITICAL_SECTION_ENTER()
	tmp = ((const Dmac *)hw)->CRCCTRL.reg;
	tmp = (tmp & DMAC_CRCCTRL_CRCBEATSIZE(mask)) >> DMAC_CRCCTRL_CRCBEATSIZE_Pos;
	DMAC_CRITICAL_SECTION_LEAVE()

	return tmp;
}

static inline hri_dmac_crcctrl_reg_t hri_dmac_read_CRCCTRL_CRCBEATSIZE_bf(const void *const hw)
{
	uint16_t tmp;

	DMAC_CRITICAL_SECTION_ENTER()
	tmp = ((const Dmac *)hw)->CRCCTRL.reg;
	tmp = (tmp & DMAC_CRCCTRL_CRCBEATSIZE_Msk) >> DMAC_CRCCTRL_CRCBEATSIZE_Pos;
	DMAC_CRITICAL_SECTION_LEAVE()

	return tmp;
}

static inline void hri_dmac_toggle_CRCCTRL_CRCBEATSIZE_bf(void *const hw, const hri_dmac_crcctrl_reg_t mask)
{
	DMAC_CRITICAL_SECTION_ENTER()
	((Dmac *)hw)->CRCCTRL.reg ^= DMAC_CRCCTRL_CRCBEATSIZE(mask);

	DMAC_CRITICAL_SECTION_LEAVE()
}

static inline void hri_dmac_set_CRCCTRL_CRCPOLY_bf(void *const hw, const hri_dmac_crcctrl_reg_t mask)
{
	DMAC_CRITICAL_SECTION_ENTER()
	((Dmac *)hw)->CRCCTRL.reg |= DMAC_CRCCTRL_CRCPOLY(mask);
	DMAC_CRITICAL_SECTION_LEAVE()
}

static inline void hri_dmac_write_CRCCTRL_CRCPOLY_bf(void *const hw, const hri_dmac_crcctrl_reg_t data)
{
	uint16_t tmp;

	DMAC_CRITICAL_SECTION_ENTER()
	tmp = ((Dmac *)hw)->CRCCTRL.reg;
	tmp &= ~DMAC_CRCCTRL_CRCPOLY_Msk;
	tmp |= DMAC_CRCCTRL_CRCPOLY(data);
	((Dmac *)hw)->CRCCTRL.reg = tmp;
	DMAC_CRITICAL_SECTION_LEAVE()
}

static inline void hri_dmac_clear_CRCCTRL_CRCPOLY_bf(void *const hw, const hri_dmac_crcctrl_reg_t mask)
{
	DMAC_CRITICAL_SECTION_ENTER()
	((Dmac *)hw)->CRCCTRL.reg &= ~DMAC_CRCCTRL_CRCPOLY(mask);
	DMAC_CRITICAL_SECTION_LEAVE()
}

static inline hri_dmac_crcctrl_reg_t hri_dmac_get_CRCCTRL_CRCPOLY_bf(const void *const hw, const hri_dmac_crcctrl_reg_t mask)
{
	uint16_t tmp;

	DMAC_CRITICAL_SECTION_ENTER()
	tmp = ((const Dmac *)hw)->CRCCTRL.reg;
	tmp = (tmp & DMAC_CRCCTRL_CRCPOLY(mask)) >> DMAC_CRCCTRL_CRCPOLY_Pos;
	DMAC_CRITICAL_SECTION_LEAVE()

	return tmp;
}

static inline hri_dmac_crcctrl_reg_t hri_dmac_read_CRCCTRL_CRCPOLY_bf(const void *const hw)
{
	uint16_t tmp;

	DMAC_CRITICAL_SECTION_ENTER()
	tmp = ((const Dmac *)hw)->CRCCTRL.reg;
	tmp = (tmp & DMAC_CRCCTRL_CRCPOLY_Msk) >> DMAC_CRCCTRL_CRCPOLY_Pos;
	DMAC_CRITICAL_SECTION_LEAVE()

	return tmp;
}

static inline void hri_dmac_toggle_CRCCTRL_CRCPOLY_bf(void *const hw, const hri_dmac_crcctrl_reg_t mask)
{
	DMAC_CRITICAL_SECTION_ENTER()
	((Dmac *)hw)->CRCCTRL.reg ^= DMAC_CRCCTRL_CRCPOLY(mask);

	DMAC_CRITICAL_SECTION_LEAVE()
}

static inline void hri_dmac_set_CRCCTRL_CRCSRC_bf(void *const hw, const hri_dmac_crcctrl_reg_t mask)
{
	DMAC_CRITICAL_SECTION_ENTER()
	((Dmac *)hw)->CRCCTRL.reg |= DMAC_CRCCTRL_CRCSRC(mask);
	DMAC_CRITICAL_SECTION_LEAVE()
}

static inline void hri_dmac_write_CRCCTRL_CRCSRC_bf(void *const hw, const hri_dmac_crcctrl_reg_t data)
{
	uint16_t tmp;

	DMAC_CRITICAL_SECTION_ENTER()
	tmp = ((Dmac *)hw)->CRCCTRL.reg;
	tmp &= ~DMAC_CRCCTRL_CRCSRC_Msk;
	tmp |= DMAC_CRCCTRL_CRCSRC(data);
	((Dmac *)hw)->CRCCTRL.reg = tmp;
	DMAC_CRITICAL_SECTION_LEAVE()
}

static inline void hri_dmac_clear_CRCCTRL_CRCSRC_bf(void *const hw, const hri_dmac_crcctrl_reg_t mask)
{
	DMAC_CRITICAL_SECTION_ENTER()
	((Dmac *)hw)->CRCCTRL.reg &= ~DMAC_CRCCTRL_CRCSRC(mask);
	DMAC_CRITICAL_SECTION_LEAVE()
}

static inline hri_dmac_crcctrl_reg_t hri_dmac_get_CRCCTRL_CRCSRC_bf(const void *const hw, const hri_dmac_crcctrl_reg_t mask)
{
	uint16_t tmp;

	DMAC_CRITICAL_SECTION_ENTER()
	tmp = ((const Dmac *)hw)->CRCCTRL.reg;
	tmp = (tmp & DMAC_CRCCTRL_CRCSRC(mask)) >> DMAC_CRCCTRL_CRCSRC_Pos;
	DMAC_CRITICAL_SECTION_LEAVE()

	return tmp;
}

static inline hri_dmac_crcctrl_reg_t hri_dmac_read_CRCCTRL_CRCSRC_bf(const void *const hw)
{
	uint16_t tmp;

	DMAC_CRITICAL_SECTION_ENTER()
	tmp = ((const Dmac *)hw)->CRCCTRL.reg;
	tmp = (tmp & DMAC_CRCCTRL_CRCSRC_Msk) >> DMAC_CRCCTRL_CRCSRC_Pos;
	DMAC_CRITICAL_SECTION_LEAVE()

	return tmp;
}

static inline void hri_dmac_toggle_CRCCTRL_CRCSRC_bf(void *const hw, const hri_dmac_crcctrl_reg_t mask)
{
	DMAC_CRITICAL_SECTION_ENTER()
	((Dmac *)hw)->CRCCTRL.reg ^= DMAC_CRCCTRL_CRCSRC(mask);

	DMAC_CRITICAL_SECTION_LEAVE()
}

static inline void hri_dmac_set_CRCDATAIN_CRCDATAIN_bf(void *const hw, const hri_dmac_crcdatain_reg_t mask)
{
	DMAC_CRITICAL_SECTION_ENTER()
	((Dmac *)hw)->CRCDATAIN.reg |= DMAC_CRCDATAIN_CRCDATAIN(mask);
	DMAC_CRITICAL_SECTION_LEAVE()
}

static inline void hri_dmac_write_CRCDATAIN_CRCDATAIN_bf(void *const hw, const hri_dmac_crcdatain_reg_t data)
{
	uint32_t tmp;

	DMAC_CRITICAL_SECTION_ENTER()
	tmp = ((Dmac *)hw)->CRCDATAIN.reg;
	tmp &= ~DMAC_CRCDATAIN_CRCDATAIN_Msk;
	tmp |= DMAC_CRCDATAIN_CRCDATAIN(data);
	((Dmac *)hw)->CRCDATAIN.reg = tmp;
	DMAC_CRITICAL_SECTION_LEAVE()
}

static inline void hri_dmac_clear_CRCDATAIN_CRCDATAIN_bf(void *const hw, const hri_dmac_crcdatain_reg_t mask)
{
	DMAC_CRITICAL_SECTION_ENTER()
	((Dmac *)hw)->CRCDATAIN.reg &= ~DMAC_CRCDATAIN_CRCDATAIN(mask);
	DMAC_CRITICAL_SECTION_LEAVE()
}

static inline hri_dmac_crcdatain_reg_t hri_dmac_get_CRCDATAIN_CRCDATAIN_bf(const void *const hw, const hri_dmac_crcdatain_reg_t mask)
{
	uint32_t tmp;

	DMAC_CRITICAL_SECTION_ENTER()
	tmp = ((const Dmac *)hw)->CRCDATAIN.reg;
	tmp = (tmp & DMAC_CRCDATAIN_CRCDATAIN(mask)) >> DMAC_CRCDATAIN_CRCDATAIN_Pos;
	DMAC_CRITICAL_SECTION_LEAVE()

	return tmp;
}

static inline hri_dmac_crcdatain_reg_t hri_dmac_read_CRCDATAIN_CRCDATAIN_bf(const void *const hw)
{
	uint32_t tmp;

	DMAC_CRITICAL_SECTION_ENTER()
	tmp = ((const Dmac *)hw)->CRCDATAIN.reg;
	tmp = (tmp & DMAC_CRCDATAIN_CRCDATAIN_Msk) >> DMAC_CRCDATAIN_CRCDATAIN_Pos;
	DMAC_CRITICAL_SECTION_LEAVE()

	return tmp;
}

static inline void hri_dmac_toggle_CRCDATAIN_CRCDATAIN_bf(void *const hw, const hri_dmac_crcdatain_reg_t mask)
{
	DMAC_CRITICAL_SECTION_ENTER()
	((Dmac *)hw)->CRCDATAIN.reg ^= DMAC_CRCDATAIN_CRCDATAIN(mask);

	DMAC_CRITICAL_SECTION_LEAVE()
}

static inline void hri_dmac_set_CRCCHKSUM_CRCCHKSUM_bf(void *const hw, const hri_dmac_crcchksum_reg_t mask)
{
	DMAC_CRITICAL_SECTION_ENTER()
	((Dmac *)hw)->CRCCHKSUM.reg |= DMAC_CRCCHKSUM_CRCCHKSUM(mask);
	DMAC_CRITICAL_SECTION_LEAVE()
}

static inline void hri_dmac_write_CRCCHKSUM_CRCCHKSUM_bf(void *const hw, const hri_dmac_crcchksum_reg_t data)
{
	uint32_t tmp;

	DMAC_CRITICAL_SECTION_ENTER()
	tmp = ((Dmac *)hw)->CRCCHKSUM.reg;
	tmp &= ~DMAC_CRCCHKSUM_CRCCHKSUM_Msk;
	tmp |= DMAC_CRCCHKSUM_CRCCHKSUM(data);
	((Dmac *)hw)->CRCCHKSUM.reg = tmp;
	DMAC_CRITICAL_SECTION_LEAVE()
}

static inline void hri_dmac_clear_CRCCHKSUM_CRCCHKSUM_bf(void *const hw, const hri_dmac_crcchksum_reg_t mask)
{
	DMAC_CRITICAL_SECTION_ENTER()
	((Dmac *)hw)->CRCCHKSUM.reg &= ~DMAC_CRCCHKSUM_CRCCHKSUM(mask);
	DMAC_CRITICAL_SECTION_LEAVE()
}

static inline hri_dmac_crcchksum_reg_t hri_dmac_get_CRCCHKSUM_CRCCHKSUM_bf(const void *const hw, const hri_dmac_crcchksum_reg_t mask)
{
	uint32_t tmp;

	DMAC_CRITICAL_SECTION_ENTER()
	tmp = ((const Dmac *)hw)->CRCCHKSUM.reg;
	tmp = (tmp & DMAC_CRCCHKSUM_CRCCHKSUM(mask)) >> DMAC_CRCCHKSUM_CRCCHKSUM_Pos;
	DMAC_CRITICAL_SECTION_LEAVE()

	return tmp;
}

static inline hri_dmac_crcchksum_reg_t hri_dmac_read_CRCCHKSUM_CRCCHKSUM_bf(const void *const hw)
{
	uint32_t tmp;

	DMAC_CRITICAL_SECTION_ENTER()
	tmp = ((const Dmac *)hw)->CRCCHKSUM.reg;
	tmp = (tmp & DMAC_CRCCHKSUM_CRCCHKSUM_Msk) >> DMAC_CRCCHKSUM_CRCCHKSUM_Pos;
	DMAC_CRITICAL_SECTION_LEAVE()

	return tmp;
}

static inline void hri_dmac_toggle_CRCCHKSUM_CRCCHKSUM_bf(void *const hw, const hri_dmac_crcchksum_reg_t mask)
{
	DMAC_CRITICAL_SECTION_ENTER()
	((Dmac *)hw)->CRCCHKSUM.reg ^= DMAC_CRCCHKSUM_CRCCHKSUM(mask);

	DMAC_CRITICAL_SECTION_LEAVE()
}

static inline void hri_dmac_set_PRICTRL0_LVLPRI0_bf(void *const hw, const hri_dmac_prictrl0_reg_t mask)
{
	DMAC_CRITICAL_SECTION_ENTER()
	((Dmac *)hw)->PRICTRL0.reg |= DMAC_PRICTRL0_LVLPRI0(mask);
	DMAC_CRITICAL_SECTION_LEAVE()
}

static inline void hri_dmac_write_PRICTRL0_LVLPRI0_bf(void *const hw, const hri_dmac_prictrl0_reg_t data)
{
	uint32_t tmp;

	DMAC_CRITICAL_SECTION_ENTER()
	tmp = ((Dmac *)hw)->PRICTRL0.reg;
	tmp &= ~DMAC_PRICTRL0_LVLPRI0_Msk;
	tmp |= DMAC_PRICTRL0_LVLPRI0(data);
	((Dmac *)hw)->PRICTRL0.reg = tmp;
	DMAC_CRITICAL_SECTION_LEAVE()
}

static inline void hri_dmac_clear_PRICTRL0_LVLPRI0_bf(void *const hw, const hri_dmac_prictrl0_reg_t mask)
{
	DMAC_CRITICAL_SECTION_ENTER()
	((Dmac *)hw)->PRICTRL0.reg &= ~DMAC_PRICTRL0_LVLPRI0(mask);
	DMAC_CRITICAL_SECTION_LEAVE()
}

static inline hri_dmac_prictrl0_reg_t hri_dmac_get_PRICTRL0_LVLPRI0_bf(const void *const hw, const hri_dmac_prictrl0_reg_t mask)
{
	uint32_t tmp;

	DMAC_CRITICAL_SECTION_ENTER()
	tmp = ((const Dmac *)hw)->PRICTRL0.reg;
	tmp = (tmp & DMAC_PRICTRL0_LVLPRI0(mask)) >> DMAC_PRICTRL0_LVLPRI0_Pos;
	DMAC_CRITICAL_SECTION_LEAVE()

	return tmp;
}

static inline hri_dmac_prictrl0_reg_t hri_dmac_read_PRICTRL0_LVLPRI0_bf(const void *const hw)
{
	uint32_t tmp;

	DMAC_CRITICAL_SECTION_ENTER()
	tmp = ((const Dmac *)hw)->PRICTRL0.reg;
	tmp = (tmp & DMAC_PRICTRL0_LVLPRI0_Msk) >> DMAC_PRICTRL0_LVLPRI0_Pos;
	DMAC_CRITICAL_SECTION_LEAVE()

	return tmp;
}

static inline void hri_dmac_toggle_PRICTRL0_LVLPRI0_bf(void *const hw, const hri_dmac_prictrl0_reg_t mask)
{
	DMAC_CRITICAL_SECTION_ENTER()
	((Dmac *)hw)->PRICTRL0.reg ^= DMAC_PRICTRL0_LVLPRI0(mask);

	DMAC_CRITICAL_SECTION_LEAVE()
}

static inline void hri_dmac_set_PRICTRL0_LVLPRI1_bf(void *const hw, const hri_dmac_prictrl0_reg_t mask)
{
	DMAC_CRITICAL_SECTION_ENTER()
	((Dmac *)hw)->PRICTRL0.reg |= DMAC_PRICTRL0_LVLPRI1(mask);
	DMAC_CRITICAL_SECTION_LEAVE()
}

static inline void hri_dmac_write_PRICTRL0_LVLPRI1_bf(void *const hw, const hri_dmac_prictrl0_reg_t data)
{
	uint32_t tmp;

	DMAC_CRITICAL_SECTION_ENTER()
	tmp = ((Dmac *)hw)->PRICTRL0.reg;
	tmp &= ~DMAC_PRICTRL0_LVLPRI1_Msk;
	tmp |= DMAC_PRICTRL0_LVLPRI1(data);
	((Dmac *)hw)->PRICTRL0.reg = tmp;
	DMAC_CRITICAL_SECTION_LEAVE()
}

static inline void hri_dmac_clear_PRICTRL0_LVLPRI1_bf(void *const hw, const hri_dmac_prictrl0_reg_t mask)
{
	DMAC_CRITICAL_SECTION_ENTER()
	((Dmac *)hw)->PRICTRL0.reg &= ~DMAC_PRICTRL0_LVLPRI1(mask);
	DMAC_CRITICAL_SECTION_LEAVE()
}

static inline hri_dmac_prictrl0_reg_t hri_dmac_get_PRICTRL0_LVLPRI1_bf(const void *const hw, const hri_dmac_prictrl0_reg_t mask)
{
	uint32_t tmp;

	DMAC_CRITICAL_SECTION_ENTER()
	tmp = ((const Dmac *)hw)->PRICTRL0.reg;
	tmp = (tmp & DMAC_PRICTRL0_LVLPRI1(mask)) >> DMAC_PRICTRL0_LVLPRI1_Pos;
	DMAC_CRITICAL_SECTION_LEAVE()

	return tmp;
}

static inline hri_dmac_prictrl0_reg_t hri_dmac_read_PRICTRL0_LVLPRI1_bf(const void *const hw)
{
	uint32_t tmp;

	DMAC_CRITICAL_SECTION_ENTER()
	tmp = ((const Dmac *)hw)->PRICTRL0.reg;
	tmp = (tmp & DMAC_PRICTRL0_LVLPRI1_Msk) >> DMAC_PRICTRL0_LVLPRI1_Pos;
	DMAC_CRITICAL_SECTION_LEAVE()

	return tmp;
}

static inline void hri_dmac_toggle_PRICTRL0_LVLPRI1_bf(void *const hw, const hri_dmac_prictrl0_reg_t mask)
{
	DMAC_CRITICAL_SECTION_ENTER()
	((Dmac *)hw)->PRICTRL0.reg ^= DMAC_PRICTRL0_LVLPRI1(mask);

	DMAC_CRITICAL_SECTION_LEAVE()
}

static inline void hri_dmac_set_PRICTRL0_LVLPRI2_bf(void *const hw, const hri_dmac_prictrl0_reg_t mask)
{
	DMAC_CRITICAL_SECTION_ENTER()
	((Dmac *)hw)->PRICTRL0.reg |= DMAC_PRICTRL0_LVLPRI2(mask);
	DMAC_CRITICAL_SECTION_LEAVE()
}

static inline void hri_dmac_write_PRICTRL0_LVLPRI2_bf(void *const hw, const hri_dmac_prictrl0_reg_t data)
{
	uint32_t tmp;

	DMAC_CRITICAL_SECTION_ENTER()
	tmp = ((Dmac *)hw)->PRICTRL0.reg;
	tmp &= ~DMAC_PRICTRL0_LVLPRI2_Msk;
	tmp |= DMAC_PRICTRL0_LVLPRI2(data);
	((Dmac *)hw)->PRICTRL0.reg = tmp;
	DMAC_CRITICAL_SECTION_LEAVE()
}

static inline void hri_dmac_clear_PRICTRL0_LVLPRI2_bf(void *const hw, const hri_dmac_prictrl0_reg_t mask)
{
	DMAC_CRITICAL_SECTION_ENTER()
	((Dmac *)hw)->PRICTRL0.reg &= ~DMAC_PRICTRL0_LVLPRI2(mask);
	DMAC_CRITICAL_SECTION_LEAVE()
}

static inline hri_dmac_prictrl0_reg_t hri_dmac_get_PRICTRL0_LVLPRI2_bf(const void *const hw, const hri_dmac_prictrl0_reg_t mask)
{
	uint32_t tmp;

	DMAC_CRITICAL_SECTION_ENTER()
	tmp = ((const Dmac *)hw)->PRICTRL0.reg;
	tmp = (tmp & DMAC_PRICTRL0_LVLPRI2(mask)) >> DMAC_PRICTRL0_LVLPRI2_Pos;
	DMAC_CRITICAL_SECTION_LEAVE()

	return tmp;
}

static inline hri_dmac_prictrl0_reg_t hri_dmac_read_PRICTRL0_LVLPRI2_bf(const void *const hw)
{
	uint32_t tmp;

	DMAC_CRITICAL_SECTION_ENTER()
	tmp = ((const Dmac *)hw)->PRICTRL0.reg;
	tmp = (tmp & DMAC_PRICTRL0_LVLPRI2_Msk) >> DMAC_PRICTRL0_LVLPRI2_Pos;
	DMAC_CRITICAL_SECTION_LEAVE()

	return tmp;
}

static inline void hri_dmac_toggle_PRICTRL0_LVLPRI2_bf(void *const hw, const hri_dmac_prictrl0_reg_t mask)
{
	DMAC_CRITICAL_SECTION_ENTER()
	((Dmac *)hw)->PRICTRL0.reg ^= DMAC_PRICTRL0_LVLPRI2(mask);

	DMAC_CRITICAL_SECTION_LEAVE()
}

static inline void hri_dmac_set_PRICTRL0_LVLPRI3_bf(void *const hw, const hri_dmac_prictrl0_reg_t mask)
{
	DMAC_CRITICAL_SECTION_ENTER()
	((Dmac *)hw)->PRICTRL0.reg |= DMAC_PRICTRL0_LVLPRI3(mask);
	DMAC_CRITICAL_SECTION_LEAVE()
}

static inline void hri_dmac_write_PRICTRL0_LVLPRI3_bf(void *const hw, const hri_dmac_prictrl0_reg_t data)
{
	uint32_t tmp;

	DMAC_CRITICAL_SECTION_ENTER()
	tmp = ((Dmac *)hw)->PRICTRL0.reg;
	tmp &= ~DMAC_PRICTRL0_LVLPRI3_Msk;
	tmp |= DMAC_PRICTRL0_LVLPRI3(data);
	((Dmac *)hw)->PRICTRL0.reg = tmp;
	DMAC_CRITICAL_SECTION_LEAVE()
}

static inline void hri_dmac_clear_PRICTRL0_LVLPRI3_bf(void *const hw, const hri_dmac_prictrl0_reg_t mask)
{
	DMAC_CRITICAL_SECTION_ENTER()
	((Dmac *)hw)->PRICTRL0.reg &= ~DMAC_PRICTRL0_LVLPRI3(mask);
	DMAC_CRITICAL_SECTION_LEAVE()
}

static inline hri_dmac_prictrl0_reg_t hri_dmac_get_PRICTRL0_LVLPRI3_bf(const void *const hw, const hri_dmac_prictrl0_reg_t mask)
{
	uint32_t tmp;

	DMAC_CRITICAL_SECTION_ENTER()
	tmp = ((const Dmac *)hw)->PRICTRL0.reg;
	tmp = (tmp & DMAC_PRICTRL0_LVLPRI3(mask)) >> DMAC_PRICTRL0_LVLPRI3_Pos;
	DMAC_CRITICAL_SECTION_LEAVE()

	return tmp;
}

static inline hri_dmac_prictrl0_reg_t hri_dmac_read_PRICTRL0_LVLPRI3_bf(const void *const hw)
{
	uint32_t tmp;

	DMAC_CRITICAL_SECTION_ENTER()
	tmp = ((const Dmac *)hw)->PRICTRL0.reg;
	tmp = (tmp & DMAC_PRICTRL0_LVLPRI3_Msk) >> DMAC_PRICTRL0_LVLPRI3_Pos;
	DMAC_CRITICAL_SECTION_LEAVE()

	return tmp;
}

static inline void hri_dmac_toggle_PRICTRL0_LVLPRI3_bf(void *const hw, const hri_dmac_prictrl0_reg_t mask)
{
	DMAC_CRITICAL_SECTION_ENTER()
	((Dmac *)hw)->PRICTRL0.reg ^= DMAC_PRICTRL0_LVLPRI3(mask);

	DMAC_CRITICAL_SECTION_LEAVE()
}

static inline void hri_dmac_set_INTPEND_ID_bf(void *const hw, const hri_dmac_intpend_reg_t mask)
{
	DMAC_CRITICAL_SECTION_ENTER()
	((Dmac *)hw)->INTPEND.reg |= DMAC_INTPEND_ID(mask);
	DMAC_CRITICAL_SECTION_LEAVE()
}

static inline void hri_dmac_write_INTPEND_ID_bf(void *const hw, const hri_dmac_intpend_reg_t data)
{
	uint16_t tmp;

	DMAC_CRITICAL_SECTION_ENTER()
	tmp = ((Dmac *)hw)->INTPEND.reg;
	tmp &= ~DMAC_INTPEND_ID_Msk;
	tmp |= DMAC_INTPEND_ID(data);
	((Dmac *)hw)->INTPEND.reg = tmp;
	DMAC_CRITICAL_SECTION_LEAVE()
}

static inline void hri_dmac_clear_INTPEND_ID_bf(void *const hw, const hri_dmac_intpend_reg_t mask)
{
	DMAC_CRITICAL_SECTION_ENTER()
	((Dmac *)hw)->INTPEND.reg &= ~DMAC_INTPEND_ID(mask);
	DMAC_CRITICAL_SECTION_LEAVE()
}

static inline hri_dmac_intpend_reg_t hri_dmac_get_INTPEND_ID_bf(const void *const hw, const hri_dmac_intpend_reg_t mask)
{
	uint16_t tmp;

	DMAC_CRITICAL_SECTION_ENTER()
	tmp = ((const Dmac *)hw)->INTPEND.reg;
	tmp = (tmp & DMAC_INTPEND_ID(mask)) >> DMAC_INTPEND_ID_Pos;
	DMAC_CRITICAL_SECTION_LEAVE()

	return tmp;
}

static inline hri_dmac_intpend_reg_t hri_dmac_read_INTPEND_ID_bf(const void *const hw)
{
	uint16_t tmp;

	DMAC_CRITICAL_SECTION_ENTER()
	tmp = ((const Dmac *)hw)->INTPEND.reg;
	tmp = (tmp & DMAC_INTPEND_ID_Msk) >> DMAC_INTPEND_ID_Pos;
	DMAC_CRITICAL_SECTION_LEAVE()

	return tmp;
}

static inline void hri_dmac_toggle_INTPEND_ID_bf(void *const hw, const hri_dmac_intpend_reg_t mask)
{
	DMAC_CRITICAL_SECTION_ENTER()
	((Dmac *)hw)->INTPEND.reg ^= DMAC_INTPEND_ID(mask);

	DMAC_CRITICAL_SECTION_LEAVE()
}

static inline hri_dmac_active_reg_t hri_dmac_get_ACTIVE_ID_bf(const void *const hw, const hri_dmac_active_reg_t mask)
{
	uint32_t tmp;

	DMAC_CRITICAL_SECTION_ENTER()
	tmp = ((const Dmac *)hw)->ACTIVE.reg;
	tmp = (tmp & DMAC_ACTIVE_ID(mask)) >> DMAC_ACTIVE_ID_Pos;
	DMAC_CRITICAL_SECTION_LEAVE()

	return tmp;
}

static inline hri_dmac_active_reg_t hri_dmac_read_ACTIVE_ID_bf(const void *const hw)
{
	uint32_t tmp;

	DMAC_CRITICAL_SECTION_ENTER()
	tmp = ((const Dmac *)hw)->ACTIVE.reg;
	tmp = (tmp & DMAC_ACTIVE_ID_Msk) >> DMAC_ACTIVE_ID_Pos;
	DMAC_CRITICAL_SECTION_LEAVE()

	return tmp;
}

static inline hri_dmac_active_reg_t hri_dmac_get_ACTIVE_BTCNT_bf(const void *const hw, const hri_dmac_active_reg_t mask)
{
	uint32_t tmp;

	DMAC_CRITICAL_SECTION_ENTER()
	tmp = ((const Dmac *)hw)->ACTIVE.reg;
	tmp = (tmp & DMAC_ACTIVE_BTCNT(mask)) >> DMAC_ACTIVE_BTCNT_Pos;
	DMAC_CRITICAL_SECTION_LEAVE()

	return tmp;
}

static inline hri_dmac_active_reg_t hri_dmac_read_ACTIVE_BTCNT_bf(const void *const hw)
{
	uint32_t tmp;

	DMAC_CRITICAL_SECTION_ENTER()
	tmp = ((const Dmac *)hw)->ACTIVE.reg;
	tmp = (tmp & DMAC_ACTIVE_BTCNT_Msk) >> DMAC_ACTIVE_BTCNT_Pos;
	DMAC_CRITICAL_SECTION_LEAVE()

	return tmp;
}

static inline void hri_dmac_set_BASEADDR_BASEADDR_bf(void *const hw, const hri_dmac_baseaddr_reg_t mask)
{
	DMAC_CRITICAL_SECTION_ENTER()
	((Dmac *)hw)->BASEADDR.reg |= DMAC_BASEADDR_BASEADDR(mask);
	DMAC_CRITICAL_SECTION_LEAVE()
}

static inline void hri_dmac_write_BASEADDR_BASEADDR_bf(void *const hw, const hri_dmac_baseaddr_reg_t data)
{
	uint32_t tmp;

	DMAC_CRITICAL_SECTION_ENTER()
	tmp = ((Dmac *)hw)->BASEADDR.reg;
	tmp &= ~DMAC_BASEADDR_BASEADDR_Msk;
	tmp |= DMAC_BASEADDR_BASEADDR(data);
	((Dmac *)hw)->BASEADDR.reg = tmp;
	DMAC_CRITICAL_SECTION_LEAVE()
}

static inline void hri_dmac_clear_BASEADDR_BASEADDR_bf(void *const hw, const hri_dmac_baseaddr_reg_t mask)
{
	DMAC_CRITICAL_SECTION_ENTER()
	((Dmac *)hw)->BASEADDR.reg &= ~DMAC_BASEADDR_BASEADDR(mask);
	DMAC_CRITICAL_SECTION_LEAVE()
}

static inline hri_dmac_baseaddr_reg_t hri_dmac_get_BASEADDR_BASEADDR_bf(const void *const hw, const hri_dmac_baseaddr_reg_t mask)
{
	uint32_t tmp;

	DMAC_CRITICAL_SECTION_ENTER()
	tmp = ((const Dmac *)hw)->BASEADDR.reg;
	tmp = (tmp & DMAC_BASEADDR_BASEADDR(mask)) >> DMAC_BASEADDR_BASEADDR_Pos;
	DMAC_CRITICAL_SECTION_LEAVE()

	return tmp;
}

static inline hri_dmac_baseaddr_reg_t hri_dmac_read_BASEADDR_BASEADDR_bf(const void *const hw)
{
	uint32_t tmp;

	DMAC_CRITICAL_SECTION_ENTER()
	tmp = ((const Dmac *)hw)->BASEADDR.reg;
	tmp = (tmp & DMAC_BASEADDR_BASEADDR_Msk) >> DMAC_BASEADDR_BASEADDR_Pos;
	DMAC_CRITICAL_SECTION_LEAVE()

	return tmp;
}

static inline void hri_dmac_toggle_BASEADDR_BASEADDR_bf(void *const hw, const hri_dmac_baseaddr_reg_t mask)
{
	DMAC_CRITICAL_SECTION_ENTER()
	((Dmac *)hw)->BASEADDR.reg ^= DMAC_BASEADDR_BASEADDR(mask);

	DMAC_CRITICAL_SECTION_LEAVE()
}

static inline void hri_dmac_set_WRBADDR_WRBADDR_bf(void *const hw, const hri_dmac_wrbaddr_reg_t mask)
{
	DMAC_CRITICAL_SECTION_ENTER()
	((Dmac *)hw)->WRBADDR.reg |= DMAC_WRBADDR_WRBADDR(mask);
	DMAC_CRITICAL_SECTION_LEAVE()
}

static inline void hri_dmac_write_WRBADDR_WRBADDR_bf(void *const hw, const hri_dmac_wrbaddr_reg_t data)
{
	uint32_t tmp;

	DMAC_CRITICAL_SECTION_ENTER()
	tmp = ((Dmac *)hw)->WRBADDR.reg;
	tmp &= ~DMAC_WRBADDR_WRBADDR_Msk;
	tmp |= DMAC_WRBADDR_WRBADDR(data);
	((Dmac *)hw)->WRBADDR.reg = tmp;
	DMAC_CRITICAL_SECTION_LEAVE()
}

static inline void hri_dmac_clear_WRBADDR_WRBADDR_bf(void *const hw, const hri_dmac_wrbaddr_reg_t mask)
{
	DMAC_CRITICAL_SECTION_ENTER()
	((Dmac *)hw)->WRBADDR.reg &= ~DMAC_WRBADDR_WRBADDR(mask);
	DMAC_CRITICAL_SECTION_LEAVE()
}

static inline hri_dmac_wrbaddr_reg_t hri_dmac_get_WRBADDR_WRBADDR_bf(const void *const hw, const hri_dmac_wrbaddr_reg_t mask)
{
	uint32_t tmp;

	DMAC_CRITICAL_SECTION_ENTER()
	tmp = ((const Dmac *)hw)->WRBADDR.reg;
	tmp = (tmp & DMAC_WRBADDR_WRBADDR(mask)) >> DMAC_WRBADDR_WRBADDR_Pos;
	DMAC_CRITICAL_SECTION_LEAVE()

	return tmp;
}

static inline hri_dmac_wrbaddr_reg_t hri_dmac_read_WRBADDR_WRBADDR_bf(const void *const hw)
{
	uint32_t tmp;

	DMAC_CRITICAL_SECTION_ENTER()
	tmp = ((const Dmac *)hw)->WRBADDR.reg;
	tmp = (tmp & DMAC_WRBADDR_WRBADDR_Msk) >> DMAC_WRBADDR_WRBADDR_Pos;
	DMAC_CRITICAL_SECTION_LEAVE()

	return tmp;
}

static inline void hri_dmac_toggle_WRBADDR_WRBADDR_bf(void *const hw, const hri_dmac_wrbaddr_reg_t mask)
{
	DMAC_CRITICAL_SECTION_ENTER()
	((Dmac *)hw)->WRBADDR.reg ^= DMAC_WRBADDR_WRBADDR(mask);

	DMAC_CRITICAL_SECTION_LEAVE()
}

static inline void hri_dmac_set_CHID_ID_bf(void *const hw, const hri_dmac_chid_reg_t mask)
{
	DMAC_CRITICAL_SECTION_ENTER()
	((Dmac *)hw)->CHID.reg |= DMAC_CHID_ID(mask);
	DMAC_CRITICAL_SECTION_LEAVE()
}

static inline void hri_dmac_write_CHID_ID_bf(void *const hw, const hri_dmac_chid_reg_t data)
{
	uint8_t tmp;

	DMAC_CRITICAL_SECTION_ENTER()
	tmp = ((Dmac *)hw)->CHID.reg;
	tmp &= ~DMAC_CHID_ID_Msk;
	tmp |= DMAC_CHID_ID(data);
	((Dmac *)hw)->CHID.reg = tmp;
	DMAC_CRITICAL_SECTION_LEAVE()
}

static inline void hri_dmac_clear_CHID_ID_bf(void *const hw, const hri_dmac_chid_reg_t mask)
{
	DMAC_CRITICAL_SECTION_ENTER()
	((Dmac *)hw)->CHID.reg &= ~DMAC_CHID_ID(mask);
	DMAC_CRITICAL_SECTION_LEAVE()
}

static inline hri_dmac_chid_reg_t hri_dmac_get_CHID_ID_bf(const void *const hw, const hri_dmac_chid_reg_t mask)
{
	uint8_t tmp;

	DMAC_CRITICAL_SECTION_ENTER()
	tmp = ((const Dmac *)hw)->CHID.reg;
	tmp = (tmp & DMAC_CHID_ID(mask)) >> DMAC_CHID_ID_Pos;
	DMAC_CRITICAL_SECTION_LEAVE()

	return tmp;
}

static inline hri_dmac_chid_reg_t hri_dmac_read_CHID_ID_bf(const void *const hw)
{
	uint8_t tmp;

	DMAC_CRITICAL_SECTION_ENTER()
	tmp = ((const Dmac *)hw)->CHID.reg;
	tmp = (tmp & DMAC_CHID_ID_Msk) >> DMAC_CHID_ID_Pos;
	DMAC_CRITICAL_SECTION_LEAVE()

	return tmp;
}

static inline void hri_dmac_toggle_CHID_ID_bf(void *const hw, const hri_dmac_chid_reg_t mask)
{
	DMAC_CRITICAL_SECTION_ENTER()
	((Dmac *)hw)->CHID.reg ^= DMAC_CHID_ID(mask);

	DMAC_CRITICAL_SECTION_LEAVE()
}

static inline void hri_dmac_set_CHCTRLB_EVACT_bf(void *const hw, const hri_dmac_chctrlb_reg_t mask)
{
	DMAC_CRITICAL_SECTION_ENTER()
	((Dmac *)hw)->CHCTRLB.reg |= DMAC_CHCTRLB_EVACT(mask);
	DMAC_CRITICAL_SECTION_LEAVE()
}

static inline void hri_dmac_write_CHCTRLB_EVACT_bf(void *const hw, const hri_dmac_chctrlb_reg_t data)
{
	uint32_t tmp;

	DMAC_CRITICAL_SECTION_ENTER()
	tmp = ((Dmac *)hw)->CHCTRLB.reg;
	tmp &= ~DMAC_CHCTRLB_EVACT_Msk;
	tmp |= DMAC_CHCTRLB_EVACT(data);
	((Dmac *)hw)->CHCTRLB.reg = tmp;
	DMAC_CRITICAL_SECTION_LEAVE()
}

static inline void hri_dmac_clear_CHCTRLB_EVACT_bf(void *const hw, const hri_dmac_chctrlb_reg_t mask)
{
	DMAC_CRITICAL_SECTION_ENTER()
	((Dmac *)hw)->CHCTRLB.reg &= ~DMAC_CHCTRLB_EVACT(mask);
	DMAC_CRITICAL_SECTION_LEAVE()
}

static inline hri_dmac_chctrlb_reg_t hri_dmac_get_CHCTRLB_EVACT_bf(const void *const hw, const hri_dmac_chctrlb_reg_t mask)
{
	uint32_t tmp;

	DMAC_CRITICAL_SECTION_ENTER()
	tmp = ((const Dmac *)hw)->CHCTRLB.reg;
	tmp = (tmp & DMAC_CHCTRLB_EVACT(mask)) >> DMAC_CHCTRLB_EVACT_Pos;
	DMAC_CRITICAL_SECTION_LEAVE()

	return tmp;
}

static inline hri_dmac_chctrlb_reg_t hri_dmac_read_CHCTRLB_EVACT_bf(const void *const hw)
{
	uint32_t tmp;

	DMAC_CRITICAL_SECTION_ENTER()
	tmp = ((const Dmac *)hw)->CHCTRLB.reg;
	tmp = (tmp & DMAC_CHCTRLB_EVACT_Msk) >> DMAC_CHCTRLB_EVACT_Pos;
	DMAC_CRITICAL_SECTION_LEAVE()

	return tmp;
}

static inline void hri_dmac_toggle_CHCTRLB_EVACT_bf(void *const hw, const hri_dmac_chctrlb_reg_t mask)
{
	DMAC_CRITICAL_SECTION_ENTER()
	((Dmac *)hw)->CHCTRLB.reg ^= DMAC_CHCTRLB_EVACT(mask);

	DMAC_CRITICAL_SECTION_LEAVE()
}

static inline void hri_dmac_set_CHCTRLB_LVL_bf(void *const hw, const hri_dmac_chctrlb_reg_t mask)
{
	DMAC_CRITICAL_SECTION_ENTER()
	((Dmac *)hw)->CHCTRLB.reg |= DMAC_CHCTRLB_LVL(mask);
	DMAC_CRITICAL_SECTION_LEAVE()
}

static inline void hri_dmac_write_CHCTRLB_LVL_bf(void *const hw, const hri_dmac_chctrlb_reg_t data)
{
	uint32_t tmp;

	DMAC_CRITICAL_SECTION_ENTER()
	tmp = ((Dmac *)hw)->CHCTRLB.reg;
	tmp &= ~DMAC_CHCTRLB_LVL_Msk;
	tmp |= DMAC_CHCTRLB_LVL(data);
	((Dmac *)hw)->CHCTRLB.reg = tmp;
	DMAC_CRITICAL_SECTION_LEAVE()
}

static inline void hri_dmac_clear_CHCTRLB_LVL_bf(void *const hw, const hri_dmac_chctrlb_reg_t mask)
{
	DMAC_CRITICAL_SECTION_ENTER()
	((Dmac *)hw)->CHCTRLB.reg &= ~DMAC_CHCTRLB_LVL(mask);
	DMAC_CRITICAL_SECTION_LEAVE()
}

static inline hri_dmac_chctrlb_reg_t hri_dmac_get_CHCTRLB_LVL_bf(const void *const hw, const hri_dmac_chctrlb_reg_t mask)
{
	uint32_t tmp;

	DMAC_CRITICAL_SECTION_ENTER()
	tmp = ((const Dmac *)hw)->CHCTRLB.reg;
	tmp = (tmp & DMAC_CHCTRLB_LVL(mask)) >> DMAC_CHCTRLB_LVL_Pos;
	DMAC_CRITICAL_SECTION_LEAVE()

	return tmp;
}

static inline hri_dmac_chctrlb_reg_t hri_dmac_read_CHCTRLB_LVL_bf(const void *const hw)
{
	uint32_t tmp;

	DMAC_CRITICAL_SECTION_ENTER()
	tmp = ((const Dmac *)hw)->CHCTRLB.reg;
	tmp = (tmp & DMAC_CHCTRLB_LVL_Msk) >> DMAC_CHCTRLB_LVL_Pos;
	DMAC_CRITICAL_SECTION_LEAVE()

	return tmp;
}

static inline void hri_dmac_toggle_CHCTRLB_LVL_bf(void *const hw, const hri_dmac_chctrlb_reg_t mask)
{
	DMAC_CRITICAL_SECTION_ENTER()
	((Dmac *)hw)->CHCTRLB.reg ^= DMAC_CHCTRLB_LVL(mask);

	DMAC_CRITICAL_SECTION_LEAVE()
}

static inline void hri_dmac_set_CHCTRLB_TRIGSRC_bf(void *const hw, const hri_dmac_chctrlb_reg_t mask)
{
	DMAC_CRITICAL_SECTION_ENTER()
	((Dmac *)hw)->CHCTRLB.reg |= DMAC_CHCTRLB_TRIGSRC(mask);
	DMAC_CRITICAL_SECTION_LEAVE()
}

static inline void hri_dmac_write_CHCTRLB_TRIGSRC_bf(void *const hw, const hri_dmac_chctrlb_reg_t data)
{
	uint32_t tmp;

	DMAC_CRITICAL_SECTION_ENTER()
	tmp = ((Dmac *)hw)->CHCTRLB.reg;
	tmp &= ~DMAC_CHCTRLB_TRIGSRC_Msk;
	tmp |= DMAC_CHCTRLB_TRIGSRC(data);
	((Dmac *)hw)->CHCTRLB.reg = tmp;
	DMAC_CRITICAL_SECTION_LEAVE()
}

static inline void hri_dmac_clear_CHCTRLB_TRIGSRC_bf(void *const hw, const hri_dmac_chctrlb_reg_t mask)
{
	DMAC_CRITICAL_SECTION_ENTER()
	((Dmac *)hw)->CHCTRLB.reg &= ~DMAC_CHCTRLB_TRIGSRC(mask);
	DMAC_CRITICAL_SECTION_LEAVE()
}

static inline hri_dmac_chctrlb_reg_t hri_dmac_get_CHCTRLB_TRIGSRC_bf(const void *const hw, const hri_dmac_chctrlb_reg_t mask)
{
	uint32_t tmp;

	DMAC_CRITICAL_SECTION_ENTER()
	tmp = ((const Dmac *)hw)->CHCTRLB.reg;
	tmp = (tmp & DMAC_CHCTRLB_TRIGSRC(mask)) >> DMAC_CHCTRLB_TRIGSRC_Pos;
	DMAC_CRITICAL_SECTION_LEAVE()

	return tmp;
}

static inline hri_dmac_chctrlb_reg_t hri_dmac_read_CHCTRLB_TRIGSRC_bf(const void *const hw)
{
	uint32_t tmp;

	DMAC_CRITICAL_SECTION_ENTER()
	tmp = ((const Dmac *)hw)->CHCTRLB.reg;
	tmp = (tmp & DMAC_CHCTRLB_TRIGSRC_Msk) >> DMAC_CHCTRLB_TRIGSRC_Pos;
	DMAC_CRITICAL_SECTION_LEAVE()

	return tmp;
}

static inline void hri_dmac_toggle_CHCTRLB_TRIGSRC_bf(void *const hw, const hri_dmac_chctrlb_reg_t mask)
{
	DMAC_CRITICAL_SECTION_ENTER()
	((Dmac *)hw)->CHCTRLB.reg ^= DMAC_CHCTRLB_TRIGSRC(mask);

	DMAC_CRITICAL_SECTION_LEAVE()
}

static inline void hri_dmac_set_CHCTRLB_TRIGACT_bf(void *const hw, const hri_dmac_chctrlb_reg_t mask)
{
	DMAC_CRITICAL_SECTION_ENTER()
	((Dmac *)hw)->CHCTRLB.reg |= DMAC_CHCTRLB_TRIGACT(mask);
	DMAC_CRITICAL_SECTION_LEAVE()
}

static inline void hri_dmac_write_CHCTRLB_TRIGACT_bf(void *const hw, const hri_dmac_chctrlb_reg_t data)
{
	uint32_t tmp;

	DMAC_CRITICAL_SECTION_ENTER()
	tmp = ((Dmac *)hw)->CHCTRLB.reg;
	tmp &= ~DMAC_CHCTRLB_TRIGACT_Msk;
	tmp |= DMAC_CHCTRLB_TRIGACT(data);
	((Dmac *)hw)->CHCTRLB.reg = tmp;
	DMAC_CRITICAL_SECTION_LEAVE()
}

static inline void hri_dmac_clear_CHCTRLB_TRIGACT_bf(void *const hw, const hri_dmac_chctrlb_reg_t mask)
{
	DMAC_CRITICAL_SECTION_ENTER()
	((Dmac *)hw)->CHCTRLB.reg &= ~DMAC_CHCTRLB_TRIGACT(mask);
	DMAC_CRITICAL_SECTION_LEAVE()
}

static inline hri_dmac_chctrlb_reg_t hri_dmac_get_CHCTRLB_TRIGACT_bf(const void *const hw, const hri_dmac_chctrlb_reg_t mask)
{
	uint32_t tmp;

	DMAC_CRITICAL_SECTION_ENTER()
	tmp = ((const Dmac *)hw)->CHCTRLB.reg;
	tmp = (tmp & DMAC_CHCTRLB_TRIGACT(mask)) >> DMAC_CHCTRLB_TRIGACT_Pos;
	DMAC_CRITICAL_SECTION_LEAVE()

	return tmp;
}

static inline hri_dmac_chctrlb_reg_t hri_dmac_read_CHCTRLB_TRIGACT_bf(const void *const hw)
{
	uint32_t tmp;

	DMAC_CRITICAL_SECTION_ENTER()
	tmp = ((const Dmac *)hw)->CHCTRLB.reg;
	tmp = (tmp & DMAC_CHCTRLB_TRIGACT_Msk) >> DMAC_CHCTRLB_TRIGACT_Pos;
	DMAC_CRITICAL_SECTION_LEAVE()

	return tmp;
}

static inline void hri_dmac_toggle_CHCTRLB_TRIGACT_bf(void *const hw, const hri_dmac_chctrlb_reg_t mask)
{
	DMAC_CRITICAL_SECTION_ENTER()
	((Dmac *)hw)->CHCTRLB.reg ^= DMAC_CHCTRLB_TRIGACT(mask);

	DMAC_CRITICAL_SECTION_LEAVE()
}

static inline void hri_dmac_set_CHCTRLB_CMD_bf(void *const hw, const hri_dmac_chctrlb_reg_t mask)
{
	DMAC_CRITICAL_SECTION_ENTER()
	((Dmac *)hw)->CHCTRLB.reg |= DMAC_CHCTRLB_CMD(mask);
	DMAC_CRITICAL_SECTION_LEAVE()
}

static inline void hri_dmac_write_CHCTRLB_CMD_bf(void *const hw, const hri_dmac_chctrlb_reg_t data)
{
	uint32_t tmp;

	DMAC_CRITICAL_SECTION_ENTER()
	tmp = ((Dmac *)hw)->CHCTRLB.reg;
	tmp &= ~DMAC_CHCTRLB_CMD_Msk;
	tmp |= DMAC_CHCTRLB_CMD(data);
	((Dmac *)hw)->CHCTRLB.reg = tmp;
	DMAC_CRITICAL_SECTION_LEAVE()
}

static inline void hri_dmac_clear_CHCTRLB_CMD_bf(void *const hw, const hri_dmac_chctrlb_reg_t mask)
{
	DMAC_CRITICAL_SECTION_ENTER()
	((Dmac *)hw)->CHCTRLB.reg &= ~DMAC_CHCTRLB_CMD(mask);
	DMAC_CRITICAL_SECTION_LEAVE()
}

static inline hri_dmac_chctrlb_reg_t hri_dmac_get_CHCTRLB_CMD_bf(const void *const hw, const hri_dmac_chctrlb_reg_t mask)
{
	uint32_t tmp;

	DMAC_CRITICAL_SECTION_ENTER()
	tmp = ((const Dmac *)hw)->CHCTRLB.reg;
	tmp = (tmp & DMAC_CHCTRLB_CMD(mask)) >> DMAC_CHCTRLB_CMD_Pos;
	DMAC_CRITICAL_SECTION_LEAVE()

	return tmp;
}

static inline hri_dmac_chctrlb_reg_t hri_dmac_read_CHCTRLB_CMD_bf(const void *const hw)
{
	uint32_t tmp;

	DMAC_CRITICAL_SECTION_ENTER()
	tmp = ((const Dmac *)hw)->CHCTRLB.reg;
	tmp = (tmp & DMAC_CHCTRLB_CMD_Msk) >> DMAC_CHCTRLB_CMD_Pos;
	DMAC_CRITICAL_SECTION_LEAVE()

	return tmp;
}

static inline void hri_dmac_toggle_CHCTRLB_CMD_bf(void *const hw, const hri_dmac_chctrlb_reg_t mask)
{
	DMAC_CRITICAL_SECTION_ENTER()
	((Dmac *)hw)->CHCTRLB.reg ^= DMAC_CHCTRLB_CMD(mask);

	DMAC_CRITICAL_SECTION_LEAVE()
}


static inline void hri_dmac_set_CTRL_reg(void *const hw, const hri_dmac_ctrl_reg_t mask)
{
	DMAC_CRITICAL_SECTION_ENTER()
	((Dmac *)hw)->CTRL.reg |= mask;
	DMAC_CRITICAL_SECTION_LEAVE()
}

static inline void hri_dmac_write_CTRL_reg(void *const hw, const hri_dmac_ctrl_reg_t data)
{
	DMAC_CRITICAL_SECTION_ENTER()
	((Dmac *)hw)->CTRL.reg = data;
	DMAC_CRITICAL_SECTION_LEAVE()
}

static inline void hri_dmac_clear_CTRL_reg(void *const hw, const hri_dmac_ctrl_reg_t mask)
{
	DMAC_CRITICAL_SECTION_ENTER()
	((Dmac *)hw)->CTRL.reg &= ~mask;
	DMAC_CRITICAL_SECTION_LEAVE()
}

static inline uint32_t hri_dmac_get_CTRL_reg(const void *const hw, const hri_dmac_ctrl_reg_t mask)
{
	uint16_t tmp;

	DMAC_CRITICAL_SECTION_ENTER()
	tmp = ((const Dmac *)hw)->CTRL.reg;
	tmp &= mask;
	DMAC_CRITICAL_SECTION_LEAVE()

	return tmp;
}

static inline uint32_t hri_dmac_read_CTRL_reg(const void *const hw)
{
	return ((const Dmac *)hw)->CTRL.reg;
}

static inline void hri_dmac_toggle_CTRL_reg(void *const hw, const hri_dmac_ctrl_reg_t mask)
{
	DMAC_CRITICAL_SECTION_ENTER()
	((Dmac *)hw)->CTRL.reg ^= mask ;
	DMAC_CRITICAL_SECTION_LEAVE()
}

static inline void hri_dmac_set_CRCCTRL_reg(void *const hw, const hri_dmac_crcctrl_reg_t mask)
{
	DMAC_CRITICAL_SECTION_ENTER()
	((Dmac *)hw)->CRCCTRL.reg |= mask;
	DMAC_CRITICAL_SECTION_LEAVE()
}

static inline void hri_dmac_write_CRCCTRL_reg(void *const hw, const hri_dmac_crcctrl_reg_t data)
{
	DMAC_CRITICAL_SECTION_ENTER()
	((Dmac *)hw)->CRCCTRL.reg = data;
	DMAC_CRITICAL_SECTION_LEAVE()
}

static inline void hri_dmac_clear_CRCCTRL_reg(void *const hw, const hri_dmac_crcctrl_reg_t mask)
{
	DMAC_CRITICAL_SECTION_ENTER()
	((Dmac *)hw)->CRCCTRL.reg &= ~mask;
	DMAC_CRITICAL_SECTION_LEAVE()
}

static inline uint32_t hri_dmac_get_CRCCTRL_reg(const void *const hw, const hri_dmac_crcctrl_reg_t mask)
{
	uint16_t tmp;

	DMAC_CRITICAL_SECTION_ENTER()
	tmp = ((const Dmac *)hw)->CRCCTRL.reg;
	tmp &= mask;
	DMAC_CRITICAL_SECTION_LEAVE()

	return tmp;
}

static inline uint32_t hri_dmac_read_CRCCTRL_reg(const void *const hw)
{
	return ((const Dmac *)hw)->CRCCTRL.reg;
}

static inline void hri_dmac_toggle_CRCCTRL_reg(void *const hw, const hri_dmac_crcctrl_reg_t mask)
{
	DMAC_CRITICAL_SECTION_ENTER()
	((Dmac *)hw)->CRCCTRL.reg ^= mask ;
	DMAC_CRITICAL_SECTION_LEAVE()
}

static inline void hri_dmac_set_CRCDATAIN_reg(void *const hw, const hri_dmac_crcdatain_reg_t mask)
{
	DMAC_CRITICAL_SECTION_ENTER()
	((Dmac *)hw)->CRCDATAIN.reg |= mask;
	DMAC_CRITICAL_SECTION_LEAVE()
}

static inline void hri_dmac_write_CRCDATAIN_reg(void *const hw, const hri_dmac_crcdatain_reg_t data)
{
	DMAC_CRITICAL_SECTION_ENTER()
	((Dmac *)hw)->CRCDATAIN.reg = data;
	DMAC_CRITICAL_SECTION_LEAVE()
}

static inline void hri_dmac_clear_CRCDATAIN_reg(void *const hw, const hri_dmac_crcdatain_reg_t mask)
{
	DMAC_CRITICAL_SECTION_ENTER()
	((Dmac *)hw)->CRCDATAIN.reg &= ~mask;
	DMAC_CRITICAL_SECTION_LEAVE()
}

static inline uint32_t hri_dmac_get_CRCDATAIN_reg(const void *const hw, const hri_dmac_crcdatain_reg_t mask)
{
	uint32_t tmp;

	DMAC_CRITICAL_SECTION_ENTER()
	tmp = ((const Dmac *)hw)->CRCDATAIN.reg;
	tmp &= mask;
	DMAC_CRITICAL_SECTION_LEAVE()

	return tmp;
}

static inline uint32_t hri_dmac_read_CRCDATAIN_reg(const void *const hw)
{
	return ((const Dmac *)hw)->CRCDATAIN.reg;
}

static inline void hri_dmac_toggle_CRCDATAIN_reg(void *const hw, const hri_dmac_crcdatain_reg_t mask)
{
	DMAC_CRITICAL_SECTION_ENTER()
	((Dmac *)hw)->CRCDATAIN.reg ^= mask ;
	DMAC_CRITICAL_SECTION_LEAVE()
}

static inline void hri_dmac_set_CRCCHKSUM_reg(void *const hw, const hri_dmac_crcchksum_reg_t mask)
{
	DMAC_CRITICAL_SECTION_ENTER()
	((Dmac *)hw)->CRCCHKSUM.reg |= mask;
	DMAC_CRITICAL_SECTION_LEAVE()
}

static inline void hri_dmac_write_CRCCHKSUM_reg(void *const hw, const hri_dmac_crcchksum_reg_t data)
{
	DMAC_CRITICAL_SECTION_ENTER()
	((Dmac *)hw)->CRCCHKSUM.reg = data;
	DMAC_CRITICAL_SECTION_LEAVE()
}

static inline void hri_dmac_clear_CRCCHKSUM_reg(void *const hw, const hri_dmac_crcchksum_reg_t mask)
{
	DMAC_CRITICAL_SECTION_ENTER()
	((Dmac *)hw)->CRCCHKSUM.reg &= ~mask;
	DMAC_CRITICAL_SECTION_LEAVE()
}

static inline uint32_t hri_dmac_get_CRCCHKSUM_reg(const void *const hw, const hri_dmac_crcchksum_reg_t mask)
{
	uint32_t tmp;

	DMAC_CRITICAL_SECTION_ENTER()
	tmp = ((const Dmac *)hw)->CRCCHKSUM.reg;
	tmp &= mask;
	DMAC_CRITICAL_SECTION_LEAVE()

	return tmp;
}

static inline uint32_t hri_dmac_read_CRCCHKSUM_reg(const void *const hw)
{
	return ((const Dmac *)hw)->CRCCHKSUM.reg;
}

static inline void hri_dmac_toggle_CRCCHKSUM_reg(void *const hw, const hri_dmac_crcchksum_reg_t mask)
{
	DMAC_CRITICAL_SECTION_ENTER()
	((Dmac *)hw)->CRCCHKSUM.reg ^= mask ;
	DMAC_CRITICAL_SECTION_LEAVE()
}

static inline void hri_dmac_clear_CRCSTATUS_reg(void *const hw, const hri_dmac_crcstatus_reg_t mask)
{
	((Dmac *)hw)->CRCSTATUS.reg = mask;
}

static inline uint32_t hri_dmac_get_CRCSTATUS_reg(const void *const hw, const hri_dmac_crcstatus_reg_t mask)
{
	uint8_t tmp;

	DMAC_CRITICAL_SECTION_ENTER()
	tmp = ((const Dmac *)hw)->CRCSTATUS.reg;
	tmp &= mask;
	DMAC_CRITICAL_SECTION_LEAVE()

	return tmp;
}

static inline uint32_t hri_dmac_read_CRCSTATUS_reg(const void *const hw)
{
	return ((const Dmac *)hw)->CRCSTATUS.reg;
}

static inline void hri_dmac_set_DBGCTRL_reg(void *const hw, const hri_dmac_dbgctrl_reg_t mask)
{
	DMAC_CRITICAL_SECTION_ENTER()
	((Dmac *)hw)->DBGCTRL.reg |= mask;
	DMAC_CRITICAL_SECTION_LEAVE()
}

static inline void hri_dmac_write_DBGCTRL_reg(void *const hw, const hri_dmac_dbgctrl_reg_t data)
{
	DMAC_CRITICAL_SECTION_ENTER()
	((Dmac *)hw)->DBGCTRL.reg = data;
	DMAC_CRITICAL_SECTION_LEAVE()
}

static inline void hri_dmac_clear_DBGCTRL_reg(void *const hw, const hri_dmac_dbgctrl_reg_t mask)
{
	DMAC_CRITICAL_SECTION_ENTER()
	((Dmac *)hw)->DBGCTRL.reg &= ~mask;
	DMAC_CRITICAL_SECTION_LEAVE()
}

static inline uint32_t hri_dmac_get_DBGCTRL_reg(const void *const hw, const hri_dmac_dbgctrl_reg_t mask)
{
	uint8_t tmp;

	DMAC_CRITICAL_SECTION_ENTER()
	tmp = ((const Dmac *)hw)->DBGCTRL.reg;
	tmp &= mask;
	DMAC_CRITICAL_SECTION_LEAVE()

	return tmp;
}

static inline uint32_t hri_dmac_read_DBGCTRL_reg(const void *const hw)
{
	return ((const Dmac *)hw)->DBGCTRL.reg;
}

static inline void hri_dmac_toggle_DBGCTRL_reg(void *const hw, const hri_dmac_dbgctrl_reg_t mask)
{
	DMAC_CRITICAL_SECTION_ENTER()
	((Dmac *)hw)->DBGCTRL.reg ^= mask ;
	DMAC_CRITICAL_SECTION_LEAVE()
}

static inline void hri_dmac_set_SWTRIGCTRL_reg(void *const hw, const hri_dmac_swtrigctrl_reg_t mask)
{
	DMAC_CRITICAL_SECTION_ENTER()
	((Dmac *)hw)->SWTRIGCTRL.reg |= mask;
	DMAC_CRITICAL_SECTION_LEAVE()
}

static inline void hri_dmac_write_SWTRIGCTRL_reg(void *const hw, const hri_dmac_swtrigctrl_reg_t data)
{
	DMAC_CRITICAL_SECTION_ENTER()
	((Dmac *)hw)->SWTRIGCTRL.reg = data;
	DMAC_CRITICAL_SECTION_LEAVE()
}

static inline void hri_dmac_clear_SWTRIGCTRL_reg(void *const hw, const hri_dmac_swtrigctrl_reg_t mask)
{
	DMAC_CRITICAL_SECTION_ENTER()
	((Dmac *)hw)->SWTRIGCTRL.reg &= ~mask;
	DMAC_CRITICAL_SECTION_LEAVE()
}

static inline uint32_t hri_dmac_get_SWTRIGCTRL_reg(const void *const hw, const hri_dmac_swtrigctrl_reg_t mask)
{
	uint32_t tmp;

	DMAC_CRITICAL_SECTION_ENTER()
	tmp = ((const Dmac *)hw)->SWTRIGCTRL.reg;
	tmp &= mask;
	DMAC_CRITICAL_SECTION_LEAVE()

	return tmp;
}

static inline uint32_t hri_dmac_read_SWTRIGCTRL_reg(const void *const hw)
{
	return ((const Dmac *)hw)->SWTRIGCTRL.reg;
}

static inline void hri_dmac_toggle_SWTRIGCTRL_reg(void *const hw, const hri_dmac_swtrigctrl_reg_t mask)
{
	DMAC_CRITICAL_SECTION_ENTER()
	((Dmac *)hw)->SWTRIGCTRL.reg ^= mask ;
	DMAC_CRITICAL_SECTION_LEAVE()
}

static inline void hri_dmac_set_PRICTRL0_reg(void *const hw, const hri_dmac_prictrl0_reg_t mask)
{
	DMAC_CRITICAL_SECTION_ENTER()
	((Dmac *)hw)->PRICTRL0.reg |= mask;
	DMAC_CRITICAL_SECTION_LEAVE()
}

static inline void hri_dmac_write_PRICTRL0_reg(void *const hw, const hri_dmac_prictrl0_reg_t data)
{
	DMAC_CRITICAL_SECTION_ENTER()
	((Dmac *)hw)->PRICTRL0.reg = data;
	DMAC_CRITICAL_SECTION_LEAVE()
}

static inline void hri_dmac_clear_PRICTRL0_reg(void *const hw, const hri_dmac_prictrl0_reg_t mask)
{
	DMAC_CRITICAL_SECTION_ENTER()
	((Dmac *)hw)->PRICTRL0.reg &= ~mask;
	DMAC_CRITICAL_SECTION_LEAVE()
}

static inline uint32_t hri_dmac_get_PRICTRL0_reg(const void *const hw, const hri_dmac_prictrl0_reg_t mask)
{
	uint32_t tmp;

	DMAC_CRITICAL_SECTION_ENTER()
	tmp = ((const Dmac *)hw)->PRICTRL0.reg;
	tmp &= mask;
	DMAC_CRITICAL_SECTION_LEAVE()

	return tmp;
}

static inline uint32_t hri_dmac_read_PRICTRL0_reg(const void *const hw)
{
	return ((const Dmac *)hw)->PRICTRL0.reg;
}

static inline void hri_dmac_toggle_PRICTRL0_reg(void *const hw, const hri_dmac_prictrl0_reg_t mask)
{
	DMAC_CRITICAL_SECTION_ENTER()
	((Dmac *)hw)->PRICTRL0.reg ^= mask ;
	DMAC_CRITICAL_SECTION_LEAVE()
}

static inline void hri_dmac_set_INTPEND_reg(void *const hw, const hri_dmac_intpend_reg_t mask)
{
	DMAC_CRITICAL_SECTION_ENTER()
	((Dmac *)hw)->INTPEND.reg |= mask;
	DMAC_CRITICAL_SECTION_LEAVE()
}

static inline void hri_dmac_write_INTPEND_reg(void *const hw, const hri_dmac_intpend_reg_t data)
{
	DMAC_CRITICAL_SECTION_ENTER()
	((Dmac *)hw)->INTPEND.reg = data;
	DMAC_CRITICAL_SECTION_LEAVE()
}

static inline void hri_dmac_clear_INTPEND_reg(void *const hw, const hri_dmac_intpend_reg_t mask)
{
	DMAC_CRITICAL_SECTION_ENTER()
	((Dmac *)hw)->INTPEND.reg &= ~mask;
	DMAC_CRITICAL_SECTION_LEAVE()
}

static inline uint32_t hri_dmac_get_INTPEND_reg(const void *const hw, const hri_dmac_intpend_reg_t mask)
{
	uint16_t tmp;

	DMAC_CRITICAL_SECTION_ENTER()
	tmp = ((const Dmac *)hw)->INTPEND.reg;
	tmp &= mask;
	DMAC_CRITICAL_SECTION_LEAVE()

	return tmp;
}

static inline uint32_t hri_dmac_read_INTPEND_reg(const void *const hw)
{
	return ((const Dmac *)hw)->INTPEND.reg;
}

static inline void hri_dmac_toggle_INTPEND_reg(void *const hw, const hri_dmac_intpend_reg_t mask)
{
	DMAC_CRITICAL_SECTION_ENTER()
	((Dmac *)hw)->INTPEND.reg ^= mask ;
	DMAC_CRITICAL_SECTION_LEAVE()
}

static inline uint32_t hri_dmac_get_INTSTATUS_reg(const void *const hw, const hri_dmac_intstatus_reg_t mask)
{
	uint32_t tmp;

	DMAC_CRITICAL_SECTION_ENTER()
	tmp = ((const Dmac *)hw)->INTSTATUS.reg;
	tmp &= mask;
	DMAC_CRITICAL_SECTION_LEAVE()

	return tmp;
}

static inline uint32_t hri_dmac_read_INTSTATUS_reg(const void *const hw)
{
	return ((const Dmac *)hw)->INTSTATUS.reg;
}

static inline uint32_t hri_dmac_get_BUSYCH_reg(const void *const hw, const hri_dmac_busych_reg_t mask)
{
	uint32_t tmp;

	DMAC_CRITICAL_SECTION_ENTER()
	tmp = ((const Dmac *)hw)->BUSYCH.reg;
	tmp &= mask;
	DMAC_CRITICAL_SECTION_LEAVE()

	return tmp;
}

static inline uint32_t hri_dmac_read_BUSYCH_reg(const void *const hw)
{
	return ((const Dmac *)hw)->BUSYCH.reg;
}

static inline uint32_t hri_dmac_get_PENDCH_reg(const void *const hw, const hri_dmac_pendch_reg_t mask)
{
	uint32_t tmp;

	DMAC_CRITICAL_SECTION_ENTER()
	tmp = ((const Dmac *)hw)->PENDCH.reg;
	tmp &= mask;
	DMAC_CRITICAL_SECTION_LEAVE()

	return tmp;
}

static inline uint32_t hri_dmac_read_PENDCH_reg(const void *const hw)
{
	return ((const Dmac *)hw)->PENDCH.reg;
}

static inline uint32_t hri_dmac_get_ACTIVE_reg(const void *const hw, const hri_dmac_active_reg_t mask)
{
	uint32_t tmp;

	DMAC_CRITICAL_SECTION_ENTER()
	tmp = ((const Dmac *)hw)->ACTIVE.reg;
	tmp &= mask;
	DMAC_CRITICAL_SECTION_LEAVE()

	return tmp;
}

static inline uint32_t hri_dmac_read_ACTIVE_reg(const void *const hw)
{
	return ((const Dmac *)hw)->ACTIVE.reg;
}

static inline void hri_dmac_set_BASEADDR_reg(void *const hw, const hri_dmac_baseaddr_reg_t mask)
{
	DMAC_CRITICAL_SECTION_ENTER()
	((Dmac *)hw)->BASEADDR.reg |= mask;
	DMAC_CRITICAL_SECTION_LEAVE()
}

static inline void hri_dmac_write_BASEADDR_reg(void *const hw, const hri_dmac_baseaddr_reg_t data)
{
	DMAC_CRITICAL_SECTION_ENTER()
	((Dmac *)hw)->BASEADDR.reg = data;
	DMAC_CRITICAL_SECTION_LEAVE()
}

static inline void hri_dmac_clear_BASEADDR_reg(void *const hw, const hri_dmac_baseaddr_reg_t mask)
{
	DMAC_CRITICAL_SECTION_ENTER()
	((Dmac *)hw)->BASEADDR.reg &= ~mask;
	DMAC_CRITICAL_SECTION_LEAVE()
}

static inline uint32_t hri_dmac_get_BASEADDR_reg(const void *const hw, const hri_dmac_baseaddr_reg_t mask)
{
	uint32_t tmp;

	DMAC_CRITICAL_SECTION_ENTER()
	tmp = ((const Dmac *)hw)->BASEADDR.reg;
	tmp &= mask;
	DMAC_CRITICAL_SECTION_LEAVE()

	return tmp;
}

static inline uint32_t hri_dmac_read_BASEADDR_reg(const void *const hw)
{
	return ((const Dmac *)hw)->BASEADDR.reg;
}

static inline void hri_dmac_toggle_BASEADDR_reg(void *const hw, const hri_dmac_baseaddr_reg_t mask)
{
	DMAC_CRITICAL_SECTION_ENTER()
	((Dmac *)hw)->BASEADDR.reg ^= mask ;
	DMAC_CRITICAL_SECTION_LEAVE()
}

static inline void hri_dmac_set_WRBADDR_reg(void *const hw, const hri_dmac_wrbaddr_reg_t mask)
{
	DMAC_CRITICAL_SECTION_ENTER()
	((Dmac *)hw)->WRBADDR.reg |= mask;
	DMAC_CRITICAL_SECTION_LEAVE()
}

static inline void hri_dmac_write_WRBADDR_reg(void *const hw, const hri_dmac_wrbaddr_reg_t data)
{
	DMAC_CRITICAL_SECTION_ENTER()
	((Dmac *)hw)->WRBADDR.reg = data;
	DMAC_CRITICAL_SECTION_LEAVE()
}

static inline void hri_dmac_clear_WRBADDR_reg(void *const hw, const hri_dmac_wrbaddr_reg_t mask)
{
	DMAC_CRITICAL_SECTION_ENTER()
	((Dmac *)hw)->WRBADDR.reg &= ~mask;
	DMAC_CRITICAL_SECTION_LEAVE()
}

static inline uint32_t hri_dmac_get_WRBADDR_reg(const void *const hw, const hri_dmac_wrbaddr_reg_t mask)
{
	uint32_t tmp;

	DMAC_CRITICAL_SECTION_ENTER()
	tmp = ((const Dmac *)hw)->WRBADDR.reg;
	tmp &= mask;
	DMAC_CRITICAL_SECTION_LEAVE()

	return tmp;
}

static inline uint32_t hri_dmac_read_WRBADDR_reg(const void *const hw)
{
	return ((const Dmac *)hw)->WRBADDR.reg;
}

static inline void hri_dmac_toggle_WRBADDR_reg(void *const hw, const hri_dmac_wrbaddr_reg_t mask)
{
	DMAC_CRITICAL_SECTION_ENTER()
	((Dmac *)hw)->WRBADDR.reg ^= mask ;
	DMAC_CRITICAL_SECTION_LEAVE()
}

static inline void hri_dmac_set_CHID_reg(void *const hw, const hri_dmac_chid_reg_t mask)
{
	DMAC_CRITICAL_SECTION_ENTER()
	((Dmac *)hw)->CHID.reg |= mask;
	DMAC_CRITICAL_SECTION_LEAVE()
}

static inline void hri_dmac_write_CHID_reg(void *const hw, const hri_dmac_chid_reg_t data)
{
	DMAC_CRITICAL_SECTION_ENTER()
	((Dmac *)hw)->CHID.reg = data;
	DMAC_CRITICAL_SECTION_LEAVE()
}

static inline void hri_dmac_clear_CHID_reg(void *const hw, const hri_dmac_chid_reg_t mask)
{
	DMAC_CRITICAL_SECTION_ENTER()
	((Dmac *)hw)->CHID.reg &= ~mask;
	DMAC_CRITICAL_SECTION_LEAVE()
}

static inline uint32_t hri_dmac_get_CHID_reg(const void *const hw, const hri_dmac_chid_reg_t mask)
{
	uint8_t tmp;

	DMAC_CRITICAL_SECTION_ENTER()
	tmp = ((const Dmac *)hw)->CHID.reg;
	tmp &= mask;
	DMAC_CRITICAL_SECTION_LEAVE()

	return tmp;
}

static inline uint32_t hri_dmac_read_CHID_reg(const void *const hw)
{
	return ((const Dmac *)hw)->CHID.reg;
}

static inline void hri_dmac_toggle_CHID_reg(void *const hw, const hri_dmac_chid_reg_t mask)
{
	DMAC_CRITICAL_SECTION_ENTER()
	((Dmac *)hw)->CHID.reg ^= mask ;
	DMAC_CRITICAL_SECTION_LEAVE()
}

static inline void hri_dmac_set_CHCTRLA_reg(void *const hw, const hri_dmac_chctrla_reg_t mask)
{
	DMAC_CRITICAL_SECTION_ENTER()
	((Dmac *)hw)->CHCTRLA.reg |= mask;
	DMAC_CRITICAL_SECTION_LEAVE()
}

static inline void hri_dmac_write_CHCTRLA_reg(void *const hw, const hri_dmac_chctrla_reg_t data)
{
	DMAC_CRITICAL_SECTION_ENTER()
	((Dmac *)hw)->CHCTRLA.reg = data;
	DMAC_CRITICAL_SECTION_LEAVE()
}

static inline void hri_dmac_clear_CHCTRLA_reg(void *const hw, const hri_dmac_chctrla_reg_t mask)
{
	DMAC_CRITICAL_SECTION_ENTER()
	((Dmac *)hw)->CHCTRLA.reg &= ~mask;
	DMAC_CRITICAL_SECTION_LEAVE()
}

static inline uint32_t hri_dmac_get_CHCTRLA_reg(const void *const hw, const hri_dmac_chctrla_reg_t mask)
{
	uint8_t tmp;

	DMAC_CRITICAL_SECTION_ENTER()
	tmp = ((const Dmac *)hw)->CHCTRLA.reg;
	tmp &= mask;
	DMAC_CRITICAL_SECTION_LEAVE()

	return tmp;
}

static inline uint32_t hri_dmac_read_CHCTRLA_reg(const void *const hw)
{
	return ((const Dmac *)hw)->CHCTRLA.reg;
}

static inline void hri_dmac_toggle_CHCTRLA_reg(void *const hw, const hri_dmac_chctrla_reg_t mask)
{
	DMAC_CRITICAL_SECTION_ENTER()
	((Dmac *)hw)->CHCTRLA.reg ^= mask ;
	DMAC_CRITICAL_SECTION_LEAVE()
}

static inline void hri_dmac_set_CHCTRLB_reg(void *const hw, const hri_dmac_chctrlb_reg_t mask)
{
	DMAC_CRITICAL_SECTION_ENTER()
	((Dmac *)hw)->CHCTRLB.reg |= mask;
	DMAC_CRITICAL_SECTION_LEAVE()
}

static inline void hri_dmac_write_CHCTRLB_reg(void *const hw, const hri_dmac_chctrlb_reg_t data)
{
	DMAC_CRITICAL_SECTION_ENTER()
	((Dmac *)hw)->CHCTRLB.reg = data;
	DMAC_CRITICAL_SECTION_LEAVE()
}

static inline void hri_dmac_clear_CHCTRLB_reg(void *const hw, const hri_dmac_chctrlb_reg_t mask)
{
	DMAC_CRITICAL_SECTION_ENTER()
	((Dmac *)hw)->CHCTRLB.reg &= ~mask;
	DMAC_CRITICAL_SECTION_LEAVE()
}

static inline uint32_t hri_dmac_get_CHCTRLB_reg(const void *const hw, const hri_dmac_chctrlb_reg_t mask)
{
	uint32_t tmp;

	DMAC_CRITICAL_SECTION_ENTER()
	tmp = ((const Dmac *)hw)->CHCTRLB.reg;
	tmp &= mask;
	DMAC_CRITICAL_SECTION_LEAVE()

	return tmp;
}

static inline uint32_t hri_dmac_read_CHCTRLB_reg(const void *const hw)
{
	return ((const Dmac *)hw)->CHCTRLB.reg;
}

static inline void hri_dmac_toggle_CHCTRLB_reg(void *const hw, const hri_dmac_chctrlb_reg_t mask)
{
	DMAC_CRITICAL_SECTION_ENTER()
	((Dmac *)hw)->CHCTRLB.reg ^= mask ;
	DMAC_CRITICAL_SECTION_LEAVE()
}

static inline void hri_dmac_clear_CHINTEN_reg(void *const hw, const hri_dmac_chinten_reg_t mask)
{
	((Dmac *)hw)->CHINTENCLR.reg = mask;
}

static inline void hri_dmac_set_CHINTEN_reg(void *const hw, const hri_dmac_chinten_reg_t mask)
{
	((Dmac *)hw)->CHINTENSET.reg = mask;
}

static inline void hri_dmac_write_CHINTEN_reg(void *const hw, const hri_dmac_chinten_reg_t data)
{
	DMAC_CRITICAL_SECTION_ENTER()
	((Dmac *)hw)->CHINTENCLR.reg = 7;
	((Dmac *)hw)->CHINTENSET.reg = data;
	DMAC_CRITICAL_SECTION_LEAVE()
}

static inline uint32_t hri_dmac_get_CHINTEN_reg(const void *const hw, const hri_dmac_chinten_reg_t mask)
{
	uint8_t tmp;

	DMAC_CRITICAL_SECTION_ENTER()
	tmp = ((const Dmac *)hw)->CHINTENSET.reg;
	tmp &= mask;
	DMAC_CRITICAL_SECTION_LEAVE()

	return tmp;
}

static inline uint32_t hri_dmac_read_CHINTEN_reg(const void *const hw)
{
	return ((const Dmac *)hw)->CHINTENSET.reg;
}

static inline void hri_dmac_clear_CHINTFLAG_reg(void *const hw, const hri_dmac_chintflag_reg_t mask)
{
	((Dmac *)hw)->CHINTFLAG.reg = mask;
}

static inline uint32_t hri_dmac_get_CHINTFLAG_reg(const void *const hw, const hri_dmac_chintflag_reg_t mask)
{
	uint8_t tmp;

	DMAC_CRITICAL_SECTION_ENTER()
	tmp = ((const Dmac *)hw)->CHINTFLAG.reg;
	tmp &= mask;
	DMAC_CRITICAL_SECTION_LEAVE()

	return tmp;
}

static inline uint32_t hri_dmac_read_CHINTFLAG_reg(const void *const hw)
{
	return ((const Dmac *)hw)->CHINTFLAG.reg;
}

static inline uint32_t hri_dmac_get_CHSTATUS_reg(const void *const hw, const hri_dmac_chstatus_reg_t mask)
{
	uint8_t tmp;

	DMAC_CRITICAL_SECTION_ENTER()
	tmp = ((const Dmac *)hw)->CHSTATUS.reg;
	tmp &= mask;
	DMAC_CRITICAL_SECTION_LEAVE()

	return tmp;
}

static inline uint32_t hri_dmac_read_CHSTATUS_reg(const void *const hw)
{
	return ((const Dmac *)hw)->CHSTATUS.reg;
}

#endif /* _HRI_DMAC_V100_H_INCLUDED */
