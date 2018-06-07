//
//  Ball.cpp
//  Arcanoid2
//
//  Created by Кежик Кызыл-оол on 18.05.2018.
//  Copyright © 2018 Кежик Кызыл-оол. All rights reserved.
//

#include "Ball.hpp"
#include "Board.hpp"
#include "Brick.hpp"
#include <cmath>
#include "GameManager.hpp"

int get_ball_coord_x(int the_type)
{
    return (the_type%3)*BALL_SIZE*5;
}

int get_ball_coord_y(int the_type)
{
    return 588+(the_type/3)*BALL_SIZE*5;
}

Ball::Ball(void* GM):
f(NULL_DESTINATION),
GM(GM)
{
    type = BALL;
    texture.loadFromFile(BLOCKS_AND_BALLS_FILE);
    sprite.setTexture(texture);
    sprite.setTextureRect(sf::IntRect(
                                      get_ball_coord_x(0),
                                      get_ball_coord_y(0),
                                      BALL_SIZE,
                                      BALL_SIZE));
    x = sf::Mouse::getPosition().x;
    y = sf::Mouse::getPosition().y;
    Vx = 0;
    Vy = 0;
    sprite.setPosition(x, y);
}

void Ball::draw(sf::RenderWindow* window)
{
    if (!free)
    {
        x = sf::Mouse::getPosition().x - window->getPosition().x - BALL_SIZE/2;
        y = sf::Mouse::getPosition().y - window->getPosition().y - 1600 - BALL_SIZE/2;
    }
    window->draw(sprite);
    
    //    std::cout << sf::Mouse::getPosition().x - window->getPosition().x << ", " << sf::Mouse::getPosition().y - window->getPosition().y - 1600 << std::endl;
}

void Ball::update(float dt)
{
    if (free)
    {
        x += Vx*dt;
        y += Vy*dt;
    }
    
    if (x > DEFAULT_SCREEN_WIDTH - BALL_SIZE)
    {
        //        exit(0);
        f = LEFT;
        changeVelocityDependedOnCollide();
        
        //        Vx = - Vx;
    }
    else if (x < 0)
    {
        f = RIGHT;
        changeVelocityDependedOnCollide();
    }
    else if (y < 0)
    {
        f = FRONT;
        changeVelocityDependedOnCollide();
    }
    else if (y > DEFAULT_SCREEN_HEIGHT && free)
    {
        Vx = 0;
        Vy = 0;
        
        ((GameManager* )GM)->MakeGameOverText();
        ((GameManager* )GM)->DestroyBall();
        ((GameManager* )GM)->DestroyBoard();
    }
    
    if (!((GameManager*)GM)->isBlocksLeft()) {
        ((GameManager* )GM)->MakeLevelClearedText();
        ((GameManager* )GM)->DestroyBall();
        ((GameManager* )GM)->DestroyBoard();
    }
    
    sprite.setPosition(x, y);
    
    //    std::cout << x << ", " << y << std::endl;
}

void Ball::release()
{
    free = true;
}

void Ball::setVelocity(double iVx, double iVy)
{
    Vx = iVx;
    Vy = iVy;
}

void Ball::collideResponse(GameObject *obj)
{
    switch (obj->who()) {
        case BLOCK:
            changeVelocityDependedOnCollide();
            break;
        case SUPPORT:
            changeVelocityDependedOnCollide();
            break;
        default:
            break;
    }
}

void Ball::changeVelocityDependedOnCollide()
{
    //    std::cout << 123123 << std::endl;
    switch (f)
    {
        case FRONT:
        {
            //            std::cout << 11111111 << std::endl;
            if (Vy < 0)
                Vy = -Vy;
            f = NULL_DESTINATION;
            break;
        }
        case BACK:
        {
            //            std::cout << 22222222 << std::endl;
            if (Vy > 0)
                Vy = -Vy;
            f = NULL_DESTINATION;
            break;
        }
        case LEFT:
        {
            //            std::cout << 33333333 << std::endl;
            if (Vx > 0)
                Vx = - Vx;
            f = NULL_DESTINATION;
            break;
        }
        case RIGHT:
        {
            //            std::cout << 444444444 << std::endl;
            if (Vx < 0)
                Vx = -Vx;
            f = NULL_DESTINATION;
            break;
        }
        case FROM_BOARD:
        {
            if (Vy > 0)
                Vy = -Vy;
            f = NULL_DESTINATION;
            Vx = reflection_angle;
            break;
        }
        default:
            break;
    }
}

bool IsInRect(double x, double y, Rect rect)
{
    if (x >= rect.x1 && x <= rect.x2 && y >= rect.y1 && y <= rect.y2)
    {
        return true;
    }
    else
        return false;
}

bool Ball::collideCheck(GameObject* obj)
{
    switch (obj->who()) {
        case BLOCK:
        {
            double x0 = obj->getX() + BLOCK_WIDTH/2;
            double y0 = obj->getY() + BLOCK_HEIGHT/2;
            #define x x+BALL_SIZE/2
            #define y y+BALL_SIZE/2
            
            Brick* tmp = (Brick* )obj;
            if (IsInRect(x, y, tmp->getRect(0)))
            {
                f = FRONT;
                return true;
            }
            else if (IsInRect(x, y, tmp->getRect(1)))
            {
                f = LEFT;
                return true;
            }
            else if (IsInRect(x, y, tmp->getRect(2)))
            {
                f = RIGHT;
                return true;
            }
            else if (IsInRect(x, y, tmp->getRect(3)))
            {
                f = BACK;
                return true;
            }
            else
                return false;
            
            #undef x
            #undef y
        }
        case SUPPORT:
        {
            double x0 = obj->getX() + BLOCK_WIDTH/2;
            double y0 = obj->getY() + BLOCK_HEIGHT/2;
#define x x+BALL_SIZE/2
#define y y+BALL_SIZE/2
            Board* tmp = (Board* )obj;
            if (IsInRect(x, y, tmp->getRect(0)))
            {
                f = FROM_BOARD;
                reflection_angle = 10*(x - x0 - tmp->getLength()/2 + BALL_SIZE/2)/(tmp->getLength());
                changeVelocityDependedOnCollide();
                return true;
            }
            else return false;
            break;
#undef x
#undef y
        }
        default:
            break;
    }
}
