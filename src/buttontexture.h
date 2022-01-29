#pragma once


#include "buttonbase.h"

#include <raylib.h>

namespace MR
{

class ButtonTexture : public ButtonBase
{
public:
    ButtonTexture(int textureId);
    ButtonTexture(int textureId, int action);
    ButtonTexture(int textureId, int action, int x, int y, int width = 0, int height = 0);

    // ButtonBase interface
    virtual void render() const override;
    virtual void setPadding(const Padding &padding) override;

    int texture() const;
    void setTexture(int textureId);

private:
    void calcTexturePos();

    int m_textureId;

    float m_textureX;
    float m_textureY;
    float m_textureWidth;
    float m_textureHeight;

};

}
