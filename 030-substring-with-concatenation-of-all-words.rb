=begin
You are given a string, s, and a list of words, words, that are all of the same
length. Find all starting indices of substring(s) in s that is a concatenation
of each word in words exactly once and without any intervening characters.

For example, given:
s: "barfoothefoobarman"
words: ["foo", "bar"]

You should return the indices: [0,9].
(order does not matter).
=end

require 'set'
require 'test/unit'

# @param {String} s
# @param {String[]} words
# @return {Integer[]}
def find_substring(s, words)
  return [] if words.empty?
  ret = []
  len = words[0].length
  s.length.times do |i|
    set = words.to_set
    j = i
    while !set.empty?
      word = s[j, len]
      if set.delete?(word)
        if set.empty?
          ret << i
          next
        end
        j += len
      else
        # words have no substring
        i += 1
      end
    end
  end
  ret
end

class TestK < Test::Unit::TestCase
  def test_k
    assert_equal([0], find_substring("dd", ["dd"]))
    assert_equal([], find_substring("dd", ["ddddd"]))
    assert_equal([0, 9], find_substring("barfoothefoobarman", ["foo", "bar"]))
  end
end
