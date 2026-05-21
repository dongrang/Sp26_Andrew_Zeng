#include "Game.hpp"

void Game::init()
{
        setKeyCallback([this](const Cervantes::KeyEvent& event){
                if(event.getKeyCode()==Cervantes::Key::Right && event.getAction() == Cervantes::KeyEvent::KeyAction::PRESS)
                    unit_1.incrementXPosition(10);
                else if(event.getKeyCode() == Cervantes::Key::Left && event.getAction() == Cervantes::KeyEvent::KeyAction::PRESS)
                    unit_1.incrementXPosition(-10);
            });
}

void Game::update()
{
    if (Collide(unit_1, unit_2))
        std::cout << "Collision detected.\n";
    Cervantes::Renderer::get()->draw(unit_1);
    Cervantes::Renderer::get()->draw(unit_2);
}

int main(){
    Game game;
    game.run();
    return 0;
}