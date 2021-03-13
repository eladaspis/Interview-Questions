#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;


//Word Count Engine

/*
Implement a document scanning function wordCountEngine, which receives a string document and returns a list of all unique words in it and their number of occurrences, sorted by the number of occurrences in a descending order. If two or more words have the same count, they should be sorted according to their order in the original sentence. Assume that all letters are in english alphabet. You function should be case-insensitive, 
so for instance, the words “Perfect” and “perfect” should be considered the same word.
The engine should strip out punctuation (even in the middle of a word) and use whitespaces to separate words.
Analyze the time and space complexities of your solution. Try to optimize for time while keeping a polynomial space complexity.

Examples:
input:  document = "Practice makes perfect. you'll only
                    get Perfect by practice. just practice!"
output: [ ["practice", "3"], ["perfect", "2"],
          ["makes", "1"], ["youll", "1"], ["only", "1"], 
          ["get", "1"], ["by", "1"], ["just", "1"] ]
Important: please convert the occurrence integers in the output list to strings (e.g. "3" instead of 3).
We ask this because in compiled languages such as C#, Java, C++, C etc., it’s not straightforward to create mixed-type arrays (as it is, for instance, in scripted languages like JavaScript, Python, Ruby etc.). The expected output will simply be an array of string arrays.
Constraints:
[time limit] 5000ms
[input] string document
[output] array.array.string
*/
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <queue>
#include <utility> 

using namespace std;
struct greaters
{
   bool operator()(const pair<string, int> & s1, const pair<string, int> & s2)
   {
       return s1.second < s2.second;
   }
};
vector<vector<string>> wordCountEngine( const string& document ) 
{
  string tmp = "";
  map<string, int> my_map;
  bool to_write = false;
  vector<pair<string,int>> ret_vec;
  vector<vector<string>> ret;
  for(int i=0; i<document.size(); i++){
    if(document[i]!=' '){
      if(tolower(document[i])<='z' && tolower(document[i])>='a'){
        tmp += tolower(document[i]);
      }
      to_write=true;
    }
    else{
      if(to_write){  
        if(my_map.find(tmp)==my_map.end()){ //the key not found
          my_map.insert(make_pair(tmp,1));
        }
        else{ //the key found - the word
          int current_occurence = my_map.find(tmp)->second;
          my_map.erase(tmp);
          my_map.insert(make_pair(tmp,current_occurence+1));
        }
        tmp = "";
          to_write=false;
      }
    }
  }
  if(my_map.find(tmp)==my_map.end()){ //the key not found
        my_map.insert(make_pair(tmp,1));
  }
  else{ //the key found - the word
    int current_occurence = my_map.find(tmp)->second;
    my_map.erase(tmp);
    my_map.insert(make_pair(tmp,current_occurence+1));
  }
  vector<pair<string,int>> t;
  for(auto i = my_map.begin(); i != my_map.end(); i++){
    ret_vec.push_back(make_pair(i->first,i->second));
  }
  make_heap(ret_vec.begin(), ret_vec.end(),greaters());
  while(!ret_vec.empty()){
    pair<string,int> tmp_pair = ret_vec.front();
    vector<string> a = {tmp_pair.first, to_string(tmp_pair.second)};
    ret.push_back(a);
    pop_heap(ret_vec.begin(),ret_vec.end());
    ret_vec.pop_back();
  }
  return ret;
}

// iterate each word and insert it to hashmap
// At the final, I'll iterate each element and create that list

//Time Complexity -O(n)
//Space Complexity - O(n)

int main() {
  return 0;
}
// iterate each word and insert it to hashmap
// At the final, I'll iterate each element and create that list

//Time Complexity -O(n)
//Space Complexity - O(n)

int main() {
  return 0;
}
