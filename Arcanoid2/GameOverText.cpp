//
//  GameOverText.cpp
//  Arcanoid2
//
//  Created by Кежик Кызыл-оол on 05.06.2018.
//  Copyright © 2018 Кежик Кызыл-оол. All rights reserved.
//

#include "GameOverText.hpp"

GameOverText::GameOverText()
{
    texture.loadFromFile(GAME_OVER_FILE);
    sprite.setTexture(texture);
    sprite.setPosition(DEFAULT_SCREEN_WIDTH/2-200, DEFAULT_SCREEN_HEIGHT/2-72);
}

void GameOverText::draw(sf::RenderWindow* window)
{
    window->draw(sprite);
}
