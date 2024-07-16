#include <gui/screen1_screen/Screen1View.hpp>
extern "C"
{
#include "../../../../Core/Inc/clock.h"
}

#ifdef SIMULATOR

struct sCurTime g_curTime;
struct sStopwatch g_stopwatch;

// not support leap year
void CurTime_Init()
{
	g_curTime.month = 1;
	g_curTime.day = 1;
	g_curTime.hour = 23;
	g_curTime.min = 59;
	g_curTime.sec = 0;
	g_curTime.countHold = 0;
}
void CurTime_Tick()
{
	if(g_curTime.countHold) return;
	const uint8_t dayTable[12] = {31,28,31,30, 31,30,31,31, 30,31,30,31};
	g_curTime.sec ++;
	if(g_curTime.sec>=60)
	{
		g_curTime.sec = 0;
		g_curTime.min ++;
		if(g_curTime.min>=60)
		{
			g_curTime.min = 0;
			g_curTime.hour ++;
			if(g_curTime.hour >=24)
			{
				g_curTime.hour = 0;
				g_curTime.day++;
				if(g_curTime.day > dayTable[g_curTime.month-1])
				{
					g_curTime.day = 1;
					g_curTime.month++;
					if(g_curTime.month>12)
					{
						g_curTime.month = 0;
					}
				}
			}
		}
	}
}
void Stopwatch_Reset()
{
	g_stopwatch.min = 0;
	g_stopwatch.sec = 0;
	g_stopwatch.subsec = 0;
	g_stopwatch.countHold = 1;
}
void Stopwatch_Tick()
{
	if(g_stopwatch.countHold == 0)
	{
		g_stopwatch.subsec ++;
		if(g_stopwatch.subsec>=1000)
		{
			g_stopwatch.subsec = 0;
			g_stopwatch.sec ++;
			if(g_stopwatch.sec>=60)
			{
				g_stopwatch.sec = 0;
				g_stopwatch.min ++;
			}
		}
	}
}
#endif
Screen1View::Screen1View()
{
//	scrollListMin.setAnimationSteps(200);
	scrollListSec.setEasingEquation(touchgfx::EasingEquations::bounceEaseOut);
#ifdef SIMULATOR
	CurTime_Init();
#endif
	updateDate();
}
/*
 * Member
    touchgfx::Box __background;
    touchgfx::Image image1;
    touchgfx::Image image2;
    touchgfx::ScrollList scrollListHour;
    touchgfx::DrawableListItems<CustomContainer1, 2> scrollListHourListItems;
    touchgfx::ScrollList scrollListMin;
    touchgfx::DrawableListItems<CustomContainer1, 2> scrollListMinListItems;
    touchgfx::ScrollList scrollListSec;
    touchgfx::DrawableListItems<CustomContainer1, 2> scrollListSecListItems;
    touchgfx::TextArea textArea2_2;
    touchgfx::TextArea textArea2_1;
    touchgfx::TextArea textArea2;
    touchgfx::ButtonWithLabel buttonWithLabel2;
    touchgfx::ButtonWithLabel buttonWithLabel1;
    touchgfx::TextArea textArea3;
 */
void Screen1View::setupScreen()
{
    Screen1ViewBase::setupScreen();
}

void Screen1View::tearDownScreen()
{
    Screen1ViewBase::tearDownScreen();
}

void Screen1View::scrollListHourUpdateItem(CustomContainer1& item, int16_t itemIndex)
{
	item.updateText(itemIndex, 2);
}
void Screen1View::scrollListMinUpdateItem(CustomContainer1& item, int16_t itemIndex)
{
	item.updateText(itemIndex, 0);
}
void Screen1View::scrollListSecUpdateItem(CustomContainer1& item, int16_t itemIndex)
{
	item.updateText(itemIndex, 0);
}
void Screen1View::onTick()
{
//	int l[] = {0,1,58,59};
//	static int a;
//	a = (::g_curTime.sec)%4;
//	scrollListSec.animateToItem(l[a], 10);
	scrollListSec.animateToItem(::g_curTime.sec, (::g_curTime.sec==0)?4: 10);
	static int a;
	if((a++ & 7) == 0)
	{
		scrollListMin.animateToItem(::g_curTime.min);
		scrollListHour.animateToItem(::g_curTime.hour);
	}
	invalidate();
}
void Screen1View::updateDate()
{
	const char charList[] = {
			""  // 0-9,10
			""}; // 正年月日時分
	uint8_t test[7*3+2];
	int pos = 0;
	if(g_curTime.month >= 11)
	{
		test[pos+0] = charList[10*3+0];
		test[pos+1] = charList[10*3+1];
		test[pos+2] = charList[10*3+2];
		pos+=3;
		int d = (g_curTime.month-10);
		test[pos+0] = charList[d*3+0];
		test[pos+1] = charList[d*3+1];
		test[pos+2] = charList[d*3+2];
		pos+=3;
	}
	else
	{
		int d = g_curTime.month;
		if(d==1) d=11;
		test[pos+0] = charList[d*3+0];
		test[pos+1] = charList[d*3+1];
		test[pos+2] = charList[d*3+2];
		pos+=3;
	}
	test[pos+0] = charList[13*3+0];
	test[pos+1] = charList[13*3+1];
	test[pos+2] = charList[13*3+2];
	pos+=3;
	if(g_curTime.month <= 10)
	{
		// space
		test[pos++] = ' ';
	}

	if(g_curTime.day >= 10)
	{
		if(g_curTime.day >= 20)
		{
			int d = g_curTime.day/10;
			test[pos+0] = charList[d*3+0];
			test[pos+1] = charList[d*3+1];
			test[pos+2] = charList[d*3+2];
			pos+=3;
		}
		test[pos+0] = charList[10*3+0];
		test[pos+1] = charList[10*3+1];
		test[pos+2] = charList[10*3+2];
		pos+=3;

	}
	{
		int d = g_curTime.day%10;
		if(d != 0)
		{
			test[pos+0] = charList[d*3+0];
			test[pos+1] = charList[d*3+1];
			test[pos+2] = charList[d*3+2];
			pos+=3;
		}
	}
	test[pos+0] = charList[14*3+0];
	test[pos+1] = charList[14*3+1];
	test[pos+2] = charList[14*3+2];
	pos+=3;
	test[pos+0] = '\0';

	Unicode::fromUTF8(test, textAreaDayBuffer, TEXTAREADAY_SIZE);
	textAreaDay.invalidate();
}


