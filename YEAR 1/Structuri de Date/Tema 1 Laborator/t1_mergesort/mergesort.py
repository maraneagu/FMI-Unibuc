import random
import time

def merge(array, left, middle, right):
    i = left
    j = middle+1
    aux = []
    while i <= middle and j <= right:
        if array[i] <= array[j]:
            aux.append(array[i])
            i += 1
        else:
            aux.append(array[j])
            j += 1
    aux.extend(array[i:middle+1])
    aux.extend(array[j:right])

    array[left:right+1] = aux[:]

def mergesort(array, left, right):
    if left < right:
        middle = (left+right)//2
        mergesort(array, left, middle)
        mergesort(array, middle+1, right)
        merge(array, left, middle, right)

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
    length = len(list)

    start = time.time()
    mergesort(list, 0, length-1)
    stop = time.time()

    if sortCheck(list):
        g.write("Sortat corect! Durata: " + str(stop - start) + " secunde" + "\n")
    else:
        g.write("Sortat incorect!" + "\n")

f.close()
g.close()

