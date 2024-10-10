#include <iostream>
using namespace std;


void TOH(int n, char from_twr, char to_twr, char aux_twr) {
    if (n == 1) {
        cout << "Move disk 1 from " << from_twr << " to " << to_twr << endl;
        return;
    }
    TOH(n - 1, from_twr, aux_twr, to_twr);
    cout << "Move disk " << n << " from " << from_twr << " to " << to_twr << endl;
    TOH(n - 1, aux_twr, to_twr, from_twr);
}


int main() {
    int N;
    cout << "Enter the number of discs : ";
    cin >> N;

    cout << "===========================\n";

    cout << "Sequence of moves:" << endl;
    TOH(N, 'A', 'C', 'B');

    cout << "Total moves: " << (1 << N) - 1 << endl;

    return 0;
}
