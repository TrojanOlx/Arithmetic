#include <iostream>
#include <vector>


// 物品的属性
typedef struct tagObject
{
	int weight; // 重量
	int price; // 价值
	int status; // 0：未选中，1：已选中，2：不可选
}OBJECT;

// 背包问题的两个属性：一个是可选物品列表，一个是背包的总重量
typedef struct tagKnapsackProblem
{
	std::vector<OBJECT> objs;
	int totalC;
}KNAPSACK_PROBLEM;


// 委托
typedef int (*SELECT_POLICY)(std::vector<OBJECT>& objs, int c);


// 根据价格选取
int Choosefunc1(std::vector<OBJECT>& objs, int c)
{

	int index = -1;
	int mp = 0;
	for (int i = 0; i < static_cast<int>(objs.size()); i++)
	{
		if ((objs[i].status == 0) && (objs[i].price > mp))
		{
			mp = objs[i].price;
			index = i;
		}
	}

	return index;
}

// 根据重量选取
int Choosefunc2(std::vector<OBJECT>& objs, int c) {
	int index = -1;
	int mw = INT_MAX;
	for (int i = 0; i < static_cast<int>(objs.size()); i++)
	{
		// 选最轻的
		if ((objs[i].status == 0) && (objs[i].weight < mw)) {
			mw = objs[i].weight;
			index = i;
		}
	}
	return index;
}

// 根据价值选取
int Choosefunc3(std::vector<OBJECT>& objs, int c) {
	int index = -1;
	double ms = 0.0;

	for (int i = 0; i < static_cast<int>(objs.size()); i++)
	{
		if (objs[i].status == 0)
		{
			double quality = objs[i].price;
			quality = quality / objs[i].weight;
			if (quality > ms)
			{
				quality = ms;
				index = i;
			}
		}
	}
	return index;
}

// 打印
void PrintResult(std::vector<OBJECT>& objs) {
	int totalW = 0;
	int totalP = 0;
	for (int i = 0; i < static_cast<int>(objs.size()); i++)
	{
		if (objs[i].status == 1)
		{
			totalW += objs[i].weight;
			totalP += objs[i].price;
			std::cout << "object " << i + 1 << ": weight=" << objs[i].weight <<
				", price=" << objs[i].price << std::endl;
		}
	}
	std::cout << "total weight : " << totalW << ", total price : " << totalP << std::endl;
}

//贪心的步骤：子问题的分解和选择策略
//spFunc参数是选择策略函数的接口，通过替换这个参数可以得到三种贪心策略
void GreedyAlgo(KNAPSACK_PROBLEM* problem, SELECT_POLICY spFunc) {
	int idx;
	int ntc = 0;
	while ((idx = spFunc(problem->objs, problem->totalC - ntc)) != -1)
	{
		// 所选物品是否满足背包称重要求
		if ((ntc + problem->objs[idx].weight) <= problem->totalC)
		{
			problem->objs[idx].status = 1;
			ntc += problem->objs[idx].weight;
		}
		else
		{
			problem->objs[idx].status = 2;
		}
	}
	PrintResult(problem->objs);
}

OBJECT objects[] = { {35,10,0}, {30,40,0}, {60,30,0}, {50,50,0},
					 {40,35,0}, {10,40,0}, {25,30,0} };

int main()
{
	std::cout << "Hello World!\n";

	KNAPSACK_PROBLEM problem;

	problem.objs.assign(objects, objects + 7);

	problem.totalC = 150;

	GreedyAlgo(&problem, Choosefunc1);
	//GreedyAlgo(&problem, Choosefunc2);
	//GreedyAlgo(&problem, Choosefunc3);
}

