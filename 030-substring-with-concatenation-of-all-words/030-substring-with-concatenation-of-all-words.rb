=begin
https://leetcode.com/problems/substring-with-concatenation-of-all-words/

You are given a string, s, and a list of words, words, that are all of the same
length. Find all starting indices of substring(s) in s that is a concatenation
of each word in words exactly once and without any intervening characters.

For example, given:
s: "barfoothefoobarman"
words: ["foo", "bar"]

You should return the indices: [0,9].
(order does not matter).
=end

def find_from(s, start, hash, words_size)
  ret = []
  word_len = hash.keys.first.length
  succ = false
  i = start
  j = start
  word2cnt = nil
  last = s.size - words_size * word_len + 1
  while i < last
    if succ # last check is successful
      remain_num = 1
      word2cnt[s[i-word_len...i]] += 1
    else
      remain_num = words_size
      word2cnt = hash.clone
    end

    fail unless i <= j

    until remain_num == 0
      word = s[j, word_len]
      if word2cnt[word] == 0
        break
      else
        word2cnt[word] -= 1
        remain_num -= 1
        j += word_len
      end
    end
    if remain_num == 0
      ret << i
      succ = true
      fail unless j - i == word_len * words_size
      i += word_len
    else
      succ = false
      i += word_len
      j = i
    end
  end
  ret
end

# @param {String} s
# @param {String[]} words
# @return {Integer[]}
def find_substring(s, words)
  return [] if words.empty?

  hash = words.each_with_object(Hash.new(0)) do |elem, mome|
    mome[elem] += 1
  end
  ret = []
  words.first.length.times do |index|
    ret += find_from(s, index, hash, words.size)
  end
  ret
end

# @param {String} s
# @param {String[]} words
# @return {Integer[]}
def find_substring_slow(s, words)
  return [] if words.empty?
  ret = []
  len = words.first.length
  hash = words.each_with_object(Hash.new(0)) do |elem, mome|
    mome[elem] += 1
  end
  (s.size - words.size * len + 1).times do |i|
    cnt = words.size
    word_cnt = hash.clone
    j = i
    until cnt == 0
      word = s[j, len]
      if word_cnt[word] == 0
        # don't match
        break
      else
        word_cnt[word] -= 1
        cnt -= 1
        j += len
      end
    end
    ret << i if cnt == 0
  end
  ret
end

require 'test/unit'

class TestHello < Test::Unit::TestCase
  def test_hello
    assert_equal([0, 1], find_substring("dd", ["d"]))
    assert_equal([], find_substring("dd", ["ddddd"]))
    assert_equal([0], find_substring("dd", ["dd"]))
    assert_equal([0, 1, 2], find_substring("aaaa", ["aa"]).sort)
    assert_equal([0, 9], find_substring("barfoothefoobarman", ["foo", "bar"]))
    assert_equal([6], find_substring("barfoofoobarthe", ["bar","foo","the"]))
    assert_equal([7], find_substring("xbarfoofoobarthe", ["bar","foo","the"]))
    assert_equal([8], find_substring("wordgoodgoodgoodbestword", ["word","good","best","good"]))
    assert_equal([6, 9, 12], find_substring("barfoofoobarthefoobarman", ["bar","foo","the"]))

    assert_equal([0, 1], find_substring_slow("dd", ["d"]))
    assert_equal([], find_substring_slow("dd", ["ddddd"]))
    assert_equal([0], find_substring_slow("dd", ["dd"]))
    assert_equal([0, 1, 2], find_substring_slow("aaaa", ["aa"]).sort)
    assert_equal([0, 9], find_substring_slow("barfoothefoobarman", ["foo", "bar"]))
    assert_equal([6], find_substring_slow("barfoofoobarthe", ["bar","foo","the"]))
    assert_equal([7], find_substring_slow("xbarfoofoobarthe", ["bar","foo","the"]))
    assert_equal([8], find_substring_slow("wordgoodgoodgoodbestword", ["word","good","best","good"]))
    assert_equal([6, 9, 12], find_substring_slow("barfoofoobarthefoobarman", ["bar","foo","the"]))
  end
end
