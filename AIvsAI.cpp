//AI vs AI

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
    int n , x;
    bool s=true;
    int firstChance;
    cout << "enter the initial number of sticks in the box\n";
    cin >> n;
    firstChance=(rand()%2)+1;
    if(firstChance==1){
        cout<<"AI 1 chance first";
         while(n>0){
        x=minmax(n,s);
        cout<<"AI 1 picked:"<<pick<<"\n";
        n=n-pick;
        if(n==1){
                cout<<"\nAI 1 won\n";
                break;
        }
        x=minmax(n,s);
        cout<<"AI 2 picked:"<<pick<<"\n";
        n=n-pick;
        if(n==1){
            cout<<"\nAI 2 won\n";
            break;
        }
         }
    }
    else if(firstChance==2){
        cout<<"AI 2 chance first\n";
         while(n>0){
        x=minmax(n,s);
        cout<<"AI 2 picked:"<<pick<<"\n";
        n=n-pick;
        if(n==1){
                cout<<"\nAI 2 won\n";
                break;
        }
        x=minmax(n,s);
        cout<<"AI 1 picked:"<<pick<<"\n";
        n=n-pick;
        if(n==1){
            cout<<"\nAI 1 won\n";
            break;
        }
         }
    }
   return 0;
}
