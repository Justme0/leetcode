class String
	def palindrome?
		letters == letters.reverse
	end
end

# @param {String} s
# @return {String[][]}
def partition(s)
	return [[]] if s.nil? || s.empty?

	ret = [[]]
	(1..(str.size - 1)).each do |i|
		sub = partition(s[i..-1])
	end
end

require "test/unit"

class TestKitty < Test::Unit::TestCase
	def test_kitty
		assert_equal([[]], partition(""))
		assert_equal([["a"]], partition("a"))
		assert_equal([["a", "a"], ["aa"]], partition("aa"))
		assert_equal([["a", "b"]], partition("ab"))
		assert_equal([["aa","b"], ["a","a","b"]], partition("aab"))
	end
end
