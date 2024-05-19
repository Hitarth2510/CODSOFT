#include <iostream>
#include <cstdlib>
#include<ctime>
using namespace std;

class dom{
    public:
    int a,guess=0;
    void generate()
    {
        srand(time(0));
        a=(rand()%101);
    }
    void guesser()
    {
        do
        {
            cout<<"Enter a guess (1-100)"<<endl;
            cin>>guess;
            if(guess>a)
            {
                cout<<"Enter a smaller number"<<endl;
            }
            else if (guess<a){
                cout<<"Enter a larger number"<<endl;
            }
            else
            {
                cout<<"You Won!!"<<endl;
            }
        }while(guess!=a);
    }
};
int main()
{
    dom r;
    r.generate();
    r.guesser();
    return 0;
    
}