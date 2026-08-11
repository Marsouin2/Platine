#ifndef SFML_INSTANTIATOR_H_
#define SFML_INSTANTIATOR_H_

#include <SFML/Graphics.hpp>

class SFMLInstantiator
{
public:
    SFMLInstantiator() = default;
    ~SFMLInstantiator() = default;
    void instantiateSFMLSprite(const sf::Texture& rTexture, const std::string& rTextureFilepath, const sf::Sprite& rSpriteOut);

private:
};

#endif