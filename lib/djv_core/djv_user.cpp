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

//! \file djv_user.cpp

#include <djv_user.h>

#if defined(DJV_WINDOWS)
#include <windows.h>
#else
#include <pwd.h>
#include <unistd.h>
#endif

namespace djv
{

//------------------------------------------------------------------------------
// User
//------------------------------------------------------------------------------

String User::current()
{
    String out;

#if defined(DJV_WINDOWS)

    //! \todo TCHAR conversion?

    TCHAR tmp [cstring_size] = { 0 };
    DWORD size = cstring_size;
    ::GetUserName(tmp, &size);
    out = String(tmp);

#else // DJV_WINDOWS

    out = uid_to_string(::getuid());

#endif // DJV_WINDOWS

    return out;
}

String User::uid_to_string(uid_t in)
{
    String out;

#if ! defined(DJV_WINDOWS)

    struct passwd * buf = ::getpwuid(in);

    if (buf)
    {
        out = buf->pw_name;
    }

#endif // ! DJV_WINDOWS

    return out;
}

} // djv

