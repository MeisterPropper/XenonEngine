#include "XWindow.hpp"
#include "XApplication.hpp"

XWindow::XWindow(){
	// Fensterklasse erstellen
	classEx_ = nullptr;
	createWindowClass(classEx_);

	// Position und Gr��e des Fensters eintragen
	xpos_ = static_cast<XUint16_t>(CW_USEDEFAULT);
	ypos_ = static_cast<XUint16_t>(CW_USEDEFAULT);
	width_ = 800;
	height_ = 600;

	// Fenster erstellen
	handle_ = nullptr;
	createWindowHandle(handle_, xpos_, ypos_, width_, height_, this);

	isOpen_ = true;
}

XWindow::XWindow(XWindow & window){
	// Werte �bernehmen
	classEx_ = new WNDCLASSEX(*window.classEx_);

	// �berpr�fen, ob die Fensterklasse korrekt kopiert wurde
	if (!classEx_) {
		// Wenn nicht, eine entsprechende 
		// Messagebox aufrufen
		MessageBoxA(nullptr,
			"Fehler beim Kopieren des Fensters",
			"Kritischer Fehler",
			MB_OK | MB_ICONERROR);
		return;
	}

	// Werte �bernehmen
	handle_ = window.handle_;

	// �berpr�fen, ob das Fenster korrekt kopiert wurde
	if (!handle_) {
		// Wenn nicht, eine entsprechende 
		// Messagebox aufrufen
		MessageBoxA(nullptr,
			"Fehler beim Kopieren des Fensters",
			"Kritischer Fehler",
			MB_OK | MB_ICONERROR);
		return;
	}

	isOpen_ = true;
}

XWindow::XWindow(XUint16_t xpos, XUint16_t ypos, XUint16_t width, XUint16_t height, char * title){
	// Fensterklasse erstellen
	classEx_ = nullptr;
	createWindowClass(classEx_);

	// Position und Gr��e des Fensters eintragen
	xpos_ = xpos;
	ypos_ = ypos;
	width_ = width;
	height_ = height;

	// Fenster erstellen
	handle_ = nullptr;
	createWindowHandle(handle_, xpos_, ypos_, width_, height_, this);

	isOpen_ = true;
}

XWindow::~XWindow(){
	// Zerst�ren des Fensters
	DestroyWindow(handle_);
}

void XWindow::show(){
	// Zeigt das Fenster
	ShowWindow(handle_, g_pApplication->getCmdShow());
	// Updated das Fenster
	UpdateWindow(handle_);
}

XAPI void XWindow::close(){
	// Das Fenster ist nicht mehr offen
	isOpen_ = false;
	// Fenster zerst�ren
	DestroyWindow(handle_);
}

XAPI void XWindow::processMessages(){
	// Bearbeiten der letzten Nachricht
	GetMessage(&message_, handle_, 0, 0);
	TranslateMessage(&message_);
	DispatchMessage(&message_);
}

XAPI LRESULT XWindow::processEvents(UINT message, WPARAM wParam, LPARAM lParam){
	switch (message) {
	case WM_CLOSE: {
		isOpen_ = false;
	}break;
	case WM_DESTROY: {
		
	}break;
	}
	return LRESULT(0);
}

LRESULT XWindow::callBack(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	// Wenn das Fenster erstellt wird, das Handle mit dem Fenster (XWindow) verkn�pfen
	if (message == WM_CREATE)
	{
		// Die Instanz des XWindows zwischenspeichern, die als letzter Parameter an CreateWindow �bergeben wurde
		LONG_PTR window = (LONG_PTR)reinterpret_cast<CREATESTRUCT*>(lParam)->lpCreateParams;

		// Die Instanz als die "User_Data" setzen
		SetWindowLongPtrW(hWnd, GWLP_USERDATA, window);
	}
	// Das zum Handle geh�rende Fenster
	XWindow * window = hWnd ? reinterpret_cast<XWindow*>(GetWindowLongPtr(hWnd, GWLP_USERDATA)) : nullptr;

	if (window) {
		window->processEvents(message, wParam, lParam);
	}

	switch (message) {
	case WM_CLOSE: {
		DestroyWindow(hWnd);
	}break;
	case WM_DESTROY: {
		PostQuitMessage(0);
	}break;
	default: {
		return DefWindowProc(hWnd, message, wParam, lParam);
	}
	}
	return LRESULT(0);
}

XAPI XResult_t createWindowClass(WNDCLASSEX *& wndclass){
	// Neue WindowClass erstellen
	wndclass = new WNDCLASSEX();

	// Zuweisung der Standardwerte
	wndclass->cbSize = sizeof(WNDCLASSEX);
	wndclass->style = 0;
	wndclass->lpfnWndProc = &XWindow::callBack;
	wndclass->cbClsExtra = 0;
	wndclass->cbWndExtra = 0;
	wndclass->hInstance = g_pApplication->getInstance();
	wndclass->hIcon = LoadIcon(nullptr, IDI_APPLICATION);
	wndclass->hCursor = LoadCursor(nullptr, IDC_ARROW);
	wndclass->hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
	wndclass->lpszMenuName = 0;
	wndclass->lpszClassName = L"StdWindow";
	wndclass->hIconSm = LoadIcon(nullptr, IDI_APPLICATION);

	// Die Fensterklasse registrieren
	if (!RegisterClassEx(wndclass)) {
		// Sollte etwas schiefgehen, eine entsprechende 
		// Messagebox aufrufen
		MessageBoxA(nullptr,
			"Fehler beim Erstellen des Fensters",
			"Kritischer Fehler",
			MB_OK | MB_ICONERROR);
		return XResult_t(-1);
	}

	return XResult_t(0);
}

XAPI XResult_t createWindowHandle(HWND & hWnd, XUint16_t xpos, XUint16_t ypos, XUint16_t width, XUint16_t height, XWindow * window){
	// Fenster erstellen
	hWnd = CreateWindowEx(WS_EX_CLIENTEDGE,
		L"StdWindow",
		L"Standardfenster",
		WS_OVERLAPPEDWINDOW,
		xpos, ypos,
		width, height,
		nullptr,
		nullptr,
		g_pApplication->getInstance(),
		window);

	// �berpr�fen, ob das Fenster korrekt erstellt wurde
	if (!hWnd) {
		// Wenn nicht, eine entsprechende 
		// Messagebox aufrufen
		MessageBoxA(nullptr,
			"Fehler beim Erstellen des Fensters",
			"Kritischer Fehler",
			MB_OK | MB_ICONERROR);
		return XResult_t(-1);
	}

	return XResult_t(0);
}
