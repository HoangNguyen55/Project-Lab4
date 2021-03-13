#include <iostream>
#include <string>
#include <math.h>
#include <ctype.h>
#include <fstream>
#include <iomanip>
using namespace std;

string name;
char input;

void gui(), lab2(), lab3();

int main()
{
    cout<<"Enter your name: \n";
    cin>>name;
    cout<<"Hello "<<name<<", please select the service:\n";
    gui();

    return 0;
}

void gui()
{
    cout<<  "A: Investment projection\n"
        <<  "B: Retirement planning\n"
        <<  "C: Mortgage\n" 
        <<  "D: College fund\n"
        <<  "E: Exit\n";

    cin>>input;
    input=tolower(input);

    switch (input)
    {
    case 'a':
        lab2();
        break;
    case 'b':
        lab3();
        break;
    case 'c' || 'd':
        cout<<"Service coming soon.\n";
        break;
    case 'e':
        cout<<"Thank you\n";
    default:
        cout<<"Input Invalid\n";
        gui();
        break;
    }
}

void lab2()
{
    //normal number
    double shares, pricePshare;
    //percents
    double comsFee, avgAnnualReturn;
    //no input
    double totalPaidNoComs, totalComsFee, totalPaid, totalTenYears;
    cout << "How many shares have been bought: \n";
    cin >> shares;
    cout << "Price per share: \n";
    cin >> pricePshare;
    cout << "Commission fee for each transaction(In percentage): \n";
    cin >> comsFee;
    cout << "Average annual return(In percentage): \n";
    cin >> avgAnnualReturn;

    totalPaidNoComs = shares*pricePshare;
    cout << "The amount you paid for the stock alone (without the commission): " << totalPaidNoComs << "\n";
    totalComsFee = (comsFee/100) * totalPaidNoComs;
    cout << "The amount of the commission fee: " << totalComsFee << "\n";
    totalPaid = totalComsFee + totalPaidNoComs;
    cout << "The total amount you paid(Coms fee incl): " << totalComsFee + totalPaidNoComs << "\n";
    totalTenYears = totalPaidNoComs * pow(1 + avgAnnualReturn/100, 10);
    cout << "After 10 years, all of your shares will worth: " << totalTenYears << "\n";

}

void lab3()
{
    double N_shares, P_shares, P_commission, A_return, Year;
    double totalPaidNoComs, totalComsFee, totalPaid, totalYears;
    char input;

    ifstream txt_input ("sample.txt");
    if(!txt_input)
    {
      cout << "Error file can't be open\n";
    }
    txt_input >> N_shares;
    txt_input >> P_shares;
    txt_input >> P_commission;
    txt_input >> A_return;
    txt_input >> Year;
    txt_input.close();

    totalPaidNoComs = N_shares*P_shares;
    cout << "The amount you paid for the stock alone (without the commission): " << totalPaidNoComs << "\n";
    totalComsFee = (P_commission/100) * totalPaidNoComs;
    cout << "The amount of the commission fee: " << totalComsFee << "\n";
    totalPaid = totalComsFee + totalPaidNoComs;
    cout << "The total amount you paid(Coms fee incl): " << totalComsFee + totalPaidNoComs << "\n";
    totalYears = totalPaidNoComs * pow(1 + A_return/100, Year);
    cout << "After 10 years, all of your shares will worth: " << totalYears << "\n";
    
    cout << "Would you like a receipt? Y/N\n";
    cin >> input;
    if(tolower(input) == 'y')
    {
        ofstream output("receipt.txt");
        if(!output){cout<<"Trying to write fail.";}
        output << setfill(' ') << setw(30) << left << "Hoang Nguyen";
        output << setfill('-') << setw(42) << "\n-";
        output << setfill(' ') << setw(31) << "\nTotal Stock: " << setprecision(2) << fixed << right << setw(1) << "$" << setw(10) << totalPaidNoComs << "\n";
        output << setw(30) << left << "Commission: " << right << setw(1) << "$" << setw(10) << totalComsFee << "\n";
        output << setw(30) << left << "Total amount: " << right << setw(1) << "$" << setw(10) << totalPaid << "\n";
        string str = "Net worth in " + to_string((int)Year) + " years: ";
        output << setw(30) << left << str << right << setw(1) << "$" << setprecision(2) << setw(10) << totalYears << "\n";
        cout << "Receipt printed";
        output.close();
    } 
    else
    {
        cout<<"Have a nice day";
    }
}