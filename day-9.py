import sys

lines = sys.stdin.readlines()
lines = [line.replace("\n","") for line in lines]

visited = [ [0] * 1000 for _ in range(1000)]
visited[0][0] = 1
headPos = [0,0] # [x,y]
tailPos = [0,0] # [x,y]

def takeStep(direction, steps):
    global tailPos
    for _ in range(steps):
        oldHeadLocation = headPos[:]
        if(direction == 'R'):
            headPos[0] += 1
        elif(direction == 'U'):
            headPos[1] += 1
        elif(direction == 'L'):
            headPos[0] -= 1
        elif(direction == 'D'):
            headPos[1] -= 1
        # don't move tail
        if((abs(headPos[0]-tailPos[0]) == 1 and abs(headPos[1]-tailPos[1]) == 1) or # if diagonal
            (headPos[0] == tailPos[0] and (abs(headPos[1]-tailPos[1]) == 1)) or     # if right above/below
            (headPos[1] == tailPos[1] and (abs(headPos[0]-tailPos[0]) == 1)) or     # if right beside it
            (headPos[0] == tailPos[0] and headPos[1] == tailPos[1])):               # if right on it
            continue
        tailPos = oldHeadLocation
        visited[tailPos[0]][tailPos[1]] = 1

for command in lines:
    direction = command.split(" ")[0]
    steps = int(command.split(" ")[1])

    takeStep(direction, steps)
print(sum(sum(visited,[])))