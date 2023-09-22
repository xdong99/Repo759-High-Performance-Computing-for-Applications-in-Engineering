#include "matmul.h"
#include <iostream>
#include <chrono>
#include <cstddef>
#include <vector>
#include <random>

using namespace std;
using namespace chrono;

int main(int argc, char *argv[]) {
	random_device rd;
	default_random_engine generator(rd()); 

	const double min = -1.0, max = 1.0; 

	uniform_real_distribution<double> dist(min, max);
	
	size_t n = 1024;
	
	double *A = new double[n*n];
	double *B = new double[n*n];
	auto result = new double[n * n]();
	
    // initialize arrays with random number
	for (size_t i = 0; i < n * n; i++) {
		A[i] = dist(generator);
		B[i] = dist(generator);
	}
	
    // initialize the vectors for mmul4
	vector<double> Avec, Bvec; 
	for (size_t i = 0; i < n * n; i++) {
		Avec.push_back(A[i]);
		Bvec.push_back(B[i]);
	}
	
	cout << n << endl;

	//test mmul1
	auto start = high_resolution_clock::now();
  	mmul1(A, B, result, n);
  	auto end = high_resolution_clock::now();

 	auto duration_sec = duration_cast<duration<double, std::milli>>(end - start);
  	cout << duration_sec.count() << endl;
 	cout << result[n * n - 1] << endl;
	
	//test mmul2
	delete[] result;
	result = new double[n * n]();
	start = high_resolution_clock::now();
  	mmul2(A, B, result, n);
  	end = high_resolution_clock::now();

 	duration_sec = duration_cast<duration<double, std::milli>>(end - start);
  	cout << duration_sec.count() << endl;
 	cout << result[n * n - 1] << endl;
	
	//test mmul3
	delete[] result;
	result = new double[n * n]();
	start = high_resolution_clock::now();
  	mmul3(A, B, result, n);
  	end = high_resolution_clock::now();

 	duration_sec = duration_cast<duration<double, std::milli>>(end - start);
  	cout << duration_sec.count() << endl;
 	cout << result[n * n - 1] << endl;
	
	//test mmul4
	delete[] result;
	result = new double[n * n]();
	start = high_resolution_clock::now();
  	mmul4(Avec, Bvec, result, n);
  	end = high_resolution_clock::now();

 	duration_sec = duration_cast<duration<double, std::milli>>(end - start);
  	cout << duration_sec.count() << endl;
 	cout << result[n * n - 1] << endl;
 	
 	//delete
 	delete[] A;
	delete[] B;
	delete[] result;
}