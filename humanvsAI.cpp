//AI vs human

#include <iostream>
using namespace std;
int pick=0;

int minmax(int n,bool s){
    if(n==0){
        if(s)
            return 1;
        return -1;
    }

    int sc1=minmax(n-1,!s);

    //alpha-beta pruning
    if((sc1==1&&s)||(sc1==-1 && !s)){
        pick=1;
        return sc1;
    }
    else if(n==1)
        return sc1;

    int sc2=minmax(n-2,!s);

    //alpha-beta pruning
    if((sc2==1&&s)||(sc2==-1 && !s)){
        pick=2;
        return sc2;
    }
    else if(n==2)
        return sc2;

    int sc3=minmax(n-3,!s);

    //alpha-beta pruning
    if((sc3==1&&s)||(sc3==-1 && !s)){
        pick=3;
        return sc3;
    }
    else{
        pick=1;
        return sc3;
    }

}
int main() {
    int n , x, match;
    bool s=true;
    int firstChance;
    cout << "enter the initial number of sticks in the box\n";
    cin >> n;
    firstChance=(rand()%2)+1;
    if(firstChance==1){
        cout<<"your chance first";
         while(n>0){
        cout<<"\nenter value: ";
        cin>>match;
        n=n-match;
        if(n==1){
                cout<<"\nYou won\n";
                break;
        }
        x=minmax(n,s);
        cout<<"opponent picked:"<<pick;
        n=n-pick;
        if(n==1){
            cout<<"\nAI won\n";
            break;
        }
         }
    }
    else{
        cout<<"AI's chance first";
        while(n>0){
        x=minmax(n,s);
        cout<<"\nopponent picked:"<<pick;
        n=n-pick;
        if(n==1){
            cout<<"\nAI won\n";
            break;
        }
        cout<<"\nenter value: ";
        cin>>match;
        n=n-match;
        if(n==1){
                cout<<"\nYou won\n";
                break;
        }
        }
    }
   return 0;
}
