def dfs(my_word):
    global dic
    vowel = ['A','E','I','O','U']
    
    if len(my_word)<=5:
        dic.append(my_word)
        
        for v in vowel:
            dfs(my_word + v)

def solution(word):
    global dic
    dic = []
    dfs('')
    answer = dic.index(word)
    return answer