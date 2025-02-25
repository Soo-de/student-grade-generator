//***********************************************************************************************************************
//**                                                                                                                   **
//**                                     SAKARYA �N�VERS�TES�                                                          **
//**                          B�LG�SAYAR VE B�L���M B�L�MLER� FAK�LTES�                                                **
//**                                B�LG�SAYAR M�HEND�SL��� B�L�M�                                                     **
//**                                                                                                                   **
//**                                  �DEV NUMARASI...: 1                                                              **
//**                                  ��RENC� ADI.....: SUDE ANDURMAN                                                  **
//**                                  ��RENC� NUMARASI: b231210005                                                     **
//**                                  DERS GRUBU......: A                                                              **
//**                                                                                                                   **
//***********************************************************************************************************************


#include <iostream>
#include <cstdlib>
#include <ctime>
#include <locale.h>
#include <iomanip>
using namespace std;
string harf(int x);

int main()
{
	setlocale(LC_ALL, "Turkish");

	string ogrenciadlari[20] = { "Ay�e", "Ali", "Veli" ,"Sude", "Ahmet", "Zeynep", "Ceyhun", "Cihan", "Polat", "�ak�r", "S�la", "B��ra", "Miray", "Tuna", "Cengiz", "Zehra", "Enes", "Sena", "�nci", "Cemil" };
	string ogrencisoyadlari[20] = { "Korhan", "Ayd�n","Korkmaz","Y�ld�r�m", "T�rk", "Ko�", "Sabanc�", "Soydan", "K���kler", "�elik", "Alt�n", "Karababa", "Andurman", "Erik", "Ta�", "Bal", "Ceviz", "S�nmez", "Konmaz", "Mecit" };

	int os;
	cout << "��renci say�s�n� giriniz : "; cin >> os; cout << endl;

	struct ogrenci
	{
		string adi[400];
		string soyadi[400];
	}o20, o30, o50;//o20: %20 lik ��rencilerin adlar� i�in, o30:%30 luk ��renciler i�in , o50:%50 likler i�in

	struct notlar//notlar� tutmak i�in
	{
		int v[400];
		int o1[400];
		int o2[400];
		int ks1[400];
		int ks2[400];
		int f[400];
		float ogrenci[400];//ortalamalar i�in
	}n20, n30, n50;//n20:%20 liklerin notlar�...

	struct carpan//�arpanlar� almak i�in
	{
		int vize;
		int odev;
		int odev2;
		int final;
		int kisasinav;
		int kisasinav2;
	}c;

	struct toplam
	{
		int t20 = 0;
		int t30 = 0;
		int t50 = 0;
	}v, o1, o2, ks1, ks2, f;

	struct ortalama
	{
		float ort;

	}ort20, ort30, ort50, son;


	//buradan
	char devam;
	int carpantoplam�;
	do
	{
		cout << "Vize'nin carpanini giriniz  : "; cin >> c.vize; cout << endl;
		cout << "Final'in carpanini giriniz  : "; cin >> c.final; cout << endl;
		cout << "1. Odev'in carpanini giriniz  : "; cin >> c.odev; cout << endl;
		cout << "2. Odev'in carpanini giriniz  : "; cin >> c.odev2; cout << endl;
		cout << "1. Kisa Sinav'�n carpanini giriniz  : "; cin >> c.kisasinav; cout << endl;
		cout << "2. Kisa Sinav'�n carpanini giriniz  : "; cin >> c.kisasinav2; cout << endl;
		carpantoplam� = c.vize + c.final + c.odev + c.odev2 + c.kisasinav + c.kisasinav2;


		if (carpantoplam� > 100)
		{
			cout << " Gecersiz" << endl;
			cout << "L�tfen toplamlar� 100 olacak �ekilde giriniz." << endl;
			cout << "Tekrar girmek 'e' tu�una bas�n�z";
			cin >> devam; cout << endl;


		}
		else if (carpantoplam� < 100)
		{
			cout << " Ge�ersiz" << endl;
			cout << "L�tfen toplamlar� 100 olacak �ekilde giriniz." << endl;
			cout << "Tekrar girmek 'e' tu�una bas�n�z.";
			cin >> devam; cout << endl;
		}
		else
			devam = 'h';//�arpanlar�n toplam� 100 oldu�undan d�ng�den ��kmak i�in. son.ort==100 kullan�nca d�ng�den ��km�yordu bu y�zden char kulland�m.

		system("CLS");

	} while (devam != 'h');
	//buraya kadar s�nav �arpanlar�n�n al�nmas� 

	srand(time(0));
	for (int i = 0; i < os * 0.2; i++)//%20 lik i�in rastgele isim olu�turulmas�
	{
		int adi = rand() % 20;
		int soyadi = rand() % 20;
		o20.soyadi[i] = ogrencisoyadlari[soyadi];
		o20.adi[i] = ogrenciadlari[adi];

	}
	for (int i = 0; i < os * 0.3; i++)//%30 luk i�in rastgele isim olu�turulmas�
	{
		int adi = rand() % 20;
		int soyadi = rand() % 20;
		o30.soyadi[i] = ogrencisoyadlari[soyadi];
		o30.adi[i] = ogrenciadlari[adi];

	}
	for (int i = 0; i < os * 0.5; i++)//%50 lik i�in rastgele isim olu�turulmas�
	{
		int adi = rand() % 20;
		int soyadi = rand() % 20;
		o50.soyadi[i] = ogrencisoyadlari[soyadi];
		o50.adi[i] = ogrenciadlari[adi];

	}//�simleri ayr� ayr� diziye almam�n nedeni en a��a��da verilerin ekrana yaz�lmas�nda i=0 ile ba�land��� i�in her aral�kta isimler de 0. indisten tekrar al�n�yordu.

	for (int i = 0; i < (int)(os * 0.2); i++)// %20 lik k�sm�n notlar� i�in
	{

		n20.v[i] = 80 + (rand() % 21);//notlar�n korunmas� i�in dizi eleman�na atanmas�
		n20.o1[i] = 80 + (rand() % 21);
		n20.o2[i] = 80 + (rand() % 21);
		n20.ks1[i] = 80 + (rand() % 21);
		n20.ks2[i] = 80 + (rand() % 21);
		n20.f[i] = 80 + (rand() % 21);
		n20.ogrenci[i] = (n20.v[i] * (c.vize * 0.01)) + (n20.o1[i] * (c.odev * 0.01)) + (n20.o2[i] * (c.odev2 * 0.01)) + (n20.ks1[i] * (c.kisasinav * 0.01)) + (n20.ks2[i] * (c.kisasinav2 * 0.01)) + (n20.f[i] * (c.final * 0.01));
		//i. ��rencinin ortalamas�n� bulmak i�in �stteki


		v.t20 += n20.v[i];//notlar�n toplam� i�in.En son �arpanla �arp�l�p ortalamas�n� almak i�in hepsinin toplad�m.
		o1.t20 += n20.o1[i];
		o2.t20 += n20.o2[i];
		ks1.t20 += n20.ks1[i];
		ks2.t20 += n20.ks2[i];
		f.t20 += n20.f[i];

	}
	for (int i = 0; i < (int)(os * 0.3); i++)//%30 luk k�sm�n notlar� i�in
	{
		//�stteki for d�ng�s�yle ayn� i�levler
		n30.v[i] = (rand() % 51);
		n30.o1[i] = (rand() % 51);
		n30.o2[i] = (rand() % 51);
		n30.ks1[i] = (rand() % 51);
		n30.ks2[i] = (rand() % 51);
		n30.f[i] = (rand() % 51);
		n30.ogrenci[i] = (n30.v[i] * (c.vize * 0.01)) + (n30.o1[i] * (c.odev * 0.01)) + (n30.o2[i] * (c.odev2 * 0.01)) + (n30.ks1[i] * (c.kisasinav * 0.01)) + (n30.ks2[i] * (c.kisasinav2 * 0.01)) + (n30.f[i] * (c.final * 0.01));


		v.t30 += n30.v[i];
		o1.t30 += n30.o1[i];
		o2.t30 += n30.o2[i];
		ks1.t30 += n30.ks1[i];
		ks2.t30 += n30.ks2[i];
		f.t30 += n30.f[i];

	}
	for (int i = 0; i < (int)(os * 0.5); i++)// %50 lik k�sm�n notlar� i�in
	{
		//�stteki for d�ng�s�yle ayn� i�levler
		n50.v[i] = 50 + (rand() % 31);
		n50.o1[i] = 50 + (rand() % 31);
		n50.o2[i] = 50 + (rand() % 31);
		n50.ks1[i] = 50 + (rand() % 31);
		n50.ks2[i] = 50 + (rand() % 31);
		n50.f[i] = 50 + (rand() % 31);
		n50.ogrenci[i] = (n50.v[i] * (c.vize * 0.01)) + (n50.o1[i] * (c.odev * 0.01)) + (n50.o2[i] * (c.odev2 * 0.01)) + (n50.ks1[i] * (c.kisasinav * 0.01)) + (n50.ks2[i] * (c.kisasinav2 * 0.01)) + (n50.f[i] * (c.final * 0.01));


		v.t50 += n50.v[i];
		o1.t50 += n50.o1[i];
		o2.t50 += n50.o2[i];
		ks1.t50 += n50.ks1[i];
		ks2.t50 += n50.ks2[i];
		f.t50 += n50.f[i];

	}
	//buradan
	ort20.ort = ((v.t20 * (c.vize * 0.01)) + (o1.t20 * (c.odev * 0.01)) + (o2.t20 * (c.odev2 * 0.01)) + (ks1.t20 * (c.kisasinav * 0.01)) + (ks2.t20 * (c.kisasinav2 * 0.01)) + (f.t20 * (c.final * 0.01))) / (os * 0.2);//%20 li�in not ortalamas�
	ort30.ort = ((v.t30 * (c.vize * 0.01)) + (o1.t30 * (c.odev * 0.01)) + (o2.t30 * (c.odev2 * 0.01)) + (ks1.t30 * (c.kisasinav * 0.01)) + (ks2.t30 * (c.kisasinav2 * 0.01)) + (f.t30 * (c.final * 0.01))) / (os * 0.3);//%30 lu�un not ortalamas�
	ort50.ort = ((v.t50 * (c.vize * 0.01)) + (o1.t50 * (c.odev * 0.01)) + (o2.t50 * (c.odev2 * 0.01)) + (ks1.t50 * (c.kisasinav * 0.01)) + (ks2.t50 * (c.kisasinav2 * 0.01)) + (f.t50 * (c.final * 0.01))) / (os * 0.5);//%50 li�in not ortalamas�
	son.ort = (ort20.ort + ort30.ort + ort50.ort) / 3;//genel not ortalamas�
	//buraya kadar ortalaman�n hesaplanmas� i�in olan i�lemler


	struct harfler
	{
		int AA = 0;
		int BA = 0;
		int BB = 0;
		int CB = 0;
		int CC = 0;
		int DC = 0;
		int DD = 0;
		int FD = 0;
		int FF = 0;
	}toplam;

	for (int i = 0; i < os * 0.2; i++)//80-100 aras� rastgele notlar�n harf sayac�
	{
		if (n20.ogrenci[i] >= 90)
			toplam.AA = toplam.AA + 1;
		else if (n20.ogrenci[i] < 90 && n20.ogrenci[i] >= 85)
			toplam.BA = toplam.BA + 1;
		else
			toplam.BB = toplam.BB + 1;

	}
	for (int i = 0; i < os * 0.5; i++)//50-80 aras� rastgele notlar�n harf sayac�
	{
		if (n50.ogrenci[i] < 80 && n50.ogrenci[i] >= 70)
			toplam.CB = toplam.CB + 1;
		else if (n50.ogrenci[i] < 70 && n50.ogrenci[i] >= 60)
			toplam.CC = toplam.CC + 1;
		else if (n50.ogrenci[i] < 60 && n50.ogrenci[i] >= 55)
			toplam.DC = toplam.DC + 1;
		else
			toplam.DD = toplam.DD + 1;

	}
	for (int i = 0; i < os * 0.3; i++)//0-50 aras� rastgele notlar�n harf sayac�
	{
		if (n30.ogrenci[i] < 50 && n30.ogrenci[i] >= 40)
			toplam.FD = toplam.FD + 1;
		else
			toplam.FF = toplam.FF + 1;

	}

	//buradan
	float enbuyuk = n20.ogrenci[0];
	float enkucuk = n30.ogrenci[0];

	for (int i = 0; i < os * 0.2; i++)
	{
		if (enbuyuk < n20.ogrenci[i])
			enbuyuk = n20.ogrenci[i];

	}

	for (int i = 0; i < os * 0.3; i++)
	{
		if (enkucuk > n30.ogrenci[i])
			enkucuk = n30.ogrenci[i];

	}//buraya kadar en k���k en b�y�k notun belirlenmesi

	cout << "-----------------" << endl;//estetik g�r�nt� i�in

	for (int i = 0; i < os * 0.2; i++)//%20 lik k�sm�n verilerinin g�sterilmesi
	{

		cout << "-->��RENC�<--" << endl;
		cout << "-----------------" << endl;
		cout << "*" << o20.adi[i] << " " << o20.soyadi[i] << "*" << endl;
		cout << "Vize: " << n20.v[i] << endl;
		cout << "�dev 1: " << n20.o1[i] << endl;
		cout << "�dev 2: " << n20.o2[i] << endl;
		cout << "K�sa S�nav 1: " << n20.ks1[i] << endl;
		cout << "K�sa S�nav 2: " << n20.ks2[i] << endl;
		cout << "Final: " << n20.f[i] << endl;
		cout << "Ortalama: " << n20.ogrenci[i] << endl;
		cout << "Harf Notu: " << harf(n20.ogrenci[i]) << endl;
		cout << "-----------------" << endl;

	}
	for (int i = 0; i < os * 0.5; i++)//%50 lik k�sm�n verilerinin g�sterilmesi
	{
		cout << "-->��RENC�<--" << endl;
		cout << "-----------------" << endl;
		cout << "*" << o50.adi[i] << " " << o50.soyadi[i] << "*" << endl;
		cout << "Vize: " << n50.v[i] << endl;
		cout << "�dev 1: " << n50.o1[i] << endl;
		cout << "�dev 2: " << n50.o2[i] << endl;
		cout << "K�sa S�nav 1: " << n50.ks1[i] << endl;
		cout << "K�sa S�nav 2: " << n50.ks2[i] << endl;
		cout << "Final: " << n50.f[i] << endl;
		cout << "Ortalama: " << n50.ogrenci[i] << endl;
		cout << "Harf Notu: " << harf(n50.ogrenci[i]) << endl;
		cout << "-----------------" << endl;

	}
	for (int i = 0; i < os * 0.3; i++)//%30 lik k�sm�n verilerinin g�sterilmesi
	{
		cout << "-->��RENC�<--" << endl;
		cout << "-----------------" << endl;
		cout << "*" << o30.adi[i] << " " << o30.soyadi[i] << "*" << endl;
		cout << "Vize: " << n30.v[i] << endl;
		cout << "�dev 1: " << n30.o1[i] << endl;
		cout << "�dev 2: " << n30.o2[i] << endl;
		cout << "K�sa S�nav 1: " << n30.ks1[i] << endl;
		cout << "K�sa S�nav 2: " << n30.ks2[i] << endl;
		cout << "Final: " << n30.f[i] << endl;
		cout << "Ortalama: " << n30.ogrenci[i] << endl;
		cout << "Harf Notu: " << harf(n30.ogrenci[i]) << endl;
		cout << "-----------------" << endl;

	}//B�t�n notlar tek bir for d�ng�s� i�inde de g�sterilebilirdi ama ba�ta b�yle yap�nca bir daha de�i�tirmedim.

	//son ��kt�lar
	cout << "S�n�f�n Ortalamas�" << setw(25) << "En Y�ksek Ortalama" << setw(20) << "En D���k Ortalama" << endl;
	cout << "----------------------------------------------------------------" << endl;
	cout << setw(10) << son.ort << setw(27) << enbuyuk << setw(20) << enkucuk << endl;
	cout << "----------------------------------------------------------------" << endl;
	cout << "AA alan ki�i say�s� : " << toplam.AA << endl;
	cout << "BA alan ki�i say�s� : " << toplam.BA << endl;
	cout << "BB alan ki�i say�s� : " << toplam.BB << endl;
	cout << "CB alan ki�i say�s� : " << toplam.CB << endl;
	cout << "CC alan ki�i say�s� : " << toplam.CC << endl;
	cout << "DC alan ki�i say�s� : " << toplam.DC << endl;
	cout << "DD alan ki�i say�s� : " << toplam.DD << endl;
	cout << "FD alan ki�i say�s� : " << toplam.FD << endl;
	cout << "FF alan ki�i say�s� : " << toplam.FF << endl;
}

string harf(int x)//her ��rencinin harf notunu tek tek belirlememek i�in. float x al�nca a��r� y�kleme hatas� veriyordu o y�zden x i int ald�m.
{
	struct harfler
	{
		string AA = "AA";
		string AB = "AB";
		string BB = "BB";
		string CB = "CB";
		string CC = "CC";
		string DC = "DC";
		string DD = "DD";
		string FD = "FD";
		string FF = "FF";
	}h;

	if (x >= 90)
	{
		return h.AA;
	}
	else if (x >= 85 && x < 90)
	{
		return h.AB;
	}
	else if (x >= 80 && x < 85)
	{
		return h.BB;
	}
	else if (x >= 70 && x < 80)
	{
		return h.CB;
	}
	else if (x >= 60 && x < 70)
	{
		return h.CC;
	}
	else if (x >= 55 && x < 60)
	{
		return h.DC;
	}
	else if (x >= 50 && x < 55)
	{
		return h.DD;
	}
	else if (x >= 40 && x < 50)
	{
		return h.FD;
	}
	else
	{
		return h.FF;
	}
}