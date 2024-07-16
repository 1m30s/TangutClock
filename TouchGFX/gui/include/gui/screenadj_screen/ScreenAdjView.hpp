#ifndef SCREENADJVIEW_HPP
#define SCREENADJVIEW_HPP

#include <gui_generated/screenadj_screen/ScreenAdjViewBase.hpp>
#include <gui/screenadj_screen/ScreenAdjPresenter.hpp>

class ScreenAdjView : public ScreenAdjViewBase
{
public:
    ScreenAdjView();
    virtual ~ScreenAdjView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();

    virtual void functionNext1();
    virtual void functionPrev1();
    virtual void functionPrev2();
    virtual void functionNext2();
    virtual void onButtonOK();
protected:
    void SetAdjMenu(int menu);
	void UpdateValue();
    int m_menu;
};

#endif // SCREENADJVIEW_HPP
