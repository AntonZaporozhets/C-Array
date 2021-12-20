#include <iostream>
#include <omp.h>
using namespace std;

int main()
{
    cout << "Input a size of array: ";
    int ARRAY_SIZE = 0;
    cin >> ARRAY_SIZE;
    cout << "Input a number of threads: ";
    int num_thread = 0;
    cin >> num_thread;
    int* arr = new int[ARRAY_SIZE];
    int thread;
    int sum = 0;
    for (int i = 0; i < ARRAY_SIZE; ++i)
    {
        arr[i] = i;
    }
    
    #pragma omp parallel for reduction (+:sum) num_threads(num_thread)
    for (int i = 0; i < ARRAY_SIZE; i++)
    {
        thread = omp_get_thread_num();
        sum += arr[i];
        printf("\n sum of thread %d = %d", thread, sum);
    }
    printf("\n ------------");
    printf("\n total sum = %d", sum);

    return 0;
}

