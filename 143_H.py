a=[[0]*3]*3
a[0]=list(map(int,input().split(' ')))
a[1]=list(map(int,input().split(' ')))
a[2]=list(map(int,input().split(' ')))
change=[[1,0],[-1,0],[0,1],[0,-1],[0,0]]
#print(a)
import copy

def doit(g,x):
    g0=copy.deepcopy(g)
    for i in range(3):
        for j in range(3):
            if x[i][j]==1:
                g0[i][j]=1-g0[i][j]
                for k in range(4):
                    x0=i+change[k][0]
                    y0=j+change[k][1]
                    if (x0 in range(3)) and (y0 in range(3)):
                        g0[x0][y0]=1-g0[x0][y0]
    if g0[0][0]+g0[0][1]+g0[0][2]+g0[1][0]+g0[1][1]+g0[1][2]+g0[2][0]+g0[2][1]+g0[2][2]==0:
        return True
    else:
        return False

for a1 in range(2):
    for a2 in range(2):
        for a3 in range(2):
            for a4 in range(2):
                for a5 in range(2):
                    for a6 in range(2):
                        for a7 in range(2):
                            for a8 in range(2):
                                for a9 in range(2):
                                    ans=[[a1,a2,a3],[a4,a5,a6],[a7,a8,a9]]
                                    flag=doit(a,ans)
                                    #print(doit(a,ans))
                                    if doit(a,ans)==True:    
                                        #print(doit(a,ans))                                    
                                        print(a1,a2,a3,sep=' ')
                                        print(a4,a5,a6,sep=' ')
                                        print(a7,a8,a9,sep=' ')
                                        #print(doit(a,ans))
                                        exit