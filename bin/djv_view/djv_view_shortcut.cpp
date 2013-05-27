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

//! \file djv_view_shortcut.cpp

#include <djv_view_shortcut.h>

#include <djv_assert.h>

namespace djv_view
{

//------------------------------------------------------------------------------
// Shortcut
//------------------------------------------------------------------------------

const List<String> & Shortcut::label_shortcut()
{
    static const List<String> data = List<String>() <<
        "Exit" <<

        "File Open" <<
        "File Reload" <<
        "File Save" <<
        "File Save Frame" <<
        "File Close" <<
        "File Layer Default" <<
        "File Layer 1" <<
        "File Layer 2" <<
        "File Layer 3" <<
        "File Layer 4" <<
        "File Layer 5" <<
        "File Layer 6" <<
        "File Layer 7" <<
        "File Layer 8" <<
        "File Layer 9" <<
        "File Layer 10" <<
        "File Layer Previous" <<
        "File Layer Next" <<
        "File Proxy None" <<
        "File Proxy 1/2" <<
        "File Proxy 1/4" <<
        "File Proxy 1/8" <<

        "Window New" <<
        "Window Copy" <<
        "Window Close" <<
        "Window Fit" <<
        "Window Fullscreen" <<
        "Window Toolbar" <<
        "Window Playbar" <<
        "Window Infobar" <<

        "View Left" <<
        "View Right" <<
        "View Up" <<
        "View Down" <<
        "View Center" <<
        "View Zoom In" <<
        "View Zoom Out" <<
        "View Zoom Reset" <<
        "View Reset" <<
        "View Fit" <<
        "View HUD" <<

        "Image Frame Store" <<
        "Image Frame Store Load" <<
        "Image Mirror Horizontal" <<
        "Image Mirror Vertical" <<
        "Image Scale None" <<
        "Image Scale 16:9" <<
        "Image Scale 1.85" <<
        "Image Scale 2.35" <<
        "Image Rotate 0" <<
        "Image Rotate 90" <<
        "Image Rotate 180" <<
        "Image Rotate 270" <<
        "Image Color Profile" <<
        "Image Channel Red" <<
        "Image Channel Green" <<
        "Image Channel Blue" <<
        "Image Channel Alpha" <<
        "Image Display Profile" <<
        "Image Display Profile Reset" <<
        "Image Display Profile 1" <<
        "Image Display Profile 2" <<
        "Image Display Profile 3" <<
        "Image Display Profile 4" <<
        "Image Display Profile 5" <<
        "Image Display Profile 6" <<
        "Image Display Profile 7" <<
        "Image Display Profile 8" <<
        "Image Display Profile 9" <<
        "Image Display Profile 10" <<

        "Playback Stop" <<
        "Playback Forward" <<
        "Playback Reverse" <<
        "Playback Loop" <<
        "Playback Start" <<
        "Playback Start Absolute" <<
        "Playback End" <<
        "Playback End Absolute" <<
        "Playback Previous" <<
        "Playback Previous X10" <<
        "Playback Previous X100" <<
        "Playback Next" <<
        "Playback Next X10" <<
        "Playback Next X100" <<
        "Playback In/Out Points" <<
        "Playback In Point Mark" <<
        "Playback In Point Reset" <<
        "Playback Out Point Mark" <<
        "Playback Out Point Reset" <<

        "Tool Magnify" <<
        "Tool Color Picker" <<
        "Tool Histogram" <<
        "Tool Information";

    DJV_ASSERT(data.size() == _SHORTCUT_SIZE);

    return data;
}

} // djv_view

