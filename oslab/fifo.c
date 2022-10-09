#include<stdio.h>
void main(){
    int n,f,prs[25];
      int frames[10], counter = 0, avail ,i, j, pos, faults = 0;
    printf("enter no of frames :");
    scanf("%d",&f);
    printf("enter no of pages:");
    scanf("%d",&n);
    printf("enter page ref string :");
    for(i=0;i<n;i++)
    {
        scanf("%d",&prs[i]);
    }
  int k=0;
  for (i = 0; i < f; ++i)
   {
      frames[i] = -1;
   }
   for(i=0;i<n;i++)
   {
    printf("%d\t",prs[i]);
    avail=0;
    for(j=0;j<f;j++)
    {
        if(frames[j]==prs[i])
        {
            avail=1;
            printf(" hit\t");
            break;
        }
    }
    if(avail==0)
    {
        printf("miss\t");
      frames[k]=prs[i];
      k=(k+1)%f;
      faults++;
      for(j=0;j<f;j++)
      {
        printf("%d\t",frames[j]);
      }


    }
    printf("\n");
   }
   printf("PAGE FAULTS :%d",faults);
}