#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>

using namespace std;


//Reverse Words in a String 

/*
Given an input string s, reverse the order of the words.
A word is defined as a sequence of non-space characters. The words in s will be separated by at least one space.
Return a string of the words in reverse order concatenated by a single space.
Note that s may contain leading or trailing spaces or multiple spaces between two words. The returned string should only have a single space separating the words. Do not include any extra spaces.



Example 1:

Input: s = "the sky is blue"
Output: "blue is sky the"
Example 2:

Input: s = "  hello world  "
Output: "world hello"
Explanation: Your reversed string should not contain leading or trailing spaces.
Example 3:

Input: s = "a good   example"
Output: "example good a"
Explanation: You need to reduce multiple spaces between two words to a single space in the reversed string.
Example 4:

Input: s = "  Bob    Loves  Alice   "
Output: "Alice Loves Bob"
Example 5:

Input: s = "Alice does not even like bob"
Output: "bob like even not does Alice"
 

Constraints:

1 <= s.length <= 104
s contains English letters (upper-case and lower-case), digits, and spaces ' '.
There is at least one word in s.
 
Follow up: Could you solve it in-place with O(1) extra space?
*/
// space : O(|s|)
string reverseWords(string s) {
	stack<string> ret_stack;
	string tmp_str = "";
	bool first = false;
	for(char& c : s){
		if(c!= ' '){
			tmp_str += c;
		}
		else{
			ret_stack.push(tmp_str);
			tmp_str = "";
		}
	}
	ret_stack.push(tmp_str);
	tmp_str = "";
	while(!ret_stack.empty()){
		tmp_str += ret_stack.top();
		ret_stack.pop();
		if(!ret_stack.empty()){
			tmp_str += " ";
		}
	}
	return tmp_str;
}

//space: O(1)
string reverseWordsImproved(string s) {
	string tmp_str = "";
        string str = "";
        bool first = true;
        bool first_space = false;
        for(char& c : s){
            if(c!= ' '){
                tmp_str += c;
                first_space = true;
            }
            else{
            	if(first_space){
            		if(first){
	                    str = tmp_str;
	                    tmp_str = "";
	                    first=false;
	                }
	                else{
	                    str = tmp_str + " " + str;
	                    tmp_str = "";
	                }	
	                first_space = false;
            	}
            }
        }
        if(s[s.length()-1] != ' '){
        	if(str==""){
        		str = tmp_str;	
        	}
        	else{
        		str = tmp_str + " " + str;	
        	}
        }
        return str;
}
int main(){
	cout << reverseWordsImproved("Alice does not even like bob") << endl;
	cout << reverseWordsImproved("   hello world  ") << endl;
	cout << reverseWordsImproved("abcLL") << endl;

}