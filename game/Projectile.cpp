#include "Projectile.hpp"
#include "Cervantes/core/window.hpp"

Projectile::Projectile(const std::string& fileName,int x,int y,int xspeed,int yspeed):Unit(fileName,x,y),xSpeed_(xspeed),ySpeed_(yspeed)
{}

void Projectile::update()
{
    incrementXPosition(xSpeed_);
    incrementYPosition(ySpeed_);

    if(getYCoordinate() > (int)Cervantes::Window::get()->getSize().height || getYCoordinate() < 0)
        deactivate();
    
}

bool Projectile::isActive() const
{
    return isActive_;
}

void Projectile::deactivate() 
{
    isActive_ = false;
}