class SList:
    class _Node:
        def __init__(self, element, next = None):
            self._element = element
            self._next = next

        def element(self):
            return self._element

        def next(self):
            return self._next

        def set_element(self, element):
            self._element = element

        def set_next(self, next):
            self._next = next

        def __str__(self):
            return str(self._element)

        def __repr__(self):
            return repr(self._element)

    def __init__(self):
        """Create a singly linked list that contains head and tail"""
        self._head = None
        self._tail = None
        self._size = 0

    def __len__(self):
        """len(SList) returns the number of elements in SList"""
        return self._size

    def __str__(self):
        """Returns the string representation and the number of elements"""
        p = self._head
        ret_str = '{}: '.format(self._size)
        while p:
            ret_str += str(p.element())+' -> '
            p = p.next()
        ret_str += 'None'
        return ret_str

    def __repr__(self):
        return str(self)

    def is_empty(self):
        return self._head is None

    def head(self):
        return self._head

    def tail(self):
        return self._tail

    def insert_first(self, element):
        """Insert a node of an element in front of head, then return the head node"""
        if self.is_empty():  # update both head and tail info
            p = self._Node(element)
            self._head = self._tail = p
        else:  # update head info only
            self._head = self._Node(element, self._head)

        self._size += 1
        return self._head

    def delete_first(self):
        """Delete the head node, then return the deleted node"""
        assert self._size

        if self._size == 1:  # there is only one node in SLL
            p = self._head
            self._head = self._tail = None
        else:
            p = self._head
            self._head = self._head.next()

        self._size -= 1
        return p

    def insert_after(self, element, p):
        """Insert an element after a node p. Caution: p should not be None"""
        assert p

        p._next = self._Node(element, p._next)
        if p == self._tail:  # update tail info
            self._tail = p._next

        self._size += 1
        return p._next

    def delete_after(self, p):
        """Delete a node after p, the return the deleted node. Caution: p should not be None"""
        assert p

        if p == self._tail:  # Cannot delete a node beyond tail
            raise IndexError("Underflow")

        q = p._next
        p._next = q.next()
        if q == self._tail:
            self._tail = p

        self._size -= 1
        return q

    def insert_last(self, element):
        """Insert a node of an element at tail."""
        if self.is_empty():  # update both head and tail info
            p = self._Node(element)
            self._head = self._tail = p
            self._size += 1
            return p

        return self.insert_after(element, self._tail)

    def delete_last(self):
        """Delete a node at tail"""
        assert self._size

        p = self._head
        if self._size == 1:  # there is only one node in SLL
            self._head = self._tail = None
            self._size -= 1
            return p

        # Find the penultimate node of SList
        while p._next._next:
            p = p._next

        return self.delete_after(p)

    def reverse_recursively(self, node):
        if node is None or node._next is None:
            self._head = node
            return
        head = node
        tail = node._next
        self.reverse_recursively(tail)
        tail._next = head
        head._next = None
        self._tail = head

    def reverse_iteratively(self, curr):
        head = self._head
        prev = None
        while curr:
            next = curr._next
            curr._next = prev
            prev = curr
            curr = next
        self._head = prev
        self._tail = head


if __name__ == "__main__":
    s1 = SList()
    # insert at head
    s1.insert_first("1")
    s1.insert_last("2")
    s1.insert_last("3")
    s1.insert_last("4")

    s1.reverse_recursively(s1.head())
    print(f"Reversing a list recursively...done. {s1} with head={s1.head()} and tail={s1.tail()}")

    s1.reverse_iteratively(s1.head())
    print(f"Reversing a list iteratively...done. {s1} with head={s1.head()} and tail={s1.tail()}")
    


