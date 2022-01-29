#pragma once

#include <raylib.h>

namespace MR
{

class Particle
{
public:
    Particle(int x, int y);
    Particle(Vector2 position);
    ~Particle();

    void update(float dt);
    void render();

    void addForce(Vector2 force);
    void setVelocity(Vector2 velocity);

    const Color &color() const;
    void setColor(Color color);

    float size() const;
    void setSize(float size);

    float lifeTime() const;
    void setLifeTime(float lifeTime);

    float elapsedTime() const;
    bool isDead() const;

    int opacity() const;
    void setOpacity(int opacity);

    int textureId() const;
    void setTexture(int textureId, Color tint = WHITE);

private:
    Vector2 m_position;
    Vector2 m_velocity{0.0f, 0.0f};
    Vector2 m_acceleration{0.0f, 0.0f};

    float m_lifeTime{-1.0f};
    float m_elapsedTime{0.0f};

    // TODO: add color ramp to change the color based on time
    Color m_color{RED};
    int m_textureId{-1};

    // TODO: add scale and different scale per times
    float m_size{10.0f};

    // TODO: check opacity and change it over time!
    int m_opacity{255};

};

}
