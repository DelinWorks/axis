/****************************************************************************

Copyright (c) 2019-present Axmol Engine contributors (see AUTHORS.md).

https://axmol.dev/

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in
all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
THE SOFTWARE.
****************************************************************************/

#pragma once

#include "math/Vec4.h"

#if defined(_WIN32)
#    pragma push_macro("TRANSPARENT")
#    undef TRANSPARENT
#endif

NS_AX_MATH_BEGIN

struct Color4B;
struct Color4F;
struct HSV;

/**
 * RGB color composed of bytes 3 bytes.
 * @since v3.0
 */
struct AX_DLL Color3B
{
    Color3B();
    Color3B(uint8_t _r, uint8_t _g, uint8_t _b);
    explicit Color3B(const Color4B& color);
    explicit Color3B(const Color4F& color);

    bool operator==(const Color3B& right) const;
    bool operator==(const Color4B& right) const;
    bool operator==(const Color4F& right) const;
    bool operator!=(const Color3B& right) const;
    bool operator!=(const Color4B& right) const;
    bool operator!=(const Color4F& right) const;

    bool equals(const Color3B& other) const { return (*this == other); }

    uint8_t r = 0;
    uint8_t g = 0;
    uint8_t b = 0;

    static const Color3B WHITE;
    static const Color3B YELLOW;
    static const Color3B BLUE;
    static const Color3B GREEN;
    static const Color3B RED;
    static const Color3B MAGENTA;
    static const Color3B BLACK;
    static const Color3B ORANGE;
    static const Color3B GRAY;
};

/**
 * RGBA color composed of 4 bytes.
 * @since v3.0
 */
struct AX_DLL Color4B
{
    Color4B();
    Color4B(uint8_t _r, uint8_t _g, uint8_t _b, uint8_t _a);
    explicit Color4B(const Color3B& color, uint8_t _a = 255);
    Color4B(const Color4F& color);

    inline void set(uint8_t _r, uint8_t _g, uint8_t _b, uint8_t _a)
    {
        r = _r;
        g = _g;
        b = _b;
        a = _a;
    }

    bool operator==(const Color4B& right) const;
    bool operator==(const Color3B& right) const;
    bool operator==(const Color4F& right) const;
    bool operator!=(const Color4B& right) const;
    bool operator!=(const Color3B& right) const;
    bool operator!=(const Color4F& right) const;

    uint8_t r = 0;
    uint8_t g = 0;
    uint8_t b = 0;
    uint8_t a = 0;

    static const Color4B WHITE;
    static const Color4B YELLOW;
    static const Color4B BLUE;
    static const Color4B GREEN;
    static const Color4B RED;
    static const Color4B MAGENTA;
    static const Color4B BLACK;
    static const Color4B ORANGE;
    static const Color4B GRAY;
    static const Color4B TRANSPARENT;  // TRANSPARENT is defined on wingdi.h /*Background Modes*/
};

/**
 * RGBA color composed of 4 floats.
 * @since v3.0
 */
struct AX_DLL Color4F : public Vec4Base<Color4F>
{
    using Vec4Base = Vec4Base<Color4F>;
    Color4F();
    Color4F(float _r, float _g, float _b, float _a);
    explicit Color4F(const Color3B& color, float _a = 1.0f);
    explicit Color4F(const Color4B& color);

    bool operator==(const Color3B& rhs) const;
    bool operator==(const Color4B& rhs) const;
    bool operator!=(const Color3B& rhs) const;
    bool operator!=(const Color4B& rhs) const;

    bool equals(const Color4F& other) const { return (*this == other); }

    static const Color4F WHITE;
    static const Color4F YELLOW;
    static const Color4F BLUE;
    static const Color4F GREEN;
    static const Color4F RED;
    static const Color4F MAGENTA;
    static const Color4F BLACK;
    static const Color4F ORANGE;
    static const Color4F GRAY;
    static const Color4F TRANSPARENT;  // TRANSPARENT is defined on wingdi.h /*Background Modes*/
};

/**
 * Hue Saturation Value color space composed of 4 floats.
 * @since axmol-1.0.0b7
 *
 * Implementation source: https://gist.github.com/fairlight1337/4935ae72bcbcc1ba5c72
 */
struct AX_DLL HSV : public Vec4Base<HSV>
{
    HSV();
    HSV(float _h, float _s, float _v, float _a = 1.0F);

    explicit HSV(const Color3B& c);
    explicit HSV(const Color4B& c);
    explicit HSV(const Color4F& c);

    bool equals(const HSV& other) const { return (*this == other); }

    void fromRgba(const Color4F& rgba);
    Color4F toRgba() const;

    Color3B toColor3B() const;
    Color4B toColor4B() const;
    Color4F toColor4F() const;
};

/**
 * Hue Saturation Luminance color space composed of 4 floats.
 * @since axmol-1.0.0b7
 *
 * Implementation source: https://gist.github.com/ciembor/1494530
 */
struct AX_DLL HSL : public Vec4Base<HSL>
{
    HSL();
    HSL(float _h, float _s, float _l, float _a = 1.0F);

    explicit HSL(const Color3B& c);
    explicit HSL(const Color4B& c);
    explicit HSL(const Color4F& c);

    bool equals(const HSL& other) const { return (*this == other); }

    void fromRgba(const Color4F& rgba);
    Color4F toRgba() const;

    static float hue2rgb(float p, float q, float t);

    Color3B toColor3B() const;
    Color4B toColor4B() const;
    Color4F toColor4F() const;
};

NS_AX_MATH_END

#if defined(_WIN32)
#    pragma pop_macro("TRANSPARENT")
#endif
