#include "Cervantes/core/Engine.hpp"
#include "Player.hpp"
#include "Enemy.hpp"

class Game : public Cervantes::Application{

    public:

        void init() override;
        void update() override;
        void shutdown() override;
        
    private:

        Cervantes::Picture background{"assets/textures/backgrounds/background_1.png"};
        Cervantes::Picture player_health{"assets/textures/ui/Player_Healthbar.png"};
        Cervantes::Picture boss_health{"assets/textures/ui/Boss_Healthbar.png"};
        // For now, drawing of units requires default vals for position in constructor until renderer
        // part of game engine is expanded
        Player player{"assets/textures/units/saori_plushie.png",0,0,100};
        Enemy boss{"assets/textures/units/donquixote.png",0,0,100};
    
};