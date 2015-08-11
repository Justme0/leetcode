#include <iostream>
#include <vector>
#include <cassert>
#include <deque>

using std::cout;
using std::endl;

class Solution {
	public:
		std::vector<int> maxSlidingWindow(std::vector<int>& nums, int k) {
			if (nums.empty()) {
				return std::vector<int>();
			}

			std::deque<size_t> win = { 0 };
			for (size_t i = 1; i < (size_t)k; ++i) {
				while (!win.empty() && nums[i] >= nums[win.back()]) {
					win.pop_back();
				}
				win.push_back(i);
			}
			std::vector<int> result = {
				nums[win.front()]
			};

			for (size_t i = k; i < nums.size(); ++i) {
				while (i - win.front() >= (size_t)k) {
					win.pop_front();	// pop elements in front of the window
					if (win.empty()) {
						break;
					}
				}
				while (!win.empty() && nums[i] >= nums[win.back()]) {
					win.pop_back();
				}
				win.push_back(i);
				result.push_back(nums[win.front()]);
			}

			return result;
		}
};

void print(const std::vector<int> &v) {
	for (const int &e : v) {
		cout << e << ' ';
	}
	cout << endl;
}


int main(void)
{
	std::vector<int> nums = {
		1, -1
	};
	int k = 1;
	std::vector<int> result = {
		1, -1
	};
	std::vector<int> maxs = Solution().maxSlidingWindow(nums, k);
	print(maxs);

	assert(maxs == result);
	cout << "Good!" << endl;

	return 0;
}
