#include <iostream>
using namespace std;

int main()
{
    int votesReceived;
    int votesToWin;
    int opponentVotes;
    
    cout << "How many electoral college votes did you receive?";
    cin >> votesReceived;
    cout<<"How many electroal college votes did your main opponent receive?";
    cin>> opponentVotes;
    cout<<"How many electroal college votes are needed to win?";
    cin>>votesToWin;
    
    double pctYou = 1.0 * votesReceived/votesToWin;
    double pctOpponent = 1.0 * opponentVotes/votesToWin;
    
    cout.setf(ios::fixed);
    cout.precision(1);
    
    cout<<endl;
    cout<<"you received "<<pctYou<<"% of the votes needed to win."<<endl;
    cout<<"Your main opponent received "<<pctOpponent<<"% of the votes needed to win."<< endl;
    
    if (pctYou>1.0)
        cout <<"It looks like you won."<<endl;
    else
        cout<<"It looks like your main opponent won."<<endl;
}
