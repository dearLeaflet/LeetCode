/*
����������������С�vector��,����һ�����������������֮��==�������Ǹ��������ң����п��ܴ����ظ�
*/
using namespace std;
#include <iostream>
#include <vector>
#include <unordered_map>
class Solution {
	//���unordered_multimap����ֵͬ��Ӧ��hashֵ��ͬ����ô�ͻ������ͻ��������Ӧ����Ѱ�ҵ���Ӧ��ľͰ֮����ľͰ���ټ����ҡ�
public:
	vector<int> twoSum(vector<int>& nums, int target) {
		unordered_multimap<int, int> v_copy;
		size_t nums_size = nums.size();
		for (size_t i = 0; i < nums_size; i++){
			v_copy.insert(make_pair((int)nums[i],i));//unordered_multimapԪ��Ϊpair����
		}
		for (size_t i = 0; i < nums_size; i++){
			int dist = target - nums[i];
			unordered_multimap<int, int>::iterator it_find = v_copy.find(dist); 
			//unordered_multimap��ÿ��hash��Ӧ���Ԫ�أ����Ԫ�ع���һ�������ȼӽ�����Ԫ����ǰ�棬
			//��leetcode�ȼӽ������ں��档���ص�Ϊpair���͵ĵ�������ľͰ�����ж��Ԫ�أ�
			if (it_find != v_copy.end()){
				vector<int> result;
				if (nums[i] == dist && v_copy.count(dist) > 1){//v_copy.count(dist) ���ص�ͰԪ�ظ���
					int count(0);//����������ͬ����������ҪľͰ�е�Ԫ�ظ�������1
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