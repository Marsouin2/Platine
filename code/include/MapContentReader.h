#ifndef _MAP_CONTENT_READER_H_
#define _MAP_CONTENT_READER_H_

#include <memory>
#include <iostream>
#include <fstream>
#include <iomanip>
#include <sstream>
#include <nlohmann/json.hpp>

#include "MapData.h"

class MapContentReader
{
public:
    MapContentReader();
    MapContentReader(std::string mapNameToLoad);
    ~MapContentReader() = default;

private:
    std::shared_ptr<MapData> _mapData;
};

#endif