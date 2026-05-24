add_executable(Game Game.cpp
                    Player.cpp
                    Enemy.cpp
                    HealthBar.cpp
                    Projectile.cpp                    
)

target_link_libraries(Game PUBLIC CervantesLib)

file(COPY assets DESTINATION ${CMAKE_BINARY_DIR}/assets)