#include <iostream>
#include <cstdio>
using namespace std;

int main(int argc, char *argv[]){
	// obtain first element and convert to int from string
	int x = atoi(argv[1]); 

	//print the first row of numbers
	for (int i = 0; i <= x; i++) {
		printf("%d ", i);
	}
	printf("\n");
	
	//print the second row of numbers
	for (int i = x; i >= 0; i--){
		cout << i << " ";
	}
	cout << endl;
}