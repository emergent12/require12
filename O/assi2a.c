// // created by suraj pisal

// #include <stdio.h>
// #include <unistd.h>   // fork function present in this library
// #include <sys/wait.h> // to include wait function


// // function to swap elements
// void swap(int *a, int *b)
// {
//   int t = *a;
//   *a = *b;
//   *b = t;
// }

// // function to find the partition position
// int partition(int array[], int low, int high)
// {

//   // select the rightmost element as pivot
//   int pivot = array[high];

//   // pointer for greater element
//   int i = (low - 1);

//   // traverse each element of the array
//   // compare them with the pivot
//   for (int j = low; j < high; j++)
//   {
//     if (array[j] <= pivot)
//     {

//       // if element smaller than pivot is found
//       // swap it with the greater element pointed by i
//       i++;

//       // swap element at i with element at j
//       swap(&array[i], &array[j]);
//     }
//   }

//   // swap the pivot element with the greater element at i
//   swap(&array[i + 1], &array[high]);

//   // return the partition point
//   return (i + 1);
// }

// void quickSort(int array[], int low, int high)
// {
//   if (low < high)
//   {

//     // find the pivot element such that
//     // elements smaller than pivot are on left of pivot
//     // elements greater than pivot are on right of pivot
//     int pi = partition(array, low, high);

//     // recursive call on the left of pivot
//     quickSort(array, low, pi - 1);

//     // recursive call on the right of pivot
//     quickSort(array, pi + 1, high);
//   }
// }

// // function to print array elements
// void printArray(int array[], int size)
// {
//   for (int i = 0; i < size; ++i)
//   {
//     printf("%d  ", array[i]);
//   }
//   printf("\n");
// }

// void bubbleSort(int array[], int size)
// {

//   // loop to access each array element
//   for (int step = 0; step < size - 1; ++step)
//   {

//     // check if swapping occurs
//     int swapped = 0;

//     // loop to compare array elements
//     for (int i = 0; i < size - step - 1; ++i)
//     {

//       // compare two array elements
//       // change > to < to sort in descending order
//       if (array[i] > array[i + 1])
//       {

//         // swapping occurs if elements
//         // are not in the intended order
//         int temp = array[i];
//         array[i] = array[i + 1];
//         array[i + 1] = temp;

//         swapped = 1;
//       }
//     }

//     // no swapping means the array is already sorted
//     // so no need for further comparison
//     if (swapped == 0)
//     {
//       break;
//     }
//   }
// }

// void bubble_Sort(int *arr, int n)
// {
//   int i, j;
//   for (i = 0; i < n; i++)
//   {
//     for (j = 0; j < n - i - 1; j++)
//     {
//       if (arr[j + 1] < arr[j])
//       {
//         swap(&arr[j], &arr[j + 1]);
//       }
//     }
//   }
// }

// // main function
// int main()
// {
//   int arr[100], n, i;
//   printf("Enter size of array : ");
//   scanf("%d", &n);
//   printf("Enter %d elements :", n);

//   for (i = 0; i < n; i++)
//   {

//     scanf("%d", &arr[i]);
//   }

//   printf("Unsorted Array\n");
//   printArray(arr, n);

//   // create new process
//   int pid = fork();

//   // if pid == 0 means it returns newly created child process
//   if (pid == 0)
//   {
//     int t = 10;
//     wait(&t);
//     printf("sorting using child\n");
//     quickSort(arr, 0, n - 1);
//   }
//   // pid greater than 0 means value contained a process id of newly created child process
//   else if (pid > 0)
//   {
//     printf("sorting using parent\n");
//     bubbleSort(arr, n);
//   }
//   else
//   {
//     printf("error child process creation failed");
//   }
//   printf("after sorting: \n");
//   printArray(arr, n);

//   return 0;
// }


