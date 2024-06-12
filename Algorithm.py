def can_abhimanyu_cross(p, enemies, a, b):
    recharge_points = [p] * b  # Recharge points

    for i in range(len(enemies)):
        if i == 2 or i == 6:  # 0-based index, 2 and 6 correspond to k3 and k7
            if i > 0 and p <= enemies[i]:
                regenerated_power = enemies[i] // 2
                if p <= regenerated_power:
                    return False
                p -= regenerated_power
        
        if p > enemies[i]:
            p -= enemies[i]  # Fight
        elif a > 0:
            a -= 1  # Skip
        elif b > 0:
            p = recharge_points[--b]  # Recharge
            if p <= enemies[i]:
                return False
            p -= enemies[i]
        else:
            return False  # Cannot fight, skip, or recharge

    return True

# Test case 1
p1 = 15
enemies1 = [1, 2, 5, 10, 4, 8, 6, 9, 3, 7, 5]
a1 = 1
b1 = 2
print("Abhimanyu can cross the Chakravyuha in Test Case 1." if can_abhimanyu_cross(p1, enemies1, a1, b1) else "Abhimanyu cannot cross the Chakravyuha in Test Case 1.")

# Test case 2
p2 = 20
enemies2 = [2, 4, 6, 8, 10, 12, 14, 16, 18, 20, 22]
a2 = 2
b2 = 1
print("Abhimanyu can cross the Chakravyuha in Test Case 2." if can_abhimanyu_cross(p2, enemies2, a2, b2) else "Abhimanyu cannot cross the Chakravyuha in Test Case 2.")
