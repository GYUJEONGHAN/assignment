
def iterative_merge_sort(x):
    """재귀 없이 list x를 merge sort / 반환값 없이 리스트만 수정"""
    num = len(x)
    tmp = [0] * num
    k = 1
    while (k < num):
        left = 0
        while ((left + k) < num):
            right = left + k
            rend = right + k
            if (rend > num):
                rend = num
            m = left
            i = left
            j = right

            while (i < right and j < rend):
                if (x[i] <= x[j]):
                    tmp[m] = x[i]
                    i += 1
                else:
                    tmp[m] = x[j]
                    j += 1
                m += 1
            while (i < right):
                tmp[m] = x[i]
                i += 1
                m += 1
            while (j < rend):
                tmp[m] = x[j]
                j += 1
                m += 1
            m = left
            while (m < rend):
                x[m] = tmp[m]
                m += 1
            left += k * 2
        k *= 2