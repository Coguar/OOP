#include "stdafx.h"
#include "ClassCar.h"

CCar::CCar()
{
	m_isEngineTurnedOn = false;
	m_gearboxState = neutral;
	m_movementDirection = stay;
}

CCar::~CCar()
{
}

bool CCar::TurnOnEngine()
{
	if (m_isEngineTurnedOn)
	{
		return false;
	}
	m_isEngineTurnedOn = true;
	return true;
}

bool CCar::TurnOffEngine()
{
	if (!m_isEngineTurnedOn)
	{
		return false;
	}
	m_isEngineTurnedOn = false;
	return true;
}

int CCar::GetGear()
{
	return m_gearboxState;
}

int CCar::GetMovementDirection()
{
	return m_movementDirection;
}
