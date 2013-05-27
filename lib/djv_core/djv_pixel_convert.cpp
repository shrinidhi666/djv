//------------------------------------------------------------------------------
// Copyright (c) 2004-2012 Darby Johnston
// All rights reserved.
//
// Redistribution and use in source and binary forms, with or without
// modification, are permitted provided that the following conditions are met:
//
// * Redistributions of source code must retain the above copyright notice,
//   this list of conditions, and the following disclaimer.
//
// * Redistributions in binary form must reproduce the above copyright notice,
//   this list of conditions, and the following disclaimer in the documentation
//   and/or other materials provided with the distribution.
//
// * Neither the names of the copyright holders nor the names of any
//   contributors may be used to endorse or promote products derived from this
//   software without specific prior written permission.
//
// THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
// AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
// IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
// ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE
// LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
// CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
// SUBSTITUE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
// INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
// CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
// ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
// POSSIBILITY OF SUCH DAMAGE.
//------------------------------------------------------------------------------

//! \file djv_pixel_convert.cpp

#include <djv_pixel.h>

#include <djv_memory.h>

namespace djv
{

//------------------------------------------------------------------------------
// Format Conversion
//------------------------------------------------------------------------------

// Luminance.

#define _L_L_(IN0, IN_T, OUT0, OUT_T) \
    OUT0 = PIXEL_##IN_T##_TO_##OUT_T(IN0);
#define _L_LA_(IN0, IN_T, OUT0, OUT1, OUT_T) \
    OUT0 = PIXEL_##IN_T##_TO_##OUT_T(IN0); \
    OUT1 = PIXEL_##OUT_T##_ONE;
#define _L_RGB_(IN0, IN_T, OUT0, OUT1, OUT2, OUT_T) \
    OUT0 = OUT1 = OUT2 = PIXEL_##IN_T##_TO_##OUT_T(IN0);
#define _L_RGBA_(IN0, IN_T, OUT0, OUT1, OUT2, OUT3, OUT_T) \
    OUT0 = OUT1 = OUT2 = PIXEL_##IN_T##_TO_##OUT_T(IN0); \
    OUT3 = PIXEL_##OUT_T##_ONE;

#define _L_L(IN, IN_T, OUT, OUT_T) \
    _L_L_(IN[0], IN_T, OUT[0], OUT_T)
#define _L_LA(IN, IN_T, OUT, OUT_T) \
    _L_LA_(IN[0], IN_T, OUT[0], OUT[1], OUT_T)
#define _L_RGB(IN, IN_T, OUT, OUT_T) \
    _L_RGB_(IN[0], IN_T, OUT[0], OUT[1], OUT[2], OUT_T)
#define _L_RGB_U10(IN, IN_T, OUT, OUT_T) \
    _L_RGB_(IN[0], IN_T, OUT->r, OUT->g, OUT->b, OUT_T)
#define _L_RGBA(IN, IN_T, OUT, OUT_T) \
    _L_RGBA_(IN[0], IN_T, OUT[0], OUT[1], OUT[2], OUT[3], OUT_T)

// Luminance alpha.

#define _LA_L_(IN0, IN1, IN_T, OUT0, OUT_T) \
    OUT0 = PIXEL_##IN_T##_TO_##OUT_T(IN0);
#define _LA_LA_(IN0, IN1, IN_T, OUT0, OUT1, OUT_T) \
    OUT0 = PIXEL_##IN_T##_TO_##OUT_T(IN0); \
    OUT1 = PIXEL_##IN_T##_TO_##OUT_T(IN1);
#define _LA_RGB_(IN0, IN1, IN_T, OUT0, OUT1, OUT2, OUT_T) \
    OUT0 = OUT1 = OUT2 = PIXEL_##IN_T##_TO_##OUT_T(IN0);
#define _LA_RGBA_(IN0, IN1, IN_T, OUT0, OUT1, OUT2, OUT3, OUT_T) \
    OUT0 = OUT1 = OUT2 = PIXEL_##IN_T##_TO_##OUT_T(IN0); \
    OUT3 = PIXEL_##IN_T##_TO_##OUT_T(IN1);

#define _LA_L(IN, IN_T, OUT, OUT_T) \
    _LA_L_(IN[0], IN[1], IN_T, OUT[0], OUT_T)
#define _LA_LA(IN, IN_T, OUT, OUT_T) \
    _LA_LA_(IN[0], IN[1], IN_T, OUT[0], OUT[1], OUT_T)
#define _LA_RGB(IN, IN_T, OUT, OUT_T) \
    _LA_RGB_(IN[0], IN[1], IN_T, OUT[0], OUT[1], OUT[2], OUT_T)
#define _LA_RGB_U10(IN, IN_T, OUT, OUT_T) \
    _LA_RGB_(IN[0], IN[1], IN_T, OUT->r, OUT->g, OUT->b, OUT_T)
#define _LA_RGBA(IN, IN_T, OUT, OUT_T) \
    _LA_RGBA_(IN[0], IN[1], IN_T, OUT[0], OUT[1], OUT[2], OUT[3], OUT_T)

// RGB.

#define _RGB_L_(IN0, IN1, IN2, IN_T, OUT0, OUT_T) \
    OUT0 = PIXEL_##IN_T##_TO_##OUT_T((IN0 + IN1 + IN2) / Pixel::IN_T##_T(3));
#define _RGB_LA_(IN0, IN1, IN2, IN_T, OUT0, OUT1, OUT_T) \
    OUT0 = PIXEL_##IN_T##_TO_##OUT_T((IN0 + IN1 + IN2) / Pixel::IN_T##_T(3)); \
    OUT1 = PIXEL_##OUT_T##_ONE;
#define _RGB_RGB_(IN0, IN1, IN2, IN_T, OUT0, OUT1, OUT2, OUT_T) \
    OUT0 = PIXEL_##IN_T##_TO_##OUT_T(IN0); \
    OUT1 = PIXEL_##IN_T##_TO_##OUT_T(IN1); \
    OUT2 = PIXEL_##IN_T##_TO_##OUT_T(IN2);
#define _RGB_RGBA_(IN0, IN1, IN2, IN_T, OUT0, OUT1, OUT2, OUT3, OUT_T) \
    OUT0 = PIXEL_##IN_T##_TO_##OUT_T(IN0); \
    OUT1 = PIXEL_##IN_T##_TO_##OUT_T(IN1); \
    OUT2 = PIXEL_##IN_T##_TO_##OUT_T(IN2); \
    OUT3 = PIXEL_##OUT_T##_ONE;

#define _RGB_L(IN, IN_T, OUT, OUT_T) \
    _RGB_L_(IN[0], IN[1], IN[2], IN_T, OUT[0], OUT_T)
#define _RGB_LA(IN, IN_T, OUT, OUT_T) \
    _RGB_LA_(IN[0], IN[1], IN[2], IN_T, OUT[0], OUT[1], OUT_T)
#define _RGB_RGB(IN, IN_T, OUT, OUT_T) \
    _RGB_RGB_(IN[bgr ? 2 : 0], IN[1], IN[bgr ? 0 : 2], IN_T, \
        OUT[0], OUT[1], OUT[2], OUT_T)
#define _RGB_RGB_U10(IN, IN_T, OUT, OUT_T) \
    _RGB_RGB_(IN[bgr ? 2 : 0], IN[1], IN[bgr ? 0 : 2], IN_T, \
        OUT->r, OUT->g, OUT->b, OUT_T)
#define _RGB_RGBA(IN, IN_T, OUT, OUT_T) \
    _RGB_RGBA_(IN[bgr ? 2 : 0], IN[1], IN[bgr ? 0 : 2], IN_T, \
        OUT[0], OUT[1], OUT[2], OUT[3], OUT_T)

#define _RGB_U10_L(IN, IN_T, OUT, OUT_T) \
    _RGB_L_(IN->r, IN->g, IN->b, IN_T, OUT[0], OUT_T)
#define _RGB_U10_LA(IN, IN_T, OUT, OUT_T) \
    _RGB_LA_(IN->r, IN->g, IN->b, IN_T, OUT[0], OUT[1], OUT_T)
#define _RGB_U10_RGB(IN, IN_T, OUT, OUT_T) \
    _RGB_RGB_(bgr ? IN->b : IN->r, IN->g, bgr ? IN->r : IN->b, IN_T, \
        OUT[0], OUT[1], OUT[2], OUT_T)
#define _RGB_U10_RGBA(IN, IN_T, OUT, OUT_T) \
    _RGB_RGBA_(bgr ? IN->b : IN->r, IN->g, bgr ? IN->r : IN->b, IN_T, \
        OUT[0], OUT[1], OUT[2], OUT[3], OUT_T)

// RGBA.

#define _RGBA_L_(IN0, IN1, IN2, IN3, IN_T, OUT0, OUT_T) \
    OUT0 = PIXEL_##IN_T##_TO_##OUT_T((IN0 + IN1 + IN2) / Pixel::IN_T##_T(3));
#define _RGBA_LA_(IN0, IN1, IN2, IN3, IN_T, OUT0, OUT1, OUT_T) \
    OUT0 = PIXEL_##IN_T##_TO_##OUT_T((IN0 + IN1 + IN2) / Pixel::IN_T##_T(3)); \
    OUT1 = PIXEL_##IN_T##_TO_##OUT_T(IN3);
#define _RGBA_RGB_(IN0, IN1, IN2, IN3, IN_T, OUT0, OUT1, OUT2, OUT_T) \
    OUT0 = PIXEL_##IN_T##_TO_##OUT_T(IN0); \
    OUT1 = PIXEL_##IN_T##_TO_##OUT_T(IN1); \
    OUT2 = PIXEL_##IN_T##_TO_##OUT_T(IN2);
#define _RGBA_RGBA_(IN0, IN1, IN2, IN3, IN_T, OUT0, OUT1, OUT2, OUT3, \
    OUT_T) \
    OUT0 = PIXEL_##IN_T##_TO_##OUT_T(IN0); \
    OUT1 = PIXEL_##IN_T##_TO_##OUT_T(IN1); \
    OUT2 = PIXEL_##IN_T##_TO_##OUT_T(IN2); \
    OUT3 = PIXEL_##IN_T##_TO_##OUT_T(IN3);

#define _RGBA_L(IN, IN_T, OUT, OUT_T) \
    _RGBA_L_(IN[0], IN[1], IN[2], IN[3], IN_T, OUT[0], OUT_T)
#define _RGBA_LA(IN, IN_T, OUT, OUT_T) \
    _RGBA_LA_(IN[0], IN[1], IN[2], IN[3], IN_T, OUT[0], OUT[1], OUT_T)
#define _RGBA_RGB(IN, IN_T, OUT, OUT_T) \
    _RGBA_RGB_(IN[bgr ? 2 : 0], IN[1], IN[bgr ? 0 : 2], IN[3], IN_T, \
        OUT[0], OUT[1], OUT[2], OUT_T)
#define _RGBA_RGB_U10(IN, IN_T, OUT, OUT_T) \
    _RGBA_RGB_(IN[bgr ? 2 : 0], IN[1], IN[bgr ? 0 : 2], IN[3], IN_T, \
        OUT->r, OUT->g, OUT->b, OUT_T)
#define _RGBA_RGBA(IN, IN_T, OUT, OUT_T) \
    _RGBA_RGBA_(IN[bgr ? 2 : 0], IN[1], IN[bgr ? 0 : 2], IN[3], IN_T, \
        OUT[0], OUT[1], OUT[2], OUT[3], OUT_T)

//------------------------------------------------------------------------------
// Functions
//------------------------------------------------------------------------------

namespace
{

#define _FNC_ARGS \
    \
    const void * in, void * out, int size, int stride, bool bgr

typedef void (Fnc)(_FNC_ARGS);

#define _FNC(IN_FORMAT, IN_TYPE, OUT_FORMAT, OUT_TYPE) \
    \
    void _##IN_FORMAT##_##IN_TYPE##_##OUT_FORMAT##_##OUT_TYPE(_FNC_ARGS) \
    { \
        const Pixel::IN_TYPE##_T * in_p = \
            reinterpret_cast<const Pixel::IN_TYPE##_T *>(in); \
        \
        Pixel::OUT_TYPE##_T * out_p = \
            reinterpret_cast<Pixel::OUT_TYPE##_T *>(out); \
        \
        const int in_stride = stride * Pixel::channels(Pixel::IN_FORMAT); \
        const int out_stride = Pixel::channels(Pixel::OUT_FORMAT); \
        \
        for (int i = 0; i < size; ++i, in_p += in_stride, out_p += out_stride) \
        { \
            _##IN_FORMAT##_##OUT_FORMAT(in_p, IN_TYPE, out_p, OUT_TYPE) \
        } \
    }

#define _FNC_DEFINE(OUT_FORMAT, OUT_TYPE) \
    \
    _FNC(L, U8, OUT_FORMAT, OUT_TYPE) \
    _FNC(L, U16, OUT_FORMAT, OUT_TYPE) \
    _FNC(L, F16, OUT_FORMAT, OUT_TYPE) \
    _FNC(L, F32, OUT_FORMAT, OUT_TYPE) \
    _FNC(LA, U8, OUT_FORMAT, OUT_TYPE) \
    _FNC(LA, U16, OUT_FORMAT, OUT_TYPE) \
    _FNC(LA, F16, OUT_FORMAT, OUT_TYPE) \
    _FNC(LA, F32, OUT_FORMAT, OUT_TYPE) \
    _FNC(RGB, U8, OUT_FORMAT, OUT_TYPE) \
    _FNC(RGB, U16, OUT_FORMAT, OUT_TYPE) \
    _FNC(RGB, F16, OUT_FORMAT, OUT_TYPE) \
    _FNC(RGB, F32, OUT_FORMAT, OUT_TYPE) \
    _FNC(RGBA, U8, OUT_FORMAT, OUT_TYPE) \
    _FNC(RGBA, U16, OUT_FORMAT, OUT_TYPE) \
    _FNC(RGBA, F16, OUT_FORMAT, OUT_TYPE) \
    _FNC(RGBA, F32, OUT_FORMAT, OUT_TYPE)

_FNC_DEFINE(L, U8)
_FNC_DEFINE(L, U16)
_FNC_DEFINE(L, F16)
_FNC_DEFINE(L, F32)
_FNC_DEFINE(LA, U8)
_FNC_DEFINE(LA, U16)
_FNC_DEFINE(LA, F16)
_FNC_DEFINE(LA, F32)
_FNC_DEFINE(RGB, U8)
_FNC_DEFINE(RGB, U16)
_FNC_DEFINE(RGB, F16)
_FNC_DEFINE(RGB, F32)
_FNC_DEFINE(RGBA, U8)
_FNC_DEFINE(RGBA, U16)
_FNC_DEFINE(RGBA, F16)
_FNC_DEFINE(RGBA, F32)

void _RGB_U10_RGB_U10(_FNC_ARGS)
{
    const Pixel::U10_S * in_p = reinterpret_cast<const Pixel::U10_S *>(in);

    Pixel::U10_S * out_p = reinterpret_cast<Pixel::U10_S *>(out);

    _RGB_RGB_(
        in_p->r, in_p->g, in_p->b, U10, out_p->r, out_p->g, out_p->b, U10);
}

#define _FNC_RGB_U10(OUT_FORMAT, OUT_TYPE) \
    \
    void _RGB_U10_##OUT_FORMAT##_##OUT_TYPE(_FNC_ARGS) \
    { \
        const Pixel::U10_S * in_p = \
         reinterpret_cast<const Pixel::U10_S *>(in); \
        \
        Pixel::OUT_TYPE##_T * out_p = \
            reinterpret_cast<Pixel::OUT_TYPE##_T *>(out); \
        \
        const int in_stride = stride; \
        const int out_stride = Pixel::channels(Pixel::OUT_FORMAT); \
        \
        for (int i = 0; i < size; ++i, in_p += in_stride, out_p += out_stride) \
        { \
            _RGB_U10_##OUT_FORMAT(in_p, U10, out_p, OUT_TYPE) \
        } \
    }

_FNC_RGB_U10(L, U8)
_FNC_RGB_U10(L, U16)
_FNC_RGB_U10(L, F16)
_FNC_RGB_U10(L, F32)
_FNC_RGB_U10(LA, U8)
_FNC_RGB_U10(LA, U16)
_FNC_RGB_U10(LA, F16)
_FNC_RGB_U10(LA, F32)
_FNC_RGB_U10(RGB, U8)
_FNC_RGB_U10(RGB, U16)
_FNC_RGB_U10(RGB, F16)
_FNC_RGB_U10(RGB, F32)
_FNC_RGB_U10(RGBA, U8)
_FNC_RGB_U10(RGBA, U16)
_FNC_RGB_U10(RGBA, F16)
_FNC_RGB_U10(RGBA, F32)

#define _FNC2_RGB_U10(IN_FORMAT, IN_TYPE) \
    \
    void _##IN_FORMAT##_##IN_TYPE##_RGB_U10(_FNC_ARGS) \
    { \
        const Pixel::IN_TYPE##_T * in_p = \
            reinterpret_cast<const Pixel::IN_TYPE##_T *>(in); \
        \
        Pixel::U10_S * out_p = reinterpret_cast<Pixel::U10_S *>(out); \
        \
        const int in_stride = stride * Pixel::channels(Pixel::IN_FORMAT); \
        \
        for (int i = 0; i < size; ++i, in_p += in_stride, ++out_p) \
        { \
            _##IN_FORMAT##_RGB_U10(in_p, IN_TYPE, out_p, U10) \
        } \
    }

_FNC2_RGB_U10(L, U8)
_FNC2_RGB_U10(L, U16)
_FNC2_RGB_U10(L, F16)
_FNC2_RGB_U10(L, F32)
_FNC2_RGB_U10(LA, U8)
_FNC2_RGB_U10(LA, U16)
_FNC2_RGB_U10(LA, F16)
_FNC2_RGB_U10(LA, F32)
_FNC2_RGB_U10(RGB, U8)
_FNC2_RGB_U10(RGB, U16)
_FNC2_RGB_U10(RGB, F16)
_FNC2_RGB_U10(RGB, F32)
_FNC2_RGB_U10(RGBA, U8)
_FNC2_RGB_U10(RGBA, U16)
_FNC2_RGB_U10(RGBA, F16)
_FNC2_RGB_U10(RGBA, F32)

// Function table.

#define _FNC_TABLE(FORMAT) \
    \
    { \
        _##FORMAT##_L_U8, \
        _##FORMAT##_L_U16, \
        _##FORMAT##_L_F16, \
        _##FORMAT##_L_F32, \
        _##FORMAT##_LA_U8, \
        _##FORMAT##_LA_U16, \
        _##FORMAT##_LA_F16, \
        _##FORMAT##_LA_F32, \
        _##FORMAT##_RGB_U8, \
        _##FORMAT##_RGB_U10, \
        _##FORMAT##_RGB_U16, \
        _##FORMAT##_RGB_F16, \
        _##FORMAT##_RGB_F32, \
        _##FORMAT##_RGBA_U8, \
        _##FORMAT##_RGBA_U16, \
        _##FORMAT##_RGBA_F16, \
        _##FORMAT##_RGBA_F32 \
    }

Fnc * fnc_tbl[Pixel::_PIXEL_SIZE][Pixel::_PIXEL_SIZE] =
{
    _FNC_TABLE(L_U8),
    _FNC_TABLE(L_U16),
    _FNC_TABLE(L_F16),
    _FNC_TABLE(L_F32),
    _FNC_TABLE(LA_U8),
    _FNC_TABLE(LA_U16),
    _FNC_TABLE(LA_F16),
    _FNC_TABLE(LA_F32),
    _FNC_TABLE(RGB_U8),
    _FNC_TABLE(RGB_U10),
    _FNC_TABLE(RGB_U16),
    _FNC_TABLE(RGB_F16),
    _FNC_TABLE(RGB_F32),
    _FNC_TABLE(RGBA_U8),
    _FNC_TABLE(RGBA_U16),
    _FNC_TABLE(RGBA_F16),
    _FNC_TABLE(RGBA_F32)
};

} // namespace

//------------------------------------------------------------------------------
// Pixel::convert
//------------------------------------------------------------------------------

void Pixel::convert(
    const void * in,
    PIXEL        in_pixel,
    void *       out,
    PIXEL        out_pixel,
    int          size,
    int          stride,
    bool         bgr)
{
    //DJV_DEBUG("Pixel::convert");
    //DJV_DEBUG_PRINT("in = " << in_pixel);
    //DJV_DEBUG_PRINT("out = " << out_pixel);
    //DJV_DEBUG_PRINT("size = " << size);
    //DJV_DEBUG_PRINT("stride = " << stride);
    //DJV_DEBUG_PRINT("bgr = " << bgr);

    if (in_pixel == out_pixel && 1 == stride && ! bgr)
    {
        Memory::copy(in, out, size * bytes(out_pixel));
    }
    else
    {
        fnc_tbl[in_pixel][out_pixel](in, out, size, stride, bgr);
    }
}

} // djv

