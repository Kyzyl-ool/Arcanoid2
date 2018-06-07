//
//  MenuBackground.cpp
//  Arcanoid2
//
//  Created by Кежик Кызыл-оол on 07.06.2018.
//  Copyright © 2018 Кежик Кызыл-оол. All rights reserved.
//

#include "MenuBackground.hpp"

MenuBackground::MenuBackground()
{
    type = MENU_BACKGROUND;
    texture.loadFromFile(MENU_BACKGROUND_FILE);
    sprite.setTexture(texture);
    sprite.setScale(2, 2);
}

void MenuBackground::draw(sf::RenderWindow *window)
{
    window->draw(sprite);
}
