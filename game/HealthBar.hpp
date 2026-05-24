#ifndef HEALTH_BAR_HPP
#define HEALTH_BAR_HPP

#include "Cervantes/core/Picture.hpp"

class HealthBar{

    public:

        HealthBar(int baseHealth,int x, int y);  
        void init();
        void render(int health);
        void setBaseHealth(int health);
        Cervantes::Picture& getDigit(int i) { return digits_[i]; }
    private: 
        
        int baseHealth_{ 0 };
        int xPos_{ 0 };
        int yPos_{ 0 };
        std::array<Cervantes::Picture,10> digits_;
};

#endif