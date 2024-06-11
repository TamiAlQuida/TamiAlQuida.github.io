import mmap

# Open the shared memory region
with open('/dev/shm/tickers', 'r') as f:
    # Map the shared memory region into the address space
    mm = mmap.mmap(f.fileno(), 0, access=mmap.ACCESS_READ)

    # Read the tickers list from the shared memory region
    tickers = mm.readline().decode('utf-8').strip().split(',')
    # print("Tickers:", tickers) # tickers with all the 1024 values
    tickers.pop(-1) # remove the unnecessary \x00 values
    print(tickers)

    # Close the shared memory region
    mm.close()