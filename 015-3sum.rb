=begin
Given an array S of n integers, are there elements a, b, c in S such that a + b + c = 0? Find all unique triplets in the array which gives the sum of zero.

Note:
Elements in a triplet (a,b,c) must be in non-descending order. (ie, a ≤ b ≤ c)
The solution set must not contain duplicate triplets.
For example, given array S = {-1 0 1 2 -1 -4},

A solution set is:
(-1, 0, 1)
(-1, -1, 2)
=end

require 'test/unit'

# @param {Integer[]} nums
# @return {Integer[][]}
def three_sum(nums)
  return [] if nums.size < 3
  ret = []
  nums.sort!
  h = Hash[nums.zip (0...nums.size)] # HACK. e.g. [-2, 1, 1] was hashed to [-2 => 0, 1 => 2], the index will be used in "h[c] > j"
  nums.each_with_index do |a, i|
    break if a > 0
    next if i >= 1 and a == nums[i-1]
    (i+1...nums.size).each do |j|
      b = nums[j]
      next if j >= i + 2 and b == nums[j-1]
      c = - a - b
      if h.include?(c) and h[c] > j
        ret << [a, b, c]
      end
    end
  end
  ret
end

class TestHello < Test::Unit::TestCase
  def test_hello
    assert_equal([[-1, -1, 2], [-1, 0, 1]], three_sum([-1, 0, 1, 2, -1, -4]))
    assert_equal([[-2, 1, 1]], three_sum([-2, 1, 1]))
    assert_equal([[0, 0, 0]], three_sum([0, 0, 0]))
    assert_equal([[0, 0, 0]], three_sum([0,0,0,0]))
    assert_equal([[-2, 0, 2]], three_sum([-4, -4, -3, -2, -1, 0, 2]))
  end
end
