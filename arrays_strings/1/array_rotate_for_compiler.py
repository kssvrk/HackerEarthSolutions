# ----------- TAKE INPUT -----------
cases = int(input())
lines_per_case = 2
data = []
array = []
count = 0
for case in range(0, lines_per_case * cases):
    if count % lines_per_case == 0:
        count = 0
        array = []
    inp = input()
    array.append(inp)
    if count == lines_per_case - 1:
        data.append(array)
    count = count + 1
# ------------------------------------
for test in data:
    array_count,step=test[0].split(' ')
    
    array_count=int(array_count)
    rotate_by=int(step)%array_count
    array=test[1].split(' ')
    done=[]
    for count in range(array_count-rotate_by,array_count):
        done.append(array[count])
    for count in range(array_count-rotate_by):
        done.append(array[count])
    s=''
    for i in done:
        s=s+str(i)+' '
    print(s)