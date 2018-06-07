//
//  MenuButton.hpp
//  Arcanoid2
//
//  Created by Кежик Кызыл-оол on 07.06.2018.
//  Copyright © 2018 Кежик Кызыл-оол. All rights reserved.
//

#ifndef MenuButton_hpp
#define MenuButton_hpp


#include "Button.hpp"
#include <string>
#include <SFML/Graphics.hpp>

class MenuButton: public Button
{
private:
    sf::Color BorderColor;
    sf::Color TextColor;
    sf::RectangleShape Rect;
    sf::Text TheText;
    
public:
    MenuButton(float ix, float iy, std::string text, sf::Color iBorderColor, sf::Color iTextColor);
    void Action();
    void Draw(sf::RenderWindow* window);
};

#endif /* MenuButton_hpp */
