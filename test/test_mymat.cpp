//
// Created by Lee on 2022/9/2.
//
#include <gtest/gtest.h>
#include <chrono>

#include "MyMatrix.h"

using std::chrono::high_resolution_clock;
using std::chrono::microseconds;
using std::chrono::duration_cast;

TEST(MyMatrixTest, init) {
    MyMatrix<int> m(5, 5);
    m.randomFillMatrix(0,1);
    EXPECT_EQ(5, m.getCol());
    EXPECT_EQ(true, m.isSquare());

    MyMatrix<int> non_square{{1, 2}, {3, 4}, {5, 6}};
    EXPECT_EQ(3, non_square.getRow());
    EXPECT_EQ(2, non_square.getCol());
    EXPECT_EQ(false, non_square.isSquare());
}

TEST(MyMatrixTest, equal) {
    MyMatrix<int> m(8, 5);
    MyMatrix<int> n(5, 8);
    EXPECT_EQ(false, m == n);
    EXPECT_EQ(true, m != n);
}

TEST(MyMatrixTest, add) {
    MyMatrix<int> m(5, 5);
    MyMatrix<int> n(5, 5);
    MyMatrix<int> res(5,5);
    res.randomFillMatrix(1,1);
    m.randomFillMatrix(0,0);
    n.randomFillMatrix(1,1);
    EXPECT_EQ(res, m+n);
}

TEST(MyMatrixTest, multi) {
    MyMatrix<int> A{{1, 2,  -3},
                    {1, 3,  0},
                    {2, -1, 1}};
    MyMatrix<int> B{{2,  1,  0},
                    {-2, -1, 1},
                    {2,  1,  -3}};
    MyMatrix<int> C{{-8, -4, 11},
                    {-4, -2, 3},
                    {8,  4,  -4}};
    EXPECT_EQ(C, A * B);
}

TEST(MyMatrixTest, multi_8) {
    MyMatrix<int> E{{9,  3,  5,  7,  5,  7,  13, 18},
                    {1,  9,  0,  4,  17, 2,  5,  8},
                    {4,  8,  6,  7,  5,  12, 3,  2},
                    {11, 2,  4,  11, 19, 13, 3,  4},
                    {17, 17, 16, 1,  1,  6,  3,  1},
                    {15, 11, 5,  20, 17, 3,  7,  16},
                    {10, 7,  2,  6,  18, 15, 17, 15},
                    {17, 4,  16, 19, 2,  15, 11, 0}};
    MyMatrix<int> F{{3,  9,  0,  1,  11, 12, 19, 11},
                    {5,  10, 8,  14, 12, 10, 14, 12},
                    {13, 11, 12, 4,  4,  13, 5,  7},
                    {8,  0,  18, 8,  0,  2,  8,  16},
                    {6,  0,  7,  18, 2,  5,  20, 6},
                    {17, 17, 0,  17, 5,  4,  9,  1},
                    {12, 8,  3,  9,  10, 3,  6,  3},
                    {15, 3,  18, 12, 7,  14, 17, 16}};
    MyMatrix<int> G{{738, 443, 608, 669,  456, 561, 841,  646},
                    {396, 197, 422, 640,  269, 330, 701,  430},
                    {486, 416, 342, 541,  278, 330, 534,  377},
                    {614, 420, 476, 781,  322, 438, 928,  549},
                    {511, 628, 380, 486,  524, 636, 758,  556},
                    {802, 455, 936, 961,  548, 737, 1305, 1034},
                    {931, 618, 635, 1076, 588, 639, 1198, 718},
                    {830, 712, 613, 679,  488, 593, 852,  711}};

    EXPECT_EQ(G, E * F);
}

TEST(MyMatrixTest, multi_14) {
    MyMatrix<int> M{{-12, -2, -18, 12, 6, -13, -15, 12, -17, -18, 5, -19, -13, -7},
                    {14, -11, 20, 9, 2, -4, 11, -5, 12, 11, 1, 15, 0, 11},
                    {7, 18, 6, 12, 13, -14, 4, 9, 3, 13, -1, -12, 11, 18},
                    {17, -12, 19, 1, -16, 10, 20, -15, 1, 13, -15, -12, -13, -4},
                    {-4, -12, -9, 7, 14, 4, 6, 15, 4, 11, 19, -8, 11, -20},
                    {0, -3, 9, -4, 0, 19, -9, 15, 20, 0, -3, 8, -13, 17},
                    {2, 19, 15, -2, 16, -7, -11, 17, 8, -20, 17, -13, 9, 3},
                    {-15, 13, 10, 14, -1, 19, 19, -6, 1, -3, -6, -10, -19, 11},
                    {-13, -18, -12, -6, -5, -5, 14, -8, 5, 6, 10, 19, -15, 13},
                    {9, -18, 6, 10, 8, -3, -18, -5, 18, 17, 16, 6, -18, -12},
                    {-13, -15, -2, -13, 0, 20, -1, -16, 1, 3, 15, 13, 6, 10},
                    {4, -9, 5, 11, -17, -4, -1, 10, 17, 8, 17, 1, -7, 18},
                    {1, -18, 1, -2, 7, -7, -1, 2, -20, 7, 7, -13, -16, 9},
                    {10, -1, 16, -20, -4, -1, -17, -1, -15, 16, 1, 9, 16, 13}};
    MyMatrix<int> N{{-10, 6, 4, -16, 9, 12, 0, -2, 4, -15, 18, 10, -3, -6},
                    {12, 14, 0, -3, 2, -17, 8, -19, 20, -14, -20, -6, 7, 17},
                    {7, -15, -14, 13, -12, 18, 3, 6, -18, -12, -10, -6, 19, -13},
                    {7, 19, 12, 4, -1, 5, -16, 13, 4, 12, -18, -4, 16, 8},
                    {-18, 8, -15, -4, 7, 0, -3, 6, -14, -18, 8, 10, 14, 6},
                    {-11, 17, 4, -11, -5, -3, 6, -20, 4, 18, -5, -16, 2, 8},
                    {6, 6, -9, 18, -4, 5, -9, 18, -19, 4, -5, 15, 3, 16},
                    {-11, -7, -10, 1, 12, -9, -8, -1, -20, 6, 14, -13, -18, -15},
                    {-19, 8, -15, -8, -6, 13, -20, -17, 3, 11, -4, -15, 2, -7},
                    {-7, -9, -5, 2, -15, 17, -19, 5, -15, -5, 11, 17, 12, -15},
                    {16, 14, 12, -12, -13, 0, -16, -12, 20, -20, -8, 16, 16, 4},
                    {3, 7, 13, 11, 6, -1, -17, -10, -14, -5, -14, 15, 11, -12},
                    {4, 16, -2, -9, -6, 7, 6, 17, 13, -9, 10, -16, 0, -19},
                    {18, -17, -12, 2, 7, -15, 9, -7, 10, 17, 14, 10, 20, 3}};
    MyMatrix<int> O{{161, -75, 489, -193, 625, -1012, 465, 281, 539, 134, 12, -279, -850, 743},
                    {14, -221, -371, 435, -298, 1035, -882, 325, -850, -113, 30, 722, 1105, -620},
                    {285, -62, -805, -38, 56, 6, -120, 464, 119, -446, 439, 159, 789, -54},
                    {-221, -608, -278, 489, -550, 1175, 56, 555, -859, 510, 91, 253, 74, 101},
                    {-732, 846, 23, -431, -415, 536, -998, 536, -378, -436, 299, -36, -223, -310},
                    {-579, -412, -577, -131, 175, -138, -271, -1222, -402, 928, 142, -504, 247, -367},
                    {146, 323, -604, -596, 193, -431, 352, -458, 720, -973, -76, -787, 216, 15},
                    {461, 69, -348, 659, -245, -385, 192, -273, -144, 1045, -1049, -193, 719, 1361},
                    {359, -451, 189, 623, -120, -91, -831, -163, -482, 613, -111, 1260, 406, 165},
                    {-833, 15, 247, -398, -465, 1107, -1383, -416, -393, -414, -64, 578, 585, -630},
                    {238, 149, 256, -152, -532, 20, -73, -552, 305, 280, -72, 372, 634, -103},
                    {390, -357, -54, -38, -297, 300, -938, -422, 177, 599, 85, 229, 540, -450},
                    {192, -1007, -74, 185, 80, -51, 182, 568, -490, -76, 777, 943, 96, 149},
                    {366, -870, -119, -188, -165, 237, 567, -60, -6, -821, 888, 346, 393, -1238}};
    EXPECT_EQ(O, M * N);
}

TEST(MyMatrixTest, multi_strassen) {
    MyMatrix<int> n(120, 120);
    n.randomFillMatrix(-10, 10);
    MyMatrix<int> m(120, 120);
    m.randomFillMatrix(-10, 10);
    MyMatrix<int> c(120, 120);
    MyMatrix<int> d(120, 120);

    high_resolution_clock::time_point start1 = high_resolution_clock::now();
    d = m * n;
    high_resolution_clock::time_point end1 = high_resolution_clock::now();
    auto duration1 = duration_cast<microseconds>(end1 - start1).count();
    std::cout << "This took: "<< duration1 << " microseconds.\n";

    high_resolution_clock::time_point start2 = high_resolution_clock::now();
    strassen(m,n,c, 120);
    high_resolution_clock::time_point end2 = high_resolution_clock::now();
    auto duration2 = duration_cast<microseconds>(end2 - start2).count();
    std::cout<< "This took: " << duration2 << " microseconds.\n";
    EXPECT_EQ(c, d);
}

TEST(MyMatrixTest, multi_profile_naive) {
    MyMatrix<int> m(100, 100);
    m.randomFillMatrix(-10, 10);
    MyMatrix<int> n(100, 100);
    n.randomFillMatrix(1, 1);
    for (int i = 0; i < 30; ++i) {
        n = n * m;
    }
}

TEST(MyMatrixTest, multi_profile_strassen) {
    MyMatrix<int> m(100, 100);
    m.randomFillMatrix(-10, 10);
    MyMatrix<int> n(100, 100);
    n.randomFillMatrix(1, 1);
    for (int i = 0; i < 30; ++i) {
        strassen(n, m, n, 100);
    }
}