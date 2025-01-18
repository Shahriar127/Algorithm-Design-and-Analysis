#include <bits/stdc++.h>
using namespace std;

struct Item {
    int value, weight;
};


bool compare(Item a, Item b) {
    double r1 = (double)a.value / a.weight;
    double r2 = (double)b.value / b.weight;
    return r1 > r2;
}

double fractionalKnapsack(int W, vector<Item>& items, int n) {
   
    sort(items.begin(), items.end(), compare);

    double maxValue = 0.0;
    int currentWeight = 0;

    for (int i = 0; i < n; i++) {
        if (currentWeight + items[i].weight <= W) {
           
            currentWeight += items[i].weight;
            maxValue += items[i].value;
        } else {
       
            int remainingWeight = W - currentWeight;
            maxValue += items[i].value * ((double)remainingWeight / items[i].weight);
            break; // Bag is full
        }
    }

    return maxValue;
}

int main() {
    int n, W;
    cout << "Enter the number of items and the capacity of the knapsack: ";
    cin >> n >> W;

    vector<Item> items(n);
    cout << "Enter the values and weights of the items:" << endl;
    for (int i = 0; i < n; i++) {
        cin >> items[i].value >> items[i].weight;
    }

    double maxValue = fractionalKnapsack(W, items, n);
    cout << "Maximum value that can be obtained: " << maxValue << endl;

    return 0;
}


/*Enter the number of items and the capacity of the knapsack: 3 50
Enter the values and weights of the items:
60 10
100 20
120 30

out :
 Maximum value that can be obtained: 240
*/



/*The logic is simple , sort all the items on basis of 'VALUE PER UNIT' and add whole item if it's weight is less than capacity otherwise
add the portion of that item.
ALGORITHM


Declare a max priority queue and implement its comparitor based on VALUE PER UNIT
2) Now push every item in pq
3) While (capacity > 0 && pq is not empty) keep poping the top element
3.1) If the top item's weight <= capacity
3.1.1) add it's value in 'total_value' and decrease the capacity by item's weight
3.2) else if item's weight > capacity
3.2.1) increment value accoring to the remaning capacity only and make capacity to zero
==> total_value += (double)top.value / top.weight * capacity;
4) return the total_value*/