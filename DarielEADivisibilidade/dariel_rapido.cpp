#include <bits/stdc++.h>

using namespace std;



int main()

{
    char binario[100000];
    register int i,j;
    int n,teste,result;
    scanf("%s",binario);
    int tamanho = strlen(binario);
    multiset<int> res;
    
	scanf("%d",&n);
    
	for(j=0;j<n;j++)
	{
		scanf("%d",&teste);
		result =0;
        for (i = 0; i < tamanho; i++) 
            result = (result*2 + (int)binario[i] - '0') %teste; 
        if(result==0){
            res.insert(teste);            
        }
	}
   
	int s = res.size();
	if(s==0)
		printf("Nenhum\n");
	else {
		i=0;
		for (auto k : res){
			printf("%d%c", k, i == s-1 ? '\n' : ' ');
			i++;
		}	
	}
	return 0;
}