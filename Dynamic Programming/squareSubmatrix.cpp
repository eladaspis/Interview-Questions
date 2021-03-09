#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>
#include <math.h>
using namespace std;

//Square Submatrix
/*
Given a 2D boolean array, find the largest square subarray of
true values. The return value should be the side length of the
largest square subarray subarray.
*/

// Complexity Time: O(|col|*|rows|*3^(|depth|)) - BAD
// Space : O(|col|+|rows|)
int squareSubmatrixAux(bool** arr, int i, int j){
	if(!arr[i][j]) return 0;
	if(i==arr.length || j==arr[0].length) return 0;
	return 1 + Math.min(Math.min(squareSubmatrixAux(arr,i,j+1), squareSubmatrixAux(arr,i+1,j)),
		squareSubmatrixAux(arr,i+1,j+1));
}
int squareSubmatrix(bool** arr)
{
	int max = 0;
	for (int i = 0; i < arr.length; ++i)
	{
		for (int j = 0; j < arr[0].length; ++j)
		{
			if(arr[i][j]){
				max = max(max, squareSubmatrixAux(arr,i,j));
			}
		}
	}	
	return max;
}

// Dp - Top Down approach
int squareSubmatrixAuxDpTd(bool** arr, int i, int j, int** cache){
	if(!arr[i][j]) return 0;
	if(i==arr.length || j==arr[0].length) return 0;
	if(cache[i][j]>0) return cache[i][j];
	cache[i][j] = 1 + Math.min(Math.min(squareSubmatrixAux(arr,i,j+1), squareSubmatrixAux(arr,i+1,j)),
		squareSubmatrixAux(arr,i+1,j+1));
	return cache[i][j];
}
int squareSubmatrixDp(bool** arr)
{
	int max = 0;
	int** cache = new int[arr.length][arr[0].length];
	//reset array
	for (int i = 0; i < arr.length; ++i)
	{
		for (int i = 0; i < arr[0].length; ++i)
		{
			cache[i][j] = 0;
		}
	}
	for (int i = 0; i < arr.length; ++i)
	{
		for (int j = 0; j < arr[0].length; ++j)
		{
			if(arr[i][j]){
				max = max(max, squareSubmatrixAux(arr,i,j, cache));
			}
		}
	}	
	return max;
}
// Dp - Bottom up approach
int squareSubmatrixAuxDpTd(bool** arr, int i, int j, int** cache){
	if(!arr[i][j]) return 0;
	if(i==arr.length || j==arr[0].length) return 0;
	if(cache[i][j]>0) return cache[i][j];
	cache[i][j] = 1 + Math.min(Math.min(squareSubmatrixAux(arr,i,j+1), squareSubmatrixAux(arr,i+1,j)),
		squareSubmatrixAux(arr,i+1,j+1));
	return cache[i][j];
}
int squareSubmatrixDp(bool** arr)
{
	int max = 0;
	int** cache = new int[arr.length][arr[0].length];
	//reset array
	for (int i = 0; i < arr.length; ++i)
	{
		for (int i = 0; i < arr[0].length; ++i)
		{
			cache[i][j] = 0;
		}
	}
	for (int i = 0; i < arr.length; ++i)
	{
		for (int j = 0; j < arr[0].length; ++j)
		{
			if(i==0 || j==0){
				cache[i][j] = arr[i][j] ? 1:0;
			}
			else{
				cache[i][j] = 1 + Math.min(Math.min(cache[i][j-1], cache[i-1][j]), cache[i-1][j-1]);
			}
			if(cache[i][j] > max){
				max = cache[i][j];
			}
		}
	}	
	return max;
}

int main(){
	cout << minOperation(5) << endl; 
}