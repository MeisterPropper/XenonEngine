#include "XApplication.hpp"

XApplication * g_pApplication = nullptr;

///////////////////////////////////////////////////////////////////////////////////////////////////
XApplication::XApplication(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow){
	hInstance_ = hInstance;
	hPrevInstance_ = hPrevInstance;
	lpCmdLine_ = lpCmdLine_;
	nCmdShow_ = nCmdShow;
}

///////////////////////////////////////////////////////////////////////////////////////////////////
XAPI XResult_t main_t(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow){
	// Neue Instanz der Anwendung erstellen
	g_pApplication = new XApplication(hInstance, hPrevInstance, lpCmdLine, nCmdShow);
	
	// Prüfen, ob alles geklappt hat
	if (!g_pApplication) {
		// Wenn nicht, dann melden und mit Fehlercode zurück
		MessageBoxA(nullptr,
			"Fehler beim Instanziieren der Anwendung",
			"Kritischer Fehler",
			MB_OK | MB_ICONERROR);
		return XResult_t(-1);
	}

	// Alles hat geklappt
	return XResult_t(0);
}
