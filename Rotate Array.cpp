/*
Rotate an array of n elements to the right by k steps.

For example, with n = 7 and k = 3, the array [1,2,3,4,5,6,7] is rotated to [5,6,7,1,2,3,4]


·­×ªÊý×é
*/
#include "lib.h"
using namespace std;
class Solution {
public:
	void rotate(vector<int>& nums, int k) {
		if (k == 0 || (k%=nums.size()) == nums.size()) return;
		k %= nums.size();
		reverse(nums.begin(), nums.end());
		reverse(nums.begin(), nums.begin() + k);
		reverse(nums.begin() + k, nums.end());
		
	}
};
