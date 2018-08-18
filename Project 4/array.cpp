#include <iostream>
#include<string>

using namespace std;

  
{
    if (n <= 0) //weed out when n is not positive
        return -1;
    int min = 0;
    string mins = array[0];
    for (int yea = 1;yea<= n-1; yea++)
    {
        if (array[yea] < mins)
        {
            mins = array[yea]; //only when there is a new minimum, this line runs
            min = yea;
        }
    }
    return min;
}

int findLastOccurrence(const string array[], int n, string target)
{
    if (n <= 0) //weed out when n is not positive
        return -1;
    int ret = -1;
    for (int yea = 0;yea<= n-1; yea++)
    {
        if (array[yea] == target) //when the target is found, the position is updated
        {
            ret = yea;
        }
    }
    return ret;
}

int flipAround(string array[],int n)
{
    if (n < 0) //weed out when n is less than 0
        return -1;
    int m=n;
    string out[10000]; //creates large array to copy array into
    int number;
    if(n%2==1) //seperates even and odd n
        number = (n-1)/2;
    else
        number = n/2;
    for (int yea = 0;yea<n; yea++) //flips each string into new array
    {
        (out[m-1] = array[yea]);
        (out[yea] = array[m-1]);
        m--;
    }
    for  (int yea=0;yea<n;yea++) //copies new array back into old array
    {
        array[yea]=out[yea];
    }
    return number;
}

bool hasNoDuplicates(const string array[], int n)
{
    cout.setf(ios::boolalpha); //makes booleans "true" and "false"
    if (n <= 0) //weed out when n is not positive
        return -1;
    for (int yea = 0;yea<n-1; yea++)
    {
        for(int ok = yea+1; ok<=n-1; ok++)
            //for each position in the array, it checks every other position
        {
            if (array[yea] == array[ok])
                return false; //this line runs only when there is a duplicate
        }
    }
    return true;
}

void unionWithNoDuplicates(const string array1[], int n1, const string array2[], int n2, string resultingString[], int &resultingSize)
{
    cout.setf(ios::boolalpha); //makes booleans "true" and "false"
    resultingSize = 0;
    for (int yea = 0;yea<n1; yea++) //checks the first array for duplicates
    {
        bool check = true;
        for (int dog = 0;dog<resultingSize; dog++)
        {
            if (array1[yea]==resultingString[dog])//if there is a duplicate, it skips over that position
                check=false;
        }
        if (check)
        {
            resultingString[resultingSize] = array1[yea];
            resultingSize++;
        }
    }
    for (int yea = 0;yea<n2; yea++) //checks the second array for duplicates within resultingString
    {
        bool check = true;
        for (int dog = 0;dog<resultingSize; dog++)
        {
            if (array2[yea]==resultingString[dog])//if there is a duplicate, it skips over that position
                check=false;
        }
        if (check)
        {
            resultingString[resultingSize] = array2[yea];
            resultingSize++;
        }
    }
    if (n1<=0 || n2<=0) //weed out when n1 or n2 are not positive
        resultingSize = -1;
}

int shiftRight(string array[], int n, int amount, string placeholderToFillEmpties)
{
    if (n<0 || amount>n || amount <0) //weed out when n or amount is less than 0
        return -1;
    int q=n,m=0;
    for (int p = 0; p<amount;p++) //counts to amount and repeats the action (amount) times
    {
        array[q-1]=array[q-1-amount]; //replaces the last positions
        q--;
    }
    for (int p = 0; p<amount;p++)
    {
        array[m]=placeholderToFillEmpties; //fills up the empty spots
        m++;
    }
    return n-amount;
}

bool isInIncreasingOrder(const string array[], int  n)
{
    cout.setf(ios::boolalpha); //makes booleans "true" and "false"
    bool check = true;
    if (n<0) //weed out when n is less than zero
        check = false;
    for (int p=0;p<n-1;p++) //goes through every string from left to right except the last one
    {
        if (array[p]>=array[p+1])
            check= false;  //this line only runs if the next position is less than the previous one
    }
    if (n == 1 || n==0)
        check = true;
    return check;
}

int main()
{

}
