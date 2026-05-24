#ifndef ENEMY_HPP_
#define ENEMY_HPP_

#include "Cervantes/core/Unit.hpp"
#include "HealthBar.hpp"
#include "Projectile.hpp"
class Enemy : public Cervantes::Unit{

    public:

        Enemy(const std::string& fileName,int xpos,int ypos,int baseHealth);

        void spawn(int health, int speed);
        void update();

        int getHealth() const;
        int baseHealth() const;
        void setHealth(int health);
        void takeDamage(int damage);

        HealthBar& Bar();
        void fire();
        std::vector<Projectile>& Projectiles();

    private:

        int health_{ 100 };
        int baseHealth_{ 100 };

        HealthBar hpBar_{100,30,730};

        std::vector<Projectile> proj_;

        // movement
        int xDirection_{ 1 };
        int yDirection_{ 1 };
        int timer_{ 0 };
        int interval_{ 30 };
        int leftBound_{ 0 };
        int rightBound_{ 0 };

        // projectiles
        int shootTimer_{ 0 };
        int shootInterval_{ 144 };

        // phases
        enum class Phase { ONE, TWO, THREE};
        Phase phase_ {Phase::ONE};
        void updatePhase();

};



#endif