#ifndef I_GRAPHICAL_DISPLAY_H_
#define I_GRAPHICAL_DISPLAY_H_

class IGraphicalDisplay
{
public:
    IGraphicalDisplay() = default;
    virtual ~IGraphicalDisplay() = default;
    virtual void renderWindow() = 0;
    virtual void drawOnWindow() = 0;
    // virtual void setTexture() = 0;
    // virtual void setSprite() = 0;
private:
};

#endif