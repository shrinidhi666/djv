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

//! \file djv_error.h

#ifndef DJV_ERROR_H
#define DJV_ERROR_H

#include <djv_list.h>
#include <djv_string.h>

namespace djv
{

//------------------------------------------------------------------------------
//! \class Error
//!
//! This class provides the base exception class.
//------------------------------------------------------------------------------

class DJV_CORE_EXPORT Error
{
public:

    //! Constructor.

    Error();

    //! Constructor.

    Error(const String &);

    //! Constructor.

    Error(const String & prefix, const String &);

    //! Get the error string.

    const String & string() const;

    operator String () const;

private:

    String _value;
};

//------------------------------------------------------------------------------
//! \struct Error_Util
//!
//! This struct provides error utilities.
//------------------------------------------------------------------------------

struct DJV_CORE_EXPORT Error_Util
{
    //! Convert an error into a printable format.

    static String format(const Error &);

    //! Print an error to the console.

    static void print(const Error &);

    //! Return the last system error (Windows specific).

    static String last_error();

    static const String
    error_format;
};

} // djv

#endif // DJV_ERROR_H

