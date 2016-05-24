//
//  main.cpp
//  DecimalGenerator
//
//  Created by Anas Saeed on 10/13/14.
//  Copyright (c) 2014 Anas Saeed. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>
std::vector<std::string> generateDecimalNumbers(int input){
    std::vector<std::string> output;
    if (input == 1) {
        output.push_back("1");
        output.push_back("0");
        return output;
    }
    std::vector<std::string> pastResult = generateDecimalNumbers(input-1);
    for ( auto x : pastResult){
        std::string temp = x + "0";
        output.push_back(temp);
        
        if (x[x.length()-1] == '1') {
            continue;
        }
        
        temp = x + "1";
        output.push_back(temp);
    }
    std::sort(output.begin(), output.end());
    return output;
}
int main(int argc, const char * argv[])
{

    // insert code here...
    std::vector<std::string> result = generateDecimalNumbers(3);
    for ( auto x: result){
        std::cout <<x << " " ;
    }
    return 0;
}

