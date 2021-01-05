from computils.reader import CaseLinePerCase

data=CaseLinePerCase(2, test="array_rotate.txt")
print(data)
for test in data:
    array_count,step=test[0].split(' ')
    rotate_by=int(step)
    array_count=int(array_count)
    array=test[1].split(' ')
    done=[]
    for count in range(array_count-rotate_by,array_count):
        done.append(array[count])
    for count in range(array_count-rotate_by):
        done.append(array[count])
    print(done)
