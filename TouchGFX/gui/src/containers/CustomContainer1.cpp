#include <gui/containers/CustomContainer1.hpp>

CustomContainer1::CustomContainer1()
{

}

void CustomContainer1::initialize()
{
    CustomContainer1Base::initialize();
}

// format example
// 0: " 零"、二十、二一、...
// 1: " 零"、二十、二十一、...
// 2: " 正"、二十、二一、...
// 3: "零"、二十、二十一、...
// 8: "零零零"
uint16_t CustomContainer1::IntToTangut(int16_t value, int16_t format, touchgfx::Unicode::UnicodeChar* buf, uint16_t bufSize, const char* unit)
{
	const char charList[] = {
			""  // 0-9,10
			""}; // 正年月日時分
	uint8_t test[10];
	uint16_t pos = 0;

	if(format == 8)
	{
		uint8_t d = value/100;
		test[pos++] = charList[d*3+0];
		test[pos++] = charList[d*3+1];
		test[pos++] = charList[d*3+2];

		d = (value/10) % 10;
		test[pos++] = charList[d*3+0];
		test[pos++] = charList[d*3+1];
		test[pos++] = charList[d*3+2];

		d = (value) % 10;
		test[pos++] = charList[d*3+0];
		test[pos++] = charList[d*3+1];
		test[pos++] = charList[d*3+2];
	}

	else if(value <= 10) // 1 char
	{
		if(format != 3) test[pos++] = ' ';
		if((format == 2) && (value == 0))
		{
			value = 11;
		}
		test[pos++] = charList[value*3+0];
		test[pos++] = charList[value*3+1];
		test[pos++] = charList[value*3+2];
	}
	else if(value <= 19) // 2 chars (11-19)
	{
		int d = value - 10;
		test[pos++] = charList[10*3+0];
		test[pos++] = charList[10*3+1];
		test[pos++] = charList[10*3+2];
		test[pos++] = charList[d*3+0];
		test[pos++] = charList[d*3+1];
		test[pos++] = charList[d*3+2];
	}
	else if((value % 10) == 0) // 2 chars (20, 30, 40,..., 90)
	{
		int d = value / 10;
		test[pos++] = charList[d*3+0];
		test[pos++] = charList[d*3+1];
		test[pos++] = charList[d*3+2];

		test[pos++] = charList[10*3+0];
		test[pos++] = charList[10*3+1];
		test[pos++] = charList[10*3+2];
	}
	else if(format == 0 || format == 2) // 2 chars
	{
		int d = value / 10;
		test[pos++] = charList[d*3+0];
		test[pos++] = charList[d*3+1];
		test[pos++] = charList[d*3+2];

		d = value % 10;
		test[pos++] = charList[d*3+0];
		test[pos++] = charList[d*3+1];
		test[pos++] = charList[d*3+2];
	}
	else if(format == 1 || format == 3) // 3 chars
	{
		int d = value / 10;
		test[pos++] = charList[d*3+0];
		test[pos++] = charList[d*3+1];
		test[pos++] = charList[d*3+2];

		test[pos++] = charList[10*3+0];
		test[pos++] = charList[10*3+1];
		test[pos++] = charList[10*3+2];

		d = value % 10;
		test[pos++] = charList[d*3+0];
		test[pos++] = charList[d*3+1];
		test[pos++] = charList[d*3+2];
	}

	if(unit)
	{
		test[pos++] = unit[0];
		test[pos++] = unit[1];
		test[pos++] = unit[2];
	}
	test[pos] = 0;

	Unicode::fromUTF8(test, buf, bufSize);
	return pos;
}

#include <string.h>
void CustomContainer1::updateText(int16_t value, int16_t format)
{

	textArea1Buffer[0] = '0';
	textArea2Buffer[0] = '0';

	touchgfx::Unicode::UnicodeChar buf[TEXTAREA1_SIZE];
	IntToTangut(value, format, buf, TEXTAREA1_SIZE, NULL);

	if(value <= 10) // 1 char
	{
		memcpy(textArea1Buffer, buf, TEXTAREA1_SIZE);
		textArea1.setVisible(true);
		textArea2.setVisible(false);
	}
	else if(value <= 19) // 2 chars (11-19)
	{
		memcpy(textArea2Buffer, buf, TEXTAREA1_SIZE);
		textArea1.setVisible(false);
		textArea2.setVisible(true);
	}
	else if((value % 10) == 0) // 2 chars (20, 30, 40,..., 90)
	{
		memcpy(textArea2Buffer, buf, TEXTAREA1_SIZE);
		textArea1.setVisible(false);
		textArea2.setVisible(true);
	}
	else if(format == 0 || format == 2) // 2 chars
	{
		memcpy(textArea2Buffer, buf, TEXTAREA1_SIZE);
		textArea1.setVisible(false);
		textArea2.setVisible(true);
	}
	else if(format == 1) // 3 chars
	{
		memcpy(textArea1Buffer, buf, TEXTAREA1_SIZE);
		textArea1.setVisible(true);
		textArea2.setVisible(false);
	}

	//const touchgfx::Unicode::UnicodeChar numList[] = {};
	//Unicode::snprintf(textArea1Buffer, TEXTAREA1_SIZE, "%d", value);
	textArea1.invalidate();
	textArea2.invalidate();
}
