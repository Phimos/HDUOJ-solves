#include<cstdio>
#include<cstring>
#include<stack>
#include<algorithm>
using namespace std;
//找桥，坑B题目
#define maxn 1010
#define strongBridge 9999999

int graph[maxn][maxn];
int father[maxn], low[maxn], dfn[maxn];
int n, m, id;
int soldierNum;

void init()
{
	memset(graph, 0xffffffff, sizeof(graph));
	memset(father, 0, sizeof(father));
	memset(low, 0, sizeof(low));
	memset(dfn, 0, sizeof(dfn));
	id = 0;
	soldierNum = 0x7fffffff;
}

void tarjan(int u, int fa)
{
	father[u] = fa;
	dfn[u] = low[u] = ++id;
	for (int i = 1; i <= n; ++i)
	{
		int k = graph[u][i];
		if (k == -1)
			continue;
		if (!dfn[i])
		{
			tarjan(i, u);
			low[u] = min(low[u], low[i]);
			if (dfn[u] < low[i] && graph[u][i] != strongBridge)
				soldierNum = min(soldierNum, graph[u][i]);
		}
		else if (fa != i)
			low[u] = min(low[u], dfn[i]);
	}
}

int main()
{
	while (scanf("%d%d", &n, &m), n && m)
	{
		init();
		int u, v, w;
		for (int i = 0; i < m; ++i)
		{
			scanf("%d%d%d", &u, &v, &w);
			if (graph[u][v] == -1)
				graph[u][v] = graph[v][u] = w;
			else
				graph[u][v] = graph[v][u] = strongBridge;
		}
		tarjan(1, 0);
		if (id != n)
			printf("0\n");
		else if (soldierNum == 0x7fffffff)
			printf("-1\n");
		else if (soldierNum == 0)
			printf("1\n");
		else
			printf("%d\n", soldierNum);
	}
}
