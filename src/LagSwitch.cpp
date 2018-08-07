#include "LagSwitch.h"

#include <iostream>
#include <cstdlib>

LagSwitch::LagSwitch()
{
	this->m_state = off;
}

LagSwitch::~LagSwitch()
{
	// do nothing
}

lag_state_t LagSwitch::GetState()
{
	return m_state;
}

void PUBG_LagSwitch::On()
{
	std::cout << "Turning on lagswitch." << std::endl;

	system("powershell New-NetQosPolicy -Name \"PUBG1\" -AppPathNameMatchCondition TSLGame.exe -ThrottleRateActionBitsPerSecond 8");
	system("powershell New-NetQosPolicy -Name \"PUBG2\" -AppPathNameMatchCondition BeService.exe -ThrottleRateActionBitsPerSecond 8");

	std::cout << "Done." << std::endl;
	this->m_state = on;
}

void PUBG_LagSwitch::Off()
{
	std::cout << "Turning off lagswitch." << std::endl;

	system("powershell Remove-NetQosPolicy -Name \"PUBG1\" -confirm:$false");
	system("powershell Remove-NetQosPolicy -Name \"PUBG2\" -confirm:$false");

	std::cout << "Done." << std::endl;
	this->m_state = off;
}

void Fortnite_LagSwitch::On()
{
	std::cout << "Turning on lagswitch." << std::endl;

	system("powershell New-NetQosPolicy -Name \"fortnitelagswitch1\" -AppPathNameMatchCondition FortniteClient-Win64-Shipping.exe -ThrottleRateActionBitsPerSecond 2048");

	std::cout << "Done." << std::endl;
	this->m_state = on;
}

void Fortnite_LagSwitch::Off()
{
	std::cout << "Turning off lagswitch." << std::endl;

	system("powershell Remove-NetQosPolicy -Name \"fortnitelagswitch1\" -confirm:$false");

	std::cout << "Done." << std::endl;
	this->m_state = off;
}