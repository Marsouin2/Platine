#include "GameMgr.h"

GameMgr::GameMgr()
{
}

void GameMgr::run()
{
    while (sfmlGraphicalDisplay.isWindowOpened()) // ADU : il ne faut pas creer 40 trucs ou faire 40 operations dans le while pendant le jeu sinon ca va le faire en boucle
    {
        while (sfmlGraphicalDisplay.getWindow()->pollEvent(sfmlGraphicalDisplay.getSFMLEventManager()->getEvent()))
        {
            if (sfmlGraphicalDisplay.getSFMLEventManager()->getEvent().type == sf::Event::Closed)
                sfmlGraphicalDisplay.getWindow()->close();
        }

        sfmlGraphicalDisplay.getWindow()->clear(sf::Color::Black);
        sfmlGraphicalDisplay.drawMapBackground("resources/" + mapContentReader.getMapData()->getMapFilename()); // ici par exemple on charge en boucle le fichier
        sfmlGraphicalDisplay.drawPlayer();
        sfmlGraphicalDisplay.finalRenderWindow();
    }
}