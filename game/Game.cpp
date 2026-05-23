#include "Game.hpp"

void Game::init()
{
    // stores key call backs as defined by game in keys array in game engine(application.hpp)
    setKeyCallback([this](const Cervantes::KeyEvent& event){
        // if press
        if(event.getAction() == Cervantes::KeyEvent::KeyAction::PRESS)
            keys_array_[static_cast<int>(event.getKeyCode())] = true;
        // if release
        else if(event.getAction() == Cervantes::KeyEvent::KeyAction::RELEASE)
            keys_array_[static_cast<int>(event.getKeyCode())] = false;
    });  

    player.spawn(100,2);

    boss.spawn(100,1);
}

void Game::update()
{

    Cervantes::Renderer::get()->draw(background,0,0);
    Cervantes::Renderer::get()->draw(boss);
    Cervantes::Renderer::get()->draw(player);
    Cervantes::Renderer::get()->draw(boss_health,20,720);
    Cervantes::Renderer::get()->draw(player_health,20,20);
    
    player.update(keys_array_);
    boss.update();
}

int main(){
    Game game;
    game.run();
    return 0;
}