// 分割等和子集.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <vector>
#include <assert.h>
using namespace std;


bool canPartition(vector<int>& nums) {
	int sum = 0;
	for (int i = 0; i < nums.size(); i++)
	{
		sum += nums[i];	
	}

	if (sum%2)
	{
		return false;
	}

	int n = nums.size();
	int C = sum / 2;
	vector<bool> memo((__int64)C+1,false);

	for (int i = 0; i <= C; i++)
	{
		memo[i] = (nums[0] == i);
	}

	for (int i = 1; i < n; i++)
	{
		if (memo[C]) return memo[C];
		
		for (int j = C; j >= nums[i]; j--) {
			memo[j] = memo[j] || memo[(__int64)j - nums[i]];
		}
		for (int b = 0; b <= C; b++) {
			cout << memo[b] << "\t";
		}
		cout << endl;
	}

	return memo[C];
}


int main()
{
	//int arr[] = { 17,58,41,75,61,70,52,7,38,11,40,58,44,45,4,81,67,54,79,80,15,3,14,16,9,66,69,41,72,37,28,3,33,90,56,12,72,49,35,22,49,27,49,82,41,77,100,82,18,95,24,51,37,2,34,82,70,53,73,32,90,98,81,22,73,76,79,40,27,62,45,96,36,15,63,28,54,88,63,37,58,9,62,98,93,72,99,53,91,29,61,31,11,42,20,35,50,68,10,86 };
	int arr[] = { 1, 5, 11, 5 };
	vector<int> nums(arr, arr + 4);

	bool flag = canPartition(nums);

	nums.clear();
	cout << flag <<endl;
}
