# Problem 1: Two Sum

## 1. Problem Statement

Given an array of integers `nums` and an integer `target`, return the indices of the two numbers that add up to the target.

## 2. Example

**Input:** `nums = [2, 7, 11, 15]`, `target = 9`

**Output:** `[0, 1]`

**Explanation:** `nums[0] + nums[1] = 2 + 7 = 9`.

## 3. Approach

Use a hash map to store numbers and their indices. For each number, calculate its complement (`target - nums[i]`). If the complement is already in the map, return both indices. Otherwise, store the current number and its index.

## 4. C++ Solution

```cpp
#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

vector<int> twoSum(vector<int>& nums, int target) {
    unordered_map<int, int> mp;

    for (int i = 0; i < nums.size(); i++) {
        int complement = target - nums[i];

        if (mp.find(complement) != mp.end()) {
            return {mp[complement], i};
        }

        mp[nums[i]] = i;
    }

    return {};
}

int main() {
    vector<int> nums = {2, 7, 11, 15};
    int target = 9;

    vector<int> result = twoSum(nums, target);

    cout << "[" << result[0] << ", " << result[1] << "]" << endl;
    return 0;
}
```

## 5. Test Cases

| Input Array      | Target | Expected Output |
| ---------------- | -----: | --------------- |
| `[2, 7, 11, 15]` |      9 | `[0, 1]`        |
| `[3, 2, 4]`      |      6 | `[1, 2]`        |
| `[3, 3]`         |      6 | `[0, 1]`        |

## 6. Complexity Analysis

* **Time Complexity:** O(n) average
* **Space Complexity:** O(n)

## 7. Learning Notes

Learned how to use a hash map to find two numbers efficiently without checking every possible pair.
