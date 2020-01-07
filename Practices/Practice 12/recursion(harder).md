# Задача за рекурсия (по-сложна)

### Задача 1.
Напишете функция ```void binarySearch(int [] arr, int left, int right, int value)```, която в сортиран масив търси индексът на елемент със стойност value (не е кой точно ако има няколко) (https://en.wikipedia.org/wiki/Binary_search_algorithm), използвайки рекурсия. Като входен масив можете просто да въведете някакъв произволен:
```cpp
int arr[] = {-234, -83, 0, 2, 11, 25, 156, 524}; // n = 8
std::cout<< binarySearch(arr, 0, 7, 25); // 5
```