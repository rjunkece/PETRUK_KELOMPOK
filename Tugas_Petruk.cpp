//Kelompok 7
//Arjuna Gunatama Sihombing (2317051085)
//Muhammad Zidane Dako (2357051005)
//Indah Febriana Della (2317051066)

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
//Bagian Indah Febriana Della
bool cariDiagonal(const vector<string>& matriks, const string& kata) {
    int jumlahBaris = matriks.size();
    int jumlahKolom = matriks[0].size();
    for (int startBaris = 0; startBaris < jumlahBaris; ++startBaris) {
        for (int startKolom = 0; startKolom < jumlahKolom; ++startKolom) {
            string diagonal = "";
            int baris = startBaris;
            int kolom = startKolom;
            while (baris < jumlahBaris && kolom < jumlahKolom) {
                diagonal += matriks[baris][kolom];
                ++baris;
                ++kolom;
            }
            if (keHurufKecil(diagonal).find(kata) != string::npos) {
                return true;
            }
        }
    }
    return false;
}

bool cariDiagonalTerbalik(const vector<string>& matriks, const string& kata) {
    int jumlahBaris = matriks.size();
    int jumlahKolom = matriks[0].size();
    for (int startBaris = jumlahBaris - 1; startBaris >= 0; --startBaris) {
        for (int startKolom = 0; startKolom < jumlahKolom; ++startKolom) {
            string diagonal = "";
            int baris = startBaris;
            int kolom = startKolom;
            while (baris >= 0 && kolom < jumlahKolom) {
                diagonal += matriks[baris][kolom];
                --baris;
                ++kolom;
            }
            if (keHurufKecil(diagonal).find(kata) != string::npos) {
                return true;
            }
        }
    }
    return false;
}

int main() {
    int N;
    cin >> N;

    vector<string> matrix = {
        "AAFLKHPFSSUFICICLESGNNΗ",
        "SFVREOMRWLRTTSXOQQNAOAO",
        "QEIAIFXAEIRFVFYSXIMINJI",
        "WSTRLGOCAPBIAFIWIWTUACM",
        "FEYAEAISTPCRLUJKOAKCERS",
        "RVDAKPNDEEHDEMSNCKKFOAH",
        "MRNEDSLCRRIWNRSAAFITMMI",
        "YAAECIEAHYMOTAVHRSSTISB",
        "RJSEWELCCENNIETOHWSGLSE",
        "ΑΤΑΝΥΥΜΟIEESNESIOIRELTR",
        "UTENEWEBHMYBETNNRAIEBEN",
        "RCLKUTEAEQJLSGSHTGDSKOA",
        "BHOICATNRRSDDECEHOOLGIT",
        "ENSLUARIRSETALOCOHCTOHE",
        "FZFUDQJYMADOYIWYGLOVESU",
        "TEKALFWONSNAEBMIEJTZNTG",
        "ESWPOSJXEUTUYOZUWAKΕΖΗΜ",
        "KZUHΒΡΕΖEERFLMSNOWBALLH",
        "NSNOWBOARDYTVWYCLEVOHSA",
        "ACOCRQLGZIYCHODRAZZILBI",
        "LBVKKWANZAAQINWOLPWONSL",
        "BFREEZINGRAINSLILGTMELT",
        "HQPYLWHFMNFFUFPSWXNUMMV"
    };

   
    for (int i = 0; i < N; ++i) {
        string word;
        cin >> word;
        bool found = searchHorizontal(matrix, toLowerCase(word)) || 
                     searchVertical(matrix, toLowerCase(word)) || 
                     searchDiagonal(matrix, toLowerCase(word)) ||
                     searchReverseDiagonal(matrix, toLowerCase(word));
        if (found) {
            cout << "Ada" << endl;
        } else {
            cout << "Tidak Ada" << endl;
        }
    }

    return 0;
}
