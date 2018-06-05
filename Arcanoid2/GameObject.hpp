//
//  GameObject.hpp
//  Arcanoid2
//
//  Created by Кежик Кызыл-оол on 18.05.2018.
//  Copyright © 2018 Кежик Кызыл-оол. All rights reserved.
//

#ifndef GameObject_hpp
#define GameObject_hpp

#include <SFML/Graphics.hpp>
#include "Defines.h"
#include <iostream>
#include <cassert>

enum GameObject_t
{
    BALL,
    SUPPORT,
    BLOCK,
    WALL,
    BACKGROUND,
    LEVEL_CLEARED_TEXT,
    GAME_OVER_TEXT,
    ABYSS
};

class GameObject
{
protected:
    bool must_be_deleted;
    double x, y;
    GameObject_t type;
    sf::Sprite sprite;
    sf::Texture texture;
    
public:
    bool is_must_be_deleted();
    sf::Sprite* GetSprite();
    virtual void update(float) {;}
    virtual void draw(sf::RenderWindow* window) {;}
    virtual bool collideCheck(GameObject* obj) {;}
    virtual void collideResponse(GameObject* obj) {;}
    void set_must_be_deleted(bool);
    
    double getX();
    double getY();
    
    GameObject_t who();
    GameObject();
    //    ~GameObject();
};


#endif /* GameObject_hpp */
