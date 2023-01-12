import random
import time

def shellsort(array):
    length = len(array)
    gap = length // 2

    while gap > 0:
        for i in range(gap,length):
            temporary = array[i]
            j = i
            while j >= gap and array[j-gap] > temporary:
                array[j] = array[j-gap]
                j -= gap
            array[j] = temporary

        gap //= 2

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
    shellsort(list)
    stop = time.time()

    if sortCheck(list):
        g.write("Sortat corect! Durata: " + str(stop - start) + " secunde" + "\n")
    else:
        g.write("Sortat incorect!" + "\n")

f.close()
g.close()
