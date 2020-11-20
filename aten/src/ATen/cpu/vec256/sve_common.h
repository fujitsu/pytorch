/*
 Copyright (c) 2020, FUJITSU LIMITED
 All rights reserved.

 Redistribution and use in source and binary forms, with or without
 modification, are permitted provided that the following conditions are met:
 * Redistributions of source code must retain the above copyright notice,
   this list of conditions and the following disclaimer.
   * Redistributions in binary form must reproduce the above copyright notice,
   this list of conditions and the following disclaimer in the documentation
   and/or other materials provided with the distribution.
   * Neither the name of the <organization> nor the names of its contributors
   may be used to endorse or promote products derived from this software
   without specific prior written permission.

 THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
 ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 DISCLAIMED. IN NO EVENT SHALL <COPYRIGHT HOLDER> BE LIABLE FOR ANY
 DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
 ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 ==============================================================================*/

#pragma once

#include <ATen/cpu/vec256/intrinsics.h>

#define ptrue svptrue_b8()
#define ALL_S8_TRUE_MASK svdup_n_s8(0xff)
#define ALL_S8_FALSE_MASK svdup_n_s8(0x0)
#define ALL_S16_TRUE_MASK svdup_n_s16(0xffff)
#define ALL_S16_FALSE_MASK svdup_n_s16(0x0)
#define ALL_S32_TRUE_MASK svdup_n_s32(0xffffffff)
#define ALL_S32_FALSE_MASK svdup_n_s32(0x0)
#define ALL_S64_TRUE_MASK svdup_n_s64(0xffffffffffffffff)
#define ALL_S64_FALSE_MASK svdup_n_s64(0x0)
#define ALL_F32_TRUE_MASK svreinterpret_f32_s32(ALL_S32_TRUE_MASK)
#define ALL_F32_FALSE_MASK svreinterpret_f32_s32(ALL_S32_FALSE_MASK)
#define ALL_F64_TRUE_MASK svreinterpret_f64_s64(ALL_S64_TRUE_MASK)
#define ALL_F64_FALSE_MASK svreinterpret_f64_s64(ALL_S64_FALSE_MASK)
