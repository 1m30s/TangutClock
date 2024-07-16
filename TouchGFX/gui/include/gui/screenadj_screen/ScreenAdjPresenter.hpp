#ifndef SCREENADJPRESENTER_HPP
#define SCREENADJPRESENTER_HPP

#include <gui/model/ModelListener.hpp>
#include <mvp/Presenter.hpp>

using namespace touchgfx;

class ScreenAdjView;

class ScreenAdjPresenter : public touchgfx::Presenter, public ModelListener
{
public:
    ScreenAdjPresenter(ScreenAdjView& v);

    /**
     * The activate function is called automatically when this screen is "switched in"
     * (ie. made active). Initialization logic can be placed here.
     */
    virtual void activate();

    /**
     * The deactivate function is called automatically when this screen is "switched out"
     * (ie. made inactive). Teardown functionality can be placed here.
     */
    virtual void deactivate();

    virtual ~ScreenAdjPresenter() {}

private:
    ScreenAdjPresenter();

    ScreenAdjView& view;
};

#endif // SCREENADJPRESENTER_HPP
