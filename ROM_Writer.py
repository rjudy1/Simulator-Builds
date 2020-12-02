import fileinput
global num_bytes

num_bytes = 0
"""
# FOR WRITING TO A ROM VALUES OF CHOICE
def consecutivePoints():
    global num_bytes
    pointInQuant = int(input("How many spaces?"))
    pointInValue = (input("What value?"))
    num_bytes += pointInQuant
    return str(pointInQuant) + "*" + str(pointInValue) + " "

def newPoint():
    global num_bytes
    pointInLocation = int(input("What address?"))
    pointInValue = (input("Value?"))
    
    if pointInLocation - num_bytes > 1:
        zeroes = pointInLocation - num_bytes
        num_bytes += 2
        return str(zeroes) + "*0 " + str(pointInValue) + " "
    else:
        num_bytes += 1
        return str(pointInLocation) + " "

with open('ComputerROM', 'w') as f:
#    f.write("v2.0 raw\n3*0 5a 90 21 ab 92 8*1 fb\n23")

    content = "v2.0 raw\n"
    while(1):
        userInput = input("Would you like to enter several consecutive identical data points (c) or enter specific points (p)?")
        if userInput == 'c':
            content += consecutivePoints()
        elif userInput == 'p':
            content += newPoint()
        else:
            continue
        cont = input("Continue(y/n)")
        if (cont == 'n' or cont == 'N'):
            break

    f.write(content)
"""

def getCommand():
    userInput = input("Choose command +, -, x, /, %, NegateA, NOTA, NegateB, NOTB, bitwise AND, OR, NAND, XOR, OddParity, EvenParity, PassA")
    commandDict = {
        '+': 0,
        '-': 1,
        'x': 2,
        '/': 3,
        '%': 4,
        'NegateA' : 5,
        'NOTA' : 6,
        'NegateB' : 7,
        'NOTB' : 8,
        'AND' : 9,
        'OR' : 'a',
        'NAND' : 'b',
        'XOR' : 'c',
        'OddParity' : 'd',
        'EvenParity' : 'e',
        'PassA' : 'f'
    }
    x = commandDict.get(userInput, lambda: "f")
    print(x)
    return x

def getValue():
    userInput = input("Enter value: ")
    return userInput


with open('ComputerROM', 'w') as f:

    content = "v2.0 raw\n"
    while(1):
        command = str(getCommand())
        value1 = getValue()
        value2 = getValue()
        content += (value1) + (value2) + (command) + "0 "
        cont = input("Continue(y/n)")
        if (cont == 'n' or cont == 'N'):
            break

    f.write(content)
