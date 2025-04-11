// OldGameData.cpp
#include "OldGameData.h"

BeterGame &BeterGame::operator()(int _dummy)
{
    this->main();
    return *this;
}

int BeterGame::main()
{
    while (true)
    {
        this->showMuti();
        int inputChar = this->CTM->getCharInput();
        int isReturn = 0;
        if (inputChar == 'w' || inputChar == 'W')
            this->l_Muti.lightLess();
        if (inputChar == 's' || inputChar == 'S')
            this->l_Muti.lightMore();
        if (inputChar == 'a' || inputChar == 'A')
            this->l_Right.lightLess();
        if (inputChar == 'd' || inputChar == 'D')
            this->l_Right.lightMore();
        if (inputChar == 'q' || inputChar == 'Q')
            isReturn = this->selectText(this->l_Muti.lightLocation);
        if (inputChar == 'e' || inputChar == 'E')
            isReturn = this->selectText(this->l_Muti.lightLocation);
        if (inputChar == 10)
            isReturn = this->selectText(this->l_Muti.lightLocation);

        if (isReturn == 1)
            return 0;
    }
    return 0;
}

int BeterGame::showMuti()
{
    int option = 0;
    os_system("cls");
    cout << "********************************" << endl;
    cout << "*******-扫雷更新类容界面-*******" << endl;

    if (this->l_Muti.lightLocation == ++option)
        cout << "******** >游戏人员列表< ********" << endl;
    else if (this->l_Muti.lightLocation != option)
        cout << "********  游戏人员列表  ********" << endl;

    if (this->l_Muti.lightLocation == ++option)
        cout << "******** >当前版本更新< ********" << endl;
    else if (this->l_Muti.lightLocation != option)
        cout << "********  当前版本更新  ********" << endl;

    if (this->l_Muti.lightLocation == ++option)
        cout << "******** >版本更新计划< ********" << endl;
    else if (this->l_Muti.lightLocation != option)
        cout << "********  版本更新计划  ********" << endl;

    if (this->l_Muti.lightLocation == ++option)
        cout << "******** >v1.0版本更新< ********" << endl;
    else if (this->l_Muti.lightLocation != option)
        cout << "********  v1.0版本更新  ********" << endl;

    if (this->l_Muti.lightLocation == 0)
        cout << "******** >退出版本查看< ********" << endl;
    else if (this->l_Muti.lightLocation != 0)
        cout << "********  退出版本查看  ********" << endl;

    cout << "*********************************" << endl;

    return 0;
}

int BeterGame::selectText(int _index)
{
    if (_index == 0)
        return 1;
    if (_index == 1)
        this->makerList();
    if (_index == 2)
        this->snapshot();
    if (_index == 3)
        this->overGame();
    if (_index == 4)
        this->old1_0();
    return 0;
}

BeterGame::BeterGame(CleanThunderManager *_CTM)
{

    this->CTM = _CTM;
    this->l_Muti.lightLocation = 1;
    this->l_Muti.typeSize_Max = 4;
    this->l_Muti.typeSize_Min = 0;

    this->l_Right.lightLocation = 1;
    this->l_Right.typeSize_Max = 2;
    this->l_Right.typeSize_Min = 1;
    return;
}

int BeterGame::makerList()
{
    os_system("cls");
    cout << "-----------------------------------------------" << endl;
    cout << "制作人员列表:" << endl;
    cout << "游戏数据结构设计:SHD-ΣOmicronRockefeller" << endl;
    cout << "游戏界面设计:SHD-ΣOmicronRockefeller" << endl;
    cout << "游戏逻辑设计:SHD-ΣOmicronRockefeller" << endl;
    cout << "游戏支持:[不给予展出]" << endl;
    cout << "特别感谢:[不给予展出]" << endl;
    cout << "-----------------------------------------------" << endl;
    cout << "QQ:  3551842864" << endl;
    cout << "邮箱:3551842864@qq.com" << endl;
    cout << "     wangzhuantou@outlook.com" << endl;
    cout << "-----------------------------------------------" << endl;
    os_system("pause");
    return 0;
}

int BeterGame::snapshot()
{
    os_system("cls");
    cout << "-----------------------------------------------" << endl;
    cout << "-v1.0.2版本更新内容:" << endl;
    cout << "1.游戏进入时将自动设置默认配置" << endl;
    cout << "-----------------------------------------------" << endl;

    os_system("pause");
    return 0;
}

int BeterGame::overGame()
{
    os_system("cls");
    cout << "未来版本更新计划:" << endl;
    cout << "-----------------------------------------------" << endl;
    cout << "1.1:结构优化，更好的菜单" << endl;
    cout << "1.2:个人系统，自己的数据" << endl;
    cout << "1.3:积分系统，万分王时代" << endl;
    cout << "1.4:成就系统，游戏的成就" << endl;
    cout << "1.5:排位系统，一分高下中" << endl;
    cout << "-----------------------------------------------" << endl;
    os_system("pause");
    return 0;
}

int BeterGame::old1_0()
{
    os_system("cls");
    cout << "v1.0.0 ~ v1.0.1版本更新内容:" << endl;
    cout << "-----------------------------------------------" << endl;
    cout << "-v1.0.0版本更新内容:" << endl;
    cout << "1.我们开发了游戏,他是以C++语言为基础开发的关于扫雷的游戏。" << endl;
    cout << "2.大家在游玩是发现了一些问题，我们将在下个版本更新中解决这些问题。" << endl;
    cout << "3.希望大家给从宝贵意见" << endl;
    cout << "-----------------------------------------------" << endl;
    cout << "-v1.0.1版本更新内容:" << endl;
    cout << "1.修复了进入游戏后，光标位置不对的问题。" << endl;
    cout << "2.修复了进入界面错误显示的问题。" << endl;
    cout << "3.修复了游戏暂停退出时显示错误的问题。" << endl;
    cout << "4.更新了游戏存储文件。" << endl;
    cout << "5.优化了游戏界面。" << endl;
    cout << "6.修复了地图大小与实际大小不一致的问题。" << endl;
    cout << "7.修复了游戏读取未完成时，游戏地图大小不正确导致游戏崩溃的问题。" << endl;
    cout << "8.更新了更新计划，当前版本更新日志" << endl;
    cout << "-----------------------------------------------" << endl;
    cout << "-v1.0.2版本更新内容:" << endl;
    cout << "1.游戏进入时将自动设置默认配置" << endl;
    cout << "-----------------------------------------------" << endl;

    os_system("pause");
    return 0;
}

int BeterGame::old1_1()
{
    os_system("cls");
    cout << "v1.1.0 ~ v1.1.0版本更新内容:" << endl;
    cout << "-----------------------------------------------" << endl;
    cout << "-----------------------------------------------" << endl;
    os_system("pause");
    return 0;
}

int BeterGame::old1_2()
{
    os_system("cls");
    cout << "v1.2.0 ~ v1.2.0版本更新内容:" << endl;
    cout << "-----------------------------------------------" << endl;
    cout << "-----------------------------------------------" << endl;
    os_system("pause");
    return 0;
}
