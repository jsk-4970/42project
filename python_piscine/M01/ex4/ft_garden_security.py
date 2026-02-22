#!/usr/bin/env python3
"""Garden security system with data validation."""


class SecurePlant:
    """A plant with protected data and validation."""

    def __init__(self, name: str) -> None:
        """Initialize a secure plant with a name."""
        self._name = name
        self._height: int = 0
        self._age: int = 0
        print(f"Plant created: {self._name}")

    def get_height(self) -> int:
        """Return the plant height."""
        return self._height

    def get_age(self) -> int:
        """Return the plant age."""
        return self._age

    def set_height(self, new_height: int) -> None:
        """Set plant height with validation."""
        if new_height < 0:
            print(
                f"\nInvalid operation attempted: "
                f"height {new_height}cm [REJECTED]"
            )
            print("Security: Negative height rejected")
        else:
            self._height = new_height
            print(f"Height updated: {new_height}cm [OK]")

    def set_age(self, new_age: int) -> None:
        """Set plant age with validation."""
        if new_age < 0:
            print(
                f"\nInvalid operation attempted: "
                f"age {new_age} days [REJECTED]"
            )
            print("Security: Negative age rejected")
        else:
            self._age = new_age
            print(f"Age updated: {new_age} days [OK]")

    def get_info(self) -> str:
        """Return current plant information."""
        return (
            f"Current plant: {self._name} "
            f"({self._height}cm, {self._age} days)"
        )


def ft_garden_security() -> None:
    """Demonstrate garden security system."""
    print("=== Garden Security System ===")
    rose = SecurePlant("Rose")
    rose.set_height(25)
    rose.set_age(30)
    rose.set_height(-5)
    print(f"\n{rose.get_info()}")


if __name__ == "__main__":
    ft_garden_security()
