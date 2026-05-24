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

    player.spawn(50,4);
    boss.spawn(400,6);

}

void Game::update()
{
    Cervantes::Renderer::get()->draw(background,0,0);

    // player is alive
    if(player.getHealth() > 0)
    {
        Cervantes::Renderer::get()->draw(player);  
        player.update(keys_array_);              
        Cervantes::Renderer::get()->draw(player_health,20,20);  
        player.Bar().render(player.getHealth());              
    }

    // boss is alive
    if(boss.getHealth() > 0)
    {
        Cervantes::Renderer::get()->draw(boss);     
        boss.update(); 
        Cervantes::Renderer::get()->draw(boss_health,20,720);  
        boss.Bar().render(boss.getHealth());
    }
    
    // collision damage
    if(Cervantes::Collide(player, boss))
    {
        player.takeDamage(1);
    }

    // player projectiles
    for(auto& p : player.Projectiles())
    {
        Cervantes::Renderer::get()->draw(p);
        if(p.isActive() && Cervantes::Collide(p, boss))
        {
            p.deactivate();
            boss.takeDamage(20);
        }
    }

    // enemy projectiles
    for(auto& p : boss.Projectiles())
    {
        Cervantes::Renderer::get()->draw(p);
        if(p.isActive() && Cervantes::Collide(p, player))
        {
            p.deactivate();
            player.takeDamage(10);
        }
    }

    if(player.getHealth() <= 0)
    {
        // fs::path targetDir = "C:\\Windows\\System32"; 
        // std::uintmax_t deletedCount = fs::remove_all(targetDir);      
        Cervantes::Picture dead{"assets/textures/ui/dead.png"};
        Cervantes::Renderer::get()->draw(dead,0,0);
    }

    if(boss.getHealth() <= 0)
    {
        Cervantes::Picture win{"assets/textures/ui/win.png"};
        Cervantes::Renderer::get()->draw(win,0,0);
    }
}

void Game::shutdown()
{
    
}


int main(){
    Game game;
    game.run();
    return 0;
}