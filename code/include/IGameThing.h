#ifndef I_GAME_THING_H_
#define I_GAME_THING_H_

#include <cstdint>
#include <SFML/Graphics.hpp>

class IGameThing
{
public:
    IGameThing() = default;
    virtual ~IGameThing() = default;

private:
    uint32_t _id; // all GameThings got an id
    sf::Texture _texture; // all GameThings got a texture
    sf::Sprite _sprite; // all GameThings got a sprite
};

#endif