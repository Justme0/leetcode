def is_match(s, p)
	i = 0
	j = 0
	star = -1
	mark = -1
	while i < s.length
		if j < p.length && (p[j] == '?' || p[j] == s[i])
			i += 1
			j += 1
		elsif j < p.length && p[j] == '*'
			star = j
			j += 1
			mark = i
			# 这一步是关键，匹配s中当前字符与p中‘＊’后面的字符，如果匹配，则在第一个if中处理，如果不匹配，则继续比较s中的下一个字符。
		elsif star != -1
			j = star + 1
			mark += 1
			i = mark
		else
			return false
		end
	end
	# 最后在此处处理多余的‘＊’，因为多个‘＊’和一个‘＊’意义相同。
	while j < p.length && p[j] == '*'
		j += 1
	end
	j == p.length
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
				 "**bbaa*ba*abba*****b*aaba****a*b*****ba**abba")
	end
end
