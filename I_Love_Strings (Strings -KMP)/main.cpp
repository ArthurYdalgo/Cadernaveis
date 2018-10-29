#include <iostream>
#include <cstdlib>
#include <cstdio>
using namespace std;

int main()
{
    int qtdS,qtdK;
    bool flag=false;
    char str[100001];
    char strK[1001];
    scanf("%d",&qtdS);
    getchar();

    for (int i=0;i<qtdS ;i++ )
    {
        gets(str);
        scanf("%d",&qtdK);
        getchar();


        for (int j=0;j<qtdK ;j++ )
        {
            gets(strK);
            for (int k=0;k<100001 ;k++ )
            {
                if(str[k]=='\0')
                {
                    cout << "n" << endl;
                    break;
                }
                if(str[k]==strK[0])
                {
                    flag=true;
                    for (int l=1;l<1000 ;l++ )
                    {
                        if(strK[l]=='\0')
                            break;
                        if(str[k+l]!=strK[l])
                        {
                            k=k+l-1;
                            flag=false;
                            break;
                        }

                    }
                    if(flag)
                    {
                        cout << "y" << endl;
                        break;
                    }
                }
            }

        }
    }
    return 0;
}
