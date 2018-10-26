#include<cstdio>
#include<algorithm>
using namespace std;
//语法
#define maxn 1010
int nums[maxn];
int main()
{
	int t;
	scanf("%d", &t);
	for (int i = 0; i < t; ++i)
	{
		int n;
		scanf("%d", &n);
		for (int i = 0; i < n; ++i)
			scanf("%d", nums + i);
		sort(nums, nums + n);
		printf("%d", nums[0]);
		for (int i = 1; i < n; ++i)
			printf(" %d", nums[i]);
		printf("\n");
	}
	return 0;
}