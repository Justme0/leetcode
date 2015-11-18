$result = {} # cache

def is_match_dfs(s, p)
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
			return $result[[s, p]] = true if is_match_dfs(s[i..-1], p[1..-1])
		end
		return $result[[s, p]] = false
	else
		if p[0] == "?" or s[0] == p[0]
			return $result[[s, p]] = is_match_dfs(s[1..-1], p[1..-1])
		else
			return $result[[s, p]] = false
		end
	end
end

# @param {String} s
# @param {String} p
# @return {Boolean}
def is_match(s, p)
	# some optimization
	return false if p.delete("*").size > s.size
	return false if p[-1] != "*" && p[-1] != "?" && p[-1] != s[-1]
	p = p.split("").chunk{|str| str == "*"}.map{|is_star, arr| is_star ? "*" : arr}.join
	is_match_dfs(s, p)
end

require "test/unit"

class TestShit < Test::Unit::TestCase
	def test_shit
		assert !is_match("b", "*a*")
		assert is_match("aab", "a*a*b")
		assert is_match("aa","a**a")
		assert !is_match("aa","a*a**a")
		assert !is_match("aa","a**a**a")
		assert !is_match("", "a")
		assert !is_match("a","aa")
		assert !is_match("aa","a")
		assert is_match("aa","aa")
		assert !is_match("aaa","aa")
		assert is_match("aa", "*")
		assert is_match("aa", "a*")
		assert is_match("ab", "?*")
		assert !is_match("aab", "c*a*b")
		assert !is_match("bbaaaabaaaaabbabbabbabbababaabababaabbabaaabba"\
				 "ababababbabaa"\
				 "bbabbbbbbaaaaaabaabbbbbabbbbabbabababaaaaa",
				 "******aa*bbb*aa*a*bb*ab***bbba*a*babaab*b*aa*a"\
				 "****")
		assert is_match("abbaaaabbbbbababbbbbbbbaaabaabbabaabbaaabbbbab"\
				"bbbab",
				"a*aaba***b**a*a********b")
		assert !is_match("aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa"\
				 "aaaaaaaaaaaaa"\
				 "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa"\
				 "aa",
				 "*aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa"\
				 "aaaaaaaaaaaaa"\
				 "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa"\
				 "aaaa*")
		assert !is_match("aaabbbbaaaabbabbbbaabbabaaababaababaaaaaaabaa"\
				 "ababbaababbaa"\
				 "babbbaaaaabaabbabbaabaababbaabababbbbbbbbabba"\
				 "abbaaabaababa"\
				 "abaababababababbbbbbabbabbaabbaabaaaaaababaab"\
				 "bbaaabaaabbbb"\
				 "bbbbbaabaabaaabaaabbabbabb",
				 "****a*b*b**b*bbb*b**bba***b**b*b*b**ba***b*b*"\
				 "a*b*b*****a**"\
				 "aaa*baaa*ba*****a****ba*a****a**b*******a*a")
		assert !is_match("bbbabaaabaababbbbabbbbababbbabbbbaaabaaaabaaa"\
				 "baabbbaabbbba"\
				 "ababbbabbbbabbbbbbabbbbaabababaaaaabbaaabbaaa"\
				 "baababaaabaab"\
				 "baabbabbaababaabaabaaabaababbaaabaaabbbbaabba"\
				 "baaabbabaaabb"\
				 "babaaaaaababaababbbbabbbaab",
				 "****aab**ba***bb***a*a*bab***b***ab*a*b*a***a"\
				 "******a*bb**a"\
				 "**bbaa*ba*abba*******************************"\
				 "**********b*aaba****a*b*****ba**abba")
	end
end
