n=int(input())
a=list(map(int,input().split(' ')))
a.sort()
min=-1
max=-1
for i in range(n-1):
    d=a[i+1]-a[i]
    if min==-1 or d<min:
        min=d
    if max==-1 or d>max:
        max=d
print(min,max)