#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include "GameManager.hpp"
// Here is a small helper for you! Have a look.
#include "ResourcePath.hpp"

int main(int, char const**)
{
    // Create the main window
    sf::RenderWindow window(sf::VideoMode(800, 600), "Arcanoid");

//    window.setFramerateLimit(60);
    
    // Set the Icon
    sf::Image icon;
    if (!icon.loadFromFile(resourcePath() + "icon.png")) {
        return EXIT_FAILURE;
    }
    window.setIcon(icon.getSize().x, icon.getSize().y, icon.getPixelsPtr());
    
    window.setIcon(icon.getSize().x, icon.getSize().y, icon.getPixelsPtr());
    
    GameManager TheGame(&window);
    TheGame.RunGame();
    
    
    return EXIT_SUCCESS;
}
