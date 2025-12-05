class Plant:
    def __init__(self, name: str, height: int, age: int):
        self.name = name
        self.height = height
        self.age = age
        self.types = "none"
        self.char = "none"

    def status(self):
        print(f"{self.name} ({self.types}): {self.height}cm, {self.age} days, {self.char}")


class Flower(Plant):
    def __init__(self, name: str, height: int, age: int):
        super().__init__(name, height, age)
        self.types = "Flower"

    def color(self, color : str):
        self.color = color
        self.char = f"{self}"d


class Tree(Plant):
    def __init__(self, name: str, height: int, age: int):
        super().__init__(name, height, age)
        self.types = "Tree"



class Vegetable(Plant):
    def __init__(self, name: str, height: int, age: int):
        super().__init__(name, height, age)
        self.types = "Vegetable"

if __name__ == "__main__":
    print("=== Garden Plant Types ===")
    x = Tree("Pin", 120, 651)
    x.status()
