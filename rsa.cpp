#include <iostream>
#include <string>
#include <cmath>
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

int modExp(int base, int exp, int mod) {
    int result = 1;
    base = base % mod;
    while (exp > 0) {
        if (exp % 2 == 1) {
            result = (result * base) % mod;
        }
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
        int Nn = (p - 1) * (q - 1);
        e = -1;
        for (int i = 2; i < 100; i++) {
            if (gcd(Nn, i) == 1) {
                e = i;
                break;
            }
        }
        if (e != -1) {

            d = modExp(e, -1, Nn);
        } else {
            cout << "Failed to find a suitable e." << endl;
            d = -1;
        }
    }
};

vector<int> convertMessageToArray(const string& message) {
    vector<int> result;
    for (char c : message) {
        result.push_back(static_cast<int>(c));
    }
    return result;
}

int main() {
    int p, q;
    string userInput;
    vector<int> CipherText;
    cout << "Enter two prime numbers to generate the keys: ";
    cin >> p >> q;
    cin.ignore();                                                       // Ignore the newline character left in the input buffer
    RSAKeys keys(p, q); 
    cout << "Your private key is: {" << keys.e << ", " << keys.n << "}" << endl;
    cout << "Your public key is: {" << keys.d << ", " << keys.n << "}" << endl;
    cout << "Enter the message you want to encrypt: ";
    getline(cin, userInput);
    vector<int> pu = convertMessageToArray(userInput);
     for(int i : pu){
        cout<<i<<" ";
    }
    for(int i : pu){
        CipherText.push_back(modExp(i, keys.e, keys.n));                // Append each ciphertext to CipherText vector
    } 
        cout<<endl;
        cout<<"your encrypted message is :";
    for(int i : CipherText){
        cout<<i<<" ";
    }
    return 0;
}


