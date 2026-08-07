#include <iostream>

#include "MapContentReader.h"
#include "SFMLGraphicalDisplay.h"

int main()
{
    MapContentReader mapContentReader;

    SFMLGraphicalDisplay sfmlGraphicalDisplay;

    //sfmlGraphicalDisplay.runGame(); // ADU : faire la boucle de gameplay ailleurs que dans le main (nouvelle classe ?)

    while (sfmlGraphicalDisplay.isWindowOpened())
    {
        while (sfmlGraphicalDisplay.getWindow()->pollEvent(sfmlGraphicalDisplay.getSFMLEventManager()->getEvent()))
        {
            if (sfmlGraphicalDisplay.getSFMLEventManager()->getEvent().type == sf::Event::Closed)
                sfmlGraphicalDisplay.getWindow()->close();
        }

        sfmlGraphicalDisplay.drawMapBackground(mapContentReader.getMapData()->getMapFilename());
        sfmlGraphicalDisplay.getWindow()->clear(sf::Color::Black);
    }   

    return 0;
}