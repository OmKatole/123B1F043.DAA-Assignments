

#include<bits/stdc++.h>
using namespace std;

struct Item {
    double utility;
    double weight;
    double ratio;  // utility per weight
};

// Compare to sort by ratio descending
bool compare(Item a, Item b) {
    return a.ratio > b.ratio;
}

double fractionalKnapsack(vector<Item>& items, double capacity) {
    sort(items.begin(), items.end(), compare);

    double totalUtility = 0.0;
    double remaining = capacity;

    for (auto& item : items) {
        if (item.weight <= remaining) {
            totalUtility += item.utility;
            remaining -= item.weight;
        } else {
            // Take fractional part
            totalUtility += item.ratio * remaining;
            break;
        }
    }
    return totalUtility;
}

int main() {
    int n;
    double capacity;
    cout << "Enter capacity of the boat:\n";
    cin >> capacity;
    cout << "Enter number of items:\n";
    cin >> n;

    vector<Item> items(n);
    cout << "Enter utility and weight for each item:\n";
    for (int i = 0; i < n; i++) {
        cin >> items[i].utility >> items[i].weight;
        items[i].ratio = items[i].utility / items[i].weight;
    }

    double maxUtility = fractionalKnapsack(items, capacity);
    cout << "Maximum utility value = \n" << maxUtility << endl;

    return 0;
}

/*Sample output
Enter capacity of the boat:
60
Enter number of items:
2
Enter utility and weight for each item:
70 20
100 40
Maximum utility value = 
170
*/
