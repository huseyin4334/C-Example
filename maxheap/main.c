#include<stdlib.h>
#include<stdio.h>
#include<conio.h>
#include<math.h>

void create(int []);
void down_adjust(int [],int);



int parent(int i)
{
  return (i-1)/2;
}
int left(int i)
{
  return 2*i+1;
}
int right(int i)
{
  return 2*i+2;
}
void maxheapify(int arr[], int n, int i)
{
  int l, r,largest,temp;
  l = left(i);
  r = right(i);
  if(l<n && arr[l] > arr[i])
    largest = l;
  else
    largest = i;
  if(r<n && arr[r] > arr[largest])
    largest = r;
  //printf("\ni=%d  l=%d  r=%d largest=%d",i,l,r,largest);
  if(largest != i)
  {
    temp = arr[i];
    arr[i] = arr[largest];
    arr[largest] = temp;
    maxheapify(arr,n,largest);
  }
}

int main()
{
	int heap[30],n,i,last,temp;

	printf("Eleman Sayisini Giriniz:");
	scanf("%d",&n);

	printf("\nElemanlari giriniz:\n");
	for(i=1;i<=n;i++)
		scanf("%d",&heap[i]);

	//create a heap
	heap[0]=n;
	create(heap);



	printf("Dizinin ilk hali : ");
  for(i=1;i<=n;i++)
    printf("%d ",heap[i]);

  for(i=(n+1)/2;i>=1;i--)
    maxheapify(heap,n,i);

  printf("\nMaxheap : ");

  for(i=0;i<n;i++)
    printf("%d ",heap[i]);
  getch();





	//sorting
	while(heap[0] > 1)
	{
		//swap heap[1] and heap[last]
		last=heap[0];
		temp=heap[1];
		heap[1]=heap[last];
		heap[last]=temp;
		heap[0]--;
		down_adjust(heap,1);
	}

	//print sorted data
	printf("\nMin Heap:\n");
	for(i=1;i<=n;i++)
		printf("%d ",heap[i]);

	return 0;
}

void create(int heap[])
{
	int i,n;
	n=heap[0]; //no. of elements

	for(i=n/2;i>=1;i--)
		down_adjust(heap,i);
}

void down_adjust(int heap[],int i)
{
	int j,temp,n,flag=1;
	n=heap[0];

	while(2*i<=n && flag==1)
	{
		j=2*i;    //j points to left child
		if(j+1<=n && heap[j+1] > heap[j])
			j=j+1;
		if(heap[i] > heap[j])
			flag=0;
		else
		{
			temp=heap[i];
			heap[i]=heap[j];
			heap[j]=temp;
			i=j;
		}
	}
}
