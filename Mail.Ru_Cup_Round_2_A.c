#include <stdio.h>
#include <stdlib.h>

int main()
{
	int x, y;
	int *n;
	int *r;

	scanf("%d %d", &x, &y);

	n = (int*)malloc(sizeof(int)*x);
	r = (int*)malloc(sizeof(int)*x);

	for (int i = 0; i < x; i++)
		scanf("%d", &n[i]);

	for (int i = 0; i < x; i++)
		scanf("%d", &r[i]);

	if (n[0] == 0)
		printf("NO");
	else if (n[y - 1] == 1)
		printf("YES");
	else if (x == y && n[y - 1] == 0)
		printf("NO");
	else if (r[y - 1] == 1)
	{
		for (int i = y; i < x; i++)
		{
			if (n[i] == 1 && r[i] == 1)
			{
				printf("YES");
				return 0;
			}
		}
		for (int i = y; i < x; i++)
		{
			if (n[i] != r[i])
			{
				printf("NO");
				break;
			}
		}
	}
	else
		printf("NO");

	return 0;
}