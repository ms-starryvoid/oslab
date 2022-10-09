#include<stdio.h>
int findLRU(int time[], int n);
void main()
{
    int n,m,prs[25];
      int frames[10], counter = 0, time[10], flag1, flag2, i, j, pos, faults = 0;
    printf("enter no of frames :");
    scanf("%d",&n);
    printf("enter no of pages:");
    scanf("%d",&m);
    printf("enter page ref string :");
    for(i=0;i<m;i++)
    {
        scanf("%d",&prs[i]);
    }
  
  for (i = 0; i < n; ++i)
   {
      frames[i] = -1;
   }
   printf("Ref string\t  page frames\n");
   for (i = 0; i < m; ++i)
   {
      printf("%d\t\t",prs[i]);
      flag1 = flag2 = 0;
 
      for (j = 0; j < n; ++j)
      {
         if (frames[j] == prs[i])
         {
            counter++;
            time[j] = counter;
            flag1 = flag2 = 1;
            break;
         }
      }
 
      if (flag1 == 0)
      {
         for (j = 0; j < n; ++j)
         {
            if (frames[j] == -1)
            {
               counter++;
               faults++;
               frames[j] = prs[i];
               time[j] = counter;
               flag2 = 1;
               break;
            }
         }
      }
 
      if (flag2 == 0)
      {
         pos = findLRU(time, n);
         counter++;
         faults++;
         frames[pos] = prs[i];
         time[pos] = counter;
      }
 
      
 
      for (j = 0; j < n; ++j)
      {
         printf("%d\t", frames[j]);
      }
      printf("\n");
   }
 
   printf("\nTotal Page Faults = %d", faults);
}

int findLRU(int time[], int n)
{
   int i, minimum = time[0], pos = 0;
 
   for (i = 1; i < n; ++i)
   {
      if (time[i] < minimum)
      {
         minimum = time[i];
         pos = i;
      }
   }
 
   return pos;
}



