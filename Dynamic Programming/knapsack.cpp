#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;
//0-1 Knapsack
/*
Given a list of items with values and weights, as well as a max
weight, find the maximum value you can generate from items,
where the sum of the weights is less than or equal to the max.
eg.
items = {(w:2, v:6), (w:2, v:10), (w:3, v:12)}
max weight = 5
knapsack(items, max weight) = 22
*/
class Item {
 int weight;
 int value;
}
unordered_map<int, int>
//Brute-Force
//Complexity Time: O(2^n)
int knapsack(Item* items, int maxWeight) {
 return knapsack(items, maxWeight, 0);
}
int knapsack(Item* items, int weight, int index)
{	
	int sum = 0;
	if(index == items.length|| weight<0){
		return 0;
	}
	if(weight-items[index].weight<0){
		return knapsack(items,weight,index+1);
	}
	return Math.Max(items[index].weight + knapsack(items, weight-items[index], index+1), knapsack(items, weight, index+1))
}

//Dp - Top down approach

int knapsackDpTd(Item* items, int weight, unordered_map<int, unordered_map<int,int>> umap, int index) {
	if(index == items.length) return 0;
	if(umap.find(index)==umap.end()){
		umap.insert(index,unordered_map<int,int>);		
	}
	int ret=0;
	if(weight-Items[index].weight<0){
		ret = knapsackDp(items, weight,umap,index+1);
	}
	else{
		ret = Math.max(items[i].value + knapsackDp(items,weight-items[i].weight, i+1, cache),
			knapsackDp(items,weight,i+1,cache));
	}
	umap.find(index).insert(w,ret);
	return ret;
}
int knapsackDpTd(Item* items, int maxWeight) {
	unordered_map<int, unordered_map<int, int>> umap;
	return knapsackDpTd(items, maxWeight, umap, 0);
}

//Dp - bottom-up approach
int knapsackDpBu(Item* items, int weight) {
	int** cache = new int[items.length+1][weight+1];
	for(int i=1; i<=items.length; i++){
		for(int j=0; j<weight;j++){
			if(items[i-1] > j){
				cache[i][j] = cache[i-1][j];
			}
			else{
				cache[i][j] = Math.max(cache[i][j], cache[i-1][j-items[i-1].weight]+items[i-1].value);
			}
		}
	}
	return cache[items.length][weight];
}

int main(){
	cout << minOperation(5) << endl; 
}