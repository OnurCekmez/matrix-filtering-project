#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define maxSize 100 // Maksimum matris boyutu

// Matris dışına taşmayı kontrol eden yardımcı fonksiyon
int getValue(int x, int y, int M, int N, int f[maxSize][maxSize]) { //x değeri (i + k) değerini taşıyor , y değeri (j + l) değerini taşıyor. Değerler applyFilter içindeki getValue'den geliyor
    if (x < 0 || y < 0 || x >= M || y >= N) { 
        return 0; // Matris dışına çıkarsa 0 döner
    }
    return f[x][y]; // Matris içindeyse gerçek değeri döndürür
}

// Filtreleme işlemini yapan fonksiyon
void applyFilter(int M, int N, int f[maxSize][maxSize], int g[maxSize][maxSize], int v[3][3]) {
    for (int i = 0; i < M; i++) { // Tüm satırlar (0'dan M'e kadar)
        for (int j = 0; j < N; j++) { // Tüm sütunlar (0'dan N'e kadar)
            int sum = 0; // Toplam değeri hesaplamak için
            for (int k = -1; k <= 1; k++) { // 3x3 filtre için
                for (int l = -1; l <= 1; l++) {
                    sum += getValue(i + k, j + l, M, N, f) * v[k + 1][l + 1]; // (i + k) değeri ya da (j + l) değeri -1 dönerse mesela f[-1][0] böyle bir eleman olmadığından işleme katıldığında yanlış sonuç vermemek için 0 olarak kabul edilicek
                }
            }
            g[i][j] = sum; // Sonuç matrise yazılır
        }
    }
}


int main() {
    int M, N;
    int f[maxSize][maxSize], g[maxSize][maxSize] = {0};
    int v[3][3];

    // Kullanıcıdan matris boyutlarını al
    printf("Matrixin satır sayısını giriniz (max deger 100): ");
    scanf("%d", &M);

    printf("Matrixin sütun sayısını giriniz (max deger 100): ");
    scanf("%d", &N);

    if (M > maxSize || N > maxSize || M <= 0 || N <= 0) {
        printf("Hatalı boyut! Matris en fazla %d x %d olabilir.\n", maxSize, maxSize);
        return 1;
    }

    srand(time(NULL)); // Rastgele sayı üretimi için seed

    // Orijinal matrisi (f) rastgele değerlerle doldur
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            f[i][j] = rand() % 256; // 0-255 arasında rastgele değer
        }
    }

    // Filtre matrisini (v) kullanıcıdan al
    printf("3x3 Filtre Matrisi Değerlerini Giriniz:\n");
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf("%d. satır ve %d. sütunun değerini giriniz: ", i + 1, j + 1);
            scanf("%d", &v[i][j]);
        }
    }

    // Filtreleme işlemini uygula
    applyFilter(M, N, f, g, v);

    // Orijinal matrisi ekrana yazdır
    printf("\n   Orijinal Matris (f):\n");
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            printf("%5d", f[i][j]);
        }
        printf("\n");
    }

    // Filtre matrisini ekrana yazdır
    printf("\n   Filtre Matrisi (v):\n");
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf("%5d", v[i][j]);
        }
        printf("\n");
    }

    // Sonuç matrisini (g) ekrana yazdır
    printf("\n   Sonuç Matris (g):\n");
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            printf("%10d", g[i][j]);
        }
        printf("\n");
    }

    return 0;
}