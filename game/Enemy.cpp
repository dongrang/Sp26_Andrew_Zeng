#include <random>
#include "Enemy.hpp"
#include "Cervantes/core/window.hpp"
Enemy::Enemy(const std::string& fileName,int xpos,int ypos,int baseHealth):Cervantes::Unit(fileName,xpos,ypos),baseHealth_(baseHealth)
{
}

void Enemy::spawn(int health, int speed)
{
    baseHealth_ = health;
    health_ = health;

    setSpeed(speed);
    setCoordinates((static_cast<int>(Cervantes::Window::get()->getSize().width)/2) - static_cast<int>(getDimensions().width)/2, 800);

    Bar().init();
    Bar().setBaseHealth(baseHealth());

    auto winWidth = Cervantes::Window::get()->getSize().width;
    auto winHeight = Cervantes::Window::get()->getSize().height;
    leftBound_ = 0;
    rightBound_ = static_cast<int>(winWidth);
}
void Enemy::update()
{
    timer_++;

    if(timer_ >= interval_)
    {
        static std::mt19937 rng{ std::random_device{}() };

        std::uniform_int_distribution<int> dirDist(-1, 1);
        std::uniform_int_distribution<int> intervalDist(30, 120);

        xDirection_ = dirDist(rng);
        yDirection_ = dirDist(rng);

        if(xDirection_ == 0 && yDirection_ == 0)
            xDirection_ = 1;
        interval_ = intervalDist(rng);
        timer_    = 0;
    }

    incrementXPosition(getSpeed() * xDirection_);
    incrementYPosition(getSpeed() * yDirection_);

    clampCoords(leftBound_, rightBound_, 
                static_cast<int>(Cervantes::Window::get()->getSize().height) / 2, 
                static_cast<int>(Cervantes::Window::get()->getSize().height));
    
    shootTimer_++;
    if(shootTimer_ >= shootInterval_)
    {
        fire();
        shootTimer_ = 0;
    }

    for(auto& p : proj_)
        p.update();

    std::erase_if(proj_, [](const Projectile& p){ return !p.isActive(); });
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
    health_ = health;
}
void Enemy::takeDamage(int damage)
{
    health_ = std::max(0,health_ - damage);
}

HealthBar& Enemy::Bar()
{
    return hpBar_;
}

void Enemy::fire()
{
    /*proj_.emplace_back("../../assets/textures/units/red.png", 
                    getXCoordinate()+getDimensions().width/2,getYCoordinate(),-5);
    */
    updatePhase();
    int middle = getXCoordinate() + getDimensions().width/2; // middle of enemy unit
    int spacing = 80;

    switch (phase_) {

        case Phase::ONE:
            proj_.emplace_back("../../assets/textures/units/red.png", 
                    middle, getYCoordinate(),-5);
            break;

        case Phase::TWO:
            proj_.emplace_back("../../assets/textures/units/red.png",
                middle - spacing, getYCoordinate(), -4);
            proj_.emplace_back("../../assets/textures/units/red.png",
                middle + spacing, getYCoordinate(), -4);            
            break;

        case Phase::THREE:
            proj_.emplace_back("../../assets/textures/units/red.png",
                middle - spacing, getYCoordinate(), -3);
            proj_.emplace_back("../../assets/textures/units/red.png",
                middle,           getYCoordinate(), -4);
            proj_.emplace_back("../../assets/textures/units/red.png",
                middle + spacing, getYCoordinate(), -3);
            break;
    }
}

std::vector<Projectile>& Enemy::Projectiles()
{
    return proj_;
}

void Enemy::updatePhase()
{
    float hp_Percent = static_cast<float>(health_)/static_cast<float>(baseHealth_);

    if(hp_Percent <= 1.0f/3.0f)
        phase_ = Phase::THREE;

    else if(hp_Percent <= 2.0f/3.0f)
        phase_ = Phase::TWO;

    else
        phase_ = Phase::ONE;
}

