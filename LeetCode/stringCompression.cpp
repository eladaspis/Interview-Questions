//
// Created by Elad on 17/08/2020.
//

#include <iostream>
#include <string>
#include "math.h"

using namespace std;

/**
 *
 * Problem: Implement a method to perform basic string compression using the
 * counts of repeated characters.
 *
 * For example, the string aabcccccaaa would become a2b1c5a3. If the
 * "compressed" string would not become smaller than the original string, your
 * method should return the original string. You can assume the string has only
 * uppercase and lowercase letters (a - z)
 *
 */

string stringCompression(const string &str) {
    string tmp;
    int count = 1;
    for (int i = 0; i < str.length() - 1; ++i) {
        if (str.at(i) == str.at(i + 1)) {
            count++;
        } else {
            tmp += str.at(i);
            tmp += to_string(count);
            count = 1;
        }
    }
    tmp += str.at(str.length() - 1);
    tmp += to_string(count);
    return tmp.length() < str.length() ? tmp : str;
}
int main() {
   std::cout << stringCompression("aaabbbccccdd") << std::endl;
   return 0;
}
