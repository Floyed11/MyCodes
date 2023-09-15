x,a,y = map(float,input().split(' '))
import math
c = math.sqrt(pow(x,2)+pow(y,2)-2*x*y*math.cos(math.pi-a/180*math.pi))
print("{:.4f}".format(c))
