// SetMode.h
#pragma once

#include "_TheSource.h"
#include "Block.h"
#include "ZZ_ClearThunderManager.h"

class SetMode
{
public:
    CleanThunderManager *CTM;
    LightLocation l_Muti;
    LightLocation l_Right;
    SetMode &operator()(int _dummy);
    int showMuti();

    int main();
    int selectText(int _index);
    int thunderNumber();

    SetMode(CleanThunderManager *_CTM);
};