from HeapPriorityQueue import HeapPriorityQueue as Heap


def HuffmanCode(freq_table):
    h = Heap()
    for i in range(len(freq_table)):
        h.insert(freq_table[i][1], freq_table[i][0])
    while(len(h) != 1):
        fir = h.remove_min()
        sec = h.remove_min()
        newKey = fir[0] + sec[0]
        newVal = '[' + fir[1] + '] [' + sec[1] + ']'
        h.insert(newKey, newVal)
    return h.min()


if __name__=="__main__":
    s = "abracadabra"
    f = [('a', 5), ('b', 2), ('r', 2), ('c', 1), ('d', 1)]
    e = HuffmanCode(f)
    print(e)
