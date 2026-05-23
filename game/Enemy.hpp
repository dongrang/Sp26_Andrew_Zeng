#ifndef ENEMY_HPP_
#define ENEMY_HPP_

#include "Cervantes/core/Unit.hpp"

class Enemy : public Cervantes::Unit{

    public:

        Enemy(const std::string& fileName,int xpos,int ypos);

        void spawn(int health, int speed);
        void update();
        void destroy();

        int getHealth() const;
        int baseHealth() const;
        void setHealth(int health);
        void takeDamage(int damage);

    private:

        int health_{ 100 };
        int baseHealth_{ 100 };
};



#endif