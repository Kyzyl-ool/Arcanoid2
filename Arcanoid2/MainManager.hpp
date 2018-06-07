//
//  MainManager.hpp
//  Arcanoid2
//
//  Created by Кежик Кызыл-оол on 07.06.2018.
//  Copyright © 2018 Кежик Кызыл-оол. All rights reserved.
//

#ifndef MainManager_hpp
#define MainManager_hpp

#include "GameManager.hpp"
#include "MainMenuManager.hpp"

class MainManager
{
private:
    sf::RenderWindow* MainWindow;
    
    bool main_menu_status = true;
    GameManager* GM;
    MainMenuManager* MMM;
    
public:
    MainManager();
    
    void RunGame();
};

#endif /* MainManager_hpp */
