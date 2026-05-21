#include "Cervantes/core/Unit.hpp"

namespace Cervantes {

Unit::Unit(const std::string& fileName)
{

}

Unit::Unit(const std::string& fileName, int xPos, int yPos):mPicture(fileName),mXpos(xPos),mYpos(yPos)
{

}
void Unit::setCoordinates(int newxPos, int newyPos)
{
    mXpos = newxPos;
    mYpos = newyPos;
}
int Unit::getXCoordinate() const
{
    return mXpos;
}
int Unit::getYCoordinate() const
{
    return mYpos;
}

void Unit::incrementXPosition(int amt)
{
    mXpos += amt;
}
void Unit::incrementYPosition(int amt)
{
    mYpos += amt;
}

void Unit::setSpeed(int newSpeed)
{
    mSpeed = newSpeed;
}
int Unit::getSpeed() const
{
    return mSpeed;
}

void Unit::makeInvisible()
{
    mIsVisible = false;
}
void Unit::makeVisible()
{
    mIsVisible = true;
}
bool Unit::isVisible() const
{
    return mIsVisible;
}

bool Collide(const Unit& one, const Unit& another)
{
    int LeftOne       = one.mXpos;
    int RightOne      = one.mXpos      + one.mPicture.getDimensions().width;
    int LeftAnother   = another.mXpos;
    int RightAnother  = another.mXpos  + another.mPicture.getDimensions().width;

    int BottomOne     = one.mYpos;
    int TopOne        = one.mYpos      + one.mPicture.getDimensions().height;
    int BottomAnother = another.mYpos;
    int TopAnother    = another.mYpos  + another.mPicture.getDimensions().height;

    bool xOverlap = (LeftOne < RightAnother) && (RightOne > LeftAnother);
    bool yOverlap = (TopOne > BottomAnother) && (BottomOne < TopAnother);
    return (yOverlap && xOverlap);
}   

} // end naemspace Cervantes
