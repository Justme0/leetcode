#include <iostream>
#include <cassert>
#include <vector>
#include <set>

using std::cout;
using std::endl;

template <class T>
class GoodSet {
	private:
		std::multiset<T> s_;

	public:
		const T & max() const {
			return *s_.rbegin();
		}

		const T & min() const {
			return *s_.begin();
		}

		void push(const T &x) {
			s_.insert(x);
		}

		/*
		 * pop only one element which "equal"s to x
		 */
		void pop(const T &x) {
			s_.erase(s_.find(x));
		}

		/*
		 * returns the number of elements erased
		 */
		size_t pop_all(const T &x) {
			return s_.erase(x);
		}

		T pop_max() {
			T m = this->max();
			// rend() return `reverse_iterator`
			// while erase() here should accept `iterator`
			s_.erase(--(s_.end()));	// HACK

			return m;
		}

		T pop_min() {
			T m = this->min();
			s_.erase(s_.begin());

			return m;
		}

		bool empty() const {
			return s_.empty();
		}

		size_t size() const {
			return s_.size();
		}
};

class Solution {
	public:
		std::vector<int> maxSlidingWindow(std::vector<int>& nums, int k) {
			if (nums.empty()) {
				return nums;
			}

			GoodSet<int> s;
			for (int i = 0; i < k; ++i) {
				s.push(nums[i]);
			}
			std::vector<int> result;
			result.push_back(s.max());
			s.pop(nums[0]);

			// window is [pos, pos+k-1]
			for (int pos = 1; pos <= static_cast<int>(nums.size()) - k; ++pos) {
				s.push(nums[pos + k - 1]);
				result.push_back(s.max());
				s.pop(nums[pos]);
			}
			assert(result.size() == nums.size() - k + 1);

			return result;
		}
};

int main() {
	std::vector<int> nums = {
		1
	};
	int k = 1;
	std::vector<int> result = {
		1
	};
	assert(Solution().maxSlidingWindow(nums, k) == result);

	return 0;
}
