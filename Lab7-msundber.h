// Matthew Sundberg
// COSC 2030
// 11-19-2018

#ifndef LAB7_MSUNDBER_H
#define LAB7_MSUNDBER_H

#include "winTimer.h"
#include <iostream>
#include <vector>
#include <algorithm>

using std::vector;
using std::sort;

double randUniform()
{
	double r = double(rand()) / (RAND_MAX + 1.0);
	r = (double(rand()) + r) / (RAND_MAX + 1.0);
	r = (double(rand()) + r) / (RAND_MAX + 1.0);
	r = (double(rand()) + r) / (RAND_MAX + 1.0);
	return  r;
}

double randReal(double minReal, double maxReal)
{
	return minReal
		+ (maxReal - minReal) * randUniform();
}

// This function will add a random number of
// random values into the vector.
vector<double> getNums(size_t listSize, double minNum, double maxNum)
{
	vector<double> theList;
	for (size_t i = 0; i < listSize; ++i)
	{
		theList.push_back(randReal(minNum, maxNum));
	}

	return theList;
}

void swap(double *x, double *y)
{
	double temp = *x;
	*x = *y;
	*y = temp;
}

void bubbleSort(vector<double> &x, int n)
{
	int i, j;
	bool swapped;
	for (i = 0; i < n - 1; i++)
	{
		swapped = false;
		for (j = 0; j < n - i - 1; j++)
		{
			if (x.at(j) > x.at(j + 1))
			{
				swap(&x.at(j), &x.at(j + 1));
				swapped = true;
			}
		}

		// IF no two elements were swapped by inner loop, then break 
		if (swapped == false)
			break;
	}
}

void insertionSort(vector<double> &x, int n)
{
	int i, j;
	double key;
	for (i = 1; i < n; i++)
	{
		key = x.at(i);
		j = i - 1;

		while (j >= 0 && x.at(j) > key)
		{
			x.at(j + 1) = x.at(j);
			j = j - 1;
		}
		x.at(j + 1) = key;
	}
}

void selectionSort(vector<double> &x, int n)
{
	int i, j, min_idx;

	for (i = 0; i < n - 1; i++)
	{
		min_idx = i;
		for (j = i + 1; j < n; j++)
			if (x.at(j) < x.at(min_idx))
				min_idx = j;

		swap(&x.at(min_idx), &x.at(i));
	}
}

void merge(vector<double> &x, int l, int m, int r)
{
	int i, j, k;
	int n1 = m - l + 1;
	int n2 = r - m;

	vector<double> L;
	vector<double> R;

	for (i = 0; i < n1; i++)
		L.push_back(x.at(l + i));
	for (j = 0; j < n2; j++)
		R.push_back(x.at(m + 1 + j));

	i = 0;
	j = 0;
	k = l;
	while (i < n1 && j < n2)
	{
		if (L[i] <= R[j])
		{
			x.at(k) = L[i];
			i++;
		}
		else
		{
			x.at(k) = R[j];
			j++;
		}
		k++;
	}

	while (i < n1)
	{
		x.at(k) = L[i];
		i++;
		k++;
	}

	while (j < n2)
	{
		x.at(k) = R[j];
		j++;
		k++;
	}
}

void mergeSort(vector<double> &x, int l, int r)
{
	if (l < r)
	{
		int m = l + (r - l) / 2;

		mergeSort(x, l, m);
		mergeSort(x, m + 1, r);

		merge(x, l, m, r);
	}
}

int partition(vector<double> &x, int low, int high)
{
	int pivot = x.at(high);
	int i = (low - 1);

	for (int j = low; j <= high - 1; j++)
	{
		if (x.at(j) <= pivot)
		{
			i++;
			swap(&x.at(i), &x.at(j));
		}
	}
	swap(&x.at(i + 1), &x.at(high));
	return (i + 1);
}

void quickSort(vector<double> &x, int low, int high)
{
	if (low < high)
	{
		int pi = partition(x, low, high);

		quickSort(x, low, pi - 1);
		quickSort(x, pi + 1, high);
	}
}

#endif