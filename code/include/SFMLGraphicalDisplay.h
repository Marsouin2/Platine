#ifndef SFML_GRAPHICAL_DISPLAY_H_
#define SFML_GRAPHICAL_DISPLAY_H_

#include <SFML/Graphics.hpp>

#include "SFMLEventManager.h"
#include "IGraphicalDisplay.h"

class SFMLGraphicalDisplay : public IGraphicalDisplay
{
public:
    SFMLGraphicalDisplay()
    {
        _screenResolution.first = 512;
        _screenResolution.second = 384;
    }

    SFMLGraphicalDisplay(const int screenResolutionHeight, const int screenResolutionWidth)
    {
        _screenResolution.first = screenResolutionHeight;
        _screenResolution.second = screenResolutionWidth;
    }

    virtual ~SFMLGraphicalDisplay() = default;
    void renderWindow() override;
    void drawOnWindow() override;
    bool isWindowOpened() const { return _pWindow->isOpen(); }
    std::shared_ptr<sf::RenderWindow> getWindow() { return _pWindow; } // ADU : Attention je mets des shared ptr de partout !
    std::shared_ptr<SFMLEventManager> getSFMLEventManager() { return _pSFMLEventManager; }

private:
    std::shared_ptr<sf::RenderWindow> _pWindow = std::make_shared<sf::RenderWindow>(sf::VideoMode(512, 384), "Changement de direction");
    std::shared_ptr<SFMLEventManager> _pSFMLEventManager = std::make_shared<SFMLEventManager>();
    std::pair<int, int> _screenResolution;
};

#endif