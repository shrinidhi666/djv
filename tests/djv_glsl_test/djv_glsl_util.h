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

//! \file djv_glsl_util.h

#ifndef DJV_GLSL_UTIL_H
#define DJV_GLSL_UTIL_H

#include <djv_gl.h>
#include <djv_pixel_data.h>

#include <djv_error.h>

namespace djv_glsl_test
{
using namespace djv;

class Texture;

//------------------------------------------------------------------------------
// Offscreen
//------------------------------------------------------------------------------

class Offscreen
{
public:

    Offscreen();

    ~Offscreen();

    void init() throw (Error);

    void bind();

    static void unbind();

    void set(const Texture &);

private:

    GLuint _id;
};

//------------------------------------------------------------------------------
// Shader
//------------------------------------------------------------------------------

class Shader
{
public:

    Shader();

    ~Shader();

    void init(const String &) throw (Error);

    void bind();

    static void unbind();

    GLuint program() const;

private:

    void del();

    GLuint _vertex;
    GLuint _fragment;
    GLuint _program;
};

//------------------------------------------------------------------------------
// Texture
//------------------------------------------------------------------------------

class Texture
{
public:

    Texture();

    ~Texture();

    void init(
        const Pixel_Data_Info &,
        GLenum min = GL_LINEAR,
        GLenum mag = GL_LINEAR) throw (Error);

    void init(
        const Pixel_Data &,
        GLenum min = GL_LINEAR,
        GLenum mag = GL_LINEAR) throw (Error);

    void copy(const Pixel_Data &);

    void copy(const Pixel_Data &, const Box2i &);

    void copy(const V2i &);

    void bind();

    const Pixel_Data_Info & info() const;

    GLenum min() const;

    GLenum mag() const;

    GLuint id() const;

private:

    void del();

    Pixel_Data_Info _info;
    GLenum          _min;
    GLenum          _mag;
    GLuint          _id;
};

//------------------------------------------------------------------------------
// Kernel
//------------------------------------------------------------------------------

class Kernel
{
public:

    Kernel();

    void init(int size);

    const String & src() const;

    //void size(int);

    void value(GLuint, const float *);

    void offset(GLuint, const float *);

private:

    int    _size;
    String _src;
};

//------------------------------------------------------------------------------
// Util
//------------------------------------------------------------------------------

struct Util
{
    static void quad(const Pixel_Data_Info &);
};

} // djv_glsl_test

#endif // DJV_GLSL_UTIL_H
