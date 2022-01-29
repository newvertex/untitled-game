#pragma once

#include <raylib.h>

#include <string>
#include <vector>
#include <map>

namespace MR
{

struct Animation
{
    int id{-1};
    std::string name;
    std::vector<int>(texturesID);
    bool loop{false};
};

class AnimatedSprite
{
public:
    AnimatedSprite(int id);
    ~AnimatedSprite();

    void render();
    void update();

    void addAnimation(std::string name, Animation *animation);
    int currentFrameTexture();

    int id() const;
    const Vector2 &position() const;
    void setPosition(const Vector2 &position);
    const Vector2 &origin() const;
    void setOrigin(const Vector2 &origin);
    float rotation() const;
    void setRotation(float rotation);
    const Vector2 &scale() const;
    void setScale(const Vector2 &scale);
    const Vector2 &size() const;
    void setSize(const Vector2 &size);
    const Color &colorTint() const;
    void setColorTint(const Color &colorTint);

    void play(std::string animationName);
    void setSpeed(int speed);



    bool flip() const;
    void setFlip(bool flip);

private:
    void calcDestSize();

    int m_id{-1};

    int m_frames{0};
    int m_currentFrame{0};
    int m_speed{4};

    Animation *m_currentAnimation{nullptr};
    std::map<std::string, Animation *> m_animations;

    Vector2 m_position{0.0f, 0.0f};
    Vector2 m_origin{0.0f, 0.0f};

    float m_rotation = 0.0f;

    Vector2 m_scale{1.0f, 1.0f};
    Vector2 m_size{0.0f, 0.0f};
    Vector2 m_destSize;

    bool m_flip{false};

    Color m_colorTint{WHITE};

};

}
