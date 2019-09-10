#include <iostream>
#include <algorithm>
#include <math.h>
#include <stack>
#include <vector>
#define PI 3.141592653

using namespace std;

typedef struct ponto
{
    double x,y;
    float angulo;
} ponto;

   vector<ponto> p;
    vector<ponto> hull;

ponto nP(int x, int y) {
    ponto p;
    p.x = x;
    p.y = y;
    return p;
}

double dist(ponto A,ponto B)
{
    return sqrt(pow(A.x-B.x,2)+pow(A.y-B.y,2));
}

bool operator<(const ponto& a, const ponto& b)
{
    return a.angulo < b.angulo;
}

float ccw(ponto p1,ponto p2,ponto p3)
{
    return (p2.x - p1.x)*(p3.y - p1.y) - (p2.y - p1.y)*(p3.x - p1.x);
}

float anglePa(int x1,int y1,int x2,int y2)
{
    return abs((atan2( y2-y1,x2-x1 ))* 180 /PI);
}

float angulo(ponto A,ponto B)
{
    return anglePa(A.x,A.y,B.x,B.y);
}

ponto next_to_top(stack<ponto> pontos)
{
    ponto aux = pontos.top();
    pontos.pop();
    ponto next = pontos.top();
    pontos.push(aux);
    return next;
}

int main()
{
    int qtd,tY,tX,iM;
    int menorY;
    double mais=0.0,menos=0.0;
    double area;
    stack<ponto> pontos;

    //ponto p[100001];


    scanf("%d",&qtd);
    p.clear();hull.clear();
    hull.reserve(qtd);
    p.reserve(qtd);
    pontos=stack<ponto>();
    mais=0.0;menos=0.0;
    menorY=10001;
    iM=0;
    for (int i=0; i<qtd ; i++)
    {
        cin >> tX >> tY;

        if(tY<menorY)
        {
            menorY=tY;
            iM=i;
        }
        p.push_back(nP(tX,tY));
    }
    swap(p[iM],p[0]);
    p[0].angulo=0;
    for (int i=1; i<qtd ; i++ )
    {
        p[i].angulo = angulo(p[0],p[i]);
    }

    //sort(p+1,p+qtd,[](ponto pA,ponto pB){return pA.angulo > pB.angulo;});
    sort(p.begin()+1,p.end());


    for (int i=1; i<p.size()-1 ; i++ )
    {
        if(p[i].angulo==p[i+1].angulo){
            if(dist(p[i],p[0])>dist(p[i+1],p[0]))
            {
                p.erase(p.begin()+i+1);
            }
            else
            {
                p.erase(p.begin()+i);
            }
            if(p[i].angulo==p[i+1].angulo)
                i--;
        }

    }

  /*  for (int i=0; i<p.size() ; i++ )
    {
        cout << p[i].x<<", "<<p[i].y <<endl;
    }*/



    pontos = stack<ponto>();

    pontos.push(p[0]);
    pontos.push(p[1]);
    pontos.push(p[2]);
    for (int i=3; i<p.size() ; i++)
    {
        while(ccw(next_to_top(pontos),pontos.top(),p[i])<=0)
            pontos.pop();
        pontos.push(p[i]);
    }



    while(pontos.size())
    {
        //cout << pontos.top().x<<", "<<pontos.top().y<<endl;
        hull.push_back(pontos.top());
        pontos.pop();
    }

    mais += hull[hull.size()-1].x*hull[0].y;
    menos += hull[0].x*hull[hull.size()-1].y;

    for (int i=0;i<hull.size()-1 ;i++ )
    {
        mais += hull[i].x*hull[i+1].y;
        menos += hull[i+1].x*hull[i].y;
    }

    area = abs(mais-menos)/2.0;
    printf("%.2f\n",area);

    return 0;
}
