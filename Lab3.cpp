#include<stdio.h>
#include<math.h>
void SortByPickingUp(int Rows, int arr1[])
{
	for (int i = 0; i < Rows; i++)
	{
		int min = arr1[i];
		int number = i;
		for (int k = i + 1; k < 5; k++)
		{
			if (arr1[k] < min)
			{
				min = arr1[k];
				number = k;
			}
		}
		arr1[number] = arr1[i];
		arr1[i] = min;
	}
}
int FooSum(int Cols, int arr2[])
{
	int Sum = 0;
	for (int i = 0; i < Cols; i++)
	{
		Sum = Sum + arr2[i];
	}
	printf("\n");
	printf("Sum = %d", Sum);
	return Sum;
}
void FooAvgGeom(int Cols, int ArrSum[])
{
	int product = 1;
	for (int i = 0; i < Cols - 1; i++)
	{
		product = product * ArrSum[i];
	}
	printf("AvgGeom = %lf", pow(product, 0.25));
	printf("\n");
}

int main()
{	/*Створення масиву*/
	int value;
	const int Rows = 5;
	const int Cols = 5;
	int arr[Rows][Cols]{};
	/*Заповнення 2-мірного масиву*/
	for (int i = 0; i < Rows; i++)
	{
		for (int j = 0; j < Cols; j++)
		{
			printf("Arr[%d, %d] = ", i, j);
			scanf("%d", &value);
			printf("\n");
			arr[i][j] = value;
		}
	}
	/*Вивід 2-мірного масиву*/
	for (int i = 0; i < Rows; i++)
	{
		for (int j = 0; j < Cols; j++)
		{
			printf("%d", arr[i][j]);
			printf("  ");
		}
		printf("\n");
	}

	/*Створення, заповнення, сортування 1-мірного масиву, що перезапише 2-мірний */
	int arr1[Cols]{};
	for (int k = 0; k < Rows; k++)
	{
		for (int n = 0; n < Cols; n++)
		{
			arr1[n] = arr[k][n];
		}
		SortByPickingUp(Rows, arr1);

		/*Перезаповнення 2-мірного масиву 1-мірним */
		for (int n = 0; n < Cols; n++)
		{
			arr[k][n] = arr1[n];
		}
	}
	/*Вивід заново перезаповнененого 2-мірного масив*/
	printf("______________NEW ARRAY________________");
	printf("\n");
	for (int i = 0; i < Rows; i++)
	{
		for (int j = 0; j < Cols; j++)
		{
			printf("%d", arr[i][j]);
			printf("  ");
		}
		printf("\n");
	}
	/*Створення та заповнення другого 1-мірного масиву*/
	printf("\n");
	int k = 4;
	int arr2[Cols]{};
	int ArrSum[Cols]{}; //Створення масиву, що сберігає суми
	for (int l = 0; l < Cols - 1; l++)
	{
		for (int s = 0; s < Cols; s++)
		{
			arr2[s] = 0;
		}
		for (int d = 0; d < k; d++)
		{
			arr2[d] = arr[d][l];
			printf("%d  ", arr2[d]);
		}
		k--;
		ArrSum[l] = FooSum(Cols, arr2);// Виклик ф-ії та збереження результатів в масив
		printf("\n");
	}
	FooAvgGeom(Cols, ArrSum);
	return 0;
}