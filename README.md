**Matris Üzerinde Filtreleme İşlemi**

Bu proje, bir M x N boyutlu matris üzerinde 3x3 filtre matrisi uygulayarak sonuçları bir çıktı matrisi olarak hesaplayan bir C programıdır.



**Özellikler**

Rastgele matris oluşturma: Kullanıcı tarafından belirlenen boyutlarda (M x N) 0-255 arasında rastgele değerlerle doldurulan bir matris oluşturur.
3x3 Filtre Matrisi: Kullanıcıdan alınan bir 3x3 filtre matrisi ile giriş matrisini işler.
Filtreleme İşlemi: Kenar durumlarını kontrol ederek 3x3 filtreyi her piksel üzerinde uygular.
Sonuç Matrisi: Filtreleme işlemi sonrası ortaya çıkan sonucu bir matris olarak gösterir.



**Kod Açıklaması**

getValue Fonksiyonu: Kenar durumu kontrolü yaparak matris dışına taşan elemanları 0 kabul eder.
applyFilter Fonksiyonu: 3x3 filtreyi giriş matrisi üzerinde uygular.
main Fonksiyonu:
Kullanıcıdan matris boyutlarını ve filtre değerlerini alır.
Rastgele bir giriş matrisi oluşturur.
Filtreleme işlemini gerçekleştirir ve tüm sonuçları ekrana yazdırır.



**Matrix Filtering Operation**

This project is a C program that applies a 3x3 filter matrix to an M x N matrix, producing a filtered output matrix as the result.



**Features**

Random Matrix Generation: Creates an M x N matrix filled with random values between 0 and 255 based on user-defined dimensions.
3x3 Filter Matrix: Accepts a 3x3 filter matrix from the user for processing the input matrix.
Filtering Operation: Applies the 3x3 filter to each element of the input matrix while handling boundary conditions.
Result Matrix: Displays the filtered output matrix after applying the filter.



**Code Explanation**

getValue Function: Handles boundary conditions by returning 0 for out-of-bounds elements.
applyFilter Function: Applies the 3x3 filter matrix to the input matrix.
main Function:
Collects matrix dimensions and filter values from the user.
Generates a random input matrix.
Performs the filtering operation and displays the results.
