
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;


int findMaxFrom(vector<string>& strs, int m, int n) {
	if (strs.empty() || m < 0 || n < 0) return 0;

	vector<vector<int>> dp((__int64)m + 1, vector<int>((__int64)n + 1, 0));

	for (auto str : strs) {
		int zero_cnt = 0, one_cnt = 0;
		for (auto ch : str) {
			if (ch == '0') zero_cnt++;
			else one_cnt++;
		}

		for (int i = m; i >= zero_cnt; --i) {
			for (int j = n; j >= one_cnt; --j)
			{
					dp[i][j] = max(dp[i][j], dp[(__int64)i - zero_cnt][(__int64)j - one_cnt] + 1);
					cout << "===================="+str << endl;

					for (int a = 0; a < m + 1; a++) {
						for (int b = 0; b < n + 1; b++) {
							cout << dp[a][b] << "\t";
						}
						cout << endl;
					}
			}
		}


		cout << "*******************" + str << endl;

		for (int a = 0; a < m + 1; a++) {
			for (int b = 0; b < n + 1; b++) {
				cout << dp[a][b] << "\t";
			}
			cout << endl;
		}
		cout << "*******************" << endl;
		

	}
	

	return dp[m][n];
}

int main()
{
	string arr[] = { "10", "0001", "111001", "1", "0" };
	int m = 5;
	int n = 3;

	int count = sizeof(arr) / sizeof(arr[0]);
	vector<string> nums(arr, arr + count);
	int num = findMaxFrom(nums, m, n);
	cout << num << endl;
}

