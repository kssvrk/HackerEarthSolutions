def CaseLinePerCase(lines_per_case, test=None):
    
    # #More easier way 
    # testCase  = int(input())
    # for _ in range(testCase):
    #     n,k = map(int,input().split())
    #     l = list(map(int,input().split()))

    if test == None:
        cases = int(input())
        tc = []
        array = []
        count = 0
        for case in range(0, lines_per_case * cases):
            if count % lines_per_case == 0:
                count = 0
                array = []
            inp = input()
            array.append(inp)
            if count == lines_per_case - 1:
                tc.append(array)
            count = count + 1
        return tc
    else:
        with open(test) as file:
            inp = file.read().split('\n')
            cases = int(inp[0])
            tc = []
            array = []
            count = 0
            for line in range(0, lines_per_case * cases):
                if count % lines_per_case == 0:
                    count = 0
                    array = []
                x = inp[line+1]
                array.append(x)
                if count == lines_per_case - 1:
                    tc.append(array)
                count = count + 1
                
            return tc
