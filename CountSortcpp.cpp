#include <iostream>
#define MAX_VALUE 9
using namespace std;
int n = 15;
// ��� ������ ���� 0���� ũ�ų� ���ٰ� ����
int arr[15] = { 7, 5, 9, 0, 3, 1, 6, 2, 9, 1, 4, 8, 0, 5, 2 };
// ��� ������ �����ϴ� �迭 ����(��� ���� 0���� �ʱ�ȭ)
int cnt[MAX_VALUE + 1] = { 0, };
int main()
{
	for (int i = 0; i < n; i++)
	{
		cnt[arr[i]] += 1;
	}
	for (int i = 0; i <MAX_VALUE+1; i++)
	{
		for (int j = 0; j < cnt[i]; j++)
		{
			cout << i << ' ';
		}

	}
	system("pause");
	return 0;
}