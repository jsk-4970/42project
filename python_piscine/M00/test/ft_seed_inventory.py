def ft_seed_inventory(seed_type: str, quantiy: int, unit: str) -> None:
	if unit == "packets":
		print(f"{seed_type} seeds: {quantiy} {unit} available")
	elif unit == "grams":
		print(f"{seed_type} seeds: {quantiy} {unit} total")
	elif unit == "area":
		print(f"{seed_type} seeds: covers {quantiy} square meters")
