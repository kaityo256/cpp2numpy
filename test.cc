#include <fstream>
#include <iostream>
#include <vector>

void save_data(const char *filename, const char *data, size_t N) {
  std::ofstream ofs(filename, std::ios::binary);
  ofs.write(data, N);
  std::cout << "Saved as " << filename << std::endl;
}

int main() {
  const size_t N = 4;
  unsigned char labels[N] = {0, 3, 2, 1};
  unsigned char data[N][4] = {{0, 2, 1, 3}, {1, 1, 2, 0}, {0, 0, 1, 0}, {2, 2, 1, 0}};
  save_data("labels.dat", reinterpret_cast<const char *>(labels), N);
}
