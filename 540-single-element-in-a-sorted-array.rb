#!/usr/bin/env ruby

require 'test/unit'

# @param {Integer[]} nums
# @return {Integer}
def single_non_duplicate(nums)
  fail if nums.size.even?
  return nums.first if nums.size == 1

  left = 0
  right = nums.size
  until (n = (right - left - 1) / 2) == 0
    mid = (left + right) / 2
    print left, mid, right, "\n"
    if nums[mid] == nums[mid - 1]
      if n.even?
        right = mid - 1
      else
        left = mid + 1
      end
    elsif nums[mid] == nums[mid + 1]
      if n.even?
        left = mid + 2
      else
        right = mid
      end
    else
      return nums[mid]
    end
  end
  return nums[left]
end

class TestOliver < Test::Unit::TestCase
  def test_oliver
    assert_equal 0, single_non_duplicate([0])
    assert_equal 1, single_non_duplicate([0, 0, 1])
    assert_equal 0, single_non_duplicate([0, 1, 1])
    assert_equal 9, single_non_duplicate([1, 1, 2, 2, 4, 4, 5, 5, 9])
  end
end
