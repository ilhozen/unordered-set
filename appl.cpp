#include "UnorderSet.h"
#include <iostream>
using namespace std;

int main() {
    UnorderedSet mySet1, mySet2;
    mySet1.insert(5);
    mySet1.insert(10);
    mySet1.insert(15);
    mySet1.insert(18);
    mySet2.insert(10);
    mySet2.insert(2);
    mySet2.insert(5);
    UnorderedSet intersectionSet = mySet1.intersection(mySet2);
    UnorderedSet unionSet = mySet1.setUnion(mySet2);
    UnorderedSet differenceSet = mySet1.setDifference(mySet2);
    std::cout << "Intersection Set: ";
    intersectionSet.printSet();
    std::cout << "Union Set: ";
    unionSet.printSet();
    std::cout << "Difference Set (mySet1 - mySet2): ";
    differenceSet.printSet();
    return 0;

}