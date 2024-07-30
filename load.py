import numpy as np


def read_from_file(filename):
    with open(filename, "rb") as f:
        return np.array(list(f.read()), dtype=np.uint8)


def main():
    labels = read_from_file("labels.dat")
    print("labels=", labels)
    data = read_from_file("data.dat")
    data = data.reshape(4, 16)
    print("Data =")
    for d in data:
        print("".join(map(str, d)))


if __name__ == "__main__":
    main()
