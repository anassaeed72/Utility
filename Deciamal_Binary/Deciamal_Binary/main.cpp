//
//  main.cpp
//  Deciamal_Binary
//
//  Created by Anas Saeed on 22/05/2014.
//  Copyright (c) 2014 Anas Saeed. All rights reserved.
//
#include <iostream>
#include <vector>
#include <fstream>
int power(int one, int two);
int power(int one, int two){
    int output  = 1;
    for (int i = 0; i < two; i++) {
        output = output*one;
    }
    return output;
}
int binary_decimal(std::string in);
int binary_decimal(std::string in){
    int output = 0;
    std::string input;
    for (long i = in.length()-1 ;i >=0; i--) {
        input = input + in[i];
    }
    int index = 0;
    for ( auto x: input){
        
        if (x =='0') {
            index++;
            continue;
        }
        output = output + power(2, index);
        index++;
    }
    std::cout << output;
    return output;
}
std::string decimal_binary(int in);
std::string decimal_binary(int in){
    std::string output;
    while (in > 0) {
        if (in%2 == 1) {
            output = output + "1";
        }else if (in%2 == 0){
            output = output + "0";
        }
        in = in/2;
        
    }
    std::string dummy;
    for (long i = output.length()-1 ;i >=0; i--) {
        dummy = dummy + output[i];
    }
    std::cout << dummy;

    return dummy;
}
bool palindrome(std::string input);
bool palindrome(std::string input){
    std::string real;
    for (int i = input.length()-1; i >= 0; i--) {
        real = real + input[i];
    }
    unsigned int index = 0;
    for ( auto x: input){
        if (x != real[index]) {
            return false;
        }
        index++;
    }
    return true;
}
bool anagram(std::string input, std::string two);
bool anagram(std::string one, std:: string two){
    if (one.length() != two.length()) {
        return false;
    }
    unsigned int index = 0;
    int num = 0;
    for ( auto x:one){
        if (x == two[index]) {
            num++;
        }
        index++;
    }
    if (num == one.length()) {
        return false;
    }
    int a[26];
    int b[26];
    for ( auto x: one){
        x = x -'a';
        int c = (int)x;
        a[c]++;
    }
    for ( auto x: two){
        x = x -'a';
        int c = (int)x;
        b[c]++;
    }
    num = 0;
    for (int i = 0; i < 26; i++) {
        if (a[i] == b[i]) {
            num++;
        }
    }
    if (num == 26) {
        return true;
    }
    return false;
}
char single(int in);
char single(int in){
    if (in == 0) {
        return '0';
    }
    if (in == 1) {
        return '1';
    }
    if (in == 2) {
        return '2';
    }
    if (in == 3) {
        return '3';
    }
    if (in == 4) {
        return '4';
    }
    if (in == 5) {
        return '5';
    }
    if (in == 6) {
        return '6';
    }
    if (in == 7) {
        return '7';
    }
    if (in == 8) {
        return '8';
    }
    return '9';
}
int singlely(char in);
int singlely(char in){
    if (in =='0') {
        return 0;
    }
    if (in =='1') {
        return 1;
    }
    if (in =='2') {
        return 2;
    }
    if (in =='3') {
        return 3;
    }
    if (in =='4') {
        return 4;
    }
    if (in =='5') {
        return 5;
    }
    if (in =='6') {
        return 6;
    }
    if (in =='7') {
        return 7;
    }
    if (in =='8') {
        return 8;
    }
    return 9;
}
std::string reverser(std::string in);
std::string reverser(std::string in){
    std::string output;
    for (int i = in.length()-1; i>=0; i--) {
        output = output + in[i];
    }
    return output;
}
std::string int_string(int input);
std::string int_string(int input){
    std::string output;
    int num = 10;
    if (input == 0) {
        return "0";
    }
    while (input >0) {
        int dummy = input%num;
        input = input/num;
//        num = num*10;
        output = output + single(dummy);
    }
    return reverser(output);
}
std::string int_string();
std::string int_string(){
    int input;
    std::cin >> input;
    return int_string(input);
}
int string_int(std::string input);
int string_int(std::string input){
    int out = 0;
    input = reverser(input);
    int num = 1;
    for ( auto x: input){
        out = out + singlely(x)*num;
        num = num*10;
    }
    return out;
}
int string_int();
int string_int(){
    std::string input;
    std::cin >> input;
    return string_int(input);
}
std::vector<std::string> string_split(std::string input);
std::vector<std::string> string_spit(std::string input){
    std::vector<std::string> output;
    std::string onetimer;
    for ( auto x: input){
        if (x == ' ') {
            output.push_back(onetimer);
            onetimer ="";
            continue;
        }
        onetimer = onetimer + x;
    }
    output.push_back(onetimer);
    return output;
}
std::string reverse_words(std::string input);
std::string reverse_words(std::string input){
    std::vector<std::string> vec = string_spit(input);
    std::vector<std::string> real;
    for (int i = vec.size()-1; i >=0; i--) {
        real.push_back(vec[i]);
    }
    int index = 0;
    std::string output;
    for ( auto x: real){
        index++;
        output = output + x;
        if (index == real.size()) {
            continue;
        }
        output = output + " ";
    }
    return output;
}
std::string password(int num){
    std::string pass;
    for (int i = 0; i < num; i++) {
        int one = rand()%127;
        std::cout << one << " ";
        char onec = static_cast<char>(one);
        pass = pass + onec;
    }
    return pass;
}
std::vector<std::string> cellphone_gen(std::string num);
std::vector<std::string> cellphone_gen(std::string num){
    std::vector<std::string> output;
    std::ofstream myfile;
    myfile.open ("example.txt");
    for (int i = 0; i < 1000; i++) {
        std::string temp = int_string(i);
        if (temp.length() == 1) {
            temp = "0" + temp;
        }
        if (temp.length() == 2) {
            temp = "0" + temp;
        }
        for (int j =0 ; j < 10000; j++) {
            std::string inner = int_string(j);
            if (inner.length() == 1) {
                inner = "0"+ inner;
            }
            if (inner.length() == 2) {
                inner = "0"+ inner;
            }
            if (inner.length() == 3) {
                inner = "0"+ inner;
            }
            inner = num +"-"+ temp + "-" + inner;
            std::cout << inner << " ";
            myfile << inner << std::endl;
            output.push_back(inner);
        }
    }
    return output;
}
int increment(int input);
int increment(int input){
    return ++input;
}
int decrement(int input);
int decrement(int input){
    return --input;
}
bool areEqual(int a, int b);
bool areEqual(int a, int b){
    if (a == b) {
        return true;
    }
    return false;
}
int sign(int input);
int sign(int input){
    if (input > 0) {
        return 1;
    }
    if (input == 0) {
        return 0;
    }
    return -1;
}
int addition(int a, int b);
int addition(int a, int b){
    int count = 0;
    while (count != b) {
        a = increment(a);
        count = increment(count);
    }
    return a;
}
int subtraction(int a, int b);
int subtraction(int a, int b){
    int count = 0;
    while ( count != b) {
        a = decrement(a);
        count = increment(count);
    }
    return a;
}
int negation(int input);
int negation(int input){
    int count = 0;
    int count2 =0;
    int input_intial = input;
    while (count2 != input_intial) {
        if (count != input_intial) {
            count++;
        }else{
            count2++;
        }
        input = decrement(input);
    }
    return input;
}
int multiplication(int a, int b);
int multiplication(int a, int b){
    int ans = 0;
    int count = 0;
    while (count != b) {
        count = increment(count);
        ans =addition(ans,a);
    }
    return ans;
}
int divide(int a, int b);
int divide(int a , int b){
    int count = 0;
    while (sign(subtraction(a, b))==1) {
        a  = subtraction(a, b);
        count = increment(count);
    }
    return count;
}
int remainder(int a, int b);
int remainder(int a, int b){
    while (sign(subtraction(a, b))==1) {
        a  = subtraction(a, b);
    }

    return a;
}
std::string upper_lower(std::string input);
std::string upper_lower(std::string input){
    std::string output;
    for ( auto x: input){
        char temp = x - 32;
        output = output + temp;
    }
    return output;
}
std::string lower_upper(std::string input);
std::string lower_upper(std::string input){
    std::string output;
    for ( auto x: input){
        char temp = x + 32;
        output = output + temp;
    }
    return output;
}
std::string crypto_shift_right(std::string input, int num);
std::string crypto_shift_right(std::string input, int num){
    std::string output;
    for ( auto x: input){
        char temp = x + num;
        output  = output + temp;
    }
    return  output;
}
std::string crypto_shift_left(std::string input ,int num);
std::string crypto_shift_left(std::string input ,int num){
    return  crypto_shift_right(input ,-num);

}
double calculate_percentage(int number, int total);
double calculate_percentage(int number, int total){
    return number*100/total;
}
int calculate_numbers(int total, double percentage);
int calculate_numbers(int total, double percentage){
    int output = total*percentage;
    output = output/100;
    return output;
}
int calculate_total(int number, double percentage);
int calculate_total(int number, double percentage){
    int total = number*100;
    total = total/percentage;
    return total;
}
int calculate_number_from_percentage(int total, double percentage);
int calculate_number_from_percentage(int total, double percentage){
    int number;
    number = percentage*total;
    number = number/100;
    return number;
}
int main(int argc, const char * argv[])
{
//    cellphone_gen("0300");
    std::cout <<calculate_percentage(10, 20)  << " " << calculate_numbers(20, 80) << calculate_total(16, 80) << " " << calculate_number_from_percentage(20, 80);
    return 0;
}

