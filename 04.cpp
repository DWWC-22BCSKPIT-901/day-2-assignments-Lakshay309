#include <iostream>
#include <vector>

using namespace std;

int findMajorityElement(const vector<int>& nums) {
    int count = 0;
    int candidate = 0;

    for (int num : nums) {
        if (count == 0) {
            candidate = num;
        }
        count += (num == candidate) ? 1 : -1;
    }

    count = 0;
    for (int num : nums) {
        if (num == candidate) {
            count++;
        }
    }

    return candidate;
}

int main() {
    int n;
    cout << "Enter the number of elements in the array: ";
    cin >> n;

    vector<int> nums(n);
    cout << "Enter the elements of the array: ";
    for (int i = 0; i < n; ++i) {
        cin >> nums[i];
    }

    int majorityElement = findMajorityElement(nums);
    cout << "The majority element is: " << majorityElement << endl;

    return 0;
}
