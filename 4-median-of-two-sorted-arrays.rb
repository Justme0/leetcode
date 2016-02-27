=begin
https://leetcode.com/problems/median-of-two-sorted-arrays/
There are two sorted arrays nums1 and nums2 of size m and n respectively. Find the median of the two sorted arrays. The overall run time complexity should be O(log (m+n)).
=end

# @param {Integer[]} nums1
# @param {Integer[]} nums2
# @return {Float}
def find_median_sorted_arrays_trivial(nums1, nums2)
  arr = (nums1 + nums2).sort
  if arr.size.odd?
    arr[(arr.size - 1) / 2]
  else
    (arr[arr.size / 2] + arr[arr.size / 2 - 1]) / 2.0
  end
end

# @param {Integer[]} nums1
# @param {Integer[]} nums2
# @return {Float}
def find_median_sorted_arrays(nums1, nums2)

end

require 'test/unit'

class TestHello < Test::Unit::TestCase
  def test_hello
    assert_equal(2, find_median_sorted_arrays([], [1, 2, 3]))
    assert_equal(2.5, find_median_sorted_arrays([], [2, 3]))
    assert_equal(1, find_median_sorted_arrays([], [1]))
    assert_equal(1, find_median_sorted_arrays([1], []))
    assert_equal(2, find_median_sorted_arrays([1, 2, 3], [1, 2, 3]))
    assert_equal(2.5, find_median_sorted_arrays([3, 4, 5], [0, 1, 2]))
    assert_equal(3, find_median_sorted_arrays([3, 4, 5], [1, 2]))
  end
end
