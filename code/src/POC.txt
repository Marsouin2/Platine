#include <SFML/Graphics.hpp>
#include <iostream>

enum Direction {
    Down,
    DownWalkOne,
    DownWalkTwo,
    Right,
    RightWalkOne,
    RightWalkTwo,
    Up,
    UpWalkOne,
    UpWalkTwo,
    Left,
    LeftWalkOne,
    LeftWalkTwo
};

bool canPlayerMoveToWantedDirection(const int &rWantedPlayerPosX, const int &rWantedPlayerPosY)
{
    bool retVal = true;

    if ((rWantedPlayerPosX < 110) || (rWantedPlayerPosX > 395) || (rWantedPlayerPosY < 105) || (rWantedPlayerPosY > 280))
    {
        retVal = false;
    }

    return retVal;
}

void handlePlayerMovementAndSprite(sf::Event &event, sf::Clock &animClock, bool &isWalkOneAlreadyDisplayed, int &playerPosX, int &playerPosY, Direction &currentDir)
{
    // Détection des touches
    if (event.type == sf::Event::KeyPressed) 
    {
        if (event.key.code == sf::Keyboard::Down)
        {
            sf::Time elapsed1 = animClock.getElapsedTime();
            if (elapsed1.asSeconds() > 0.15f) // every 1s -> change sprite
            {
                if ((currentDir == Down) && (isWalkOneAlreadyDisplayed))
                {
                    currentDir = DownWalkTwo;
                    isWalkOneAlreadyDisplayed = false;
                }
                else if (currentDir == Down)
                {
                    currentDir = DownWalkOne;
                    isWalkOneAlreadyDisplayed = true;
                }
                else
                {
                    currentDir = Down;
                }
                animClock.restart();
            }
            if (canPlayerMoveToWantedDirection(playerPosX, playerPosY + 5))
                playerPosY += 5;
        }
        else if (event.key.code == sf::Keyboard::Right)
        {
            sf::Time elapsed1 = animClock.getElapsedTime();
            if (elapsed1.asSeconds() > 0.15f) // every 1s -> change sprite
            {
                if ((currentDir == Right) && (isWalkOneAlreadyDisplayed))
                {
                    currentDir = RightWalkTwo;
                    isWalkOneAlreadyDisplayed = false;
                }
                else if (currentDir == Right)
                {
                    currentDir = RightWalkOne;
                    isWalkOneAlreadyDisplayed = true;
                }
                else
                {
                    currentDir = Right;
                }
                animClock.restart();
            }
            if (canPlayerMoveToWantedDirection(playerPosX + 5, playerPosY))
                playerPosX += 5;
        }
        else if (event.key.code == sf::Keyboard::Up)
        {
            sf::Time elapsed1 = animClock.getElapsedTime();
            if (elapsed1.asSeconds() > 0.15f) // every 1s -> change sprite
            {
                if ((currentDir == Up) && (isWalkOneAlreadyDisplayed))
                {
                    currentDir = UpWalkTwo;
                    isWalkOneAlreadyDisplayed = false;
                }
                else if (currentDir == Up)
                {
                    currentDir = UpWalkOne;
                    isWalkOneAlreadyDisplayed = true;
                }
                else
                {
                    currentDir = Up;
                }
                animClock.restart();
            }
            if (canPlayerMoveToWantedDirection(playerPosX, playerPosY - 5))
                playerPosY -= 5;
        }
        else if (event.key.code == sf::Keyboard::Left)
        {
            sf::Time elapsed1 = animClock.getElapsedTime();
            if (elapsed1.asSeconds() > 0.15f) // every 1s -> change sprite
            {
                if ((currentDir == Left) && (isWalkOneAlreadyDisplayed))
                {
                    currentDir = LeftWalkTwo;
                    isWalkOneAlreadyDisplayed = false;
                }
                else if (currentDir == Left)
                {
                    currentDir = LeftWalkOne;
                    isWalkOneAlreadyDisplayed = true;
                }
                else
                {
                    currentDir = Left;
                }
                animClock.restart();
            }
            if (canPlayerMoveToWantedDirection(playerPosX - 5, playerPosY))
                playerPosX -= 5;
        }
    }
}

int main()
{
    sf::RenderWindow window(sf::VideoMode(512, 384), "Changement de direction");
    sf::Texture texture;
    sf::Texture texture2;

    if (!texture.loadFromFile("resources/lucas.png"))
        return -1;

    if (!texture2.loadFromFile("resources/Player_House.png"))
        return -1;

    sf::Sprite sprite;
    sprite.setTexture(texture);

    sf::Sprite backgroundSprite;
    backgroundSprite.setTexture(texture2);

    // Dimensions d’un sprite
    const int SPRITE_W = 19;
    const int SPRITE_H = 25;

    int playerPosX = 200;
    int playerPosY = 100;

    // Position "pivot" du sprite dans l’image globale
    const sf::Vector2i SPRITE_ORIGIN_GLOBAL(34, 50); // pied du sprite

    // Dictionnaire des coordonnées selon la direction
    std::map<Direction, sf::Vector2i> directionCoords = {
        {Down,  {24, 36}},
        {DownWalkOne, {60, 36}},
        {DownWalkTwo, {95, 36}},
        {Right, {130, 37}},
        {RightWalkOne, {164, 37}},
        {RightWalkTwo, {199, 37}},
        {Up,    {234, 37}},
        {UpWalkOne, {270, 37}},
        {UpWalkTwo, {305, 37}},
        {Left, {340, 37}},
        {LeftWalkOne, {376, 37}},
        {LeftWalkTwo, {411, 37}}
    };

    Direction currentDir = Down;

    // --- Initialisation
    sf::Vector2i pos = directionCoords[currentDir];
                                                // 262 = start from where picture is taken 5 is same but vertically
    backgroundSprite.setTextureRect(sf::IntRect(262, 5, 245, 168));
    backgroundSprite.setPosition(0, 0);

    // Zoom on the background
    float backgroundScale = std::max(
        static_cast<float>(512) / 245,
        static_cast<float>(384) / 168
    );
    backgroundSprite.setScale(backgroundScale, backgroundScale);

    sprite.setTextureRect(sf::IntRect(pos.x, pos.y, SPRITE_W, SPRITE_H));
    sprite.setPosition(playerPosX, playerPosY);
    // Zoom on the background
    float caracterScale = std::max(
        static_cast<float>(512) / 245,
        static_cast<float>(384) / 168
    );
    sprite.setScale(caracterScale, caracterScale);

    sf::Clock animClock; // timer to time sprite animations
    bool isWalkOneAlreadyDisplayed = false;
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();

            handlePlayerMovementAndSprite(event, animClock, isWalkOneAlreadyDisplayed, playerPosX, playerPosY, currentDir);

            // Mettre à jour le sprite
            sf::Vector2i pos = directionCoords[currentDir];
            sprite.setTextureRect(sf::IntRect(pos.x, pos.y, SPRITE_W, SPRITE_H));
            sprite.setPosition(playerPosX, playerPosY);
            backgroundSprite.setTextureRect(sf::IntRect(262, 5, 245, 168));
        }

        window.clear(sf::Color::Black);
        window.draw(backgroundSprite);
        window.draw(sprite);
        window.display();
    }

    return 0;
}
