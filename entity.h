#ifndef ENTITY_H
#define ENTITY_H

#define SPAWN 0
#define ROW 8
#define COL 8

enum Movement{UP, LEFT, DOWN, RIGHT, INVALID, PLACE};


class Entity
{
public:
    Entity(int);

    int getPosition() const;
    void setPosition(int);

    // move the postion

    void movePosition(Movement);
    bool isInRange(Movement)const;


protected:
    int position;

    
};

#endif