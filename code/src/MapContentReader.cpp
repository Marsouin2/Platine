#include "MapContentReader.h"

MapContentReader::MapContentReader() : _mapData(std::make_shared<MapData>())
{
    // # load the very first json map into MapData class
    loadMapDataInternally(_veryFirstMapName);
}

MapContentReader::MapContentReader(std::string& mapNameToLoad) : _mapData(std::make_shared<MapData>())
{
    // # load the json map content into MapData class
    loadMapDataInternally(mapNameToLoad);
}

void MapContentReader::loadMapDataInternally(const std::string& mapNameToLoad)
{
    // load the file containing map's data in MapData class
    std::fstream File;
    File.open(mapNameToLoad, std::ios::in);

    if (File.is_open())
    {
        nlohmann::json Doc{nlohmann::json::parse(File)};

        const auto bricks_json_data = Doc["name"];
        std::cout << "name = " << bricks_json_data << '\n';

        // height
        _mapData->setMapHeight(Doc["height"]);
        // width
        _mapData->setMapWidth(Doc["width"]);
        // player spawn pos
        PointPosition<double> playerSpawnPos(Doc["spawn"].at("x"), Doc["spawn"].at("y"));
        _mapData->setMapPlayerSpawnPos(playerSpawnPos);

        // music
        _mapData->setMapMusicFile(Doc["music"]);
        std::cout << "on a charge la musique du fichier et c'est desormais en interne donc c'est : " << _mapData->getMapMusicFilename() << '\n';

        const auto tiles_json_data = Doc["tiles"];
        std::vector<std::vector<char>> tempoVectorMapTile;
        for (size_t i = 0; i < _mapData->getMapHeight(); ++i)
        {
            tempoVectorMapTile.push_back(tiles_json_data.at(0));
        }
        _mapData->setMapTile(std::move(tempoVectorMapTile));
        //std::cout << "tiles = " << tiles_json_data << '\n';
      }
    else
    {
        std::cerr << "MapContentReader::MapContentReader() : Failed to open file : " << mapNameToLoad << " do not exist !\n";
    }
}