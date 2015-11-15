# s and p both are char
def match?(s, p)
	fail unless s.size == 1 && p.size == 1
	return p == "?" || p == s
end

$result = {} # cache

def is_match_clean(s, p)
	result = $result[[s, p]]
	return result if !result.nil?

	fail if s.nil? || p.nil?
	return $result[[s, p]] = s.empty? if p.empty?
	if s.empty?
		return $result[[s, p]] = true if p == "*"
		return $result[[s, p]] = false if p[0] != "*"
	end

	if p[0] == "*"
		(0..s.size).each do |i|
			return $result[[s, p]] = true if is_match(s[i..-1], p[1..-1])
		end
		return $result[[s, p]] = false
	else
		if match?(s[0], p[0])
			return $result[[s, p]] = is_match(s[1..-1], p[1..-1])
		else
			return $result[[s, p]] = false
		end
	end
end

# @param {String} s
# @param {String} p
# @return {Boolean}
def is_match(s, p)
	p = p.split("").chunk{|str| str == "*"}.map(&:first).join
	puts p
	is_match_clean(s, p)
end

require "test/unit"

class TestShit < Test::Unit::TestCase
	def test_shit
		assert !is_match("", "a")
		assert !is_match("a","aa")
		assert !is_match("aa","a")
		assert is_match("aa","aa")
		assert !is_match("aaa","aa")
		assert is_match("aa", "*")
		assert is_match("aa", "a*")
		assert is_match("ab", "?*")
		assert !is_match("aab", "c*a*b")
	end
end
