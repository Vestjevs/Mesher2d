#include "Mesher.h"

#include <cassert>

Mesher2d::Mesher2d(const std::vector<Point_2>& points)
{
	size_t size = points.size();
	Polygon_2 polygon;
	polygon.reserve(size);

	for (const auto& pt: points)
		polygon.push_back(pt);

	std::vector<Polygon_2> partitionPolys;

	CGAL::approx_convex_partition_2(polygon.vertices_begin(),
		                            polygon.vertices_end(),
		                            std::back_inserter(partitionPolys));

	assert(CGAL::convex_partition_is_valid_2(polygon.vertices_begin(),
		                                     polygon.vertices_end(),
		                                     partitionPolys.begin(),
		                                     partitionPolys.end()));

	triangulations_.reserve(partitionPolys.size());

	for (const auto& poly : partitionPolys)
	{
		auto& container = poly.container();
		Triangulation triangulation;
		triangulation.insert(container.begin(), container.end());
		triangulations_.push_back(triangulation);
	}
}