#!/usr/bin/env python3

class Plant():
	def __init__(self, name: str, height: int, age: int):
		self.name = name
		self.height = height
		self.initial_height = height
		self.age = age
	def update_height(self):
		self.height += 1
	def update_age(self):
		self.age += 1
	def create_garden_network(self, other_plant):
	def get_info(self):
		return (f"{self.name}: {self.height}cm, {self.age}days old")

class FloweringPlant(Plant):
	def __init__(self, name: str, height: int, age: int, flower_color: str):
		super().__init__(name, height, age)
		self.flower_color = flower_color
	def get_info(self):
		return (f"{self.name}: {self.height}cm, {self.age}days old, {self.flower_color} flowers")

class PrizeFlower(FloweringPlant):
	def __init__(self, name: str, height: int, age: int, flower_color: str, prize: str):
		super().__init__(name, height, age, flower_color)
		self.prize = prize
	def get_info(self):
		return (f"{self.name}: {self.height}cm, {self.age}days old, {self.flower_color} flowers, won {self.prize}")

def ft_gaeden_analytics():
	plant1 = Plant("Sunflower", 30, 10)
	plant2 = FloweringPlant("Rose", 20, 5, "red")
	plant3 = PrizeFlower("Orchid", 15, 3, "purple", "Best in Show")
	print(plant1.get_info())
	print(plant2.get_info())
	print(plant3.get_info())

if __name__ == "__main__":
	ft_plant_factory()
