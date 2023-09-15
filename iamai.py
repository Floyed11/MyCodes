# strassen algorithm
def strassen(a, b):
    if len(a) == 1:
        return [[a[0][0]*b[0][0]]]
    else:
        n = len(a)
        a11 = [[a[i][j] for j in range(n//2)] for i in range(n//2)]
        a12 = [[a[i][j] for j in range(n//2, n)] for i in range(n//2)]
        a21 = [[a[i][j] for j in range(n//2)] for i in range(n//2, n)]
        a22 = [[a[i][j] for j in range(n//2, n)] for i in range(n//2, n)]
        b11 = [[b[i][j] for j in range(n//2)] for i in range(n//2)]
        b12 = [[b[i][j] for j in range(n//2, n)] for i in range(n//2)]
        b21 = [[b[i][j] for j in range(n//2)] for i in range(n//2, n)]
        b22 = [[b[i][j] for j in range(n//2, n)] for i in range(n//2, n)]
        m1 = strassen(add(a11, a22), add(b11, b22))
        m2 = strassen(add(a21, a22), b11)
        m3 = strassen(a11, sub(b12, b22))
        m4 = strassen(a22, sub(b21, b11))
        m5 = strassen(add(a11, a12), b22)
        m6 = strassen(sub(a21, a11), add(b11, b12))
        m7 = strassen(sub(a12, a22), add(b21, b22))
        c11 = add(sub(add(m1, m4), m5), m7)
        c12 = add(m3, m5)
        c21 = add(m2, m4)
        c22 = add(sub(add(m1, m3), m2), m6)
        c = [[0 for j in range(n)] for i in range(n)]
        for i in range(n//2):
            for j in range(n//2):
                c[i][j] = c11[i][j]
                c[i][j+n//2] = c12[i][j]
                c[i+n//2][j] = c21[i][j]
                c[i+n//2][j+n//2] = c22[i][j]
        return c
    # add two matrices
def add(a, b):
    n = len(a)
    c = [[0 for j in range(n)] for i in range(n)]
    for i in range(n):
        for j in range(n):
            c[i][j] = a[i][j] + b[i][j]
    return c
    # sub two matrices
def sub(a, b):
    n = len(a)
    c = [[0 for j in range(n)] for i in range(n)]
    for i in range(n):
        for j in range(n):
            c[i][j] = a[i][j] - b[i][j]
    return c
# main
if __name__ == '__main__':
    a = [[1, 2], [3, 4]]
    b = [[5, 6], [7, 8]]
    print (strassen(a, b))
    a = [[1, 2, 3, 4], [5, 6, 7, 8], [9, 10, 11, 12], [13, 14, 15, 16]]
    b = [[17, 18, 19, 20], [21, 22, 23, 24], [25, 26, 27, 28], [29, 30, 31, 32]]
    print (strassen(a, b))
    # a = [[1, 2, 3], [4, 5, 6], [7, 8, 9]]
    # b = [[10, 11, 12], [13, 14, 15], [16, 17, 18]]
    # print (strassen(a, b))