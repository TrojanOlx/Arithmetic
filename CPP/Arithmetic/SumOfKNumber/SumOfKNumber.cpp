#include <iostream>
#define GET_ARRAY_LEN(array,len){len=(sizeof(array)/sizeof(array[0]));}
using namespace std;



int res[100], k = 0, len, targer;

void sumOfKNumber(int* nums, int n, int sum) {
	if (n <= 0 || sum < 0) return;

	if (sum == 0) {
		if (n < len && nums[n] == targer) {
			cout << nums[n] << endl;
		}
	}

	if (k > 0)
	{
		if (sum == nums[n - 1]) {
			for (int i = k - 1; i >= 0; --i)
				cout << res[i] << "+";
			cout << nums[n - 1] << endl; // 输出时该元素还未加入数组
		}
	}

	// 考虑取第几个数
	res[k++] = nums[n - 1];
	sumOfKNumber(nums, n - 1, sum - nums[n - 1]);
	k--;
	sumOfKNumber(nums, n - 1, sum);
}

int main()
{
	int nums[] = { 10,20,30,40,50,60,70,80,90,100 };
	targer = 100;
	GET_ARRAY_LEN(nums, len);
	sumOfKNumber(nums, len, targer);
}

