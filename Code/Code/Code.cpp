#include <iostream>
#include <string>
#include<windows.h>

using namespace std;

int main()
{
	//Подключаем русский язык
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);

	int n;
	cout << "Сколько строк надо ввести?" << endl;
	cin >> n; //Вводим кол-во строк

	if (n < 1) //Проверка на валидность
	{
		cout << "Кол-во строк должно быть >= 1!" << endl;
		return 0;
	}

	string **Arr = new string*[n]; //Формируем динамический массив динамических строк

	cin.ignore(); //Удаляем из потока cin лишний пробел от ввода кол-ва строк

	for (int i = 0; i < n; i++)
	{
		Arr[i] = new string[1]; //Инициализируем элемент динамического массива

		do
		{
			cout << "Введите строку:" << " ";
			getline(cin, Arr[i][0]); //Пользователь вводит строку
		} 
		while (Arr[i][0].empty());
	}

	for (int i = 0; i < n; i++)
	{
		string element = Arr[i][0]; //Получаем строку
		int start_index = 0;
		int last_index = element.size() - 1;
		int counter = 0;
		bool flag = false;

		//Находим первый элемент строки, который не пробел
		while (counter < element.size() && !flag)
		{
			flag = element[counter] != ' ';
			start_index = counter;
			counter++;
		}

		counter = element.size() - 1;
		flag = false;

		//Находим последний элемент строки, не равный пробелу
		while (counter > -1 && !flag)
		{
			flag = element[counter] != ' ';
			last_index = counter;
			counter--;
		}

		if (element[start_index] == element[last_index]) //Если первый и последний символы строки совпадают
		{
			if (i != n - 1) //Если элемент не последний
			{
				for (int j = i; j < n - 1; j++)
					Arr[j][0] = Arr[j + 1][0]; //Затираем плохую строку
			}

			delete[] Arr[n - 1]; //Удаляем последнюю строку, так как теперь она лишняя
			Arr[n - 1] = nullptr; //Делаем указатель, указывающий на пустую ячейку памяти, нулевым
			n--; //Уменьшаем размер массива
			i--; //Уменьшаем индекс на один связи с затиранием элемента
		}
	}

	cout << endl;

	//Если хотя бы одна строка осталась
	if (n != 0)
	{
		//то выводим отредактированный массив
		cout << "Ваши строки:" << endl;

		for (int i = 0; i < n; i++)
			cout << Arr[i][0] << endl;
	}
	else
	{
		//Иначе сообщаем, что все элементы были удалены
		cout << "Все строки были удалены!" << endl;
	}
	

	//Строки 99 - 103: чистим память
	for (int i = 0; i < n; i++)
		delete[] Arr[i];

	delete[] Arr;
}
