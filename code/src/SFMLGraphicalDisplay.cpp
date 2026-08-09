#include "SFMLGraphicalDisplay.h"

void SFMLGraphicalDisplay::renderWindow()
{

}

void SFMLGraphicalDisplay::drawOnWindow()
{

}

void SFMLGraphicalDisplay::drawMapBackground(const std::string& rMapFilepath)
{
    // creer et charger la texture
    sf::Texture texture;
    if (!texture.loadFromFile(rMapFilepath))
        return ;
    // creer et charger le sprite
    sf::Sprite backgroundSprite;
    backgroundSprite.setTexture(texture);
    backgroundSprite.setTextureRect(sf::IntRect(262, 5, 245, 168));
    backgroundSprite.setPosition(0, 0);
    // Zoom on the background
    float backgroundScale = std::max(
        static_cast<float>(512) / 245,
        static_cast<float>(384) / 168
    );
    backgroundSprite.setScale(backgroundScale, backgroundScale);
    backgroundSprite.setTextureRect(sf::IntRect(262, 5, 245, 168));
    _pWindow->draw(backgroundSprite);
    // draw
}

void SFMLGraphicalDisplay::finalRenderWindow()
{
    _pWindow->display();
}
