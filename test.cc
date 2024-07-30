#include <fstream>
#include <iostream>
#include <vector>

const int N = 4; // Number of Data
const int M = 4; // 状態の種類(one-hot-vectorに直したときのbit数)
const int L = 4; // マスの数

void save_data(const char *filename, std::vector<unsigned char> &data) {
  std::ofstream ofs(filename, std::ios::binary);
  ofs.write(reinterpret_cast<const char *>(data.data()), data.size());
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
  printf("Converted one-hot-vectors\n");
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
  printf("labels = ");
  for (const auto v : labels) {
    printf("%d ", v);
  }
  printf("\n");
  save_data("labels.dat", labels);
  auto v = make_one_hot_vector(data);
  save_data("data.dat", v);
}
