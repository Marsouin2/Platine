#ifndef SFML_EVENT_MANAGER_H_
#define SFML_EVENT_MANAGER_H_

#include <SFML/Graphics.hpp>
#include <memory>

#include "IEventManager.h"

class SFMLEventManager : public IEventManager
{
public:
    SFMLEventManager() = default;
    virtual ~SFMLEventManager() = default;
    sf::Event& getEvent() { return pEvent; }

private:
    sf::Event pEvent;
};

#endif