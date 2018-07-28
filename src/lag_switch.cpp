#include "lag_switch.hpp"

#include <cstdlib>

pubglagswitch::pubglagswitch()
{
    this->lagswitch_state = lag::off;
}

pubglagswitch::~pubglagswitch()
{
    // do nothing
}

lag pubglagswitch::get_state()
{
    return this->lagswitch_state;
}

void pubglagswitch::on()
{
    system("powershell New-NetQosPolicy -Name \"pubglagswitch1\" -AppPathNameMatchCondition TSLGame.exe -ThrottleRateActionBitsPerSecond 8");
    system("powershell New-NetQosPolicy -Name \"pubglagswitch2\" -AppPathNameMatchCondition BeService.exe -ThrottleRateActionBitsPerSecond 8");
    
    this->lagswitch_state = lag::on;
}

void pubglagswitch::off()
{
    system("powershell Remove-NetQosPolicy -Name \"pubglagswitch1\" -confirm:$false");
    system("powershell Remove-NetQosPolicy -Name \"pubglagswitch2\" -confirm:$false");

    this->lagswitch_state = lag::off;
}

fortnitelagswitch::fortnitelagswitch()
{
    this->lagswitch_state = lag::off;
}

fortnitelagswitch::~fortnitelagswitch()
{
    // do nothing
}

lag fortnitelagswitch::get_state()
{
    return this->lagswitch_state;
}

void fortnitelagswitch::on()
{
    // game appears to work when throttled to 16384 bits/s
    system("powershell New-NetQosPolicy -Name \"fortnitelagswitch1\" -AppPathNameMatchCondition FortniteClient-Win64-Shipping.exe -ThrottleRateActionBitsPerSecond 2048");
    this->lagswitch_state = lag::on;
}

void fortnitelagswitch::off()
{
    system("powershell Remove-NetQosPolicy -Name \"fortnitelagswitch1\" -confirm:$false");  
    this->lagswitch_state = lag::off;
}