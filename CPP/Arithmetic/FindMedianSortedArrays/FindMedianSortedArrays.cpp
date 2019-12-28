// FindMedianSortedArrays.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;





double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
	int m = nums1.size(), n = nums2.size();
	// 保证 m <= n
	if (m > n) return findMedianSortedArrays(nums2, nums1);
	// Ci 为第i个数组的割，比如C1为2时表示第1个数组只有2个元素。
	// Lmaxi为第i个数组割后的左元素。
	// Rmini为第i个数组割后的右元素。

	// 我们目前是虚拟加了‘#’所以数组1是2*n长度
	int Lmax1, Lmax2, Rmin1, Rmin2, c1, c2, lo = 0, hi = 2 * m;

	while (lo <= hi)
	{
		// c1 是二分的结果
		c1 = (lo + hi) / 2;
		c2 = m + n - c1;

		Lmax1 = (c1 == 0) ? INT_MIN : nums1[(c1 - 1) / 2];
		Rmin1 = (c1 == 2 * m) ? INT_MAX : nums1[c1 / 2];
		Lmax2 = (c2 == 0) ? INT_MIN : nums2[(c2 - 1) / 2];
		Rmin2 = (c2 == 2 * n) ? INT_MAX : nums2[c2 / 2];

		if (Lmax1 > Rmin2) hi = c1 - 1;
		else if (Lmax2 > Rmin1) lo = c1 + 1;
		else break;
	}
	return (max(Lmax1, Lmax2) + min(Rmin1, Rmin2)) / 2.0;


}


double findMedianSortedArrays1(vector<int>& nums1, vector<int>& nums2) {
	int m = nums1.size(), n = nums2.size();
	if (m > n) return findMedianSortedArrays1(nums2, nums1);

	int iMin = 0, iMax = m, halfLen = (m + n + 1) / 2;
	while (iMin <= iMax)
	{
		int i = (iMin + iMax) / 2;
		int j = halfLen - i;
		if (i<iMax && nums2[j - 1]>nums1[i]) iMin = i + 1;
		else if (i > iMin&& nums1[i - 1] > nums2[j]) iMax = i - 1;
		else
		{
			int maxLeft;
			if (i == 0) maxLeft = nums2[j - 1];
			else if (j == 0) maxLeft = nums1[i - 1];
			else maxLeft = max(nums1[i - 1], nums2[j - 1]);

			// 奇数
			if ((m + n) % 2 == 1)return maxLeft;
			// 偶数
			int minRight;
			if (i == m)minRight = nums2[j];
			else if (j == n) minRight = nums1[i];
			else minRight = min(nums2[j], nums1[i]);

			return (maxLeft + minRight) / 2.0;
		}
	}
	return 0.0;

}


int main()
{
	vector<int> nums1 = { 3 };
	vector<int> nums2 = { -2,-1 };

	double ret = findMedianSortedArrays1(nums1, nums2);
	return 0;
}
