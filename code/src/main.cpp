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

    if (!texture.loadFromFile("resources/lucas.png"))
        return -1;

    sf::Sprite sprite;
    sprite.setTexture(texture);

    // Dimensions d’un sprite
    const int SPRITE_W = 19;
    const int SPRITE_H = 25;

    // Position "pivot" du sprite dans l’image globale
    const sf::Vector2i SPRITE_ORIGIN_GLOBAL(34, 50); // pied du sprite
    const sf::Vector2i SPRITE_OFFSET(0, 0); // sera calculé pour chaque frame

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
    sprite.setTextureRect(sf::IntRect(pos.x, pos.y, SPRITE_W, SPRITE_H));
    sprite.setOrigin(SPRITE_ORIGIN_GLOBAL.x - pos.x, SPRITE_ORIGIN_GLOBAL.y - pos.y);
    sprite.setPosition(400, 300);

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();

            // Détection des touches
            if (event.type == sf::Event::KeyPressed) {
                if (event.key.code == sf::Keyboard::Down)
                    currentDir = Down;
                else if (event.key.code == sf::Keyboard::Right)
                    currentDir = Right;
                else if (event.key.code == sf::Keyboard::Up)
                    currentDir = Up;
                else if (event.key.code == sf::Keyboard::Left)
                    currentDir = Left;

                // Mettre à jour le sprite
                sf::Vector2i pos = directionCoords[currentDir];
                sprite.setTextureRect(sf::IntRect(pos.x, pos.y, SPRITE_W, SPRITE_H));
                //sprite.setOrigin(SPRITE_ORIGIN_GLOBAL.x - pos.x, SPRITE_ORIGIN_GLOBAL.y - pos.y);
            }
        }

        window.clear(sf::Color::Black);
        window.draw(sprite);
        window.display();
    }

    return 0;
}
