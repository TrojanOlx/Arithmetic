// Convert.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <string>
using namespace std;


string convert(string s, int numRows) {
	if (numRows == 1) return s;
	int temp = numRows * 2 - 2;
	string str;
	int n = s.size();
	for (int i = 0; i < numRows; i++)
	{
		for (int j = 0; j + i < n; j += temp)
		{
			str += s[j + i];
			if (i != 0 && i != numRows - 1 && j + temp - i < n)
			{
				str += s[j + temp - i];
			}
		}
	}
	return str;

}


int main()
{
	string str = convert("LEETCODEISHIRING",3);
}





