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
void swap(int *xp,int *yp)
{
  int temp;
  temp=*xp;
  *xp=*yp;
  *yp=temp;
}
int distance(int n,int m)
{
    return abs(n-m);
}


void sort(int arr[],int n,int order)
{
   int i,j;
   for(i=0;i<n-1;i++)
   {
     for(j=i+1;j<n;j++)
     {
      if(order==1)
      {
        if(arr[i]<arr[j])
        {
          swap(&arr[i],&arr[j]);

        }
      }
      else{
        if(arr[i]>arr[j])
        {
          swap(&arr[i],&arr[j]);

        }
      }
     }
   }
}
void right(int arr[])
{

}

void main()
{
  int i,j=0,req[20],left[20],right[20],q[20],n,seek=0,dist;
  int head,maxrange,qleft=0,qright=0;
  printf("enter no of requests :");
  scanf("%d",&n);
  printf("enter head position :");
  scanf("%d",&head);
  printf("enter max range :");
  scanf("%d",&maxrange);
  printf("enter the request sequence :");
  for(i=0;i<n;i++)
  {
    scanf("%d",&req[i]);
    if(req[i]<head)
    {
      left[qleft]=req[i];
      qleft++;
    }
    else{
      right[qright]=req[i];
      qright++;
    }
  }
  char ch;
  printf("enter direction :");
  scanf("\n");
  scanf("%c",&ch);
  sort(left,qleft,1);
  sort(right,qright,2);
  printarr(left,qleft);
  printarr(right,qright);
   q[j]=head;
   j++;
  switch (ch)
  {
  case  'r'/* constant-expression */:
                  for(i=0;i<qleft;i++)
                  {
                    q[j]=right[i];
                    j++;
                  }  
                  q[j]=maxrange;
                  j++;
                  for(i=0;i<qright;i++)
                  {
                    q[j]=left[i];
                    j++;
                  }
  
    /* code */
    break;
    case 'l': for(i=0;i<qright;i++)
                  {
                    q[j]=left[i];
                    j++;
                  }
                  q[j]=0;
                  j++;

                  for(i=0;i<qleft;i++)
                  {
                    q[j]=right[i];
                    j++;
                  }  
                  break;

         
  
  default:
    break;
  }
  for(i=0;i<j-1;i++)
  {
     dist=distance(q[i+1],q[i]);
     seek+=dist;
     printf("%d\n",seek);
  }
  printarr(q,j);
  printf("\n---------seek distance : %d",seek);
}