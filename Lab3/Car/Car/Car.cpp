// Car.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "ClassCar.h"

using namespace std;

static const map <string, States_Gearbox> GEARBOX_STATES_MAP = {
	{"back", States_Gearbox::back},
	{ "neutral", States_Gearbox::neutral },
	{ "first", States_Gearbox::first },
	{ "second", States_Gearbox::second },
	{ "third", States_Gearbox::third },
	{ "fourth", States_Gearbox::fourth },
	{ "fifth", States_Gearbox::fifth }
};

static const map <States_Gearbox, string> GEARBOX_INFO_MAP = {
	{ States_Gearbox::back, "back" },
	{ States_Gearbox::neutral, "neutral" },
	{ States_Gearbox::first, "first" },
	{ States_Gearbox::second, "second" },
	{ States_Gearbox::third, "third" },
	{ States_Gearbox::fourth, "fourth" },
	{ States_Gearbox::fifth, "fifth" }
};

static const map <Movement_Direction, string> MOVEMENT_INFO_MAP = {
	{ Movement_Direction::Forward, "Forward"},
	{ Movement_Direction::Backward, "Backward" },
	{ Movement_Direction::Stopped, "Stay" }
};

void ShowCarInfo(CCar const& car)
{
	string infoStr;
	infoStr = (car.IsEngineWorking() == true ? "Engine active!" : "Engine disabled");
	cout << infoStr << endl;

	cout << "Movement Direction: " << MOVEMENT_INFO_MAP.find(car.GetMovementDirection())->second << endl;
	cout << "Current Speed " << car.GetCurrentSpeed() << endl;
	cout << "Gearbox state " << GEARBOX_INFO_MAP.find(car.GetGear())->second << endl;

}

void ShowHelp()
{
	cout << "Using commands: " << endl;
	cout << "TurnOn/ TurnOff - to start/finish engine" << endl;
	cout << "SetSpeed - to set speed" << endl;
	cout << "SetGear  - to set gear from list :" << endl;
	cout << "back/ neutral/ first/ second/ third/ fouth/ fifth." << endl;
	cout << "Info - show information" << endl;
	cout << "Help - Show THIS info" << endl;
}

int main()
{
	CCar myCar;
	std::string str;
	unsigned value;
	while (!std::cin.eof() && !std::cin.fail())
	{
		std::cout << "> ";
		std::cin >> str;

		if (str == "TurnOff")
		{
			myCar.TurnOffEngine();
		}
		else if (str == "TurnOn")
		{
			myCar.TurnOnEngine();
		}
		else if (str == "SetSpeed")
		{
			std::cin >> value;
			myCar.SetSpeed(value);
		}
		else if (str == "SetGear")
		{
			std::cin >> str;
			if (GEARBOX_STATES_MAP.find(str) != GEARBOX_STATES_MAP.end())
			{
				myCar.SetGear(GEARBOX_STATES_MAP.find(str)->second);
			}
			else
			{
				cout << "Unknown command " << str <<endl;

			}
		}
		else if (str == "Info")
		{
			ShowCarInfo(myCar);
		}
		else if (str == "Help")
		{
			ShowHelp();
		}
		else
		{
			std::cout << "Invalid command!" << std::endl;
		}
	}

	return 0;
}

