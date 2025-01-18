#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

int findLIS(int nums[], int size, int index, int prevIndex, vector<vector<int>> &memo) {  
    if (index == size) return 0; 

    if (memo[index][prevIndex + 1] != -1)   
        return memo[index][prevIndex + 1]; 

    
    int skip = findLIS(nums, size, index + 1, prevIndex, memo);      


    int include = 0; 
    if (prevIndex == -1 || nums[index] > nums[prevIndex]) {   
        include = 1 + findLIS(nums, size, index + 1, index, memo);   
    }      

    memo[index][prevIndex + 1] = max(skip, include);
    return memo[index][prevIndex + 1];
}

int longestIncreasingSubsequence(int nums[], int size) {
    vector<vector<int>> memo(size, vector<int>(size + 1, -1));
    return findLIS(nums, size, 0, -1, memo);
}

int main() {
    int nums[] = {10, 9, 2, 5, 3, 7, 101, 18};
    int size = sizeof(nums) / sizeof(nums[0]);
    cout << "The length of the longest increasing subsequence is " 
         << longestIncreasingSubsequence(nums, size) << endl;
    return 0;
}





















/*

---

### **শিক্ষকের কাছে বোঝানোর জন্য সহজ ব্যাখ্যা**

**সমস্যার লক্ষ্য**:  
আমাদের এমন একটি উপ-সিকোয়েন্স (subsequence) খুঁজে বের করতে হবে যেখানে সংখ্যাগুলি ক্রমানুসারে (strictly increasing) সাজানো থাকে।  

**উপায়**:  
প্রতিটি ইনডেক্সে দুটি অপশন থাকে:
1. **এলিমেন্ট বাদ দিন**: বর্তমান ইনডেক্সের এলিমেন্টটি না নিয়ে সামনে যান।  
2. **এলিমেন্ট যোগ করুন**: যদি বর্তমান এলিমেন্টটি আগের এলিমেন্টের থেকে বড় হয়, তাহলে এটিকে যোগ করুন।  

**ডাইনামিক প্রোগ্রামিং (DP)** ব্যবহার করে আমরা এই দুই অপশনের ফলাফলের মধ্যে সর্বোচ্চটি বেছে নেই।  

- `skip`: এলিমেন্ট বাদ দিয়ে রিকার্সিভ কল করি।
- `include`: বর্তমান এলিমেন্টটি যোগ করে রিকার্সিভ কল করি।

**মেমোয়াইজেশন**:  
যাতে একই ইনডেক্স ও শর্তের জন্য ফলাফল বারবার গণনা না হয়, আমরা ফলাফল একটি `memo` অ্যারেতে সংরক্ষণ করি।  

**উদাহরণ**:  
ধরি `nums = {10, 9, 2, 5, 3, 7, 101, 18}`। এখানে Longest Increasing Subsequence (LIS) হলো `{2, 3, 7, 101}` এবং এর দৈর্ঘ্য ৪।*/