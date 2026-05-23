#ifndef PLAYER_HPP
#define PLAYER_HPP

#include "Cervantes/core/Unit.hpp"

class Player : public Cervantes::Unit{

    public:
        Player(const std::string& fileName,int xpos,int ypos);

        void spawn(int health, int speed);
        void update(bool* keys_array);
        void bounds();

        int getHealth() const;
        int baseHealth() const;
        void setHealth(int health);
        void takeDamage(int damage);

    private: 
    
        int health_{ 100 };
        int baseHealth_{ 100 };
};

#endif