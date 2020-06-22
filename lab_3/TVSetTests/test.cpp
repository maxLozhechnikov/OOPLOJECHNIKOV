#include "pch.h"
#include "../TVSet/Controller.h"
#include "../TVSet/CTVSet.h"

TEST(GetChannelTest, HandlesPositiveInput) {
    CTVSet TV;
    TV.TurnOn();
    EXPECT_EQ(TV.GetChannel(), 1);
    TV.TurnOff();
    EXPECT_EQ(TV.GetChannel(), 0);
}

TEST(SelectChannelTest, HandlesPositiveInput) {
    CTVSet TV;
    TV.TurnOn();
    TV.SelectChannel(99);

    EXPECT_EQ(TV.GetChannel(), 99);
}

TEST(ChannelAfterRestartTest, HandlesPositiveInput) {
    CTVSet TV;
    TV.TurnOn();
    TV.SelectChannel(10);
    TV.TurnOff();
    TV.TurnOn();

    EXPECT_EQ(TV.GetChannel(), 10);
}

TEST(ChannelAfterSelectingNotExistingChannel, HandlesPositiveInput) {
    CTVSet TV;
    TV.TurnOn();
    TV.SelectChannel(10);
    TV.SelectChannel(100);

    EXPECT_EQ(TV.GetChannel(), 10);
}

TEST(TryingSelectChannelWhenTVTurnedOff, HandlesPositiveInput) {
    CTVSet TV;
    TV.TurnOff();
    TV.SelectChannel(2);

    EXPECT_EQ(TV.GetChannel(), 0);
}

TEST(TestingPreviousChannel, HandlesPositiveInput) {
    CTVSet TV;
    TV.TurnOn();
    TV.SelectChannel(10);
    TV.SelectChannel(99);

    EXPECT_EQ(TV.GetChannel(), 99);
    TV.SelectPreviousChannel();

    EXPECT_EQ(TV.GetChannel(), 10);
}