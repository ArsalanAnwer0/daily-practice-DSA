#include <iostream>
using namespace std;

class heap
{
public:
    int *arr;
    int size;

    heap()
    {
        arr = new int[100];
        size = 0;
    }
    void insert(int val)
    {

        size++;
        arr[size] = val;
        int index = size;

        while (index > 1)
        {
            int parent = index / 2;
            if (arr[index] > arr[parent])
            {

                swap(arr[index], arr[parent]);
                index = parent;
            }
            else
            {
                return;
            }
        }
    }
    void print()
    {
        for (int i = 1; i <= size; i++)
        {
            cout << arr[i] << " ";
        }
    }
    void deleteMe()
    {

        if (size == 0)
        {
            cout << "Nothing to delete";
        }
        arr[1] = arr[size];
        size--;

        // take root node to its correct position

        int i = 1;
        while (i < size)
        {
            int left = 2 * i;
            int right = 2 * i + 1;
            if (right < size && arr[left] > arr[i])
            {

                swap(arr[left], arr[i]);
                i = left;
            }
            if (left < size && arr[right] > arr[i])
            {

                swap(arr[right], arr[i]);
                i = right;
            }
            else{
                return;
            }

        }
    }
}; 
void heapify(int arr[], int size, int i){

    int left = 2*i;
    int right = 2*i+1;
    
    int largest =  i;

    if(arr[i] < arr[left]){

        largest = left;

    }
    if(arr[i] < arr[right]){

        largest = right;

    }
    if(largest != i){
        swap(arr[largest],arr[i]);
        heapify(arr,size,largest);
    }
}
void heapsort(int arr[],int size){

    for(int i=size/2; i>0;i--){
        heapify(arr,size,i);
    }

    for(int i=size;i>1;i--){
        swap(arr[1],arr[i]);
        heapify(arr,i-1,1);

    }






}
int main()
{
    // heap h;
    // h.insert(5);
    // h.insert(10);
    // h.insert(15);
    // h.print();
    // int array[5] = {3,5,7,9,11};
    // int size = 5;
    // for(int i = size/2;i>0;i--){
    //     heapify(array,size,i);
    // }
    int height;
    cout << "Enter height: ";
    cin >> height;

    if(height > 120){

        cout << "You can ride the machine" << endl;

    }
    else{

        cout << "You cannot ride the machine " << endl;

    }

}