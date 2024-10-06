
def fibonacci(n, cache):
    if n in cache: 
        return cache[n]
    
    if(n==0):
        return 0
    if(n==1):
        return 1
    
    cache[n] = fibonacci(n-1, cache) + fibonacci(n-2, cache)
    return cache[n]




def main():
    cache = {}
    print(fibonacci(10, cache))
    
if __name__ == "__main__":
    main()