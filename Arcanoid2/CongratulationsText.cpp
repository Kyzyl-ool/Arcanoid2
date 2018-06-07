//
//  CongratulationsText.cpp
//  Arcanoid2
//
//  Created by Кежик Кызыл-оол on 07.06.2018.
//  Copyright © 2018 Кежик Кызыл-оол. All rights reserved.
//

#include "CongratulationsText.hpp"

CongratulationsText::CongratulationsText()
{
    type = CONGRATULATIONS_TEXT;
    
    texture.loadFromFile(CONGRATULATIONS_FILE);
    sprite.setTexture(texture);
    sprite.setPosition((DEFAULT_SCREEN_WIDTH-CONGRATULATIONS_WIDTH)/2, (DEFAULT_SCREEN_HEIGHT-CONGRATULATIONS_HEIGHT)/2);
    
}

void CongratulationsText::draw(sf::RenderWindow *window)
{
    window->draw(sprite);
}
