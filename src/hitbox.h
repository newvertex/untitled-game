#pragma once

#include <raylib.h>

namespace MR
{

class Entity;

class HitBox
{
public:
    HitBox();
    HitBox(int id, const char *groupTag, const Vector2 &position, const Vector2 &size, Entity *entity);

//    void render();
//    void update();


private:
    int m_id;
    const char *m_groupTag;

    Vector2 m_position;
    Vector2 m_size;

    Entity *m_entity{nullptr};

};

}
