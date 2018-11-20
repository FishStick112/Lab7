// Matthew Sundberg
// COSC 2030
// 11-19-2018

#include "Lab7-msundber.h"
#include "winTimer.h"
#include <iostream>
#include <vector>
#include <algorithm>

using std::cin;
using std::cout;
using std::endl;
using std::vector;
using std::sort;

int main()
{
	vector<double> stl = getNums(2299000, 1, 500);
	vector<double> quick = getNums(600000, 1, 500);
	vector<double> bubble = getNums(16800, 1, 500);
	vector<double> insertion = getNums(24000, 1, 500);
	vector<double> selection = getNums(21000, 1, 500);
	vector<double> merge = getNums(520000, 1, 500);

	Timer time;
	
	time.start();
	sort(begin(stl), end(stl));
	time.stop();
	cout << "stl::sort : " << time() << " seconds." << endl;
	
	time.start();
	quickSort(quick, 0, 599999);
	time.stop();
	cout << "quick sort : " << time() << " seconds." << endl;
	
	time.start();
	bubbleSort(bubble, 16800);
	time.stop();
	cout << "bubble sort : " << time() << " seconds." << endl;
	
	time.start();
	insertionSort(insertion, 24000);
	time.stop();
	cout << "insertion sort : " << time() << " seconds." << endl;
	
	time.start();
	selectionSort(selection, 21000);
	time.stop();
	cout << "selection sort : " << time() << " seconds." << endl;
	
	
	time.start();
	mergeSort(merge, 0, 519999);
	time.stop();
	cout << "merge sort : " << time() << " seconds." << endl;
	

	system("pause");

	return 0;
}