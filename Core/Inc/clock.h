/*
 * clock.h
 *
 *  Created on: Jul 14, 2024
 *      Author: Hiroyuki Yamada (Y-Logic)
 */

#ifndef APPLICATION_USER_CLOCK_H_
#define APPLICATION_USER_CLOCK_H_

struct sCurTime
{
	uint8_t month;
	uint8_t day;
	uint8_t hour;
	uint8_t min;
	uint8_t sec;
	uint8_t countHold;
};
extern struct sCurTime g_curTime;
struct sStopwatch
{
	uint16_t subsec; // 0-999
	uint8_t sec;
	uint8_t min;
	uint8_t countHold;
};
extern struct sStopwatch g_stopwatch;
void CurTime_Init();
void CurTime_Tick();
void Stopwatch_Reset();
void Stopwatch_Tick();



#endif /* APPLICATION_USER_CLOCK_H_ */
