#pragma once

static const enum STATES_GEARBOX { back = -1, neutral = 0, first = 1, second = 2, third = 3, fourth = 4, fifth = 5 };

static const enum MOVEMENT_DIRECTION {backward = -1, stay = 0, forward = 1};

class CCar
{
public:
	CCar();
	~CCar();

	bool TurnOnEngine();

	bool TurnOffEngine();

	int GetGear();

	int GetMovementDirection();
private:

	bool m_isEngineTurnedOn;

	STATES_GEARBOX m_gearboxState;

	MOVEMENT_DIRECTION m_movementDirection;
};



