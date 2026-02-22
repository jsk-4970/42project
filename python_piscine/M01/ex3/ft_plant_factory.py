#!/usr/bin/env python3
"""Plant factory for batch creation."""


class Plant:
    """A plant with name, height, and age."""

    def __init__(self, name: str, height: int, age: int) -> None:
        """Initialize plant with name, height, and age."""
        self.name = name
        self.height = height
        self.age = age

    def get_info(self) -> str:
        """Return formatted plant information."""
        return f"{self.name} ({self.height}cm, {self.age} days)"


def ft_plant_factory() -> None:
    """Create multiple plants from raw data."""
    raw_data = [
        ("Rose", 25, 30),
        ("Oak", 200, 365),
        ("Cactus", 5, 90),
        ("Sunflower", 80, 45),
        ("Fern", 15, 120),
    ]
    plants = []
    print("=== Plant Factory Output ===")
    for name, height, age in raw_data:
        new_plant = Plant(name, height, age)
        plants.append(new_plant)
        print(f"Created: {new_plant.get_info()}")
    print(f"\nTotal plants created: {len(plants)}")


if __name__ == "__main__":
    ft_plant_factory()
