// Password for auto-filling Signcode.exe's password dlg
#define SIGNCODE_DLG_TITLE   "Enter Private Key Password"
#define PVK_PASSWD           "<your pwd>"

BOOL fPwdSet = FALSE;
while(!fPwdSet)
{
   // Try to find Signcode's dialog
   HWND hDlg = ::FindWindow("#32770", SIGNCODE_DLG_TITLE);
   if(hDlg)
   {
      // Find the pwd edit box and the OK button
      HWND hEdit = ::GetDlgItem(hDlg, 0x1F5);
      HWND hOK = ::GetDlgItem(hDlg, IDOK);
      if(hEdit && hOK)    
      {
         // In Win32 you can't do a WM_SETTEXT to a wnd in another process.
         // Instead, "type" the passwd, char by char, to the pwd edit box
         LPCSTR psPwChar = PVK_PASSWD;
         while(*psPwChar)
         {
            ::PostMessage(hEdit, WM_CHAR, *psPwChar, 0);
            psPwChar++;
         }

         // Now "click" the pwd dlg's OK button
         ::PostMessage(hOK, WM_LBUTTONDOWN, MK_LBUTTON, MAKELPARAM(3,3));
         ::PostMessage(hOK, WM_LBUTTONUP, 0, MAKELPARAM(3,3));

         fPwdSet = TRUE;
      }
   }

   // Don't hog the CPU while we're waitingto find the dlg
   Sleep(100);
}