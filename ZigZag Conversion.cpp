/*
@��Z�����ַ���ת�ɰ����������Z���ε��ַ���ת�������ȵ��ַ�����
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
					string_convert.at(string_convert_count++) = s.at(x); //��������
				if (i == 0 || i == numRows-1)	continue;
				int n = j * line_num + line_num - i;
				if (n < s.size()) 
					string_convert.at(string_convert_count++) = s.at(n);//����б��
			}
		}
		return string_convert;
	}
};