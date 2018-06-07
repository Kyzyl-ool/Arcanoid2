//
//  Background.cpp
//  Arcanoid2
//
//  Created by Кежик Кызыл-оол on 18.05.2018.
//  Copyright © 2018 Кежик Кызыл-оол. All rights reserved.
//

#include "Background.hpp"

int get_background_coord_x(int the_type)
{
    return (((the_type % 8)+1)*BACKGROUND_DISTANCE + BACKGROUND_TEXTURE_SIZE*(the_type % 8));
}

int get_background_coord_y(int the_type)
{
    return ((the_type / 8)+1)*BACKGROUND_DISTANCE + BACKGROUND_TEXTURE_SIZE*(the_type / 8);
}

Background::Background(int the_type)
{
    type = BACKGROUND;
    sort = the_type;
    x = get_background_coord_x(sort);
    y = get_background_coord_y(sort);
    
    
    texture.loadFromFile(BACKGROUNDS_FILE);
    
    sprite.setTexture(texture);
    sprite.setTextureRect(sf::IntRect(x, y, BACKGROUND_TEXTURE_SIZE, BACKGROUND_TEXTURE_SIZE));
}

void Background::draw(sf::RenderWindow* window)
{
    sf::Vector2u WindowSize = window->getSize();
    
    for (int i = 0; i < WindowSize.x / BACKGROUND_TEXTURE_SIZE; i++)
        for (int j = 0; j < WindowSize.y / BACKGROUND_TEXTURE_SIZE + 1; j++)
        {
            sprite.setPosition(i*BACKGROUND_TEXTURE_SIZE + BACKGROUND_BORDER_THICKNESS, j*BACKGROUND_TEXTURE_SIZE);
            window->draw(sprite);
        }
}

void Background::set_number(int number)
{
    x = get_background_coord_x(number);
    y = get_background_coord_y(number);
    sprite.setTextureRect(sf::IntRect(x, y, BACKGROUND_TEXTURE_SIZE, BACKGROUND_TEXTURE_SIZE));
}
