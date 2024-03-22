def MakeSet(s): #2글자씩 끊은 알파벳만 리스트로 출력
    lst = []
    for i,_ in enumerate(s[:-1]):
        a = s[i:i+2]
        if a.isalpha():
            lst.append(a.lower())
    return lst

def func(l1, l2): #중복 교집합과 중복 합집합의 길이를 각각 출력
    intersection_set, union_set = [], []
    inter = set(l1) & set(l2)
    union = set(l1) | set(l2)
    
    for n in union:
        intersection_num = min(l1.count(n),l2.count(n))
        union_num = max(l1.count(n),l2.count(n))
        
        for _ in range(intersection_num):
            intersection_set.append(n)
            
        for _ in range(union_num):
            union_set.append(n)

    return len(intersection_set), len(union_set)

def solution(str1, str2): #메인 코드
    answer = 0
    
    arr1 = MakeSet(str1)
    arr2 = MakeSet(str2)
    
    a,b = func(arr1,arr2)
    
    if b:
        answer = int((a/b)*65536)
    else:
        answer = 65536
    
    return answer