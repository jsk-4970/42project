#!/usr/bin/env python3


class SecurePlant:
    def __init__(self, name: str, height: int, age: int):
        self._name = name
        self._height = height
        self._initial_height = height
        self._age = age

    def get_height(self):
        return self._height

    def set_height(self, new_height: int):
        if new_height < 0:
            print("Invalid operation attempted: height [REJECTED]")
            print("Security: Negative height rejected")
        else:
            self._height = new_height
            print(f"Height updated: {new_height}cm [OK]")

    def get_info(self):
        return f"Plant created: {self._name}\nHeight updated: {self._height}cm [OK]\nAge updeted: {self._age} days [OK]"


def ft_garden_security():
    print("=== Garden Security System ===")
    rose = SecurePlant("Rose", 25, 30)
    print(rose.get_info())
    rose.set_height(rose.get_height() - 30)


if __name__ == "__main__":
    ft_garden_security()
