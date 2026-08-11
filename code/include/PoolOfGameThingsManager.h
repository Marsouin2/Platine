#ifndef POOL_OF_GAME_THINGS_MANAGER_H_
#define POOL_OF_GAME_THINGS_MANAGER_H_

#include <array>
#include <memory>

#include "IGameThing.h"
#include "MapContentReader.h"

enum class EGameThing
{
    renderedMap = 0,
    player = 1
};

class PoolOfGameThingsManager
{
public:
    PoolOfGameThingsManager();
    ~PoolOfGameThingsManager() = default;
    void instantiatePool();

private: // ## functions
    void instantiateMap();

private:
    std::shared_ptr<MapContentReader> _pMapContentReader;
    const uint32_t _poolSize = 40U;
    std::array<std::unique_ptr<IGameThing>, _poolSize> _arrayPoolOfGameThings;
};

#endif