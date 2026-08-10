#ifndef GAME_MGR_H_
#define GAME_MGR_H_

#include "MapContentReader.h"
#include "SFMLGraphicalDisplay.h"
#include "PoolOfGameThingsManager.h"

class GameMgr
{
public:
    GameMgr();
    ~GameMgr() = default;
    void run();

private:
    MapContentReader mapContentReader;
    SFMLGraphicalDisplay sfmlGraphicalDisplay;
    PoolOfGameThingsManager _poolOfGameThingsManager;
};

#endif