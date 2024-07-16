#include <gui/screen2_screen/Screen2View.hpp>
#include <gui/containers/CustomContainer1.hpp>

extern "C"
{
#include "../../../../Core/Inc/clock.h"
}


Screen2View::Screen2View()
{
	Stopwatch_Reset();
}

void Screen2View::setupScreen()
{
    Screen2ViewBase::setupScreen();
}

void Screen2View::tearDownScreen()
{
    Screen2ViewBase::tearDownScreen();
}
void Screen2View::scrollListMinUpdateItem(CustomContainer1& item, int16_t itemIndex)
{
	item.updateText(itemIndex, 0);
}
void Screen2View::scrollListSecUpdateItem(CustomContainer1& item, int16_t itemIndex)
{
	item.updateText(itemIndex, 0);
}
void Screen2View::handleTickEvent()
{
	// subsec

	CustomContainer1::IntToTangut(g_stopwatch.subsec, 8, textAreaSubsecBuffer, TEXTAREASUBSEC_SIZE, NULL);
	static uint8_t lastsec;

	if(lastsec != ::g_stopwatch.sec)
	{
		lastsec = ::g_stopwatch.sec;
		// update view
		scrollListSec.animateToItem(::g_stopwatch.sec, (::g_stopwatch.sec==0)?10: 30);
		scrollListMin.animateToItem(::g_stopwatch.min);
	}
	invalidate();
}
/*
    static const uint16_t TEXTAREASUBSEC_SIZE = 10;
    touchgfx::Unicode::UnicodeChar textAreaSubsecBuffer[TEXTAREASUBSEC_SIZE];
 */
/*
 * Virtual Action Handlers
 */
void Screen2View::onButtonStop()
{
	g_stopwatch.countHold = 1;
	buttonWithLabelStop.setVisible(false);
	buttonWithLabelStart.setVisible(true);
}
void Screen2View::onButtonStart()
{
	g_stopwatch.countHold = 0;
	buttonWithLabelStop.setVisible(true);
	buttonWithLabelStart.setVisible(false);
}
void Screen2View::onButtonReset()
{
	Stopwatch_Reset();
	buttonWithLabelStop.setVisible(false);
	buttonWithLabelStart.setVisible(true);
}
