def place(nums)
	nums.each_with_index { |x, i|
		while x.between?(1, nums.size) and x != i + 1
			nums[i], nums[x - 1] = nums[x - 1], nums[i]
		end
	}
end

def first_missing_positive_aux(nums)

end

# @param {Integer[]} nums
# @return {Integer}
def first_missing_positive(nums)
	place(nums)
	puts "after place, nums is #{nums}"
	first_missing_positive_aux(nums)
end

p first_missing_positive([2, 1])
