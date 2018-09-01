#include <iostream>
#include <vector>
using namespace std;
int qtdF;
int maxC;

struct caso
{
    int nC,nD;
};

int m[50][50];

vector<caso> frase;


int rec(int f, int sD,int sC)
{
    int temp=0;
    int record=0;
    if(frase[f].nC+sC<=maxC)
    {
        sD+=frase[f].nD;
        sC+=frase[f].nC;
        if(f==qtdF-1)
            return sD;
        for(int i=f+1; i<qtdF; i++)
        {
            temp = rec(i,sD,sC);
            if(temp>record)
                record = temp;
        }
        return record;

    }
    else
    {
        return sD;
    }

}

int main()
{
    frase.reserve(50);
    int record=0,temp,cont=1,tC,tD;
    while(true)
    {
        record =0;
        cin >> maxC;
        cin >> qtdF;

        if(maxC==0)
            break;

        for(int i=0; i<qtdF; i++)
        {
            cin >> tC;
            cin >> tD;
            if(tC<=maxC)
            {
                frase[i].nC = tC;
                frase[i].nD = tD;
            }
            else
            {
                qtdF--;
            }
        }
        for(int i=0; i<qtdF; i++)
        {
            temp = rec(i,0,0);
            if(temp>record)
                record = temp;
        }
        cout << "Teste " << cont++<<endl;
        cout << record << endl<<endl;

    }


    return 0;
}
