#include "lib.h"
using namespace std;
//The Skyline Problem
//���������ƽ��ͼ��������ߵ�����㣬�ұ߱�Ե�Ĺյ�
class Solution {
public:
	vector<pair<int, int>> getSkyline(vector<vector<int>>& buildings) {
		vector<pair<int, int>> height;//��¼ÿ���������
		for (vector<int> it : buildings){
			height.push_back({ it[0], -it[2] });
			height.push_back({ it[1], it[2] });
		}
		sort(height.begin(), height.end());
		int pre = 0, cur = 0;
		multiset<int> heightest;
		heightest.insert(0);
		vector<pair<int, int>> res;
		for (pair<int, int> it : height){
			if (it.second < 0){
				heightest.insert(-it.second);
			}
			else {
				heightest.erase(heightest.find(it.second));
			}
			cur = *heightest.rbegin();
			if (cur != pre){
				res.push_back({it.first, cur});
				pre = cur;
			}
				
		}
		return res;
	}
	
};
