# Growth Simulator

class Plant:
    def __init__(self, name: str, height: int, age: int):
        self.name = name
        self.height = height
        self.age = age

    def status(self):
        print(self.name, ": ", self.height, "cm, ", self.age, " days old", sep='')

    def growth(self, days):
        self.age += days
        self.height += days*2
        self.status()
        if (days == 6):
            print(f"Growth this week: +{days*2}cm\n")
        else:
            print(f"Growth on {days} days: +{days*2}cm\n")


if __name__ == "__main__":
    print("=== Day 1 ===")
    rose = Plant("Rose", 25, 30)
    rose.status()
    sunflower = Plant("Sunflower", 80, 45)
    sunflower.status()
    cactus = Plant("Cactus", 15, 120)
    cactus.status()
    print("\n=== Day 7 ===")
    rose.growth(6)
    sunflower.growth(7)
    cactus.growth(6)
