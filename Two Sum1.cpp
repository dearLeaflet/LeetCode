/*
给定有序的整数序列《vector》,给定一个数，求出那两个数之和==给定的那个数，并且，序列可能存在重复
*/
using namespace std;
#include <iostream>
#include <vector>
#include <unordered_map>
class Solution {
	//如果unordered_multimap，不同值对应的hash值相同，那么就会产生冲突，理论上应该在寻找到对应的木桶之后，在木桶中再继续找。
public:
	vector<int> twoSum(vector<int>& nums, int target) {
		unordered_multimap<int, int> v_copy;
		size_t nums_size = nums.size();
		for (size_t i = 0; i < nums_size; i++){
			v_copy.insert(make_pair((int)nums[i],i));//unordered_multimap元素为pair类型
		}
		for (size_t i = 0; i < nums_size; i++){
			int dist = target - nums[i];
			unordered_multimap<int, int>::iterator it_find = v_copy.find(dist); 
			//unordered_multimap中每个hash对应多个元素，多个元素构成一个链表，先加进来的元素在前面，
			//而leetcode先加进来的在后面。返回的为pair类型的迭代器（木桶，含有多个元素）
			if (it_find != v_copy.end()){
				vector<int> result;
				if (nums[i] == dist && v_copy.count(dist) > 1){//v_copy.count(dist) 返回的桶元素个数
					int count(0);//若是两个相同的数，则需要木桶中的元素个数大于1
					for (size_t i = 0; i < v_copy.count(dist); i++){
						if (it_find->first == dist){
							++count;
							result.push_back(it_find->second + 1);
							if (count >= 2){
								cout << result[0] << " " << result[1] << endl;
								return result;
							}
							++it_find;
						}
					}
				}
				else if (nums[i] != dist){
					result.push_back(i + 1);
					result.push_back((*it_find).second + 1); 
					cout << result[0] << " " << result[1] << endl;
					return result;
				}
			}
		}
		vector<int> result;
		return result;
	}
};
//int main()
//{
//	vector<int> v{ 0, 4, 3, 9 };
//	Solution s;
//	s.twoSum(v, 3);
//	return 0;
//}