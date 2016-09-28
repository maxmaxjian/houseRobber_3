#include <memory>
// #include <functional>
// #include <unordered_set>
// #include <vector>
// #include <queue>
#include <iostream>

class TreeNode {
  public:
    int val;
    std::shared_ptr<TreeNode> left, right;
    
  public:
    TreeNode(int xval) : val(xval), left(nullptr), right(nullptr) {}

    size_t hash() const {
        int result = std::hash<int>()(val);
        if (left != nullptr)
            result ^= left->hash();
        if (right != nullptr)
            result ^= right->hash();
        return result;
    }
};

using pNode = std::shared_ptr<TreeNode>;

// class TreeNodeHasher {
//   public:
//     size_t operator()(const pNode & node) {
//         return node->hash();
//     }
// };

// const pNode & getParent(const pNode & root, const pNode & curr) {
//     std::queue<pNode> qu;
//     qu.push(root);
//     while (!qu.empty()) {
//         auto & node = qu.front();
//         qu.pop();
//         if (node == curr)
//             return nullptr;
//         if (node->left == curr || node->right == curr)
//             return node;
//         if (node->left != nullptr)
//             qu.push(node->left);
//         if (node->right != nullptr)
//             qu.push(node->right);
//     }
// }
//
// class solution {
//   public:
//     int rob(const pNode & root) {
//         std::unordered_set<pNode> visited;
//         std::vector<std::unordered_set<pNode>> paths = robFrom(root, root, visited);
//         std::vector<int> cands;
//         for (auto & path : paths) {
//             int sum = 0;
//             for (auto it = path.begin(); it != path.end(); ++it)
//                 sum += (*it)->val;
//             cands.push_back(sum);
//         }

//         return *std::max_element(cands.begin(), cands.end());
//     }

//   private:
//     std::vector<std::unordered_set<pNode>> robFrom(const pNode & root, const pNode & curr, const std::unordered_set<pNode> & visited) {
//         std::vector<std::unordered_set<pNode>> result;
//         if (curr == nullptr) {
//             result.push_back(visited);
//         }
//         else {
//             pNode parent = getParent(root, curr);
//             if (parent == nullptr) {
//                 std::unordered_set<pNode> tmp1;
//                 tmp1.insert(curr);
//                 auto left = 
                
//                 std::unordered_set<pNode> tmp2;
//                 result.push_back(tmp1);
//                 result.push_back(tmp2);
//             }
//             else {
//                 if (visited.find(parent) != visited.end()) {
                    
//                 }
//             }
//         }
        
//     }
// };

class solution {
  public:
    int rob(const pNode & root) {
        int res1 = robFrom(root, true), res2 = robFrom(root, false);
        return std::max(res1, res2);
    }

  private:
    int robFrom(const pNode & root, bool canRobRoot) {
        if (root == nullptr)
            return 0;
        else {
            if (canRobRoot) {
                return root->val + robFrom(root->left, false) + robFrom(root->right, false);
            }
            else {
                return robFrom(root->left, true)+robFrom(root->right, true);
            }
        }
    }
};

int main() {
    // pNode root = std::make_shared<TreeNode>(3);
    // root->left = std::make_shared<TreeNode>(2);
    // root->right = std::make_shared<TreeNode>(3);
    // root->left->right = std::make_shared<TreeNode>(3);
    // root->right->right = std::make_shared<TreeNode>(1);

    pNode root = std::make_shared<TreeNode>(3);
    root->left = std::make_shared<TreeNode>(4);
    root->right = std::make_shared<TreeNode>(5);
    root->left->left = std::make_shared<TreeNode>(1);
    root->left->right = std::make_shared<TreeNode>(3);
    root->right->right = std::make_shared<TreeNode>(1);

    solution soln;
    int result = soln.rob(root);

    std::cout << "The maximum amount of money can be robbed is:\n";
    std::cout << result << std::endl;
}






