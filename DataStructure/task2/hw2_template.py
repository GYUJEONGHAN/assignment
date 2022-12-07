from SList import SList
from DList import DList
from CList import CList

# 2.7
def merge_slists(x, y):
    def find_end(lst):
        a = x._head
        while a:
            if a.next() == None:
                return a
            a = a._next

    find_end(x)._next = y._head
    x._size = y._size + y._size
    return x
    raise NotImplementedError

# 2.9
def reverse_slist(x):
    x.reverse_iteratively(x.head())
    return x
    raise NotImplementedError

# 2.12
def find_slist_middle_node(x):
    if x._head == None:
        return x._head
    fast = x._head.next()
    normal = x._head

    while fast != None:
        fast = fast.next()
        if fast != None:
            normal = normal.next()
            fast = fast.next()
    return normal
    raise NotImplementedError


# Finding the middle node of the DList
def find_dlist_middle_node(x):
    if x._header != None:
        slow = x._header
        fast = x._header
        while (fast != None) and (fast.next() != None) and (fast.next().next() != None) :
            slow = slow.next()
            fast = fast.next().next()
        return slow
    raise NotImplementedError


# Finding the middle node of the CList
def find_clist_middle_node(x):
    fast = x.first()
    slow = x.first()
    while fast != x.last():
        fast = fast.next()
        if fast != x.last():
            slow = slow.next()
            fast = fast.next()
    return slow
    raise NotImplementedError


if __name__ == "__main__":
    # for test 2.7
    x = SList()
    y = SList()
    for i in range(10):
        x.insert_last(i*2+1)
        y.insert_last(i*2)
    print(x)
    print(y)
    z = merge_slists(x, y)
    print(z)

    # for test 2.9
    x = SList()
    for i in range(10):
        x.insert_last(i*2)
    print(x)

    reverse_slist(x)
    print(x)

    # for test 2.12
    x = SList()
    y = DList()
    z = CList()
    for i in range(10):
        x.insert_last(i*2)
        y.insert_last(i*2)
        z.insert(i*2)

    print(x)
    m = find_slist_middle_node(x)
    print("Middle node is {}".format(m))

    print(y)
    m = find_dlist_middle_node(y)
    print("Middle node is {}".format(m))

    print(z)
    m = find_clist_middle_node(z)
    print("Middle node is {}".format(m))
