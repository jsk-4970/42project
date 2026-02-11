#!/usr/bin/env python3

class Plant:
	def __init__(self, name: str, height: int, age: int):
		self.name = name
		self.height = height
		self.initial_height = height
		self.age = age
	def update_height(self):
		self.height += 1
	def update_age(self):
		self.age += 1
	def get_info(self):
		return (f"{self.name}: {self.height}cm, {self.age}days old")

def ft_plant_factory():
	
	raw_data = [
    ("Rose", 25, 30),
    ("Sunflower", 80, 45),
    ("Cactus", 5, 90),
    ("Oak", 200, 365),
    ("Fern", 15, 120)
	]
	plants = []
	print("=== Plant Factory Output===")
	for name, height, age in raw_data:
		new_plant = Plant(name, height, age)
		plants.append(new_plant)
		print(f"Created: {new_plant.get_info()}")
	print(f"\nTotal plants created: {len(plants)}")

if __name__ == "__main__":
	ft_plant_factory()
	
	
