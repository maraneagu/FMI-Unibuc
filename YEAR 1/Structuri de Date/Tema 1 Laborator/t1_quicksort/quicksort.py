import random
import time
import sys

def partition(array, left, right):
    pivot_index = left
    pivot = array[pivot_index]
    length = len(array)

    while left < right:
        while left < length and array[left] <= pivot:
            left += 1
        while array[right] > pivot:
            right -= 1
        if(left < right):
            array[left], array[right] = array[right], array[left]

    array[right], array[pivot_index] = array[pivot_index], array[right]
    return right

def quickSort(array, left, right):
    if left < right:
        p = partition(array, left, right)
        quicksort(array, left, p-1)
        quicksort(array, p+1, right)

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

    sys.setrecursionlimit(10 ** 8)

    start = time.time()
    quicksort(list, 0, length-1)
    stop = time.time()

    if sortCheck(list):
        g.write("Sortat corect! Durata: " + str(stop - start) + " secunde" + "\n")
    else:
        g.write("Sortat incorect!" + "\n")

f.close()
g.close()