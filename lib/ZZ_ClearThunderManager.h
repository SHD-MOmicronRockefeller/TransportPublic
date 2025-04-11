// ZZ_ClearThunderManager.h
#pragma once

#include "Block.h"
#include "GameRun.h"

class CleanThunderManager
{
public:
    int __system;

    int showMuti();
    int getCharInput();

    LightLocation l_Muti;
    LightLocation l_Home;
    int mutiManager();
    int selectText(int i);

    Bag bag;
    bool isCanOpen(bool isOut);
    int cantRunAfter();
    int intoHome();

    bool hasOld;
    Bag oldBag;
    vector<vector<Block>> blockArray;
    bool hasOldf(bool _out = false);

    bool setMode();
    bool resetMode();

    int exitGame();

    CleanThunderManager();
    ~CleanThunderManager();
};