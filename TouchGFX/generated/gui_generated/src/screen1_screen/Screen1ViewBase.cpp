/*********************************************************************************/
/********** THIS FILE IS GENERATED BY TOUCHGFX DESIGNER, DO NOT MODIFY ***********/
/*********************************************************************************/
#include <gui_generated/screen1_screen/Screen1ViewBase.hpp>
#include <touchgfx/Color.hpp>
#include <images/BitmapDatabase.hpp>
#include <texts/TextKeysAndLanguages.hpp>

Screen1ViewBase::Screen1ViewBase() :
    updateItemCallback(this, &Screen1ViewBase::updateItemCallbackHandler),
    buttonCallback(this, &Screen1ViewBase::buttonCallbackHandler),
    frameCountOnTickInterval(0)
{
    __background.setPosition(0, 0, 240, 320);
    __background.setColor(touchgfx::Color::getColorFromRGB(0, 0, 0));
    add(__background);

    image1.setXY(0, 0);
    image1.setBitmap(touchgfx::Bitmap(BITMAP_PAPER_BG_240X320_ID));
    add(image1);

    image2.setXY(0, 6);
    image2.setBitmap(touchgfx::Bitmap(BITMAP_GLASS_THEME_IMAGES_BARS_240X240_BOTTOM_DIM_DARK_ID));
    add(image2);

    scrollListHour.setPosition(5, 31, 76, 219);
    scrollListHour.setHorizontal(true);
    scrollListHour.setCircular(true);
    scrollListHour.setEasingEquation(touchgfx::EasingEquations::quadEaseOut);
    scrollListHour.setSwipeAcceleration(10);
    scrollListHour.setDragAcceleration(10);
    scrollListHour.setNumberOfItems(24);
    scrollListHour.setPadding(0, 0);
    scrollListHour.setSnapping(true);
    scrollListHour.setOvershootPercentage(75);
    scrollListHour.setDrawableSize(79, 0);
    scrollListHour.setDrawables(scrollListHourListItems, updateItemCallback);
    add(scrollListHour);

    scrollListMin.setPosition(81, 31, 72, 219);
    scrollListMin.setHorizontal(true);
    scrollListMin.setCircular(true);
    scrollListMin.setEasingEquation(touchgfx::EasingEquations::backEaseOut);
    scrollListMin.setSwipeAcceleration(10);
    scrollListMin.setDragAcceleration(10);
    scrollListMin.setNumberOfItems(60);
    scrollListMin.setPadding(0, 0);
    scrollListMin.setSnapping(true);
    scrollListMin.setOvershootPercentage(75);
    scrollListMin.setDrawableSize(79, 0);
    scrollListMin.setDrawables(scrollListMinListItems, updateItemCallback);
    add(scrollListMin);

    scrollListSec.setPosition(161, 31, 79, 219);
    scrollListSec.setHorizontal(true);
    scrollListSec.setCircular(true);
    scrollListSec.setEasingEquation(touchgfx::EasingEquations::bounceEaseOut);
    scrollListSec.setSwipeAcceleration(10);
    scrollListSec.setDragAcceleration(10);
    scrollListSec.setNumberOfItems(60);
    scrollListSec.setPadding(0, 0);
    scrollListSec.setSnapping(true);
    scrollListSec.setOvershootPercentage(75);
    scrollListSec.setDrawableSize(79, 0);
    scrollListSec.setDrawables(scrollListSecListItems, updateItemCallback);
    add(scrollListSec);

    textArea2_2.setXY(183, 221);
    textArea2_2.setColor(touchgfx::Color::getColorFromRGB(18, 9, 4));
    textArea2_2.setLinespacing(0);
    textArea2_2.setTypedText(touchgfx::TypedText(T___SINGLEUSE_ILEP));
    add(textArea2_2);

    textArea2_1.setXY(26, 221);
    textArea2_1.setColor(touchgfx::Color::getColorFromRGB(18, 9, 4));
    textArea2_1.setLinespacing(0);
    textArea2_1.setTypedText(touchgfx::TypedText(T___SINGLEUSE_WRD6));
    add(textArea2_1);

    textArea2.setXY(103, 221);
    textArea2.setColor(touchgfx::Color::getColorFromRGB(18, 9, 4));
    textArea2.setLinespacing(0);
    textArea2.setTypedText(touchgfx::TypedText(T___SINGLEUSE_73D9));
    add(textArea2);

    buttonWithLabel2.setXY(17, 278);
    buttonWithLabel2.setBitmaps(touchgfx::Bitmap(BITMAP_ALTERNATE_THEME_IMAGES_WIDGETS_BUTTON_REGULAR_HEIGHT_36_TINY_ROUNDED_DISABLED_ID), touchgfx::Bitmap(BITMAP_ALTERNATE_THEME_IMAGES_WIDGETS_BUTTON_REGULAR_HEIGHT_36_TINY_ROUNDED_NORMAL_ID));
    buttonWithLabel2.setLabelText(touchgfx::TypedText(T___SINGLEUSE_H435));
    buttonWithLabel2.setLabelColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    buttonWithLabel2.setLabelColorPressed(touchgfx::Color::getColorFromRGB(255, 255, 255));
    buttonWithLabel2.setAction(buttonCallback);
    add(buttonWithLabel2);

    buttonWithLabel1.setXY(128, 278);
    buttonWithLabel1.setBitmaps(touchgfx::Bitmap(BITMAP_ALTERNATE_THEME_IMAGES_WIDGETS_BUTTON_REGULAR_HEIGHT_36_TINY_ROUNDED_DISABLED_ID), touchgfx::Bitmap(BITMAP_ALTERNATE_THEME_IMAGES_WIDGETS_BUTTON_REGULAR_HEIGHT_36_TINY_ROUNDED_NORMAL_ID));
    buttonWithLabel1.setLabelText(touchgfx::TypedText(T___SINGLEUSE_TX5L));
    buttonWithLabel1.setLabelColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    buttonWithLabel1.setLabelColorPressed(touchgfx::Color::getColorFromRGB(255, 255, 255));
    buttonWithLabel1.setAction(buttonCallback);
    add(buttonWithLabel1);

    textAreaDay.setPosition(0, 13, 240, 37);
    textAreaDay.setColor(touchgfx::Color::getColorFromRGB(18, 31, 48));
    textAreaDay.setLinespacing(0);
    Unicode::snprintf(textAreaDayBuffer, TEXTAREADAY_SIZE, "%s", touchgfx::TypedText(T___SINGLEUSE_JDCK).getText());
    textAreaDay.setWildcard(textAreaDayBuffer);
    textAreaDay.setTypedText(touchgfx::TypedText(T___SINGLEUSE_65GX));
    add(textAreaDay);

    modalWindow1.setBackground(touchgfx::BitmapId(BITMAP_LIGHT_THEME_IMAGES_CONTAINERS_SMALL_WIDE_OUTLINED_NEUTRAL_ID), 13, 85);
    modalWindow1.setShadeColor(touchgfx::Color::getColorFromRGB(0, 0, 0));
    modalWindow1.hide();
    textArea3.setPosition(20, 13, 175, 85);
    textArea3.setColor(touchgfx::Color::getColorFromRGB(0, 0, 0));
    textArea3.setLinespacing(6);
    textArea3.setTypedText(touchgfx::TypedText(T___SINGLEUSE_UUQW));
    modalWindow1.add(textArea3);

    buttonWithLabelYes.setXY(4, 98);
    buttonWithLabelYes.setBitmaps(touchgfx::Bitmap(BITMAP_ALTERNATE_THEME_IMAGES_WIDGETS_BUTTON_REGULAR_HEIGHT_36_TINY_ROUNDED_ACTION_ID), touchgfx::Bitmap(BITMAP_ALTERNATE_THEME_IMAGES_WIDGETS_BUTTON_REGULAR_HEIGHT_36_TINY_ROUNDED_PRESSED_ID));
    buttonWithLabelYes.setLabelText(touchgfx::TypedText(T___SINGLEUSE_WN60));
    buttonWithLabelYes.setLabelColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    buttonWithLabelYes.setLabelColorPressed(touchgfx::Color::getColorFromRGB(255, 255, 255));
    buttonWithLabelYes.setAction(buttonCallback);
    modalWindow1.add(buttonWithLabelYes);

    buttonWithLabelNo.setXY(107, 98);
    buttonWithLabelNo.setBitmaps(touchgfx::Bitmap(BITMAP_ALTERNATE_THEME_IMAGES_WIDGETS_BUTTON_REGULAR_HEIGHT_36_TINY_ROUNDED_ACTION_ID), touchgfx::Bitmap(BITMAP_ALTERNATE_THEME_IMAGES_WIDGETS_BUTTON_REGULAR_HEIGHT_36_TINY_ROUNDED_PRESSED_ID));
    buttonWithLabelNo.setLabelText(touchgfx::TypedText(T___SINGLEUSE_J97W));
    buttonWithLabelNo.setLabelColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    buttonWithLabelNo.setLabelColorPressed(touchgfx::Color::getColorFromRGB(255, 255, 255));
    buttonWithLabelNo.setAction(buttonCallback);
    modalWindow1.add(buttonWithLabelNo);

    add(modalWindow1);
}

Screen1ViewBase::~Screen1ViewBase()
{

}

void Screen1ViewBase::setupScreen()
{
    scrollListHour.initialize();
    for (int i = 0; i < scrollListHourListItems.getNumberOfDrawables(); i++)
    {
        scrollListHourListItems[i].initialize();
    }
    scrollListMin.initialize();
    for (int i = 0; i < scrollListMinListItems.getNumberOfDrawables(); i++)
    {
        scrollListMinListItems[i].initialize();
    }
    scrollListSec.initialize();
    for (int i = 0; i < scrollListSecListItems.getNumberOfDrawables(); i++)
    {
        scrollListSecListItems[i].initialize();
    }
}

void Screen1ViewBase::buttonCallbackHandler(const touchgfx::AbstractButton& src)
{
    if (&src == &buttonWithLabel1)
    {
        //Interaction1
        //When buttonWithLabel1 clicked change screen to Screen2
        //Go to Screen2 with screen transition towards East
        application().gotoScreen2ScreenSlideTransitionEast();
    }
    if (&src == &buttonWithLabel2)
    {
        //Interaction2
        //When buttonWithLabel2 clicked show modalWindow1
        //Show modalWindow1
        modalWindow1.setVisible(true);
        modalWindow1.invalidate();
    }
    if (&src == &buttonWithLabelNo)
    {
        //Interaction3
        //When buttonWithLabelNo clicked hide modalWindow1
        //Hide modalWindow1
        modalWindow1.setVisible(false);
        modalWindow1.invalidate();
    }
    if (&src == &buttonWithLabelYes)
    {
        //Interaction4
        //When buttonWithLabelYes clicked change screen to ScreenAdj
        //Go to ScreenAdj with screen transition towards South
        application().gotoScreenAdjScreenWipeTransitionSouth();
    }
}

void Screen1ViewBase::handleTickEvent()
{
    frameCountOnTickInterval++;
    if(frameCountOnTickInterval == TICK_ONTICK_INTERVAL)
    {
        //OnTick
        //When every N tick call virtual function
        //Call onTick
        onTick();
        frameCountOnTickInterval = 0;
    }
}

void Screen1ViewBase::updateItemCallbackHandler(touchgfx::DrawableListItemsInterface* items, int16_t containerIndex, int16_t itemIndex)
{
    if (items == &scrollListHourListItems)
    {
        scrollListHourUpdateItem(scrollListHourListItems[containerIndex], itemIndex);
    }

    if (items == &scrollListMinListItems)
    {
        scrollListMinUpdateItem(scrollListMinListItems[containerIndex], itemIndex);
    }

    if (items == &scrollListSecListItems)
    {
        scrollListSecUpdateItem(scrollListSecListItems[containerIndex], itemIndex);
    }
}
