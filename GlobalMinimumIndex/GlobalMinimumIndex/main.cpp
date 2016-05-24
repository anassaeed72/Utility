//
//  main.cpp
//  GlobalMinimumIndex
//
//  Created by Anas Saeed on 10/13/14.
//  Copyright (c) 2014 Anas Saeed. All rights reserved.
//

#include <iostream>
#include <vector>
int globalMinimum(std::vector<int> vector){
    int min = vector[0];
    for ( auto x: vector){
        if (x < min) {
            min = x;
        }
    }
    return min;
}
int globalMaximum(std::vector<int> vector){
    int max= vector[0];
    for ( auto x: vector){
        if (x >max) {
            max = x;
        }
    }
    return max;
}
int globalMinimumIndex(std::vector<int> vector){
    int min = vector[0];
    int index = 0;
    for (int i = 0; i < vector.size(); i++) {
        if (vector[i] < min) {
            index = i;
        }
    }
    return index;
}
int globalMaximumIndex(std::vector<int> vector){
    int max = vector[0];
    int index = 0;
    for (int i = 0; i < vector.size(); i++) {
        if (vector[i] > max) {
            index = i;
        }
    }
    return index;
}
int main(int argc, const char * argv[])
{

    std::vector<int> tester ={3, 4, 15, 20, 30, 70, 80, 120};
    std::cout << globalMinimumIndex(tester);
    return 0;
}

