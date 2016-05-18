#include "stdafx.h"
#include "../Shape2/App.h"

struct application
{
	CApp myApp;
};

BOOST_FIXTURE_TEST_SUITE(testing_appliication, application);

BOOST_AUTO_TEST_CASE(can_add_point)
{
	myApp.AddShape("Point 1 2");
	BOOST_CHECK_EQUAL(myApp.GetShapesCount(), 1);
}

BOOST_AUTO_TEST_CASE(can_add_line)
{
	myApp.AddShape("Line 1 2 1 3");
	BOOST_CHECK_EQUAL(myApp.GetShapesCount(), 1);
}

BOOST_AUTO_TEST_CASE(can_add_circle)
{
	myApp.AddShape("Circle 3 3 3");
	BOOST_CHECK_EQUAL(myApp.GetShapesCount(), 1);
}

BOOST_AUTO_TEST_CASE(can_add_rectangle)
{
	myApp.AddShape("Rectangle 3 3 3 3");
	BOOST_CHECK_EQUAL(myApp.GetShapesCount(), 1);
}

BOOST_AUTO_TEST_CASE(can_add_triangle)
{
	myApp.AddShape("Triangle 3 3 4 3 5 5");
	BOOST_CHECK_EQUAL(myApp.GetShapesCount(), 1);
}
BOOST_AUTO_TEST_SUITE_END();
