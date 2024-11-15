#include <iostream>
#include <string>
#include <vector>
using namespace std;

int gcd(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

int modInverse(int a, int mod) {
    int m0 = mod, y = 0, x = 1;
    while (a > 1) {
        int q = a / mod;
        int t = mod;
        mod = a % mod, a = t;
        t = y;
        y = x - q * y;
        x = t;
    }
    if (x < 0)
        x += m0;
    return x;
}

int modExp(int base, int exp, int mod) {
    int result = 1;
    base = base % mod;
    while (exp > 0) {
        if (exp % 2 == 1)
            result = (result * base) % mod;
        exp = exp >> 1;
        base = (base * base) % mod;
    }
    return result;
}

class RSAKeys {
public:
    int e, d, n;
    RSAKeys(int p, int q) {
        n = p * q;
        int phi_n = (p - 1) * (q - 1);
        e = -1;
        for (int i = 2; i < phi_n; i++) {
            if (gcd(phi_n, i) == 1) {
                e = i;
                break;
            }
        }
        if (e != -1) {
            d = modInverse(e, phi_n);
        } else {
            cout << "Failed to find a suitable 'e'. Exiting..." << endl;
            exit(1);
        }
    }
};

vector<int> convertMessageToArray(const string &message) {
    vector<int> result;
    for (char c : message) {
        result.push_back(static_cast<int>(c));
    }
    return result;
}

string convertArrayToMessage(const vector<int> &array) {
    string result;
    for (int i : array) {
        result += static_cast<char>(i);
    }
    return result;
}

int main() {
    int p, q;
    string userInput;
    vector<int> cipherText;

    cout << "Enter two prime numbers to generate the keys: ";
    cin >> p >> q;
    cin.ignore();

    RSAKeys keys(p, q);
    cout << "Your public key is: {" << keys.e << ", " << keys.n << "}" << endl;
    cout << "Your private key is: {" << keys.d << ", " << keys.n << "}" << endl;

    cout << "Enter the message you want to encrypt: ";
    getline(cin, userInput);

    vector<int> plainText = convertMessageToArray(userInput);

    for (int i : plainText) {
        cipherText.push_back(modExp(i, keys.e, keys.n));
    }

    cout << "Your encrypted message is: ";
    for (int i : cipherText) {
        cout << i << " ";
    }
    cout << endl;

    vector<int> decryptedText;
    for (int i : cipherText) {
        decryptedText.push_back(modExp(i, keys.d, keys.n));
    }

    cout << "Your decrypted message is: " << convertArrayToMessage(decryptedText) << endl;

    return 0;
}
