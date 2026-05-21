#include "Cervantes/core/Engine.hpp"

class Game : public Cervantes::Application
{
public:

    void init() override;
    void update() override;
    
private:
    Cervantes::Unit unit_1{"../../assets/textures/saori_plushie.png",100,100};
    Cervantes::Unit unit_2{"../../assets/textures/saori_plushie.png",800,100};
};