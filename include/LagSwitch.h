#pragma once

enum lag_state_t {off = 0, on = 1};

class LagSwitch
{
public:
	LagSwitch();
	~LagSwitch();

	virtual void On() =0;
	virtual void Off() =0;

	lag_state_t GetState();

protected:
	lag_state_t m_state;
};

class PUBG_LagSwitch : public LagSwitch
{
public:
	using LagSwitch::LagSwitch;

	void On();
	void Off();
};
