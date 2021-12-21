#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
using namespace std;

///////// Задание 1

void task_1()
{
    int n;
    int max;
    cout << "Введите натуральное число - размер массива:" << endl;
    cin >> n;
    vector<int> arr(n+1);
    
    cout << "Заполните массив:" << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    max = arr[0];
    for (auto i : arr)
    {
        
        if (max <= i)        
            max = i;      
        
    }
    cout << "\n"<< max;
}

//////// Задание 2

void input(vector<int> &arr, int &n) /// Функция заполнения массива числами 
{      
    cout << "Заполните массив числами от 1 до 20:" << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        while ((arr[i] < 1) || (arr[i] > 20))
        {
            cout << "Вы ввели число вне диапазона [1; 20]. Попробуйте снова:" << endl;
            cin >> arr[i];
        }
    }
}

void sort(vector<int>& arr, int &n) /// Сортировка массива по возрастанию
{
    for (int i = 0; i < n - 1; i++)
    {
        int min = i;
        
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[min])
                min = j;
        }
        swap(arr[i], arr[min]);
    }
}

void print(vector<int>& arr, int& n) /// Вывод чисел
{
    int k = 1;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == arr[i + 1])
            k += 1;
        else
        {
            cout << arr[i] << ":" << k << endl;
            k = 1;
        }
    }
}

/// /// Задание 3

vector<int> eratosthene(int &n)
{
    vector<int> result;
    int k = 15001;
    vector<bool> arr(k+1);
    for (int i = 2; i < k; i++)
    {
        arr[i] = true;
    }

    for (int i = 2; i * i < k; i++)
    {
        if (arr[i])
            for (int j = i * i; j < k; j += i)
            {
                arr[j] = false;
            }
    }

    for (int i = 2; i < n; i++) {
        if (arr[i]) {
            result.push_back(i);
        }            
    }       
    return result;
}


int main()
{
    setlocale(LC_ALL, "Rus"); 
    /// Задание 1
    int n = 0;
    task_1();  
       
    /// Задание 2
    cout << "\nВведите натуральное число - размер массива:" << endl;
    cin >> n;
    vector<int> a(n+1);
    input(a, n); 
    sort(a, n);  
    print(a, n);
   
    /// Задание 3
    ofstream fout("output.txt");
    cout << "Введите натуральное число 0 < N < 15000:" << endl;
    cin >> n;
    vector<int> result =  eratosthene(n);
    for (int i = 0; i < result.size(); i++) {
            cout << result[i] << endl;    
            fout << result[i] << endl;
    }

    //// Задание 4
    vector<int> a;
    int f;
    while (true)
    {
        cin >> f;
        a.push_back(f);
        cout << "Текущий размер вектора: " << a.capacity() << "\n" << endl;
    }
    return 0;
}


