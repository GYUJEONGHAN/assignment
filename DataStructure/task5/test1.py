from HeapPriorityQueue import HeapPriorityQueue as Heap
from BinaryTree2 import BinaryTree

def build_huffman_tree(freq_table):
    h = Heap()
    for (val, key) in freq_table:
        h.insert(key, val)
    while len(h) > 1:
        btree1 = BinaryTree()
        btree2 = BinaryTree()
        (e1_key, e1_val) = h.remove_min()
        (e2_key, e2_val) = h.remove_min()
        btree1.set_root(e1_val)
        btree2.set_root(e2_val)

        e_key = e1_key + e2_key
        e_val = BinaryTree()
        e_val.add_left(btree1)
        e_val.add_right(btree2)
        h.insert(e_key, e_val)
    return h.remove_min()

def gen_freq_table(s):
    appear_list = list(set(s))
    l = []
    for i in appear_list:
        l.append(s.count(i))
    new = list(zip(appear_list, l))
    return new

def generate_code(node, code_table, prefix=""):
    raise NotImplementedError


s = "abracadabra"
f = gen_freq_table(s)
t = build_huffman_tree(f)
print(t)
print(t[1])
print(t[1].root)
code_tbl = []
generate_code(t[1].root(), code_tbl, "")
print(code_tbl)
