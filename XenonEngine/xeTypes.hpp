/// The MIT License (MIT)
///
/// Copyright (c) 2015 Luc Arne Wengoborski
///
/// Permission is hereby granted, free of charge, to any person obtaining a copy
/// of this software and associated documentation files (the "Software"), to deal
/// in the Software without restriction, including without limitation the rights
/// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
/// copies of the Software, and to permit persons to whom the Software is
/// furnished to do so, subject to the following conditions:
///
/// The above copyright notice and this permission notice shall be included in all
/// copies or substantial portions of the Software.

/// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
/// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
/// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
/// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
/// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
/// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
/// SOFTWARE.

#pragma once

/// Typdefinitionen

// Vorzeichenloser 8-Bit Integer
typedef unsigned __int8	 XUint8_t;
// Vorzeichenbehafteter 8-Bit Integer
typedef   signed __int8  XInt8_t;
// Vorzeichenloser 16-Bit Integer
typedef unsigned __int16 XUint16_t;
// Vorzeichenbehafteter 16-Bit Integer
typedef   signed __int16 XInt16_t;
// Vorzeichenloser 32-Bit Integer
typedef unsigned __int32 XUint32_t;
// Vorzeichenbehafteter 32-Bit Integer
typedef   signed __int32 XInt32_t;
// Vorzeichenloser 64-Bit Integer
typedef unsigned __int64 XUint64_t;
// Vorzeichenbehafteter 64-Bit Integer
typedef   signed __int64 XInt64_t;

// 32-Bit Gleitkomma (Einfache Genauigkeit)
// Präzision: 7 - 8 Stellen
typedef float		XFloat32_t;
// 64-Bit Gleitkomma (Doppelte Genauigkeit)
// Präzision: 15 - 16 Stellen
typedef double		XFloat64_t;
// 80-Bit Gleitkomma (Erweiterte Genauigkeit)
// Präzision: 19 - 20 Stellen
typedef long double XFloat80_t;

// Bool
typedef bool			XBool_t;
// Char
typedef unsigned char	XChar_t;
// Byte
typedef unsigned __int8 XByte_t;
// Rückgabetyp
typedef long			XResult_t;

/// Makros

#define XDLL_EXPORT

#ifdef XDLL_EXPORT
// Dllexport
#define XAPI __declspec(dllexport)
#else
// Dllimport
#define XAPI __declspec(dllimport)
#endif

#ifdef XCALL_STD
// Stdcall
#define XCALL _stdcall
#elif XCALL_FAST
// Fastcall
#define XCALL _fastcall
#elif XCALL_VECTOR
// Vectorcall
#define XCALL _vectorcall
#else
// CDecl
#define XCALL _cdecl
#endif





