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
	
def ft_plant_growth():
	rose = Plant("Rose", 25, 30)
	print("=== Day 1 ===")
	print(rose.get_info())
	for i in range(7):
		rose.update_height()
		rose.update_age()
	print("=== Day 7 ===")
	print(rose.get_info())
	print(f"Growth this week: +{rose.height - rose.initial_height}cm")
	

if __name__ == "__main__":
	ft_plant_growth()