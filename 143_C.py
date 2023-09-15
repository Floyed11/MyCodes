n,m,k=map(int,input().split(" "))
p=int(input())

def factorial(k):
    num=1
    for i in range(k):
        num*=(i+1)
    return num

#print(factorial(n))

temp=factorial(n)//(factorial(k)*factorial(n-k)) % p
ans=1
for i in range(m):
    ans = ans * temp % p
print(ans)
