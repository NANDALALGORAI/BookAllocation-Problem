#include<iostream>
#include<vector>

using namespace std;
bool ispossible(vector<int> &arr, int n, int m, int mid)
{
    int studentCount=1;
    int pageSum=0;
    for(int i=0; i<n; i++)
    {
        if(pageSum+arr[i]<=mid)
        {
            pageSum+=arr[i];
        }
        else
        {
            studentCount++;
            if(studentCount>m || arr[i]>mid)
            {
                return false;
            }
            else
            {
                pageSum=arr[i];
            }
        }
        
    }
   return true; 
}
    int allocateBooks(vector<int> &arr, int n, int m)
    {
        int s=0;
        int sum=0;
        for(int i=0; i<n; i++)
        {
            sum+=arr[i];
        }
        int e=sum;
        int ans=-1;
        int mid=(s+e)/2;
        while(s<=e)
        {
            if(ispossible(arr, n, m, mid))
            {
                ans=mid;
                e=mid-1;
            }
            else
            {
                s=mid+1;
            }
           mid=(s+e)/2;
        }
     return ans;
}
int main(){

vector<int> arr;
int element, size;
cout<<"Enter total number of books:- ";
cin>>size;
for(int i=0; i<size; i++)
{
    cout<<"Enter number of pages of book in sorted order:- ";
    cin>>element;
    arr.push_back(element);
}
cout<<"Answer:-"<<allocateBooks(arr, size, 2);
return 0;
}
