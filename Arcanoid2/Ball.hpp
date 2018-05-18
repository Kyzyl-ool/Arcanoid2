//
//  Ball.hpp
//  Arcanoid2
//
//  Created by Кежик Кызыл-оол on 18.05.2018.
//  Copyright © 2018 Кежик Кызыл-оол. All rights reserved.
//

#ifndef Ball_hpp
#define Ball_hpp

#include <GameObject.hpp>

enum collide_flag
{
    NULL_DESTINATION,
    FRONT,
    LEFT,
    RIGHT,
    BACK,
};

class Ball: public GameObject
{
private:
    double Vx, Vy;
    int type;
    bool free = false;
    collide_flag f;
    double reflection_angle;
    
    
public:
    Ball();
    
    void setVelocity(double iVx, double iVy);
    
    void update(float dt);
    void draw(sf::RenderWindow* window);
    bool collideCheck(GameObject* obj);
    void collideResponse(GameObject* obj);
    
    void release();
    
    void changeVelocityDependedOnCollide();
};


#endif /* Ball_hpp */
