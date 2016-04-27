#include "stdafx.h"
#include "../Shape/Shape.h"

struct point_test
{
	point_test()
	{
		point = std::make_unique<CPoint>(10, 20, "#FFAACC");
	}

	std::unique_ptr<CPoint> point;
};

BOOST_FIXTURE_TEST_SUITE(test_point_class, point_test);

	BOOST_AUTO_TEST_CASE(points_area_must_be_zero)
	{
		BOOST_CHECK_EQUAL(point->GetArea(), 0);
	}

	BOOST_AUTO_TEST_CASE(points_perimetr_must_be_zero)
	{
		BOOST_CHECK_EQUAL(point->GetPerimetr(), 0);
	}

	BOOST_AUTO_TEST_CASE(point_position_must_be_equal_with_given)
	{
		auto pos = point->GetPosition();
		BOOST_CHECK_EQUAL(pos.first, 10);
		BOOST_CHECK_EQUAL(pos.second, 20);
	}

	BOOST_AUTO_TEST_CASE(point_color_must_be_equal_with_given)
	{
		auto color = point->GetColor();
		BOOST_CHECK(color == std::string("#FFAACC"));
	}

BOOST_AUTO_TEST_SUITE_END();

struct line_segment_test
{
	line_segment_test()
	{
		lineSegment = std::make_unique<CLineSegment>(std::make_pair(10, 20 ), std::make_pair( 20, 20), "#FFAACC");
	}

	std::unique_ptr<CLineSegment> lineSegment;
};

BOOST_FIXTURE_TEST_SUITE(test_line_segment_class, line_segment_test);

BOOST_AUTO_TEST_CASE(line_segments_area_must_be_zero)
{
	BOOST_CHECK_EQUAL(lineSegment->GetArea(), 0);
}

BOOST_AUTO_TEST_CASE(line_segments_perimetr_must_be_equal_distans_between_points)
{
	BOOST_CHECK_EQUAL(lineSegment->GetPerimetr(), 10);
}

BOOST_AUTO_TEST_CASE(line_segment_color_must_be_equal_with_given)
{
	auto color = lineSegment->GetColor();
	BOOST_CHECK(color == std::string("#FFAACC"));
}
BOOST_AUTO_TEST_SUITE_END();
