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

//! \file djv_view_shortcut.h

#ifndef DJV_VIEW_SHORTCUT_H
#define DJV_VIEW_SHORTCUT_H

#include <djv_string.h>

#if defined(DJV_WINDOWS)
#undef FILE_OPEN //! \todo Windows name-space pollution.
#endif

namespace djv_view
{
using namespace djv;

//------------------------------------------------------------------------------
//! \class Shortcut
//!
//! This class provides keyboard shortcuts.
//------------------------------------------------------------------------------

class Shortcut
{
public:

    //! Keyboard shortcuts.

    enum SHORTCUT
    {
        EXIT,

        FILE_OPEN,
        FILE_RELOAD,
        FILE_SAVE,
        FILE_SAVE_FRAME,
        FILE_CLOSE,
        FILE_LAYER_DEFAULT,
        FILE_LAYER_1,
        FILE_LAYER_2,
        FILE_LAYER_3,
        FILE_LAYER_4,
        FILE_LAYER_5,
        FILE_LAYER_6,
        FILE_LAYER_7,
        FILE_LAYER_8,
        FILE_LAYER_9,
        FILE_LAYER_10,
        FILE_LAYER_PREV,
        FILE_LAYER_NEXT,
        FILE_PROXY_NONE,
        FILE_PROXY_1_2,
        FILE_PROXY_1_4,
        FILE_PROXY_1_8,

        WINDOW_NEW,
        WINDOW_COPY,
        WINDOW_CLOSE,
        WINDOW_FIT,
        WINDOW_FULLSCREEN,
        WINDOW_TOOLBAR_BUTTONS,
        WINDOW_TOOLBAR_PLAYBACK,
        WINDOW_TOOLBAR_INFO,

        VIEW_LEFT,
        VIEW_RIGHT,
        VIEW_UP,
        VIEW_DOWN,
        VIEW_CENTER,
        VIEW_ZOOM_IN,
        VIEW_ZOOM_OUT,
        VIEW_ZOOM_RESET,
        VIEW_RESET,
        VIEW_FIT,
        VIEW_HUD,

        IMAGE_FRAME_STORE,
        IMAGE_FRAME_STORE_LOAD,
        IMAGE_MIRROR_HORIZONTAL,
        IMAGE_MIRROR_VERTICAL,
        IMAGE_SCALE_NONE,
        IMAGE_SCALE_16_9,
        IMAGE_SCALE_1_85,
        IMAGE_SCALE_2_35,
        IMAGE_ROTATE_0,
        IMAGE_ROTATE_90,
        IMAGE_ROTATE_180,
        IMAGE_ROTATE_270,
        IMAGE_COLOR_PROFILE,
        IMAGE_CHANNEL_RED,
        IMAGE_CHANNEL_GREEN,
        IMAGE_CHANNEL_BLUE,
        IMAGE_CHANNEL_ALPHA,
        IMAGE_DISPLAY_PROFILE,
        IMAGE_DISPLAY_PROFILE_RESET,
        IMAGE_DISPLAY_PROFILE_1,
        IMAGE_DISPLAY_PROFILE_2,
        IMAGE_DISPLAY_PROFILE_3,
        IMAGE_DISPLAY_PROFILE_4,
        IMAGE_DISPLAY_PROFILE_5,
        IMAGE_DISPLAY_PROFILE_6,
        IMAGE_DISPLAY_PROFILE_7,
        IMAGE_DISPLAY_PROFILE_8,
        IMAGE_DISPLAY_PROFILE_9,
        IMAGE_DISPLAY_PROFILE_10,

        PLAYBACK_STOP,
        PLAYBACK_FORWARD,
        PLAYBACK_REVERSE,
        PLAYBACK_LOOP,
        PLAYBACK_START,
        PLAYBACK_START_ABS,
        PLAYBACK_END,
        PLAYBACK_END_ABS,
        PLAYBACK_PREV,
        PLAYBACK_PREV_X10,
        PLAYBACK_PREV_X100,
        PLAYBACK_NEXT,
        PLAYBACK_NEXT_X10,
        PLAYBACK_NEXT_X100,
        PLAYBACK_IN_OUT,
        PLAYBACK_IN_MARK,
        PLAYBACK_IN_RESET,
        PLAYBACK_OUT_MARK,
        PLAYBACK_OUT_RESET,

        TOOL_MAGNIFY,
        TOOL_COLOR_PICKER,
        TOOL_HISTOGRAM,
        TOOL_INFO,

        _SHORTCUT_SIZE
    };

    //! Get the shortcut labels.

    static const List<String> & label_shortcut();
};

} // djv_view

#endif // DJV_VIEW_SHORTCUT_H

