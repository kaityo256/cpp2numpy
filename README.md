# C++からNumPy用のデータを保存してPythonから読み込むサンプル

## 使い方

```sh
$ make test
g++ -std=c++11 test.cc
./a.out
labels = 0 3 2 1 
Saved as labels.dat
Converted one-hot-vectors
1000001001000001
0100010000101000
1000100001001000
0010001001001000
Saved as data.dat
python3 load.py
labels= [0 3 2 1]
Data =
1000001001000001
0100010000101000
1000100001001000
0010001001001000

```

## 解説

C++側から、学習用の正解ラベルと、学習用のone-hot-vectorを、それぞれ`labels.dat`と`data.dat`に保存する。ラベルはそのまま、データは一度one-hot-vectorに保存してから、一次元配列として保存する。

Python側からは、一度`f.read()`で読み込み、`list`でリスト化し`numpy.array`で配列として読み込む。必要ならあとでreshapeする。

## ライセンス

MIT
