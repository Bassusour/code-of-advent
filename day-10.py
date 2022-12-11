import sys

signalStrength = 0
signalStrengthList = []
X = 1

lines = sys.stdin.readlines()
lines = [line.replace("\n","") for line in lines]
lines.insert(0, "asdf")

cycles = len(lines)
cycle = 1

while cycle < cycles:
    line = lines[cycle]
    command = line.split(" ")[0]

    if(cycle == 20 or cycle % 40 == 20):
        """print("cycle is " + str(cycle))
        print("X is " + str(X))
        print(changesInX)
        print()"""
        signalStrength += cycle*X
        signalStrengthList.append(cycle*X)

    if(command == "noop"):
        cycle += 1
        continue
    
    increment = line.split(" ")[1]

    # add instr. to increment X next cycle
    if(command == "addx"):
        lines.insert(cycle+1, "addXX " + increment)
        cycles += 1
    # increment X
    elif(command == "addXX"):
        X += int(increment)

    cycle += 1
    

print(signalStrengthList)
print(signalStrength)