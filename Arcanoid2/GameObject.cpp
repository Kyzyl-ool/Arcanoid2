//
//  GameObject.cpp
//  Arcanoid2
//
//  Created by Кежик Кызыл-оол on 18.05.2018.
//  Copyright © 2018 Кежик Кызыл-оол. All rights reserved.
//

#include "GameObject.hpp"

GameObject::GameObject()
{
    
}

sf::Sprite* GameObject::GetSprite()
{
    return &sprite;
}

GameObject_t GameObject::who()
{
    return type;
}

double GameObject::getX()
{
    return x;
}

double GameObject::getY()
{
    return y;
}

bool GameObject::is_active()
{
    return active;
}

void GameObject::Deactivate()
{
    active = false;
}

void GameObject::Activate()
{
    active = true;
}
