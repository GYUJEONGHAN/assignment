from HeapPriorityQueue import HeapPriorityQueue as Heap
from BinaryTree2 import BinaryTree


def build_huffman_tree(freq_table):
    h = Heap()
    for i in range(len(freq_table)):
        h.insert(freq_table[i][1], freq_table[i][0])
    while (len(h) != 1):
        fir = h.remove_min()
        sec = h.remove_min()
        newKey = fir[0] + sec[0]
        newVal = str(newKey) + ' [' + fir[1] + '] [' + sec[1] + ']'
        if(len(h) <= 0):
            newVal = '[' + newVal + ']'
        h.insert(newKey, newVal)
    return h.min()

def generate_code(node, code_table, prefix=""):
    raise NotImplementedError

def gen_freq_table(s):
    appear_list = list(set(s))
    l = []
    for i in appear_list:
        l.append(s.count(i))
    new = list(zip(appear_list, l))
    return new

if __name__=="__main__":
    s = "abracadabra"
    # I will test your code with     
    #s = "In computer science and information theory, a Huffman code is a particular type of optimal prefix code that is commonly used for lossless data compression."

    f = gen_freq_table(s) # f will be or looks like [['a', 5], ['b', 2], ['r', 2], ['c', 1], ['d', 1]]
    t = build_huffman_tree(f) # t is a pair of (key, huffman code tree) for the frequency table f
    print(t[1]) # print the huffman code tree only
                # Output looks like [11 [a] [6 [r] [4 [b] [2 [c] [d]]]]]

    # Now generate codes of alphabets according to the huffman code tree
    code_tbl = []
    generate_code(t[1].root(), code_tbl, "")
    print(code_tbl) # Output looks like [('a', '0'), ('r', '10'), ('b', '110'), ('c', '1110'), ('d', '1111')]

    # Compute how the input string s is encoded by code_tbl
    print(f"Input={s}, Size={len(s)} characters")
    print(f"Encoded=", end="")
    count = 0
    for c in s:
        for alphabet, code in code_tbl:
            if alphabet == c:
                print(code, end="")
                count += len(code)
                break
    print(f", Size={count} bits")
    print("Total gain with respect to ASCII: {}/{} = {:.2f}%".format(count, len(s)*8, count/(len(s)*8)*100))
