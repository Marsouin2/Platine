#include <SFML/Graphics.hpp>

int main()
{
    // Créer une fenêtre SFML
    sf::RenderWindow window(sf::VideoMode(800, 600), "SFML Window");

    // Créer un cercle
    sf::CircleShape circle(50);
    circle.setFillColor(sf::Color::Red);
    circle.setPosition(375, 275); // Position au centre de la fenêtre

    // Boucle principale
    while (window.isOpen())
    {
        // Gérer les événements
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        // Effacer l'écran
        window.clear(sf::Color::Black);

        // Dessiner le cercle
        window.draw(circle);

        // Afficher tout ce qui a été dessiné
        window.display();
    }

    return 0;
}
