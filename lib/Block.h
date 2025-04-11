// Block.h
#pragma once

#include "_TheSource.h"

class Block
{
public:
    int m_LocationLen;
    int m_LocationWid;

    int m_AboutTunderNum;
    bool m_IsThunder;
    bool m_IsOpen;

    Block();
    ~Block();
};

class Bag
{
public:
    int m_MapLen;
    int m_MapWid;
    bool m_IsThunderCalculate;
    int m_ThunderNum;

    Bag();
};

class LightLocation
{
public:
    int lightLocation;
    int typeSize_Max;
    int typeSize_Min;
    int lightMore(int i = 1);
    int lightLess(int i = 1);
    LightLocation();
};

