#include <iostream>

int main() {
    const int n = 7;
//    const int n = 4;

    const int N = n + 1;
    const int w[] = {20, 5, 17, 10, 20, 3, 25};
//    const int w[] = {4, 2, 6, 3};

    int* W = new int[N*N];
    // W[i,j] = W[i*N + j];

    for (int j = 0; j <= n; j++) {
        for (int i = 0; i <= j; i++) {
            W[i*N + j] = 0;
            for (int k = i + 1; k <= j; k++) {
                W[i*N + j] += w[k - 1];
            }
//            std::cout << "(i, j): " << "(" << i << "," << j << "): " << W[i*N + j] << std::endl;
        }
    }

    int* c = new int[N*N];
    // c[i,j] = c[i*N + j]

    for (int i = 0; i <= n; i++) {
        c[i*N + i] = 0; // c[i,i] = 0
    }

//    for (int j = 1; j <= n; j++) {
//        for (int i = 0; i < j; i++) {
    for (int s = 1; s <= n; s++) {
        for (int i = 0; i <= n - s; i++) {
            int j = i + s;
            int min = INT_MAX;
//            std::cout << "(" << i << "," << j << ")" << std::endl;

            for (int r = i + 1; r <= j; r++) {
//                std::cout << r << std::endl;
//                std::cout << c[i*N + r - 1] << " " << std::endl;
//                std::cout << c[r*N + j] << " " << std::endl;
//                std::cout << W[i*N + j] << " " << std::endl << std::endl;

                min = std::min(min, c[i*N + r - 1] + c[r*N + j] + W[i*N + j]);
            }
            c[i*N + j] = min;

//            for (int q = 0; q <= n; q++) {
//                for (int t = 0; t <= n; t++) {
//                    std::cout << c[q*N + t] << " ";
//                }
//                std::cout << std::endl;
//            }
        }
    }


    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= n; j++) {
            std::cout << c[i*N + j] << " ";
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;

    std::cout << c[N-1] << std::endl;
    return 0;
}
