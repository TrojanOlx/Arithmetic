// LongestPalindrome.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;



string longestPalindrome(string s) {
	// 特判
	int size = s.size();
	if (size < 2) return s;

	// 得到预处理的字符串
	string str = "^#";
	for (int i = 0; i < size; i++)
	{
		str += s[i];
		str += "#";
	}
	str += "$";

	// 新字符串长度
	int strSize = 2 * size + 1;

	// 数组 p 记录了扫描过的回文子串的信息
	vector<int> p(strSize, 0);

	// 双指针，它们是一一对应的，须同时更新
	int maxRight = 0;
	int center = 0;

	// 当前遍历的中心最大扩散步数，其值等于原始字符串的最大回文子串的长度
	int maxLen = 0;
	// 原始字符串的最长回文子串的起始位置，与maxLen 必须同时更新
	int start = 0;


	for (int i = 1; i < strSize-1; i++)
	{
		if (i < maxRight)
		{
			int mirror = 2 * center - i;
			// 这一行代码是 manacher 算法的关键所在，要结合图形来理解
			p[i] = min(maxRight - i, p[mirror]);
		}
		else
		{
			p[i] = 0;
		}

		// 下一次尝试扩散的左右起点，能扩散的步数直接加到 p[i] 中
		//int left = i - (1 + p[i]);

		while (str[i + 1 + p[i]] == str[i - 1 - p[i]])
		{
			p[i]++;
		}

		// 根据 maxRight 的定义，它是遍历过的 i 的 i+p[i] 的最大值
		// 如果 maxRight 的值越大，进入上面 i < maxRight 的判断的可能性就越大，这样就可以重复利用之前判断过的回文信息
		if (i + p[i] > maxRight)
		{
			maxRight = i + p[i];
			center = i;
		}

		if (p[i] > maxLen) {
			maxLen = p[i];
			start = (i - maxLen) / 2;
		}
	}
	return s.substr(start, maxLen);

}

int main()
{
	string str = longestPalindrome("cbcbccde");
}


