#pragma once

#include <texture.h>

#include <raylib.h>

namespace MR
{

class Sprite
{
public:
    Sprite(int id);
    Sprite(int id, int textureId);
    Sprite(int id, int x, int y, int width, int height, int textureId);

    void render() const;

    int id() const;

    const Vector2 &position() const;
    void setPosition(const Vector2 &position);
    void setPosition(int x, int y);

    const Vector2 &size() const;
    void setSize(const Vector2 &size);
    void setSize(int width, int height);

    const Vector2 &scale() const;
    void setScale(const Vector2 &scale);
    void setScale(int x, int y);

    float rotation() const;
    void setRotation(float rotation);

    const Vector2 &origin() const;
    void setOrigin(const Vector2 &origin);

    const Color &colorTint() const;
    void setColorTint(const Color &colorTint);

    int textureId() const;
    void setTextureId(int textureId);



    void calcDestSize();

    bool flip() const;
    void setFlip(bool flip);

protected:
    int m_id{-1};

    // TODO: parent position(global transform, local transform)
    Vector2 m_position{0.0f, 0.0f};

    Vector2 m_origin{0.0f, 0.0f};
    float m_rotation = 0.0f;

    Vector2 m_scale{1.0f, 1.0f};
    Vector2 m_size{0.0f, 0.0f};
    Vector2 m_destSize;

    bool m_flip{false};

    Color m_colorTint{WHITE};

    int m_textureId{0};

};

}
