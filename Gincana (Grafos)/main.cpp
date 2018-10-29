#include <iostream>

using namespace std;

struct v{
    int bff[1001];
    int qtdBff=0;
};

bool visitas[1001];

v alunos[1001];
int qtdALunos;
int num;
int grupos=0;
bool alone=false;

void rec(int now)
{
    visitas[now]=true;
    for(int i=0;i<alunos[now].qtdBff;i++)
    {
        if(!visitas[alunos[now].bff[i]])
            rec(alunos[now].bff[i]);
    }
}

int main()
{
    int I,J;
    cin >> qtdALunos;
    cin >> num;

    for(int i=1;i<=num;i++)
    {
        cin >> I;
        cin >> J;
        alunos[I].bff[alunos[I].qtdBff++] = J;
        alunos[J].bff[alunos[J].qtdBff++] = I;
    }
    for(int i=1;i<=qtdALunos;i++)
    {
        if(alunos[i].qtdBff==0){
            grupos++;
        }
        else if(!visitas[i])
        {
            grupos++;
            rec(i);
        }
    }
    cout << grupos<<endl;

    return 0;
}
