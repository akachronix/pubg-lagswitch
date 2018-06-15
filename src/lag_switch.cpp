#include "lag_switch.hpp"

#include <cstdlib>

lagswitch::lagswitch()
{
    lagswitch_state = lag::off;
}

lagswitch::~lagswitch()
{
    // do nothing
}

lag lagswitch::get_state()
{
    return this->lagswitch_state;
}

void lagswitch::on()
{
    system("powershell New-NetQosPolicy -Name \"CHANGEME\" -AppPathNameMatchCondition TSLGame.exe -ThrottleRateActionBitsPerSecond 8");
    system("powershell New-NetQosPolicy -Name \"CHANGEME2\" -AppPathNameMatchCondition BeService.exe -ThrottleRateActionBitsPerSecond 8");
    
    this->lagswitch_state = lag::on;
}

void lagswitch::off()
{
    system("powershell Remove-NetQosPolicy -Name \"CHANGEME\" -confirm:$false");
    system("powershell Remove-NetQosPolicy -Name \"CHANGEME2\" -confirm:$false");

    this->lagswitch_state = lag::off;
}