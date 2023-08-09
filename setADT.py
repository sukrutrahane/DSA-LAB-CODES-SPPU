class Set:
    def __init__(self):
        self.elements = []

    def add(self, element):
        if element not in self.elements:
            self.elements.append(element)

    def remove(self, element):
        if element in self.elements:
            self.elements.remove(element)

    def contains(self, element):
        return element in self.elements

    def size(self):
        return len(self.elements)

    def union(self, other_set):
        new_set = Set()
        new_set.elements = self.elements.copy()
        for element in other_set.elements:
            if element not in new_set.elements:
                new_set.elements.append(element)
        return new_set

    def intersection(self, other_set):
        new_set = Set()
        for element in self.elements:
            if element in other_set.elements:
                new_set.add(element)
        return new_set

    def difference(self, other_set):
        new_set = Set()
        for element in self.elements:
            if element not in other_set.elements:
                new_set.add(element)
        return new_set

    def is_subset(self, other_set):
        for element in self.elements:
            if element not in other_set.elements:
                return False
        return True

set1 = Set()
set1.add(1)
set1.add(2)
set1.add(3)

set2 = Set()
set2.add(3)
set2.add(4)
set2.add(5)

print("Set 1: ",set1.elements) 
print("Set 2: ",set2.elements)

set3 = set1.union(set2)
print("Union:",set3.elements)  # Output: [1, 2, 3, 4, 5]

set4 = set1.intersection(set2)
print("Intersection:",set4.elements)  # Output: [3]

set5 = set1.difference(set2)
print("Difference:",set5.elements)  # Output: [1, 2]

print("Is set1 subset of set 2: ",set1.is_subset(set2)) 
print("Is set2 subset of set 1: ",set2.is_subset(set1)) 
