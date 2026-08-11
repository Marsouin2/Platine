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

private: // ## functions
    void loadNewMap(const std::string& rNewMapFilepathToLoad);

private: // ## attributs
    std::shared_ptr<MapContentReader> _pMapContentReader;
    SFMLGraphicalDisplay _sfmlGraphicalDisplay;
};

#endif