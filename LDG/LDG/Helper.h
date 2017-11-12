#ifndef HELPER_H
#define HELPER_H

#include <string>
#include <iostream>
#include <Windows.h>

class Helper
{
public:
	Helper() = default;
	~Helper() = default;

	static void ClearScreen();
	static bool CheckInputYN(char _input);
	static bool CheckInputNum(int _input, int _min, int _max);
	static void WaitFor(int _milliseconds);
	static void DotDotDot(int _gapBetweenDots);
};

#endif