"""
알고리즘(M013-1)
최소 동전 거스름돈 문제

작성자: 201821133 한규정
작성일: 2022.11.15(화)
"""

import sys

def cal_change(coin_kind, change, min, uc):
    for i in range(change + 1):
        count = i
        new = 1
        for j in [c for c in coin_kind if c <= i]:
            if min[i - j] + 1 < count:
                count = min[i - j] + 1
                new = j
        min[i] = count
        uc[i] = new
    return min[change]

def print_change(coin_kind, change, uc):
    change_cp = change
    change_list = []
    while change > 0:
        cur = uc[change]
        change_list.append(uc[change])
        change = change - cur
    print(f'{change_cp}: ', end = '')
    for j in range(len(coin_kind)):
        print(f'{coin_kind[j]}({change_list.count(coin_kind[j])}) ', end='')
    print()


while True:
    input_list = list(map(int, sys.stdin.readline().split()))
    if int(input_list[len(input_list) - 1]) == 0:
        input_list.pop(-1) #0을 제거
        break
    else:
        print('거스름돈이 0이 아닙니다. 재입력하세요: ', end='')

coin_kind = []
changes = []

for i in range(len(input_list)):
    if i == 0:
        continue
    elif i <= int(input_list[0]):
        coin_kind.append(int(input_list[i]))
    elif i <= (len(input_list) - 1):
        changes.append(int(input_list[i]))



for i in range(len(changes)):
    uc = [0] * (changes[i] + 1)
    count = [0] * (changes[i] + 1)

    cal_change(coin_kind, changes[i], count, uc)
    print_change(coin_kind, changes[i], uc)