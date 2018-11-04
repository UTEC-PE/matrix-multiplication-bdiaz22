#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <thread>
#include <mutex>
#include <atomic>
#include <iomanip>

using namespace std;

#define SIZE 2
#define NUM_THREADS 4

int counter = 0;
mutex mtx;

int matrix1[SIZE][SIZE];
int matrix2[SIZE][SIZE];
int matrix3[SIZE][SIZE];
    
void multiply_matrix(void *arg){
	for (int i = 0; i < SIZE; ++i)
	{
		for (int j = 0; j < SIZE; ++j)
		{
			matrix3[i][j]= 0;
			for (int k = 0; k < SIZE; ++k)
			{
				matrix3[i][j] += matrix1[i][k] * matrix2[k][j];
			}
		}
		cout<<"\n";
	}
}

int main(int argc, char *argv[]) {
	srand(time(0));
    cout << "===========================================================" << endl;
    cout << "\tThreads" << endl;
    cout << "===========================================================" << endl << endl;
    
    for (int i = 0; i < SIZE; ++i)
	{
		for (int j = 0; j < SIZE; ++j)
		{
			matrix1[i][j] = rand()%10;
			matrix2[i][j] = rand()%10;
		}
	}


    cout<< "Matriz 1"<<"\n";

	for (int i = 0; i < SIZE; ++i)
	{
		for (int j = 0; j < SIZE; ++j)
		{
			cout << matrix1[i][j] << setw(3);
		}
		cout<<"\n";
	}
	
	cout << "\n";
	cout<< "Matriz 2"<<"\n";

	for (int i = 0; i < SIZE; ++i)
	{
		for (int j = 0; j < SIZE; ++j)
		{
			cout << matrix2[i][j] << setw(3); 
		}
		cout<<"\n";
	}	


    thread threads[NUM_THREADS];

    for (int i = 0; i < NUM_THREADS; i++) {
    	int *p;
    	threads[i] = thread(multiply_matrix,(void*)(p));	
        
    }

    for (int i = 0; i < NUM_THREADS; ++i) {
        threads[i].join();
    }

	cout << "\n";
	cout<< "Matriz 3"<<"\n";

	for (int i = 0; i < SIZE; ++i)
	{
		for (int j = 0; j < SIZE; ++j)
		{
			cout << matrix3[i][j] << setw(5);  
		}
		cout<<"\n";
	}

    return EXIT_SUCCESS;
}
