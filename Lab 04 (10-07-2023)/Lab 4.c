#include<stdio.h>
#include<time.h>
#include<stdlib.h>

void mergesort(int a[],int i,int j);
void merge(int a[],int i1,int j1,int i2,int j2);

int main()
{
    int a[50000],n,i;
    clock_t start_t, end_t;
    double total_t;
    srand(time(NULL));

    printf("Enter the number of elements:\n");
    scanf("%d",&n);

    printf("Enter array elements:");
    for(i=0;i<n;i++)
    a[i]=rand()%10000;
    start_t = clock();
    printf("Starting of the program, start_t = %ld\n", start_t);
    mergesort(a,0,n-1);
    end_t = clock();

    printf("End of the program, end_t = %ld\n", end_t);
    total_t = (double)(end_t - start_t) / CLOCKS_PER_SEC;
    printf("Total time taken by CPU: %f\n", total_t  );

    printf("\nSorted array is :");
    for(i=0;i<n;i++)
    printf("%d ",a[i]);

    return 0;
}

void mergesort(int a[],int i,int j)
{
    int mid;
    if(i<j)
    {
        mid=(i+j)/2;
        mergesort(a,i,mid);
        mergesort(a,mid+1,j);
        merge(a,i,mid,mid+1,j);
    }
}

void merge(int a[],int i1,int j1,int i2,int j2)
{
    int temp[50000];
    int i,j,k;

    i=i1;
    j=i2;
    k=0;

    while(i<=j1 && j<=j2)
    {
        if(a[i]<a[j])
        temp[k++]=a[i++];

        else
        temp[k++]=a[j++];
    }

    while(i<=j1)
    temp[k++]=a[i++];

    while(j<=j2)
    temp[k++]=a[j++];

    for(i=i1,j=0;i<=j2;i++,j++)
    a[i]=temp[j];
}
