#include <iostream>
#include <time.h>


// Task 1
int** initArr(int length, int height)
{
	int** ptr = (int**) calloc(length, sizeof(int));
	for (int i = 0; i < length; i++)
	{
		ptr[i] = (int*) calloc(height, sizeof(int));
	}
	return ptr;
}

void fillArr(int** arrPtr, int length, int height, int border)
{
	srand(time(NULL));
	for (int i = 0; i < length; i++)
		for (int j = 0; j < height; j++)
			arrPtr[i][j] = rand() % border;
}

void deleteArr(int** arrPtr, int length, int height)
{
	for (int i = 0; i < length; i++)
		delete[] arrPtr[i];
	delete[] arrPtr;
}

void printArr(int** arrPtr, int length, int height)
{
	for (int i = 0; i < length; i++)
	{
		for (int j = 0; j < height; j++)
			printf("%3d", arrPtr[i][j]);
		printf("\n");
	}
}

void swapSort(int** arrPtr, int length, int height)
{
	int temp{ 0 };
	int count{ 0 };
	while (count < length * height)
	{
		for (int i = 0; i < length; i++)
		{
			for (int j = 0; j < height - 1; j++)
			{
				temp = arrPtr[i][j];
				if (arrPtr[i][j] > arrPtr[i][j + 1])
				{
					arrPtr[i][j] = arrPtr[i][j + 1];
					arrPtr[i][j + 1] = temp;
				}
			}
			if (i < length - 1)
			{
				temp = arrPtr[i][height - 1];
				if (arrPtr[i][height - 1] > arrPtr[i + 1][0])
				{
					arrPtr[i][height - 1] = arrPtr[i + 1][0];
					arrPtr[i + 1][0] = temp;
				}
			}
		}
		count++;
	}
}

// Task 3

void tpk(int** arrPtr)
{
	for (int i = 10; i > 0; i--)
	{
		arrPtr[0][i] = sqrt(fabs(arrPtr[0][i])) + 5 * pow(arrPtr[0][i], 3);
		if (arrPtr[0][i] > 400)
			printf("%d%s", i, ":TooLarge ");
		else
			printf("%d%s%d%s", i, ":", arrPtr[0][i], " ");
	}
}

int main ()
{
	// Task 1
	const int length = 10;
	const int height = 10;

	int** arrPtr;

	arrPtr = initArr(length, height);
	fillArr(arrPtr, length, height, 100);
	printArr(arrPtr, length, height);

	printf("\n");

	swapSort(arrPtr, length, height);
	printArr(arrPtr, length, height);

	deleteArr(arrPtr, length, height);

	// Task 3
	
	printf("\n");
	arrPtr = initArr(1, 11);
	fillArr(arrPtr, 1, 11, 6);
	printArr(arrPtr, 1, 11);

	printf("\n");

	tpk(arrPtr);

	deleteArr(arrPtr, 1, 11);
	return 0;
}