from itertools import product

# takes a directed graph G with edge costs specified by C and a
# starting vertex s
# i) if there is no negative cost cycle reachable from s then it
# returns the distance labels and predecessor information
# ii) else it returns None since distance labels don't make sense and
# the list of vertices in the negative cycle
def bellmanford(G, C, s):
    d = dict()
    p = dict()
    for u in G:
        d[u] = None
        p[u] = None
    d[s] = 0 

    n = len(G.keys())
    for i in range(n-1):
        relaxed = False
        for u in G:
            if d[u] is None:
            	continue    
            for v in G[u]:
                if d[v] is None or d[u] + C[(u, v)] < d[v]:
                    d[v] = d[u] + C[(u, v)]
                    p[v] = u
                    relaxed = True
        if not relaxed:
            break

    for u in G:
        if d[u] is None:
            continue   
        for v in G[u]:
            # detecting a negative cycle
            if d[u] + C[(u, v)] < d[v]:
                d[v] = d[u] + C[(u,v)]
                p[v] = u

                # finding the negative cycle
                hare = p[p[v]]
                tortoise = p[v]
                while hare != tortoise:
                    hare = p[p[hare]]
                    tortoise = p[tortoise] 

                stack = [hare]
                head = stack[-1]
                while p[head] != hare :
                    stack.append(p[head])
                    head = stack[-1] 

                stack.reverse()

                return None, stack

    return d, p

if __name__ == '__main__':
    G = {'s': ['t', 'y'],
         't': ['x', 'y','z'],
         'y': ['z','x'],
         'x': ['t'],
         'z': ['x','s']}
    C = {('s', 't'): 6,
         ('s', 'y'): 7,
         ('t', 'x'): 5,
         ('t', 'z'): -4,
         ('t', 'y'): 8,
         ('y', 'z'): 9,
         ('y', 'x'): -3,
         ('x', 't'): -2,
         ('z', 'x'): 7,
         ('z', 's'): 2}
    s = 's'
    d, p = bellmanford(G, C, s)

    if d is None:
        print 'negative cycle detected:', p
    else:
        for u in G:
            if d[u] is None:
                print u, 'is unreachable'
            else:
                print u, ':', d[u], ':',

                stack = [u]
                head = stack[-1]
                while p[head]:
                    stack.append(p[head])
                    head = stack[-1]

                while stack:
                    print stack.pop(),
                print
