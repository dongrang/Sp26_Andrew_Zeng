#ifndef PROJECTILE_HPP
#define PROJECTILE_HPP

#include "Cervantes/core/Unit.hpp"

class Projectile : public Cervantes::Unit{

    public:     
        Projectile(const std::string& fileName,int x,int y,int speed);
        void update();
        bool isActive() const;
        void deactivate();
    private:
        int speed_;
        bool isActive_{ true };
};

#endif