/*
@ brief : Find the kth largest element in an unsorted array.
Note that it is the kth largest element in the sorted order, not the kth distinct element.
*/
#include"lib.h"
using namespace std;
class Solution {
public:
	int findKthLargest(vector<int>& nums, int k) {
		int L = 0, R = nums.size() - 1;
		while (L < R){
			int left = L, right = R;
			int key = nums[left];

			while (left < right){
				while (left < right && key > nums[right]){
					--right;
				}
				nums[left] = nums[right];

				while (left < right && key <= nums[left]){
					++left;
				}
				nums[right] = nums[left];
			}
			nums[left] = key;
			if (left == k - 1){
				return nums[k - 1];
			}
			if (left < k - 1){
				L = left + 1;
			}
			else{
				R = left - 1;
			}
		}
		return nums[k - 1];
	}
};

//int main()
//{
//	Solution s;
//	vector<int> v{1};
//	cout << s.findKthLargest(v, 1) << endl;;
//	return 0;
//}