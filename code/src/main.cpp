#include <iostream>

#include "MapContentReader.h"
#include "SFMLGraphicalDisplay.h"

int main()
{
    MapContentReader mapContentReader;

    SFMLGraphicalDisplay sfmlGraphicalDisplay;

    while (sfmlGraphicalDisplay.isWindowOpened())
    {
        while (sfmlGraphicalDisplay.getWindow()->pollEvent(sfmlGraphicalDisplay.getSFMLEventManager()->getEvent()))
        {
            if (sfmlGraphicalDisplay.getSFMLEventManager()->getEvent().type == sf::Event::Closed)
                sfmlGraphicalDisplay.getWindow()->close();
        }
    }

    /*while (window.isOpen())
    {
        // gameplay loop
    }*/

    // dealocate everything needed
    return 0;
}