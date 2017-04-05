#include <iostream>
#include <windows.h>

#define qbt 0x51
#define wbt 0x57
#define obt 0x4F
#define pbt 0x50
#define xbt 0x58
#define commabt 0xBC
#define onebt 0x31
#define twobt 0x32
#define zerobt 0x30
#define minusbt 0xBD
#define startbt 0x0D

using namespace std;

int main()
{
    HANDLE serialHandle;

    serialHandle = CreateFile("\\\\.\\COM3", GENERIC_READ, 0, 0, OPEN_ALWAYS, FILE_ATTRIBUTE_NORMAL, 0);

    DCB serialParams = {0};
    serialParams.DCBlength = sizeof(serialParams);

    SetCommState(serialHandle, &serialParams);
    serialParams.BaudRate = 57600;
    serialParams.ByteSize = 1;
    serialParams.StopBits = ONESTOPBIT;
    serialParams.Parity = NOPARITY;
    SetCommState(serialHandle, &serialParams);

    COMMTIMEOUTS timeout = {0};
    timeout.ReadIntervalTimeout = 10;
    timeout.ReadTotalTimeoutConstant = 5;
    timeout.ReadTotalTimeoutMultiplier = 5;

    SetCommTimeouts(serialHandle, &timeout);
    char data[1] = {0};
    ReadFile(serialHandle,data,1,NULL,NULL);

    int ll = 0;
    bool flag_ll = 0;
    int lr = 0;
    bool flag_lr = 0;
    int rl = 0;
    bool flag_rl = 0;
    int rr = 0;
    bool flag_rr = 0;

    int fx1 = 0;
    bool flag_fx1 = 0;
    int fx2 = 0;
    bool flag_fx2 = 0;
    int fx3 = 0;
    bool flag_fx3 = 0;

    while(true)
    {
        ReadFile(serialHandle,data,1,NULL,NULL);

        if(data[0] == '3')//spam fx1
        {
            fx1 = 3;
        }

        if(fx1 > 0)
        {
            if(fx1 > 0 && flag_fx1 == 0)
            {
                keybd_event(xbt,0,0,0);
                flag_fx1 = 1;
            }

            fx1--;
        }
        else
        {
            flag_fx1 = 0;
            keybd_event(xbt,0,KEYEVENTF_KEYUP,0);
        }

        if(data[0] == '4')//spam fx2
        {
            fx2 = 3;
        }

        if(fx2 > 0)
        {
            if(fx2 > 0 && flag_fx2 == 0)
            {
                keybd_event(commabt,0,0,0);
                flag_fx2 = 1;
            }

            fx2--;
        }
        else
        {
            flag_fx2 = 0;
            keybd_event(commabt,0,KEYEVENTF_KEYUP,0);
        }

        if(data[0] == '5')//spam fx3
        {
            fx1 = 3;
            fx2 = 3;
        }

        if(data[0] == '1')//spam ll
        {
            ll = 5;
            lr = 0;
        }

        if(ll > 0)
        {
            if(ll > 0 && flag_ll == 0)
            {
                keybd_event(onebt,0,0,0);
                flag_ll = 1;
            }

            ll--;
        }
        else
        {
            flag_ll = 0;
            keybd_event(onebt,0,KEYEVENTF_KEYUP,0);
        }

        if(data[0] == '2')//spam lr
        {
            lr = 5;
            ll = 0;
        }

        if(lr > 0)
        {
            if(lr > 0 && flag_lr == 0)
            {
                keybd_event(twobt,0,0,0);
                flag_lr = 1;
            }

            lr--;
        }
        else
        {
            flag_lr = 0;
            keybd_event(twobt,0,KEYEVENTF_KEYUP,0);
        }

        if(data[0] == '0')//spam rl
        {
            rl = 5;
            rr = 0;
        }

        if(rl > 0)
        {
            if(rl > 0 && flag_rl == 0)
            {
                keybd_event(zerobt,0,0,0);
                flag_rl = 1;
            }

            rl--;
        }
        else
        {
            flag_rl = 0;
            keybd_event(zerobt,0,KEYEVENTF_KEYUP,0);
        }

        if(data[0] == '-')//spam rr
        {
            rr = 5;
            rl = 0;
        }

        if(rr > 0)
        {
            if(rr > 0 && flag_rr == 0)
            {
                keybd_event(minusbt,0,0,0);
                flag_rr = 1;
            }

            rr--;
        }
        else
        {
            flag_rr = 0;
            keybd_event(minusbt,0,KEYEVENTF_KEYUP,0);
        }

        Sleep(1);

        if(data[0] == 'a')//start
        {
            keybd_event(startbt,0,0,0);
        }
        if(data[0] == 'q')
        {
            keybd_event(startbt,0,KEYEVENTF_KEYUP,0);
        }

        if(data[0] == 's')//a
        {
            keybd_event(qbt,0,0,0);
        }
        if(data[0] == 'w')
        {
            keybd_event(qbt,0,KEYEVENTF_KEYUP,0);
        }

        if(data[0] == 'd')//b
        {
            keybd_event(wbt,0,0,0);
        }
        if(data[0] == 'e')
        {
            keybd_event(wbt,0,KEYEVENTF_KEYUP,0);
        }

        if(data[0] == 'f')//c
        {
            keybd_event(obt,0,0,0);
        }
        if(data[0] == 'r')
        {
            keybd_event(obt,0,KEYEVENTF_KEYUP,0);
        }

        if(data[0] == 'g')//d
        {
            keybd_event(pbt,0,0,0);
        }
        if(data[0] == 't')
        {
            keybd_event(pbt,0,KEYEVENTF_KEYUP,0);
        }

        data[0] = ' ';
    }

    return 0;
}
