#include <iostream>
#include <vector>

using namespace std;

bool compareRows(const vector<int>& a, const vector<int>& b) {
    return a < b; 
}

int partition(vector<vector<int>>& arr, int low, int high) {
    vector<int> pivot = arr[high];
    int i = low - 1;

    for (int j = low; j < high; j++) {
        if (compareRows(arr[j], pivot)) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return i + 1;
}

void quickSort(vector<vector<int>>& arr, int low, int high) {
    if (low < high) {
        int pivotIndex = partition(arr, low, high);
        quickSort(arr, low, pivotIndex - 1);
        quickSort(arr, pivotIndex + 1, high);
    }
}

int main() {
    vector<vector<int>> arr = {
        {1,2,3}, {1,2,2}, {1,1,1}, {2,2,2}, {2,1,1}, {2,1,2}, {3,3,3}, {3,2,2}, {3,1,1}
    };

    cout << "Before sorting" << endl;
    for (auto &row : arr) {
        for (int num : row) cout << num << " ";
        cout << endl;
    }


    quickSort(arr, 0, arr.size() - 1);

    cout << "After sorting" << endl;
    for (auto &row : arr) {
        for (int num : row) cout << num << " ";
        cout << endl;
    }

    return 0;
}
