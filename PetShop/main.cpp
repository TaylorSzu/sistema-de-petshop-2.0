#include <windows.h>
#include <commctrl.h>
#include <stdio.h>
#include "resource.h"

HINSTANCE hInst;

#define menu 101
#define cadastro 102
#define pedidos 103
#define servicos 104
#define relatorios 105
#define retangCadastro 106
#define CADASTRO_DO_PET 107
#define RACA 108
#define barraTexto1 109
#define retangPedido 110

BOOL butoes_visiveis = FALSE;

BOOL CALLBACK DlgMain(HWND hwndDlg, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
    switch(uMsg)
    {
    case WM_INITDIALOG:
    {
        ShowWindow(GetDlgItem(hwndDlg, cadastro), SW_HIDE);
        ShowWindow(GetDlgItem(hwndDlg, pedidos), SW_HIDE);
        ShowWindow(GetDlgItem(hwndDlg, servicos), SW_HIDE);
        ShowWindow(GetDlgItem(hwndDlg, relatorios), SW_HIDE);
        ShowWindow(GetDlgItem(hwndDlg, retangCadastro), SW_HIDE);
        ShowWindow(GetDlgItem(hwndDlg, CADASTRO_DO_PET), SW_HIDE);
        ShowWindow(GetDlgItem(hwndDlg, barraTexto1), SW_HIDE);
        ShowWindow(GetDlgItem(hwndDlg, RACA), SW_HIDE);
        ShowWindow(GetDlgItem(hwndDlg, retangPedido), SW_HIDE);
    }
    return TRUE;

    case WM_CLOSE:
    {
        EndDialog(hwndDlg, 0);
    }
    return TRUE;

    case WM_COMMAND:
    {
        switch(LOWORD(wParam))
        {
            case menu:
            {
                butoes_visiveis = !butoes_visiveis;
                ShowWindow(GetDlgItem(hwndDlg, cadastro), butoes_visiveis ? SW_SHOW : SW_HIDE);
                ShowWindow(GetDlgItem(hwndDlg, pedidos), butoes_visiveis ? SW_SHOW : SW_HIDE);
                ShowWindow(GetDlgItem(hwndDlg, servicos), butoes_visiveis ? SW_SHOW : SW_HIDE);
                ShowWindow(GetDlgItem(hwndDlg, relatorios), butoes_visiveis ? SW_SHOW : SW_HIDE);
                break;
            }
            case cadastro:
            {
                butoes_visiveis = !butoes_visiveis;
                ShowWindow(GetDlgItem(hwndDlg, retangCadastro), butoes_visiveis ? SW_SHOW : SW_HIDE);
                ShowWindow(GetDlgItem(hwndDlg, CADASTRO_DO_PET), butoes_visiveis ? SW_SHOW : SW_HIDE);
                ShowWindow(GetDlgItem(hwndDlg, barraTexto1), butoes_visiveis ? SW_SHOW : SW_HIDE);
                ShowWindow(GetDlgItem(hwndDlg, RACA), butoes_visiveis ? SW_SHOW : SW_HIDE);
                break;
            }
            case pedidos:
            {
                butoes_visiveis = !butoes_visiveis;
                ShowWindow(GetDlgItem(hwndDlg, retangPedido), butoes_visiveis ? SW_SHOW : SW_HIDE);
                break;
            }
            return TRUE;
        }
    }
    return TRUE;
    }
    return FALSE;
}

int APIENTRY WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nShowCmd)
{
    hInst = hInstance;
    InitCommonControls();
    return DialogBox(hInst, MAKEINTRESOURCE(DLG_MAIN), NULL, (DLGPROC)DlgMain);
}
