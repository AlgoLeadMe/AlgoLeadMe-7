def solution(s):
    answer = []
    dic = {}
    s = s.replace('{','').replace('}','').split(',')
    
    for n in s:
        n = int(n)
        if n not in dic:
            dic[n] = 1
        else:
            dic[n]+= 1
    
    dic_sorted = sorted(dic.items(), key=lambda x:x[1], reverse=True)
                        
    for d in dic_sorted:
        answer.append(d[0])
        
    return answer