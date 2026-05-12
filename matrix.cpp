#include <iostream>
#include <iomanip>
using namespace std;

// =============================================
//   VARIABEL GLOBAL
// =============================================
double matriks[10][10];
int baris = 0, kolom = 0;
bool sudahInput = false;

// =============================================
//   FUNGSI BANTU
// =============================================
void displayMenu() {
    cout << "\n=============================================\n";
    cout << "         PROGRAM OPERASI MATRIKS\n";
    cout << "=============================================\n";
    cout << "  1. Input Data Matriks\n";
    cout << "  2. Tampilkan Matriks\n";
    cout << "  3. Penjumlahan 2 Matriks\n";
    cout << "  4. Perkalian 2 Matriks\n";
    cout << "  5. Matriks Diagonal\n";
    cout << "  6. Matriks Segitiga Bawah\n";
    cout << "  7. Matriks Segitiga Atas\n";
    cout << "  8. Keluar dari Program\n";
    cout << "=============================================\n";
    cout << "  Pilih menu (1-8): ";
}

void cetakMatriks(double m[][10], int r, int c) {
    cout << "\n";
    for (int i = 0; i < r; i++) {
        cout << "  [ ";
        for (int j = 0; j < c; j++) {
            cout << setw(8) << fixed << setprecision(2) << m[i][j] << " ";
        }
        cout << "]\n";
    }
    cout << "\n";
}

// =============================================
//   CASE 1: Input Data Matriks → Membuat Matriks
// =============================================
void inputMatriks() {
    cout << "\n[Input Data Matriks]\n";
    cout << "Masukkan jumlah baris  : "; cin >> baris;
    cout << "Masukkan jumlah kolom  : "; cin >> kolom;
    cout << "Masukkan elemen matriks (" << baris << "x" << kolom << "):\n";
    for (int i = 0; i < baris; i++) {
        for (int j = 0; j < kolom; j++) {
            cout << "  Elemen [" << i+1 << "][" << j+1 << "]: ";
            cin >> matriks[i][j];
        }
    }
    sudahInput = true;
    cout << "Matriks berhasil dibuat!\n";
}

// =============================================
//   CASE 2: Display dataMatriks
// =============================================
void displayMatriks() {
    if (!sudahInput) {
        cout << "\nBelum ada matriks yang diinput!\n";
        return;
    }
    cout << "\n[Tampilan Matriks]\n";
    cetakMatriks(matriks, baris, kolom);
}

// =============================================
//   CASE 3: Menjumlahkan 2 Matriks → OUTPUT hasil
// =============================================
void jumlahkanMatriks() {
    if (!sudahInput) {
        cout << "\nBelum ada matriks yang diinput!\n";
        return;
    }
    cout << "\n[Penjumlahan 2 Matriks]\n";
    cout << "Matriks A:\n";
    cetakMatriks(matriks, baris, kolom);

    double b[10][10];
    cout << "Masukkan Matriks B (ukuran sama: " << baris << "x" << kolom << "):\n";
    for (int i = 0; i < baris; i++) {
        for (int j = 0; j < kolom; j++) {
            cout << "  Elemen B[" << i+1 << "][" << j+1 << "]: ";
            cin >> b[i][j];
        }
    }

    double hasil[10][10];
    for (int i = 0; i < baris; i++)
        for (int j = 0; j < kolom; j++)
            hasil[i][j] = matriks[i][j] + b[i][j];

    cout << "OUTPUT Hasil (A + B):\n";
    cetakMatriks(hasil, baris, kolom);
}

// =============================================
//   CASE 4: Mengalikan 2 Matriks → OUTPUT hasil
// =============================================
void kalikanMatriks() {
    if (!sudahInput) {
        cout << "\nBelum ada matriks yang diinput!\n";
        return;
    }
    cout << "\n[Perkalian 2 Matriks]\n";
    cout << "Matriks A (" << baris << "x" << kolom << "):\n";
    cetakMatriks(matriks, baris, kolom);

    int rb, cb;
    cout << "Masukkan jumlah baris Matriks B (harus " << kolom << "): "; cin >> rb;
    if (rb != kolom) {
        cout << "Error: Jumlah baris B harus sama dengan kolom A (" << kolom << ")!\n";
        return;
    }
    cout << "Masukkan jumlah kolom Matriks B: "; cin >> cb;

    double b[10][10];
    cout << "Masukkan elemen Matriks B:\n";
    for (int i = 0; i < rb; i++) {
        for (int j = 0; j < cb; j++) {
            cout << "  Elemen B[" << i+1 << "][" << j+1 << "]: ";
            cin >> b[i][j];
        }
    }

    double hasil[10][10] = {};
    for (int i = 0; i < baris; i++)
        for (int j = 0; j < cb; j++)
            for (int k = 0; k < kolom; k++)
                hasil[i][j] += matriks[i][k] * b[k][j];

    cout << "OUTPUT Hasil (A x B):\n";
    cetakMatriks(hasil, baris, cb);
}

// =============================================
//   CASE 5: Memproses Matriks Diagonal
// =============================================
void matriksDiagonal() {
    if (!sudahInput) {
        cout << "\nBelum ada matriks yang diinput!\n";
        return;
    }
    if (baris != kolom) {
        cout << "\nMatriks harus persegi (n x n) untuk diagonal!\n";
        return;
    }
    cout << "\n[DISPLAY Matriks Diagonal]\n";
    double hasil[10][10] = {};
    cout << "Elemen diagonal: [ ";
    for (int i = 0; i < baris; i++) {
        hasil[i][i] = matriks[i][i];
        cout << matriks[i][i] << " ";
    }
    cout << "]\n";
    cout << "\nMatriks Diagonal:\n";
    cetakMatriks(hasil, baris, kolom);
}

// =============================================
//   CASE 6: Memproses Matriks Segitiga Bawah
// =============================================
void matriks_segitigaBawah() {
    if (!sudahInput) {
        cout << "\nBelum ada matriks yang diinput!\n";
        return;
    }
    if (baris != kolom) {
        cout << "\nMatriks harus persegi (n x n)!\n";
        return;
    }
    cout << "\n[DISPLAY Matriks Segitiga Bawah]\n";
    double hasil[10][10] = {};
    for (int i = 0; i < baris; i++)
        for (int j = 0; j <= i; j++)
            hasil[i][j] = matriks[i][j];
    cetakMatriks(hasil, baris, kolom);
}

// =============================================
//   CASE 7: Memproses Matriks Segitiga Atas
// =============================================
void matriks_segitigaAtas() {
    if (!sudahInput) {
        cout << "\nBelum ada matriks yang diinput!\n";
        return;
    }
    if (baris != kolom) {
        cout << "\nMatriks harus persegi (n x n)!\n";
        return;
    }
    cout << "\n[DISPLAY Matriks Segitiga Atas]\n";
    double hasil[10][10] = {};
    for (int i = 0; i < baris; i++)
        for (int j = i; j < kolom; j++)
            hasil[i][j] = matriks[i][j];
    cetakMatriks(hasil, baris, kolom);
}

// =============================================
//   MAIN — mengikuti alur flowchart
// =============================================
int main() {
    // START
    int index;

    // DISPLAY Menu
    displayMenu();

    // INPUT indexMatriks
    cin >> index;

    // WHILE true
    while (true) {

        // Switch index
        switch (index) {
            case 1:   // INPUT dataMatriks → Membuat matriks → Break
                inputMatriks();
                break;

            case 2:   // DISPLAY dataMatriks → Break
                displayMatriks();
                break;

            case 3:   // Menjumlahkan 2 Matriks → OUTPUT hasil → Break
                jumlahkanMatriks();
                break;

            case 4:   // Mengalikan 2 Matriks → OUTPUT hasil → Break
                kalikanMatriks();
                break;

            case 5:   // Memproses Matriks Diagonal → DISPLAY → Break
                matriksDiagonal();
                break;

            case 6:   // Memproses Matriks Segitiga Bawah → DISPLAY → Break
                matriks_segitigaBawah();
                break;

            case 7:   // Memproses Matriks Segitiga Atas → DISPLAY → Break
                matriks_segitigaAtas();
                break;

            case 8:   // Keluar dari Program
                cout << "\nDISPLAY: Terima kasih telah menggunakan program ini!\n";
                cout << "Keluar dari Program...\n";
                return 0; // END

            default:  // Pilihan tidak valid
                cout << "\nDISPLAY: Pilihan tidak valid! Silakan pilih 1-8.\n";
                break;
        }

        // Kembali ke DISPLAY Menu & INPUT index
        displayMenu();
        cin >> index;
    }

    // END
    return 0;
}