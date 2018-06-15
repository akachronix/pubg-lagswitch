#pragma once

enum class lag {off = 0, on = 1};

class lagswitch
{
public:
    lagswitch();
    ~lagswitch();

    lag get_state();

    void on();
    void off();

private:
    lag lagswitch_state;
};
