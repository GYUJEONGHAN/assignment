class DList:
    class _Node:
        def __init__(self, element, prev, next):
            self._element = element
            self._prev = prev
            self._next = next

        def element(self):
            return self._element

        def next(self):
            return self._next

        def prev(self):
            return self._prev

        def set_element(self, element):
            self._element = element

        def set_next(self, next):
            self._next = next

        def set_prev(self, prev):
            self._prev = prev

        def __str__(self):
            return str(self._element)

        def __repr__(self):
            return str(self)

    def __init__(self):
        self._header = self._Node(None, None, None)
        self._trailer = self._Node(None, None, None)
        self._header._next = self._trailer
        self._trailer._prev = self._header
        self._size = 0

    def __len__(self):
        return self._size

    def __str__(self):
        """Returns the string representation and the number of elements"""
        p = self._header._next
        ret_str = '{}: '.format(self._size)
        ret_str += 'Header'
        while p is not self.trailer():
            ret_str += ' <-> {}'.format(p)
            p = p._next
        ret_str += ' <-> Trailer'
        return ret_str  # f"{count}:" + '<->'.join(elements)

    def __repr__(self):
        return str(self)

    def is_empty(self):
        # return (self._header._next == self._trailer) and (self._trailer._prev == self._header)
        return self._size == 0

    def header(self):
        return self._header

    def trailer(self):
        return self._trailer

    def insert_between(self, element, predecessor, successor):
        """Add an element between predecessor and successor, and return a new node"""
        new_node = self._Node(element, predecessor, successor)
        predecessor._next = new_node
        successor._prev = new_node
        self._size += 1
        return new_node

    def insert_after(self, element, p):
        if p is self._trailer:
            return None
        else:
            return self.insert_between(element, p, p._next)

    def insert_before(self, element, p):
        if p is self._header:
            return None
        else:
            return self.insert_between(element, p._prev, p)

    def insert_first(self, element):
        return self.insert_after(element, self._header)

    def insert_last(self, element):
        return self.insert_before(element, self._trailer)

    def delete_node(self, node):
        """Delete non-sentinel node and return its element"""
        if (node is self._header) or (node is self._trailer):
            return None

        predecessor = node._prev
        successor = node._next
        predecessor._next = successor
        successor._prev = predecessor
        self._size -= 1
        element = node._element
        node._prev = node._next = node._element = None # clean deleted node safely
        return element


if __name__ == '__main__':
    dll = DList()
    print(f"Creating an empty dll {dll} with header={dll.header()} and trailer={dll.trailer()}")

    what = dll.insert_first(2)
    print(f"Inserting {what} at header...done. {dll}")
    
    what = dll.insert_last(4)
    print(f"Inserting {what} at trailer...done. {dll}")
    
    at = dll.header().next()
    what = dll.insert_after(3, at)
    print(f"Inserting {what} at after {at}...done. {dll}")

    what = dll.insert_before(1, at)
    print(f"Inserting {what} at before {at}...done. {dll}")

    what_element = dll.delete_node(what)
    print(f"Deleting {what_element}...done. {dll}")
