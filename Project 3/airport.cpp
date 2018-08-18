#include <iostream>
#include <string>
using namespace std;

bool isWellFormedAirportString (string commands)
{
    cout.setf(ios::boolalpha);
    
    bool status1;
    
    int m = 0;
    
    size_t length = commands.size();
    if (length == 0)
        return false;
    
    while (m < length)
    {
        char first = commands[0+m];
        char second = commands[1+m];
        
        if ((first == 'A'||first =='a') && (second == 'A'|| second=='a'))
            status1 = true;
        else if ((first == 'D'||first =='d') && (second == 'L'|| second=='l'))
            status1 = true;
        else if ((first == 'U'||first =='u') && (second == 'A'|| second=='a'))
            status1 = true;
        else if ((first == 'S'||first =='s') && (second == 'W'|| second=='w'))
            status1 = true;
        else if ((first == 'A'||first =='a') && (second == 'L'|| second=='l'))
            status1 = true;
        else if ((first == 'V'||first =='v') && (second == 'A'|| second=='a'))
            status1 = true;
        else
            status1 = false;
    
        if (status1 == false)
            return false;

        int n=2+m;
        
        while (commands[n]=='0')
        {
            n++;
            m++;
        }
    
        while ((n<(5+m))&&((commands[n] != '+')&&(commands[n] != '-')))
        {

            if (commands[n] != '0' && commands[n] != '1' && commands[n] != '2' && commands[n] != '3' && commands[n] != '4' && commands[n] != '5' && commands[n] != '6' && commands[n] != '7' && commands[n] != '8' && commands[n] != '9')
            {
                return false;
            }
            n++;
        }
        
        if (commands[2+m]== '0')
            return false;
        else if (n == 2+m)
            return false;
        else if (n == 5+m)
        {
            if (commands[5+m] == '+' || commands[5+m] == '-')
                n=n;
            else
            {
                return false;
            }
            
        }
        
        int a=n+1;
        
        if (commands[a]=='0')
        {
        while(commands[a] == '0')
        {
            n++;
            a++;
        }
        
        if (commands[a] == '0' || commands[a] == '1' || commands[a] == '2' || commands[a] == '3' || commands[a] == '4' || commands[a] == '5' || commands[a] == '6' || commands[a] == '7' || commands[a] == '8' || commands[a] == '9')
        {
            n=n;
        }
        else
        {
            n--;
            a--;
        }
        }
        
        while ((a<(4+n))&&(commands[a] == '0' || commands[a] == '1' || commands[a] == '2' || commands[a] == '3' || commands[a] == '4' || commands[a] == '5' || commands[a] == '6' || commands[a] == '7' || commands[a] == '8' || commands[a] == '9'))
            {
            a++;
            }
        
        if (commands[n+1]== '0' && a>n+2)
            return false;
        else if (a == 1+n)
            return false;
 
        m=a;
    }
    
    return true;
}

double ontimeArrivalPercentage(string commands, string airlinecode)
{
    if (isWellFormedAirportString(commands) ==false)
    {
        return -1;
    }
    cout.setf(ios::boolalpha);
    
    string status2;
    string status3;
    int minutes;
    double percent;
    int time=2;
    int h=0;
    
    char first2 = airlinecode[0];
    char second2 = airlinecode[1];
    
    if (airlinecode.size() > 2)
        return -1;
    else if ((first2 == 'A'||first2 =='a') && (second2 == 'A'|| second2 =='a'))
        status2 = "AA";
    else if ((first2 == 'D'||first2 =='d') && (second2 == 'L'|| second2 =='l'))
        status2 = "DL";
    else if ((first2 == 'U'||first2 =='u') && (second2 == 'A'|| second2 =='a'))
        status2 = "UA";
    else if ((first2 == 'S'||first2 =='s') && (second2 == 'W'|| second2 =='w'))
        status2 = "SW";
    else if ((first2 == 'A'||first2 =='a') && (second2 == 'L'|| second2 =='l'))
        status2 = "AL";
    else if ((first2 == 'V'||first2 =='v') && (second2 == 'A'|| second2 =='a'))
        status2 = "VA";
    else
        return -1;
    
    int j = 0;
    int p = 0;
    double top = 0;
    double bottom = 0;
    
    size_t length = commands.size();
    
    while (j < length)
    {
        
        char first3 = commands[0+j];
        char second3 = commands[1+j];
        
        if ((first3 == 'A'||first3 =='a') && (second3 == 'A'|| second3 =='a'))
            status3 = "AA";
        else if ((first3 == 'D'||first3 =='d') && (second3 == 'L'|| second3 =='l'))
            status3 = "DL";
        else if ((first3 == 'U'||first3 =='u') && (second3 == 'A'|| second3 =='a'))
            status3 = "UA";
        else if ((first3 == 'S'||first3 =='s') && (second3 == 'W'|| second3 =='w'))
            status3 = "SW";
        else if ((first3 == 'A'||first3 =='a') && (second3 == 'L'|| second3 =='l'))
            status3 = "AL";
        else if ((first3 == 'V'||first3 =='v') && (second3 == 'A'|| second3 =='a'))
            status3 = "VA";
        else
            status3="ohno";
        
        if(status3==status2)
        {
            while (commands[j]=='0')
            {
                j++;
            }
            
            while (commands[j] != '+' && commands[j] != '-') {
                j++;
            }
            h=0;
            if (commands[j] == '-')
            {
                time = 1;
                h = 1;
            }
            j++;
            p=0;
            
            if (commands[j]=='0')
            {
            while (commands[j]=='0')
            {
                j++;
            }
            
            if (commands[j] == '0' || commands[j] == '1' || commands[j] == '2' || commands[j] == '3' || commands[j] == '4' || commands[j] == '5' || commands[j] == '6' || commands[j] == '7' || commands[j] == '8' || commands[j] == '9')
            {
                j=j;
            }
            else
            {
                j--;
            }
            }
            
            while ((commands[p+j] == '0' || commands[p+j] == '1' || commands[p+j] == '2' || commands[p+j] == '3' || commands[p+j] == '4' || commands[p+j] == '5' || commands[p+j] == '6' || commands[p+j] == '7' || commands[p+j] == '8' || commands[p+j] == '9'))
            {
                p++;
                
            }
            
            
            switch (p) {
                case 1:
                    minutes = (commands[p+j-1]-'0');
                    break;
                case 2:
                    minutes = (commands[p+j-2]-'0')*10 + (commands[p+j-1]-'0');
                    break;
                default:
                    time=0;
                    minutes = 15;
            }
            if (h==1)
                time=1;
            else if (minutes<15)
                time = 1;
            else
                time = 0;
        
        
            if (time == 1)
            {
                top++;
                bottom++;
            }
            else if (time == 0)
            {
                bottom++;
            }
            else
            {
                bottom = bottom;
            }
        
            time = 2;
        }
        
        j++;
        
    }
    percent = top/bottom;
    
    if (bottom == 0)
        return 0;
    else
    {
        cout.setf(ios::fixed);
        cout.precision(1);
        return (percent);
    }
}

int main()
{
    string code,airline;
    cout<<"code: ";
    getline(cin,code);
    cout<<"airline: ";
    getline(cin,airline);
     
    cout<<ontimeArrivalPercentage(code, airline)<<endl;
}
