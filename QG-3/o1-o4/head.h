#ifndef HEAD_H
#define HEAD_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <windows.h>
void menu();//菜单函数声明
void menul();//大数据量菜单函数声明
//void print(int arr[], int n);//打印函数声明
void fr(int arr[], int n);//从文件中读取数据到数组中声明
void fc(int arr[], int n);//将数组中的数据写入文件中声明
void InsertSort(int arr[], int n);//插入排序函数声明
void Merge(int arr[], int left, int mid, int right);//归并排序合并函数声明
void MergeSortRecursive(int arr[], int left, int right);//归并排序递归函数声明
void MergeSort(int arr[], int n);//归并排序函数声明
int Partition(int arr[], int low, int high);//快速排序分区函数声明
void QuickSortRecursive(int arr[], int low, int high);//快速排序递归函数声明
void QuickSort(int arr[], int n);//快速排序函数声明
void CountSort(int arr[], int n);//计数排序函数声明
void RadixCountSort(int arr[], int n); //基数排序函数声明
void menus();//大量小数据量菜单函数声明 

//上面的函数服务于大数据量，下面的函数服务于小数据量
//本质无区别，只是基于应用有细微的调整,同时有公共函数调用

void InsertSort1(int arr[], int n);//插入排序函数声明
void MergeSort1(int arr[], int n);//归并排序函数声明
void QuickSort1(int arr[], int n);//快速排序函数声明
void CountSort1(int arr[], int n);//计数排序函数声明
void RadixCountSort1(int arr[], int n); //基数排序函数声明
#endif