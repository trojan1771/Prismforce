#include <iostream>
#include <vector>
#include <algorithm>

bool canAbhimanyuCross(int p, std::vector<int>& enemies, int a, int b) {
    int n = enemies.size();
    std::vector<int> recharge_points(b, p); // Recharge points

    for (int i = 0; i < n; ++i) {
        if (i == 3 || i == 7) {
            // Enemies k3 and k7 regeneration check
            if (i > 0 && p <= enemies[i]) {
                int regeneratedPower = enemies[i] / 2;
                if (p <= regeneratedPower) return false;
                p -= regeneratedPower;
            }
        }
        if (p > enemies[i]) {
            // Fight if power is enough
            p -= enemies[i];
        } else if (a > 0) {
            // Skip if power is not enough and skips are available
            a--;
        } else if (b > 0) {
            // Recharge if skips are not available but recharges are
            p = recharge_points[--b];
            if (p <= enemies[i]) return false;
            p -= enemies[i];
        } else {
            // If no skips or recharges are available and power is not enough
            return false;
        }
    }
    return true;
}

int main() {
    // Test case 1
    int p1 = 15;
    std::vector<int> enemies1 = {1, 2, 5, 10, 4, 8, 6, 9, 3, 7, 5};
    int a1 = 1;
    int b1 = 2;
    if (canAbhimanyuCross(p1, enemies1, a1, b1)) {
        std::cout << "Abhimanyu can cross the Chakravyuha in Test Case 1.\n";
    } else {
        std::cout << "Abhimanyu cannot cross the Chakravyuha in Test Case 1.\n";
    }

    // Test case 2
    int p2 = 20;
    std::vector<int> enemies2 = {2, 4, 6, 8, 10, 12, 14, 16, 18, 20, 22};
    int a2 = 2;
    int b2 = 1;
    if (canAbhimanyuCross(p2, enemies2, a2, b2)) {
        std::cout << "Abhimanyu can cross the Chakravyuha in Test Case 2.\n";
    } else {
        std::cout << "Abhimanyu cannot cross the Chakravyuha in Test Case 2.\n";
    }

    return 0;
}
