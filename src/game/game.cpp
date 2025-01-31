#include "game/game.h"
#include "game/field.h"
#include "creature/player.h"

Game::Game() : player_(nullptr), field_(nullptr) {
}

Game::~Game() {
    if (field_ != nullptr)
        delete field_;
    if (player_ != nullptr)
        delete player_;
}

void Game::Init() {
    field_ = new Field();
}

void Game::Update() {
    if (player_ == nullptr)
        CreatePlayer();

    if (player_->IsDead()) {
        delete player_;
        player_ = nullptr;
        CreatePlayer();
    }

    field_->Update(player_);
}

void Game::CreatePlayer() {
    while(player_ == nullptr) {
        std::cout << "======================================" << std::endl;
        std::cout << "캐릭터를 생성하세요!!" << std::endl;
        std::cout << "1) 기사 2) 궁수 3) 법사" << std::endl;
        std::cout << "======================================" << std::endl;

        std::cout << "> ";

        int input = 0;
        std::cin >> input;

        if (input == PT_Knight) {
            player_ = new Knight();
        } else if (input == PT_Archer) {
            player_ = new Archer();
        } else if (input == PT_Mage) {
            player_ = new Mage();
        }
    }

}