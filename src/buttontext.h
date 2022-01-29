#pragma once

#include "buttonbase.h"
#include "text.h"

#include <raylib.h>

#include <string>

namespace MR
{

class ButtonText : public ButtonBase
{
public:
    ButtonText(const std::string &text);
    ButtonText(const std::string &text, int action);
    ButtonText(const std::string &text, int action, int x, int y, int width = 0, int height = 0);

    // ButtonBase interface
    virtual void render() const override;
    virtual void setPadding(const Padding &padding) override;

    const std::string &text() const;
    void setText(const std::string &text);

    int fontSize() const;
    void setFontSize(int fontSize);

    const Color &textColor() const;
    void setTextColor(const Color &textColor);

    TextAlign align() const;
    void setAlign(TextAlign align);

private:
    void calcTextSize();
    void calcTextPos();

    std::string m_text;
    int m_fontSize{18};
    Color m_textColor{BLACK};
    TextAlign m_textAlign{TextAlign::LEFT};

    int m_textX;
    int m_textY;

    int m_textWidth;
    int m_textHeight;
    int m_textCenterX;
    int m_textCenterY;

};

}
