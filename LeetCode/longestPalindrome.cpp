#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int longestPalindrome(string s){
	int dp[s.size()][s.size()];
	for(int i = 0; i < s.size();i++){
		for(int j = 0; j <s.size(); j++){
			if(i==j){
				dp[i][j]=1;
			}
			else{
				dp[i][j]=0;
			}
		}
	}
	for(int diagonal = 2; diagonal <= s.size(); diagonal++){
		for(int i = 0; i < s.size()-diagonal+1; i++){
			int j = i+diagonal-1;
			if(s[i]==s[j]){
				if(diagonal == 2){
					dp[i][j] = 2;
				}
				else{
					dp[i][j] = dp[i+1][j-1]+2;
				}
			}
			else{
				dp[i][j] = max(dp[i+1][j],dp[i][j-1]);
			}
		}
	}
	return dp[0][s.size()-1];
}
int main(){
	string s="abaaaa";
	cout << longestPalindrome(s) << endl;
}
