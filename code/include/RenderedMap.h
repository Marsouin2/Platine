#ifndef RENDERED_MAP_H_
#define RENDERED_MAP_H_

#include <SFML/Graphics.hpp>

#include "IGameThing.h"

class RenderedMap : public IGameThing
{
private:
    RenderedMap() = default;
    virtual ~RenderedMap() = default;

public:
    uint32_t _id;
    sf::Texture _texture;
    sf::Sprite _sprite;
};

#endif