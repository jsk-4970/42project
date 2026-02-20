#!/usr/bin/env python3

class Plant:
	def __init__(self, name: str, height: int, age: int):
		self.name = name
		self.height = height
		self.age = age
	def get_info(self):
		return (f"{self.name}: {self.height}cm, {self.age}days old")
	

def ft_garden_data():
	rose = Plant("Rose", 25, 30)
	sunflower = Plant("Sunflower", 80, 45)
	cactus = Plant("Cactus", 15, 120)

	print("=== Garden Plant Registry ==")
	print(rose.get_info())
	print(sunflower.get_info())
	print(cactus.get_info())

if __name__ == "__main__":
	ft_garden_data()