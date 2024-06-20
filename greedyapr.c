#include<stdio.h>
void knapsack(int num, float weight[], float profit[], float capacity)
{
    float x[20], tp =0;
    int i,j,u;
    u=capacity;

    for(i=0; i<num; i++)
    x[i] =0.0;


    for(i=0; i<num; i++)
    {
        if(weight[i]>u)
        break;

        else
        {
            x[i]=1.0;
            tp = tp + profit[i];
            u = u- weight[i];
  }
    }

    if(i<num)
    {
        x[i]= u/weight[i];
        tp = tp+(x[i]*profit[i]);
    }

    printf("\n the resulted vector is:");
    for(i=0; i<num; i++)
    printf("%f\t",x[i]);

    printf("Maximum profit is: %f",tp);
}


int main()
{
    printf("-------------------------------------------------\n");

    float weight[20], profit[20], capacity;
    int num, i,j;
    float ratio[20],temp;
    printf("Enter the number of objects: ");
    scanf("%d", &num);
 printf("Enter the weight and profits of each objects: ");
    for(i=0; i<num; i++)
    scanf("%f %f",&weight[i],&profit[i]);

    printf("Enter the capacity of knapsack:");
    scanf("%f",&capacity);
   
    for(i=0; i<num; i++)
    {
        for(j=i+1; j<num; j++)
        {
            ratio[i]=profit[i]/weight[i];
            ratio[j]=profit[j]/weight[j];
            
            if(ratio[i]<ratio[j])
            {
                temp = ratio[j];
                ratio[j] = ratio[i];
                ratio[i]= temp;

                temp = weight[j];
                weight[j]= weight[i];
                weight[i]= temp;

                temp = profit[j];
  profit[j]= profit[i];
                profit[i] = temp;
            }
        }
    }
    knapsack(num, weight,profit,capacity);
    return 0;
}

