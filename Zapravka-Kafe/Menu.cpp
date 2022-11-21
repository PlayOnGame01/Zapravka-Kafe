#include "resource.h"
#include "dialog_window.h"
#include "dialog_window.h"

BOOL CALLBACK DlgProc(HWND, UINT, WPARAM, LPARAM);
Zapravka_dialog* Zapravka_dialog::ptr = NULL;

Zapravka_dialog::Zapravka_dialog(void)
{
	ptr = this;
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
	hEdit1 = GetDlgItem(hwnd, IDC_EDIT1);
	hStatic1 = GetDlgItem(hwnd, IDC_STATIC1);
	hEdit2 = GetDlgItem(hwnd, IDC_EDIT2);
	hStatic2 = GetDlgItem(hwnd, IDC_STATIC2);
	SetWindowText(hEdit1, TEXT("Заправка!"));
	SetWindowText(hEdit2, TEXT("Кафе!"));
	return TRUE;
}


void Zapravka_dialog::Cls_OnCommand(HWND hwnd, int id, HWND hwndCtl, UINT codeNotify)
{
	if (id == IDC_BUTTON1)
	{
		Zapravka_dialog dlg;
		TCHAR buffer[200];
		GetWindowText(hEdit1, buffer, 200);		
		_tcscpy(dlg.text, buffer);
		INT_PTR result = DialogBox(GetModuleHandle(NULL), MAKEINTRESOURCE(IDD_DIALOG1), hwnd, Zapravka_dialog::DlgProc);
		if (result == IDOK)
		{
			SetWindowText(hStatic1, dlg.text);
		}
	}
	else if (id == IDC_BUTTON2)
	{
		TCHAR buffer[200];
		GetWindowText(hEdit2, buffer, 200);
		Zapravka_dialog dlg(buffer);
		INT_PTR result = DialogBox(GetModuleHandle(NULL), MAKEINTRESOURCE(IDD_DIALOG2), hwnd, Zapravka_dialog::DlgProc);
		if (result == IDOK)
		{
			SetWindowText(hStatic2, dlg.text);
		}
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