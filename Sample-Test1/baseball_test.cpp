#include "pch.h"
#include "../Project11/baseball.cpp"

TEST(BaseballGame, ThrowExceptionAboutLength)
{
	Baseball game;
	EXPECT_THROW(game.guess(string("12")), length_error);
}
TEST(BaseballGame, ThrowExceptionWhenInvalidChar)
{
	Baseball game;
	EXPECT_THROW(game.guess(string("12s")), invalid_argument);
}
