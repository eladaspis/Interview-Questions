#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;
//3Sum
//Given an array nums of n integers, are there elements a, b, c in nums such that a + b + c = 0? Find all unique triplets in the array which gives the sum of zero.
//Notice that the solution set must not contain duplicate triplets.

//Sol 1
// Time Complexity : O(n^3)
vector<vector<int>> threeSumBruteForce(vector<int>& nums) {
        vector<vector<int>> v;
	    for (int i = 0; i < nums.size(); ++i)
	    {
			for (int j = 0; j < nums.size(); ++j)
			{
					for (int k = 0; k < nums.size(); ++k)
					{
						if (i==j || j==k || k==i) continue;
						if (nums.at(i)+nums.at(j)+nums.at(k)==0){
							std::vector<int> tmp;
							tmp.push_back(nums.at(i));
							tmp.push_back(nums.at(j));
							tmp.push_back(nums.at(k));
                            sort(tmp.begin(), tmp.end());
                            vector<vector<int>>::iterator it = std::find(v.begin(), v.end(), tmp);
                            if(it==v.end()){
                                v.push_back(tmp);
                            }
						}
					}	
			}
	    }
	    return v;
}
// Time Complexity : O((n^2))
vector<vector<int>> threeSum(vector<int>& nums) {
    unordered_map<int, int> umap;
    vector<vector<int>> ret_vec;
    int cnt=0;
    for(auto num: nums){
        umap.insert(make_pair(cnt, nums[cnt]));
        cnt++;
    }
	for (auto it = umap.begin(); it != umap.end(); it++){
		for (auto it2 = umap.begin(); it2 != umap.end(); it2++){
			if (it!=it2){
				std::unordered_map<int, int>::iterator got = umap.find((-1)*(it->second + it2->second));
				if(got != umap.end() && got != it && got != it2){
					vector<int> v;
					v.push_back(it->second);
					v.push_back(it2->second);
					v.push_back((-1)*(it->second + it2->second));
					sort(v.begin(), v.end());
					if(std::find(ret_vec.begin(), ret_vec.end(), v) == ret_vec.end())
					{
					  ret_vec.push_back(v);
					} 
				}
			}
		}
	}
	return ret_vec;
}

int main(){
	std::vector<int> v;
	v.push_back(0);
	v.push_back(-58);
	v.push_back(-2);
	v.push_back(60);
	vector<vector<int>> vec = threeSum(v);
	for(auto tmp : vec){
		for(auto num: tmp){
			cout << num << endl;
		}
	}

}