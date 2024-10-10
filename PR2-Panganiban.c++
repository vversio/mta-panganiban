#include <iostream>
#include <vector>
#include <algorithm> // For merge
#include <chrono> // For measuring execution time
#include <cstdlib> // For generating random numbers

using namespace std;
using namespace std::chrono;

// Bubble Sort Algorithm
void bubbleSort(vector<int>& arr) {
    int n = arr.size();
    for (int i = 0; i < n-1; i++) {
        for (int j = 0; j < n-i-1; j++) {
            if (arr[j] > arr[j+1]) {
                swap(arr[j], arr[j+1]);
            }
        }
    }
}

// Merge Sort Helper Functions
void merge(vector<int>& arr, int l, int m, int r) {
    int n1 = m - l + 1;
    int n2 = r - m;

    vector<int> L(n1), R(n2);

    for (int i = 0; i < n1; i++) L[i] = arr[l + i];
    for (int i = 0; i < n2; i++) R[i] = arr[m + 1 + i];

    int i = 0, j = 0, k = l;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) arr[k++] = L[i++];
        else arr[k++] = R[j++];
    }

    while (i < n1) arr[k++] = L[i++];
    while (j < n2) arr[k++] = R[j++];
}

void mergeSort(vector<int>& arr, int l, int r) {
    if (l < r) {
        int m = l + (r - l) / 2;
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);
        merge(arr, l, m, r);
    }
}

int main() {
    // Define different input sizes
    vector<int> sizes = {22, 420, 16034}; // Small, Medium, Large

    for (int size : sizes) {
        // Generate random delivery times
        vector<int> deliveryTimes(size);
        for (int i = 0; i < size; ++i) {
            deliveryTimes[i] = rand() % 1000; // Random times between 0 and 999
        }

        vector<int> deliveryTimesForBubble = deliveryTimes;
        vector<int> deliveryTimesForMerge = deliveryTimes;

        // Bubble Sort
        auto start = high_resolution_clock::now();
        bubbleSort(deliveryTimesForBubble);
        auto stop = high_resolution_clock::now();
        auto bubbleDuration = duration_cast<milliseconds>(stop - start);
        cout << "Bubble Sort on size " << size << " took " << bubbleDuration.count() << " ms" << endl;

        // Merge Sort
        start = high_resolution_clock::now();
        mergeSort(deliveryTimesForMerge, 0, size - 1);
        stop = high_resolution_clock::now();
        auto mergeDuration = duration_cast<milliseconds>(stop - start);
        cout << "Merge Sort on size " << size << " took " << mergeDuration.count() << " ms" << endl;
        cout << "==============================================" << endl;
    }

    return 0;
}
