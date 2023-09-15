def dfs(x,y,count):
    global ans
    if count>ans and ans!=0:
        return
    if x not in range(n) or y not in range(m) or a[x][y]=='#' or a[x][y]=='V':
        return
    elif a[x][y]=='E':
        ans=count
        return
    else:
        a[x]=a[x][:y]+'#'+a[x][y+1:]
        dfs(x+1,y,count+1)
        dfs(x-1,y,count+1)
        dfs(x,y+1,count+1)
        dfs(x,y-1,count+1) 
        a[x]=a[x][:y]+'.'+a[x][y+1:m]
    return

ans=0
n,m=map(int,input().split(' '))
a=list()
for i in range(n):
    a.append(input())
for i in range(n):
    for j in range(m):
        if a[i][j]=='V':
            dfs(i+1,j,1)
            dfs(i-1,j,1)
            dfs(i,j+1,1)
            dfs(i,j-1,1)
            break
print(ans)