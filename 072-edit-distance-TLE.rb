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
  dp = Array.new(1005) { Array.new(1005) }
  len1 = word1.size
  len2 = word2.size

  (0..[len1, len2].max).each do |i|
    dp[0][i] = i
    dp[i][0] = i
  end

  (1..len1).each do |i|
    (1..len2).each do |j|
      dp[i][j] = [dp[i-1][j] + 1, dp[i][j-1] + 1,
                  dp[i-1][j-1] + (word1[i-1] == word2[j-1] ? 0 : 1)].min
    end
  end

  dp[len1][len2]
end

require 'test/unit'

class TestShit < Test::Unit::TestCase
  def test_shit
    assert_equal(0, min_distance("", ""))
    assert_equal(1, min_distance("a", "ac"))
    assert_equal(0, min_distance("a", "a"))
    assert_equal(1, min_distance("", "a"))
    assert_equal(1, min_distance("a", ""))
    assert_equal(1, min_distance("c", ""))
    assert_equal(1, min_distance("a", "b"))
    assert_equal(1, min_distance("aa", "a"))
    assert_equal(1, min_distance("aba", "aaa"))
    assert_equal(1, min_distance("aba", "acba"))
    assert_equal(2, min_distance("abbba", "acba"))
    assert_equal(2, min_distance("", "ac"))
    assert_equal(2, min_distance("ac", ""))
    assert_equal(3, min_distance("teacher", "poached"))
  end
end
