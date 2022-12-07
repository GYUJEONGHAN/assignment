from PriorityQueue import PriorityQueue


class HeapPriorityQueue(PriorityQueue):
    """Heap implementation of PriorityQueue.
    Heap is implemented by 0-indexed list."""

    def __init__(self):
        self._data = []

    def __len__(self):
        return len(self._data)

    def __repr__(self):
        return self._data

    def __str__(self):
        return str(self._data)

    def _parent(self, idx):
        return (idx - 1) // 2

    def _left(self, idx):
        return idx * 2 + 1

    def _has_left(self, idx):
        return self._left(idx) < len(self)

    def _right(self, idx):
        return idx * 2 + 2

    def _has_right(self, idx):
        return self._right(idx) < len(self)

    def _swap(self, i, j):
        self._data[i], self._data[j] = self._data[j], self._data[i]

    def _upheap(self, idx):
        parent = self._parent(idx)
        if idx > 0 and self._data[idx] < self._data[parent]:
            self._swap(idx, parent)
            self._upheap(parent)

    def _downheap(self, idx):
        if self._has_left(idx):
            left = self._left(idx)
            small = left
            if self._has_right(idx):
                right = self._right(idx)
                if self._data[right] < self._data[small]:
                    small = right
            if self._data[small] < self._data[idx]:
                self._swap(idx, small)
                self._downheap(small)

    def insert(self, key, value):
        """Add a key-value pair."""
        self._data.append(self._Item(key, value))
        self._upheap(len(self) - 1)

    def min(self):
        """Return (key,value) tuple with minimum key.
        Raise Empty exception if empty."""
        if self.is_empty():
            raise IndexError('Priority Queue is empty')

        return self._data[0].key(), self._data[0].value()

    def remove_min(self):
        """Remove and return (key,value) tuple with minimum key.
        Raise Empty exception if empty."""
        if self.is_empty():
            raise IndexError('Priority Queue is empty')

        self._swap(0, len(self) - 1)
        item = self._data.pop()
        self._downheap(0)
        return item.key(), item.value()


if __name__ == "__main__":
    S = [7, 4, 8, 2, 5, 3, 9]
    T = []

    print(f'Unsorted: {S}')
    PQ = HeapPriorityQueue()
    for v in S:
        PQ.insert(v, v)

    print(f'End of pase 1: {PQ}')

    for _ in range(len(PQ)):
        T.append(PQ.remove_min()[1])

    print(f'Sorted: {T}')
