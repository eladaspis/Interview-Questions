#include <iostream>
#include <vector>
#include <algorithm>
#include <limits> 

using namespace std;
//Making Change
/*
Given an integer representing a given amount of change, write a
function to compute the total number of coins required to make
that amount of change. You can assume that there is always a
1¢ coin.
eg. (assuming American coins: 1, 5, 10, and 25 cents)
makeChange(1) = 1 (1)
makeChange(6) = 2 (5 + 1)
makeChange(49) = 7 (25 + 10 + 10 + 1 + 1 + 1 + 1)
*/

vector<int> coins{1,5,10,25};

// BruteForce Method
// Time Complexity: O(c^n) - where n is the number of different coins
// Space: O(1)

int makeChange(int c){
	if(c==0) return 0; // input checking
	int minCoin = numeric_limits<int>::max();
	for(int coin: coins){
		if(c-coin>=0){
			int ret = makeChange(c-coin);
			if(ret < minCoin){
				minCoin = ret;
			}
		}
	}
	return minCoin+1;
}
//DP - top down approach
int makeChange(int c, int cache[]){
	if(cache[c]>=0) return cache[c]; // input checking
	int minCoin = numeric_limits<int>::max();
	for(int coin: coins){
		if(c-coin>=0){
			int ret = makeChange(c-coin);
			if(ret < minCoin){
				minCoin = ret;
			}
		}
	}
	cache[c] = minCoin+1;
	return cache[c];
}
int makeChangeDpTd(int c){
	int* cache = new int[c+1];
	for (int i = 1; i < c+1; ++i)
	{
		cache[i] = -1;
	}
	makeChange(c,cache);
}
//DP - bottom up approach
int makeChangeDpBu(int c){
	int* cache = new int[c+1];
	for (int i = 0; i < c+1; ++i)
	{
		cache[i]=0;
	}
	for (int i = 1; i <= c; ++i)
	{
		int minCoin = numeric_limits<int>::max();
		for(int coin: coins){
			if(i-coin>=0){
				int ret = cache[i-coin]+1;
				if(ret < minCoin){
					minCoin = ret;
				}
			}
		}
		cache[i] = minCoin;
	}
	return cache[c];
}
int main(){
	cout << makeChange(22) << endl; 
	cout << makeChangeDpTd(23) << endl; 
	cout << makeChangeDpBu(24) << endl; 
}
