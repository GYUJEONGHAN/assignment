from ch02.SList import SList

class LeakyStack:
    def __init__(self, maxCap = 10):
        self._items = SList()
        self._maxCap = maxCap

    def __len__(self):
        return len(self._items)

    def __str__(self):
        return str(self._items)

    def __repr__(self):
        return str(self._items)

    def is_empty(self):
        return self._items.is_empty()

    def push(self, item):
        self._items.insert_first(item)
        if (self.__len__() > self._maxCap):
            assert not self.is_empty()
            self._items.delete_last()

    def pop(self):
        assert not self.is_empty()
        return self._items.delete_first()

    def top(self):
        assert not self.is_empty()
        return self._items.head()


def evaluate_infix_expression(exp):
    i = 0
    operator = []
    number = []
    while (i < len(exp)):
        if (exp[i] >= '0' and exp[i] <= '9'):
            cn = []
            j = i
            while (j < len(exp) and exp[j] >= '0' and exp[j] <= '9'):
                cn.append(exp[j])
                j += 1
            i = (j - 1)
            number.append(int(''.join(cn)))
        elif (exp[i] == '('):
            operator.append(exp[i])
        elif (exp[i] == ')'):
            while (operator[-1] != '('):
                number.append(oper_execution(operator.pop(), number.pop(), number.pop()))
            operator.pop()
        elif (exp[i] == '+' or exp[i] == '*' or exp[i] == '-' or exp[i] == '/'):
            while ((len(operator) != 0) and (oper_order(exp[i], operator[-1]))):
                number.append(oper_execution(operator.pop(), number.pop(), number.pop()))
            operator.append(exp[i])
        i = i + 1
    while (len(operator) != 0):
        number.append(oper_execution(operator.pop(), number.pop(), number.pop()))
    return number.pop()

def oper_order(op1, op2):
    if (op2 == '(' or op2 == ')'):
        return False
    if ((op1 == '*' or op1 == '/') and (op2 == '+' or op2 == '-')):
        return False
    else:
        return True

def oper_execution(operator, a, b):
    if operator == '+':
        return a+b
    elif operator == '-':
        return b-a
    elif operator == '/':
        return b/a
    elif operator == '*':
        return a*b
    else:
        return 0


if __name__ == "__main__":
    address = LeakyStack(5)
    address.push(1)
    address.push(2)
    address.push(3)
    address.push(4)
    address.push(5)
    print(address)
    what = address.pop()
    print("Pop {} becomes {}".format(what, address))
    address.push(6)
    print(address)
    address.push(7)
    print("Top {} element at {}".format(address.top(), address))
    what = address.pop()
    print("{} is popped at {}".format(what, address))

    # Test for evaluation of infix expression

    exp = "14 - 3 * 2 + 7"
    print(f"Evaluation of \'{exp}\' is {evaluate_infix_expression(exp)}")
