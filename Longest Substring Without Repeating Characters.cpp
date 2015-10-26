/*
查找最大子串（子串为元素不重复的子串）
*/

#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
class Solution {
public:
	int lengthOfLongestSubstring(string s) {
		if (s.size() == 0){
			return 0;
		}
		SubString sub_string;
		//当末尾字符没有在所查找范围类重复字符出现时，则直接跳出，最大子串非全局最大子串。
		while (string_high < s.size()){
			//cout << string_low << " " << string_high << endl;
			string::iterator it = find(s.begin() + string_low, s.begin() + string_high, s.at(string_high));
			if (it == (s.begin() + string_high)){
				++string_high;
			}
			else{
				int ssize = string_high - string_low;
				if (ssize > sub_string.size){
					sub_string.size = ssize;
					sub_string.begin = string_low;
					sub_string.end = string_high -1;
				}
				string_low = it - s.begin()+1;
				++string_high;
			}
		}
		string::iterator it = find(s.begin() + string_low, s.end(), s.at(string_high- 1));
		if (it == s.end()){
			int ssize = string_high - string_low;
			if (ssize > sub_string.size){
				sub_string.size = ssize;
				sub_string.begin = string_low;
				sub_string.end = string_high-1;
			}
		}
		//判断末尾字符串是否较长
		return sub_string.size > string_high - string_low ? sub_string.size : string_high - string_low;
	}
private:
	struct SubString{
		int begin = 0;
		int end = 0;
		size_t size = 0;
	};
	int string_low = 0;
	int string_high = 1;
};