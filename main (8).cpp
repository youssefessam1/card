#include <iostream>
#include <string>
#include <assert.h>
//youssef essam farid iD;20170346
using namespace std;
enum Suit{clubs,diamond,heart,spade,eNd};
Suit operator ++( Suit &c,int )
{
	//if ( value == spade ) return ( clubs );
switch (c)
    {
        case spade: c = eNd; return c;
        case diamond: c = heart; return c;
        case heart: c = spade; return c;
        case clubs: c = diamond; return c;
        default: return c;

    }

}
int ACE=1;
int JACK=11;
int QUEEN=12;
int KING=13;
class card{
protected:
    int ranK;
    Suit type;
public:
    card(){
        ranK=0;
    }
    card(string x)
    {
        int g=x.length();
        string ss;
            for(int i=1;i<11;i++){
                ss=to_string(i);
                if (x.substr(0,g-1)==ss) ranK=i;
            }
            if(x[0]=='j'||x[0]=='J') ranK=11;
            else if(x[0]=='q'||x[0]=='Q') ranK=12;
            else if(x[0]=='k'||x[0]=='K') ranK=13;
            else if(x[0]=='a'||x[0]=='A') ranK=1;
            if (x[g-1]=='s'||x[g-1]=='S')type=spade;
            else if (x[g-1]=='h'||x[g-1]=='H')type=heart;
            else if (x[g-1]=='d'||x[g-1]=='D')type=diamond;
            else if (x[g-1]=='c'||x[g-1]=='C')type=clubs;



    }
    card(int x,Suit typee){
        assert (x<14);
        ranK=x;
        if (typee==spade)type=spade;
        else if (typee==diamond)type=diamond;
        else if (typee==clubs)type=clubs;
        else if (typee==heart)type=heart;
    }
    getr(){
        cout<<ranK<<endl;
    }
    gett(){
        cout<<type<<endl;
    }
    string toString(){
        /*if (ranK==1)cout<<"A";
        else if (ranK==11)cout<<"J";
        else if (ranK==12)cout<<"Q";
        else if (ranK==13)cout<<"K";
        else cout<<ranK;
        if (type==0)cout<<"C";
        else if (type==1)cout<<"D";
        else if (type==2)cout<<"H";
        else if (type==3)cout<<"K";
        cout<<endl;*/
        string ranks[] = {"", "A", "2", "3", "4", "5", "6","7", "8", "9", "10", "J", "Q", "K"};
        string suits[] = {"C", "D", "H", "S"};
        string c=ranks[ranK]+suits[type];
        return c;
    }

};

int main()
{
/*    Suit suitt=static_cast<Suit>(1);
    card x("ad");
    card y(ACE,diamond);
    y.toString();
    x.toString();
    x.getr();
    x.gett();
    y.getr();
    y.gett();
    cout << "Hello world!" << endl;
    return 0;*/
    for (Suit t = clubs; t <= spade; t++) {
        for (int i = ACE; i <= KING; i++) {
            card g(i,t);
            cout << g.toString()<<" ";
        }
        cout << endl;
    }
return 0;
}

