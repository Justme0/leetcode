=begin
https://leetcode.com/problems/median-of-two-sorted-arrays/
There are two sorted arrays nums1 and nums2 of size m and n respectively. Find the median of the two sorted arrays. The overall run time complexity should be O(log (m+n)).
=end

# @param {Integer[]} nums1
# @param {Integer[]} nums2
# @return {Float}
def find_median_sorted_arrays_trivial(nums1, nums2)
  (nums1 + nums2).sort.median
end

# from https://github.com/acearth/LeetCodePractice/blob/master/find_median_sorted_arrays.rb
def find_median_sorted_arrays_acearth(a,b)
  len=a.size+b.size
  return find_kth(a,b,len/2+1) if len.odd?
  (find_kth(a,b,len/2)+find_kth(a,b,len/2+1))*0.5
end
## k>0
def find_kth(a,b,k)
  return find_kth(b,a,k) if a.size<b.size  #ensure a.size >= b.size
  return a[k-1] if b.size==0
  return a[0]>b[0] ? b[0] : a[0] if k==1
  lenb=[b.size,k/2].min
  lena=k-lenb
  return find_kth(a[lena..-1],b,k-lena) if a[lena-1]<b[lenb-1]
  find_kth(a,b[lenb..-1],k-lenb)
end

class Array
  # @return {Float}
  def median
    if self.size.odd?
      self[median_index]
    else
      (self[median_index] + self[median_index + 1]) / 2.0
    end
  end

  # if the size is even, return the down median index
  def median_index
    (self.size + 1) / 2 - 1
  end

  def down_half
    self[0..median_index]
  end

  def up_half
    self[median_index + (self.size.even? ? 1 : 0)..-1]
  end
end

# k is 0-based
def find_kth_sorted_arrays(nums1, nums2, k)
  puts "nums1 is #{nums1}, nums2 is #{nums2}, k is #{k}"
  fail if nums1.empty? and nums2.empty?
  return nums2[k] if nums1.empty?
  return nums1[k] if nums2.empty?
  s1 = nums1.size
  s2 = nums2.size
  m1 = nums1.median
  m2 = nums2.median
  if k == 0
    return [nums1.first, nums2.first].min
  end
  if s2 == 1
    if s1 - 1 < k
      return [nums1.last, nums2.last].max
    end
    candidate = nums1[k]
    if candidate <= nums2.first
      return candidate
    else
      return [nums1[k - 1], nums2.first].max
    end
  end
  if s1 == 1
    return find_kth_sorted_arrays(nums2, nums1, k)
  end

  return m1 if m1 == m2
  if m1 > m2
    if (1 + k) <= (1 + s1) / 2 + (1 + s2) / 2
      return find_kth_sorted_arrays(nums1.down_half, nums2, k)
    else
      return find_kth_sorted_arrays(nums1, nums2.up_half, k - s2 / 2)
    end
  else
    return find_kth_sorted_arrays(nums2, nums1, k)
  end
end

# @param {Integer[]} nums1
# @param {Integer[]} nums2
# @return {Float}
def find_median_sorted_arrays(nums1, nums2)
  total_size = nums1.size + nums2.size
  down_median_index = (total_size + 1) / 2 - 1
  total_size.odd? ? find_kth_sorted_arrays(nums1, nums2, down_median_index) : (find_kth_sorted_arrays(nums1, nums2, down_median_index) + find_kth_sorted_arrays(nums1, nums2, down_median_index + 1)) / 2.0
end

# @param {Integer[]} nums1
# @param {Integer[]} nums2
# @return {Float}
# TODO:
def find_median_sorted_arrays_med(nums1, nums2)
  puts "nums1 is #{nums1}, nums2 is #{nums2}"
  return nums2.median if nums1.empty?
  return nums1.median if nums2.empty?
  s1 = nums1.size
  s2 = nums2.size
  m1 = nums1.median
  m2 = nums2.median
  return m1 if m1 == m2
  if s2 == 1
    return (nums1 + nums2).sort.median if s1 <= 3
    if s1.even?
      if nums2.first < nums1[nums1.median_index]
        return nums1[nums1.median_index]
      elsif nums2.first > nums1[1+nums1.median_index]
        return nums1[1+nums1.median_index]
      else
        return nums2.first
      end
    else
      other = nil
      left = nums1[nums1.median_index - 1]
      right = nums1[nums1.median_index + 1]
      if m2 < m1
        other = [left, m2].max
      else
        other = [right, m2].min
      end
      return (m1 + other) / 2.0
    end
  end
  return find_median_sorted_arrays(nums2, nums1) if s1 == 1

  return find_median_sorted_arrays(nums2, nums1) if s1 < s2
  if m1 > m2
    return find_median_sorted_arrays(nums1[0..-1-s2/2], nums2.up_half)
  else
    return find_median_sorted_arrays(nums1[s2/2..-1], nums2.down_half)
  end
end

require 'test/unit'

class TestHello < Test::Unit::TestCase
  def test_hello
    assert_equal(3.5, find_median_sorted_arrays([1,2,6], [3,4,5]))
    assert_equal(0.5, find_median_sorted_arrays([0], [1]))
    assert_equal(0.5, find_median_sorted_arrays([1], [0]))
    assert_equal(100, find_kth_sorted_arrays([1, 100], [10], 2))
    assert_equal(100, find_kth_sorted_arrays([1, 100], [10], 2))
    assert_equal(1, find_median_sorted_arrays([1], [1]))
    assert_equal(100, find_kth_sorted_arrays([1, 2, 3, 100, 101], [1], 4))
    assert_equal(100, find_kth_sorted_arrays([1, 2, 3, 100, 101], [3], 4))
    assert_equal(101, find_kth_sorted_arrays([1, 2, 3, 100, 102], [101], 4))
    assert_equal(100, find_median_sorted_arrays([1, 2], [1, 2, 3, 100, 101, 102, 103, 104, 105]))
    assert_equal(2, find_kth_sorted_arrays([1, 2, 3], [1, 2, 3], 2))
    assert_equal(2, find_kth_sorted_arrays([1, 2, 3], [0], 2))
    assert_equal(1, find_kth_sorted_arrays([], [1], 0))
    assert_equal(1.5, find_median_sorted_arrays([1, 2, 3], [0]))
    assert_equal(1.5, find_median_sorted_arrays([0], [1, 2, 3]))
    assert_equal([2], [1, 2].up_half)
    assert_equal([1], [1, 2].down_half)
    assert_equal([2], [2].down_half)
    assert_equal(2, find_median_sorted_arrays([], [1, 2, 3]))
    assert_equal(2.5, find_median_sorted_arrays([], [2, 3]))
    assert_equal(1, find_median_sorted_arrays([], [1]))
    assert_equal(1, find_median_sorted_arrays([1], []))
    assert_equal(100000.5, find_median_sorted_arrays([100000], [100001]))
    assert_equal(100000.5, find_median_sorted_arrays([100001], [100000]))
    assert_equal(1.5, find_median_sorted_arrays([0, 1], [2, 3]))
    assert_equal(2, find_median_sorted_arrays([1, 2, 3], [1, 2, 3]))
    assert_equal(2.5, find_median_sorted_arrays([3, 4, 5], [0, 1, 2]))
    assert_equal(3, find_median_sorted_arrays([3, 4, 5], [1, 2]))
  end
end
