//
//  MenuButton.cpp
//  Arcanoid2
//
//  Created by Кежик Кызыл-оол on 07.06.2018.
//  Copyright © 2018 Кежик Кызыл-оол. All rights reserved.
//

#include "MenuButton.hpp"

#define MENU_BUTTON_WIDTH   200
#define MENU_BUTTON_HEIGHT  40
#define MENU_BUTTON_FONT_SIZE 20

MenuButton::MenuButton(float ix, float iy, std::string text, sf::Color iBorderColor, sf::Color iTextColor):
TheText(sf::Text(text, Font, MENU_BUTTON_FONT_SIZE)),
BorderColor(iBorderColor),
TextColor(iTextColor)
{
    x = ix;
    y = iy;
    width = MENU_BUTTON_WIDTH;
    height = MENU_BUTTON_HEIGHT;
    
    Rect = sf::RectangleShape(sf::Vector2f(width, height));
    Rect.setFillColor(BorderColor);
    Rect.setPosition(x, y);
    
    TheText.setPosition(x, y+7);
}

void MenuButton::Action()
{
    
}

void MenuButton::Draw(sf::RenderWindow *window)
{
    window->draw(Rect);
    window->draw(TheText);
}
