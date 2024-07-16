#ifndef SCREEN2VIEW_HPP
#define SCREEN2VIEW_HPP

#include <gui_generated/screen2_screen/Screen2ViewBase.hpp>
#include <gui/screen2_screen/Screen2Presenter.hpp>

class Screen2View : public Screen2ViewBase
{
public:
    Screen2View();
    virtual ~Screen2View() {}
    virtual void setupScreen();
    virtual void tearDownScreen();

    virtual void scrollListMinUpdateItem(CustomContainer1& item, int16_t itemIndex);
    virtual void scrollListSecUpdateItem(CustomContainer1& item, int16_t itemIndex);

    /*
     * Virtual Action Handlers
     */
    virtual void onButtonStop();
    virtual void onButtonStart();
    virtual void onButtonReset();

    virtual void handleTickEvent();
protected:
};

#endif // SCREEN2VIEW_HPP
