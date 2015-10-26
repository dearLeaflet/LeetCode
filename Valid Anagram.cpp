/*
判断连个字符串中的字符对应的字符在各自的串中次数是否相同

*/
#include <iostream>
#include <stack>
#include <string>
#include <sstream>
#include <deque>
#include <unordered_map>
using namespace std;
class Solution {
public:
	bool isAnagram(string s, string t) {
		if (s.size() != t.size()){
			return false;
		}

		unordered_map<int, int> uMapS;

		for (char letter : s){
			++uMapS[tolower(letter)];
		}

		for (char letter : t){
			if (uMapS[tolower(letter)] == 0){
				return false;
			}
			--uMapS[tolower(letter)];
		}

		return true;
	}
};