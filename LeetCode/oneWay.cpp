//
// Created by Elad on 16/08/2020.
//
#include <iostream>
#include <string>
#include "math.h"

using namespace std;

/**
 *
 * Problem: One Away: There are three types of edits that can be performed on
 * strings: insert a character, remove a character, or replace a character.
 * Given two strings, write a function to check if they are one edit (or zero
 * edits) away.
 *
 * Solution:
 */
bool oneWay(const string &a, const string &b) {
    int tmp = a.length() - b.length();
    if (abs(tmp) > 1) return false;
    bool check = false;
    if (a.length() == b.length()) {
        for (int i = 0; i < a.length(); ++i) {
            if (a.at(i) != b.at(i) && !check) {
                check = true;
            } else if (a.at(i) != b.at(i) && check) {
                return false;
            }
        }
        return true;
    }
    check = false;
    int index = 0;
    for (int j = 0; j < (a.length() > b.length() ? b.length() : a.length()); ++j) {
        if (a.at(j) == b.at(j)) continue;
        if (a.at(j) != b.at(j)) {
            index = j;
            for (int i = index; i < (a.length() > b.length() ? b.length() : a.length()); ++i) {
                if (a.length() > b.length()) {
                    if (a.at(i + 1) != b.at(i)) {
                        return false;
                    }
                } else {
                    if (a.at(i) != b.at(i + 1)) {
                        return false;
                    }
                }
            }
            return true;
        }
    }
    return true;
}
int main() {
   std::cout << oneWay("pale","bale") << std::endl;
   return 0;
}
