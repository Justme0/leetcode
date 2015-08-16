# @param {Integer[]} nums
# @return {Integer}
def first_missing_positive(nums)
	nums = nums.sort.uniq
	first_positive_index = nums.find_index { |x|
		x >= 1
	}
	return 1 if first_positive_index.nil?
	first_positive = nums[first_positive_index]
	return 1 if first_positive >= 2
	diff = first_positive - first_positive_index
	fail unless first_positive == 1
	i = first_positive_index + 1
	while i != nums.size
		fail unless 0 <= i and i < nums.size
		diff2 = nums[i] - i
		fail unless diff2 >= diff
		return nums[i - 1] + 1 if diff2 > diff
		i += 1
	end
	nums.last + 1
end

def test(nums, result)
	p nums
	p result
	if result != first_missing_positive(nums)
		fail
	end
end

test([1, 1], 2)
puts "ok"
