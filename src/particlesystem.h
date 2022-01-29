#pragma once

#include "particle.h"

#include <list>
#include <memory>
#include <vector>
#include <iostream>

namespace MR
{

class ParticleSystem
{
public:
    ParticleSystem(int x, int y);
    ParticleSystem(Vector2 position);
    ~ParticleSystem();

    void update(float dt);
    void render();

    void createParticle(int howMany = 1);

    const Vector2 &position() const;
    void setPosition(Vector2 position);
    void setPosition(int x, int y);

    void addForce(Vector2 force);

    const Vector2 &initialVelocity() const;
    void setInitialVelocity(Vector2 initialVelocity);
    void setInitialRandomVelocity(Vector2 from, Vector2 to);

    bool randomVelocity() const;
    void setRandomVelocity(bool randomVelocity);

    bool randomPosX() const;
    void setRandomPosX(bool randomPosX);
    void setRandomPosX(int fromX, int toX);

    bool randomPosY() const;
    void setRandomPosY(bool randomPosY);
    void setRandomPosY(int fromY, int toY);

    float lifeTime() const;
    void setLifeTime(float time);

    bool randomLifeTime() const;
    void setRandomLifeTime(bool randomLifeTime);
    void setRandomLifeTime(float lifeTimeFrom, float lifeTimeTo);

    float size() const;
    void setSize(float size);

    bool randomSize() const;
    void setRandomSize(bool randomSize);
    void setRandomSize(float sizeFrom, float sizeTo);

    Color color() const;
    void setColor(Color color);

    int textureId() const;
    Color textureColorTint() const;
    void setTexture(int textureId, Color tint = WHITE);

    void setRandomTexture(bool randomTexture);
    void setTextureColorTint(Color tint = WHITE);
    void addTextures(int textureId);

    friend std::ostream &operator<<(std::ostream &out, const ParticleSystem &particleSystem);

private:
    // Position
    Vector2 m_position;

    bool m_randomPosX{false};
    int m_posX1;
    int m_posX2;

    bool m_randomPosY{false};
    int m_posY1;
    int m_posY2;

    // Velocity
    Vector2 m_initialVelocity{0.0f, 0.0f};

    bool m_randomVelocity{false};
    Vector2 m_velFrom{0.0f, 0.0f};
    Vector2 m_velTo{0.0f, 0.0f};

    // LifeTime
    float m_lifeTime{-1.0f};

    bool m_randomLifeTime{false};
    float m_lifeTimeFrom{0.0f};
    float m_lifeTimeTo{1.0f};

    // Size
    float m_size{10.0f};

    bool m_randomSize{false};
    float m_sizeFrom{0.0f};
    float m_sizeTo{1.0f};

    // Color
    Color m_color{RED};

    // Texture
    int m_textureId{-1};

    bool m_randomTexture{false};
    std::vector<int> m_texturesId;
    Color m_colorTint{WHITE};

    std::list<std::unique_ptr<Particle>> m_particles;

};

}
