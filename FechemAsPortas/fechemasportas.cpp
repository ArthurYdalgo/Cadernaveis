#include <iostream>
#include <math.h>
using namespace std;

int main()
{
    int n;
    int v;
    while(true)
    {
        cin >> n;
        if(n==0)
            break;
        else
        {
            cout << 1 ;
            for(int i=2; ; i++)
            {
                v = i*i;
                if(v<=n)
                    cout << " "<<v;
                else
                    break;
            }

            cout << endl;
        }


    }

    return 0;
}

