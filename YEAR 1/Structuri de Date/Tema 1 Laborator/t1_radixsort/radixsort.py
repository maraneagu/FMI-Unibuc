import random
import time

def countingSort(array, position):
    length = len(array)

    output = [0] * length
    count = [0] * 10

    for i in range(0, length):
        index = array[i] // position
        count[index % 10] += 1

    for i in range(1, 10):
        count[i] += count[i - 1]

    for i in range(length-1,-1,-1):
        index = array[i] // position
        output[count[index % 10] - 1] = array[i]
        count[index % 10] -= 1

    for i in range(0, length):
        array[i] = output[i]

def radixSort(array):
    maximum = max(array)
    position = 1
    while maximum // position > 1:
        countingSort(array, position)
        position *= 10

def sortCheck(array):
    length = len(array)
    for i in range(1,length):
        if array[i] < array[i-1]:
            return 0
    return 1

f = open("teste.txt")
g = open("output_teste.txt","w")
T = f.readline()
g.write(f"T = {T}" + "\n")

for linie in f:
    test = [int(x) for x in linie.split()]
    N = test[0]
    MAX = test[1]
    g.write(f"N = {N}, MAX = {MAX}" + "\n")

    list = []
    for i in range(N):
        element = random.randint(1,MAX)
        list.append(element)

    start = time.time()
    radixSort(list)
    stop = time.time()

    if sortCheck(list):
        g.write("Sortat corect! Durata: " + str(stop - start) + " secunde" + "\n")
    else:
        g.write("Sortat incorect!" + "\n")

f.close()
g.close()
