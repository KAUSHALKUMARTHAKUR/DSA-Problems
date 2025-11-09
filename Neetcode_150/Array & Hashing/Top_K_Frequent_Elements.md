# Top K Frequent Elements

## ✅ Problem Description
Given an integer array `nums` and an integer `k`, return the **k most frequent elements** in the array.

The answer is **always unique**, and the result can be returned in **any order**.

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
- 1 <= nums.length <= 10⁴  
- -1000 <= nums[i] <= 1000  
- 1 <= k <= number of distinct elements in nums

---

# ✅ Approach
1. Count the frequency of each number using an unordered_map.  
2. Use a **max-heap (priority_queue)** to store `{value, frequency}` pairs.  
3. The heap ensures the most frequent elements are on top.  
4. Pop the top `k` frequent elements.

---

# ✅ Time Complexity
**O(n log n)**  
- Frequency count → O(n)  
- Push all unique numbers to heap → O(n log n)  
- Extract k elements → O(k log n)

---

# ✅ Space Complexity
**O(n)**  
- Hash map stores up to n unique elements  
- Priority queue stores up to n elements  

---

# ✅ C++ Code

```cpp
class Solution {
public:
    struct cmp {
        bool operator()(const pair<int,int>& a, const pair<int,int>& b) const {
            return a.second < b.second;   // max-heap based on frequency
        }
    };

    vector<int> topKFrequent(vector<int>& nums, int k) {
        
        int n = nums.size();
        vector<int> result;

        unordered_map<int,int> mp;

        // Count frequency
        for(int i = 0; i < n; i++) {
            mp[nums[i]]++;
        }

        // Max heap based on frequency
        priority_queue<pair<int,int>, vector<pair<int,int>>, cmp> pq;

        for(auto it : mp) {
            pq.push({it.first, it.second});
        }

        // Extract top k frequent elements
        while(k-- && !pq.empty()) {
            result.push_back(pq.top().first);
            pq.pop();
        }

        return result;
    }
};
```
