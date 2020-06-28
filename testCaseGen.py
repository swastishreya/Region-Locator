import random

INF = 1000000
n = random.randint(1,INF)
q = random.randint(1,INF)
totalReg = random.randint(1,INF)

reg = [x for x in range(totalReg)]

x = []
min_y = INF+1
dx = {}
dy = {}

x1 = 0
x2 = random.randint(1,INF)

x.append(x1)
x.append(x2)
dx[x1] = 1
dx[x2] = 1

var = n
while(var>1):
    x.append(random.randint(x[-1],INF))
    dx[x[-1]] = 1
    x.append(random.randint(x[-1],INF))
    dx[x[-1]] = 1
    var -= 1
    if(x[-1] == x[-2]):
        x.pop()
        x.pop()
        break

n = len(x)-1
print str(n) + " " + str(q)

for var in range(n):
    numReg = random.randint(1,totalReg)
    
    y = []
    y1 = 0
    y2 = random.randint(1,INF)
    y.append(y1)
    y.append(y2)
    dy[y1] = 1
    dy[y2] = 1
    while(numReg>1):
        y.append(random.randint(y[-1],INF))
        dy[y[-1]] = 1
        y.append(random.randint(y[-1],INF))
        dy[y[-1]] = 1
        if(y[-1] == y[-2]) :
            y.pop()
            y.pop()
            break
        numReg -= 1

    min_y = min([min_y,y[-1]])
    numReg = len(y)-1
    print  str(x[var])+ " " + str(x[var+1]) + " " + str(numReg)
    for var in range(numReg): 
        nameReg = random.randint(1,totalReg)
        print  str(y[var])+ " " + str(y[var+1]) + " " + str(nameReg)

var = q
while(var>0):
    xq = random.randint(1,x[-1]-1)
    while(xq in dx):
        xq = random.randint(1,x[-1]-1)

    yq = random.randint(1,min_y-1)
    while(yq in dy):
        yq = random.randint(1,min_y-1)
    print str(xq) + " " + str(yq)
    var -= 1

