#ifndef LIVING_CHARACTER_H_
#define LIVING_CHARACTER_H_

#include "IGameThing.h"

class LivingCharacter : public IGameThing
{
public:
    LivingCharacter() = default;
    virtual ~LivingCharacter() = default;

private:
    uint32_t _id;
    // _position;
    // sf::Texture _texture;
    // sf::Sprite _sprite;
};

#endif