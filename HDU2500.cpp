#include<iostream>
using namespace std;
//语法
int main()
{
	int t;
	cin >> t;
	for (int i = 0; i < t; ++i)
	{
		int k;
		cin >> k;
		for (int i = 0; i < 3 * k; ++i)
		{
			for (int i = 0; i < k; ++i)
				cout << "HDU";
			cout << endl;
		}
	}
}