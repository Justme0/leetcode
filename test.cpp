#include <iostream>
#include <set>

using std::cout;
using std::endl;

template <class T = float>
class GoodSet {
	private:
		std::multiset<float> s_;

	public:
		float max() {
			return *s_.rend();
		}

		float min() {
			return *s_.begin();
		}

		void insert(const float &x) {
			s_.insert(x);
		}

		float erase(const float &x) {
			s_.erase(s_.find(x));
		}

		float erase_all(const float &x) {
			s_.erase(x);
		}

		bool empty() const {
			return s_.empty();
		}

		size_t size() const {
			return s_.size();
		}
};

int main() {
	GoodSet<int> q;
	q.max();


	return 0;
}
