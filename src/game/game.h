#pragma once

#include <iostream>

// 헤더 파일엔 전방선언
// cpp 파일엔 include
class Player;
class Field;

class Game {
 public:
   Game();
   ~Game();

   void Init();
   void Update();

   void CreatePlayer();

 public:
    Player* player_;
    Field* field_;
};