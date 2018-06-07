//
//  CongratulationsText.hpp
//  Arcanoid2
//
//  Created by Кежик Кызыл-оол on 07.06.2018.
//  Copyright © 2018 Кежик Кызыл-оол. All rights reserved.
//

#ifndef CongratulationsText_hpp
#define CongratulationsText_hpp

#include "GameObject.hpp"

class CongratulationsText: public GameObject
{
public:
    CongratulationsText();
    
    void draw(sf::RenderWindow* window);
};

#endif /* CongratulationsText_hpp */
