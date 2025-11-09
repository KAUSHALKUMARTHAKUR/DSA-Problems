# Top K Frequent Elements

## ✅ Problem Description
Given an integer array `nums` and an integer `k`, return the **k most frequent elements** in the array.

You may return the output in any order.  
The answer is always **unique**.

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
- 1 ≤ k ≤ number of distinct elements in nums  

---

# ✅ Approach 1 — Max-Heap (Priority Queue)

### **Steps**
1. Count the frequency of each element using `unordered_map`.  
2. Use a **max-heap** to store `{number, frequency}`.  
3. Extract the top `k` most frequent elements.

---

### ✅ Time Complexity
- Counting frequencies → **O(n)**  
- Building heap → **O(n log n)**  
- Extracting k elements → **O(k log n)**  

✅ **Overall: O(n log n)**

### ✅ Space Complexity
- Hash map → **O(n)**  
- Heap → **O(n)**  

✅ **Total: O(n)**

---

## ✅ C++ Code — Max Heap Approach

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

### **Steps**
1. Count frequencies using `unordered_map`.  
2. Push `{number, frequency}` into a vector.  
3. Sort the vector in **descending order of frequency**.  
4. Take the first `k` elements.

---

### ✅ Time Complexity
- Counting frequencies → **O(n)**  
- Building vector of unique elements → **O(n)**  
- Sorting → **O(n log n)**  

✅ **Overall: O(n log n)**

### ✅ Space Complexity
- Hash map → **O(n)**  
- Vector of pairs → **O(n)**  

✅ **Total: O(n)**

---

## ✅ C++ Code — Sorting Approach

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

# ✅ Summary

| Approach | Time Complexity | Space Complexity | Notes |
|---------|-----------------|------------------|-------|
| **Max-Heap** | O(n log n) | O(n) | Efficient, widely used |
| **Sorting** | O(n log n) | O(n) | Simpler logic, easy to write |

✅ Both are acceptable and efficient.  
✅ For strict **O(n)** solution, Bucket Sort is used (optional).  

---

