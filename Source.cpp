#include <iostream> 
#include <ctime> 
#include <cstdlib>  
using namespace std;
//���� 4 (������)
int main()
{
	setlocale(0, "rus");
	srand(time(0));
	system("color 4F");
	const int size = 6;
	int array[size];
	int i;
	int j;
	int count = 0;

	for (i = 0; i < size; i++)
		array[i] = rand() % 10;

	for (i = 0; i < size; i++)
		cout << array[i] << " ";
	cout << endl;

	for (i = 0, j = size - 1; i < size / 2; i++, j--)
	{
		if (array[i] == array[j])
			count++;
	}

	if (count == size / 2)
		cout << "������ ����������� " << endl;
	else
		cout << "������ �� ����������� " << endl;
	delete[]array;
	system("Pause");
}