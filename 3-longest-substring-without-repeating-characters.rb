=begin
https://leetcode.com/problems/longest-substring-without-repeating-characters/

Given a string, find the length of the longest substring without repeating characters. For example, the longest substring without repeating letters for "abcabcbb" is "abc", which the length is 3. For "bbbbb" the longest substring is "b", with the length of 1.
=end

require 'test/unit'
require 'set'

# @param {String} s
# @return {Integer}
def length_of_longest_substring(s)
  first = 0
  last = 0
  max_len = 0
  sub = {} # char => index
  s.split(//).each_with_index do |c, last|
    if sub.include?(c)
      c_index = sub[c] # c is the repeated char
      (first..c_index).each do |i|
        sub.delete(s[i])
      end
      first = c_index + 1
      sub[c] = last
    else
      sub[c] = last
      max_len = sub.size if sub.size > max_len
    end
  end
  max_len
end

class TestHello < Test::Unit::TestCase
  def test_hello
    assert_equal(0, length_of_longest_substring(""))
    assert_equal(3, length_of_longest_substring("abcabcbb"))
    assert_equal(1, length_of_longest_substring("bbbb"))
    assert_equal(1, length_of_longest_substring("a"))
    assert_equal(2, length_of_longest_substring("aabb"))
    assert_equal(4, length_of_longest_substring("abcd"))
    assert_equal(2, length_of_longest_substring("aaad"))
  end
end
