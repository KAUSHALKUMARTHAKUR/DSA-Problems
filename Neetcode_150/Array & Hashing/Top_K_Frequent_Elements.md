# Top K Frequent Elements

## ✅ Problem Description
Given an integer array `nums` and an integer `k`, return the **k most frequent elements** in any order.

The result is always **unique**.

---

## ✅ Examples

### Example 1
**Input:**  
nums = [1,2,2,3,3,3], k = 2  
**Output:**  
[2,3]

### Example 2
**Input:**  
nums = [7,7], k = 1  
**Output:**  
[7]

---

## ✅ Constraints
- 1 ≤ nums.length ≤ 10⁴  
- -1000 ≤ nums[i] ≤ 1000  
- 1 ≤ k ≤ number of distinct elements  

---

# ✅ Approach 1 — Max-Heap (Your Code)

### ✅ Time Complexity  
- Building frequency map → **O(n)**  
- Creating max-heap of size n → **O(n log n)**  
- Extracting k elements → **O(k log n)**  
✅ **Total: O(n log n)**

### ✅ Space Complexity  
- Frequency map → **O(n)**  
- Max heap → **O(n)**  
✅ **Total: O(n)**

### ✅ Your Code (No Changes)
```cpp
class Solution {
public:
struct cmp {
    bool operator()(const pair<int,int>& a, const pair<int,int>& b) const {
        return a.second < b.second;   // max-heap on second
    }
};


    vector<int> topKFrequent(vector<int>& nums, int k) {
        
        int n = nums.size();

        vector<int>result;

        unordered_map<int,int>mp;

        for(int i=0;i<n;i++){

            mp[nums[i]]++;
        }
priority_queue<pair<int,int>, vector<pair<int,int>>, cmp> pq;


for(auto i:mp){

    pq.push({i.first,i.second});
}


while(k-- && !pq.empty()){

    result.push_back(pq.top().first);
    pq.pop();
}

return result;
    }
};
```

---

# ✅ Approach 2 — Sorting Method (Your Code)

### ✅ Time Complexity  
- Counting frequencies → **O(n)**  
- Sorting vector of pairs → **O(n log n)**  
✅ **Total: O(n log n)**

### ✅ Space Complexity  
- Map → **O(n)**  
- Vector of pairs → **O(n)**  
✅ **Total: O(n)**

### ✅ Your Code (No Changes)
```cpp
class Solution {
public:

static bool myCmp(pair<int,int>& a, pair<int,int>& b){

    return a.second>b.second;
}

    vector<int> topKFrequent(vector<int>& nums, int k) {
        
        int n = nums.size();

        vector<int>result;

        vector<pair<int,int>>v;

        unordered_map<int,int>mp;

        for(int i=0;i<n;i++){

            mp[nums[i]]++;
        }



for(auto i:mp){

    v.push_back({i.first,i.second});
}

sort(v.begin(),v.end(),myCmp);



for(int i=0;i<k;i++){

    result.push_back(v[i].first);
}


return result;
    }
};
```

---

# ✅ Approach 3 — Bucket Sort (Your Code)

### ✅ Time Complexity  
- Counting frequencies → **O(n)**  
- Creating buckets → **O(n)**  
- Extracting k results → **O(n)**  
✅ **Total: O(n)** (Optimal)

### ✅ Space Complexity  
- Map → **O(n)**  
- Buckets → **O(n)**  
✅ **Total: O(n)**

### ✅ Your Code (No Changes)
```cpp
class Solution {
public:


    vector<int> topKFrequent(vector<int>& nums, int k) {
         int n = nums.size();
        unordered_map<int,int>mp;

        vector<vector<int>>freq(n+1);

       

        for(int i=0;i<n;i++){

            mp[nums[i]]++;
        }

for(auto i:mp){

    freq[i.second].push_back(i.first);
}

vector<int>result;
for(int i=n;i>=1;i--){

    

        int m = freq[i].size();

        for(int j=m-1;j>=0;j--){
result.push_back(freq[i][j]);
if(result.size()==k){
    return result;
}    
    }
}


return result;
    }
};
```

---

# ✅ Summary

| Approach | Time Complexity | Space Complexity | Notes |
|---------|-----------------|------------------|-------|
| Max Heap | O(n log n) | O(n) | Good, standard |
| Sorting | O(n log n) | O(n) | Simple |
| Bucket Sort | ✅ O(n) | O(n) | **Most optimal** |

---

