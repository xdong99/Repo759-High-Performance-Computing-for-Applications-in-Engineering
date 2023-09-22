#include "convolution.h"
#include <cstdio>
#include <cstdlib>
#include <chrono>
#include <iostream>
#include <random>

using namespace std;
using namespace chrono;

int main(int argc, char *argv[]){
	size_t n = atoi(argv[1]);
	size_t m = atoi(argv[2]);

	// Seed the random number generator with a random device, 
    // reference: https://en.cppreference.com/w/cpp/numeric/random/random_device
	random_device rd;
	default_random_engine generator(rd()); 

	const float minImage = -10.0, maxImage = 10.0;
	const float minMask = -1.0, maxMask = 1.0;

	uniform_real_distribution<float> distIm(minImage, maxImage);
	uniform_real_distribution<float> distMa(minMask, maxMask); 

    // Create an n x n mask matrix and fill it with random float numbers between -10 and 10
    float* imageMatrix = new float[n * n];
    for (size_t i = 0; i < n * n; i++) {
        imageMatrix[i] = distIm(generator);
    }

    // Create an m x m mask matrix and fill it with random float numbers between -1.0 and 1.0
    float* maskMatrix = new float[m * m];
    for (size_t i = 0; i < m * m; i++) {
        maskMatrix[i] = distMa(generator);
    }
	
	float *output = new float[n*n];
	
	//timing for the convolution
  	auto start = high_resolution_clock::now();
  	convolve(imageMatrix, output, n, maskMatrix, m);
  	auto end = high_resolution_clock::now();

	
	auto duration_sec = duration_cast<duration<double, std::milli>>(end - start);
	cout << "Time taken by scan function: " << duration_sec.count() << " milliseconds" << endl;
	cout << "First element in output is " << output[0] << endl;
	cout << "Last element in output is " << output[n * (n-1)] << endl;
	
	//Done with the matrix then delete;
	delete[] imageMatrix;
	delete[] maskMatrix;
	delete[] output;
}