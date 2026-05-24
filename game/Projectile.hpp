#ifndef PROJECTILE_HPP
#define PROJECTILE_HPP

#include "Cervantes/core/Unit.hpp"

class Projectile : public Cervantes::Unit{

    public:     
        Projectile(const std::string& fileName,int x,int y,int xspeed,int yspeed);
        void update();
        bool isActive() const;
        void deactivate();
    private:
        int xSpeed_;
        int ySpeed_;
        bool isActive_{ true };
};

#endif