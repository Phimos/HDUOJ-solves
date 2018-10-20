#include<cstdio>
#include<cstring>
using namespace std;
//树状数组 单点更新
#define maxn 50010

int arr[maxn];
int t, n;

int lowbit(int x)
{
	return x & (-x);
}

void update(int k, int inc)
{
	for (int i = k; i <= n; i += lowbit(i))
		arr[i] += inc;
	return;
}

int getSum(int k)
{
	int ans = 0;
	for (int i = k; i > 0; i -= lowbit(i))
		ans += arr[i];
	return ans;
}

int query(int l, int r)
{
	return getSum(r) - getSum(l - 1);
}

int main()
{
	scanf("%d", &t);
	for (int it = 1; it <= t; ++it)
	{
		printf("Case %d:\n", it);
		scanf("%d", &n);
		memset(arr, 0, sizeof(arr));
		int num, l, r, pos;
		char command[10];
		for (int i = 1; i <= n; ++i)
		{
			scanf("%d", &num);
			update(i, num);
		}
		getchar();
		while (scanf("%s", command))
		{
			if (command[0] == 'Q')
			{
				scanf("%d%d", &l, &r);
				printf("%d\n", query(l, r));
			}
			else if (command[0] == 'E')
				break;
			else
			{
				scanf("%d%d", &pos, &num);
				if (command[0] == 'A')
					update(pos, num);
				else
					update(pos, -num);
			}
			getchar();
		}
	}
}