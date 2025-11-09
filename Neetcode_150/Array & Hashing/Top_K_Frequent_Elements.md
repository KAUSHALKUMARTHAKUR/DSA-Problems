# Top K Frequent Elements

## ✅ Problem Description
Given an integer array `nums` and an integer `k`, return the **k most frequent elements** in any order.  
The answer is always unique.

---

## ✅ Examples

### **Example 1**
**Input:**  
nums = [1,2,2,3,3,3], k = 2  
**Output:**  
[2,3]

### **Example 2**
**Input:**  
nums = [7,7], k = 1  
**Output:**  
[7]

---

## ✅ Constraints
- 1 ≤ nums.length ≤ 10⁴  
- -1000 ≤ nums[i] ≤ 1000  
- k ≤ number of distinct elements  

---

# ✅ Approach 1 — Max-Heap (Priority Queue)

### ✅ Intuition
- Count frequency of each number.
- Push `{num, freq}` into a **max-heap**.
- Extract top `k` frequent elements.

### ✅ Time Complexity
**O(n log n)**  
(Heap operations)

### ✅ Space Complexity
**O(n)**  
(Hash map + heap)

### ✅ C++ Code
```cpp
class Solution {
public:
    struct cmp {
        bool operator()(const pair<int,int>& a, const pair<int,int>& b) const {
            return a.second < b.second;   // max-heap on frequency
        }
    };

    vector<int> topKFrequent(vector<int>& nums, int k) {

        unordered_map<int,int> mp;
        for (int x : nums)
            mp[x]++;

        priority_queue<pair<int,int>, vector<pair<int,int>>, cmp> pq;

        for (auto &it : mp) {
            pq.push({it.first, it.second});
        }

        vector<int> result;
        while (k-- && !pq.empty()) {
            result.push_back(pq.top().first);
            pq.pop();
        }

        return result;
    }
};
```

---

# ✅ Approach 2 — Sorting Using Vector of Pairs

### ✅ Intuition
- Count frequencies.
- Store `{num, freq}` in a vector.
- Sort by frequency (descending).
- Take first `k` elements.

### ✅ Time Complexity
**O(n log n)**  
(Sorting dominates)

### ✅ Space Complexity
**O(n)**  
(Map + vector)

### ✅ C++ Code
```cpp
class Solution {
public:

    static bool myCmp(pair<int,int>& a, pair<int,int>& b) {
        return a.second > b.second;   // Sort by frequency in descending order
    }

    vector<int> topKFrequent(vector<int>& nums, int k) {
        
        unordered_map<int,int> mp;
        for (int x : nums)
            mp[x]++;

        vector<pair<int,int>> v;
        for (auto &it : mp) {
            v.push_back({it.first, it.second});
        }

        sort(v.begin(), v.end(), myCmp);

        vector<int> result;
        for (int i = 0; i < k; i++) {
            result.push_back(v[i].first);
        }

        return result;
    }
};
```

---

# ✅ Approach 3 — Bucket Sort (Optimal O(n) Solution)

### ✅ Intuition
- Maximum possible frequency is `n`.
- Create buckets: `freq[i]` contains all numbers with frequency `i`.
- Traverse from highest freq to lowest and collect top `k` elements.

### ✅ Time Complexity
✅ **O(n)**  
- Counting: O(n)  
- Bucket creation: O(n)  
- Collecting k elements: ≤ O(n)

### ✅ Space Complexity
✅ **O(n)**  
- Map + bucket array

### ✅ C++ Code
```cpp
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int,int> mp;

        vector<vector<int>> freq(n + 1);

        // Count frequencies
        for (int x : nums) {
            mp[x]++;
        }

        // Insert numbers into buckets
        for (auto &it : mp) {
            freq[it.second].push_back(it.first);
        }

        vector<int> result;

        // Traverse buckets from high freq to low freq
        for (int i = n; i >= 1; i--) {
            for (int num : freq[i]) {
                result.push_back(num);
                if (result.size() == k) {
                    return result;
                }
            }
        }

        return result;
    }
};
```

---

# ✅ Summary of All Approaches

| Approach | Time Complexity | Space Complexity | Notes |
|----------|------------------|-------------------|--------|
| **Max-Heap** | O(n log n) | O(n) | Simple & commonly used |
| **Sorting** | O(n log n) | O(n) | Easy to write |
| **Bucket Sort** | ✅ O(n) | O(n) | **Best optimal solution** |

---

# ✅ Final Recommendation
Use **Bucket Sort** (Approach 3) when optimal performance is needed.  
Use **Heap** or **Sorting** for simpler code or interviews where clarity matters.

---

