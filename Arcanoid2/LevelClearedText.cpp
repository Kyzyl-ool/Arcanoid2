//
//  LevelClearedText.cpp
//  Arcanoid2
//
//  Created by Кежик Кызыл-оол on 05.06.2018.
//  Copyright © 2018 Кежик Кызыл-оол. All rights reserved.
//

#include "LevelClearedText.hpp"

LevelClearedText::LevelClearedText()
{
    type = LEVEL_CLEARED_TEXT;
    texture.loadFromFile(LEVEL_CLEARED_FILE);
    sprite.setTexture(texture);
    sprite.setPosition((DEFAULT_SCREEN_WIDTH-LEVELCLEARED_WIDTH)/2, (DEFAULT_SCREEN_HEIGHT-LEVELCLEARED_HEIGHT)/2);
}

void LevelClearedText::draw(sf::RenderWindow *window)
{
    window->draw(sprite);
}
