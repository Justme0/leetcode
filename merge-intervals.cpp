#include <vector>
#include <algorithm>
#include <cassert>

struct Interval {
	int start;
	int end;
	Interval() : start(0), end(0) {}
	Interval(int s, int e) : start(s), end(e) {}
};

class Solution {
public:
	std::vector<Interval> merge(std::vector<Interval> &intervals) {
		if (intervals.empty()) {
			return std::vector<Interval>();
		}

		std::vector<Point> coordinates;
		for (const Interval &intv : intervals) {
			coordinates.push_back(Point(intv.start, true));
			coordinates.push_back(Point(intv.end, false));
		}
		std::sort(coordinates.begin(), coordinates.end());

		int depth = 0;	// 覆盖的深度
		assert(coordinates.front().isLeft);
		std::vector<Interval> merged_itvs;
		int start = 0;
		for (const Point &point : coordinates) {
			assert(depth >= 0);
			if (0 == depth) {
				start = point.x;	// 此时“栈空”，iter 指向左端点，开始合并一个区间
			}
			point.isLeft ? ++depth : --depth;
			if (0 == depth) {
				merged_itvs.push_back(Interval(start, point.x));	// 此时“栈空”，iter 指向右端点，确定了一个区间
			}
		}

		return merged_itvs;		// 接口设计得不好
	}

	struct Point {
		int x;
		bool isLeft;

		Point(int _x = 0, bool _isLeft = false) : x(_x), isLeft(_isLeft) {}

		bool operator<(const Point &other) const {
			if (x < other.x) {
				return true;
			} else if (x > other.x) {
				return false;
			} else if (isLeft == other.isLeft) {
				return false;
			} else {
				return isLeft;
			}
		}

		// bool operator<(const Point &other) const {
		// 	if (this->x < other.x) {
		// 		return true;
		// 	} else if (this->x > other.x) {
		// 		return false;
		// 	} else if (this->isLeft == other.isLeft) {
		// 		return this < &other;
		// 	} else {
		// 		return this->isLeft;
		// 	}
		// }
	};
};
