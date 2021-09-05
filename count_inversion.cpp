//Q-https://practice.geeksforgeeks.org/problems/inversion-of-array-1587115620/1
//soln-https://www.geeksforgeeks.org/counting-inversions/
//see all the solution below sets

#include<bits/stdc++.h>
using namespace std;

long long merge(vector<long long int> &arr,long long int left,long long int right,long long int mid){

    long long int i,j;
    i=left;
    j=mid+1;
    int inv_count=0;
    int k=0;
    long long int temp[right-left+1];

    while(i<=mid && j<=right){
        
        if(arr[i]>arr[j]){
            
            temp[k++]=arr[j];
            inv_count+=mid-i+1;
            j++;
            
        }
        else if(arr[i]<arr[j]){

            temp[k++]=arr[i];
            i++;

        }
        else{

                
            temp[k++]=arr[i];
            temp[k++]=arr[j];          
            i++;
            j++;
        }
    }

    while(i<=mid)
        temp[k++]=arr[i++];
    
    while(j<=right){
        temp[k++]=arr[j++];
    }
    
    k=0;
    for(int x=left;x<=right;x++){
        arr[x]=temp[k++];
    }
    
    return inv_count;
}

long long int merge_sort(vector<long long int> &arr,long long int left,long long int right){
    
    long long inv_count=0;
    if(left<right){
        
        

        long long int mid;

        mid=(left+right)/2;

        inv_count+=merge_sort(arr,left,mid);
        inv_count+=merge_sort(arr,mid+1,right);

        inv_count+=merge(arr,left,right,mid);

        
    }
    return inv_count;
}


long long int inversionCount(vector<long long int> &arr, long long int n){
    
    
    return merge_sort(arr,0,n-1);


}

int main(){
    
    int t;

    cin>>t;

    while (t--)
    {
        int n;
        cin>>n;

        vector<long long int> arr;
        long long int ip;
        
        for(int i=0;i<n;i++){
            
            cin>>ip;
            arr.push_back(ip);
        }

        cout<<inversionCount(arr,n)<<endl;
    }
    
}