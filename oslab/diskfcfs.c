#include<stdio.h>
#include<stdlib.h>
void printarr(int arr[],int n)
{
    int i=0;
    printf("\n");
    for(i=0;i<n;i++)
    {
        printf("%d \t",arr[i]);
    }
}
void swap(int* xp, int* yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

void main()
{
    int curr,head,dist=0,i=0,j=0,n,left[25],right[25],k,seek=0,q[50],x,temp,maxrange;
    
    printf("enter the no of requests: ");
     scanf("%d",&n);
    printf("enter current head position :");
    scanf("%d",&head);
    printf("Enter the max range :'");
    scanf("%d",&maxrange);
   
    printf("Enter request sequence : ");
    for(k=0;k<n;k++)
    {
        scanf("%d",&temp);
        if(temp<head)
        {
            left[i]=temp;
            i++;
        }
        else{
            right[j]=temp;
            j++;
        }
    }
    printarr(left,i);
   

    printarr(right,j);
    
    for(k=0;k<i-1;k++)
    {
        for(x=k+1;x<i;x++)
        {
            if(left[k]<left[x])
            {
              swap(&left[k],&left[x]);
            }
        }
    }
    printarr(left,i);
    for(k=0;k<j-1;k++)
    {
        for(x=k+1;x<j;x++)
        {
            if(right[k]>right[x])
            {
              swap(&right[k],&right[x]);
            }
        }
    }
    printarr(right,j);
    for(k=1,x=0;k<=j;k++,x++)
    {
        q[k]=right[x];
    }
    q[0]=head;
    q[k]=maxrange;
    for(k=i+1,x=0;x<=j;k++,x++)
    {
        q[k]=left[x];
    }
    q[k]=0;
    printarr(q,n+3);
    for(k=0;k<n+2;k++)
    {
        seek=abs(q[k+1]-q[k]);
        printf("\t %d",seek);
        dist=dist+seek;
    }
    
printf("\n seek time :%d",dist);
}
