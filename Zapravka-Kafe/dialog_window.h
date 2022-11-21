#pragma once
#include "header.h"

class Zapravka_dialog
{
public:
	Zapravka_dialog(void);
	Zapravka_dialog(LPCTSTR lpStr);
public:
	~Zapravka_dialog(void);
	static BOOL CALLBACK DlgProc(HWND hWnd, UINT mes, WPARAM wp, LPARAM lp);
	static Zapravka_dialog* ptr;
	BOOL Cls_OnInitDialog(HWND hwnd, HWND hwndFocus, LPARAM lParam);
	void Cls_OnCommand(HWND hwnd, int id, HWND hwndCtl, UINT codeNotify);
	void Cls_OnClose(HWND hwnd);
	TCHAR text[200];
	HWND hEdit, hStatic;
};