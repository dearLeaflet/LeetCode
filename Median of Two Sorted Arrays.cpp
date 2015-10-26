/*
在两个有序的序列中，查找中值
*/

#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class Solution {
public:
	double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2){
		int size1 = nums1.size();
		int size2 = nums2.size();
		if ((size1 + size2) & 0x01){
			return findKTh(nums1.begin(), size1, nums2.begin(), size2, (size1 + size2) / 2 + 1);
		}
		else{
			return findKTh(nums1.begin(), size1, nums2.begin(), size2, (size1 + size2) / 2) / 2
				+ findKTh(nums1.begin(), size1, nums2.begin(), size2, (size1 + size2) / 2 + 1) / 2;
		}
	}
private:
	double findKTh(vector<int>::iterator numIt1,size_t size1, vector<int>::iterator numIt2, size_t size2, int k){
		if (size1 > size2)
			return findKTh(numIt2, size2, numIt1, size1, k);
		if (size1 == 0)
			return numIt2[k - 1];
		if (k <= 1)
			return min(numIt1[0], numIt2[0]);
		int pa = min(k / 2, (int)size1), pb = k - pa;
		if (numIt1[pa - 1] > numIt2[pb - 1])
			return findKTh(numIt1, size1, numIt2 + pb, size2 - pb, k - pb);
		if (numIt1[pa - 1] < numIt2[pb - 1])
			return findKTh(numIt1 + pa, size1 - pa, numIt2, size2, k - pa);
		if (numIt1[pa - 1] == numIt2[pb - 1])
			return numIt1[pa - 1];
	}
};
//int main()
//{
//	Solution s;
//	vector<int> v1{ 1, 2 }, v2{ 1, 2 };
//	cout << s.findMedianSortedArrays(v1, v2);
//	return 0;
//
//}