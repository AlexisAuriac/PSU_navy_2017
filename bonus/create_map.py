#!/usr/bin/python3

import sys
from random import *

if len(sys.argv) is not 2:
    print("Error")
    exit(84)


class Boat:
    """Boat class composed of size, orientation, first column and first line"""

    def __init__(self, size):
        """Initializes the attributes to random values"""
        self.size = size
        self.orient = choice(["hor", "ver"])
        if self.orient == "hor":
            self.col = randrange(1, 9 - size)
            self.line = randrange(1, 8)
        else:
            self.line = randrange(1, 9 - size)
            self.col = randrange(1, 8)

    def __str__(self):
        """Returns the str form of boat with this form: 'size:P1:P2'"""
        rtrn = "%d:" % self.size
        rtrn += "%c%d:" % (self.col + 65, self.line)
        if self.orient == "hor":
            rtrn += "%c%d" % (self.col + 65 + self.size - 1, self.line)
        else:
            rtrn += "%c%d" % (self.col + 65, self.line + self.size - 1)
        return rtrn

    def collide(self, boat):
        """Tests if the boat collides with another boat"""
        if self.orient == boat.orient:
            if self.orient == "hor" and self.line == boat.line:
                if self.col + self.size > boat.col:
                    return True
            elif self.col == boat.col and self.line + self.size > boat.line:
                return True
        else:
            if self.orient == "hor":
                if self.line >= boat.line and self.line < boat.line + boat.size:
                    if self.col <= boat.col and self.col + self.size > boat.col:
                        return True
            else:
                if self.col >= boat.col and self.col < boat.col + boat.size:
                    if self.line <= boat.line and self.line + self.size > boat.line:
                        return True
        return False


def boat_collision(pos):
    for i, boat in enumerate(pos):
        for boat2 in pos[i + 1:]:
            if boat.collide(boat2):
                return True
    return False


def place_boats():
    while True:
        pos = []
        for i in range(2, 6):
            pos.append(Boat(i))
        if boat_collision(pos) is False:
            break
    return (pos)


pos = place_boats()
file = open(sys.argv[1], "w")
for i in pos:
    file.write(str(i) + "\n")
