# void
def place(nums)
	nums.each_with_index do |x, i|
		while x.between?(1, nums.size) and x != i + 1 and nums[i] != nums[x - 1]
			nums[i], nums[x - 1] = nums[x - 1], nums[i]
			x = nums[i]	# NOTE
		end
	end
end

# Integer
def first_missing_positive_aux(arr)
	arr.each_with_index do |x, i|
		if x != i + 1
			return i + 1
		end
	end
	arr.size + 1
end

# @param {Integer[]} nums
# @return {Integer}
def first_missing_positive(nums)
	place(nums)
	first_missing_positive_aux(nums)
end

require "test/unit"

class TestKitty < Test::Unit::TestCase
	def test_kitty
		assert_equal(3, first_missing_positive([2, 1]))
		assert_equal(1, first_missing_positive([-1, -1]))
		assert_equal(2, first_missing_positive([1, -1]))
		assert_equal(2, first_missing_positive([1, 1]))
		assert_equal(1, first_missing_positive([]))
		assert_equal(3, first_missing_positive([1, 2, 0]))
		assert_equal(2, first_missing_positive([3, 4, -1, 1]))
		assert_equal(4, first_missing_positive([-3, -2, -1, 0, 1, 2, 3]))
	end
end
