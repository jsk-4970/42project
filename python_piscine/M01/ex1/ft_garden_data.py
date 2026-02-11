class Plant:
	def __init__(self, name: str, height: int, age: int):
		self.name = name
		self.height = height
		self.age = age
	def get_info(self):
		return (f"{self.name}: {self.height}cm, {self.age}days old")
	

def ft_garden_data():
	rose = Plant(Rose, 25, 30)
	sunflower = Plant(Sunflower, 80, 45)
	cactus = Plant(Cactus, 15, 120)

	print("=== Garden Plant Registry ==")
	print(get_info(rose))
	print(get_info(sunflower))
	print(get_info(cactus))

if __name__ == "main":
	ft_garden_data()