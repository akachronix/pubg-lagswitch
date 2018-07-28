#pragma once

/* Fortnite Processes:
 * FortniteClient-Win64-Shipping.exe
 * FortniteClient-Win64-Shipping_BE.exe
 * FortniteLauncher.exe
 * BEService.exe
 */

enum class lag {off = 0, on = 1};

class pubglagswitch
{
public:
    pubglagswitch();
    ~pubglagswitch();

    lag get_state();

    void on();
    void off();

private:
    lag lagswitch_state;
};

class fortnitelagswitch
{
public:
    fortnitelagswitch();
    ~fortnitelagswitch();

    lag get_state();

    void on();
    void off();

private:
    lag lagswitch_state;
};
