class String
	def palindrome?
		self == self.reverse
	end
end

# @param {String} s
# @return {String[][]}
def partition(s)
	return [[]] if s.nil? || s.empty?

	ret = []	# not [[]]
	(1..s.size).each do |i|
		front = s[0...i]
		back = s[i..-1]
		next unless front.palindrome?
		sub = partition(back)		# [[]]
		sub.each do |str_arr|
			str_arr.unshift(front)	# care order
		end
		ret += sub unless sub.empty?	# don't care order here
	end
	ret
end

require "test/unit"

class TestKitty < Test::Unit::TestCase
	def test_kitty
		assert_equal([[]], partition(""))
		assert_equal([["a"]], partition("a"))
		# assert_equal([["aa"], ["a", "a"]], partition("aa"))
		assert_equal([["a", "b"]], partition("ab"))
		# assert_equal([["aa","b"], ["a","a","b"]], partition("aab"))
	end
end
