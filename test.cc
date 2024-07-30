#include <fstream>
#include <iostream>
#include <vector>

const int N = 4; // Number of Data
const int M = 4; // 状態の種類(one-hot-vectorに直したときのbit数)
const int L = 4; // マスの数

void save_data(const char *filename, const char *data, size_t N) {
  std::ofstream ofs(filename, std::ios::binary);
  ofs.write(data, N);
  std::cout << "Saved as " << filename << std::endl;
}

std::vector<unsigned char> make_one_hot_vector(std::vector<std::vector<unsigned char>> &data) {
  unsigned char results[N][M * L] = {};
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < L; j++) {
      results[i][j * 4 + data[i][j]] = 1;
    }
  }
  std::vector<unsigned char> v;
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M * L; j++) {
      printf("%d", results[i][j]);
      v.push_back(results[i][j]);
    }
    printf("\n");
  }
  return v;
}

int main() {
  const size_t N = 4;
  std::vector<unsigned char> labels = {0, 3, 2, 1};
  std::vector<std::vector<unsigned char>> data = {{0, 2, 1, 3}, {1, 1, 2, 0}, {0, 0, 1, 0}, {2, 2, 1, 0}};
  save_data("labels.dat", reinterpret_cast<const char *>(labels.data()), N);
  auto v = make_one_hot_vector(data);
}
