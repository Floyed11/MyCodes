import math

def isPrime(n0):
    flag=True
    for j in range(2,int(math.sqrt(n0))+1):
        if n0 % j ==0:
            flag=False
            break
    return flag

print("please input a number: ",end='')
n=int(input())
for i in range(2,n+1):
    if  isPrime(i):
        print(i,end=' ')
print('')