#!/usr/bin/env python3


class Plant:
    def __init__(self, name: str, height: int):
        self.name = name
        self.height = height
        self.initial_height = height

    def update_height(self):
        self.height += 1

    def update_age(self):
        self.age += 1

    def get_info(self):
        return f"{self.name}: {self.height}cm"


class FloweringPlant(Plant):
    def __init__(self, name: str, height: int, flower_color: str):
        super().__init__(name, height)
        self.flower_color = flower_color

    def get_info(self):
        return f"{self.name}: {self.height}cm, {self.flower_color} flowers (blooming)"


class PrizeFlower(FloweringPlant):
    def __init__(self, name: str, height: int, flower_color: str, prize: int):
        super().__init__(name, height, flower_color)
        self.prize = prize

    def get_info(self):
        return f"{self.name}: {self.height}cm, {self.flower_color} flowers (blooming), Prize points: {self.prize}"


class GardenManeger:
    total_plants = 0

    def __init__(self, owner: str):
        self.owner = owner
        self.plants = []
        GardenManeger.total_plants += 1

    def add_plant(self, plant: Plant):
        self.plants.append(plant)
        print(f"Addded {plant.name} to {self.owner}'s garden")

    def help_all_grow(self):
        print(f"Alice is helping all plants grow...")
        for plant in self.plants:
            plant.update_height()
            print(f"{plant.name} grew 1cm")

    def get_garden_scores(self) -> int:
        scores = 0
        for plant in self.plants:
            scores += plant.height
        return scores

	@staticmethod
	def height_validator(height: int) -> bool:
		return height > 0
	
    def get_garden_report(self):
        print("\n=== Alice's Garden Report ===")
        regular = 0
        floating = 0
        prize = 0

        for plant in self.plants:
            if isinstance(plant, PrizeFlower):
                prize += 1
            elif isinstance(plant, FloweringPlant):
                floating += 1
            else:
                regular += 1
            print(plant.get_info())
            print(f"Plants added: {len(self.plants)}, Total growth: {self.get_garden_scores()}cm")
        print(f"Plant types: {regular} regular, {floating} flowering, {prize} prize")
		print(f"Height validation test: {self.height_validator(plant.height)}")
		print(f"Garden scores - {self.owner}: {self.get_garden_scores()} points")
		print(f"Totak gardens managed: {GardenManeger.total_plants}")


def ft_garden_analytics():
    print("=== Garden Management System Demo ===\n")
    plant1 = Plant("Oak Tree", 100)
    plant2 = FloweringPlant("Rose", 20, "red")
    plant3 = PrizeFlower("Sunflower", 15, "purple", 10)
    alice = GardenManeger("Alice")
    alice.add_plant(plant1)
    alice.add_plant(plant2)
    alice.add_plant(plant3)
    alice.help_all_grow()
    alice.get_garden_report()


if __name__ == "__main__":
    ft_garden_analytics()
