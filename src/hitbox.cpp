#include "hitbox.h"

namespace MR
{

HitBox::HitBox()
{

}

HitBox::HitBox(int id, const char *groupTag, const Vector2 &position, const Vector2 &size, Entity *entity)
    : m_id(id),m_groupTag(groupTag), m_position(position), m_size(size), m_entity(entity)
{

}

}
