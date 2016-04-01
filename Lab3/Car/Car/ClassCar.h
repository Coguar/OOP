#pragma once

static const enum STATES_GEARBOX { back = -1, neutral = 0, first = 1, second = 2, third = 3, fourth = 4, fifth = 5 };

static const enum MOVEMENT_DIRECTION {backward = -1, stay = 0, forward = 1};

static const std::map<STATES_GEARBOX, std::pair<unsigned, unsigned>> SPEED_RANGE = {
	{back, {0, 20}},
	{neutral, {0, 150}},
	{first, {0, 30}},
	{second, {20, 50}},
	{third, {30, 60}},
	{fourth, {40, 90}},
	{fifth, {50, 150}}
};

class CCar
{
public:
	CCar();
	~CCar();

	bool IsEngineWorking() const
	{
		return m_isEngineTurnedOn;
	}

	bool TurnOnEngine();

	bool TurnOffEngine();

	int GetGear() const;

	int GetMovementDirection() const;

	unsigned GetCurrentSpeed() const;

	bool SetSpeed(unsigned const& speed);

	bool SetGear(STATES_GEARBOX const& gearState);


private:

	void SetMovementDirection();

	unsigned m_currentSpeed;

	bool m_isEngineTurnedOn;

	STATES_GEARBOX m_gearboxState;

	MOVEMENT_DIRECTION m_movementDirection;
};



