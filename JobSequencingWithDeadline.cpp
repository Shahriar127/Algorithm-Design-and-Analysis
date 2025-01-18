#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Job {
    int id, deadline, profit;
};

bool compare(Job a, Job b) {
    return a.profit > b.profit;
}

void jobSequencing(Job jobs[], int n) {
    sort(jobs, jobs + n, compare);

    int maxDeadline = 0;
    for (int i = 0; i < n; i++) maxDeadline = max(maxDeadline, jobs[i].deadline);

    vector<int> slot(maxDeadline + 1, -1);
    int totalProfit = 0;

    for (int i = 0; i < n; i++) {
        for (int j = jobs[i].deadline; j > 0; j--) {
            if (slot[j] == -1) {
                slot[j] = jobs[i].id;
                totalProfit += jobs[i].profit;
                break;
            }
        }
    }

    cout << totalProfit << endl;
}

int main() {
    int n;
    cin >> n;

    Job jobs[n];
    for (int i = 0; i < n; i++) 
        cin >> jobs[i].id >> jobs[i].deadline >> jobs[i].profit;

    jobSequencing(jobs, n);
    return 0;
}
