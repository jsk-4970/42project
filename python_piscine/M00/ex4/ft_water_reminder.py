def ft_water_reminder():
	day = int(input("Days since last watering: "))
	if day >= 2:
		print("Water the plant!")
	else:
		print("Plants are fine.")