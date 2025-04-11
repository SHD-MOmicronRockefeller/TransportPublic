//_TheSource.h
#pragma once

#include <string>
#include <iostream>
#include <vector>
#include <limits>
#include <algorithm>
#include <iomanip>
#include <stdio.h>
#include <random>
#include <ctime>

#include <unistd.h>
#include <fstream>

#ifdef _WIN32
#include <conio.h>
#include <windows.h>
#else
//
#include <termio.h>
#include <stdio.h>
#include <unistd.h>
#endif

using namespace std;

extern int os_cin(int &_os);
extern char os_getchar();
class O_S
{
public:
    bool _thisSystem;
    int _endlNum;

    O_S &operator()(string _os);
    O_S();
};
extern O_S os_system;