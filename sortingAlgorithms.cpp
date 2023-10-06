#include <iostream>
#include <time.h>
#include <chrono>
#include <ctype.h>

using namespace std;
using namespace std::chrono;

// Functions
void choice();
void bubble(int *, int);
void insertion(int *, int);
void selection(int *, int);
void shell(int *, int);
void radix(int *, int);
int MaxNum(int *, int);
void countsort(int *, int, int);

int main()
{
    choice();
    return 0;
}

void choice()
{
    int exittrig = 1;
    int length;
    char len;
    int flag = 0;
    char choice;
    system("cls");
newarray:

    cout << "Enter length of the data Array: " << endl
         << endl;
    cout << "1 -> 1,000" << endl;
    cout << "2 -> 10,000" << endl;
    cout << "3 -> 1,00,000" << endl;
    cout << "4 -> 1,000,000" << endl;
    cout << "4 -> Manual" << endl;
    cout << "\nEnter your choice: " << endl
         << "-> ";
    cin >> len;
    switch (len)
    {
    case '1':
        length = 1000;
        break;
    case '2':
        length = 10000;
        break;
    case '3':
        length = 100000;
        break;
    case '4':
        length = 1000000;
        break;
    case '5':
        cout << "Enter length of the data Array: ";
        cin >> length;
        break;
    default:
        break;
    }

    int *array = new int[length];
    srand(time(NULL)); // Defines the seed for random pick.

    // array generation initiated.
    for (int i = 0; i < length;)
    {

        int randomNumber = (int)(rand() % length);

        if (!flag)
        {
            array[i] = randomNumber;
            i++;
        }
        flag = 0;
    }

    // array generation completed.
    cout << endl;
    cout << endl;
    cout << endl;

    cout << "Select Sorting Method" << endl
         << endl;
    cout << "1 -> Bubble Sort" << endl;
    cout << "2 -> Insertion Sort" << endl;
    cout << "3 -> Selection Sort" << endl;
    cout << "4 -> Shell Sort" << endl;
    cout << "5 -> Radix Sort" << endl;
    cout << "6 -> Exit" << endl;
    cout << "7 -> New Array" << endl;

    cout << "\nEnter your choice: " << endl
         << "-> ";
    cin >> choice;

    switch (choice)
    {
    case '1':
        bubble(array, length);
        break;

    case '2':
        insertion(array, length);
        break;

    case '3':
        selection(array, length);
        break;

    case '4':
        shell(array, length);
        break;

    case '5':
        radix(array, length);
        break;

    case '6':
        exittrig = 0;
        break;

    case '7':
        goto newarray;
        break;

    default:
        break;
    }
}

// bubble sort
void bubble(int arr[], int n)
{

    int temp;
    auto start = high_resolution_clock::now();
    cout << "Sort Initiated" << endl;

    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < (n - 1 - i); j++)
        {
            if (arr[j] > arr[j + 1])
            {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }

    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    cout << endl
         << "Time taken by Bubble sort: " << duration.count() << " micro-seconds " << endl;
}

// insertion sort
void insertion(int arr[], int n)
{

    int temp;
    auto start = high_resolution_clock::now();
    cout << "Sort Initiated" << endl;

    for (int i = 1; i < n; i++)
    {
        temp = arr[i];
        int j = i - 1;

        while (j >= 0 && arr[j] > temp)
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = temp;
    }

    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);

    cout << endl
         << "Time taken by Insertion sort: " << duration.count() << " micro-seconds " << endl;
}

// selection sort
void selection(int arr[], int n)
{
    int temp;

    auto start = high_resolution_clock::now();
    cout << "Sort Initiated" << endl;

    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (arr[i] > arr[j])
            {
                temp = arr[j];
                arr[j] = arr[i];
                arr[i] = temp;
            }
        }
    }

    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    cout << endl
         << "Time taken by selection sort: " << duration.count() << " micro-seconds " << endl;
}

// shell sort
void shell(int arr[], int n)
{

    auto start = high_resolution_clock::now();
    cout << "Sort Initiated" << endl;

    for (int gap = n / 2; gap > 0; gap /= 2)
    {
        for (int i = gap; i < n; i += 1)
        {
            int temp = arr[i];

            int j;
            for (j = i; j >= gap && arr[j - gap] > temp; j -= gap)
                arr[j] = arr[j - gap];
            arr[j] = temp;
        }
    }

    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);

    cout << endl
         << "Time taken by Shell sort: " << duration.count() << " micro-seconds " << endl;
}

int MaxNum(int arr[], int n)
{
    int mx = arr[0];
    for (int i = 1; i < n; i++)
        if (arr[i] > mx)
            mx = arr[i];
    return mx;
}

void countsort(int arr[], int n, int exp)
{
    int *output = new int[n];
    int i, count[10] = {0};

    for (i = 0; i < n; i++)
        count[(arr[i] / exp) % 10]++;

    for (i = 1; i < 10; i++)
        count[i] += count[i - 1];

    for (i = n - 1; i >= 0; i--)
    {
        output[count[(arr[i] / exp) % 10] - 1] = arr[i];
        count[(arr[i] / exp) % 10]--;
    }

    for (i = 0; i < n; i++)
        arr[i] = output[i];
}

void radix(int arr[], int n)
{
    int m = MaxNum(arr, n);
    auto start = high_resolution_clock::now();
    for (int exp = 1; m / exp > 0; exp *= 10)
    {
        countsort(arr, n, exp);
    }
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);

    cout << endl
         << "Time taken by Radix sort: " << duration.count() << " micro-seconds " << endl;
}
