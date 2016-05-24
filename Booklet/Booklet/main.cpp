//
//  main.cpp
//  Booklet
//
//  Created by Anas Saeed on 10/3/14.
//  Copyright (c) 2014 Anas Saeed. All rights reserved.
//

#include <iostream>
#include <vector>
int roundPagesInBook(int totalPagesInBook){
    int remainder = totalPagesInBook%4;
    while (remainder != 0) {
        totalPagesInBook++;
        remainder = totalPagesInBook%4;
    }
    return totalPagesInBook;
}
int totalLeafletsInBook(int totalPagesInBook){
    int remainder = totalPagesInBook%4;
    while (remainder != 0) {
        totalPagesInBook++;
        remainder = totalPagesInBook%4;
    }
    return totalPagesInBook/4;
}
std::vector<int> pages(int totalPagesInBook, int number){
    std::vector<int> output;

    output.push_back(number*2 -1);
    output.push_back(number*2);
    int temp = totalPagesInBook - 2*(number-1);
    output.push_back(temp-1);
    output.push_back(temp);
    return output;
}
int main(int argc, const char * argv[])
{
    std::vector<int> result  = pages(12, 1);
    for (auto x: result){
        std::cout << x << " ";
    }
    std::cout <<std::endl;
    result  = pages(12, 2);
    for (auto x: result){
        std::cout << x << " ";
    }
    std::cout << std::endl;
    result  = pages(12, 3);
    for (auto x: result){
        std::cout << x << " ";
    }

    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}

