/*
Scenario: Emergency Relief Supply Distribution
A devastating flood has hit multiple villages in a remote area, and the government, along

with NGOs, is organizing an emergency relief operation. A rescue team has a limited-
capacity boat that can carry a maximum weight of W kilograms. The boat must transport

critical supplies, including food, medicine, and drinking water, from a relief center to the
affected villages.
Each type of relief item has:
● A weight (wi) in kilograms.
● Utility value (vi) indicating its importance (e.g., medicine has higher value than food).
● Some items can be divided into smaller portions (e.g., food and water), while others must
be taken as a whole (e.g., medical kits).
As the logistics manager, you must:
1. Implement the Fractional Knapsack algorithm to maximize the total utility value of the
supplies transported.
2. Prioritize high-value items while considering weight constraints.
3. Allow partial selection of divisible items (e.g., carrying a fraction of food packets).
4. Ensure that the boat carries the most critical supplies given its weight limit W.
*/

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
