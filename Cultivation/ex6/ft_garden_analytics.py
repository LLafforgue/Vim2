class Plant:
    def __init__(self, name: str, height: int):
        self.name = name
        self.height = height
        self.description = f'{name} : {height}cm'

    def status(self):
        print({self.description})


class FloweringPLant(Plant):
    def __init__(self, name: str, height: int, color: str):
        super().__init__(name, height)
        self.types = "Flowering Plants"
        self.color = color
        self.description = f'{name} : {height}cm, {color} flowers (blooming)'


class PrizeFlower(FloweringPLant):
    def __init__(self, name: str, height: int, color: str, prize: int):
        super().__init__(name, height, color)
        self.prize = prize
        self.description = f'{name} : {height}cm, {color} \
flowers (blooming), Prize: ${prize}'

class Garden:
    _instances = []

    def __init__(self, owner: str):
        self.owner = owner
        self.plants = []
        Garden._instances.append(self)

    def add_plant(self, plant):
        self.plants.append(plant)

    def garden_status(self):
        print(f"Garden: {self.owner}")
        for plant in self.plants:
            plant.status()
        print(f"Total plants in garden: {len(self.plants)}\n")

    @classmethod
    def get_all_gardens(cls):
        return cls._instances

class GardenManager:



    @staticmethod
    def get_gardens_report():
        print("=== Garden Network Report ===")
        network = ""
        for _ in Garden.get_all_gardens():
            network += f"{_.owner}: {len(_.plants)} plants | "
        print(network)
        print("=== End of Report ===\n")

    # def owner_report(date)
    # @staticmethod
    # def create_garden_network():

if __name__ == "__main__":
    print("=== Garden Analytics ===")
    garden1 = Garden("Alice")
    garden2 = Garden("Bob")

    rose = PrizeFlower("Rose", 25, "Red", 100)
    sunflower = FloweringPLant("Sunflower", 80, "Yellow")
    cactus = Plant("Cactus", 15)

    garden1.add_plant(rose)
    garden1.add_plant(cactus)
    garden2.add_plant(sunflower)

    garden1.garden_status()
    garden2.garden_status()

    GardenManager.get_gardens_report()

