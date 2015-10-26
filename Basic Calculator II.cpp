/*

@2015/08/14

Implement a basic calculator to evaluate a simple expression string.

The expression string contains only non-negative integers, +, -, *, / operators and empty spaces . The integer division should truncate toward zero.

You may assume that the given expression is always valid.

Some examples:
"3+2*2" = 7
" 3/2 " = 1
" 3+5 / 2 " = 5

*/
#include"lib.h"
using namespace std;
class Solution {
public:
	int calculate(string s) {
		if (s.size() == 0) return 0;
		bool flage = true;
		int sum = 0;
		for (size_t i = 0; i < s.size(); i++){
			if (s[i] == ' ') continue;
			if (s[i] == '*' || s[i] == '/' || s[i] == '+' || s[i] == '-'){
				numbers.push_back(sum);
				sum = 0;
				operaterChar.push_back(s[i]);
				continue;
			}
			sum = sum * 10 + int(s[i] - '0');
		}
		numbers.push_back(sum);
		if (numbers.size() == 1)
		{
			return numbers.front();
		}
		sum = 0;
		while (operaterChar.size() > 0){
			int x, y;
			char op = operaterChar.front();
			operaterChar.pop_front();
			switch (op){
			case '-': 
				numbers1.push_back(numbers.front());
				numbers.pop_front();
				operaterChar1.push_back(op);
				break;
			case '+':
				numbers1.push_back(numbers.front());
				numbers.pop_front();
				operaterChar1.push_back(op);
				break;
			case '*':
				numbers1.push_back(numbers.front());
				numbers.pop_front();
				x = numbers.front();
				y = numbers1.back(); //队列的数加上队列1的数，结果重新加入队列
				numbers1.pop_back();
				numbers.pop_front();
				numbers.push_front(x * y);
				
				break;
			case '/':
				numbers1.push_back(numbers.front());
				numbers.pop_front();
				x = numbers1.back();
				y = numbers.front();
				numbers1.pop_back();
				numbers.pop_front();
				numbers.push_front(x / y);
				break;
			}

		}
		numbers1.push_back(numbers.front());
		sum = numbers1.front();
		numbers1.pop_front();
		while (!operaterChar1.empty()){
			char op = operaterChar1.front();
			operaterChar1.pop_front();
			switch (op){
			case '+': sum += numbers1.front();
				numbers1.pop_front();
				break;
			case '-': sum -= numbers1.front();
				numbers1.pop_front();
				break;
			default:
				break;
			}
		}
		return sum;
	}
private:
	deque<char> operaterChar;
	deque<int> numbers;
	deque<char> operaterChar1;
	deque<int> numbers1;
	int twoCalculate(int x, int y, char op){
	}
};