#ifndef CUSTOMCONTAINER1_HPP
#define CUSTOMCONTAINER1_HPP

#include <gui_generated/containers/CustomContainer1Base.hpp>

class CustomContainer1 : public CustomContainer1Base
{
public:
    CustomContainer1();
    virtual ~CustomContainer1() {}

    virtual void initialize();
    void updateText(int16_t value, int16_t format);
    static uint16_t IntToTangut(
    		int16_t value, int16_t format, touchgfx::Unicode::UnicodeChar* buf, uint16_t bufSize, const char* unit);
protected:
};

#endif // CUSTOMCONTAINER1_HPP
