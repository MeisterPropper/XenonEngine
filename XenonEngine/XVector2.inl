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

////////////////////////////////////////////////////////////////
/// Enthält alle Definitionen der in XVector2 deklarierten Templatemethoden
///
/// Vom Build ausgeschlossen
////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////////////////////////
template <typename type>
XVector2<type>::XVector2() {
	x = 0;
	y = 0;
}

///////////////////////////////////////////////////////////////////////////////////////////////////
template<typename type>
XVector2<type>::XVector2(XVector2<type> & vector){
	x = vector.x;
	y = vector.y;
}

///////////////////////////////////////////////////////////////////////////////////////////////////
template<typename type>
XVector2<type>::XVector2(type x, type y){
	this.x = x;
	this.y = y;
}

///////////////////////////////////////////////////////////////////////////////////////////////////
template<typename type>
void XVector2<type>::operator=(XVector2<type> & vector){
	x = vector.x;
	y = vector.y;
}

///////////////////////////////////////////////////////////////////////////////////////////////////
template<typename type>
void XVector2<type>::operator=(type value){
	x = value;
	y = value;
}

///////////////////////////////////////////////////////////////////////////////////////////////////
template<typename type>
void XVector2<type>::operator+=(XVector2<type>& vector){
	x += vector.x;
	y += vector.y;
}

///////////////////////////////////////////////////////////////////////////////////////////////////
template<typename type>
void XVector2<type>::operator+=(type value){
	x += value;
	y += value;
}

///////////////////////////////////////////////////////////////////////////////////////////////////
template<typename type>
void XVector2<type>::operator-=(XVector2<type>& vector){
	x -= vector.x;
	y -= vector.y;
}

///////////////////////////////////////////////////////////////////////////////////////////////////
template<typename type>
void XVector2<type>::operator-=(type value){
	x -= value;
	y -= value;
}

///////////////////////////////////////////////////////////////////////////////////////////////////
template <typename type>
XAPI XBool_t	operator== (const XVector2<type> & vector1,
	const XVector2<type> & vector2) {
	return (vector1.x == vector2.x &&
		vector1.y == vector2.y) ? true : false;
}

///////////////////////////////////////////////////////////////////////////////////////////////////
template <typename type>
XAPI XBool_t	operator!= (const XVector2<type> & vector1,
	const XVector2<type> & vector2) {
	return (vector1.x == vector2.x &&
		vector1.y == vector2.y) ? false : true;
}