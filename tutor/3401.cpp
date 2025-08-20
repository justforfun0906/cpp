#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

// 全域變數，用於儲存輸入的長度和最終的解
int n;
std::vector<std::string> solutions;

/**
 * @brief 使用遞迴回溯法生成有效的括號序列
 * * @param s 當前正在建立的字串
 * @param open_count 當前字串中左括號 '(' 的數量
 * @param close_count 當前字串中右括號 ')' 的數量
 */
void generate(std::string s, int open_count, int close_count) {
    // 基底情況 (Base Case): 如果當前字串的長度達到了 n，
    // 表示我們已經建立了一個完整的序列，將其加入解集合中。
    if (s.length() == n) {
        solutions.push_back(s);
        return;
    }

    // 每個有效序列需要 n/2 個左括號和 n/2 個右括號。
    int num_pairs = n / 2;

    // 遞迴步驟 (Recursive Step):

    // 選擇 1: 嘗試添加一個左括號 '('
    // 條件：只要已使用的左括號數量還沒有達到上限 (n/2)，我們就可以添加。
    if (open_count < num_pairs) {
        generate(s + '(', open_count + 1, close_count);
    }

    // 選擇 2: 嘗試添加一個右括號 ')'
    // 條件：只有當已使用的右括號數量嚴格小於左括號數量時，
    // 我們才能添加右括號，以確保序列始終有效（不會出現 '())' 這種情況）。
    if (close_count < open_count) {
        generate(s + ')', open_count, close_count + 1);
    }
}

int main() {
    // 為了提高執行效率，關閉 C++ stream 與 C stdio 的同步
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    std::cin >> n;

    // 一個有效的括號序列長度必須是偶數。
    // 如果 n 是奇數，不可能有任何解。
    if (n % 2 != 0) {
        std::cout << 0 << std::endl;
        return 0;
    }

    // 從一個空字串、0 個左括號、0 個右括號開始生成
    generate("", 0, 0);

    // 題目要求先輸出解的數量
    std::cout << solutions.size() << std::endl;

    // 接著按字典序輸出所有解。
    // 我們的遞迴生成方式自然地產生了按字典序排序的結果，所以不需要額外排序。
    for (const std::string& s : solutions) {
        std::cout << s << std::endl;
    }

    return 0;
}
