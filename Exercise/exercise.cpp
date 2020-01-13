#include <iostream>
#include <random>
#include <ctime>
using namespace std;

#define ARRAY_SIZE 20

#define SELECTSORT_TEST
//#define BUBBLESORT_TEST
//#define INSERTSORT_TEST
//#define MERGESORT_TEST
//#define QUICKSORT_TEST

void print(int *MyArray, int size) {
	for (int i = 0; i < size; i++) {
		cout << MyArray[i] << "\t";
	}
	cout << endl;
}

void Init(int *MyArray, int size) {
	srand((int)time(0));  
	for (int i = 0; i < size; i++)
	{
		MyArray[i] = rand() % 100;
	}
}


void SelectSort(int *MyArray, int size) {
	int n=size;
    	for(;n>1;n--)
    	{
        	int i_max=0,i;
        	for(i=1;i<n;i++)
        	{
            		if(MyArray[i]>MyArray[i_max])
                		i_max=i;
        	}
        	int temp=MyArray[i_max];
        	MyArray[i_max]=MyArray[n-1];
        	MyArray[n-1]=temp;
    	}
}

void BubbleSort(int *MyArray, int size) {
	for(int i=0; i<size-1; ++i)
        {
        	for(int j=0; j<size-1-i; ++j)
        	{
            		if(MyArray[j]>MyArray[j+1])
            		{
                		int temp=MyArray[j];
                		MyArray[j]=MyArray[j+1];
               			MyArray[j+1]=temp;
           		}
        	}
    	}
}

void InsertSort(int *MyArray, int size) {
	int temp2;
    	for(int i=1;i<size;i++)
    	{
        	temp2=i;
        	for(int j=i-1;j>=0;j--)
        	{
            		if(MyArray[i]<=MyArray[j])
            		{
                		int temp1=MyArray[i];
                		MyArray[i]=MyArray[j];
                		MyArray[j]=temp1;
                		i=j;
            		}
            	else
                	break;
        	}
        	i=temp2;
    	} 
}

void MergeSort(int *MyArray, int size)
{
    	int mid,i=0,j=0,k=0,*left,*right;
    	if(size<2)
        	return;
    	mid=size/2;
    	left=new int[mid];
    	right=new int[size-mid];
    	for(i=0;i<mid;++i)
        	left[i]=MyArray[i];
    	for(i=0;i<size-mid;++i)
        	right[i]=MyArray[i+mid];
    	MergeSort(left,mid);
    	MergeSort(right,size-mid);
    	i=0;
    	while(i<mid && j<size-mid)
    	{
        	if(left[i]<right[j])
            		MyArray[k++]=left[i++];
        	else
            		MyArray[k++]=right[j++];
    	}
    	while(i<mid)
        	MyArray[k++]=left[i++];
    	while(j<size-mid)
        	MyArray[k++]=right[j++];
    	delete [] left;
    	delete [] right;
}

void QuickSort(int *MyArray, int size)
{
    	int i, j, t, temp,left=0,right=size-1;
    	if(left > right)
        	return;
    	temp = MyArray[left];
    	i = left;
    	j = right;
   	while(i != j)
    	{
        	while(MyArray[j] >= temp && i < j)
            		j--;
        	while(MyArray[i] <= temp && i < j)
            		i++;
        	if(i < j)
        	{
            		t = MyArray[i];
            		MyArray[i] = MyArray[j];
            		MyArray[j] = t;
        	}
   	 }
    	MyArray[left] = MyArray[i];
    	MyArray[i] = temp;
    	int *l=new int[i-left];
    	int *r=new int[right-i];
    	QuickSort(l, i-left);
    	QuickSort(r, right-i);
    	delete [] l;
    	delete [] r;
}
int main()
{
	int *MyArray = new int[ARRAY_SIZE];

	// Init
	Init(MyArray, ARRAY_SIZE);
	cout << "Before Sort:"; print(MyArray, ARRAY_SIZE);

#ifdef SELECTSORT_TEST
	SelectSort(MyArray, ARRAY_SIZE);
	cout << "After SelectSort:"; print(MyArray, ARRAY_SIZE);
#endif // SELECTSORT_TEST

#ifdef BUBBLESORT_TEST
	BubbleSort(MyArray, ARRAY_SIZE);
	cout << "After BubbleSort:"; print(MyArray, ARRAY_SIZE);
#endif // BUBBLESORT_TEST

#ifdef INSERTSORT_TEST
	InsertSort(MyArray, ARRAY_SIZE);
	cout << "After InsertSort:"; print(MyArray, ARRAY_SIZE);
#endif // INSERTSORT_TEST

#ifdef MERGESORT_TEST
	MergeSort(MyArray, ARRAY_SIZE);
	cout << "After MergeSort:"; print(MyArray, ARRAY_SIZE);
#endif // MERGESORT_TEST

#ifdef QUICKSORT_TEST
	QuickSort(MyArray, ARRAY_SIZE);
	cout << "After QuickSort:"; print(MyArray, ARRAY_SIZE);
#endif // QUICKESORT_TEST
	delete []MyArray;
}

// Q1: What is the time complexity of your sorting algorithm？ 
// It would be better if U can write down the process how you calculate
// A1:
SelectSort:It traverses for n + n-1 + n-2 + ...... + 2 + 1 = 0.5 * n ^ 2 + 0.5 * n times in total so the time complexity is O(N^2).
BubbleSort:If the initial state is positive，it only needs one scan to complete sorting.
	   Then the number of comparison is n-1, the number of move is 0. So the best time complexity is O(N).
	   If the sequence is in reverse order, it will also traverse for n + n-1 + n-2 + ...... + 2 + 1 = 0.5 * n ^ 2 + 0.5 * n times in total and the number of move is 3*n*(n-1)/2. 
           So the worst time complexity is O(N^2).
           In summary, the average of time complexity is O(N^2).
InsertSort:In the best situation, it only needs to compare for n-1 times.
	   In the worst situation, it needs 1 + 2 + ...... + n-1 = n*(n-1)/2 times in total to compare.
	   So the average of time complexity is O(N^2).
MergeSort:O(n log n).
QuickSort:O(n log n).
// Q2: What is the loop invariant of your sorting algorithm?
// I kown U must Know!! 
// A2:I'm not sure about this question...
SelectSort:MyArray[i_max] is the biggest number in the array.
BubbleSort:MyArray[j] <= MyArray[j+1](0<=j<size-1).
InsertSort:MyArray[i] > MyArray[j](for any 0<=j<i , 0<i<size).
MergeSort:size >= 2.
QuickSort:left < right.
// Q3: What difficulties did you encounter when writing the code?
// I will read this carefully!
// A3:
I haven't learned MergeSort before so it took me time to understand the algorithm and at the start didn't thought of the necessary condition that size shouldn't less than 2.
