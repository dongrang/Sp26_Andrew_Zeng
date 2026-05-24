# Cervantes
CSCI 39541-01 Game Engines Project

This is "Bullet Hell" style game.
The controls are simple, arrow keys to move, hold spacebar to shoot.
The red bar at the top of the screen represents the boss health, and the green bar at the bottom represents the player health.
The boss, the only enemy at the moment, has 3 phases. In the first phase it shoots 1 bullet, at 2/3rds health, it will start shooting 2 bullets, and at 1/3rd of the original health it shoots 3 bullets.

Clone and build(Linux):

```bash
git clone --recursive https://github.com/dongrang/Cervantes.git
git submodule update --init --recursive 
cd Cervantes
cmake -S . -B build
cmake --build build --target Game
```

Run:

```bash
./Game
```
