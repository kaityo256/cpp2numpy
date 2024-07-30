import numpy as np

def read_from_file(filename):
    with open(filename, "rb") as f:
        return np.array(list(f.read()),dtype=np.uint8)

def main():
    data = read_from_file("labels.dat")
    print(data)


if __name__ == "__main__":
    main()
