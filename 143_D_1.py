ans=0
n,m=map(int,input().split(' '))
a=list()
b=[]
c=[[1,0],[-1,0],[0,1],[0,-1]]
l=0
r=0
p=0
for i in range(n):
    a.append(input())
for i in range(n):
    for j in range(m):
        if a[i][j]=='V':
            b.append([i,j,0])
            break

#print(b[l][0]+c[0][0])
flag=0
while True:
    for i in range(4):
        x=b[l][0]+c[i][0]
        y=b[l][1]+c[i][1]
        if x not in range(n) or y not in range(m):
            continue
        if a[x][y]=='E':
            #print([x,y])
            ans=b[l][2]+1
            flag=1
            break
        if a[x][y]=='.':
            r+=1
            b.append([x,y,b[l][2]+1])
            a[x]=a[x][:y]+'#'+a[x][y+1:m]
            #print([x,y])
    if flag==1:
        break
    l+=1
print(ans)