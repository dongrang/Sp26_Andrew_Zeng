#include "HealthBar.hpp"
#include "Cervantes/core/Renderer.hpp"

HealthBar::HealthBar(int baseHealth,int x, int y):baseHealth_(baseHealth),xPos_(x),yPos_(y)
{

}
void HealthBar::init()
{
    digits_[0].LoadImage("assets/textures/numbers/0.png");
    digits_[1].LoadImage("assets/textures/numbers/1.png");
    digits_[2].LoadImage("assets/textures/numbers/2.png");
    digits_[3].LoadImage("assets/textures/numbers/3.png");
    digits_[4].LoadImage("assets/textures/numbers/4.png");
    digits_[5].LoadImage("assets/textures/numbers/5.png");
    digits_[6].LoadImage("assets/textures/numbers/6.png");
    digits_[7].LoadImage("assets/textures/numbers/7.png");
    digits_[8].LoadImage("assets/textures/numbers/8.png");
    digits_[9].LoadImage("assets/textures/numbers/9.png");
}

void HealthBar::render(int health)
{
    health = std::max(0,health);
    std::string healthStr = std::to_string(health);
    int offsetX = xPos_;

    for(char c: healthStr)
    {
        int num = c - '0';
        Cervantes::Renderer::get()->draw(digits_[num],offsetX,yPos_);
        offsetX += digits_[num].getDimensions().width+3;
    }
}

void HealthBar::setBaseHealth(int health)
{
    baseHealth_ = health;
}