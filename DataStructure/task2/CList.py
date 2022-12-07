class CList:
    class _Node:
        def __init__(self, element, next=None):
            self._element = element
            self._next = next

        def element(self):
            return self._element

        def next(self):
            return self._next

        def __str__(self):
            return str(self._element)

        def __repr__(self):
            return repr(self._element)

    def __init__(self):
        """Create a circular linked list that contains last as a cursor"""
        self._last = None
        self._size = 0

    def __len__(self):
        """len(CList) returns the number of elements in SList"""
        return self._size

    def __str__(self):
        """Returns the string representation and the number of elements"""
        if self.is_empty():
            return ""
        else:
            ret_str = '{}: '.format(self._size)
            first = self._last.next()
            p = first
            while p.next() != first:
                ret_str += str(p.element())+' -> '
                p = p.next()
            ret_str += str(p.element())
        return ret_str

    def __repr__(self):
        return str(self)

    def is_empty(self):
        return self._last is None

    def first(self):
        if self.is_empty():
            raise Exception("Underflow")
        else:
            return self._last.next()

    def last(self):
        if self.is_empty():
            raise Exception("Underflow")
        else:
            return self._last

    def insert(self, element):
        """Insert a node of an element at the very next of the self._last, then return the first node"""
        if self.is_empty():  # should update last
            p = self._Node(element)
            self._last = p._next = p
        else:  
            self._last._next = self._Node(element, self._last._next)

        self._size += 1
        return self._last._next

    def delete(self):
        """Delete the node at the very next of the self._last, then return the deleted node"""
        assert self._size

        if self._size == 1:  # there is only one node in CLL
            p = self._last
            self._last = None
        else:
            p = self._last._next
            self._last._next = p.next()

        self._size -= 1
        return p


if __name__ == "__main__":
    s = CList()
    s.insert('pear')
    s.insert('cherry')
    s.insert('orange')
    s.insert('apple')
    print(s)
    s.delete()
    print(s)
    s.delete()
    print(s)
    print(s.first())
    print(s.last())
