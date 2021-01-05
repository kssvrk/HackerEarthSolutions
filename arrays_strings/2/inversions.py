def main():
    cases = int(input())
    data = []
    for i in range(0, cases):
        m_size = int(input())
        matrix = []
        for s in range(0, m_size):
            matrix.append(list(map(int, input().split(" "))))
        data.append(matrix)
    for m in data:
        count = 0
        size = len(m)
        for r in range(size):
            for c in range(size):
                for cr in range(r, size):
                    for cc in range(c, size):
                        if m[r][c] > m[cr][cc]:
                            count = count + 1
        print(count)


main()