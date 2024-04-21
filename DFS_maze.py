import queue

n, m = map(int, input().split())

maze = [[0] * m for _ in range(n)]
color = [[0] * m for _ in range(n)]
min_step = [[0] * m for _ in range(n)]

for i in range(n):
    in_maze = list(map(int, input().split()))
    for j in range(m):
        maze[i][j] = in_maze[j]

move = [(0, 1), (0, -1), (1, 0), (-1, 0)]
end = (n - 1, m - 1)

def bfs(start):
    global min_step
    que = queue.Queue()
    que.put(start)
    while not que.empty():
        position = que.get()
        x, y = position
        color[x][y] = 1

        for i in range(4):
            new_x, new_y = x + move[i][0], y + move[i][1]
            if (new_x <0 or new_x >= n or new_y < 0 or new_y >= m) or maze[new_x][new_y] == 1 or color[new_x][new_y] == 1 or min_step[new_x][new_y] != 0:
                continue
            que.put((new_x, new_y))
            min_step[new_x][new_y] = min_step[x][y] + 1
            
    return

bfs((0, 0))
print(min_step[n - 1][m - 1])

# print(path)

# maze_visualization.visualize_maze_with_path(maze, path, color_map)