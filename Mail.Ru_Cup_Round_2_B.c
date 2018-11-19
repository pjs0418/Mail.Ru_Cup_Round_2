#include <stdio.h>
#include <stdlib.h>

int main()
{
	int x, numReq, favHair;
	long long *numHair;
	int firstNum, numHairLine, numHairGrow;
	int swingCount = 0, flag = 0;

	scanf("%d %d %d", &x, &numReq, &favHair);

	numHair = (long long*)malloc(sizeof(long long) * x);

	for (int i = 0; i < x; i++)
	{
		scanf("%lld", &numHair[i]);
	}

	for (int i = 0; i < x; i++)
	{
		if ((flag == 1 && numHair[i] > favHair) || (flag == 0 && numHair[i] <= favHair))
		{
			continue;
		}
		else if (flag == 0 && numHair[i] > favHair)
		{
			swingCount++;
			flag = 1;
		}
		else
		{
			flag = 0;
		}
	}

	for (int i = 0; i < numReq; i++)
	{
		scanf("%d", &firstNum);

		if (firstNum == 0)
		{
			printf("%d\n", swingCount);
		}
		else if (firstNum == 1)
		{
			scanf("%d %d", &numHairLine, &numHairGrow);
			numHair[numHairLine - 1] += numHairGrow;

			if (x == 1 && numHair[0] - numHairGrow <= favHair)
			{
				if (numHair[0] > favHair)
				{
					swingCount++;
				}
			}
			else if (numHairLine == 1 && numHair[numHairLine - 1] - numHairGrow <= favHair && numHair[numHairLine] <= favHair)
			{
				if (numHair[numHairLine - 1] > favHair)
				{
					swingCount++;
				}
			}
			else if (numHairLine == x && numHair[numHairLine - 2] <= favHair && numHair[numHairLine - 1] - numHairGrow <= favHair)
			{
				if (numHair[numHairLine - 1] > favHair)
				{
					swingCount++;
				}
			}
			else if ((numHairLine > 1) && (numHairLine < x) && (numHair[numHairLine - 1] - numHairGrow <= favHair) && (numHair[numHairLine - 2] <= favHair) && (numHair[numHairLine] <= favHair))
			{
				if (numHair[numHairLine - 1] > favHair)
				{
					swingCount++;
				}
			}
			else if ((numHairLine > 1) && (numHairLine < x) && (numHair[numHairLine - 1] - numHairGrow <= favHair) && (numHair[numHairLine - 2] > favHair) && (numHair[numHairLine] > favHair))
			{
				if (numHair[numHairLine - 1] > favHair)
				{
					swingCount--;
				}
			}
		}
	}

	return 0;
}