#include <iostream>
#include <vector>

int main()
{
    using namespace std;

    vector<int> vect;
    for (int nCount=0; nCount < 6; nCount++)
        vect.push_back(nCount);

    vector<int> second(vect.begin(), vect.begin() );

    vector<int>::iterator it; // declare an read-only iterator
    it = second.begin(); // assign it to the start of the vector

    while (it != second.end()) // while it hasn't reach the end
    {
        cout << *it << " "; // print the value of the element it points to
        it++; // and iterate to the next element
    }

    cout << endl;
}