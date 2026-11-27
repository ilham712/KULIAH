#include <iostream>
using namespace std;
int b = 1;
void UAS (int a, int *c);

int main () {
	int a, b;
	for (a = 1;a <= 3;a++) {
		for (b = a;b <= 3; b ++) {
			cout << b << " ";
		}
		cout << "\n\n";
	}
}


/*
int main() {
    int a,c;
    a = 3; b = 1; c = 2;
    cout << a << " " << b << " " << c << "\n";
    UAS(a, &c);
    cout << a << " " << b << " " << c << "\n";
    a = 2; b = 4; c = 3;
    cout << a << " " << b << " " << c << "\n";
    UAS(c, &a);
    cout << a << " " << b << " " << c << "\n";

    return 0;
}

void UAS (int a, int *c) {
	a = b+ *c; *c = 10 + b; b = 5 - *c;
}*/
