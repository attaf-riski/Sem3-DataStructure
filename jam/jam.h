#ifndef JAM_H
#define JAM_H

typedef struct {
    int HH;
    int Minute;
    int Second';
} JAM;

/// DEFINISI PRIMITIF
/// KELOMPOK VALIDASI TERHADAP TYPE

bool isJValid(int H, int M, int S);
/*
{ Mengirim true jika H,M,S dapat membentuk J yang valid }
{ dipakai untuk mentest SEBELUM membentuk sebuah Jam }
*/

/// KONSTRUKTOR
JAM makeJam(int HH, int MM, int SS);
/*
{ Membentuk sebuah JAM dari komponen-komponennya yang valid }
{ Prekondisi : HH, MM, SS valid untuk membentuk JAM }
*/

/// OPERATOR TERHADAP KOMPONEN : SELEKTOR GET DAN SET
/// SELEKTOR
int getHour(JAM J);
/*
{ Mengirimkan bagian jam (HH) dari JAM }
*/
int getMinute(JAM J);
/*
{ Mengirimkan bagian Menit (MM) dari JAM }
*/
int getSecond(JAM J);
/*
{ Mengirimkan bagian second (SS) dari JAM }
*/
/// PENGUBAH NILAI KOMPONEN
void setHH(JAM J, int newHH);
/*
{ Mengubah nilai komponen HH dari J }
*/
void setMM(JAM J, int newMM);
/*
{ Mengubah nilai komponen MM dari J }
*/
void setSS(JAM J, int newSS);
/*
{ Mengubah nilai komponen SS dari J }
*/

/// DESKTUKTOR
/// TIDAK PERLU, AKAN DIJELASKAN KEMUDIAN

/// KELOMPOK BACA/TULIS
void bacaJam(JAM J);
/*
{ I.S. : J tidak terdefinisi }
{ F.S. : J terdefinisi dan merupakan jam yang valid }
{ Proses : mengulangi membaca komponen H,M,S sehingga membentuk J }
{ yang valid. Tidak mungkin menghasilkan J yang tidak valid. }
*/

void bacaJam(JAM J);
/*
{ I.S. : J sembarang }
{ F.S. : Nilai J ditulis dg format HH:MM:SS }
{ Proses : menulis nilai setiap komponen J ke layar }
*/

/// KELOMPOK KONVERSI TERHADAP TYPE
int jamToDetik(JAM J);
/*
{ Diberikan sebuah JAM, mengkonversi menjadi Detik }
{ Rumus : detik = 3600*hour+menit*60 + detik }
{ nilai maksimum = 3600*23+59*60+59*60 }
{ hati-hati dengan representasi integer pada bahasa implementasi }
{ kebanyakan sistem mengimplementasi integer, }
{ bernilai maksimum kurang dari nilai maksimum hasil konversi }
*/

JAM detikToJam(int N);
/*
{ Mengirim konversi detik ke JAM }
{ pada beberapa bahasa, representasi integer tidak cukup untuk }
{ menampung N }
*/

/// KELOMPOK OPERASI TERHADAP TYPE
/// KELOMPOK OPERATOR RELATIONAL
bool JEQ(JAM J1, JAM J2);
/*
{ Mengirimkan true jika J1=J2, false jika tidak }
*/
bool JNEQ(JAM J1, JAM J2);
/*
{ Mengirimkan true jika J1=J2, false jika tidak }
*/
bool JLT(JAM J1, JAM J2);
/*
{ Mengirimkan true jika J1=J2, false jika tidak }
*/
bool JGT(JAM J1, JAM J2);
/*
{ Mengirimkan true jika J1=J2, false jika tidak }
*/

/// OPEATOR ARITMATIKA JAM
JAM JPlus(JAM J1,JAM J2);
/*
{ Menghasilkan J1+J2, dalam bentuk JAM }
*/
JAM JMinus(JAM J1,JAM J2);
/*
{ Menghasilkan J1+J2, dalam bentuk JAM }
{ Prekondisi : J1<=J2 }
*/
JAM nextDetik(JAM J);
/*
{ Mengirim 1 detik setelah J dalam bentuk JAM }
*/
JAM nextNDetik(JAM J);
/*
{ Mengirim N detik setelah J dalam bentuk JAM }
*/
JAM prevDetik(JAM J);
/*
{ Mengirim 1 detik sebelum J dalam bentuk JAM }
*/
JAM prevNDetik(JAM J);
/*
{ Mengirim N detik sebelum J dalam bentuk JAM }
*/
/// KELOMPOK OPERATOR ARITMETIKA
long int durasi(JAM jaw, JAM jakh);
/*
{ Mengirim JAkh -JAw dlm Detik, dengan kalkulasi }
{ Hasilnya negatif jika Jaw > JAkhir }
*/

/// DAPAT DITAMBAHKAN FUNGSI LAIN


#endif // JAM_H
