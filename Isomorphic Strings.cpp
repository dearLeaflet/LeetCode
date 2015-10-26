/*
@ brief : Given two strings s and t, determine if they are isomorphic.

Two strings are isomorphic if the characters in s can be replaced to get t.

All occurrences of a character must be replaced with another character

while preserving the order of characters. No two characters may map to

the same character but a character may map to itself.

For example,
Given "egg", "add", return true.

Given "foo", "bar", return false.

Given "paper", "title", return true.
*/
#include"lib.h"
using namespace std;
class Solution {
public:
	bool isIsomorphic(string s, string t) {
		if (s.size() != t.size()) return false;
		map<int, int> s1;
		for (size_t i = 0; i < s.size(); i++){
			if (s1.find(s[i]) == s1.end()){
				s1[s[i]] = t[i];
			}
			else{
				if (s1[s[i]] != t[i])
					return false;
			}
		}
		s1.clear();
		for (size_t i = 0; i < t.size(); i++){
			if (s1.find(t[i]) == s1.end()){
				s1[t[i]] = s[i];
			}
			else{
				if (s1[t[i]] != s[i])
					return false;
			}
		}
		return true;
	}
};