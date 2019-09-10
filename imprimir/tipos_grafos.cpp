#include <iostream>

using namespace std;

struct v
{
    int bff[1001];
    int qtdBff=0;
};

bool visitas[1001];

v alunos[1001];
int qtdALunos;
int num;
int total;
int me;

bool alone=false;

void rec(int now)
{
    visitas[now]=true;
    total++;
    for(int i=0; i<alunos[now].qtdBff; i++)
    {
        if(!visitas[alunos[now].bff[i]])
            rec(alunos[now].bff[i]);
    }
}

int main()
{
    int I,J;

    while(scanf("%d",&qtdALunos)==1)
    {

        cin >> num;
        total=0;

        for (int i=1;i<=qtdALunos ;i++ )
        {
            alunos[i].qtdBff=0;
            visitas[i]=false;
        }


        for(int i=1; i<=num; i++)
        {
            cin >> I;
            cin >> J;
            alunos[I].bff[alunos[I].qtdBff++] = J;
            alunos[J].bff[alunos[J].qtdBff++] = I;
        }
        cin >> me;
        rec(me);

        cout << total<<endl;
    }
    return 0;
}
