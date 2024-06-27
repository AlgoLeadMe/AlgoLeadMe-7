def solution(board):
    n = len(board)
    for i in range(n):
        board[i].insert(0,-1)
        board[i].append(-1)
    board.insert(0,[-1]*(n+2))
    board.append([-1]*(n+2))
    
    for i in range(n+2):
        for j in range(n+2):
            
            if board[i][j]==1:
                for dx in (-1,0,1):
                    for dy in (-1,0,1):
                        board[i+dy][j+dx] = board[i+dy][j+dx]*2 -1
    
    return sum(board, []).count(0)