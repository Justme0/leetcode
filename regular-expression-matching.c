#include<stdbool.h>
#include<stdio.h>
#include<string.h>

bool isMatch(const char* s, const char* p){
	if(strlen(p)==0) return strlen(s)==0;
	if(strlen(p)==1){
		if(*p == '*' || (*p=='?'&&strlen(s)==1) ||p==s) return true;
		return false;
	}else{
		if(strlen(s)==0) return false;
		if(p[0]==s[0]||p[0]=='?')return isMatch(s+1,p+1);
		if(p[0]=='*'){
			for(size_t i=0;i<strlen(s);i++){
				if(isMatch(s+i,p+1))return true;
			}
		}
	}
	return false;
}

int main(){
	const char* s1="aa";
	const char* s2="aa";
	printf("%d\n", isMatch(s1,s2));
}
