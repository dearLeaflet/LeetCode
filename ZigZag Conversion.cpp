/*
@将Z字形字符串转成按行输出，将Z字形的字符，转成行优先的字符序列
*/

#include <string>
using namespace std;
class Solution {
public:
	string convert(string s, int numRows) {
		if (numRows == 1)	return s;
		string string_convert = s;
		int string_convert_count = 0;
		for (size_t i = 0; i < numRows; i++){
			int line_num = (2 * numRows - 2);
			for (size_t j = 0; j < s.size() / line_num + 1; j++){
				int x = j * line_num + i;
				if (x < s.size())
					string_convert.at(string_convert_count++) = s.at(x); //处理竖行
				if (i == 0 || i == numRows-1)	continue;
				int n = j * line_num + line_num - i;
				if (n < s.size()) 
					string_convert.at(string_convert_count++) = s.at(n);//处理斜行
			}
		}
		return string_convert;
	}
};