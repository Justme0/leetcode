=begin
Given two words word1 and word2, find the minimum number of steps required to
convert word1 to word2. (each operation is counted as 1 step.)

You have the following 3 operations permitted on a word:

a) Insert a character
b) Delete a character
c) Replace a character
=end

# @param {String} word1
# @param {String} word2
# @return {Integer}

def min_distance(word1, word2)
  fail if word1.nil? or word2.nil?

  return word2.size if word1 == ""
  return word1.size if word2 == ""
end

require 'test/unit'

class TestShit < Test::Unit::TestCase
  def test_shit
    assert_equal(0, min_distance("", ""))
    assert_equal(0, min_distance("a", "a"))
    assert_equal(1, min_distance("", "a"))
    assert_equal(1, min_distance("c", ""))
    assert_equal(1, min_distance("a", "b"))
    assert_equal(1, min_distance("aa", "a"))
    assert_equal(1, min_distance("a", "aa"))
    assert_equal(1, min_distance("a", "ba"))
    assert_equal(2, min_distance("", "ac"))
    assert_equal(2, min_distance("ac", ""))
  end
end
