#include <stdexcept>
#include<iostream>
using namespace std;
struct GuessResult
{
	bool solved;
	int strikes;
	int balls;
};
class Baseball
{
public:
	explicit Baseball(const string& question)
		:question(question)
	{

	}
	GuessResult guess(const string& guessNumber)
	{
		assertIllegalArgument(guessNumber);
		if(guessNumber == question)
			return {true,3,0 };
		return { false, countingStirke(guessNumber),countingBall(guessNumber)};
	}
	int countingBall(const string& guessNumber)
	{
		int count = 0;
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				if (i == j) continue;
				if (guessNumber[i] == question[j])
				{
					count++;
					break;
				}
			}
	
		}
		return count;
	}
	int countingStirke(const string& guessNumber)
	{
		int count = 0;
		for (int i = 0; i < 3; i++)
		{
			if (guessNumber[i] == question[i])
			{
				count++;
			}
		}
		return count;
	}
	bool isDuplicatedNumber(const string& guessNumber)
	{
		if (guessNumber[0] == guessNumber[1]
			|| guessNumber[1] == guessNumber[2]
			|| guessNumber[2] == guessNumber[0])
			return true;
		return false;
	}
	void assertIllegalArgument(const string& guessNumber)
	{
		if (guessNumber.length() != 3)
			throw length_error("Must be three letters.");

		for (char ch : guessNumber)
		{
			if (ch >= '0' && ch <='9') continue;
			throw invalid_argument("Must be number");
		}
		if (isDuplicatedNumber(guessNumber))
		{
			throw invalid_argument("Must not have same number");
		}
	}
private:
	string question;
};
