#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Activity {
    int start, finish;
};

bool compare(Activity a, Activity b) {
    return a.finish < b.finish;
}

void activitySelection(vector<Activity>& activities) {
    sort(activities.begin(), activities.end(), compare);

    cout << "Selected activities:\n";
    int lastFinish = activities[0].finish;
    cout << "(" << activities[0].start << ", " << activities[0].finish << ")\n";

    for (int i = 1; i < activities.size(); i++) {
        if (activities[i].start >= lastFinish) {
            cout << "(" << activities[i].start << ", " << activities[i].finish << ")\n";
            lastFinish = activities[i].finish;
        }
    }
}

int main() {
    vector<Activity> activities = {{1, 3}, {2, 5}, {4, 6}, {6, 7}, {5, 9}, {8, 9}};
    activitySelection(activities);

    return 0;
}
