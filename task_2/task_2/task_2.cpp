#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include <map>
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
   /* for (auto i : arr)
    {
        
        if (max <= i)
            max = i;
        
    }*/
    for (int i = 0; i < n; i++)
    {
        if (max <= arr[i]) max = arr[i];
    }
    cout << "\n"<< max;
}

//////// Задание 2


void task_2()
{
    int n;
    
    cout << "\nВведите натуральное число - количество чисел на ввод:" << endl;
    cin >> n;
    cout << endl;

    map<int, int> dict;
    vector<int> v(n);    
    
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
        dict[v[i]] += 1;
    }
   
    for (auto digit : dict)
        cout << digit.first << ":" << digit.second << endl;
}



/// /// Задание 3

vector<int> eratosthene(int &n)
{
    vector<int> result;
    int k = n*log(n)+n*log(log(n))+6;
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

    for (int i = 2; i < k; i++) {
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
    
     task_2();
   
    /// Задание 3
    ofstream fout("output.txt");
    cout << "Введите натуральное число 0 < N < 15000:" << endl;
    cin >> n;
    vector<int> result =  eratosthene(n);
    for (int i = 0; i < n; i++) {
            cout << result[i] << endl;    
            fout << result[i] << endl;
    }

    //// Задание 4
    vector<int> mass;
    int f;
    cout << "\n" << "Введите число: ";
    cin >> f;
    for (int i=0; i<f; i++)   
    {              
        cout << "Size: " << mass.size() << " \tCapacity:  " << mass.capacity() << endl;  
        mass.push_back(1);
    }  

    return 0;
}


