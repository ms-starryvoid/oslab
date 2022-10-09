#include<stdio.h>
void main()
{
    int memBlock[20],processSize[20],i,j,mem,proc,alloc[20],occupied[20],idx;
    printf("enter the no of memory blocks ;");
    scanf("%d",&mem);
    printf("enter mem blocksize :");
    for(i=0;i<mem;i++)
     {
         scanf("%d",&memBlock[i]);
         occupied[i]=0;
     }
     printf("enter no of processes :");
     scanf("%d",&proc);
     printf("enter proc sizes :");
     for(i=0;i<proc;i++)
     {
        scanf("%d",&processSize[i]);
        alloc[i]=-1;
     }
     for(i=0;i<proc;i++)
     {
        idx=-1;
        for(j=0;j<mem;j++)
        {
            if(memBlock[j]>=processSize[i] && occupied[j]==0)
            {
                if(idx==-1)
                {
                    idx=j;
                }
                else if(memBlock[j]>memBlock[idx]){
                    idx=j;

                }
            }
        }
        if(idx!=-1)
        {
            alloc[i]=idx;
            memBlock[idx]-=processSize[i];
            occupied[idx]=1;
        }
     }
     printf("procno\tprocsize\t memblock\n");
     for(i=0;i<proc;i++)
     {
     printf("  %d   \t   %d     \t",i+1,processSize[i]);
     if(alloc[i]!=-1)
     {
        printf("%d\n",alloc[i]+1);
     }
     else
     {
        printf("not allocated\n");
     }
     }
}