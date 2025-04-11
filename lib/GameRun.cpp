// GameRun.cpp
#include "GameRun.h"
#include "_TheSource.h"

GameRun &GameRun::operator()(Bag &_copyText)
{
    this->l_CityLen.typeSize_Max = _copyText.m_MapLen;
    this->l_CityWid.typeSize_Max = _copyText.m_MapWid;
    this->l_CityLen.lightLocation = 1;
    this->l_CityWid.lightLocation = 1;

    this->m_IsThunderCalculate = _copyText.m_IsThunderCalculate;
    this->m_MapLen = _copyText.m_MapLen;
    this->m_MapWid = _copyText.m_MapWid;
    this->m_ThunderNum = _copyText.m_ThunderNum;

    this->makeMap();
    return *this;
}

GameRun &GameRun::operator()(Bag &_copyText, vector<vector<Block>> &_copyBlock)
{
    this->l_CityLen.typeSize_Max = _copyText.m_MapLen;
    this->l_CityWid.typeSize_Max = _copyText.m_MapWid;
    this->l_CityLen.lightLocation = 1;
    this->l_CityWid.lightLocation = 1;

    this->m_IsThunderCalculate = _copyText.m_IsThunderCalculate;
    this->m_MapWid = _copyText.m_MapLen;
    this->m_MapLen = _copyText.m_MapWid;
    this->m_ThunderNum = _copyText.m_ThunderNum;

    this->blockArray = _copyBlock;
    this->main();
    return *this;
}

GameRun::GameRun()
{
    this->foot = 0;

    this->m_IsThunderCalculate = false;
    this->m_MapLen = 0;
    this->m_MapWid = 0;
    this->m_ThunderNum = 0;

    this->l_CityLen.typeSize_Min = 1;
    this->l_CityWid.typeSize_Min = 1;
    return;
}

int GameRun::getCharInput()
{
    char inputChar;
    inputChar = os_getchar();
    if (inputChar == 27)
    {
        inputChar = os_getchar();
        if (inputChar == 91)
        {
            inputChar = os_getchar();
            if (inputChar >= 48 && inputChar <= 52)
            {
                char inputChar2 = os_getchar();
                if (inputChar2 == 57)
                {
                    inputChar2 = os_getchar();
                }
                return inputChar;
            }
            return inputChar;
        }
    }
    return inputChar;
}

int GameRun::makeMap()
{
    this->setMap();
    int setThunderNum = 0;
    while (setThunderNum < this->m_ThunderNum)
    {
        int thunder_Len = rand() % (this->m_MapLen - 1) + 1;
        int thunder_Wod = rand() % (this->m_MapWid - 1) + 1;
        if (this->blockArray.at(thunder_Len).at(thunder_Wod).m_IsThunder == false)
        {
            this->blockArray.at(thunder_Len).at(thunder_Wod).m_IsThunder = true;
            this->blockArray.at(thunder_Len).at(thunder_Wod).m_AboutTunderNum = -1;
            setThunderNum++;
        }
    }
    for (int oLen = 1; oLen <= this->m_MapLen; oLen++)
    {
        for (int oWid = 1; oWid <= this->m_MapWid; oWid++)
        {
            if (this->blockArray.at(oLen).at(oWid).m_IsThunder == false)
            {
                for (int iLen = oLen - 1; iLen <= oLen + 1; iLen++)
                {
                    for (int iWid = oWid - 1; iWid <= oWid + 1; iWid++)
                    {
                        if (iLen >= 1 && iLen <= this->m_MapLen && iWid >= 1 && iWid <= this->m_MapWid)
                        {
                            if (this->blockArray.at(iLen).at(iWid).m_IsThunder == true)
                            {
                                this->blockArray.at(oLen).at(oWid).m_AboutTunderNum++;
                            }
                        }
                    }
                }
            }
            else
            {
                this->blockArray.at(oLen).at(oWid).m_AboutTunderNum = -1;
            }
        }
    }
    for (int i = 0; i < this->m_MapWid + 2; i++)
    {
        this->blockArray.at(0).at(i).m_AboutTunderNum = -2;
        this->blockArray.at(this->m_MapLen + 1).at(i).m_AboutTunderNum = -2;
    }
    for (int i = 0; i < this->m_MapLen + 2; i++)
    {
        this->blockArray.at(i).at(0).m_AboutTunderNum = -2;
        this->blockArray.at(i).at(this->m_MapWid + 1).m_AboutTunderNum = -2;
    }
    this->main();
    return 0;
}

int GameRun::main()
{
    bool stream = true;
    int condition = 0;
    while (stream)
    {
        this->showMap(0);
        char inputChar = this->getCharInput();
        condition = this->logic(inputChar);
        if (condition != 1)
        {
            condition = this->isEnd(condition);
        }
        // 0 = 游戏进行   1 = 游戏结束   2 = 游戏胜利    3 = 退出游戏
        this->saveMap(condition);
        stream = this->canResream(condition);
    }
    this->cleanSave(condition);
    this->saveLine(condition);
    this->gameEnd(condition);
    return 0;
}

int GameRun::logic(int _logic_Num)
{
    if (_logic_Num == 'w' || _logic_Num == 'W')
    {
        this->l_CityLen.lightLess();
        return 0;
    }
    if (_logic_Num == 's' || _logic_Num == 'S')
    {
        this->l_CityLen.lightMore();
        return 0;
    }
    if (_logic_Num == 'a' || _logic_Num == 'A')
    {
        this->l_CityWid.lightLess();
        return 0;
    }
    if (_logic_Num == 'd' || _logic_Num == 'D')
    {
        this->l_CityWid.lightMore();
        return 0;
    }

    if (_logic_Num == 'q' || _logic_Num == 'Q' || _logic_Num == 10)
        return this->open();
    if (_logic_Num == 'e' || _logic_Num == 'E')
        this->mark();
    if (_logic_Num == 'r' || _logic_Num == 'R')
        return 3;

    return 0;
}

int GameRun::open()
{
    if (this->blockArray.at(this->l_CityLen.lightLocation).at(this->l_CityWid.lightLocation).m_IsOpen == false)
    {
        this->foot++;
        this->blockArray.at(this->l_CityLen.lightLocation).at(this->l_CityWid.lightLocation).m_IsOpen = true;
        if (this->blockArray.at(this->l_CityLen.lightLocation).at(this->l_CityWid.lightLocation).m_IsThunder)
        {
            return 1;
        }
        else if (this->blockArray.at(this->l_CityLen.lightLocation).at(this->l_CityWid.lightLocation).m_AboutTunderNum == 0)
        {
            this->reopen(this->l_CityLen.lightLocation, this->l_CityWid.lightLocation);
        }
        else
            return 0;
    }
    return 0;
}

int GameRun::reopen(int os_Len, int os_Wid)
{
    this->blockArray.at(os_Len).at(os_Wid).m_IsOpen = true;
    if (this->blockArray.at(os_Len).at(os_Wid).m_AboutTunderNum == 0)
    {
        for (int iLen = os_Len - 1; iLen <= os_Len + 1; iLen++)
        {
            for (int iWid = os_Wid - 1; iWid <= os_Wid + 1; iWid++)
            {
                if (iLen >= 0 && iLen <= this->m_MapLen + 1 && iWid >= 0 && iWid <= this->m_MapWid + 1)
                {
                    if (this->blockArray.at(iLen).at(iWid).m_AboutTunderNum == 0 && this->blockArray.at(iLen).at(iWid).m_IsOpen == false)
                        this->reopen(iLen, iWid);
                    else
                        this->blockArray.at(iLen).at(iWid).m_IsOpen = true;
                }
            }
        }
    }
    return 0;
}

int GameRun::mark()
{
    return this->open();
}

int GameRun::isEnd(int _isEnd_Num)
{
    int addtion = 0;
    for (int i = 1; i <= this->m_MapLen; i++)
    {
        for (int j = 1; j <= this->m_MapWid; j++)
        {
            if (!this->blockArray.at(i).at(j).m_IsOpen)
            {
                addtion++;
            }
        }
    }
    if (addtion == this->m_ThunderNum)
    {
        return 2;
    }
    else
    {
        return _isEnd_Num;
    }
}

bool GameRun::canResream(int judgeNum)
{
    if (judgeNum == 0)
    {
        return true;
    }
    if (judgeNum == 1)
    {
        return false;
    }
    if (judgeNum == 2)
    {
        return false;
    }
    if (judgeNum == 3)
    {
        return false;
    }
    return false;
}

int GameRun::saveMap(int _saveMap_Num)
{
    fstream file;
    file.open("isntOverGame.dati", ios::out);
    if (_saveMap_Num == 0 || _saveMap_Num == 3)
    {
        file << "true ";
        file << this->m_MapLen << " ";
        file << this->m_MapWid << " ";
        file << this->m_IsThunderCalculate;
        file << " " << this->m_ThunderNum;
        file << '\n';

        file << "maxBegin" << '\n';
        for (int i = 0; i < this->m_MapLen + 2; i++)
        {
            file << "begin";
            for (int j = 0; j < this->m_MapWid + 2; j++)
            {
                file << " ";
                file << setw(2) << this->blockArray.at(i).at(j).m_IsOpen << " ";
                file << setw(2) << this->blockArray.at(i).at(j).m_IsThunder << " ";
                file << setw(2) << this->blockArray.at(i).at(j).m_AboutTunderNum << " ";
            }
            file << "end";
            file << '\n';
        }
        file << "maxEnd" << '\n';

        // file << "mapThing" << endl;
        // for (int i = 0; i < this->blockArray.size(); i++)
        // {
        //     for (int j = 0; j < this->blockArray.at(i).size(); j++)
        //     {
        //         file << setw(2) << this->blockArray.at(i).at(j).m_AboutTunderNum;
        //     }
        //     file << endl;
        // }
    }
    else
    {
        file << "false";
    }
    file.close();
    return 0;
}

int GameRun::cleanSave(int _cleanSave_Num)
{
    if (_cleanSave_Num == 2)
    {
        fstream file;
        file.open("isntOverGame.dati", ios::out);
        file << "false";
        file.close();
    }
    return 0;
}

int GameRun::saveLine(int _saveLine_Num)
{
    if (_saveLine_Num == 2)
    {
        fstream file;
        file.open("beforeGame.dati", ios::out | ios::app);
        file << this->m_MapLen << " ";
        file << this->m_MapWid << " ";
        file << this->m_IsThunderCalculate << " ";
        file << this->m_ThunderNum << " ";
        file << this->foot << " ";
        file << '\n';
    }
    return 0;
}

int GameRun::gameEnd(int _gameEnd_Num)
{
    // 1 = 游戏结束 2 = 游戏胜利
    if (_gameEnd_Num != 3)
    {
        this->showMap(1);
        if (_gameEnd_Num == 1)
        {
            cout << "游戏结束！" << endl;
            cout << "游戏步数：" << this->foot << endl;
        }
        if (_gameEnd_Num == 2)
        {
            cout << "游戏胜利！" << endl;
            cout << "游戏步数：" << this->foot << endl;
        }
        os_system("pause");
    }

    return 0;
}

int GameRun::setMap()
{
    for (int i = 0; i < this->mapArray.size(); i++)
        this->mapArray.at(i).clear();
    this->mapArray.clear();
    for (int i = 0; i < this->m_MapLen + 2; i++)
    {
        this->mapArray.push_back(vector<Block>());
        for (int j = 0; j < this->m_MapWid + 2; j++)
        {
            this->mapArray.at(i).push_back(Block());
            this->mapArray.at(i).at(j).m_IsOpen = false;
            this->mapArray.at(i).at(j).m_IsThunder = false;
            this->mapArray.at(i).at(j).m_AboutTunderNum = 0;
            this->mapArray.at(i).at(j).m_LocationLen = i;
            this->mapArray.at(i).at(j).m_LocationWid = j;
        }
    }
    this->blockArray = this->mapArray;
    return 0;
}

int GameRun::outTitle(const int cin_Num, int size, int air)
{
    int maxNum = 0;
    int num = cin_Num;
    while (num > 0)
    {
        maxNum++;
        num /= 10;
    }
    vector<vector<int>> num_Array(maxNum, vector<int>(cin_Num, 0));
    for (int i = 0; i < cin_Num; ++i)
    {
        int for_num = i + 1;
        int emp = 0;
        while (for_num > 0 && emp < maxNum)
        {
            num_Array[maxNum - emp - 1][i] = for_num % 10;
            for_num /= 10;
            ++emp;
        }
    }

    for (int i = 0; i < maxNum; ++i)
    {
        for (int j = 0; j < air; ++j)
            cout << " ";
        for (int j = 0; j < cin_Num; ++j)
            cout << setw(size) << num_Array[i][j];
        cout << endl;
    }
    for (int i = 0; i < air; ++i)
    {
        cout << " ";
    }
    for (int i = 0; i < cin_Num; ++i)
    {
        for (int j = 0; j < size; ++j)
        {
            cout << "_";
        }
    }
    cout << endl;
    return 0;
}

int GameRun::showMap(int condition)
{
    // 0 = 游戏进行
    // 1 = 游戏结束
    // 2 = 游戏胜利
    os_system("cls");
    this->outTitle(this->m_MapWid, 2, 4);
    for (int i = 1; i <= this->m_MapLen; ++i)
    {
        cout << setw(3) << i << "|";
        for (int j = 1; j <= this->m_MapWid; ++j)
        {
            if (!this->blockArray.at(i).at(j).m_IsThunder)
            {
                if (i == this->l_CityLen.lightLocation && j == this->l_CityWid.lightLocation)
                {
                    cout << setw(2) << "+";
                }
                else
                {
                    if (!this->blockArray.at(i).at(j).m_IsOpen)
                    {
                        cout << setw(2) << "M";
                    }
                    if (this->blockArray.at(i).at(j).m_IsOpen)
                    {
                        if (!this->blockArray.at(i).at(j).m_AboutTunderNum)
                        {
                            cout << setw(2) << "-";
                        }
                        else
                        {
                            cout << setw(2) << this->blockArray.at(i).at(j).m_AboutTunderNum;
                        }
                    }
                }
            }
            else if (this->blockArray.at(i).at(j).m_IsThunder)
            {
                if (i == this->l_CityLen.lightLocation && j == this->l_CityWid.lightLocation)
                {
                    cout << setw(2) << "+";
                }
                else
                {
                    if (!condition)
                    {
                        cout << setw(2) << "M";
                    }
                    else if (condition) // 1
                    {
                        cout << setw(2) << "X";
                    }
                    else if (condition) // 2
                    {
                        cout << setw(2) << "X";
                    }
                }
            }
        }
        cout << '\n';
    }
    return 0;
}
