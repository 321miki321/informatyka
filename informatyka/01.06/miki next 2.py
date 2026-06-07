from abc import ABC, abstractmethod


class Shape(ABC):
    @abstractmethod
    def area(self):
        pass




class Circle(Shape):
    def __init__(self, radius):
        self.radius = radius

    def area(self):
        return 3.14159265359 * (self.radius ** 2)



class Rectangle(Shape):
    def __init__(self, width, height):
        self.width = width
        self.height = height


    def area(self):
        return self.width * self.height

class Triangle(Shape):
    def __init__(self, width, height):
        self.width = width
        self.height = height
    def area(self):
        return (self.width * self.height) / 2

class Square(Shape):
    def __init__(self, width, height):
        self.width = width
        self.height = height
    def area(self):
        return self.width * self.height

class Parallelogram(Shape):
    def __init__(self, width, height):
        self.width = width
        self.height = height
    def area(self):
        return self.width * self.height


if __name__ == '__main__':
    circle = Circle(5)
    rectangle = Rectangle(4, 6)
    triangle = Triangle(5, 6)
    square = Square(4, 8)
    parallelogram = Parallelogram(3, 3)

    print("Circle Area:", circle.area())
    print("Rectangle Area:", rectangle.area())
    print("Triangle Area:", triangle.area())
    print("Square Area:", triangle.area())
    print("Parallelogram Area:", triangle.area())