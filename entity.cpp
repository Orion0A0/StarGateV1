#include "entity.h"

Entity::Entity(int pos) : position(pos){}

int Entity::getPosition() const {return position;}

void Entity::setPosition(int position) {this->position = position;}

void Entity::movePosition(Movement input)
{
    if(!isInRange(input))
        return;
    switch (input)
    {
    case UP:
        position -= ROW;
        break;
    case DOWN:
        position += ROW;
        break;
    case LEFT:
        --position;
        break;
    case RIGHT:
        ++position;
        break;
    }
}

bool Entity::isInRange(Movement input) const
{
    switch (input)
    {
    case UP: return position >= COL;
    case DOWN: return position < (ROW * COL) - COL;
    case LEFT: return position % COL > 0;    
    case RIGHT: return position % COL < COL - 1;
    }
    return true;
}
