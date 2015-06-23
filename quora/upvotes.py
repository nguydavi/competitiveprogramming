class Interval:
    """Simple interval class"""
    def __init__(self, left, right):
        self.left = left
        self.right = right

    def is_before(self, val):
        return self.right < val

    def is_after(self, val):
        return val < self.left

    def contains(self, val):
        return self.left <= val and val <= self.right

    def __len__(self):
        return self.right - self.left + 1

    def __str__(self):
        return "[{}, {}]".format(self.left, self.right)

    def __repr__(self):
        return self.__str__()

def count_subranges(k):
    """Returns number of subranges in an interval of size k"""
    return k * (k - 1) / 2

def get_inc_intervals(arr):
    """Returns all increasing(= non-decreasing) intervals from arr"""
    res = [Interval(-1, -1)]
    start = -1
    for i in xrange(1, len(arr)):
        if start != -1:
            if arr[i] < arr[i-1]:
                res.append(Interval(start, i-1))
                start = -1
        elif arr[i] >= arr[i-1]:
            start = i-1
    if start != -1:
        res.append(Interval(start, len(arr)-1))

    res.append(Interval(1000000, 1000000))
    return res

def get_partial_subranges(arr):
    """Returns partial sum of all subranges for each interval"""
    partial_subranges = []
    for i in xrange(len(arr)):
        subranges = count_subranges(len(arr[i]))
        if i == 0:
            partial_subranges.append(subranges)
        else:
            partial_subranges.append(partial_subranges[i-1] + subranges)

    return partial_subranges

def find_interval_index(intervals, val):
    """Given an array of sorted non overlapping intervals, find lowerbound index of interval containing val"""
    left = 0
    right = len(intervals) - 1
    while left < right:
        mid = (left + right) / 2
        if intervals[mid].is_before(val):
            left = mid + 1
        else:
            right = mid

    return left

def subranges_in_window(intervals, partial_subranges, start_index, end_index):
    """Computes number of subranges in window [start_index, end_index]"""
    start_interval = find_interval_index(intervals, start_index)
    if not intervals[start_interval].contains(start_index):
        start_interval -= 1
    end_interval = find_interval_index(intervals, end_index)

    res = 0
    if start_interval + 1 < end_interval:
        res += partial_subranges[end_interval - 1] - partial_subranges[start_interval]

    if start_interval == end_interval \
        and intervals[start_interval].contains(start_index) \
        and intervals[start_interval].contains(end_index):
            res += count_subranges(end_index - start_index + 1)
    else:
        if intervals[start_interval].contains(start_index):
            res += count_subranges(intervals[start_interval].right - start_index + 1)
        if intervals[end_interval].contains(end_index):
            res += count_subranges(end_index - intervals[end_interval].left + 1)

    return res

def solve(N, K, votes):
    inc_intervals = get_inc_intervals(votes)
    dec_intervals = get_inc_intervals([x*-1 for x in votes])

    partial_subranges_inc = get_partial_subranges(inc_intervals)
    partial_subranges_dec = get_partial_subranges(dec_intervals)

    start_index = 0
    end_index = K-1
    res = []
    while end_index < N:
        sol = 0

        # Non decreasing subranges in window
        sol += subranges_in_window(inc_intervals, partial_subranges_inc, start_index, end_index)
        # Non increasing subranges in window
        sol -= subranges_in_window(dec_intervals, partial_subranges_dec, start_index, end_index)

        res.append(sol)
        start_index += 1
        end_index += 1

    return res

#
# BRUTE FORCE
#
# def is_inc(arr, start_index, end_index):
#     for i in xrange(start_index+1, end_index+1):
#         if arr[i] < arr[i-1]:
#             return False
#     return True

# def is_dec(arr, start_index, end_index):
#     for i in xrange(start_index+1, end_index+1):
#         if arr[i] > arr[i-1]:
#             return False
#     return True

# def solve_brute_force(N, K, votes):
#     start_index = 0
#     end_index = K-1
#     res = []
#     while end_index < N:
#         sol = 0
#         for i in xrange(K):
#             for j in xrange(1, K-i):
#                 if is_inc(votes, start_index + i, start_index + i + j):
#                     sol += 1
#         for i in xrange(K):
#             for j in xrange(1, K-i):
#                 if is_dec(votes, start_index + i, start_index + i + j):
#                     sol -= 1

#         res.append(sol)
#         start_index += 1
#         end_index += 1

#     return res

# from random import randint

if __name__ == "__main__":
    # while True:
    #     try:
            N, K = [int(x) for x in raw_input().split()]
            votes = [int(x) for x in raw_input().split()]

            # N = randint(1, 100000)
            # K = randint(1, N)
            # votes = [0]*N
            # for i in xrange(N):
            #     votes[i] = randint(0, 1000000000)

            ans = solve(N, K, votes)
            # ans2 = solve_brute_force(N, K, votes)

            # print ans
            # print ans2
            # if ans != ans2:
            #     print "ERROR"
            #     print N, K
            #     print votes
            #     print
            # print

            for a in ans:
                print a
        # except (EOFError):
        #     break
