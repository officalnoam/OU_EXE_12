#ifndef SORT_UTILS
  #define SORT_UTILS
  
  void swap(int* arr, int i, int j);
  int get_array_size(int* arr);
  int partition(int* arr, int low, int high);
  void quick_sort(int* arr, int low, int high);
  int* get_sorted_arr_copy(int* arr);
#endif
