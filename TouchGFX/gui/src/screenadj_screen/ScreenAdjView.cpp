#include <gui/screenadj_screen/ScreenAdjView.hpp>
#include <gui/containers/CustomContainer1.hpp>
extern "C"
{
#include "../../../../Core/Inc/clock.h"
extern struct sCurTime g_curTime;

}

uint16_t IntToTangut(int16_t value, int16_t format, touchgfx::Unicode::UnicodeChar* buf, uint16_t bufSize, const char* unit);

ScreenAdjView::ScreenAdjView()
{
	m_menu = 0;
	g_curTime.countHold = 1;
	SetAdjMenu(m_menu);
}
void ScreenAdjView::onButtonOK()
{
	g_curTime.sec = 0;
	g_curTime.countHold = 0;
}

void ScreenAdjView::setupScreen()
{
    ScreenAdjViewBase::setupScreen();
}

void ScreenAdjView::tearDownScreen()
{
    ScreenAdjViewBase::tearDownScreen();
}

void ScreenAdjView::SetAdjMenu(int menu)
{
	// adjust menu: month -> day -> hour -> min
	const char charList[] = {
			""}; // 月日時分
	uint8_t test[10];
	m_menu = menu & 3;

	test[0] = charList[m_menu*3+0];
	test[1] = charList[m_menu*3+1];
	test[2] = charList[m_menu*3+2];
	test[3] = 0;
	Unicode::fromUTF8(test, textAreaTypeBuffer, TEXTAREATYPE_SIZE);

	textAreaType.invalidate();

	UpdateValue();
}
#include <string.h>
void ScreenAdjView::UpdateValue()
{
	uint16_t pos = 0;
	touchgfx::Unicode::UnicodeChar buf[14];

	// pos: 3,6,9,12
	switch(m_menu)
	{
	case 0: // month
		pos = CustomContainer1::IntToTangut(g_curTime.month, 3, buf, 14, "");
		break;
	case 1: // day
		pos = CustomContainer1::IntToTangut(g_curTime.day, 3, buf, 14, "");
		break;
	case 2: // hour
		pos = CustomContainer1::IntToTangut(g_curTime.hour, 3, buf, 14, "");
		break;
	case 3: // min
		pos = CustomContainer1::IntToTangut(g_curTime.min, 3, buf, 14, "");
		break;
	}

	textAreaValue2C.setVisible(false);
	textAreaValue3C.setVisible(false);
	textAreaValue4C.setVisible(false);
	if(pos <= 6) // 2 chars
	{
		memcpy(textAreaValue2CBuffer, buf, TEXTAREAVALUE2C_SIZE);
		textAreaValue2C.setVisible(true);
	}
	else if(pos <= 9) // 3 chars
	{
		memcpy(textAreaValue3CBuffer, buf, TEXTAREAVALUE3C_SIZE);
		textAreaValue3C.setVisible(true);
	}
	else // 4 chars
	{
		memcpy(textAreaValue4CBuffer, buf, TEXTAREAVALUE4C_SIZE);
		textAreaValue4C.setVisible(true);
	}


	textAreaValue2C.invalidate();
	textAreaValue3C.invalidate();
	textAreaValue4C.invalidate();

}

/*
    static const uint16_t TEXTAREATYPE_SIZE = 10;
    touchgfx::Unicode::UnicodeChar textAreaTypeBuffer[TEXTAREATYPE_SIZE];
    static const uint16_t TEXTAREAVALUE4C_SIZE = 14;
    touchgfx::Unicode::UnicodeChar textAreaValue4CBuffer[TEXTAREAVALUE4C_SIZE];
    static const uint16_t TEXTAREAVALUE2C_SIZE = 10;
    touchgfx::Unicode::UnicodeChar textAreaValue2CBuffer[TEXTAREAVALUE2C_SIZE];
    static const uint16_t TEXTAREAVALUE3C_SIZE = 10;
    touchgfx::Unicode::UnicodeChar textAreaValue3CBuffer[TEXTAREAVALUE3C_SIZE];
*/
// type
void ScreenAdjView::functionNext1()
{
	int menu = m_menu;
	SetAdjMenu((menu+1) % 4);
}
void ScreenAdjView::functionPrev1()
{
	int menu = m_menu;
	SetAdjMenu((menu-1) % 4);
}
// value
void ScreenAdjView::functionNext2()
{
	const uint8_t dayTable[12] = {31,28,31,30, 31,30,31,31, 30,31,30,31};
	switch(m_menu)
	{
	case 0: // month
		g_curTime.month = (g_curTime.month) % 12 + 1;
		break;
	case 1: // day
		g_curTime.day   = (g_curTime.day) % dayTable[g_curTime.month-1] + 1;
		break;
	case 2: // hour
		g_curTime.hour = (g_curTime.hour + 1) % 24;
		break;
	case 3: // min
		g_curTime.min  = (g_curTime.min + 1) % 60;
		break;
	}
	UpdateValue();
}
void ScreenAdjView::functionPrev2()
{
	const uint8_t dayTable[12] = {31,28,31,30, 31,30,31,31, 30,31,30,31};
	switch(m_menu)
	{
	case 0: // month
		if(g_curTime.month == 1) g_curTime.month  = 12;
		else g_curTime.month--;
		break;
	case 1: // day
		if(g_curTime.day == 1) g_curTime.day = dayTable[g_curTime.month-1];
		else g_curTime.day--;
		break;
	case 2: // hour
		if(g_curTime.hour == 0) g_curTime.hour = 23;
		else g_curTime.hour --;
		break;
	case 3: // min
		if(g_curTime.min == 0) g_curTime.min = 59;
		else g_curTime.min --;
		break;
	}
	UpdateValue();
}
