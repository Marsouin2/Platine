#include "PoolOfGameThingsManager.h"

PoolOfGameThingsManager::PoolOfGameThingsManager()
{
    instantiatePool();
}

void PoolOfGameThingsManager::instantiateMap()
{
    _arrayPoolOfGameThings[EGameThing::renderedMap]._texture;
}

void PoolOfGameThingsManager::instantiatePlayer()
{

}

void PoolOfGameThingsManager::instantiatePool()
{
    for (auto& it : _arrayPoolOfGameThings)
    {
        it = std::make_unique<IGameThing>();
    }

    instantiateMap();
    instantiatePlayer();
    // init map (there will always be a map)


    // init player (there will always be a player)
}