#!/usr/bin/python3
""" Determines if a data set represents a valide utf_8"""


def validUTF8(data):
    bytes_number = 0

    byte_map = {
        0b0: 0,
        0b110: 1,
        0b1110: 2,
        0b11110: 3
    }

    for num in data:
        byte = num & 0xFF

        if bytes_number == 0:
            for key, value in byte_map.items():
                if (byte >> (8 - len(bin(key)) + 2)) == key:
                    bytes_number = value
                    break
            else:
                return False
        else:
            if (byte >> 6) != 0b10:
                return False
            bytes_number -= 1

    return bytes_number == 0
