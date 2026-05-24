#ifndef PLAYER_HPP
#define PLAYER_HPP

#include "Cervantes/core/Unit.hpp"

#include "HealthBar.hpp"
#include "Projectile.hpp"
class Player : public Cervantes::Unit{

    public:
        Player(const std::string& fileName,int xpos,int ypos, int baseHealth);

        void spawn(int health, int speed);
        void update(bool* keys_array);
        void bounds();

        int getHealth() const;
        int baseHealth() const;
        void setHealth(int health);
        void takeDamage(int damage);

        HealthBar& Bar();
        void fire(bool* keys_array);
        std::vector<Projectile>& Projectiles();
        
    private: 
    
        int health_{ 100 };
        int baseHealth_{ 100 };

        HealthBar hpBar_{100,30,30};

        std::vector<Projectile> proj_;
        bool spacePress_{ false };

        // shooting
        int shootTimer_{ 0 };
        int shootInterval_{ 45 };
};

#endif