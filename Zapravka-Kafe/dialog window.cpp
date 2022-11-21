#include "dialog_window.h"

Zapravka_dialog* Zapravka_dialog::ptr = NULL;

Zapravka_dialog::Zapravka_dialog(void)
{
	ptr = this;
}

Zapravka_dialog::Zapravka_dialog(LPCTSTR lpStr)
{
	ptr = this;
	_tcscpy(text, lpStr);
}

Zapravka_dialog::~Zapravka_dialog(void)
{

}

void Zapravka_dialog::Cls_OnClose(HWND hwnd)
{
	EndDialog(hwnd, IDCANCEL);
}

BOOL Zapravka_dialog::Cls_OnInitDialog(HWND hwnd, HWND hwndFocus, LPARAM lParam)
{
	hEdit = GetDlgItem(hwnd, IDC_EDIT1);
	hStatic = GetDlgItem(hwnd, IDC_STATIC1);
	// Переданные от главного диалога данные отображаются на статике
	SetWindowText(hStatic, text);
	SetWindowText(hwnd, TEXT("Заправка"));
	SetWindowText(hEdit, TEXT("Передает цену!"));
	return TRUE;
}


void Zapravka_dialog::Cls_OnCommand(HWND hwnd, int id, HWND hwndCtl, UINT codeNotify)
{
	if (id == IDOK)
	{
		TCHAR buffer[200];
		GetWindowText(hEdit, buffer, 200);
		_tcscpy(text, buffer);
		HWND hParent = GetParent(hwnd);
		// Передача данных главному диалогу
		SetWindowText(hParent, TEXT("Кафе!"));
		EndDialog(hwnd, IDOK);
	}
	else if (id == IDCANCEL)
	{
		EndDialog(hwnd, IDCANCEL);
	}
}

BOOL CALLBACK Zapravka_dialog::DlgProc(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	switch (message)
	{
		HANDLE_MSG(hwnd, WM_CLOSE, ptr->Cls_OnClose);
		HANDLE_MSG(hwnd, WM_INITDIALOG, ptr->Cls_OnInitDialog);
		HANDLE_MSG(hwnd, WM_COMMAND, ptr->Cls_OnCommand);
	}
	return FALSE;
}
