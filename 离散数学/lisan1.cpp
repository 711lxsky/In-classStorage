#include <iostream>
#include <vector>

bool isEquivalenceRelation(const std::vector<std::vector<int>>& relationMatrix) {
    int n = relationMatrix.size();

    // 检查自反性：对于所有的 i，i 和 i 必须是等价的
    for (int i = 0; i < n; i++) {
        if (relationMatrix[i][i] != 1) {
            return false;
        }
    }

    // 检查对称性：如果 i 和 j 等价，则 j 和 i 也必须等价
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (relationMatrix[i][j] != relationMatrix[j][i]) {
                return false;
            }
        }
    }

    // 检查传递性：如果 i 和 j 等价，j 和 k 等价，则 i 和 k 也必须等价
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (relationMatrix[i][j] == 1) {
                for (int k = 0; k < n; k++) {
                    if (relationMatrix[j][k] == 1 && relationMatrix[i][k] != 1) {
                        return false;
                    }
                }
            }
        }
    }

    return true;
}

int main() {
    std::vector<std::vector<int>> relationMatrix = {
        {1, 0, 0},
        {0, 1, 0},
        {0, 0, 1}
    };

    if (isEquivalenceRelation(relationMatrix)) {
        std::cout << "The given relation is an equivalence relation." << std::endl;
    } else {
        std::cout << "The given relation is not an equivalence relation." << std::endl;
    }

    return 0;
}

/*上面的代码定义了一个 isEquivalenceRelation 函数，用于判断给定关系矩阵是否表示等价关系。
函数首先检查关系矩阵的自反性，然后检查关系矩阵的对称性和传递性。
在 main 函数中，我们定义了一个示例的关系矩阵，并调用 isEquivalenceRelation 函数来判断给定的关系矩阵是否是等价关系。
根据示例中的关系矩阵，输出相应的结果。*/
