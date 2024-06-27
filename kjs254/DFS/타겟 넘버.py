def DFS(length, start, path):
    if len(path) > length:
        return
    idxs_list.append(path)
    
    for i in range(start, length):
        DFS(length, i + 1, path + [i])

def solution(numbers, target):
    global idxs_list
    idxs_list = []
    DFS(len(numbers),0,[])
    my_numbers = [x for x in numbers]
    count=0
    
    for idx in idxs_list:
        for i in idx:
            my_numbers[i] *=-1
        if sum(my_numbers)==target:
            count+=1
        my_numbers = [x for x in numbers]
    
    return count