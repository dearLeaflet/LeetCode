#include <vector>
#include <iostream>
using namespace std;
class Solution {
public:
	vector<vector<int>> combinationSum3(int k, int n) {
		int index = 1, sum = 0;
		vector<int> temp;
		vector<vector<int>> ret;
		DFS(index, n, k, temp, ret, sum);
		return ret;
	}
private:
	bool DFS(int index, int n, int cnt, vector<int> &temp, vector<vector<int>> &ret, int sum){
		if (temp.size() == cnt && sum == n){
			ret.push_back(temp);
			return true;
		}
		if (temp.size() > cnt || sum > n){
			return false;
		}
		if (temp.size() == cnt && sum > n){
			return false;
		}
		for (int i = index; i <= 9; i++){
			temp.push_back(i);
			DFS(i + 1, n, cnt, temp, ret, sum);
			temp.pop_back();
		}
		return true;
	}

};
