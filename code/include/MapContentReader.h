#ifndef _MAP_CONTENT_READER_H_
#define _MAP_CONTENT_READER_H_

#include <memory>
#include <iostream>
#include <fstream>
#include <iomanip>
#include <sstream>
#include <nlohmann/json.hpp>

#include "PointPosition.h"
#include "MapData.h"

class MapContentReader
{
public:
    MapContentReader();
    MapContentReader(std::string& mapNameToLoad);
    ~MapContentReader() = default;

private: // # functions
    void loadMapDataInternally(const std::string& mapNameToLoad);

private: // # attributes
    std::shared_ptr<MapData> _mapData;
    const std::string _veryFirstMapName = "resources/Player_First_Floor.json";
};

#endif