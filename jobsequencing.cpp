#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

struct Job {
    char id;
    int deadline, profit;
};

bool compare(Job a, Job b) {
    return a.profit > b.profit;
}

void jobSequencing(vector<Job>& jobs) {
    sort(jobs.begin(), jobs.end(), compare);

    int n = jobs.size();
    vector<int> slot(n, 0);
    vector<char> result(n, '-');

    for (int i = 0; i < n; i++) {
        for (int j = jobs[i].deadline - 1; j >= 0; j--) {
            if (slot[j] == 0) {
                slot[j] = 1;
                result[j] = jobs[i].id;
                break;
            }
        }
    }

    cout << "Job sequence for maximum profit: ";
    for (char jobId : result)
        if (jobId != '-')
            cout << jobId << " ";
    cout << endl;
}

int main() {
    vector<Job> jobs = { {'a', 2, 100}, {'b', 1, 19}, {'c', 2, 27},
                         {'d', 1, 25}, {'e', 3, 15} };

    jobSequencing(jobs);

    return 0;
}
