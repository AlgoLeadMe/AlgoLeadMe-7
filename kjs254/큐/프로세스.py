def solution(priorities, location):
    answer = 0
    processes = list(range(len(priorities))) # 프로세스 번호 [0,1,2,...]
    
    while priorities:
        if priorities[0]<max(priorities): 
            priorities.append(priorities.pop(0)) # 우선순위가 더 높은 프로세스가 존재할 때, 큐의 맨 뒤에 삽입
            processes.append(processes.pop(0)) # 프로세스 번호에도 똑같이 적용
        else:
            del(priorities[0]) # 프로세스 종료 및 실행횟수 증가
            answer +=1
            
            if location==processes.pop(0):
                return answer