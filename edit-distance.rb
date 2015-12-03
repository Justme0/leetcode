# @param {String} word1
# @param {String} word2
# @return {Integer}
def min_distance(word1, word2)

end

require 'test/unit'

class TestShit < Test::Unit::TestCase
	def test_shit
		assert_equal(0, min_distance("", ""))
		assert_equal(0, min_distance("a", "a"))
		assert_equal(1, min_distance("a", "b"))
		assert_equal(1, min_distance("aa", "a"))
		assert_equal(1, min_distance("a", "aa"))
		assert_equal(1, min_distance("a", "ba"))
		assert_equal(2, min_distance("", "ac"))
		assert_equal(2, min_distance("ac", ""))
	end
end
