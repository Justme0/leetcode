# s and p both are char
def match?(s, p)
	fail unless s.size == 1 && p.size == 1
	return p == "." || p == s
end

$result = {}

# @param {String} s
# @param {String} p
# @return {Boolean}
def is_match(s, p)
	if !$result[[s, p]].nil?
		return $result[[s, p]]
	end

	fail if s.nil? || p.nil?
	return s.empty? if p.empty?
	return p.empty? || (p.size == 2 && p[1] == "*") if s.empty?

	if p[1] == "*"
		return true if is_match(s, p[2..-1])
		index = 0
		while index < s.size && match?(s[index], p[0])
			return true if is_match(s[(index + 1)..-1], p[2..-1])
			index += 1
		end
		return false
	else
		if match?(s[0], p[0])
			return is_match(s[1..-1], p[1..-1])
		else
			return false
		end
	end
end

require "test/unit"

class TestShit < Test::Unit::TestCase
	def test_shit
		assert !is_match("aaaaab", "a*c")
		assert !is_match("ab", ".*c")
		assert is_match("","")
		assert is_match("a","a")
		assert is_match("a",".")
		assert !is_match("aa","a")
		assert is_match("aa","aa")
		assert !is_match("aaa","aa")
		assert is_match("","a*")
		assert is_match("a","a*")
		assert is_match("aa", "a*")
		assert is_match("", "a*")
		assert is_match("aaa", "a*")
		assert !is_match("abb", "a*ab")
		assert is_match("abb", "a*.b")
		assert !is_match("abb", "a*b")
		assert is_match("aa", ".*")
		assert is_match("aaa", ".*")
		assert is_match("ab", ".*")
		assert is_match("aab", "c*a*b")
	end
end
