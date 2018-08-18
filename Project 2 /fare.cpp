#include <iostream>
#include <string>
using namespace std;


int main()
{
    string name;
    string type;
    double miles;
    double minutes;
    double total;
    
    cout<<"Customer Name: ";
    getline(cin, name);

    if (name=="")
    {
        cout<<"--- You must enter a customer name."<<endl;
        return 1;
    }
    
    cout<<"Miles to be driven: ";
    cin>>miles;
    
    if (miles<=0)
    {
        cout<<"--- The mileage must be positive."<<endl;
        return 1;
    }
    
    cout<<"Minutes to be driven: ";
    cin>>minutes;
    
    if (minutes<=0)
    {
        cout<<"--- The time must be positive."<<endl;
        return 1;
    }
    
    cout<<"Ride Type: ";
    cin.ignore(1000, '\n');
    getline(cin, type);
    
    if (type == "Br-UberXL")
    {
        miles=miles*1.55;
        minutes=minutes*0.30;
        total= miles + minutes +1.65;
        if (total<7.65)
            total=7.65;
    }
    else if (type == "Br-UberX")
    {
        miles=miles*0.90;
        minutes=minutes*0.15;
        total= miles + minutes +1.65;
        if (total<5.15)
            total=5.15;
    }
    else
    {
        cout<<"--- The ride type is not valid."<<endl;
        return 1;
    }
    
    cout.setf(ios::fixed);
    cout.precision(2);
    
    cout<<"--- The fare for "<<name<<" is $"<<total<<endl;
    
    return 0;

}
