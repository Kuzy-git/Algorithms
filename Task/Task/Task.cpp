#include <iostream>
#include <vector>

using namespace std;

void task_1()
{
	cout << "Задание 1\n" << endl;
	for (int i = 0; i < 11; i++)
	{
		cout << i << endl;
	}
}

void task_2()
{
	cout << "Задание 2\n" << endl;
	int n = 0;
	cout << "Введите размер массива:" << endl;
	cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; i++)
	{
		a[i] = 2 * i;
		cout << a[i] << endl;
	}
}

void task_3()
{
	cout << "Задание 3\n" << endl;
	int n = 0;
	cout << "Введите натуральное число n:" << endl;
	cin >> n;
	vector<bool> arr(n + 1);

	for (int i = 2; i <= n; i++)
	{
		arr[i] = true;
	}

	for (int i = 2; i * i <= n; i++)
	{
		if (arr[i])
			for (int j = i * i; j <= n; j += i)
			{
				arr[j] = false;
			}
	}

	for (int i = 2; i <= n; i++)
	{
		if (arr[i] == true)
		{
			cout << i << endl;
		}
	}

}

vector<int> massive() {
	int n = 15000;
	vector<bool> mass(n + 1, true);
	vector<int> result(n);

	for (int i = 2; i <= n; i++)
	{
		mass[i] = true;
	}

	for (int i = 2; i * i <= n; i++)
	{
		if (mass[i])
			for (int j = i * i; j <= n; j += i)
			{
				mass[j] = false;
			}
	}
	int ind = 0;
	for (int i = 2; i < mass.size(); i++) {
		if (mass[i])
		{
			result[ind] = i;
			ind += 1;
		}
	}
	return result;
}

void task_4()
{
	int n=0;
	cout << "Задание 4\n" << endl;
	cout << "Введите натуральное число 0 < N < 15000:" << endl;
	cin >> n;
	vector<int> arr(n);	
	cout << "Введите числа:" << endl;
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}
	cout << endl;
	vector<int> result = massive();
	for (auto ind : arr)
	{
		cout << result[ind - 1] << endl;
	}
}


int main()
{
	setlocale(LC_ALL, "Rus");
	task_1();
	task_2();
	task_3();
	task_4();
	return 0;
}
