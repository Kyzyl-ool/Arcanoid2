//
//  GameManager.hpp
//  Arcanoid2
//
//  Created by Кежик Кызыл-оол on 05.06.2018.
//  Copyright © 2018 Кежик Кызыл-оол. All rights reserved.
//

#ifndef GameManager_hpp
#define GameManager_hpp

#include "GraphicsManager.hpp"
#include "PhysicsManager.hpp"

class GameManager
{
private:
    sf::RenderWindow* MainWindow;
    
    ObjectManager MainObjectManager;
    GraphicsManager MainGraphicsManager;
    PhysicsManager MainPhysicsManager;
    
    Background MainBackground;
    Board TheBoard;
    Ball TheBall;
    Brick* Bricks;
    
    GameOverText TheGameOverText;
    LevelClearedText TheLevelClearedText;
    
    sf::Event MainEvent;
    
    int Space[MAX_BLOCKS_Y][MAX_BLOCKS_X];
    
public:
    GameManager(sf::RenderWindow* iMainWindow);
    
    void RunGame(); //start game loop
    
    void CheckEvents(); //check events
    void CheckKeyboard(); //check keyboard event
    void CheckKeyboardRelease(); //check mouse release event
    void CheckMousePress(); //check mouse press event
    
    void ClearWindow(); //clear window
    void DrawObjects(); //draw all objects
    void UpdateObjects(); //update all objects
    
    void MakeGameOverText();
    void MakeLevelClearedText();
    
    void DestroyBoard();
    void DestroyBall();
    
    void LoadMap(int map_number);
    
//    void StopGame(); //stops game
    
    bool isBlocksLeft();
};

#endif /* GameManager_hpp */
