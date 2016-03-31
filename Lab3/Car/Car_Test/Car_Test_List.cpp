#include "stdafx.h"
#include "../Car/ClassCar.h"

using namespace std;

struct TempCar
{
	CCar myCar;

};

BOOST_FIXTURE_TEST_SUITE(temp, TempCar);

	BOOST_AUTO_TEST_CASE(first_start_our_car_must_be_true)
	{
		BOOST_CHECK(myCar.TurnOnEngine());
	}

	BOOST_AUTO_TEST_CASE(if_engine_turned_off_TurnOffEngine_must_return_false)
	{
		BOOST_CHECK(!myCar.TurnOffEngine());
	}

	BOOST_AUTO_TEST_CASE(if_engine_turned_off_gearbox_state_must_be_neutral)
	{
		BOOST_CHECK_EQUAL(myCar.GetGear(), 0);
	}

	BOOST_AUTO_TEST_CASE(if_engine_turned_off_car_must_be_staying)
	{
		BOOST_CHECK_EQUAL(myCar.GetMovementDirection(), 0);
	}

	struct when_engine_turned_on_: TempCar
	{
		when_engine_turned_on_()
		{
			myCar.TurnOnEngine();
		}

	};
	
	BOOST_FIXTURE_TEST_SUITE(when_engine_turned_on, when_engine_turned_on_);

		BOOST_AUTO_TEST_CASE(when_engine_turned_on_start_engine_must_return_false)
		{
			BOOST_CHECK(!myCar.TurnOnEngine());

		}

	BOOST_AUTO_TEST_SUITE_END();
BOOST_AUTO_TEST_SUITE_END();