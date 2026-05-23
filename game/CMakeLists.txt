add_executable(Game Game.cpp
                    Player.cpp
                    Enemy.cpp                    
)

target_link_libraries(Game PUBLIC CervantesLib)

