// g++ -DUNICODE  -finput-charset=GBK opendir.cpp && ./a.exe
#include <windows.h>
#include <ShlObj.h>
#include <iostream>

using namespace std;

BOOL SelectDir(HWND hWnd)
{
    BROWSEINFO bifolder;
    wchar_t FileName[MAX_PATH];
    ZeroMemory(&bifolder, sizeof(BROWSEINFO)); 
    bifolder.hwndOwner = hWnd;              // ӵ���߾��
    bifolder.pszDisplayName = FileName;     // ���Ŀ¼·��������
    bifolder.lpszTitle = TEXT("��ѡ���ļ���");  // ����
    bifolder.ulFlags = BIF_NEWDIALOGSTYLE | BIF_EDITBOX; // �µ���ʽ,���༭��

    LPITEMIDLIST idl = SHBrowseForFolder(&bifolder);
    if (idl == NULL)
    {
        return FALSE;
    }

    SHGetPathFromIDList(idl,FileName);    
    MessageBox(hWnd, FileName, TEXT("������Ϣ"), MB_OK|MB_ICONERROR);
    return TRUE;
}

int main()
{
    SelectDir(NULL);

    return 0;
}
