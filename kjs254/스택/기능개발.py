def solution(progresses, speeds):
    answer = []
    days = []
    stk = []
    
    for i,p in enumerate(progresses):
        term = 100-p
        s = speeds[i]
        
        if term%s==0:
            days.append(term//s)
        else:
            days.append(term//s+1)
            
    while days:
        if not stk:
            stk.append(days.pop(0))
        elif max(stk)>=days[0]:
            stk.append(days.pop(0))
        else:
            answer.append(len(stk))
            stk.clear()
    
    answer.append(len(stk))
    return answer