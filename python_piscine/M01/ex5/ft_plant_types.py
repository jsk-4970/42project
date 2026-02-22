#!/usr/bin/env python3
"""Specialized plant types using inheritance."""


class Plant:
    """Base class for all plants."""

    def __init__(
        self, name: str, height: int, age: int
    ) -> None:
        """Initialize plant with name, height, and age."""
        self.name = name
        self.height = height
        self.age = age

    def get_info(self) -> str:
        """Return formatted plant information."""
        return (
            f"{self.name}: {self.height}cm, "
            f"{self.age} days old"
        )


class Flower(Plant):
    """A flowering plant with color."""

    def __init__(
        self, name: str, height: int,
        age: int, color: str
    ) -> None:
        """Initialize flower with color attribute."""
        super().__init__(name, height, age)
        self.color = color

    def bloom(self) -> str:
        """Return bloom message."""
        return f"{self.name} is blooming beautifully!"

    def get_info(self) -> str:
        """Return flower information."""
        return (
            f"{self.name} (Flower): {self.height}cm, "
            f"{self.age} days, {self.color} color"
        )


class Tree(Plant):
    """A tree with trunk diameter."""

    def __init__(
        self, name: str, height: int,
        age: int, trunk_diameter: int
    ) -> None:
        """Initialize tree with trunk diameter."""
        super().__init__(name, height, age)
        self.trunk_diameter = trunk_diameter

    def produce_shade(self) -> int:
        """Calculate shade area in square meters."""
        return self.trunk_diameter + 28

    def get_info(self) -> str:
        """Return tree information."""
        return (
            f"{self.name} (Tree): {self.height}cm, "
            f"{self.age} days, "
            f"{self.trunk_diameter}cm diameter"
        )


class Vegetable(Plant):
    """A vegetable with harvest season."""

    def __init__(
        self, name: str, height: int,
        age: int, harvest_season: str,
        nutritional_value: str = ""
    ) -> None:
        """Initialize vegetable with season and nutrition."""
        super().__init__(name, height, age)
        self.harvest_season = harvest_season
        self.nutritional_value = nutritional_value

    def get_info(self) -> str:
        """Return vegetable information."""
        return (
            f"{self.name} (Vegetable): {self.height}cm, "
            f"{self.age} days, "
            f"{self.harvest_season} harvest"
        )


def ft_plant_types() -> None:
    """Demonstrate specialized plant types."""
    print("=== Garden Plant Types ===\n")

    flowers = [
        Flower("Rose", 25, 30, "red"),
        Flower("Lily", 20, 15, "white"),
    ]
    print(flowers[0].get_info())
    print(flowers[0].bloom())

    print()
    trees = [
        Tree("Oak", 500, 1825, 50),
        Tree("Pine", 400, 1460, 35),
    ]
    shade = trees[0].produce_shade()
    print(trees[0].get_info())
    print(
        f"{trees[0].name} provides "
        f"{shade} square meters of shade"
    )

    print()
    vegs = [
        Vegetable("Tomato", 80, 90, "summer", "vitamin C"),
        Vegetable("Carrot", 30, 60, "autumn", "vitamin A"),
    ]
    print(vegs[0].get_info())
    print(
        f"{vegs[0].name} is rich in "
        f"{vegs[0].nutritional_value}"
    )


if __name__ == "__main__":
    ft_plant_types()
