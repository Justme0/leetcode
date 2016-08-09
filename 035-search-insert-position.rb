=begin
Given a sorted array and a target value, return the index if the target is found. If not, return the index where it would be if it were inserted in order.

You may assume no duplicates in the array.

Here are few examples.
[1,3,5,6], 5 → 2
[1,3,5,6], 2 → 1
[1,3,5,6], 7 → 4
[1,3,5,6], 0 → 0
=end

# @param {Integer[]} nums
# @param {Integer} target
# @return {Integer}
def search_insert(nums, target)
  low = 0
  high = nums.size
  until high - low <= 1
    mid = low + (high - low) / 2
    if nums[mid] == target
      return mid
    elsif nums[mid] < target
      low = mid + 1
    else
      high = mid
      fail unless high >= 0
    end
  end
  if high == low
    low
  else
    target > nums[low] ? high : low
  end
end

require 'test/unit'

class TestA < Test::Unit::TestCase
  def test_a
    assert_equal(0, search_insert([], 5))
    assert_equal(1, search_insert([1, 3], 2))
    assert_equal(2, search_insert([1,3,5,6], 5))
    assert_equal(1, search_insert([1,3,5,6], 2))
    assert_equal(4, search_insert([1,3,5,6], 7))
    assert_equal(0, search_insert([1,3,5,6], 0))
  end
end
