hashtable=[[] for _ in range(10)]

def hashfunction(key):
    return hash(key)%10

def insert(key, value):
    index=hashfunction(key)
    chain=hashtable[index]
    chain.append((key,value))

def delete(key):
    index=hashfunction(key)
    chain=hashtable[index]
    for item in chain:
        if item[0]==key:
            chain.remove(item)
            print("Key deleted")
            return
    print("Item not found!")

def search(key):
    index=hashfunction(key)
    chain=hashtable[index]
    for item in chain:
        if key==item[0]:
            print(item[1])
            return


def display():
    for i,chain in enumerate(hashtable):
        print(f"\nindex {i}: ",end="")
        for item in chain:
            print("\tkey:%d value:%s"%(item[0],item[1]),end="")
    return
    

insert(1,"apple")
insert(2,"ball")
insert(2,"banana")
insert(3,"cat")
insert(4,"dog")

# delete(3)

search(3)

display()