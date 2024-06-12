public class AbhimanyuChakravyuha {

    public static boolean canAbhimanyuCross(int p, int[] enemies, int a, int b) {
        int[] rechargePoints = new int[b];
        for (int i = 0; i < b; i++) {
            rechargePoints[i] = p;
        }

        for (int i = 0; i < enemies.length; i++) {
            if (i == 2 || i == 6) {
                if (i > 0 && p <= enemies[i]) {
                    int regeneratedPower = enemies[i] / 2;
                    if (p <= regeneratedPower) return false;
                    p -= regeneratedPower;
                }
            }
            if (p > enemies[i]) {
                p -= enemies[i];  // Fight
            } else if (a > 0) {
                a--;  // Skip
            } else if (b > 0) {
                p = rechargePoints[--b];  // Recharge
                if (p <= enemies[i]) return false;
                p -= enemies[i];
            } else {
                return false;  // Cannot fight, skip, or recharge
            }
        }
        return true;
    }

    public static void main(String[] args) {
        // Test case 1
        int p1 = 15;
        int[] enemies1 = {1, 2, 5, 10, 4, 8, 6, 9, 3, 7, 5};
        int a1 = 1;
        int b1 = 2;
        System.out.println("Abhimanyu can cross the Chakravyuha in Test Case 1: " + canAbhimanyuCross(p1, enemies1, a1, b1));

        // Test case 2
        int p2 = 20;
        int[] enemies2 = {2, 4, 6, 8, 10, 12, 14, 16, 18, 20, 22};
        int a2 = 2;
        int b2 = 1;
        System.out.println("Abhimanyu can cross the Chakravyuha in Test Case 2: " + canAbhimanyuCross(p2, enemies2, a2, b2));
    }
}
