//_TheSource.cpp
#include "_TheSource.h"

int os_cin(int &_os)
{
    if (!(cin >> _os))
    {
        cin.clear();
        // #ifdef _WIN32
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        // #endif
    }

    return 0;
}

char os_getchar()
{
    char ch;
#ifndef _WIN32
    struct termios oldt, newt;

    tcgetattr(STDIN_FILENO, &oldt);
    newt = oldt;
    newt.c_lflag &= ~(ICANON | ECHO);
    tcsetattr(STDIN_FILENO, TCSANOW, &newt);

    ch = getchar();

    tcsetattr(STDIN_FILENO, TCSANOW, &oldt);

#endif

#ifdef _WIN32

    ch = _getch();

#endif
    return ch;
}

O_S &O_S::operator()(string _os)
{
    if (_os == "cls")
    {
        if (this->_thisSystem)
            system("cls");
        else
            for (int i = 0; i < this->_endlNum; i++)
                cout << endl;
    }
    if (_os == "pause")
    {
        if (this->_thisSystem)
            system("pause");
        else
        {
            cout << "请输入任意数据并回车后继续。。。。" << endl;
            int _a = 0;
            os_cin(_a);
        }
    }
    if (_os == "chcp 65001")
    {
        if (this->_thisSystem)
            system("chcp 65001");
        else
            cout << "请在命令行下运行此命令" << endl;
    }

    return *this;
}

O_S::O_S()
{
#ifdef _WIN32
    this->_thisSystem = true;
#else
    this->_thisSystem = false;
#endif
    this->_endlNum = 80;
}

class O_S os_system;