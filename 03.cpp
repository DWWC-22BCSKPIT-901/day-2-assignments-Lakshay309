#include <bits/stdc++.h>

using namespace std;

int maxHappyGroups(int batchSize, vector<int>& groups) {
    vector<int> remainderCount(batchSize, 0);
    int happyGroups = 0;

    for (int group : groups) {
        int remainder = group % batchSize;
        if (remainder == 0) {
            happyGroups++;
        } else if (remainderCount[batchSize - remainder] > 0) {
            happyGroups++;
            remainderCount[batchSize - remainder]--;
        } else {
            remainderCount[remainder]++;
        }
    }

    int remainingGroups = 0;
    for (int i = 1; i < batchSize; ++i) {
        remainingGroups += remainderCount[i];
    }

    happyGroups += remainingGroups / batchSize;

    return happyGroups;
}

int main() {
    int batchSize, n;
    cout << "Enter the batch size: ";
    cin >> batchSize;

    cout << "Enter the number of groups: ";
    cin >> n;

    vector<int> groups(n);
    cout << "Enter the size of each group: ";
    for (int i = 0; i < n; ++i) {
        cin >> groups[i];
    }

    int result = maxHappyGroups(batchSize, groups);
    cout << "The maximum number of happy groups is: " << result << endl;

    return 0;
}
