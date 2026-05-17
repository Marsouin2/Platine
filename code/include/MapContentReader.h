#ifndef _MAP_CONTENT_READER_H_
#define _MAP_CONTENT_READER_H_

#include <memory>

#include "MapData.h"

class MapContentReader
{
public:
    MapContentReader() = default;
    ~MapContentReader() = default;

private:
    std::shared_ptr<MapData> _mapData;
};

#endif