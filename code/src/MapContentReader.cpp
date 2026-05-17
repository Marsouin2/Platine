#include "MapContentReader.h"

MapContentReader::MapContentReader()
{
    std::fstream File;
    File.open("resources/Player_House.json", std::ios::in);

    if (File.is_open())
    {
        nlohmann::json Doc{nlohmann::json::parse(File)};
  
        std::cout << Doc.dump(2);
    }
    else
    {
        std::cerr << "MapContentReader::MapContentReader() : Failed to open file : resources/Player_House.json do not exist !\n";
    }
}

MapContentReader::MapContentReader(std::string mapNameToLoad) : _mapData(std::make_shared<MapData>(mapNameToLoad))
{

}