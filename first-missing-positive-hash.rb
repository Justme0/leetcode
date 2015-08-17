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
	p nums
	place(nums)
	p nums
	first_missing_positive_aux(nums)
end

def test(a, result)
	fail unless first_missing_positive(a) == result
	p "ok"
end

test([2, 1], 3)
test([-1, -1], 1)
test([1, -1], 2)
test([1, 1], 2)
test([], 1)
test([1, 2, 0], 3)
test([3, 4, -1, 1], 2)
test([-3, -2, -1, 0, 1, 2, 3], 4)
