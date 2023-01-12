import random
import time

def countingsort(array):
    min_element = min(array)
    max_element = max(array)
    range_elements = max_element - min_element + 1
    length = len(array)

    count = [0] * range_elements
    output = [0] * length

    for i in range(length):
        count[array[i] - min_element] += 1
    for i in range(1,len(count)):
        count[i] += count[i-1]
    for i in range(length-1,-1,-1):
        output[count[array[i] - min_element] - 1] = array[i]
        count[array[i] - min_element] -= 1

    for i in range(length):
        array[i] = output[i]
    return array

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
    countingsort(list)
    stop = time.time()

    if sortCheck(list):
        g.write("Sortat corect! Durata: " + str(stop - start) + " secunde" + "\n")
    else:
        g.write("Sortat incorect!" + "\n")

f.close()
g.close()
