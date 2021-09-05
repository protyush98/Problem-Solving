//Q- https://leetcode.com/problems/next-permutation/
//brute force- https://www.geeksforgeeks.org/lexicographic-permutations-of-string/
// relevant-https://www.geeksforgeeks.org/write-a-c-program-to-print-all-permutations-of-a-given-string/
#include <bits/stdc++.h>
using namespace std;

void nextPermutation(vector<int>& nums){

    if(nums.size()==1){
        
        cout<<nums[0]<<endl;
        return;
    }

    int i;
    
    for(i=nums.size()-1;i>=1;i--){
        if(nums[i-1] < nums[i])
            break;   
    }
    if(i>0){
        int j;
        for(j=nums.size()-1;j>=0;j--){
            if(nums[i-1]<nums[j]){
            break;
            }
        }
        swap(nums[i-1],nums[j]);

    }

    reverse(nums.begin()+i,nums.end());

    

}

int main(){

    int t,n;
    
    cin>>t;

    while (t--)
    {
        vector<int> arr;
        int ip;

        cin>>n;

        for(int i=0;i<n;i++){
            cin>>ip;
            arr.push_back(ip);
        }

        nextPermutation(arr);

        for(auto val: arr){
            cout<<val<<" ";
        }
        cout<<endl;
        
    }
    
}