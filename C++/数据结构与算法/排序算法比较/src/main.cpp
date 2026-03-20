#include <iostream>
#include <vector>
#include <string>
#include <random>
#include <chrono>
#include <iomanip>
#include <functional>
using namespace std;

struct SortResult {
    long long comparisons = 0;
    long long moves = 0;
    double time_ms = 0.0;
};

// Direct Insertion Sort
SortResult insertion_sort(vector<int>& arr) {
    SortResult r;
    int n = arr.size();
    for (int i = 1; i < n; ++i) {
        int key = arr[i];
        r.moves++;
        int j = i - 1;
        while (j >= 0) {
            r.comparisons++;
            if (arr[j] > key) {
                arr[j + 1] = arr[j];
                r.moves++;
                --j;
            } else {
                break;
            }
        }
        arr[j + 1] = key;
        r.moves++;
    }
    return r;
}

// Binary Insertion Sort
SortResult binary_insertion_sort(vector<int>& arr) {
    SortResult r;
    int n = arr.size();
    for (int i = 1; i < n; ++i) {
        int key = arr[i];
        r.moves++;
        int lo = 0, hi = i - 1;
        while (lo <= hi) {
            int mid = (lo + hi) / 2;
            r.comparisons++;
            if (arr[mid] > key)
                hi = mid - 1;
            else
                lo = mid + 1;
        }
        for (int j = i - 1; j >= lo; --j) {
            arr[j + 1] = arr[j];
            r.moves++;
        }
        arr[lo] = key;
        r.moves++;
    }
    return r;
}

// Shell Sort
SortResult shell_sort(vector<int>& arr) {
    SortResult r;
    int n = arr.size();
    for (int gap = n / 2; gap > 0; gap /= 2) {
        for (int i = gap; i < n; ++i) {
            int key = arr[i];
            r.moves++;
            int j = i - gap;
            while (j >= 0) {
                r.comparisons++;
                if (arr[j] > key) {
                    arr[j + gap] = arr[j];
                    r.moves++;
                    j -= gap;
                } else {
                    break;
                }
            }
            arr[j + gap] = key;
            r.moves++;
        }
    }
    return r;
}

// Bubble Sort
SortResult bubble_sort(vector<int>& arr) {
    SortResult r;
    int n = arr.size();
    for (int i = 0; i < n - 1; ++i) {
        bool swapped = false;
        for (int j = 0; j < n - 1 - i; ++j) {
            r.comparisons++;
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
                r.moves += 3;
                swapped = true;
            }
        }
        if (!swapped) break;
    }
    return r;
}

// Quick Sort
void quick_sort_impl(vector<int>& arr, int lo, int hi, SortResult& r) {
    if (lo >= hi) return;
    int pivot = arr[lo];
    r.moves++;
    int i = lo, j = hi;
    while (i < j) {
        while (i < j) {
            r.comparisons++;
            if (arr[j] < pivot) break;
            --j;
        }
        if (i < j) { arr[i++] = arr[j]; r.moves++; }
        while (i < j) {
            r.comparisons++;
            if (arr[i] > pivot) break;
            ++i;
        }
        if (i < j) { arr[j--] = arr[i]; r.moves++; }
    }
    arr[i] = pivot;
    r.moves++;
    quick_sort_impl(arr, lo, i - 1, r);
    quick_sort_impl(arr, i + 1, hi, r);
}

SortResult quick_sort(vector<int>& arr) {
    SortResult r;
    if (!arr.empty())
        quick_sort_impl(arr, 0, arr.size() - 1, r);
    return r;
}

// Selection Sort
SortResult selection_sort(vector<int>& arr) {
    SortResult r;
    int n = arr.size();
    for (int i = 0; i < n - 1; ++i) {
        int min_idx = i;
        for (int j = i + 1; j < n; ++j) {
            r.comparisons++;
            if (arr[j] < arr[min_idx])
                min_idx = j;
        }
        if (min_idx != i) {
            swap(arr[i], arr[min_idx]);
            r.moves += 3;
        }
    }
    return r;
}

struct SortAlgorithm {
    string name;
    function<SortResult(vector<int>&)> func;
};

int main() {
    vector<SortAlgorithm> algorithms = {
        {"InsertionSort",    insertion_sort},
        {"BinaryInsertSort", binary_insertion_sort},
        {"ShellSort",        shell_sort},
        {"BubbleSort",       bubble_sort},
        {"QuickSort",        quick_sort},
        {"SelectionSort",    selection_sort},
    };

    vector<int> sizes = {1000, 5000, 10000};

    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<int> dist(1, 100000);

    for (int size : sizes) {
        vector<int> original(size);
        for (int& v : original) v = dist(gen);

        cout << "=== Data Size: " << size << " ===" << endl;
        cout << left << setw(20) << "Algorithm"
             << right << setw(15) << "Comparisons"
             << setw(15) << "Moves"
             << setw(15) << "Time(ms)" << endl;
        cout << string(65, '-') << endl;

        for (auto& [name, func] : algorithms) {
            vector<int> data(original);

            auto start = chrono::high_resolution_clock::now();
            SortResult result = func(data);
            auto end = chrono::high_resolution_clock::now();
            result.time_ms = chrono::duration<double, milli>(end - start).count();

            cout << left << setw(20) << name
                 << right << setw(15) << result.comparisons
                 << setw(15) << result.moves
                 << setw(15) << fixed << setprecision(3) << result.time_ms << endl;
        }
        cout << endl;
    }

    return 0;
}
