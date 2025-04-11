// OldGameData.h
#pragma once

#include "_TheSource.h"
#include "Block.h"
#include "ZZ_ClearThunderManager.h"

class BeterGame
{
public:
    LightLocation l_Muti;
    LightLocation l_Right;
    CleanThunderManager *CTM;
    BeterGame &operator()(int _dummy);
    int main();

    int showMuti();

    int selectText(int _index);

    BeterGame(CleanThunderManager *_CTM);

    int makerList();
    int snapshot();
    int overGame();

    int old1_0();
    int old1_1();
    int old1_2();
};