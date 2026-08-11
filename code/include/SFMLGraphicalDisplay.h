#ifndef SFML_GRAPHICAL_DISPLAY_H_
#define SFML_GRAPHICAL_DISPLAY_H_

#include <iostream>
#include <SFML/Graphics.hpp>

#include "PoolOfGameThingsManager.h"
#include "SFMLEventManager.h"
#include "IGraphicalDisplay.h"
#include "MapContentReader.h"

class SFMLGraphicalDisplay : public IGraphicalDisplay
{
public:
    SFMLGraphicalDisplay() : _didPlayerAlreadySpawned(false)
    {
        _screenResolution.first = 512;
        _screenResolution.second = 384;
    }

    SFMLGraphicalDisplay(const int screenResolutionHeight, const int screenResolutionWidth) : _didPlayerAlreadySpawned(false)
    {
        _screenResolution.first = screenResolutionHeight;
        _screenResolution.second = screenResolutionWidth;
    }

    virtual ~SFMLGraphicalDisplay() = default;
    void renderWindow() override;
    void drawOnWindow() override;
    void drawMapBackground(const std::string& rMapFilepath);
    void drawPlayer();
    bool isWindowOpened() const { return _pWindow->isOpen(); }
    std::shared_ptr<sf::RenderWindow> getWindow() { return _pWindow; } // ADU : Attention je mets des shared ptr de partout !
    std::shared_ptr<SFMLEventManager> getSFMLEventManager() { return _pSFMLEventManager; }
    void finalRenderWindow();
    void setMapContentReader(std::shared_ptr<MapContentReader> pMapContentReader) { _pMapContentReader = pMapContentReader; };

private:
    PoolOfGameThingsManager _poolOfGameThingsManager;
    std::shared_ptr<sf::RenderWindow> _pWindow = std::make_shared<sf::RenderWindow>(sf::VideoMode(512, 384), "Changement de direction");
    std::pair<int, int> _screenResolution;
    std::shared_ptr<MapContentReader> _pMapContentReader;
    const std::string _sPlayerTextureFilepath = "resources/lucas.png";
    bool _didPlayerAlreadySpawned;
};

#endif