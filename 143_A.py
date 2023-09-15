t=int(input())
list0=[1,1]
i=0
j=1
while(list0[i]+list0[j]<=10000000000000):
        list0.append(list0[i]+list0[j])
        i=i+1
        j=j+1
for k in range(t):
    a,b =map(int,input().split(' '))
    count=0
    l=0
    while list0[l] <a:
        l+=1
    r=l
    while r<=j and list0[r] in range(a,b):
        r+=1
    print(r-l)
#print(list0[j])