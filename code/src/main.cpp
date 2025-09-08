#include <SFML/Graphics.hpp>

enum Direction {
    Down,
    Right,
    Up,
    Left
};

int main() {
    sf::RenderWindow window(sf::VideoMode(800, 600), "Changement de direction");
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

    int playerPosX = 400;
    int playerPosY = 300;

    // Position "pivot" du sprite dans l’image globale
    const sf::Vector2i SPRITE_ORIGIN_GLOBAL(34, 50); // pied du sprite

    // Dictionnaire des coordonnées selon la direction
    std::map<Direction, sf::Vector2i> directionCoords = {
        {Down,  {24, 36}},
        {Right, {130, 37}},
        {Up,    {234, 37}},
        {Left,  {340, 37}}
    };

    Direction currentDir = Down;

    // --- Initialisation
    sf::Vector2i pos = directionCoords[currentDir];
    backgroundSprite.setTextureRect(sf::IntRect(0, 0, 500, 200));
    backgroundSprite.setPosition(0, 0);
    sprite.setTextureRect(sf::IntRect(pos.x, pos.y, SPRITE_W, SPRITE_H));
    sprite.setPosition(playerPosX, playerPosY);


    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();

            // Détection des touches
            if (event.type == sf::Event::KeyPressed) {
                if (event.key.code == sf::Keyboard::Down)
                {
                    currentDir = Down;
                    playerPosY += 5;
                }
                else if (event.key.code == sf::Keyboard::Right)
                {
                    currentDir = Right;
                    playerPosX += 5;
                }
                else if (event.key.code == sf::Keyboard::Up)
                {
                    currentDir = Up;
                    playerPosY -= 5;
                }
                else if (event.key.code == sf::Keyboard::Left)
                {
                    currentDir = Left;
                    playerPosX -= 5;
                }

                // Mettre à jour le sprite
                sf::Vector2i pos = directionCoords[currentDir];
                sprite.setTextureRect(sf::IntRect(pos.x, pos.y, SPRITE_W, SPRITE_H));
                sprite.setPosition(playerPosX, playerPosY);
                backgroundSprite.setTextureRect(sf::IntRect(0, 0, 500, 200));
            }
        }

        window.clear(sf::Color::Black);
        window.draw(backgroundSprite);
        window.draw(sprite);
        window.display();
    }

    return 0;
}
