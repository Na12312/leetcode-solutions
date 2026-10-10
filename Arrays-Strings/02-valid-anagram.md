# Problem 2: Valid Anagram

## 1. Problem Statement

Given two strings `s` and `t`, determine whether `t` is an anagram of `s`. An anagram contains exactly the same characters with the same frequencies.

## 2. Examples

**Example 1**

Input: `s = "anagram"`, `t = "nagaram"`

Output: `true`

**Example 2**

Input: `s = "rat"`, `t = "car"`

Output: `false`

## 3. Approach

First, check whether both strings have the same length. Then use an array of 26 counters for lowercase English letters. Increase the count for each character in `s` and decrease the count for the corresponding character in `t`. If every counter is zero, the strings are anagrams.

## 4. C++ Solution

```cpp
class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.size() != t.size()) {
            return false;
        }

        vector<int> count(26, 0);

        for (int i = 0; i < s.size(); i++) {
            count[s[i] - 'a']++;
            count[t[i] - 'a']--;
        }

        for (int frequency : count) {
            if (frequency != 0) {
                return false;
            }
        }

        return true;
    }
};
```

## 5. Test Cases

| String s  | String t  | Expected Output |
| --------- | --------- | --------------- |
| `anagram` | `nagaram` | `true`          |
| `rat`     | `car`     | `false`         |
| `listen`  | `silent`  | `true`          |
| `a`       | `ab`      | `false`         |

## 6. Complexity Analysis

* **Time Complexity:** O(n)
* **Space Complexity:** O(1), because the counter array always contains 26 entries.

## 7. Learning Notes

Learned how character frequencies can be compared efficiently using a fixed-size array. This avoids sorting both strings and gives a linear-time solution.
