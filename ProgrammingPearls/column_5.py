def binarySearch(x, n, t):
    l = 0
    u = n - 1
    while l <= u:
        m = int((l + u) / 2)
        if x[m] < t:
            l = m + 1
        elif x[m] == t:
            return m;
        else:
            u = m - 1

    return -1;

def initArr(n):
    x = [i for i in range(n)]
    return x


def test(n):
    x = [10*i for i in range(n)]

    for i in range(n):
        assert binarySearch(x, n, 10 * i) == i
        assert binarySearch(x, n, 10 * i -5) == -1

    assert binarySearch(x, n, 10 * n - 5) == -1
    assert binarySearch(x, n, 10 * n) == -1

if __name__ == '__main__':
    while True:
        n, t = list(map(int, input().split()))
        if n < 0:
            break
        x = [i*10 for i in range(n)]
        print(binarySearch(x, n, t))