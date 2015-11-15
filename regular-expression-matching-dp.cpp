#include <iostream>
#include <vector>
#include <cstring>
#include <cassert>

bool isMatch(const char *s, const char *p) {
	int m = strlen(s), n = strlen(p);
	std::vector<std::vector<bool>> dp(m+1, std::vector<bool>(n+1,false));
	dp[0][0] = true;
	for(int i=0; i<m; i++) {
		for(int j=1; j<n; j++) {
			if(p[j-1]==s[i-1] || p[j-1]=='?') 
				dp[i][j] = i>0 && dp[i-1][j-1];
			else if(p[j-1]=='*') 
				dp[i][j] = dp[i][j-1] || (i>0 && (dp[i-1][j-1] || dp[i-1][j]));
		}
	}
	return dp[m][n];
}

int main() {
	assert(!isMatch("aab", "c*a*b"));
	assert(!isMatch("aaabbbbaaaabbabbbbaabbabaaababaababaaaaaaabaaababbaababbaa"\
				"babbbaaaaabaabbabbaabaababbaabababbbbbbbbabbaabbaaabaababa"\
				"abaababababababbbbbbabbabbaabbaabaaaaaababaabbbaaabaaabbbb"\
				"bbbbbaabaabaaabaaabbabbabb",
				"****a*b*b**b*bbb*b**bba***b**b*b*b**ba***b*b*a*b*b*****a**"\
				"aaa*baaa*ba*****a****ba*a****a**b*******a*a"));
	assert(isMatch("ab", "?*"));

	return 0;
}
