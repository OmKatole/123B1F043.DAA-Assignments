
/*Design and implement a sorting algorithm using Merge Sort to efficiently arrange customer orders based on their timestamps. 
The solution should handle a large dataset (up to 1 million orders) with minimal computational overhead. 
Additionally, analyze the time complexity and compare it with traditional sorting techniques.*/


#include <bits/stdc++.h>
using namespace std;

struct Order {
    int order_id;
    long long timestamp;
    double value;
};

// Merge function
void merge(vector<Order>& arr, int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    vector<Order> L(n1), R(n2);

    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    int i = 0, j = 0, k = left;

    while (i < n1 && j < n2) {
        if (L[i].timestamp <= R[j].timestamp)
            arr[k++] = L[i++];
        else
            arr[k++] = R[j++];
    }

    while (i < n1)
        arr[k++] = L[i++];
    while (j < n2)
        arr[k++] = R[j++];
}

// Recursive Merge Sort
void mergeSort(vector<Order>& arr, int left, int right) {
    if (left >= right) return;
    int mid = left + (right - left) / 2;
    mergeSort(arr, left, mid);
    mergeSort(arr, mid + 1, right);
    merge(arr, left, mid, right);
}

// Helper: Generate random orders
vector<Order> generateOrders(int n) {
    vector<Order> orders(n);
    srand(time(0));
    for (int i = 0; i < n; i++) {
        orders[i].order_id = i + 1;
        orders[i].timestamp = rand() % 1000000000 + 1;
        orders[i].value = (double)(rand() % 100000) / 100.0;
    }
    return orders;
}

// Print orders (for small examples)
void printOrders(const vector<Order>& orders, int limit = 10) {
    for (int i = 0; i < min(limit, (int)orders.size()); i++) {
        cout << "Order " << orders[i].order_id 
             << " | Timestamp: " << orders[i].timestamp 
             << " | Value: " << orders[i].value << "\n";
    }
}

int main() {
    int n = 20; // number of orders (can increase up to 1 million)
    vector<Order> orders = generateOrders(n);

    cout << "Orders before sorting:\n";
    printOrders(orders);

    mergeSort(orders, 0, n - 1);

    cout << "\nOrders after sorting by timestamp:\n";
    printOrders(orders);

    return 0;
}


/*Sample output
Orders before sorting:
Order 1 | Timestamp: 951158240 | Value: 338.25
Order 2 | Timestamp: 319170166 | Value: 819.48
Order 3 | Timestamp: 231892469 | Value: 57.35
Order 4 | Timestamp: 29947539 | Value: 138.85
Order 5 | Timestamp: 305066447 | Value: 455.59
Order 6 | Timestamp: 2706906 | Value: 302.12
Order 7 | Timestamp: 498456952 | Value: 968.41
Order 8 | Timestamp: 392085531 | Value: 329.94
Order 9 | Timestamp: 144515845 | Value: 72.6
Order 10 | Timestamp: 904008819 | Value: 265.05

Orders after sorting by timestamp:
Order 6 | Timestamp: 2706906 | Value: 302.12
Order 4 | Timestamp: 29947539 | Value: 138.85
Order 19 | Timestamp: 44311472 | Value: 123.93
Order 20 | Timestamp: 53145263 | Value: 942.69
Order 11 | Timestamp: 131013961 | Value: 238.21
Order 9 | Timestamp: 144515845 | Value: 72.6
Order 16 | Timestamp: 176219219 | Value: 665.54
Order 18 | Timestamp: 202248503 | Value: 313.77
Order 15 | Timestamp: 215191963 | Value: 887.32
Order 3 | Timestamp: 231892469 | Value: 57.35
*/
