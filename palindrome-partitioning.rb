require 'set'

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

require 'test/unit'

module Test::Unit::Assertions
	def assert_equal_unorder(exp, act, msg = nil)
		# msg = message(msg) {}
		assert_equal(exp.to_set, act.to_set, msg)
	end
end

class TestKitty < Test::Unit::TestCase
	def test_kitty
		assert_equal_unorder([[]], partition(""))
		assert_equal_unorder([["a"]], partition("a"))
		assert_equal_unorder([["aa"], ["a", "a"]], partition("aa"))
		assert_equal_unorder([["a", "a"], ["aa"]], partition("aa"))
		assert_equal_unorder([["a", "b"]], partition("ab"))
		assert_equal_unorder([["aa","b"], ["a","a","b"]], partition("aab"))
	end
end
