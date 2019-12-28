// LengthOfLongestSubstring.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <string>
#include <unordered_set>
#include <algorithm>
using namespace std;



int lengthOfLongestSubstring(string s) {
	if (s.size() == 0) return 0;
	unordered_set<char> lookup;
	int maxStr = 0;
	int left = 0;
	for (int i = 0; i < s.size(); i++) {
		// 移动窗口
		while (lookup.find(s[i]) != lookup.end())
		{
			lookup.erase(s[left]);
			left++;
		}
		maxStr = max(maxStr, i - left + 1);
		lookup.insert(s[i]);
	}
	return maxStr;
}

int lengthOfLongestSubstring1(string s) {
	int hash[128] = {0};
	int ans = 0;
	for (int startIndex = 0, i = 0; i < s.size(); i++) {
		startIndex = max(hash[s[i]], startIndex);
		hash[s[i]] = i + 1;
		ans = max(ans, i - startIndex + 1);
	}
	return ans;
}

int lengthOfLongestSubstring2(string s) {
	int arr[256] = { 0 };
	int left = 0;
	int temp = 0, max = 0;
	for (int right = 0; right < s.size(); ++right)
	{
		if (arr[s[right]] == 0)
		{
			arr[s[right]] = right + 1;
			temp++;
		}
		else
		{
			left = left > arr[s[right]] ? left : arr[s[right]];
			arr[s[right]] = right + 1;
			temp = right - left + 1;
		}
		max = max > temp ? max : temp;
	}
	return max;
}

int main()
{
	string str = "abcabcbb";
	int num = lengthOfLongestSubstring1(str);
}



