class GardenError(Exception):
    """ A basic error for garden problems """
    message = "Error in Garden : "


class PlantError(GardenError):
    """ For problems with plants  """

class WaterError(GardenError):
    """ or problems with watering """



def plant_water_delay(name: str, days: int):
    if days > 10:
        raise PlantError(f"Caught PlantError: The {name} plant is wilting!")
    elif days < 0:
        raise ValueError("Delay must be >= 0")
    else:
        return f"Good delay! The {name} needs to be watered in {10 - days} days."

def water_tank(tank: int):
    if tank < 15 and tank >= 0:
        raise WaterError("Caught WaterError: Not enough water in the tank!")
    elif tank < 0:
        raise ValueError("Tank level must be >= 0")
    else:
        return f"Water tank level is sufficient: {tank} liters available."

def garden_error(name: str, tank: int, days: int):
    if water_tank(tank) and plant_water_delay(name, days):
        return "Garden is healthy and well maintained."
    else:
        raise GardenError("Caught GardenError: General garden issue occurred.")


def test_plantErrors(args: list):
    for i in args:
        try:
            print(plant_water_delay("tomato", i))
        except PlantError as e:
            print(e)
        except ValueError as e:
            print(e)

def test_waterErrors(args: list):
    for i in args:
        try:
            print(water_tank(i))
        except WaterError as e:
            print(e)
        except ValueError as e:
            print(e)

def test_gardenErrors(name: str, tank_args: int, days_args: int):
    try:
        print(garden_error(name, tank_args, days_args))
    except GardenError as e:
        print(e)
    except WaterError as e:
        print(e)
    except PlantError as e:
        print(e)
    except ValueError as e:
        print(e)

if __name__ == "__main__":
    print("=== Custom Garden Errors Demo ===\n")
    print("Testing PlantError...")
    test_plantErrors([0, 15, -2, 5])
    print("\nTesting WaterError...")
    test_waterErrors([20, 10, -5, 30])
    print("\nTesting catching all garden errors...")
    test_gardenErrors("cucumber", 5, 15)

