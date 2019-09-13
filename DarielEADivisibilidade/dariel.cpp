#include <bits/stdc++.h>

using namespace std;

int amod(string num, int a) 
{ 
    int res = 0; 
  
    for (int i = 0; i < num.length(); i++) 
         res = (res*2 + (int)num[i] - '0') %a; 
  
    return res; 
}  

int main()

{
    string binario;
    int n,i,j,teste,result;
    cin >> binario;
    
    multiset<int> res;
    
	scanf("%d",&n);
    
	for(j=0;j<n;j++)
	{
		scanf("%d",&teste);
        result = amod(binario,teste);
        if(result==0){
            res.insert(teste);            
        }
	}
   
	int s = res.size();
	if(s==0)
		printf("Nenhum\n");
	else {
		i=0;
		for (auto j : res){
			printf("%d%c", j, i == s-1 ? '\n' : ' ');
			i++;
		}	
	}
	return 0;
}