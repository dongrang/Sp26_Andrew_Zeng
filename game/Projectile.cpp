#include "Projectile.hpp"
#include "Cervantes/core/window.hpp"

Projectile::Projectile(const std::string& fileName,int x,int y,int speed):Unit(fileName,x,y),speed_(speed)
{}

void Projectile::update()
{
    incrementYPosition(speed_);

    if(getYCoordinate() > (int)Cervantes::Window::get()->getSize().height || getYCoordinate() < 0)
    {
        deactivate();
    }
}

bool Projectile::isActive() const
{
    return isActive_;
}

void Projectile::deactivate() 
{
    isActive_ = false;
}