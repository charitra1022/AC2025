// Task 1: Study the basic Sorting algorithms ( Bubble, Selection and Insertion). 
// Also focus in its Time and space complexities, stability, and in place or not.

#include <iostream>
#include <vector>
using namespace std;

void initializeArray(vector<int> &arr) {
  // Initializes the array with random values
  for(int i=0; i<arr.size(); i++) arr[i] = rand()%100;
}
void printArray(vector<int> &arr) {
  // Print the array
  cout << "Array[" << arr.size() << "]: ";
  for(int i: arr) cout << i << " ";
  cout << endl;
}


/* ----------------- 1. Selection Sort ----------------------------------
Time Complexity: 
       Best: O(N^2)
      Worst: O(N^2)
Space Complexity: O(1)
*/
void selectionSort(vector<int> &arr) {
  int n = arr.size();

  for(int i=0; i<n-1; i++) {
    int minPos = i;   // consider i-th element to be minimum

    // Iterate through right side subarray
    for(int j=i+1; j<n; j++)
      if(arr[minPos] > arr[j]) 
        minPos = j;  // store index of minimum element in right subarray
    
    swap(arr[i], arr[minPos]);  // swap the i-th and minPos-th element
  }
}


/* ----------------- 2. Bubble Sort ----------------------------------
Time Complexity: 
       Best: O(N)
      Worst: O(N^2)
Space Complexity: O(1)
*/
void bubbleSort(vector<int> &arr) {
  int n = arr.size();

  for(int i=n; i>0; i--) {
    bool swapped = false;     // has swapping took place in this round?

    // Iterate subarray from start till end (before last sorted subarray)
    for(int j=1; j<i; j++)
      if(arr[j-1] > arr[j]) {
        swap(arr[j], arr[j-1]);   // swap if consecutive elements are not sorted
        swapped = true;           // mark swaping as true
      } 
    
    if(!swapped) // if no swapping occured, means already sorted
      break;
  }
}


/* ----------------- 3. Insertion Sort ----------------------------------
Time Complexity: 
       Best: O(N)
      Worst: O(N^2)
Space Complexity: O(1)
*/
void insertionSort(vector<int> &arr) {
  int n = arr.size();

  for(int i=1; i<n; i++) {
    int temp = arr[i];    // store current element
    int j;

    for(j=i-1; j>=0; j--) {
      if(arr[j] > temp) 
        arr[j+1] = arr[j];  // right shift elements if j-th element is greater than stored element

      else break;   // break if j-th element is greater or equal to temp
    }
    arr[j+1] = temp;  // store temp in the created space
  }
}






// ---------------------------------------------------------
// Driver code
int main(){
  srand((unsigned) time(NULL)); // make random values different in each execution
  int size = ((rand())%6)+5;   // random array size between 5-10
  vector<int> arr(size);        // declare an array


  // -----------------
  // 1. Selection Sort
  initializeArray(arr);         // initialize array with some values  
  cout << "1. Selection Sort:" << endl;
  printArray(arr);              // print original array
  selectionSort(arr);           // sorting algo applied
  printArray(arr);              // print sorted array
  cout << endl;



  // -----------------
  // 2. Bubble Sort
  initializeArray(arr);         // initialize array with some values  
  cout << "2. Bubble Sort:" << endl;
  printArray(arr);              // print original array
  bubbleSort(arr);              // sorting algo applied
  printArray(arr);              // print sorted array
  cout << endl;



  // -----------------
  // 3. Insertion Sort
  initializeArray(arr);         // initialize array with some values  
  cout << "3. Insertion Sort:" << endl;
  printArray(arr);              // print original array
  insertionSort(arr);           // sorting algo applied
  printArray(arr);              // print sorted array
  cout << endl;


  return 0;
}
