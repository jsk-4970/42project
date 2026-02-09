def ft_count_harvest_recursive():
    day = int(input("Days until harvest: "))

    def countdown(days, count):
        if days <= 0:
            print("Harvest time!")
        else:
            count += 1
            print(f"Day {count}")
            countdown(days - 1, count)

    countdown(day, 0)
