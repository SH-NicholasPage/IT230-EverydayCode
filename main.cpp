#include <iostream>
#include <string>
#include "source.h"

using namespace std;

void runTests();
bool testMeanOfEvenNumbers();
bool testWordBuilder();
bool testWordBuilderTC();
bool testCountOnes();

template <typename T>
    concept Numeric = std::is_arithmetic_v<T>;//Is numeric

int main()
{
    runTests();
    return 0;
}

void runTests()
{
    const int TESTS = 1;
    int failedTests = 0;
    failedTests = (testMeanOfEvenNumbers()) ? failedTests + 1 : failedTests;
    testWordBuilder();
    testWordBuilderTC();
    failedTests = (testCountOnes()) ? failedTests + 1 : failedTests;


    //cout << "Correctness score: " << (TESTS - failedTests) << "/" << TESTS << endl;
}

template<Numeric T>
bool runEqTest(T num1, T num2, const string& testName, bool *failed)
{
    if(num1 != num2)
    {
        cerr << testName << " failed. Expected: " << num1 << " Actual: " << num2 << endl << flush;
        if(failed != nullptr)
        {
            *failed = true;
        }
        return false;
    }
    return true;
}

bool testMeanOfEvenNumbers()
{
    bool failed = false;

    int array1[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int array1Length = 9;
    double array1Mean = 5;
    runEqTest(array1Mean, meanOfEvenNumbers(array1, array1Length), "testMeanOfEvenNumbers", &failed);
    int array2[] = {2, 4, 6, 8, 10};
    int array2Length = 5;
    double array2Mean = 6;
    runEqTest(array2Mean, meanOfEvenNumbers(array2, array2Length), "testMeanOfEvenNumbers", &failed);
    int array3[100];
    int array3Length = 100;

    for (int i = 0; i < 100; i++)
    {
        array3[i] = i + 1;
    }

    double array3Mean = 51;
    runEqTest(array3Mean, meanOfEvenNumbers(array3, array3Length), "testMeanOfEvenNumbers", &failed);
    int array4[50];
    int array4Length = 50;

    for(int i = 0; i < 50; i++)
    {
        array4[i] = i * i * 3;
    }
    double array4Mean = 2352;
    runEqTest(array4Mean, meanOfEvenNumbers(array4, array4Length), "testMeanOfEvenNumbers", &failed);
    int array5[] = {1, 3, 5, 7, 9, 11, 13, 15, 17, 19};
    int array5Length = 10;
    double array5Mean = 0;
    runEqTest(array5Mean, meanOfEvenNumbers(array5, array5Length), "testMeanOfEvenNumbers", &failed);

    if(failed == false)
    {
        cout << "testMeanOfEvenNumbers passed!" << endl << endl << flush;
    }

    return failed;
}

bool testWordBuilder()
{
    char letters[] = {'a', 'b', 'c', 'd', 'e'};
    size_t returnSize = 0;
    string* words = wordBuilder(letters, 5, &returnSize);
    cout << "You returned the following words: " << endl << flush;

    for (int i = 0; i < returnSize; i++)
    {
        std::cout << words[i];

        if(i < returnSize - 1)
        {
            cout << ", " << flush;
        }
    }

    cout << endl << endl << flush;

    delete[] words;

    return true;
}

bool testWordBuilderTC()
{
    char letters[] = {'a', 'b', 'c', 'd'};
    size_t returnSize = 0;
    string* words = wordBuilderTC(letters, 5, &returnSize);
    cout << "You returned the following three-letter words: " << endl << flush;

    for (int i = 0; i < returnSize; i++)
    {
        std::cout << words[i];

        if(i < returnSize - 1)
        {
            cout << ", " << flush;
        }
    }

    cout << endl << endl << flush;

    delete[] words;

    return true;
}

bool testCountOnes()
{
    //Create a 2-dimensional, staggered vector
    vector<vector<int>> array;
    array.push_back(vector<int>());
    array.push_back(vector<int>());
    array.push_back(vector<int>());
    array[0] = {0, 1, 1, 1, 0};
    array[1] = {0, 1, 0, 1, 0, 1};
    array[2] = {1, 0};
    size_t ones = 7;
    size_t count = countTheOnes(array);
    bool failed = false;
    runEqTest(ones, count, "testCountOnes", &failed);

    if(failed == false)
    {
        cout << "testCountOnes passed!" << endl << endl << flush;
    }

    return failed;
}