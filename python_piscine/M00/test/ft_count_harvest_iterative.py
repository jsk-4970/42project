def ft_count_harvest_iterative():
	days = int(input("Days until harvest: "))
	count = 0
	while days > 0:
		days -= 1
		count += 1
		print(f"Day {count}")
	print("Harvest time!")