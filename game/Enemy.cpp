#include "Enemy.hpp"
#include "Cervantes/core/window.hpp"
Enemy::Enemy(const std::string& fileName,int xpos,int ypos):Cervantes::Unit(fileName,xpos,ypos)
{
}

void Enemy::spawn(int health, int speed)
{
    baseHealth_ = health;
    setHealth(health);
    setSpeed(speed);
    setCoordinates((static_cast<int>(Cervantes::Window::get()->getSize().width)/2) - static_cast<int>(getDimensions().width)/2, 800);
}
void Enemy::update()
{
    if(getYCoordinate() > 480)
        incrementYPosition(-getSpeed());
}
void Enemy::destroy()
{

}

int Enemy::getHealth() const
{
    return health_;
}

int Enemy::baseHealth() const
{
    return baseHealth_;
}

void Enemy::setHealth(int health)
{
    baseHealth_ = health;
    health_ = health;
}
void Enemy::takeDamage(int damage)
{
    health_ -= damage;
}
