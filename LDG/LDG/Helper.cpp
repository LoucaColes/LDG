#include "Helper.h"

void Helper::ClearScreen()
{
	std::cout << std::string(100, '\n');
}

bool Helper::CheckInputYN(char _input)
{
	if (_input == 'Y' || _input == 'N')
	{
		return true;
	}
	else
	{
		return false;
	}
}

void Helper::WaitFor(int _milliseconds)
{
	Sleep(_milliseconds);
}

void Helper::DotDotDot(int __gapBetweenDots)
{
	std::cout << ".";
	Sleep(__gapBetweenDots);
	std::cout << ".";
	Sleep(__gapBetweenDots);
	std::cout << ".";
	Sleep(__gapBetweenDots);
	std::cout << ".";
	Sleep(__gapBetweenDots);
	std::cout << ".";
	Sleep(__gapBetweenDots);
	std::cout << std::endl;
}

bool Helper::CheckInputNum(int _num, int _min, int _max)
{
	if (_num >= _min && _num <= _max)
	{
		return true;
	}
	else
	{
		return false;
	}
}