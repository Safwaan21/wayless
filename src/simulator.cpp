#include <SFML/Graphics.hpp>
// TODO: make pixel-to-meters conversion, create Vehicle using VehicleBuilder, add a clock, call update() each frame

int main()
{
    sf::RenderWindow window(sf::VideoMode({800, 600}), "Simulator");

    sf::CircleShape circle(10);
    circle.setFillColor(sf::Color::Green);

    window.setVerticalSyncEnabled(true);
    while (window.isOpen())
    {
        while (const std::optional event = window.pollEvent())
        {
            if (event->is<sf::Event::Closed>())
                window.close();
        }

        window.clear(sf::Color::Black);
        window.draw(circle);
        window.display();
    }

    return 0;
}
