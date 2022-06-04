#include<iostream>
#include <bits/stdc++.h>
using namespace std;
int minComputation(int a[],int n)
{
    priority_queue<int, vector<int>, greater<int> > pq;  //create a min heap

   for(int i=0;i<n;i++)
   {
       pq.push(a[i]);      // add sizes to priority queue
   }
   int cost=0;
   int sum;
   while(pq.size()>1)
   {
       int x=pq.top();
       pq.pop();
       int y=pq.top();
       pq.pop();
       sum=x+y;
       cost+=sum;
       pq.push(sum);
   }
    return cost;
 
}
int main()
{
    int n;
    int i,j,a[100];
    cout<<"Enter the number of elements in the array\n";
    cin>>n;
    cout<<"Enter the elements of the array\n";
    for(i=0;i<n;i++)
    {
        cin>>a[i];
    }
    int temp;
    for(i=0;i<n-1;i++)
    {
        for(j=0;j<n-i-1;j++)
        {
            if(a[j+1]<a[j])
            {
                int temp=a[j];
                a[j]=a[j+1];
                a[j+1]=temp;
            }
        }
    }
    cout<<"The sorted array is\n";
    for(i=0;i<n;i++)
    {
        cout<<"  "<<a[i];
    }
    cout<<"\nThe minimum number of computation is "<<minComputation(a,n);
}