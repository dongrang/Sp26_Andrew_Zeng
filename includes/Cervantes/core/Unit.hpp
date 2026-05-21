#ifndef UNIT_HPP
#define UNIT_HPP

#include "Picture.hpp"
#include "types.hpp"

namespace Cervantes {
    

    class Unit{
    public:
    
        Unit(const std::string& fileName);
        Unit(const std::string& fileName, int xPos, int yPos);

        void setCoordinates(int newxPos, int newyPos);
        int getXCoordinate() const;
        int getYCoordinate() const;

        void incrementXPosition(int amt);
        void incrementYPosition(int amt);

        Dimensions getDimensions() const;
        void setSpeed(int newSpeed);
        int getSpeed() const;

        void makeInvisible();
        void makeVisible();
        bool isVisible() const;
        
    private:

        Picture mPicture;
        int mXpos{ 0 };
        int mYpos{ 0 };
        int mSpeed{ 0 };
        bool mIsVisible{ true };

        friend class Renderer;
        friend bool Collide(const Unit& one, const Unit& another);        
};
bool Collide(const Unit& one, const Unit& another);
}

#endif
