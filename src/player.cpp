#include "player.h"

#include "text.h"
#include "sprite.h"
#include "input.h"
#include "maths.h"
#include "assets.h"
#include "canvas.h"
#include "animatedsprite.h"

#include <raylib.h>
#include <raymath.h>

namespace MR
{

Player::Player(int x, int y)
    : Entity(x, y)
{
//    Sprite *playerSprite = new Sprite(4, x, y, 96, 96, 1);
//    setSprite(playerSprite);

    auto animSprite = new AnimatedSprite(1);
    animSprite->setSize({60.0f , 100.0f });
    setHitBoxRect({-29.0f, -49, 53.0f, 93.0f});
    animSprite->setSpeed(8);
    setAnimatedSprite(animSprite);

    auto animRun = new Animation();
    animRun->id = 0;
    animRun->name = "run";
    animRun->texturesID.push_back(Assets::PLAYER_RUN_1);
    animRun->texturesID.push_back(Assets::PLAYER_RUN_2);
    animRun->texturesID.push_back(Assets::PLAYER_RUN_3);
    addAnimation("run", animRun);

    auto animIdle = new Animation();
    animIdle->id = 0;
    animIdle->name = "idle";
    animIdle->texturesID.push_back(Assets::PLAYER_IDLE);
    addAnimation("idle", animIdle);

    auto animJump = new Animation();
    animJump->id = 0;
    animJump->name = "jump";
    animJump->texturesID.push_back(Assets::PLAYER_JUMP);
    addAnimation("jump", animJump);

    playAnim("idle");

    // physics
    setFriction(0.2f);
    setMaxVelocity({30.0f, 60.0f});

    setGroupTag("PLAYER");

    m_particle = std::make_unique<ParticleSystem>(x, y);
    m_particle->setInitialRandomVelocity({-1.0f, -10.0f}, {4.0f, -5.0f});
    m_particle->setRandomSize(2.5f, 6.0f);
    m_particle->setLifeTime(5.0f);
}

void Player::update(float dt)
{


    // if player dead show this
    m_particle->update(dt);
    m_particle->addForce({0.0f, 10.0f});
    if (Canvas::IsDead)
    {
        m_frames += 1;
        m_particle->setPosition(m_position);
        m_particle->createParticle(3);

        playAnim("idle");
        setRotation(90);
        if (!m_ground)
        {
            setPosition(Vector2Add(position(), {0, 50}));
            addForce(m_gravity);
        }

        if (m_frames > 200)
        {
            Canvas::GameState = GameStates::DEAD;
        }
    }
    else
    {
        m_frames = 0;
        Vector2 direction{0.0f, 0.0f};

        if (Input::isKeyA())
        {
            direction.x = -1.0;
            animatedSprite()->setFlip(true);
        }
        if (Input::isKeyD())
        {
            direction.x = 1.0;
            animatedSprite()->setFlip(false);
        }
        if (Input::isKeyW())
        {
            direction.y = -1.0;
        }
        if (Input::isKeyS())
        {
            direction.y = 1.0;
        }

        direction = Vector2Normalize(direction);

        if (Input::isKeyShift())
        {
            direction = Maths::mulVec(direction, m_nitro);
        }
        else
        {
            direction = Maths::mulVec(direction, m_speed);
        }

        playAnim("idle");
        if (direction.x != 0)
        {
            playAnim("run");
        }
        if (velocity().y != 0)
        {
            playAnim("jump");
        }


        if (m_ground && Input::isKeySpace())
        {
            m_jump = true;
            Assets::getSoundByID(Assets::SND_JUMP)->playOnce();
            addForce(m_jumpHeight);
        }

        addForce(direction);

        if (!m_ground)
        {
            addForce(m_gravity);
        }
        else if (m_ground && !m_jump)
        {
            setAcceleration(Vector2Multiply(acceleration(), {1.0f, 0.0f}));
            setVelocity(Vector2Multiply(velocity(), {1.0f, 0.0f}));
        }

        if (m_jump && m_ground)
        {
            m_jump = false;
        }

        if (m_scoreAlpha > 1)
        {
            m_scoreAlpha -= 2;
        }
        else
        {
            m_scoreAlpha = 0;
        }

        Entity::update(dt);
        m_ground = false;
    }
}

void MR::Player::render() const
{
    // if player dead show this
    Entity::render();
    m_particle->render();

    Assets::getTextureByID(Assets::PROP_COIN)->draw(position().x - 32 - 50.0f, position().y - 32 - 70.0f, 64, 64, {255, 255, 255, m_scoreAlpha});
    Text::medium(TextFormat("%d", m_score), position().x - 25.0f, position().y - 82.0f, 26.0f, { 135, 60, 190, m_scoreAlpha });
}

void Player::trigger(Entity *other)
{
//    std::cout << "Player Trigger: " << other->id() << ", " << other->groupTag() << "\n";

    if (other->groupTag() == "GROUND")
    {
        m_ground = true;
//        m_scoreAlpha = 255;
    }

    if (other->groupTag() == "SAW")
    {
        Canvas::IsDead = true;
    }

    if (other->groupTag() == "END")
    {
        Canvas::GameState = GameStates::DEAD;
    }

}

}



