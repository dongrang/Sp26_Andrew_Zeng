#include "Player.hpp"
#include "Cervantes/core/window.hpp"
Player::Player(const std::string& fileName,int xpos,int ypos):Unit(fileName,xpos,ypos)
{
}

void Player::spawn(int health,int speed)
{
    setHealth(health);
    setSpeed(speed);
    setCoordinates((static_cast<int>(Cervantes::Window::get()->getSize().width)/2) - static_cast<int>(getDimensions().width)/2, 100);
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
}

void Player::bounds()
{
    auto winHeight = Cervantes::Window::get()->getSize().height;
    auto winWidth = Cervantes::Window::get()->getSize().width;
    auto pHeight = getDimensions().height;
    auto pWidth = getDimensions().width;
    setCoordinates(std::clamp(getXCoordinate(),0,(int)(winWidth-pWidth)), 
                   std::clamp(getYCoordinate(),0,(int)(winHeight-pHeight)));
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
    baseHealth_ = health;
    health_ = health;
}

void Player::takeDamage(int damage)
{
    health_ -= damage;
}

 // end namespace Cervantes