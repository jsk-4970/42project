#!/usr/bin/env python3
"""Plant growth simulator."""


class Plant:
    """A plant that can grow and age over time."""

    def __init__(self, name: str, height: int, age: int) -> None:
        """Initialize plant with name, height, and age."""
        self.name = name
        self.height = height
        self.initial_height = height
        self.age = age

    def update_height(self) -> None:
        """Increase plant height by 1cm."""
        self.height += 1

    def update_age(self) -> None:
        """Increase plant age by 1 day."""
        self.age += 1

    def get_info(self) -> str:
        """Return formatted plant information."""
        return f"{self.name}: {self.height}cm, {self.age} days old"


def ft_plant_growth() -> None:
    """Simulate a week of plant growth."""
    rose = Plant("Rose", 25, 30)
    print("=== Day 1 ===")
    print(rose.get_info())
    for _ in range(7):
        rose.update_height()
        rose.update_age()
    print("=== Day 7 ===")
    print(rose.get_info())
    growth = rose.height - rose.initial_height
    print(f"Growth this week: +{growth}cm")


if __name__ == "__main__":
    ft_plant_growth()
