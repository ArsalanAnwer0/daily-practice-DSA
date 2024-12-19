#include <iostream>
using namespace std;

int left(int arr[], int size, int val)
{
    // number of occurence

    // binary search

    int start = 0;
    int end = size - 1;

    int index = -1;

    while (start <= end)
    {
        int mid = start + (end - start) / 2;

        if (arr[mid] == val)
        {
            index = mid;
            end = mid - 1;
        }
        else if(arr[mid] < val){

            start = mid + 1;
        }
        else
        {
            end = mid - 1;
        }

    }
    return index;
}
int right(int arr[], int size, int val)
{

    int start = 0;
    int end = size - 1;

    int index=-1;

    while (start <= end)
    {
        int mid = start + (end - start) / 2;

        if (arr[mid] == val)
        {
            index = mid;
            start = mid + 1;
        }
        else if(arr[mid] < val){

            start = mid + 1;


        }
        else
        {

            end = mid - 1;
           
        }

    }
    return index;
}

int main()
{

    int leftIndex, rightIndex;
    int size = 5;
    int arr[5] = {2, 2, 2, 2, 2};
    int val;
    cout << "Enter val: ";
    cin >> val;
    leftIndex = left(arr, size, val);
    rightIndex = right(arr, size, val);

    int index = rightIndex - leftIndex;
    cout << index + 1;
    return 0;
}
// }
// #include <iostream>
// using namespace std;

// int left(int arr[], int size, int val)
// {
//     int start = 0;
//     int end = size - 1;
//     int index = -1;

//     // Find the leftmost occurrence of val
//     while (start <= end)
//     {
//         int mid = start + (end - start) / 2;

//         if (arr[mid] == val)
//         {
//             index = mid; // Update index to the current mid
//             end = mid - 1; // Continue searching to the left
//         }
//         else if (arr[mid] < val)
//         {
//             start = mid + 1;
//         }
//         else
//         {
//             end = mid - 1;
//         }
//     }
//     return index;
// }

// int right(int arr[], int size, int val)
// {
//     int start = 0;
//     int end = size - 1;
//     int index = -1;

//     // Find the rightmost occurrence of val
//     while (start <= end)
//     {
//         int mid = start + (end - start) / 2;

//         if (arr[mid] == val)
//         {
//             index = mid; // Update index to the current mid
//             start = mid + 1; // Continue searching to the right
//         }
//         else if (arr[mid] < val)
//         {
//             start = mid + 1;
//         }
//         else
//         {
//             end = mid - 1;
//         }
//     }
//     return index;
// }

// int main()
// {
//     int size = 5;
//     int arr[5] = {2, 2, 2, 2, 2};
//     int val;

//     cout << "Enter val: ";
//     cin >> val;

//     int leftIndex = left(arr, size, val);
//     int rightIndex = right(arr, size, val);

//     if (leftIndex == -1 || rightIndex == -1)
//     {
//         cout << "Element not found" << endl;
//     }
//     else
//     {
//         int count = rightIndex - leftIndex + 1;
//         cout << "Number of occurrences: " << count << endl;
//     }

//     return 0;
// }
