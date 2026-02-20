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
        return f"{self.name}: {self.height}cm, {self.age}days old"

class Flower(Plant):
	def __init__(self, name: str, height: int, age: int, color: str):
		super().__init__(name, height, age)
		self.color = color
	def get_info(self):
		return f"{self.name} (Flower): {self.height}cm, {self.age}days, Color: {self.color}\n{self.name} is blooming beautifully"

class Tree(Plant):
	def __init__(self, name: str, height: int, age: int, diameter: int):
	    super().__init__(name, height, age)
		self.diameter = diameter
	def get_info(self):
		return f"{self.name} (Tree): {self.height}cm, {self.age}days, Diameter: {self.diameter}cm\n{self.name} proivides 78 square meters of shade"

class Vegetable(Plant):
	def __init__(self, name: str, height: int, age: int, season: str):
		super().__init__(name, height, age)
		self.season = season
	def get_info(self):
		return f"{self.name} (Vegetable): {self.height}cm, {self.age}days, {self.season}harvest\n{self.name} is rich in vitamin C"

def ft_plant_types():
	print("=== Garden Plant Types ===")
	rose = Flower("Rose", 25, 30, "red")
	oak = Tree("Oak", 500, 1825, 50)
	tomato = Vegetable("Tomato", 80, 90, "summer")
	print(rose.get_info())
	print(oak.get_info())
	print(tomato.get_info())

if __name__ == "__main__":
	ft_plant_types();
