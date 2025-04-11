// GameRun.h
#include "_TheSource.h"
#include "Block.h"

class GameRun
{
public:
    int m_MapLen;
    int m_MapWid;

    bool m_IsThunderCalculate;
    int m_ThunderNum;
    GameRun &operator()(Bag &_copyText);
    GameRun &operator()(Bag &_copyText, vector<vector<Block>> &_copyBlock);
    vector<vector<Block>> blockArray;
    GameRun();

    int getCharInput();

    int makeMap();
    int main();

    LightLocation l_CityLen;
    LightLocation l_CityWid;
    int foot;

    int logic(int _logic_Num);
    int open();
    int reopen(int os_Len, int os_Wid);
    int mark();

    int isEnd(int _isEnd_Num);

    bool canResream(int judgeNum);
    int saveMap(int _saveMap_Num);
    int cleanSave(int _cleanSave_Num);

    int gameEnd(int _gameEnd_Num);
    int saveLine(int _saveLine_Num);

    vector<vector<Block>> mapArray;
    int setMap();

    int outTitle(const int cin_Num, int size = 2, int air = 2);
    int showMap(int condition);
};