from CList import CList
c1 = CList()
c1.insert(1)
c1.insert(2)
c1.insert(3)



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


a = find_clist_middle_node(c1)
print(a)

