#ifndef HEAD_H
#define HEAD_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <windows.h>
void menu();//�˵���������
void menul();//���������˵���������
//void print(int arr[], int n);//��ӡ��������
void fr(int arr[], int n);//���ļ��ж�ȡ���ݵ�����������
void fc(int arr[], int n);//�������е�����д���ļ�������
void InsertSort(int arr[], int n);//��������������
void Merge(int arr[], int left, int mid, int right);//�鲢����ϲ���������
void MergeSortRecursive(int arr[], int left, int right);//�鲢����ݹ麯������
void MergeSort(int arr[], int n);//�鲢����������
int Partition(int arr[], int low, int high);//�������������������
void QuickSortRecursive(int arr[], int low, int high);//��������ݹ麯������
void QuickSort(int arr[], int n);//��������������
void CountSort(int arr[], int n);//��������������
void RadixCountSort(int arr[], int n); //��������������
void menus();//����С�������˵��������� 

//����ĺ��������ڴ�������������ĺ���������С������
//����������ֻ�ǻ���Ӧ����ϸ΢�ĵ���,ͬʱ�й�����������

void InsertSort1(int arr[], int n);//��������������
void MergeSort1(int arr[], int n);//�鲢����������
void QuickSort1(int arr[], int n);//��������������
void CountSort1(int arr[], int n);//��������������
void RadixCountSort1(int arr[], int n); //��������������
#endif