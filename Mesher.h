#include <CGAL/Exact_predicates_inexact_constructions_kernel.h>
#include <CGAL/partition_2.h>
#include <CGAL/Partition_traits_2.h>
#include <CGAL/Triangulation_2.h>

#include <vector>

class Mesher2d
{
    using K = CGAL::Exact_predicates_inexact_constructions_kernel;
	using Traits = CGAL::Partition_traits_2<K>;
	using Triangulation = CGAL::Triangulation_2<K>;
	using Polygon_2 = Traits::Polygon_2;
	using Point_2 = Traits::Point_2;
    
    public:
	    Mesher2d(const std::vector<Point_2>& points);

		std::vector<Triangulation> get_meshed_blocks() { return triangulations_; };

    private:
		std::vector<Triangulation> triangulations_;
};			