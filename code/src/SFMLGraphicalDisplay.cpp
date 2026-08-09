#include "SFMLGraphicalDisplay.h"

void SFMLGraphicalDisplay::renderWindow()
{

}

void SFMLGraphicalDisplay::drawOnWindow()
{
    _didPlayerAlreadySpawned = false;
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

void SFMLGraphicalDisplay::drawPlayer()
{
    sf::Texture playerTexture;
    if (!playerTexture.loadFromFile(_sPlayerTextureFilepath))
    {
        std::cerr << "ERROR WHILE LOADING PLAYER SPRITE\n";
        return ;
    }
    sf::Sprite playerSprite;
    playerSprite.setTexture(playerTexture);
    playerSprite.setTextureRect(sf::IntRect(24, 36, 19U, 25U));
    playerSprite.setPosition(200, 150);
    // Zoom on the background
    float caracterScale = std::max(
        static_cast<float>(512) / 245,
        static_cast<float>(384) / 168
    );
    playerSprite.setScale(caracterScale, caracterScale);
    _pWindow->draw(playerSprite);
}

void SFMLGraphicalDisplay::finalRenderWindow()
{
    _pWindow->display();
}
