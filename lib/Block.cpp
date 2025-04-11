// Block.cpp
#include "Block.h"
#include "_TheSource.h"

Block::Block()
{
    this->m_LocationLen = -1;
    this->m_LocationWid = -1;
    this->m_AboutTunderNum = 0;
    this->m_IsThunder = false;
    this->m_IsOpen = false;
    return;
}

Block::~Block()
{
    this->m_LocationLen = -1;
    this->m_LocationWid = -1;
    this->m_AboutTunderNum = 0;
    this->m_IsThunder = false;
    this->m_IsOpen = false;
    return;
}

Bag::Bag()
{
    this->m_IsThunderCalculate = false;
    this->m_MapLen = 0;
    this->m_MapWid = 0;
    this->m_ThunderNum = 0;
    return;
}

int LightLocation::lightMore(int i)
{
    if (this->typeSize_Max == this->typeSize_Min)
    {
        cout << "error: typeSize_Max == typeSize_Min" << endl;
        return 0;
    }
    this->lightLocation += i;
    while (this->lightLocation > this->typeSize_Max)
    {
        this->lightLocation -= (this->typeSize_Max - this->typeSize_Min + 1);
    }
    while (this->lightLocation < this->typeSize_Min)
    {
        this->lightLocation += (this->typeSize_Max - this->typeSize_Min + 1);
    }
    return this->lightLocation;
}

int LightLocation::lightLess(int i)
{
    if (this->typeSize_Max == this->typeSize_Min)
    {
        cout << "error: typeSize_Max == typeSize_Min" << endl;
        return 0;
    }
    this->lightLocation -= i;
    while (this->lightLocation > this->typeSize_Max)
    {
        this->lightLocation -= (this->typeSize_Max - this->typeSize_Min + 1);
    }
    while (this->lightLocation < this->typeSize_Min)
    {
        this->lightLocation += (this->typeSize_Max - this->typeSize_Min + 1);
    }
    return this->lightLocation;
}

LightLocation::LightLocation()
{
    this->lightLocation = 0;
    this->typeSize_Max = 0;
    this->typeSize_Min = 0;
    return;
}