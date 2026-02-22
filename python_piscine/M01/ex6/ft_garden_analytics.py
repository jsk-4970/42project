#!/usr/bin/env python3
"""Garden Analytics Platform for managing garden data."""


class Plant:
    """Base class representing a garden plant."""

    def __init__(self, name: str, height: int) -> None:
        """Initialize a plant with name and height."""
        self.name = name
        self.height = height
        self.initial_height = height

    def update_height(self) -> None:
        """Increase plant height by 1cm."""
        self.height += 1

    def get_info(self) -> str:
        """Return plant information string."""
        return f"{self.name}: {self.height}cm"


class FloweringPlant(Plant):
    """A plant that produces flowers."""

    def __init__(
        self, name: str, height: int, flower_color: str
    ) -> None:
        """Initialize a flowering plant with color."""
        super().__init__(name, height)
        self.flower_color = flower_color

    def get_info(self) -> str:
        """Return flowering plant information."""
        return (
            f"{self.name}: {self.height}cm, "
            f"{self.flower_color} flowers (blooming)"
        )


class PrizeFlower(FloweringPlant):
    """A flowering plant that has won prizes."""

    def __init__(
        self, name: str, height: int,
        flower_color: str, prize: int
    ) -> None:
        """Initialize a prize-winning flower."""
        super().__init__(name, height, flower_color)
        self.prize = prize

    def get_info(self) -> str:
        """Return prize flower information."""
        return (
            f"{self.name}: {self.height}cm, "
            f"{self.flower_color} flowers (blooming), "
            f"Prize points: {self.prize}"
        )


class GardenManager:
    """Manages gardens and provides analytics."""

    total_gardens: int = 0
    _gardens: list = []

    class GardenStats:
        """Nested helper for garden statistics."""

        BLOOM_BONUS: int = 20

        @staticmethod
        def calculate_score(plants: list) -> int:
            """Calculate garden score with bloom bonus."""
            score: int = 0
            for plant in plants:
                score += plant.height
                if isinstance(plant, FloweringPlant):
                    bonus = GardenManager.GardenStats
                    score += bonus.BLOOM_BONUS
            return score

        @staticmethod
        def count_types(plants: list) -> tuple:
            """Count plants by type category."""
            regular: int = 0
            flowering: int = 0
            prize: int = 0
            for plant in plants:
                if isinstance(plant, PrizeFlower):
                    prize += 1
                elif isinstance(plant, FloweringPlant):
                    flowering += 1
                else:
                    regular += 1
            return regular, flowering, prize

        @staticmethod
        def total_growth(plants: list) -> int:
            """Calculate total growth from initial."""
            return sum(
                p.height - p.initial_height
                for p in plants
            )

    def __init__(self, owner: str) -> None:
        """Initialize a garden with an owner name."""
        self.owner = owner
        self.plants: list = []
        GardenManager.total_gardens += 1
        GardenManager._gardens.append(self)

    def add_plant(self, plant: Plant) -> None:
        """Add a plant to the garden."""
        self.plants.append(plant)
        print(
            f"Added {plant.name} to "
            f"{self.owner}'s garden"
        )

    def help_all_grow(self) -> None:
        """Help all plants grow by 1cm."""
        print(
            f"\n{self.owner} is helping "
            f"all plants grow..."
        )
        for plant in self.plants:
            plant.update_height()
            print(f"{plant.name} grew 1cm")

    def get_garden_scores(self) -> str:
        """Get formatted scores for all gardens."""
        scores: list = []
        for garden in GardenManager._gardens:
            score = self.GardenStats.calculate_score(
                garden.plants
            )
            scores.append(f"{garden.owner}: {score}")
        return ", ".join(scores)

    @staticmethod
    def height_validator(height: int) -> bool:
        """Validate that a plant height is positive."""
        return height > 0

    @classmethod
    def create_garden_network(cls) -> list:
        """Create a network of managed gardens."""
        alice = cls("Alice")
        bob = cls("Bob")
        bob.plants.extend([
            Plant("Maple", 40),
            FloweringPlant("Tulip", 32, "pink"),
        ])
        return [alice, bob]

    def get_garden_report(self) -> None:
        """Generate and display a garden report."""
        stats = self.GardenStats
        print(f"\n=== {self.owner}'s Garden Report ===")
        print("Plants in garden:")
        for plant in self.plants:
            print(f"- {plant.get_info()}")
        growth = stats.total_growth(self.plants)
        regular, flowering, prize = stats.count_types(
            self.plants
        )
        print(
            f"\nPlants added: {len(self.plants)}, "
            f"Total growth: {growth}cm"
        )
        print(
            f"Plant types: {regular} regular, "
            f"{flowering} flowering, "
            f"{prize} prize flowers"
        )
        if self.plants:
            last_h = self.plants[-1].height
            valid = self.height_validator(last_h)
        else:
            valid = False
        print(f"\nHeight validation test: {valid}")
        print(
            f"Garden scores - "
            f"{self.get_garden_scores()}"
        )
        print(
            f"Total gardens managed: "
            f"{GardenManager.total_gardens}"
        )


def ft_garden_analytics() -> None:
    """Run the garden analytics demonstration."""
    print("=== Garden Management System Demo ===\n")
    gardens = GardenManager.create_garden_network()
    alice = gardens[0]
    alice.add_plant(Plant("Oak Tree", 100))
    alice.add_plant(
        FloweringPlant("Rose", 25, "red")
    )
    alice.add_plant(
        PrizeFlower("Sunflower", 50, "yellow", 10)
    )
    alice.help_all_grow()
    alice.get_garden_report()


if __name__ == "__main__":
    ft_garden_analytics()
