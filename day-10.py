import sys

signalStrength = 0
signalStrengthList = []
X = 1

lines = sys.stdin.readlines()
lines = [line.replace("\n","") for line in lines]
lines.insert(0, "asdf")

cycles = len(lines)
cycle = 1

spritePixels = [1,2,3]
def moveSprite(inc):
    return [pixel+inc for pixel in spritePixels]

while cycle < cycles:
    line = lines[cycle]
    command = line.split(" ")[0]

    if((cycle % 40) in spritePixels):
        print('#', end='')
    else:
        print('.', end='')
    if(cycle % 40 == 0): 
        print("")

    if(cycle == 20 or cycle % 40 == 20):
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
        spritePixels = moveSprite(int(increment))

    cycle += 1
    
print()
print(signalStrengthList)
print(signalStrength)