class PriorityQueue:
    """Abstract base class for a priority queue."""

    class _Item:
        def __init__(self, k, v):
            self._key = k
            self._value = v

        def __lt__(self, other):
            return self._key < other.key()  # compare items based on their keys

        def __repr__(self):
            return f'({self._key},{self._value})'

        def key(self):
            return self._key

        def value(self):
            return self._value

    def __len__(self):
        """Return the number of items in the priority queue."""
        raise NotImplementedError('must be implemented by subclass')

    def __repr__(self):
        raise NotImplementedError('must be implemented by subclass')

    def __str__(self):
        raise NotImplementedError('must be implemented by subclass')

    def is_empty(self):  # concrete method assuming abstract len
        """Return True if the priority queue is empty."""
        return len(self) == 0

    def insert(self, key, value):
        """Add a key-value pair."""
        raise NotImplementedError('must be implemented by subclass')

    def min(self):
        """Return but do not remove (k,v) tuple with minimum key.
        Raise Empty exception if empty.
        """
        raise NotImplementedError('must be implemented by subclass')

    def remove_min(self):
        """Remove and return (k,v) tuple with minimum key.
        Raise Empty exception if empty.
        """
        raise NotImplementedError('must be implemented by subclass')
