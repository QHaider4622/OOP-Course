/******************************************************************************
Assignment 1: OOP Sprig 2021
In this assignment you are given a main function that uses
some array functions.

Complete the code of these function such that main can work properly.
Expected output of main is given along the lines
*******************************************************************************/

#include <iostream>
using namespace std;

/*complete the header of following functions by specifying return type and
paramters. Use const where ever function doesnt need to change the data.
In all functions you have to deallocate the array or part of array that is not going
to be used.

Define the complete functions after main.
All the functions work with integer arrays
*/


/*The function takes a size and create and allocated dynamic
integer array of that size and returns the addressd of thae array*/
int* allocate_array(const int size);

/*This function take dynamic array as input and deallocates it
and changes the pointer of array to nullptr*/
void deallocate_array(int*& array);

/*This function takes an array as input and doubles its size,
the current elements are copies to first half of the new
bigger array. Note that the input array is doubled, size param should
also be doubled. Default value in 2nd half can be -1 */
void double_the_array(int*& arrayptr, int& size);

/*This functions take the array as input and reduce the size to half
element of only first half are retained. Note that the input array
is halfed. Size param should also be halfed*/
void half_the_array(int*& arrayptr, int& size);

/*This function takes any array, start index and end index as input
and returns a copy of slice of array from start index to end index.
Input array should not be effected.*/
int* slice_of_array(int* arrayptr, int size, int si, int ei, int& slice_size);

/*This function takes an array as input and give the mean of
numbers of array*/
double mean_array(int* arrayptr, int size);

/*This function takes two arrays and their sizes
and return's True if both have the same elements
in the same order else return false. If the size
of both arrays is not the same return False*/
bool compare_array(const int* const array1, const int* const array2, const int  size1, const int size2);

/*This function takes two arrays and their size and
returns a new array the is concatenation of both. */
int* concatenate_arrays(const int const* array1, const int const* array2, const int size1, const int size2, int& csize);

/*This function takes an array and sorts its inplace
sort inplace means sorting the input array, not creating its copy*/
void sort_array(int* const arrayptr, int size);

/*This function take and array and returns it's sorted copy
orignal input array should not be effeected
Hint: you can use sort array function in this function*/
int* sorted_copy(const int const* arrayptr, const int size);

/*This function takes an array and returns a new array containing only
distinct elements of input array. Original array should not be changed
It also returns the size of new array*/
int* distinct_copy(const int const* arrayptr, const int size, int& dsize);

/*This function takes an array deletes the redudant elements from it
So the input array will not have only distinct value. This function is
different from distinct_copy function, here input array is changed.*/
void distinct_array(int*& arrayptr, int& size);

/*this function takes an array as input; and a number and checkes
if number exists in array. If yes, return True else return false*/
bool exists(int* arrayptr, int size, int number);

/*takes a pointer as input and return true if pointer is NULL of nullptr
else false*/
bool is_nullptr(int* arrayptr);

/*Function to print an array*/
void print_array(const int* p, int size)
{
    cout << "Array Size: " << size << "\t" << "Elements {";
    if (size <= 0)
        cout << "}" << endl;
    else
    {
        for (int i = 0; i < size - 1; i++)
            cout << p[i] << ", ";
        cout << p[size - 1] << "}" << endl;
    }
}


int main()
{
    // Your function  should be written such that the main code 
    // can run and will give the exact output as shown
    //Main function also serves the purpose of sample runs of each function


    int* my_array1 = allocate_array(50);
    if (is_nullptr(my_array1))
        cout << "my_array1 is nullptr" << endl;
    else
        cout << "my_array1 is not nullptr" << endl;
    // OUTPUT  my_array1 is not nullptr

    print_array(my_array1, 5);
    // OUTPUT Array Size: 50       Elements {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}

    deallocate_array(my_array1);
    if (is_nullptr(my_array1))
        cout << "my_array1 is nullptr" << endl;
    else
        cout << "my_array1 is not nullptr" << endl;
    // OUTPUT my_array1 is nullptr


/*Double and half the array */
    int my_array_size = 10;
    int* my_array =
        new int[my_array_size] { 5, 6, 7, 8, 10, 11, 12, 34, 16, 14 };
    print_array(my_array, my_array_size);
    // OUTPUT Array Size: 10  Elements {5, 6, 7, 8, 10, 11, 12, 34, 16, 14}

    double_the_array(my_array, my_array_size);
    print_array(my_array, my_array_size);
    //OUTPUT Array Size: 20  Elements {5, 6, 7, 8, 10, 11, 12, 34, 16, 14, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1}
    my_array[14] = 100;
    print_array(my_array, my_array_size);
    //OUTPUT Array Size: 20  Elements {5, 6, 7, 8, 10, 11, 12, 34, 16, 14, -1, -1, -1, -1, 100, -1, -1, -1, -1, -1}
    half_the_array(my_array, my_array_size);
    print_array(my_array, my_array_size);
    //OUTPUT Array Size: 10   Elements {5, 6, 7, 8, 10, 11, 12, 34, 16, 14}

/*Slice of array */
    int my_slice_size = 0;
    int* my_slice =
        slice_of_array(my_array, my_array_size, 3, 5, my_slice_size);
    print_array(my_array, my_array_size);
    //OUTPUT Array Size: 10    Elements {5, 6, 7, 8, 10, 11, 12, 34, 16, 14}
    print_array(my_slice, my_slice_size);
    //OUTPUT Array Size: 3     Elements {8, 10, 11}

/*mean of array */
    double mean = mean_array(my_array, my_array_size);
    cout << "mean= " << mean << endl;
    // OUTPUT 12.3


/* Concat arrays */
    int concat_array_size = 0;
    int my_array2_size = 3;
    int* my_array2 = new int[my_array2_size] { 10, 5, 6 };

    print_array(my_array, my_array_size);
    //OUTPUT Array Size: 10 Elements {5, 6, 7, 8, 10, 11, 12, 34, 16, 14}

    print_array(my_array2, my_array2_size);
    // OUTPUT Array Size: 3 Elements {10, 5, 6}



    int* concat_array =
        concatenate_arrays(my_array, my_array2, my_array_size, my_array2_size,
            concat_array_size);

    print_array(my_array, my_array_size);
    // OUTPUT Array Size: 10 Elements {5, 6, 7, 8, 10, 11, 12, 34, 16, 14}


    print_array(my_array2, my_array2_size);
    //OUTPUT  Array Size: 3   Elements {10, 5, 6}
    print_array(concat_array, concat_array_size);
    // OUTPUTArray Size: 13   Elements {5, 6, 7, 8, 10, 11, 12, 34, 16, 14, 10, 5, 6}


/*Compare array */
    cout << compare_array(my_array, my_array2, my_array_size, my_array2_size) << endl;
    //OUTPUT  0
    cout << compare_array(my_array, my_array, my_array_size, my_array_size) << endl;
    //OUTPUT  1

/*Sort arrays */
    print_array(my_array2, my_array2_size);
    //OUTPUT Array Size: 3  Elements {10, 5, 6}
    sort_array(my_array2, my_array2_size);
    print_array(my_array2, my_array2_size);
    //OUTPUT Array Size: 3 Elements {5, 6, 10}


    print_array(my_array, my_array_size);
    //OUTPUT Array Size: 10  Elements {5, 6, 7, 8, 10, 11, 12, 34, 16, 14}
    int* my_array_sorted = sorted_copy(my_array, my_array_size);
    print_array(my_array, my_array_size);
    //OUTPUT Array Size: 10       Elements {5, 6, 7, 8, 10, 11, 12, 34, 16, 14}
    print_array(my_array_sorted, my_array_size);
    //OUTPUT  Array Size: 10       Elements {5, 6, 7, 8, 10, 11, 12, 14, 16, 34}


/*Exists */
    cout << exists(my_array, my_array_size, 1000) << endl;	//OUTPUT 0
    cout << exists(my_array, my_array_size, 34) << endl;	// OUTPUT 1

    /*Distinct */
    int my_array3_size = 6;
    int* my_array3 = new int[my_array3_size] { 44, 6, 7, 6, 7, 5 };

    print_array(my_array3, my_array3_size);
    // OUTPUT Array Size: 6    Elements {44, 6, 7, 6, 7, 5}  
    int distinct_myarray3_copy_size = 0;
    int* distinct_myarray3_copy =
        distinct_copy(my_array3, my_array3_size, distinct_myarray3_copy_size);
    print_array(my_array3, my_array3_size);
    // OUTPUT Array Size: 6     Elements {44, 6, 7, 6, 7, 5}
    print_array(distinct_myarray3_copy, distinct_myarray3_copy_size);
    //OUTPUT Array Size: 4  Elements {44, 6,  7,  5}

    distinct_array(my_array3, my_array3_size);
    print_array(my_array3, my_array3_size);
    //OUTPUT Array Size: 4     Elements {44, 6,  7,  5}

}


// Write the complete functions here
int* allocate_array(const int size)
{
    int* arrayptr = new int[size];
    return arrayptr;
}

void deallocate_array(int*& array)
{
    delete[]array;
    array = nullptr;
}

void double_the_array(int*& arrayptr, int& size)
{
    int last_size = size;
    size = size * 2;
    int* newarray = new int[size];
    for (int i = 0; i < size; i++)
    {
        if (i < last_size)
        {
            newarray[i] = arrayptr[i];
        }
        else if (i >= last_size)
        {
            newarray[i] = 1;
        }
    }
    delete[]arrayptr;
    arrayptr = newarray;
    newarray = nullptr;
    delete[]newarray;
}

void half_the_array(int*& arrayptr, int& size)
{
    int lastsize = size;
    size = size / 2;
    int* newarray = new int[size];
    for (int i = 0; i < size; i++)
    {
        newarray[i] = arrayptr[i];
    }
    delete[]arrayptr;
    arrayptr = newarray;
    newarray = nullptr;
    delete[]newarray;
}

int* slice_of_array(int* arrayptr, int size, int si, int ei, int& slice_size)
{
    slice_size = ei - si + 1;
    int* newarray = new int[slice_size];
    int count = 0;
    for (int i = si; i <= ei; i++)
    {
        newarray[count] = arrayptr[i];
        count++;
    }
    return newarray;
}

double mean_array(int* arrayptr, int size)
{
    double sum = 0, mean = 0;
    for (int i = 0; i < size; i++)
    {
        sum = sum + arrayptr[i];
    }
    mean = sum / size;
    return mean;
}

bool compare_array(const int* const array1, const int* const array2, const int  size1, const int size2)
{

    if (size1 != size2)
    {
        return false;
    }
    else if (size1 == size2)
    {
        for (int i = 0; i < size1; i++)
        {
            if (array1[i] != array2[i])
            {
                return false;
            }
        }
    }
    return true;

}

int* concatenate_arrays(const int const* array1, const int const* array2, const int size1, const int size2, int& csize)
{
    csize = size1 + size2;
    int* newarray = new int[csize];
    int count = 0;
    for (int i = 0; i < size1; i++)
    {
        newarray[count] = array1[i];
        count++;
    }
    for (int i = 0; i < size2; i++)
    {
        newarray[count] = array2[i];
        count++;
    }
    return newarray;
}

void sort_array(int* const arrayptr, int size)
{
    for (int i = 0; i < size - 1; i++)
    {
        for (int j = 0; j < size - i - 1; j++)
        {
            if (arrayptr[j] > arrayptr[j + 1])
            {
                swap(arrayptr[j], arrayptr[j + 1]);
            }
        }
    }
}

int* sorted_copy(const int const* arrayptr, const int size)
{
    int* newarray = new int[size];
    for (int i = 0; i < size; i++)
    {
        newarray[i] = arrayptr[i];
    }
    sort_array(newarray, size);
    return newarray;
}

int* distinct_copy(const int const* arrayptr, const int size, int& dsize)
{
    int* newarray = new int[size];
    int count = 0;
    for (int i = 0; i < size; i++)
    {
        if (exists(newarray, size, arrayptr[i]) == false)
        {
            newarray[count] = arrayptr[i];
            count++;
        }
    }
    int* copyarray = new int[count];
    for (int i = 0; i < count; i++)
    {
        copyarray[i] = newarray[i];
    }
    dsize = count;
    delete[] newarray;
    newarray = nullptr;
    return copyarray;
}

void distinct_array(int*& arrayptr, int& size)
{
    int* newarray = new int[size] {0};
    int count = 0;
    for (int i = 0; i < size; i++)
    {
        if (exists(newarray, size, arrayptr[i]) == false)
        {
            newarray[count] = arrayptr[i];
            count++;
        }
    }
    delete[]arrayptr;
    arrayptr = nullptr;
    arrayptr = new int[count];
    for (int i = 0; i < count; i++)
    {
        arrayptr[i] = newarray[i];
    }
    size = count;
    delete[]newarray;
    newarray = nullptr;
}


bool exists(int* arrayptr, int size, int number)
{
    for (int i = 0; i < size; i++)
    {
        if (arrayptr[i] == number)
        {
            return true;
        }
    }
    return false;
}

bool is_nullptr(int* arrayptr)
{
    if (arrayptr == nullptr)
    {
        return true;
    }
    else
    {
        return false;
    }
}