#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
using namespace std;
class Solution {
public:
	//数组有序
	vector<int> twoSum(vector<int>& nums, int target) {
		for (size_t i = 0; i < nums.size();){
			//vector<int>::iterator locate_max = find_if(nums.begin() + i, nums.end(), bind1st(mem_fun(&Solution::find_max_min), this));
			int xx = target - nums[i];
			vector<int>::iterator locate_max = find_if(nums.begin() + i, nums.end(), [xx](int x){return xx > x ? false : true; });//使用lambda表达式，xx为变量
			while (true){
				if (nums[i] + *locate_max == target){
					return_v.push_back(i);
					return_v.push_back(locate_max - nums.begin());
					cout << "index1 = " << i << ", index2 = " << locate_max - nums.begin() << endl;
					return return_v;
				}
				int temp = *(locate_max - 1);
				if (nums[i] + temp == target){
					return_v.push_back(i);
					return_v.push_back(locate_max  - nums.begin()- 1);
					cout << "index1 = " << i << ", index2 = " << locate_max - nums.begin() -1 << endl;
					return return_v;
				}
				else if (nums[i] + temp < target){
					i++;
					break;
				}
				else{
					--locate_max;
				}
			}
		}
	}


private:
	size_t num_num;
	vector<int> return_v;
};