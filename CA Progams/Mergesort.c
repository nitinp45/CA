
#include<stdio.h>
#include<time.h>
void merge(int a[],int mid ,int low,int high)
{  
    int b[100]; //2nd array
    int i=low;
    int j=mid+1;
    int k=low;  //2nd array 1 index
    while (i<=mid && j<=high)
    {
        if(a[i]<a[j])
        {
            b[k]=a[i];
            i++;
            k++;
        }
        else{
            b[k]=a[j];
            j++;
            k++;
        }
    }
    while(i<=mid)
    {
        b[k]=a[i];
        k++;
        i++;
    }
    while(j<=high)
    {
        b[k]=a[j];
        k++;
        j++;
    }
    for(i=low;i<=high;i++)
    {
        a[i]=b[i];
    }
    }
void mergesort(int a[],int low,int high)
{
    int mid;
   // delay(100);
    if(low<high)
    {
        mid=(low+high)/2;
        mergesort(a,low,mid);  //left part of array
        mergesort(a,mid+1,high);   //right part of array
        merge(a,mid,low,high);
    }
}
void print(int *a,int size)
{
    for(int i=0;i<size;i++)
    {
    printf("%d ",a[i]);
    }
    printf("\n");
}
int main()
{   
    int size=6;
    int a[]={12,3,4,10,9,7};
    //clock_t begin,end;
    print(a,size);
    //begin=clock();
    mergesort(a,0,5);
    //end=clock();
    printf("After merging the array\n");
    print(a,size);
    return 0;
}