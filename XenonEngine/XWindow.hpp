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

#include <Windows.h>

#include "xeTypes.hpp"

class XWindow {
public:
	////////////////////////////////////////////////////////////
	/// Standardkonstruktor
	///
	/// Erstellt ein Fenster mit Standardeinstellungen
	////////////////////////////////////////////////////////////
	XAPI XWindow();

	////////////////////////////////////////////////////////////
	/// Kopierkonstruktor
	/// 
	/// Erstellt ein neues Fenster mit den Werten des zu kopierenden Fensters
	///
	/// @window - Referenz auf das zu kopierende Fenster
	////////////////////////////////////////////////////////////
	XAPI XWindow(XWindow & window);

	////////////////////////////////////////////////////////////
	/// Konstruktor
	///
	/// Erstellt ein neues Fenster mit den übergebenen Werten
	///
	/// @xpos	- Position des Fensters auf der X-Achse
	/// @ypos	- Position des Fensters auf der Y-Achse
	/// @width	- Breite des Fensters
	/// @height - Höhe des Fensters
	/// @title	- Titel des Fensters
	////////////////////////////////////////////////////////////
	XAPI XWindow(XUint16_t xpos, XUint16_t ypos, XUint16_t width, XUint16_t height, char* title);

	////////////////////////////////////////////////////////////
	/// Destruktor
	///
	/// Zerstört das Fenster und löscht allen Speicher
	////////////////////////////////////////////////////////////
	XAPI ~XWindow();

	////////////////////////////////////////////////////////////
	/// show()
	///
	/// Zeigt den aktuellen Inhalt des Fensters
	////////////////////////////////////////////////////////////
	XAPI void show();

	////////////////////////////////////////////////////////////
	/// close()
	/// 
	/// Schließt das Fenster
	////////////////////////////////////////////////////////////
	XAPI void close();

	////////////////////////////////////////////////////////////
	/// isOpen()
	///
	/// Gibt an, ob das Fenster noch offen ist
	////////////////////////////////////////////////////////////
	XAPI XBool_t isOpen() { return isOpen_; }

	////////////////////////////////////////////////////////////
	/// processMessages()
	///
	/// Verarbeitet die Nachrichten des Fensters
	////////////////////////////////////////////////////////////
	XAPI void processMessages();
	
private:
	WNDCLASSEX*	classEx_;	// Fensterklasse
	HWND		handle_;	// Fensterhandle
	MSG			message_;	// Nachrichten

	XUint16_t xpos_;
	XUint16_t ypos_;
	XUint16_t width_;
	XUint16_t height_;

	XBool_t	  isOpen_;

	// Callback
	static LRESULT CALLBACK callBack(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);

	friend XAPI XResult_t createWindowClass(WNDCLASSEX*& wndclass);

	////////////////////////////////////////////////////////////
	/// processEvents()
	///
	/// Verarbeitet die Nachrichten des Fensters
	///
	/// @message - Nachricht
	/// @wParam  - WPARAM
	/// @lParam  - LPARAM
	////////////////////////////////////////////////////////////
	XAPI LRESULT processEvents(UINT message, WPARAM wParam, LPARAM lParam);
};



////////////////////////////////////////////////////////////////
/// createWindowClass()
///
/// Erstellt eine Fensterklasse
///
/// @wndclass - Zeiger auf WNDCLASSEX-Referenz, die ausgefüllt werden soll
///				sollte auf Null zeigen
///
////////////////////////////////////////////////////////////////
XAPI XResult_t createWindowClass(WNDCLASSEX*& wndclass);

////////////////////////////////////////////////////////////////
/// createWindowHandle()
///
/// Erstellt ein Fenster 
///
/// @hWnd	- Referenz auf das Handle das ausgefüllt werden soll
/// @xpos	- XPosition des Fensters
/// @ypos	- YPosition des Fensters
/// @width	- Breite des Fensters
/// @height - Höhe des Fensters
///
////////////////////////////////////////////////////////////////
XAPI XResult_t createWindowHandle(HWND& hWnd, XUint16_t xpos,
	XUint16_t ypos, XUint16_t width, XUint16_t height, XWindow *);

