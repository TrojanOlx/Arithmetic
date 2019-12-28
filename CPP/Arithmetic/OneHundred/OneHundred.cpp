// OneHundred.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <vector>
#include <list>
using namespace std;

int nums[] = { 0,10,21,20,30,31,57,40,79,50,60,69,70,71 };
list<int>list1;
void SumOfkNumber(int sum, int n)
{
	// 递归出口
	if (n <= 0 || sum <= 0)
		return;

	// 输出找到的结果
	if (sum == nums[n])
	{
		// 反转list
		list1.reverse();
		for (list<int>::iterator iter = list1.begin(); iter != list1.end(); iter++)
			cout << *iter << " + ";
		cout << nums[n] << endl;
		list1.reverse();//此处还需反转回来
	}

	list1.push_front(nums[n]);      //典型的01背包问题
	SumOfkNumber(sum - nums[n], n - 1);   //“放”n，前n-1个数“填满”sum-n
	list1.pop_front();
	SumOfkNumber(sum, n - 1);     //不“放”n，n-1个数“填满”sum
}


int main()
{
	int num = 100;
	vector<int> numList(nums, nums + 12);

	// 这里是为了找到最接近的值是多少
	int max = 0;
	vector<bool> memo((__int64)num + 1, false);

	for (int i = 0; i <= num; i++)
	{
		memo[i] = (nums[0] == i);
	}


	for (int i = 1; i < numList.size(); i++)
	{
		if (memo[num]) {
			break;
		}

		for (int j = num; j >= nums[i]; j--) {
			memo[j] = memo[j] || memo[(__int64)j - nums[i]];
		}
	}
	for (int i = memo.size() - 1; i >= 0; i--)
	{
		if (memo[i])
		{
			max = i;
			break;
		}
	}

	// 将所有结果列举出来
	SumOfkNumber(max, numList.size()-1);
}
