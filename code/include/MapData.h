#ifndef _MAP_DATA_H_
#define _MAP_DATA_H_

#include <string>
#include <vector>

#include "PointPosition.h"

class MapData
{
public:
    MapData();
    ~MapData() = default;

    // # setter
    void setMapFilename(const std::string& rNewMapFilename) { _mapFilename = rNewMapFilename; }
    void setMapMusicFile(const std::string& newMapMusicFilename) { _mapMusicFilename = newMapMusicFilename; }
    void setMapHeight(const double dNewMapHeight) { _mapHeight = dNewMapHeight; }
    void setMapWidth(const double dNewMapWidth) { _mapWidth = dNewMapWidth; }
    void setMapPlayerSpawnPos(const PointPosition<double> newMapPlayerSpawnPos) { _mapPlayerSpawnPos = newMapPlayerSpawnPos; }
    void setMapTile(const std::vector<std::vector<char>> newMapTile) { _mapTile = std::move(newMapTile); }

    // # getter
    const std::string getMapFilename() const { return _mapFilename; }
    const std::string getMapMusicFilename() const { return _mapMusicFilename; }
    const double getMapHeight() const { return _mapHeight; }
    const double getMapWidth() const { return _mapWidth; }
    const PointPosition<double> getMapPlayerSpawnPos() const { return _mapPlayerSpawnPos; }

private: // # functions

private: // # attributes
    std::string _mapFilename;
    std::string _mapMusicFilename; // ADU : mettre des float au lieu des double pour utiliser moins de memoire ?
    double _mapHeight;
    double _mapWidth;
    PointPosition<double> _mapPlayerSpawnPos;
    [[maybe_unused]]double _mapWarpPos;
    std::vector<std::vector<char>> _mapTile; // ADU : vu qu'on connaitra la taille de la map au moment ou on parse le fichier un std::array est ptet mieux ?
    // npc list containing all NPC + their informations
};

#endif