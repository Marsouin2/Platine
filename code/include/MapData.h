#ifndef _MAP_DATA_H_
#define _MAP_DATA_H_

#include <string>
#include <vector>

class MapData
{
public:
    MapData(const std::string mapNameToLoad);
    ~MapData() = default;

private:
    [[maybe_unused]]std::string _mapMusicFile;
    [[maybe_unused]]double _mapHeight;
    [[maybe_unused]]double _mapWidth;
    [[maybe_unused]]double _mapPlayerSpawnPos;
    [[maybe_unused]]double _mapWarpPos;
    std::vector<std::vector<char>> _mapTile;
    // npc list containing all NPC + their informations
};

#endif