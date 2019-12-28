// Euler.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
#include <stack>
#include <list>
using namespace std;

void Fleury(int start);
void DFS(int start);

const int maxn = 1005;
stack<int> S;
queue<int> solution;//存放欧拉回路（通路）的解 
list<int> adjList[maxn];//邻接表 

//（采用list+数组的形式，避免vector删边的较大时间复杂度） 
int V, E;

int main()
{
    int size[maxn];//存放每个邻接表的初始大小
    auto _ = freopen("./fleury.txt", "r", stdin);
    memset(size, 0, sizeof(size));

    scanf("%d%d", &V, &E);
    for (int i = 0; i < E; i++) {
        int v1, v2;
        scanf("%d%d", &v1, &v2);
        adjList[v1].push_back(v2);
        adjList[v2].push_back(v1);
        size[v1]++;
        size[v2]++;
    }

    int oddCount = 0, start = 1;
    for (int i = 1; i <= V; i++) {
        if (size[i] % 2) {
            oddCount++;
            start = i;
        }
    }
    if (oddCount > 2) printf("No Euler path.\n");
    else Fleury(start);
    //如果奇点数为0，则任意一个顶点都可以作为欧拉回路的起点（终点）
    //如果奇点数为2，则这两个点必然一个是起点，一个是终点
    //如果奇点数为4或更大，则不存在欧拉回路（通路） 
    return 0;
}

void Fleury(int start)
{
    S.push(start);

    while (!S.empty()) {
        int cur = S.top();
        bool bridge = !adjList[cur].empty();//判断是否有点可以扩展 
        if (bridge) {
            S.pop();
            DFS(cur);//这里要注意顺序，必须先出栈再DFS 
        }
        else {
            solution.push(cur);
            S.pop();//这里的顺序则无关紧要 
        }
    }

    bool first = true;
    while (!solution.empty()) {
        if (first) {
            printf("%d", solution.front());
            first = false;
        }
        else printf("->%d", solution.front());
        solution.pop();
    }//输出结果（注意first变量的使用） 
}

void DFS(int start)
{
    S.push(start);//将start放入堆栈中 
    if (!adjList[start].empty()) {
        list<int>::iterator itA = adjList[start].begin();
        list<int>::iterator itB;
        for (itB = adjList[*itA].begin(); itB != adjList[*itA].end(); itB++) {
            if (*itB == start) {
                itB = adjList[*itA].erase(itB);
                break;//双向删边，注意list的erase的用法 
            }
        }

        int next = *itA;
        itA = adjList[start].erase(itA);
        DFS(next);
    }
}
