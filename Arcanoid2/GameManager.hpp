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
    
    ObjectManager* MainObjectManager;
    GraphicsManager* MainGraphicsManager;
    PhysicsManager* MainPhysicsManager;
    
    Background* MainBackground;
    MenuBackground* TheMenuBackground;
    Board* TheBoard;
    Ball* TheBall;
    Brick* Bricks;
    
    GameOverText* TheGameOverText;
    LevelClearedText* TheLevelClearedText;
    CongratulationsText* TheCongratulationsText;
    
    sf::Event MainEvent;
    sf::Font MainFont;
    
    int Space[MAX_BLOCKS_Y][MAX_BLOCKS_X];
    
    int current_map_number = 0;
    bool level_cleared = false;
    bool main_menu_status = true;
    
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
    
    void DrawMenu();
    void CheckMenuEvents();
    void CheckMenuKeyboardEvents();
    
    void MakeGameOverText();
    void MakeLevelClearedText();
    void MakeCongratulationsText();
    
    void DestroyBoard();
    void DestroyBall();
    
    void BallFelt();
    void LevelComplete();
    
    void LoadMap(int map_number);
    
    void GoNextLevel();
    
//    void StopGame(); //stops game
    
    bool isBlocksLeft();
    
};

#endif /* GameManager_hpp */
