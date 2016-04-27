#include "stdafx.h"
#include "../Car/ClassCar.h"

using namespace std;

struct TempCar
{
	CCar myCar;

};

BOOST_FIXTURE_TEST_SUITE(when_engine_turned_off_, TempCar);

	BOOST_AUTO_TEST_CASE(first_start_our_car_must_be_true)
	{
		BOOST_CHECK(myCar.TurnOnEngine());
	}

	BOOST_AUTO_TEST_CASE(if_engine_turned_off_TurnOffEngine_must_return_false)
	{
		BOOST_CHECK(!myCar.TurnOffEngine());
	}

	BOOST_AUTO_TEST_CASE(gearbox_state_must_be_neutral)
	{
		BOOST_CHECK(myCar.GetGear() == States_Gearbox::neutral);
	}

	BOOST_AUTO_TEST_CASE(car_must_be_staying)
	{
		BOOST_CHECK(myCar.GetMovementDirection() == Movement_Direction::Stopped);
	}

	BOOST_AUTO_TEST_CASE(current_speed_must_be_zero)
	{
		BOOST_CHECK_EQUAL(myCar.GetCurrentSpeed(), 0);
	}

	BOOST_AUTO_TEST_CASE(SetSpeed_return_false)
	{
		BOOST_CHECK(!myCar.SetSpeed(10));
	}

	BOOST_AUTO_TEST_CASE(SetGear_return_false)
	{
		BOOST_CHECK(!myCar.SetGear(States_Gearbox::first));
	}

	struct when_engine_turned_on_: TempCar
	{
		when_engine_turned_on_()
		{
			myCar.TurnOnEngine();
		}

	};
	
	BOOST_FIXTURE_TEST_SUITE(when_engine_turned_on, when_engine_turned_on_);

		BOOST_AUTO_TEST_CASE(start_engine_must_return_false)
		{
			BOOST_CHECK(!myCar.TurnOnEngine());

		}

		BOOST_AUTO_TEST_CASE(TurnOff_engine_must_return_true)
		{
			BOOST_CHECK(myCar.TurnOffEngine());

		}

		BOOST_AUTO_TEST_CASE(start_speed_must_be_zero)
		{
			BOOST_CHECK_EQUAL(myCar.GetCurrentSpeed(), 0);
		}

		BOOST_AUTO_TEST_CASE(change_gear_from_neutral_to_first_or_back_return_true)
		{
			BOOST_CHECK(myCar.SetGear(States_Gearbox::back));
			myCar.SetGear(States_Gearbox::neutral);
			BOOST_CHECK(myCar.SetGear(States_Gearbox::first));
		}

		BOOST_AUTO_TEST_CASE(change_gear_from_neutral_to_second_return_false)
		{
			BOOST_CHECK(!myCar.SetGear(States_Gearbox::second));
		}

		BOOST_AUTO_TEST_CASE(start_movement_direction_must_be_staying)
		{
			BOOST_CHECK(myCar.GetMovementDirection() == Movement_Direction::Stopped);
		}
		
		BOOST_AUTO_TEST_CASE(when_gearbox_state_is_neutral_can_not_be_accelerated)
		{
			BOOST_CHECK(!myCar.SetSpeed(10));
		}
	BOOST_AUTO_TEST_SUITE_END();

	struct when_engine_turned_on_gearstate_is_first_ : TempCar
	{
		when_engine_turned_on_gearstate_is_first_()
		{
			myCar.TurnOnEngine();
			myCar.SetGear(States_Gearbox::first);
			myCar.SetSpeed(10);
		}

	};

	BOOST_FIXTURE_TEST_SUITE(when_engine_turned_on_gearstate_is_first, when_engine_turned_on_gearstate_is_first_);

	BOOST_AUTO_TEST_CASE(change_gearstate_on_speed_from_first_to_back_must_return_false)
	{
		BOOST_CHECK(!myCar.SetGear(States_Gearbox::back));
	}

	BOOST_AUTO_TEST_CASE(change_gearstate_on_speed_from_first_to_neutral_must_return_true)
	{
		BOOST_CHECK(myCar.SetGear(States_Gearbox::neutral));
	}

	BOOST_AUTO_TEST_CASE(change_gearstate_on_speed_from_first_to_second_on_low_speed_must_return_false)
	{
		BOOST_CHECK(!myCar.SetGear(States_Gearbox::second));
	}

	BOOST_AUTO_TEST_CASE(change_gearstate_on_speed_from_first_to_second_on_acceptable_speed_must_return_true)
	{
		myCar.SetSpeed(25);
		BOOST_CHECK(myCar.SetGear(States_Gearbox::second));
	}

	BOOST_AUTO_TEST_CASE(when_car_moved_and_gear_state_is_first_movement_direction_must_be_forward)
	{
		BOOST_CHECK(myCar.GetMovementDirection() == Movement_Direction::Forward);
	}

	BOOST_AUTO_TEST_CASE(when_car_was_moved_forward_with_speed_and_set_gear_on_neutral_movement_direction_must_be_forward)
	{
		myCar.SetSpeed(25);
		myCar.SetGear(States_Gearbox::neutral);
		BOOST_CHECK(myCar.GetMovementDirection() == Movement_Direction::Forward);
	}

	BOOST_AUTO_TEST_CASE(TurnOff_returned_false_while_car_moving)
	{
		BOOST_CHECK(!myCar.TurnOffEngine());
	}

	BOOST_AUTO_TEST_CASE(if_speed_is_zero_and_gear_state_is_first_can_change_gear_on_back)
	{
		myCar.SetSpeed(0);
		BOOST_CHECK(myCar.SetGear(States_Gearbox::back));
	}

	BOOST_AUTO_TEST_CASE(if_speed_is_not_zero_and_gear_state_is_neutral_car_can_set_lower_speed)
	{
		myCar.SetGear(States_Gearbox::neutral);
		BOOST_CHECK(myCar.SetSpeed(5));
	}
	BOOST_AUTO_TEST_SUITE_END();

	struct when_car_moving_back_ : TempCar
	{
		when_car_moving_back_()
		{
			myCar.TurnOnEngine();
			myCar.SetGear(States_Gearbox::back);
			myCar.SetSpeed(10);
		}

	};

	BOOST_FIXTURE_TEST_SUITE(when_car_moving_back, when_car_moving_back_);

		BOOST_AUTO_TEST_CASE(change_gearstate_from_back_to_first_must_return_false)
		{
			BOOST_CHECK(!myCar.SetGear(States_Gearbox::first));
		}

		BOOST_AUTO_TEST_CASE(change_gearstate_on_speed_from_first_to_neutral_must_return_true)
		{
			BOOST_CHECK(myCar.SetGear(States_Gearbox::neutral));
		}

		BOOST_AUTO_TEST_CASE(change_gearstate_to_second_must_return_false)
		{
			BOOST_CHECK(!myCar.SetGear(States_Gearbox::second));
		}

		BOOST_AUTO_TEST_CASE(change_gearstate_on_zero_speed_from_back_to_first_must_return_true)
		{
			myCar.SetSpeed(0);
			BOOST_CHECK(myCar.SetGear(States_Gearbox::first));
		}

		BOOST_AUTO_TEST_CASE(SetSpeed_more_than_max_in_range_must_return_false)
		{
			BOOST_CHECK(!myCar.SetSpeed(30));
		}

		BOOST_AUTO_TEST_CASE(can_not_TurnOff_engine_while_car_is_moving)
		{
			BOOST_CHECK(!myCar.TurnOffEngine());
		}

		BOOST_AUTO_TEST_CASE(when_car_is_moving_back_and_SetGear_neutral_movement_direction_musta_be_backward)
		{
			myCar.SetGear(States_Gearbox::neutral);
			BOOST_CHECK(myCar.GetMovementDirection() == Movement_Direction::Backward);
		}

		BOOST_AUTO_TEST_CASE(when_car_is_moving_back_and_SetGear_neutral_can_not_SetGear_first)
		{
			myCar.SetGear(States_Gearbox::neutral);
			BOOST_CHECK(!myCar.SetGear(States_Gearbox::first));
		}
	BOOST_AUTO_TEST_SUITE_END();

	struct turn_on_engine_to_check_speed_range_ : TempCar
	{
		turn_on_engine_to_check_speed_range_()
		{
			myCar.TurnOnEngine();
		}
	};

	BOOST_FIXTURE_TEST_SUITE(turn_on_engine_to_check_speed, turn_on_engine_to_check_speed_range_);

		struct first_gear_state_ : turn_on_engine_to_check_speed_range_
		{
			first_gear_state_()
			{
				myCar.SetGear(States_Gearbox::first);
			}
		};

		BOOST_FIXTURE_TEST_SUITE(first_gear_state, first_gear_state_);
		
			BOOST_AUTO_TEST_CASE(check_acceptable_speed)
			{
				for (int speed = 0; speed <= 30; ++speed)
					BOOST_CHECK(myCar.SetSpeed(speed));
			}

			BOOST_AUTO_TEST_CASE(check_unacceptable_speed)
			{
					BOOST_CHECK(!myCar.SetSpeed(31));
			}

		BOOST_AUTO_TEST_SUITE_END();

		struct second_gear_state_ : first_gear_state_
		{
			second_gear_state_()
			{
				myCar.SetSpeed(30);
				myCar.SetGear(States_Gearbox::second);

			}
		};

	BOOST_AUTO_TEST_SUITE_END();
BOOST_AUTO_TEST_SUITE_END();