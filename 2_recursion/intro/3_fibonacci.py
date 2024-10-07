
def fibonacci(n, cache):
    if n in cache: 
        return cache[n]
    
    if(n==0 or n==1):
        return n
    
    cache[n] = fibonacci(n-1, cache) + fibonacci(n-2, cache)
    return cache[n]




def main():
    cache = {}
    print(fibonacci(10, cache))
    
if __name__ == "__main__":
    main()