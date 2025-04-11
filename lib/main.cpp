// main.cpp
#include "ZZ_ClearThunderManager.h"
#include "_TheSource.h"
using namespace std;

int main(int argc, char **argv)
{
    cout << "argc = " << argc << endl;
    // cout << "argv = " << *argv << endl;
    os_system("chcp 65001")("cls");
    // os_system("pause");
    srand(time(NULL));
    class CleanThunderManager CTM;
    CTM.intoHome();
    int _retNum = CTM.mutiManager();
    return _retNum;
    // return 0;
}