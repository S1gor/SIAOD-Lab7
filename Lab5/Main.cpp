#include <iostream>

using namespace std;

/*–азработать алгоритм и программу переразмещени€ чисел в некоторой заданной таблице таким образом,
чтобы все отрицательные значени€ предшествовали положительным.Ёлементы не нужно полностью сортировать;
достаточно просто отделить отрицательные числа от положительных.јлгоритм должен производить минимальное число обменов.*/

void swap(int& a, int& b)
{
	int tmp = a;
	a = b;
	b = tmp;
}

void randomInput(int* mas, int size)
{
	for (int i = 0; i < size; i++)
		mas[i] = rand() % 20 - 10;
}

void separate(int* mas, int size, int& steps)
{
	bool flag = true;
	for (int i = 0; i < size - 1; i++)
	{
		flag = true;
		for (int j = 0; j < size - 1 - i; j++)
		{
			if (mas[j] >= 0 && mas[j + 1] < 0)
			{
				swap(mas[j], mas[j + 1]);
				flag = false;
			}
			steps++;
		}
		if (flag)	break;
	}
}

void print(int* mas, int size)
{
	for (int i = 0; i < size; i++)
		cout << " " << mas[i] << " ";
	cout << endl;
}

int main()
{
	srand(time(NULL));

	const int size = 10;
	int mas[size];
	int steps = 0;

	randomInput(mas, size);
	print(mas, size);

	separate(mas, size, steps);
	print(mas, size);
	cout << "Steps: " << steps << endl;

	return 0;
}