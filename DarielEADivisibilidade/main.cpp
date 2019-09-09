#include <bits/stdc++.h>

using namespace std;

int main()

{
	char binario[100000];
    int n,i,teste;
    scanf("%s",binario);
    bitset<10> bits(binario);
    multiset<int> res;
    unsigned long long decimal;
    decimal =  bits.to_ulong();
    
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%d",&teste);
		if(decimal%teste==0)
		{
			res.insert(teste);
		}
	}
	int s = res.size();
	if(s==0 || decimal == 0)
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