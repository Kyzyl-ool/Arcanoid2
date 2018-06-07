//
//  Brick.cpp
//  Arcanoid2
//
//  Created by Кежик Кызыл-оол on 18.05.2018.
//  Copyright © 2018 Кежик Кызыл-оол. All rights reserved.
//

#include "Brick.hpp"
#include "GameManager.hpp"

int get_brick_coord_x(int sort)
{
    return sort*BLOCK_WIDTH/2;
}
int get_brick_coord_y(int health)
{
    return (health-1)*BLOCK_HEIGHT/2;
}

Brick::Brick(int the_sort, int ix, int iy, void* GM):
sort(the_sort),
health(1),
GM(GM)
{
    type = BLOCK;
    
    x = ix;
    y = iy;
    
    texture.loadFromFile(DEFAULT_BLOCKS_FILE);
    sprite.setTexture(texture);
    sprite.setTextureRect(sf::IntRect(
                                      get_brick_coord_x(sort),
                                      get_brick_coord_y(health),
                                      BLOCK_WIDTH/2,
                                      BLOCK_HEIGHT/2));
    sprite.setScale(2, 2);
    sprite.setPosition(x, y);
    
    collisionRectangles[0] = {x, y+BLOCK_HEIGHT, x+BLOCK_WIDTH, y+BLOCK_HEIGHT+BALL_SIZE/2};
    collisionRectangles[1] = {x - BALL_SIZE/2, y, x, y + BLOCK_HEIGHT};
    collisionRectangles[2] = {x + BLOCK_WIDTH, y, x + BLOCK_WIDTH + BALL_SIZE/2, y + BLOCK_HEIGHT};
    collisionRectangles[3] = {x, y - BALL_SIZE/2, x + BLOCK_WIDTH, y};
    
}

void Brick::update(float)
{
    if (health <= 0)
    {
        active = false;
        ((GameManager* )GM)->BrickDestroyed();
    }
    else
    {
        sprite.setTextureRect(sf::IntRect(
                                          get_brick_coord_x(sort),
                                          get_brick_coord_y(health),
                                          BLOCK_WIDTH/2,
                                          BLOCK_HEIGHT/2));
    }
}

void Brick::draw(sf::RenderWindow* window)
{
    window->draw(sprite);
}

void Brick::getDamage()
{
    if (health > 0)
        health--;
}

void Brick::collideResponse(GameObject *obj)
{
    switch (obj->who())
    {
        case BALL:
            getDamage();
            break;
        default:
            break;
    }
}

Rect Brick::getRect(int n)
{
    assert(n < BRICK_AMOUNT_OF_COLLISION_RECTANGLES && n >= 0);
    return collisionRectangles[n];
}

void Brick::setSort(int isort)
{
    sort = isort;
}

void Brick::setHealth(int ihealth)
{
    health = ihealth;
}
