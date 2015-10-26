/*
Author: 
Data: 2015-08-02
Description: Given two integers representing the numerator and denominator of a fraction, return the fraction in string format.
	If the fractional part is repeating, enclose the repeating part in parentheses.

	���������ȥ��β��ѭ�����֣�����������
*/
#include <string>
#include <unordered_map>
#include <iostream>
using namespace std;
class Solution {
public:
	string fractionToDecimal(long long numerator, long long denominator) {
		string fractionStr; 
		long long integrater(0);  //��������
		if (numerator == 0) 
			return fractionStr.append("0");  //����Ϊ�㷵�� 0
		if (numerator < 0 ^ denominator < 0) 
			fractionStr.append("-");	//�жϽ���Ƿ��Ǹ���
		if (numerator < 0)
			numerator *= -1;
		if (denominator < 0)
			denominator *= -1;
		integrater = numerator / denominator;
		fractionStr.append(to_string(integrater));
		if (numerator % denominator == 0)
			return fractionStr;
		fractionStr.append(".");
		numerator = numerator % denominator;
		unordered_map<int, int> remainderMap;
		while (numerator != 0){
			if (remainderMap.count(numerator) > 0){
				fractionStr.insert(remainderMap[numerator],1,'(');
				fractionStr.append(")");
				return fractionStr;
			}
			remainderMap[numerator] = fractionStr.size();
			integrater = numerator * 10 / denominator;
			fractionStr.append(to_string(integrater));
			numerator = numerator * 10 % denominator;
			
		}
		return fractionStr;
	}
};
//int main()
//{
//	Solution s;
//	string str = s.fractionToDecimal(-1, 2147483648);
//	cout << str << endl;
//	return 0;
//}