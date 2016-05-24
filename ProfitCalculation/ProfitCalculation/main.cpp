//
//  main.cpp
//  ProfitCalculation
//
//  Created by Anas Saeed on 19/08/2014.
//  Copyright (c) 2014 Anas Saeed. All rights reserved.
//

#include <iostream>
void run();
//int first = fa
void run(){
    long last_month_units, last_month_cost, last_month_cost_per_unit;
    std::cout <<"Please enter the last months  in units:    " ;
//    std::cout << "Please enter the number of units:   ";
    std::cin >> last_month_units;
    std::cout <<"\nPlease enter the last months cost of production in PKR:  ";
    std::cin >> last_month_cost;
    last_month_cost_per_unit = last_month_cost/last_month_units;
    //
    long current_month_units, current_month_cost, current_month_cost_per_unit, units_unsold;
    std::cout << "\nPlease enter the current months production in units:    ";
    std::cin >> current_month_units;
    std::cout <<"\nPlease enter the currents months cost of production in PKR:  ";
    std::cin >> current_month_cost;
    current_month_cost_per_unit = current_month_cost/ current_month_units;
    std::cout <<"\nPlease enter the units unsold from last month in units:  ";
    std::cin >> units_unsold;
    long sold_units, sale_price;
    std::cout <<"\nPlease enter the number of units sold in units:   ";
    std::cin >> sold_units;
    std::cout <<"\nPlease enter the price of a unit in PKR:    ";
    std::cin >> sale_price;
    // the actual calculating
    long profit, temp;
    if (sold_units < units_unsold) {
        profit = sold_units*sale_price;
        profit = profit -sold_units*last_month_cost_per_unit;
    }else{
        
        profit = units_unsold*sale_price;
        profit = profit - units_unsold*last_month_cost_per_unit;
        sold_units = sold_units -units_unsold;
        temp = current_month_units - sold_units;
        profit = profit + sold_units*sale_price;
        profit = profit - sold_units*current_month_cost_per_unit;
    }
    if (profit >0) {
        std::cout << "The profit is in PKR :";
        std::cout << profit;
    } else{
        profit = -profit;
        std::cout <<"The loss is in PKR :";
        std::cout << profit;
    }
    std::cout <<"\nRunning again\n\n\n\n\n\n\n\n\n" << std::endl;
    run();
}
int main()
{
    std::cout <<"Welcome to Profit Calculation Program. Hope you enjoy it." << std::endl <<"Regards, Anas Saeed" << std::endl;
    run();
    return 0;
}

