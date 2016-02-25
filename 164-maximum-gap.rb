# TODO: time complexity
def maximum_gap(nums)
	return 0 if nums.length <= 1
	nums.sort!.each_cons(2).map{|a, b| b - a}.max
end
