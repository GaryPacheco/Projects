int OptimizedBubbleSort(int the_array[], unsigned int size) {
  bool swapped = false;
  int pass = 0;
  while (swapped == false) {
    for (int i = size -1; i > 1; i--) {
      swapped = false;
      for(unsigned int j = 0; j < i - 1; j++) {
        if (the_array[j] > the_array[j + 1])
          SwapValues(the_array[j], the_array[j + 1]);
          swapped = true;
      }
    }
    pass++;
  }
  return pass;
}

/*
 * Apply the selection sort algorithm to sort an array of integers.
 * @param int[] the_array - The integer array to be sorted
 * @param unsigned int size - The size of the_array
 * @return int - The number of passes the algorithm does. In this case "pass" is
 *               defined as the number of times the outside loop runs. You
 *               should increment your variable once you enter the outside loop.
 */
int SelectionSort(int the_array[], unsigned int size) {
  int smallest = 0;
  int pass = 0;
  for (int i = 0; i < size - 1; i++) {
    smallest = i;
    for (int j = i + 1; j < size - 1;) {
      if (the_array[j] < the_array[smallest])
        smalletst = j;
    }
    if (smallest != i)
      SwapValues(the_array[i], the_array[smallest]);
    pass++;
  }
  return pass;
}