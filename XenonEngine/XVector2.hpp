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

#include "xeTypes.hpp"

template <typename type>
class XVector2 {
public:
	////////////////////////////////////////////////////////////
	/// Standardkonstruktor
	///
	/// Initialisiert den Vektor mit Standardwerten (0)
	////////////////////////////////////////////////////////////
	XAPI XVector2();

	////////////////////////////////////////////////////////////
	/// Kopierkonstruktor
	///
	/// Kopiert die Werte des übergeben Vektors in den neuen
	///
	/// @vector - Zu kopierender Vektor
	////////////////////////////////////////////////////////////
	XAPI XVector2(XVector2<type> & vector);

	////////////////////////////////////////////////////////////
	/// Konstruktor
	///
	/// Initialisiert den Vector mit den übergebenen Werten
	///
	/// @x - x-Komponente des Vektors
	/// @y - y-Komponente des Vektors
	////////////////////////////////////////////////////////////
	XAPI XVector2(type x, type y);

	////////////////////////////////////////////////////////////
	/// Operator=
	///
	/// Weist dem Vektor neue Werte zu
	///
	/// @vector - Referenz auf den Vektor, dessen Werte übernommen werden sollen
	////////////////////////////////////////////////////////////
	XAPI void operator=(XVector2<type> & vector);

	////////////////////////////////////////////////////////////
	/// Operator=
	///
	/// Weist dem Vektor neue Werte zu
	///
	/// @value - Wert, der x und y zugewiesen werden soll
	////////////////////////////////////////////////////////////
	XAPI void operator=(type value);

	////////////////////////////////////////////////////////////
	/// operator+=
	///
	/// Addiert einen Vektor zu diesem hinzu
	///
	/// @vector - Referenz auf den Vektor, der hinzuaddiert werden soll
	////////////////////////////////////////////////////////////
	XAPI void operator+=(XVector2<type> & vector);

	////////////////////////////////////////////////////////////
	/// operator+=
	///
	/// Addiert einen Skalar zu diesem Vektor hinzu
	///
	/// @value - Wert, der x und y hinzuaddiert werden soll
	////////////////////////////////////////////////////////////
	XAPI void operator+=(type value);

	////////////////////////////////////////////////////////////
	/// operator-=
	///
	/// Zieht einen Vektor von diesem ab
	///
	/// @vector - Referenz auf den Vektor, der abgezogen werden soll
	////////////////////////////////////////////////////////////
	XAPI void operator-=(XVector2<type> & vector);

	////////////////////////////////////////////////////////////
	/// operator-=
	///
	/// Zieht einen Skalar von diesem Vektor ab
	///
	/// @value - Wert, der x und y abgezogen werden soll
	////////////////////////////////////////////////////////////
	XAPI void operator-=(type value);


	////////////////////////////////////////////////////////////
	/// Member
	////////////////////////////////////////////////////////////
	type	x;	// x-Komponente des Vektors
	type	y;	// y-Komponente des Vektors
};

////////////////////////////////////////////////////////////////
/// Operatoren
////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////
/// Operator==
/// 
/// Testet zwei Vektoren auf Gleichheit
///
/// @vector1 - Erster Vektor
/// @vector2 - Zweiter Vektor
////////////////////////////////////////////////////////////////
template <typename type>
XAPI XBool_t	operator== (const XVector2<type> & vector1, 
	const XVector2<type> & vector2);

////////////////////////////////////////////////////////////////
/// Operator!=
/// 
/// Testet zwei Vektoren auf Ungleichheit
///
/// @vector1 - Erster Vektor
/// @vector2 - Zweiter Vektor
////////////////////////////////////////////////////////////////
template <typename type>
XAPI XBool_t	operator!= (const XVector2<type> & vector1,
	const XVector2<type> & vector2);

// Definitionen einbinden
#include "XVector2.inl"

////////////////////////////////////////////////////////////////
/// Verschiedene Typedefs für Standardvektoren
////////////////////////////////////////////////////////////////
typedef XVector2<XInt32_t>		XVector2i;	// 32-Bit Integervektor
typedef XVector2<XUint32_t>		XVector2u;	// 32-Bit Vorzeichenloser Integervektor
typedef XVector2<XFloat32_t>	XVector2f;	// 32-Bit Gleitkommavektor


