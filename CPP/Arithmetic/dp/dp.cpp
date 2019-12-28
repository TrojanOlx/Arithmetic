#include <iostream>
#include <vector>

const int MIN = 0x80000000;
const int N = 7; // 物品数量
const int V = 150;// 背包容量
int f[N + 1][V + 1];

int Package(int* W, int* C, int N, int V)
{
	int i, j;
	memset(f, 0, sizeof(f));
	for (i = 1; i <= N; i++)          //此步骤是解决是否恰好满足背包容量，
		for (j = 1; j <= V; j++)      //若“恰好”满足背包容量，即正好装满背包，则加上此步骤，若不需要“恰好”，则初始化为0
			f[i][j] = MIN;


	for (i = 1; i <= N; i++)
		for (j = C[i]; j <= V; j++)
		{
			f[i][j] = (f[i - 1][j] > f[i - 1][j - C[i]] + W[i]) ? f[i - 1][j] : (f[i - 1][j - C[i]] + W[i]);
			std::cout << "f[" << i << "][" << j << "]=" << f[i][j] << std::endl;
		}

	return f[N][V];
}



void DPAlgo() {
	int W[8] = { 0,10,40,30,50,35,40,30 };      //物品权重
	int C[8] = { 0,35,30,60,50,40,10,25 };      //物品大小
	int result = Package(W, C, N, V);
	if (result > 0)
	{
		std::cout << std::endl;
		std::cout << "选择的值:" << result << std::endl;
		int i = N, j = V;
		while (i)
		{
			if (f[i][j] == (f[i - 1][j - C[i]] + W[i]))
			{
				std::cout << i << ":" << "w=" << W[i] << ",c=" << C[i] << std::endl;
				j -= C[i];
			}
			i--;
		} 
	}
	else
		std::cout << "can not find the opt value" << std::endl;
}

int main()
{
	DPAlgo();
}

