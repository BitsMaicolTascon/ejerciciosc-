#include <iostream>

using namespace std;

// Función lógica A1'A0'B0' + A0(A1'(B1 ^ B0) + A1(B1 ^ B0)) + A1B0'(A0 ^ B1) + A1A0B1B0
bool canDonateBlood(int A1, int A0, int B1, int B0) {
    return (!A1 && !A0 && !B0) || (A0 && (!A1 && (B1 ^ B0) || (A1 && (B1 ^ B0))) || (A1 && !B0 && (A0 ^ B1)) || (A1 && A0 && B1 && B0));
}

int main() {
    cout << "A1| A0| B1| B0| T" << endl;
    
    for (int A1 = 0; A1 <= 1; A1++) {
        for (int A0 = 0; A0 <= 1; A0++) {
            for (int B1 = 0; B1 <= 1; B1++) {
                for (int B0 = 0; B0 <= 1; B0++) {
                    bool result = canDonateBlood(A1, A0, B1, B0);
                    cout << A1 << " | " << A0 << " | " << B1 << " | " << B0 << " | " << result << endl;
                }
            }
        }
    }
    
    return 0;
}
