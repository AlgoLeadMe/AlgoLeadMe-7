def func(bracket):
    stk = []
    for b in bracket:
        if b in ["[","{","("]:
            stk.append(b)
        elif b in ["]","}",")"]:
            if not stk:
                return False
            if stk[-1]=="[" and b=="]":
                stk.pop()
            elif stk[-1]=="{" and b=="}":
                stk.pop()
            elif stk[-1]=="(" and b==")":
                stk.pop()
            else:
                return False
    return not stk

def solution(s):
    answer = 0
    l = len(s)
    for i in range(l):
        x = s[i:]+s[:i]
        if func(x):
            answer +=1
        
    return answer