#include "scan.h"
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <chrono>
#include <random>

using namespace std;
using namespace chrono;

int main(int argc, char *argv[]){

	(void)argc;
	
	// Seed the random number generator with a random device, 
    // reference: https://en.cppreference.com/w/cpp/numeric/random/random_device
	random_device rd;
	default_random_engine generator(rd()); 

    // Specify the range for the random value generator
	const float min = -1.0, max = 1.0; 

	// Produces uniformly distributed random floating-point values,
    // reference: https://en.cppreference.com/w/cpp/numeric/random/uniform_real_distribution
	uniform_real_distribution<float> distribution(min, max);
	
    // n is read as command line argument
	size_t n = atol(argv[1]);

    // Allocate memory for the two arrays both of n float values
	float *arr = (float*)malloc(n * sizeof(float));
	float *output = (float*)malloc(n * sizeof(float));
	
    // Randomly generate the input array
	for (size_t i = 0; i < n; i++) {
		arr[i] = distribution(generator);
	}
	
    // Scan the array and calculate time taken,
    // reference: timing.md from ME759-2023
    high_resolution_clock::time_point start;
    high_resolution_clock::time_point end;
    duration<double, milli> duration_sec;

	start = high_resolution_clock::now();
	scan(arr, output, n);
	end = high_resolution_clock::now();
	
	// Get time used for doing the scan
	duration_sec = duration_cast< duration<double, milli> >(end - start);

    // Output
	cout << "Time taken by scan function: " << duration_sec.count() << " milliseconds" << endl;
	cout << "First element in output is " << output[0] << endl;
	cout << "Last element in output is " << output[n-1] << endl;
	
    // Deallocates memory
	free(arr);
	free(output);
}