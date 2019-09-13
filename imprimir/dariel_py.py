entrada = str(input())
num = int(str(entrada), 2)
qtd = int(input())
lista = []
for i in range(qtd):
    divisor = int(input())
    if(num%divisor==0):
        lista.append(divisor)

if(len(lista)==0):
    print("Nenhum")
else:
    lista.sort()
    print (' '.join(map(str, lista)))
