#include "SFMLInstantiator.h"

void SFMLInstantiator::instantiateSFMLSprite(const sf::Texture& rTexture, const std::string& rTextureFilepath, const sf::Sprite& rSpriteOut)
{
    if (!rTexture.loadFromFile(rTextureFilepath))
        return ;
    rSpriteOut.setTexture(rTexture);
}