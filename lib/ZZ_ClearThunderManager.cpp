// ZZ_ClearThunderManager.cpp
#include "ZZ_ClearThunderManager.h"
#include "_TheSource.h"
#include "SetMode.h"
#include "OldGameData.h"

int CleanThunderManager::showMuti()
{
     int option = 0;
     os_system("cls");
     cout << "********************************" << endl;
     cout << "********高级扫雷(V1.0.1)********" << endl;

     if (this->l_Muti.lightLocation == ++option)
          cout << "******** >开始新的游戏< ********" << endl;
     else if (this->l_Muti.lightLocation != option)
          cout << "********  开始新的游戏  ********" << endl;

     if (this->l_Muti.lightLocation == ++option)
          cout << "******** >继续上次游戏< ********" << endl;
     else if (this->l_Muti.lightLocation != option)
          cout << "********  继续上次游戏  ********" << endl;

     if (this->l_Muti.lightLocation == ++option)
          cout << "******** >设置游戏模式< ********" << endl;
     else if (this->l_Muti.lightLocation != option)
          cout << "********  设置游戏模式  ********" << endl;

     if (this->l_Muti.lightLocation == ++option)
          cout << "******** >查看更新类容< ********" << endl;
     else if (this->l_Muti.lightLocation != option)
          cout << "********  查看更新类容  ********" << endl;

     if (this->l_Muti.lightLocation == 0)
          cout << "******** >退出当前游戏< ********" << endl;
     else if (this->l_Muti.lightLocation != 0)
          cout << "********  退出当前游戏  ********" << endl;

     cout << "*********************************" << endl;
     return 0;
}

int CleanThunderManager::getCharInput()
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
                         inputChar2 = os_getchar();
                    return inputChar;
               }
               return inputChar;
          }
     }
     return inputChar;
}

int CleanThunderManager::mutiManager()
{
     this->l_Muti.typeSize_Max = 4;
     this->l_Muti.typeSize_Min = 0;
     this->l_Home.typeSize_Max = 3;
     this->l_Home.typeSize_Min = 1;
     this->l_Muti.lightLocation = 1;
     while (true)
     {
          this->showMuti();
          int inputChar = this->getCharInput();
          if (inputChar == 'w' || inputChar == 'W')
               this->l_Muti.lightLess();
          if (inputChar == 's' || inputChar == 'S')
               this->l_Muti.lightMore();
          if (inputChar == 'a' || inputChar == 'A')
               this->l_Home.lightLess();
          if (inputChar == 'd' || inputChar == 'D')
               this->l_Home.lightMore();
          if (inputChar == 'q' || inputChar == 'Q')
               this->selectText(this->l_Muti.lightLocation);
          if (inputChar == 'e' || inputChar == 'E')
               this->selectText(this->l_Muti.lightLocation);
          if (inputChar == 10)
               this->selectText(this->l_Muti.lightLocation);
     }
     return 0;
}

int CleanThunderManager::selectText(int i)
{
     os_system("cls");
     if (i == 1)
     {
          // 0 = cant play
          // 1 = can play
          // 2 = return this
          os_system("cls");
          while (!this->isCanOpen(true))
          {
               int i = this->cantRunAfter();
               if (i == 0)
               {
                    this->setMode();
                    os_system("cls");
               }
               if (i == 1)
                    continue;
               if (i == 2)
               {
                    os_system("cls");
                    return 0;
               }
          }
          cout << "您已初始化成功，是否开始游戏？" << endl;
          cout << "a/A: 开始游戏" << endl;
          cout << "b/B: 返回主菜单" << endl;
          char inputChar = this->getCharInput();
          if (inputChar == 'a' || inputChar == 'A')
               GameRun()(this->bag);
          if (inputChar == 'b' || inputChar == 'B')
               return 0;
          os_system("cls");
          return 0;
     }
     if (i == 2)
     {
          if (!this->hasOldf())
          {
               cout << "当前没有需要继续的游戏" << endl;
               os_system("pause")("cls");
               return 0;
          }
          if (this->hasOldf())
          {
               GameRun()(this->oldBag, this->blockArray);
               os_system("cls");
               return 0;
          }
     }
     if (i == 3)
     {
          bool re = true;
          // The next that the "re" mast before than "!this->setMode()".
          while (re && !this->setMode())
          {
               re = this->resetMode();
          }
          os_system("cls");
          return 0;
     }
     if (i == 4)
     {
          BeterGame(this)(256);
          os_system("cls");
          return 0;
     }
     if (i == 0)
     {
          this->exitGame();
          os_system("cls");
          return 0;
     }
     os_system("cls");
     return 0;
}

bool CleanThunderManager::isCanOpen(bool isOut)
{
     bool canPlay = true;
     if (bag.m_MapLen < 2)
     {
          canPlay = false;
          if (isOut)
               cout << "游戏的长未初始化成功" << endl;
     }
     if (bag.m_MapWid < 2)
     {
          canPlay = false;
          if (isOut)
               cout << "游戏的宽未初始化成功" << endl;
     }
     if (!bag.m_IsThunderCalculate)
     {
          if (bag.m_ThunderNum < 1)
          {
               canPlay = false;
               if (isOut)
                    cout << "游戏的雷未初始化成功" << endl;
          }
     }
     if (canPlay)
          return true;
     else
          return false;
}

int CleanThunderManager::cantRunAfter()
{
     os_system("cls");
     cout << "游戏未初始化成功，是否前往初始化？" << endl;
     cout << "a/A: 前往初始化" << endl;
     cout << "b/B: 返回主菜单" << endl;
     char inputChar = this->getCharInput();
     if (inputChar == 'a' || inputChar == 'A')
          return 0;
     else if (inputChar == 'b' || inputChar == 'B')
          return 2;
     else
     {
          cout << "输入错误，请重新输入" << endl;
          return 1;
     }
     return 2;
}

int CleanThunderManager::intoHome()
{
     os_system("cls");
     cout << "欢迎进入清雷游戏！" << endl
          << endl;
     cout << "请等待数据导入完成。。。" << endl;
     cout << "正在导入未完成的游戏数据。。。" << endl;
     this->hasOldf(true);
     cout << "整理数据中。。。" << endl;
#ifdef _WIN32
     Sleep(1000);
#else
     sleep(1);
#endif
     cout << "完成！" << endl;
     cout << "数据导入完成！" << endl
          << endl;
     os_system("pause");
     os_system("cls");
     cout << "等待进入。。。" << endl;
#ifdef _WIN32

     Sleep(rand() % 1001 + 1000);
#else
     sleep(rand() % 2 + 1);
#endif
     os_system("cls");
     return 0;
}

bool CleanThunderManager::hasOldf(bool _out)
{
     this->hasOld = false;
     this->blockArray.clear();
     ifstream ifs;
     ifs.open("isntOverGame.dati", ios::in);
     if (ifs.is_open())
     {
          string ch;
          ifs >> ch;
          if (ch == "true")
          {
               this->hasOld = true;
               ifs >> this->oldBag.m_MapLen;
               ifs >> this->oldBag.m_MapWid;
               ifs >> this->oldBag.m_IsThunderCalculate;
               ifs >> this->oldBag.m_ThunderNum;

               if (_out)
                    cout << "找到上次未完成的游戏数据";
               this->blockArray.clear();
               cout << endl;

               ifs >> ch;
               if (ch != "maxBegin")
               {
                    this->hasOld = false;
                    return false;
               }
               else
               {
                    int i = 0;
                    ifs >> ch;
                    if (ch != "begin")
                    {
                         this->hasOld = false;
                         return false;
                    }
                    while (ch == "begin")
                    {
                         int j = 0;
                         this->blockArray.push_back(vector<Block>());
                         ifs >> ch;
                         while (ch != "end")
                         {
                              this->blockArray.at(this->blockArray.size() - 1).push_back(Block());
                              this->blockArray.at(this->blockArray.size() - 1).at(this->blockArray.at(this->blockArray.size() - 1).size() - 1).m_IsOpen = stoi(ch);
                              ifs >> this->blockArray.at(this->blockArray.size() - 1).at(this->blockArray.at(this->blockArray.size() - 1).size() - 1).m_IsThunder;
                              ifs >> this->blockArray.at(this->blockArray.size() - 1).at(this->blockArray.at(this->blockArray.size() - 1).size() - 1).m_AboutTunderNum;
                              ifs >> ch;
                         }
                         ifs >> ch;
                         if (_out)
                              cout << '\r' << "已加载进度:[" << setw(3) << ++i << "/" << setw(3) << this->oldBag.m_MapLen + 2 << "]";
                    }
                    if (ch != "maxEnd")
                    {
                         this->hasOld = false;
                         return false;
                    }
               }

               if (_out)
                    cout << endl;
          }
     }

     ifs.close();
     return this->hasOld;
}

bool CleanThunderManager::setMode()
{
     SetMode(this)(256);
     return this->isCanOpen(false);
}

bool CleanThunderManager::resetMode()
{
     bool canRe = this->isCanOpen(true);
     if (!canRe)
     {
          cout << "游戏模式设置不完整，是否重新设置？" << endl;
          cout << "y/Y: 重新设置" << endl;
          cout << "other: 退出设置" << endl;
          char inputChar = this->getCharInput();
          if (inputChar == 'y' || inputChar == 'Y')
               return true;
          else
               return false;
     }
     os_system("pause");
     return false;
}

int CleanThunderManager::exitGame()
{
     os_system("cls");
     cout << "是否退出游戏？" << endl;
     cout << "y/Y: 退出游戏" << endl;
     cout << "other: 继续游戏" << endl;
     char inputChar = this->getCharInput();
     if (inputChar == 'y' || inputChar == 'Y')
     {
          cout << "欢迎下次游玩！" << endl;
          cout << "正在退出游戏。。。" << endl;
#ifdef _WIN32
          Sleep(1000);
#else
          sleep(1);
#endif
          cout << "退出成功！" << endl;
          exit(0);
     }
     else
          return 0;
     os_system("pause");
     return 0;
}

CleanThunderManager::CleanThunderManager()
{
     this->__system = 0;
     this->bag.m_IsThunderCalculate = true;
     this->bag.m_ThunderNum = 10;
     this->bag.m_MapLen = 10;
     this->bag.m_MapWid = 10;
     this->hasOldf(false);
     return;
}

CleanThunderManager::~CleanThunderManager()
{
     return;
}
