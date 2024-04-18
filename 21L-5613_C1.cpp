#include<iostream>
#include <vector>
using namespace std;
void swap(int* x, int* y);
template <class T>
class MinHeap {
    T* arr;
    T capacity;
    T heap_size;
public:
    MinHeap(T cap) {
        heap_size = 0;
        capacity = cap;
        arr = new int[cap];
    }
    int getMin() {
        return arr[0];
    }
    int mini()
    {
        return arr[2];
    }
    int parent(int i) {
        return (i - 1) / 2;
    }
    int left(int i) {
        return (2 * i + 1);
    }
    int right(int i) {
        return (2 * i + 2);
    }
    void insertKey(T k) {
        if (heap_size == capacity)
        {
            cout << "No space";
            return;
        }
        heap_size++;
        int i = heap_size - 1;
        arr[i] = k;
        while (i != 0 && arr[parent(i)] > arr[i])
        {
            swap(&arr[i], &arr[parent(i)]);
            i = parent(i);
        }
    }
    void deleteKey(int i){
        decreaseKey(i, INT_MIN);
        extractMin();
    }
    void decreaseKey(int i, T new_val) {
        arr[i] = new_val;
        while (i != 0 && arr[parent(i)] > arr[i])
        {
            swap(&arr[i], &arr[parent(i)]);
            i = parent(i);
        }
    }
    T extractMin() {
        if (heap_size <= 0)
            return INT_MAX;
        if (heap_size == 1)
        {
            heap_size--;
            return arr[0];
        }

        int root = arr[0];
        arr[0] = arr[heap_size - 1];
        heap_size--;
        MinHeapify(0);

        return root;
    }
    void MinHeapify(int i) {
        int l = left(i);
        int r = right(i);
        int smallest = i;
        if (l < heap_size && arr[l] < arr[i])
            smallest = l;
        if (r < heap_size && arr[r] < arr[smallest])
            smallest = r;
        if (smallest != i)
        {
            swap(&arr[i], &arr[smallest]);
            MinHeapify(smallest);
        }
    }
    void MaxHeapify(int i)
    {
        int l = 2 * i + 1;
        int r = 2 * i + 2;
        int largest = i;

        if (l < heap_size && arr[l] > arr[i])
            largest = l;
        if (r < heap_size && arr[r] > arr[largest])
            largest = r;
        if (largest != i) {
            swap(&arr[i], &arr[largest]);
            MaxHeapify(largest);
        }
    }
    void convertMaxHeap()
    {
        for (int i = (heap_size) / 2; i >= 0; --i)
            MaxHeapify(i);
    }
    void display()
    {
        cout << "Heap Elements: " << endl;
        for (int i = 0; i < heap_size; i++)
        {
            cout << arr[i] << endl;
        }
        cout << endl;
    }
};
void swap(int* x, int* y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}
int main(){
    MinHeap<int> h(6);
    h.insertKey(10);
    h.insertKey(40);
    h.insertKey(50);
    h.insertKey(5);
    h.insertKey(60);
    h.insertKey(15);
    cout << "Min Heap :" << endl;;
    h.display();
    cout << "Minimum Value : " << h.extractMin() << " " << endl;
    cout << "Second Minimum Value : " << h.getMin() << " " << endl;
    cout << "Third Minimum Value : " << h.mini() << " " << endl;

    h.convertMaxHeap();
    cout << endl << "Max Heap :" << endl;;
    h.display();
    cout << endl << endl << endl;
    return 0;
}