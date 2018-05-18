//
//  Board.cpp
//  Arcanoid2
//
//  Created by Кежик Кызыл-оол on 18.05.2018.
//  Copyright © 2018 Кежик Кызыл-оол. All rights reserved.
//

#include "Board.hpp"

Board::Board():
length(SUPPORT_NORMAL),
screen_size(DEFAULT_SCREEN_WIDTH)
{
    type = SUPPORT;
    
    x = 0;
    y = DEFAULT_SCREEN_HEIGHT - SUPPORT_HEIGHT;
    
    texture.loadFromFile(BOARD_FILE);
    sprite.setTexture(texture);
    sprite.setTextureRect(sf::IntRect(0, 0, 44, 22));
    
    sprite2.setTexture(texture);
    sprite2.setTextureRect(sf::IntRect(0, 0, 44, 22));
    sprite2.setScale(-1, 1);
}

double Board::getVelocity()
{
    return velocity;
}

void Board::update(float dt)
{
    if (x >= 0 && x + length <= screen_size)
        x += velocity*dt;
    else
    {
        velocity = 0;
        if (x < 0)
            x = 0;
        else
            x = screen_size - length;
    }
    
    sprite.setPosition(x, y);
    sprite2.setPosition(x+length, y);
}

void Board::dump()
{
    std::cout << "vel: " << velocity << std::endl;
}


//КОРЯВАЯ ФУНКЦИЯ
void Board::reduceVelocity()
{
    velocity = velocity / 4;
}

void Board::setVelocity(double v)
{
    velocity = v;
}

void Board::draw(sf::RenderWindow* window)
{
    window->draw(sprite);
    window->draw(sprite2);
}

int Board::getLength()
{
    return length;
}
