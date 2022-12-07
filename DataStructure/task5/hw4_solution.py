from HeapPriorityQueue import HeapPriorityQueue as Heap


def HuffmanCode(freq_table):
    """Generating Huffman code for input frequency table.
    Frequency table is the list of (alphabet, frequency) pairs.
    This code should return the last entry of heap in tihs homework."""

    # Setp 1: Create an empty heap
    h = Heap()

    # Setp 2: Insert (key, val) pair into the heap, where key=frequency and val=alphabet
    for (val, key) in freq_table:
        h.insert(key, val)

    # Step 3: Until there is only one pair in the heap,
    #             - Execute remove_min twice
    #             - Create a new (sum of the two keys, concatenation of two values) pair
    #                 * Two values, provided val1 and val2, should be concatenated as f"[{val1}] [{val2}]"
    #             - Insert the new pair into the heap
    while len(h) > 1:
        (e1_key, e1_val) = h.remove_min()
        (e2_key, e2_val) = h.remove_min()
        e_key = e1_key + e2_key
        e_val = f'[{e1_val}] [{e2_val}]'
        h.insert(e_key, e_val)

    # Setp 4: Return the last entry of the heap
    return h.remove_min()


if __name__=="__main__":
    s = "abracadabra"
    f = [('a', 5), ('b', 2), ('r', 2), ('c', 1), ('d', 1)]
    e = HuffmanCode(f)
    print(e)
