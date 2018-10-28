#include<iostream>
#include<algorithm>
#include<map>
#include<stack>
#include<cstdio>
using namespace std;
#define maxn 50010

struct Node
{
	int l, r;
	int leftLen, rightLen;
	bool allConnected;
} tree[maxn << 2];
int n, m;

void buildTree(int root, int l, int r)
{
	tree[root].l = l;
	tree[root].r = r;
	tree[root].leftLen = tree[root].rightLen = r - l + 1;
	tree[root].allConnected = true;
	if (l == r)
		return;
	else
	{
		int mid = (l + r) >> 1;
		buildTree(root << 1, l, mid);
		buildTree(root << 1 | 1, mid + 1, r);
	}
}

void pushUp(int root)
{
	tree[root].leftLen = tree[root << 1].leftLen;
	if (tree[root << 1].allConnected)
		tree[root].leftLen += tree[root << 1 | 1].leftLen;
	tree[root].rightLen = tree[root << 1 | 1].rightLen;
	if (tree[root << 1 | 1].allConnected)
		tree[root].rightLen += tree[root << 1].rightLen;
	tree[root].allConnected = tree[root << 1].allConnected && tree[root << 1 | 1].allConnected;
}

void destroy(int root, int k)
{
	if (tree[root].l == tree[root].r)
	{
		tree[root].leftLen = tree[root].rightLen = 0;
		tree[root].allConnected = false;
		return;
	}
	else
	{
		if (tree[root << 1].r >= k)
			destroy(root << 1, k);
		else
			destroy(root << 1 | 1, k);
		pushUp(root);
	}
}

void rebuild(int root, int k)
{
	if (tree[root].l == tree[root].r)
	{
		tree[root].leftLen = tree[root].rightLen = 1;
		tree[root].allConnected = true;
		return;
	}
	else
	{
		if (tree[root << 1].r >= k)
			rebuild(root << 1, k);
		else
			rebuild(root << 1 | 1, k);
		pushUp(root);
	}
}

int query(int root, int k)
{
	int ans = 0;
	if (tree[root].allConnected)
	{
		return tree[root].leftLen;
	}
	else if (tree[root].l == tree[root].r)
		return 0;
	else
	{
		if (tree[root << 1].r >= k)
		{
			if (tree[root << 1].r - tree[root << 1].rightLen < k)
				return query(root << 1, k) + tree[root << 1 | 1].leftLen;
			else
				return query(root << 1, k);
		}
		else
		{
			if (tree[root << 1 | 1].l + tree[root << 1 | 1].leftLen > k)
				return query(root << 1 | 1, k) + tree[root << 1].rightLen;
			else
				return query(root << 1 | 1, k);
		}
	}
}


int main()
{
	char event;
	int k;
	stack<int> destroyed;
	while (scanf("%d %d", &n, &m))
	{
		buildTree(1, 1, n);
		for (int i = 0; i < m; ++i)
		{
			getchar();
			scanf("%c", &event);
			if (event == 'R')
			{
				rebuild(1, destroyed.top());
				destroyed.pop();
			}
			else
			{
				scanf("%d", &k);
				if (event == 'D')
				{
					destroy(1, k);
					destroyed.push(k);
				}
				else
				{
					int ans = query(1, k);
					printf("%d\n", ans);
				}
			}
		}
	}
}