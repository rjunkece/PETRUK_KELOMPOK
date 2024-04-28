#include <iostream>
#include <vector>
#include <string>
#include <algorithm> 

using namespace std;
//Bagian Arjuna
string keHurufKecil(const string& str) {
    string hasil = str;
    transform(hasil.begin(), hasil.end(), hasil.begin(), ::tolower);
    return hasil;
}

bool cariHorizontal(const vector<string>& matriks, const string& kata) {
    for (const string& baris : matriks) {
        if (keHurufKecil(baris).find(kata) != string::npos) {
            return true;
        }
    }
    return false;
}

bool cariVertikal(const vector<string>& matriks, const string& kata) {
    int jumlahBaris = matriks.size();
    int jumlahKolom = matriks[0].size();
    for (int kolom = 0; kolom < jumlahKolom; ++kolom) {
        string kolomString = "";
        for (int baris = 0; baris < jumlahBaris; ++baris) {
            kolomString += matriks[baris][kolom];
        }
        if (keHurufKecil(kolomString).find(kata) != string::npos) {
            return true;
        }
    }
    return false;
}
