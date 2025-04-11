// SetMode.cpp
#include "SetMode.h"

SetMode &SetMode::operator()(int _dummy)
{
    this->main();
    return *this;
}

int SetMode::showMuti()
{
    int option = 0;
    os_system("cls");
    cout << "********************************" << endl;
    cout << "*******-扫雷模式设置界面-*******" << endl;

    if (this->l_Muti.lightLocation == ++option)
        cout << "******** >设置游戏的长< ********" << endl;
    else if (this->l_Muti.lightLocation != option)
        cout << "********  设置游戏的长  ********" << endl;

    if (this->l_Muti.lightLocation == ++option)
        cout << "******** >设置游戏的宽< ********" << endl;
    else if (this->l_Muti.lightLocation != option)
        cout << "********  设置游戏的宽  ********" << endl;

    if (this->l_Muti.lightLocation == ++option)
        cout << "******** >设置雷的自算< ********" << endl;
    else if (this->l_Muti.lightLocation != option)
        cout << "********  设置雷的自算  ********" << endl;

    if (this->l_Muti.lightLocation == ++option)
        cout << "******** >设置雷的数量< ********" << endl;
    else if (this->l_Muti.lightLocation != option)
        cout << "********  设置雷的数量  ********" << endl;

    if (this->l_Muti.lightLocation == ++option)
        cout << "******** >默认游戏设置< ********" << endl;
    else if (this->l_Muti.lightLocation != option)
        cout << "********  默认游戏设置  ********" << endl;

    if (this->l_Muti.lightLocation == ++option)
        cout << "******** >退出游戏设置< ********" << endl;
    else if (this->l_Muti.lightLocation != option)
        cout << "********  退出游戏设置  ********" << endl;

    cout << "*********************************" << endl;

    return 0;
}

int SetMode::main()
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

int SetMode::selectText(int _index)
{
    if (_index == 1)
    {
        cout << endl
             << "请输入长：" << endl;
        os_cin(this->CTM->bag.m_MapLen);
        if (this->CTM->bag.m_MapLen < 2 || this->CTM->bag.m_MapLen > 128)
        {
            cout << "输入错误，请重新输入！" << endl;
            this->CTM->bag.m_MapLen = 2;
        }
        cout << "成功设置长为:" << this->CTM->bag.m_MapLen << endl;
        this->thunderNumber();
        os_system("pause");
        return 0;
    }
    if (_index == 2)
    {
        cout << endl
             << "请输入宽：" << endl;
        os_cin(this->CTM->bag.m_MapWid);
        if (this->CTM->bag.m_MapWid < 2 || this->CTM->bag.m_MapWid > 128)
        {
            cout << "输入错误，请重新输入！" << endl;
            this->CTM->bag.m_MapWid = 2;
        }
        cout << "成功设置宽为:" << this->CTM->bag.m_MapWid << endl;
        this->thunderNumber();
        os_system("pause");
        return 0;
    }
    if (_index == 3)
    {
        cout << endl
             << "是否开启雷的自算？(y/n)(Y/N)" << endl;
        char inputChar = this->CTM->getCharInput();
        if (inputChar == 'y' || inputChar == 'Y')
            this->CTM->bag.m_IsThunderCalculate = true;
        else if (inputChar == 'n' || inputChar == 'N')
            this->CTM->bag.m_IsThunderCalculate = false;
        else
        {
            cout << "输入错误，请重新输入！" << endl;
            os_system("pause");
            return 0;
        }
        cout << "成功设置雷的自算为:" << this->CTM->bag.m_IsThunderCalculate << endl;
        this->thunderNumber();
        cout << "雷的数量：" << this->CTM->bag.m_ThunderNum << endl;
        os_system("pause");
        return 0;
    }
    if (_index == 4)
    {

        cout << endl;
        if (this->CTM->bag.m_IsThunderCalculate)
            cout << "已开启雷的自算，当您设置雷的数量时，系统会自动关闭雷的自算功能。" << endl;
        cout << "请输入宽：" << endl;
        os_cin(this->CTM->bag.m_ThunderNum);
        if (this->CTM->bag.m_ThunderNum < 1 || this->CTM->bag.m_ThunderNum > (this->CTM->bag.m_MapLen * this->CTM->bag.m_MapWid))
        {
            cout << "输入错误，请重新输入！" << endl;
            this->CTM->bag.m_ThunderNum = (this->CTM->bag.m_MapLen * this->CTM->bag.m_MapWid) / 10;
        }
        cout << "成功设置雷的数量为:" << this->CTM->bag.m_ThunderNum << endl;
        this->CTM->bag.m_IsThunderCalculate = false;
        os_system("pause");
        return 0;
    }
    if (_index == 5)
    {
        this->CTM->bag.m_MapLen = 10;
        this->CTM->bag.m_MapWid = 10;
        this->CTM->bag.m_ThunderNum = 10;
        this->CTM->bag.m_IsThunderCalculate = false;
        cout << endl
             << "成功恢复默认设置！" << endl;
        cout << "长：" << this->CTM->bag.m_MapLen << endl;
        cout << "宽：" << this->CTM->bag.m_MapWid << endl;
        cout << "雷的自算：" << this->CTM->bag.m_IsThunderCalculate << endl;
        cout << "雷的数量：" << this->CTM->bag.m_ThunderNum << endl;
        os_system("pause");
        return 0;
    }
    if (_index == 6)
        return 1;
    return 0;
}

int SetMode::thunderNumber()
{
    if (this->CTM->bag.m_MapLen != 0 || this->CTM->bag.m_MapWid != 0)
    {
        int thunderNum = 0;
        thunderNum = (this->CTM->bag.m_MapLen * this->CTM->bag.m_MapWid) / 10;
        this->CTM->bag.m_ThunderNum = thunderNum;
    }
    return this->CTM->bag.m_ThunderNum;
}

SetMode::SetMode(CleanThunderManager *_CTM)
{
    this->CTM = _CTM;
    this->l_Muti.lightLocation = 1;
    this->l_Muti.typeSize_Max = 6;
    this->l_Muti.typeSize_Min = 1;

    this->l_Right.lightLocation = 1;
    this->l_Right.typeSize_Max = 2;
    this->l_Right.typeSize_Min = 1;
    return;
}