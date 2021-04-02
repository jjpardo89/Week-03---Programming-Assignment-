
// Including preprocessor directives
#include <iostream>
// to open, write, and close a file for the program to record
#include <fstream>
#include <string>
#include<algorithm>
#include<iomanip>
#include <locale>  

//to use cin and cout easily
using namespace std;

//Static Values defined as constants
const int FRAGILE_COST = 2;
//Constants for the BASE Shipping cost of each country
const int USA_BASE = 6;
const int USA_SECOND = 9;
const int USA_THIRD = 12;

const int CAN_BASE = 8;
const int CAN_SECOND = 12;
const int CAN_THIRD = 15;

const int AUS_BASE = 10;
const int AUS_SECOND = 14;
const int AUS_THIRD = 17;
//SATURN ADDED AS THE 4TH DESTINATION
const int SATURN_BASE = 1200;
const int SATURN_SECOND = 1600;
const int SATURN_THIRD = 2000;

//Main is always needed in C++ - start of the functions for the program
int main()

{
    //Making the file Order.txt
    ofstream file("Order.txt");

    // total_shipping - calculates the overall shipping with the order
    // shipping_cost is only the cost of the shipping
    // order_total is the user input of their order total without shipping
    float total_shipping = 0, order_total, shipping_cost = 0;

    //Top banner
    string item_name, destination;
    for (int i = 0; i < 50; i++)
        cout << ".";
    cout << "\nITCS 2530 - Programming Assignment for week #3\n";
    for (int i = 0; i < 40; i++)
        cout << ".";

    // Saving the top banner to the file Order.txt
    for (int i = 0; i < 40; i++)
        file << ".";
    file << "\nITCS 2530 - Programming Assignment for week #3\n";
    for (int i = 0; i < 40; i++)
        file << ".";

    // User input (and file write to) of the name of the order
    cout << "\nPlease enter the item name (no spaces).................:";
    file << "\nPlease enter the item name (no spaces).................:";
    cin >> item_name;
    file << item_name << endl;

    // Declaring fragileCost variable of "y" or "n" from the user
    char fragile;

    // Asking the user if the item is fragile
    cout << "Is the item fragile? (y=yes/n=no)..................:";
    file << "Is the item fragile? (y=yes/n=no)..................:";
    cin >> fragile;
    file << fragile << endl;


    //Calculating the cost of the shipping with (or without) fragile included
    if (fragile == 'y' || fragile == 'Y') { shipping_cost += FRAGILE_COST; }
    else if (fragile == 'n');
    else {

        //If the user makes an invalid entry (typing other than y or n)
        cout << "Invalid entry, exiting\nPress any key to continue . . .";
        file << "Invalid entry, exiting\nPress any key to continue . . .";
        getchar();

        file.close();

        return 0;

    }

    //Asks the user to enter their total of the order (not including fragile or shipping) - also writing it to the file Order.txt
    cout << "Please enter your order total.......................:";
    file << "Please enter your order total.......................:";
    cin >> order_total;
    file << order_total << endl;

    //New destination added - SATURN! User is selecting their desination
    cout << "Please enter destination on earth, or send to SATURN (usa/can/aus/sat)............:";
    file << "Please enter destination on earth, or send to SATURN (usa/can/aus/sat)............:";
    cin >> destination;
    file << destination << endl;

    // Function to calculate the shipping cost based on the input destination. Base shipping is defined as a constant. WITH SATURN!
    if (destination == "usa" || destination == "USA")
    {
        if (order_total <= 50) shipping_cost += USA_BASE;
        else if (order_total <= 100) shipping_cost += USA_SECOND;
        else if (order_total <= 150) shipping_cost += USA_THIRD;
    }
    else if (destination == "can" || destination == "CAN")
    {

        if (order_total <= 50) shipping_cost += CAN_BASE;
        else if (order_total <= 100) shipping_cost += CAN_SECOND;
        else if (order_total <= 150) shipping_cost += CAN_THIRD;
    }
    else if (destination == "aus" || destination == "AUS")
    {
        if (order_total <= 50) shipping_cost += AUS_BASE;
        else if (order_total <= 100) shipping_cost += AUS_SECOND;
        else if (order_total <= 150) shipping_cost += AUS_THIRD;
    }
    else if (destination == "sat" || destination == "SAT")
    {
        if (order_total <= 50) shipping_cost += SATURN_BASE;
        else if (order_total <= 100) shipping_cost += SATURN_SECOND;
        else if (order_total <= 150) shipping_cost += SATURN_THIRD;
    }
    else {

        cout << "Invalid entry, exiting\nPress any key to continue . . .";
        file << "Invalid entry, exiting\nPress any key to continue . . .";
        getchar();

        file.close();

        return 0;
    }

    //Totaling the cost so with destination shipping
    total_shipping += order_total;

    //Function to change the result's output into caps
    transform(destination.begin(), destination.end(), destination.begin(), ::toupper);
    transform(item_name.begin(), item_name.end(), item_name.begin(), ::toupper);

    //Calculating the total final order (order cost entered by the user, plus fragile fee if any, plus shipping based on destination and price)
    total_shipping += shipping_cost;

    //final output
    cout << "\nYour item is.................................." << item_name << endl;
    file << "\nYour item is.................................." << item_name << endl;

    // Output of the shipping cost
    //use of i/o manipulators fixed and setprecision
    cout << "Your shipping cost is........................." << "$" << fixed << setprecision(2) << shipping_cost << endl;
    file << "Your shipping cost is........................." << "$" << fixed << setprecision(2) << shipping_cost << endl;

    //Output of the destination being shiped to
    cout << "You are shipping to..........................." << destination << endl;
    file << "You are shipping to..........................." << destination << endl;

    //Output of the total with i/o manipulators to set the price correctly
    cout << "Your total shipping costs are................." << "$" << fixed << setprecision(2) << total_shipping << endl;
    file << "Your total shipping costs are................." << "$" << fixed << setprecision(2) << total_shipping << endl;
    cout << "" << endl;
    cout << "----------------------------------------------Thank you !" << endl;

    //closing the file Order.txt
    file.close();

    return 0;

}
