// Binary Search
#include <iostream>
using namespace std;

int binarySearch(int arr[], int size, int key)
{
    int start = 0;
    int end = size - 1;
    int mid = start + (end - start) / 2; // check
    while (start <= end)
    {
        if (arr[mid] == key)
        {
            return mid;
        }
        else if (arr[mid] < key)
        {
            start = mid + 1;
        }
        else
        {
            end = mid - 1;
        }
        mid = start + (end - start) / 2; // check
    }
    return -1;
}

int main()
{
    int z;
    cout << "Enter an array: ";
    int arr[100];
    int count = 0;
    while (true)
    {

        int value;
        cin >> value;
        if (value != -1)
        {
            arr[count] = value;
            count++;
        }
        else
        {
            break;
        }
    }
    // printing array
    for (int j = 0; j < count; j++)
    {
        cout << arr[j] << " ";
    }
    cout << endl;


    // before finding the index
    cout << "Enter key: ";
    int key;
    while (true)
    {
        if (cin >> key)
        {
            int hi = binarySearch(arr, count, key);
            if(hi == -1){
                cout << "Key not found! " << endl;
                break;
            }
            else{
            cout << "Key: " << hi << endl;
            break;
            }
        }
        else
        {
            cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
            cout << "Enter a number! " << endl;   
        }
    }

    return 0;
}