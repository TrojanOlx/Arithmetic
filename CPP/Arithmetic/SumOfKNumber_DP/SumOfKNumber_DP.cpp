// SumOfKNumber_DP.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;



void append(vector<vector<int> >& A, vector<vector<int> >& B, int C) {
	for (int i = 0; i < B.size(); i++) {
		A.push_back(B[i]);
		A[A.size() - 1].push_back(C);
	}
}
vector<vector<int> > anslist[105][1005];
vector<vector<int> > kSumII(vector<int> A, int k, int target) {
	int ans[105][1005];
	ans[0][0] = 1;
	anslist[0][0].push_back(vector<int>());
	for (int i = 0; i < A.size(); ++i)
		for (int j = k; j > 0; j--)
			for (int l = target; l >= A[i]; l--) {
				ans[j][l] += ans[j - 1][l - A[i]];
				append(anslist[j][l], anslist[j - 1][l - A[i]], A[i]);
			}
	return anslist[k][target];
}

int main()
{
	int nums[] = { 1,2,3,4 };
	int num = 100;
	vector<int> numList(nums, nums + 4);

	set<vector<int>> returnSet;
	for (int i = 1; i <= numList.size(); i++)
	{
		auto ll = kSumII(numList, 2, 5);
		for (vector<int> list : ll) {
			sort(list.begin(), list.begin() + list.size());
			returnSet.insert(list);
		}
	}
}
