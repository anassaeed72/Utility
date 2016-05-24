//
//  main.cpp
//  HanoiTower
//
//  Created by Anas Saeed on 11/2/14.
//  Copyright (c) 2014 Anas Saeed. All rights reserved.
//

#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>
std::stack<int> one;
std::stack<int> two;
std::stack<int> three;
int totaldisks = 3;
bool insert(int spindle, int disk);
void intialize(){
    for (int i = totaldisks; i >0; i--) {
        insert(1, i);
    }
}
bool insert(int spindle, int disk){
    if (spindle == 1) {
        if (one.size() == 0) {
            one.push(disk);
            return true;
        }
        if (one.top() > disk) {
            one.push(disk);
            return true;
        }
        return false;
    }
    if (spindle == 2 ) {
        if (two.size() == 0) {
            two.push(disk);
            return true;
        }
        if (two.top() > disk) {
            two.push(disk);
            return true;
        }
        return false;
    }
    if (spindle == 3) {
        if (three.size() == 0) {
            three.push(disk);
            return true;
        }
        if (three.top() > disk) {
            three.push(disk);
            return true;
        }
        return false;
    }
    
    return false;
}
void printing(){
    int maxSize =std::max(three.size(), std::max(one.size(), two.size()));
    std::stack<int> oneTemp;
    std::stack<int> twoTemp;
    std::stack<int> threeTemp;
    if (maxSize == one.size()) {
        while (maxSize !=0) {
            if (maxSize <= one.size()) {
                int temp = one.top();
                one.pop();
                oneTemp.push(temp);
                std::cout << temp << " ";
            } else {
                std::cout << "  ";
            }
            if (maxSize <= two.size()) {
                int temp = two.top();
                two.pop();
                twoTemp.push(temp);
                std::cout << temp << " ";
            } else {
                std::cout <<"  ";
            }
            if (maxSize <= three.size() ) {
                int temp = three.top();
                three.pop();
                threeTemp.push(temp);
                std::cout << temp;
            }
            maxSize--;
            std::cout << std::endl;
        }
    }
    std::cout <<"A B C\n";
    while (oneTemp.empty() == false) {
        one.push(oneTemp.top());
        oneTemp.pop();
    }
    while (twoTemp.empty() == false) {
        two.push(twoTemp.top());
        twoTemp.pop();
    }
    while (threeTemp.empty() == false) {
        three.push(threeTemp.top());
        threeTemp.pop();
    }
}
void move(int from, int too){
    if (from == too) {
        return;
    }
    if (from == 1) {
        if (one.size() == 0) {
        } else{
            int temp = one.top();
            one.pop();
            bool checkForInsertion = insert(too, temp);
            
        }
    }
    if (from == 2) {
        if (two.size() > 0) {
            int temp = two.top();
            two.pop();
            bool checkForInsertion = insert(too, temp);
        }
    }
    if (from == 3) {
        if (three.size() > 0) {
            int temp = three.top();
            three.pop();
            bool checkForInsertion = insert(too, temp);
        }
    }
}
int main(int argc, const char * argv[])
{
    intialize();
    printing();
    move(1, 2);
    printing();
    move(2, 3);
    printing();
    // insert code here...
    return 0;
}

