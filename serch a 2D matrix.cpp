/*
ÿ��ÿ���е�Ԫ���������������Ѱ��ĳ�����Ƿ����
*/
#include <vector>
using namespace std;
class Solution {
public:
	bool searchMatrix(vector<vector<int>>& matrix, int target) {
		for (size_t i = 0; i < matrix[0].size(); i++){
			int mid;
			int r_low = 0;
			int r_high = matrix.size() - 1;
			while (r_low <= r_high){
				mid = (r_low + r_high) / 2;
				if (matrix[mid][i] > target){ //��ÿһ�����ö��ֲ���
					r_high = mid - 1;
					continue;
				}
				if (target == matrix[mid][i]){
					return true;
				}
				else{
					r_low = mid + 1;
				}
			}
		}
		return false;
	}
};