from HeapPriorityQueue import HeapPriorityQueue as Heap
from BinaryTree2 import BinaryTree


def build_huffman_tree(freq_table):
    h = Heap()
    for (val, key) in freq_table:
        b = BinaryTree()
        b.add_root(val)
        h.insert(key, b)

    while len(h) >= 2:
        (e1_key, e1_val) = h.remove_min()
        (e2_key, e2_val) = h.remove_min()
        e_key = e1_key + e2_key
        b = BinaryTree()
        b.add_root(e_key)
        b.attach(b.root(), e1_val, e2_val)
        h.insert(e_key, b)

    return h.remove_min()

def generate_code(node, code_table, prefix=""):
    if node.left():
        generate_code(node.left(), code_table, prefix + '0')
    if node.right():
            generate_code(node.right(), code_table, prefix + '1')
    if node.left() is None:
        if node.right() is None:
            code_table.append((node.element(), prefix))

def gen_freq_table(s):
    ht = {}
    for i in s:
        if i not in ht:
            ht[i] = 1
        else:
            ht[i] = ht[i] + 1
    l = list(zip(ht.keys(), ht.values()))
    return l


if __name__=="__main__":
    s = "abracadabra"
    f = gen_freq_table(s)
    t = build_huffman_tree(f)
    print(t[1])


    code_tbl = []
    generate_code(t[1].root(), code_tbl, "")
    print(code_tbl)

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
