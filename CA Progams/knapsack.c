#include<stdio.h>
void knapsack(int n,float profit[],float weight[],float capacity)
{
  int i,j,k;
  float x[10],totalp=0;   //x[i] is the number of items selected
  k=capacity;

  for(i=0;i<n;i++)    //if job is not include
  {
      x[i]=0.0;
  }
  for(i=0;i<n;i++)
  {
      if(weight[i]>k)
      {
        x[i]=0.0;
         break;
      }
      else
      {
          x[i]=1.0;
          totalp=totalp+profit[i];
          k=k-weight[i];
      }
  }
  if(i<n)
  {
      x[i]=k/weight[i];
      totalp=totalp+x[i]*profit[i];

      printf("The resultant vector is:\n");
        for(i=0;i<n;i++)
        {
            printf("%f\n",x[i]);
        }
        printf("The total profit is:%f\n",totalp);

}
}
int main()
{
    int n,capacity;
    int i,j,temp;
    float profit[100],weight[100],ratio[100];

    printf("Enter the number of objects:");
    scanf("%d",&n);

    printf("Enter the capacity of knapsack:");
    scanf("%d",&capacity);

    printf("Enter the profit and weight of objects:");
    for(i=0;i<n;i++)
    {
        scanf("%f%f",&profit[i],&weight[i]);
    }

    for(i=0;i<n;i++)
    {
        ratio[i]=profit[i]/weight[i];
    }
    for(i=0;i<n;i++)
    {
        for(j=i+1;j<n;j++)
        {
            if(ratio[i]<ratio[j])
            {
                temp=ratio[i];
                ratio[i]=ratio[j];
                ratio[j]=temp;

                temp=profit[i];
                profit[i]=profit[j];
                profit[j]=temp;

                temp=weight[i];
                weight[i]=weight[j];
                weight[j]=temp;
            }
        }
    }
    knapsack(n,profit,weight,capacity);
}