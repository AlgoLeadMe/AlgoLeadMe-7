import heapq
def solution(n, works):
    max_heap = []
    for w in works:
        heapq.heappush(max_heap, (-w,w))
    
    for i in range(n):
        max_work = heapq.heappop(max_heap)[1]-1
        if max_work<0:
            return 0
        
        heapq.heappush(max_heap,(-max_work,max_work))
        
    print(max_heap)
    answer = sum([x[1]**2 for x in max_heap])
    return answer