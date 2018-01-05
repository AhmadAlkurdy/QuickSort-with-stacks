// Ahmad Alkurdy
//date: 9/16/2016
// quick sort with stacks, non-recursive
#include <iostream>

using namespace std;
//declaring the function
int Partition(int* numarray, int leftNum, int rightNum);
void quicksort(int* numarray, int count);

int main()
{
	int size = 0;
  
	//prompot the user to get the number of the array so we can create the dynamic array
  cout << "Enter size of the array: " << endl;
  cin >> size;
  int *numarray = new int[size];
 
  //prompt the user so we can fill up the array 
  for(int i=0;  i<  size; i++)
  {
	  cout << "Enter element " << i + 1 << " : " << endl;
    cin >> numarray[i];
  }
  
  quicksort(numarray, size); // call the function quicksort to get the numbers sorted

  cout << "Sorted elements: " << endl; // displya the array after the array is sorted
  for(int i = 0; i < size; i++)
  {
    cout << numarray[i] << endl;
  }

  system("pause");
  return 0;
}


int Partition(int* numarray, int leftNum, int rightNum)// function would place small values to the left and large values to the right

{
	int last = numarray[rightNum];
	int first = (leftNum - 1);

	for (int j = leftNum; j <= rightNum - 1; ++j)
	{
		if (numarray[j] <= last)
		{
			++first;
			swap(numarray[first], numarray[j]);
		}
	}

	swap(numarray[first + 1], numarray[rightNum]);

	return (first + 1);
}

void quicksort(int* numarray, int size)
	//function will quick sort the function using stacks 
{
	int pivot = 0;
	int first = 0;
	int last = size - 1;
	int top = -1;
	int* stack = new int[size]; // creating dynamic stack to fill the array in it

	stack[++top] = first;
	stack[++top] = last;

	while (top >= 0)
	{
		last = stack[top--];
		first = stack[top--];

		 pivot = Partition(numarray, first, last); // call partition function

		if (pivot - 1 > first)
		{
			stack[++top] = first;
			stack[++top] = pivot - 1;
		}

		if (pivot + 1 < last)
		{
			stack[++top] = pivot + 1;
			stack[++top] = last;
		}
	}

	delete stack;
}






