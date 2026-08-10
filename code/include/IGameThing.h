#ifndef I_GAME_THING_H_
#define I_GAME_THING_H_

#include <cstdint>

class IGameThing
{
public:
    IGameThing() = default;
    virtual ~IGameThing() = default;

private:
    uint32_t _id;
};

#endif