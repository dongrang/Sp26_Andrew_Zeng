#include "Player.hpp"
#include "Cervantes/core/window.hpp"
#include "Cervantes/core/Renderer.hpp"
#include "Cervantes/core/Picture.hpp"
Player::Player(const std::string& fileName,int xpos,int ypos,int baseHealth):Unit(fileName,xpos,ypos),baseHealth_(baseHealth)
{
}

void Player::spawn(int health,int speed)
{
    baseHealth_ = health;
    health_ = health;
    setSpeed(speed);
    setCoordinates((static_cast<int>(Cervantes::Window::get()->getSize().width)/2) - static_cast<int>(getDimensions().width)/2, 100);

    Bar().init();
    Bar().setBaseHealth(baseHealth());
}

void Player::update(bool* keys_array)
{
    if (keys_array[static_cast<int>(Cervantes::Key::Up)])
        incrementYPosition(getSpeed());
    if (keys_array[static_cast<int>(Cervantes::Key::Down)])
        incrementYPosition(-getSpeed());
    if (keys_array[static_cast<int>(Cervantes::Key::Right)])
        incrementXPosition(getSpeed());
    if (keys_array[static_cast<int>(Cervantes::Key::Left)])
        incrementXPosition(-getSpeed());

    bounds();
    fire(keys_array);

    for(auto& p : proj_)
        p.update();

    std::erase_if(proj_,[](const Projectile& p) { return !p.isActive(); } );

}

void Player::bounds()
{
    auto winHeight = Cervantes::Window::get()->getSize().height;
    auto winWidth = Cervantes::Window::get()->getSize().width;
    clampCoords(0, winWidth, 0, winHeight);
}

int Player::getHealth() const
{
    return health_;
}

int Player::baseHealth() const
{
    return baseHealth_;
}

void Player::setHealth(int health)
{
    health_ = health;
}

void Player::takeDamage(int damage)
{
    health_ = std::max(0,health_ - damage);
}

HealthBar& Player::Bar()
{
    return hpBar_;
}

void Player::fire(bool* keys_array)
{
    if(keys_array[static_cast<int>(Cervantes::Key::Space)])
    {
        shootTimer_++;
        if(shootTimer_ >= shootInterval_)
        {
            proj_.emplace_back("assets/textures/units/blue.png", getXCoordinate(),getYCoordinate(),5);
            shootTimer_ = 0;
        }
    }
    else{
        shootTimer_ = 0;
    }


}

std::vector<Projectile>& Player::Projectiles()
{
    return proj_;
}