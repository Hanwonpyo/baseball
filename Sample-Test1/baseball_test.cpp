#include "pch.h"
#include "../Project11/baseball.cpp"

TEST(BaseballGame, ThrowExceptionAboutLength)
{
	Baseball game;
	EXPECT_THROW(game.guess(string("12")), length_error);
}