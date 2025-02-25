//***********************************************************************************************************************
//**                                                                                                                   **
//**                                     SAKARYA ÜNÝVERSÝTESÝ                                                          **
//**                          BÝLGÝSAYAR VE BÝLÝÞÝM BÝLÝMLERÝ FAKÜLTESÝ                                                **
//**                                BÝLGÝSAYAR MÜHENDÝSLÝÐÝ BÖLÜMÜ                                                     **
//**                                                                                                                   **
//**                                  ÖDEV NUMARASI...: 1                                                              **
//**                                  ÖÐRENCÝ ADI.....: SUDE ANDURMAN                                                  **
//**                                  ÖÐRENCÝ NUMARASI: b231210005                                                     **
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

	string ogrenciadlari[20] = { "Ayþe", "Ali", "Veli" ,"Sude", "Ahmet", "Zeynep", "Ceyhun", "Cihan", "Polat", "Çakýr", "Sýla", "Büþra", "Miray", "Tuna", "Cengiz", "Zehra", "Enes", "Sena", "Ýnci", "Cemil" };
	string ogrencisoyadlari[20] = { "Korhan", "Aydýn","Korkmaz","Yýldýrým", "Türk", "Koç", "Sabancý", "Soydan", "Küçükler", "Çelik", "Altýn", "Karababa", "Andurman", "Erik", "Taþ", "Bal", "Ceviz", "Sönmez", "Konmaz", "Mecit" };

	int os;
	cout << "Öðrenci sayýsýný giriniz : "; cin >> os; cout << endl;

	struct ogrenci
	{
		string adi[400];
		string soyadi[400];
	}o20, o30, o50;//o20: %20 lik öðrencilerin adlarý için, o30:%30 luk öðrenciler için , o50:%50 likler için

	struct notlar//notlarý tutmak için
	{
		int v[400];
		int o1[400];
		int o2[400];
		int ks1[400];
		int ks2[400];
		int f[400];
		float ogrenci[400];//ortalamalar için
	}n20, n30, n50;//n20:%20 liklerin notlarý...

	struct carpan//çarpanlarý almak için
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
	int carpantoplamý;
	do
	{
		cout << "Vize'nin carpanini giriniz  : "; cin >> c.vize; cout << endl;
		cout << "Final'in carpanini giriniz  : "; cin >> c.final; cout << endl;
		cout << "1. Odev'in carpanini giriniz  : "; cin >> c.odev; cout << endl;
		cout << "2. Odev'in carpanini giriniz  : "; cin >> c.odev2; cout << endl;
		cout << "1. Kisa Sinav'ýn carpanini giriniz  : "; cin >> c.kisasinav; cout << endl;
		cout << "2. Kisa Sinav'ýn carpanini giriniz  : "; cin >> c.kisasinav2; cout << endl;
		carpantoplamý = c.vize + c.final + c.odev + c.odev2 + c.kisasinav + c.kisasinav2;


		if (carpantoplamý > 100)
		{
			cout << " Gecersiz" << endl;
			cout << "Lütfen toplamlarý 100 olacak þekilde giriniz." << endl;
			cout << "Tekrar girmek 'e' tuþuna basýnýz";
			cin >> devam; cout << endl;


		}
		else if (carpantoplamý < 100)
		{
			cout << " Geçersiz" << endl;
			cout << "Lütfen toplamlarý 100 olacak þekilde giriniz." << endl;
			cout << "Tekrar girmek 'e' tuþuna basýnýz.";
			cin >> devam; cout << endl;
		}
		else
			devam = 'h';//çarpanlarýn toplamý 100 olduðundan döngüden çýkmak için. son.ort==100 kullanýnca döngüden çýkmýyordu bu yüzden char kullandým.

		system("CLS");

	} while (devam != 'h');
	//buraya kadar sýnav çarpanlarýnýn alýnmasý 

	srand(time(0));
	for (int i = 0; i < os * 0.2; i++)//%20 lik için rastgele isim oluþturulmasý
	{
		int adi = rand() % 20;
		int soyadi = rand() % 20;
		o20.soyadi[i] = ogrencisoyadlari[soyadi];
		o20.adi[i] = ogrenciadlari[adi];

	}
	for (int i = 0; i < os * 0.3; i++)//%30 luk için rastgele isim oluþturulmasý
	{
		int adi = rand() % 20;
		int soyadi = rand() % 20;
		o30.soyadi[i] = ogrencisoyadlari[soyadi];
		o30.adi[i] = ogrenciadlari[adi];

	}
	for (int i = 0; i < os * 0.5; i++)//%50 lik için rastgele isim oluþturulmasý
	{
		int adi = rand() % 20;
		int soyadi = rand() % 20;
		o50.soyadi[i] = ogrencisoyadlari[soyadi];
		o50.adi[i] = ogrenciadlari[adi];

	}//Ýsimleri ayrý ayrý diziye almamýn nedeni en aþþaðýda verilerin ekrana yazýlmasýnda i=0 ile baþlandýðý için her aralýkta isimler de 0. indisten tekrar alýnýyordu.

	for (int i = 0; i < (int)(os * 0.2); i++)// %20 lik kýsmýn notlarý için
	{

		n20.v[i] = 80 + (rand() % 21);//notlarýn korunmasý için dizi elemanýna atanmasý
		n20.o1[i] = 80 + (rand() % 21);
		n20.o2[i] = 80 + (rand() % 21);
		n20.ks1[i] = 80 + (rand() % 21);
		n20.ks2[i] = 80 + (rand() % 21);
		n20.f[i] = 80 + (rand() % 21);
		n20.ogrenci[i] = (n20.v[i] * (c.vize * 0.01)) + (n20.o1[i] * (c.odev * 0.01)) + (n20.o2[i] * (c.odev2 * 0.01)) + (n20.ks1[i] * (c.kisasinav * 0.01)) + (n20.ks2[i] * (c.kisasinav2 * 0.01)) + (n20.f[i] * (c.final * 0.01));
		//i. öðrencinin ortalamasýný bulmak için üstteki


		v.t20 += n20.v[i];//notlarýn toplamý için.En son çarpanla çarpýlýp ortalamasýný almak için hepsinin topladým.
		o1.t20 += n20.o1[i];
		o2.t20 += n20.o2[i];
		ks1.t20 += n20.ks1[i];
		ks2.t20 += n20.ks2[i];
		f.t20 += n20.f[i];

	}
	for (int i = 0; i < (int)(os * 0.3); i++)//%30 luk kýsmýn notlarý için
	{
		//üstteki for döngüsüyle ayný iþlevler
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
	for (int i = 0; i < (int)(os * 0.5); i++)// %50 lik kýsmýn notlarý için
	{
		//üstteki for döngüsüyle ayný iþlevler
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
	ort20.ort = ((v.t20 * (c.vize * 0.01)) + (o1.t20 * (c.odev * 0.01)) + (o2.t20 * (c.odev2 * 0.01)) + (ks1.t20 * (c.kisasinav * 0.01)) + (ks2.t20 * (c.kisasinav2 * 0.01)) + (f.t20 * (c.final * 0.01))) / (os * 0.2);//%20 liðin not ortalamasý
	ort30.ort = ((v.t30 * (c.vize * 0.01)) + (o1.t30 * (c.odev * 0.01)) + (o2.t30 * (c.odev2 * 0.01)) + (ks1.t30 * (c.kisasinav * 0.01)) + (ks2.t30 * (c.kisasinav2 * 0.01)) + (f.t30 * (c.final * 0.01))) / (os * 0.3);//%30 luðun not ortalamasý
	ort50.ort = ((v.t50 * (c.vize * 0.01)) + (o1.t50 * (c.odev * 0.01)) + (o2.t50 * (c.odev2 * 0.01)) + (ks1.t50 * (c.kisasinav * 0.01)) + (ks2.t50 * (c.kisasinav2 * 0.01)) + (f.t50 * (c.final * 0.01))) / (os * 0.5);//%50 liðin not ortalamasý
	son.ort = (ort20.ort + ort30.ort + ort50.ort) / 3;//genel not ortalamasý
	//buraya kadar ortalamanýn hesaplanmasý için olan iþlemler


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

	for (int i = 0; i < os * 0.2; i++)//80-100 arasý rastgele notlarýn harf sayacý
	{
		if (n20.ogrenci[i] >= 90)
			toplam.AA = toplam.AA + 1;
		else if (n20.ogrenci[i] < 90 && n20.ogrenci[i] >= 85)
			toplam.BA = toplam.BA + 1;
		else
			toplam.BB = toplam.BB + 1;

	}
	for (int i = 0; i < os * 0.5; i++)//50-80 arasý rastgele notlarýn harf sayacý
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
	for (int i = 0; i < os * 0.3; i++)//0-50 arasý rastgele notlarýn harf sayacý
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

	}//buraya kadar en küçük en büyük notun belirlenmesi

	cout << "-----------------" << endl;//estetik görüntü için

	for (int i = 0; i < os * 0.2; i++)//%20 lik kýsmýn verilerinin gösterilmesi
	{

		cout << "-->ÖÐRENCÝ<--" << endl;
		cout << "-----------------" << endl;
		cout << "*" << o20.adi[i] << " " << o20.soyadi[i] << "*" << endl;
		cout << "Vize: " << n20.v[i] << endl;
		cout << "Ödev 1: " << n20.o1[i] << endl;
		cout << "Ödev 2: " << n20.o2[i] << endl;
		cout << "Kýsa Sýnav 1: " << n20.ks1[i] << endl;
		cout << "Kýsa Sýnav 2: " << n20.ks2[i] << endl;
		cout << "Final: " << n20.f[i] << endl;
		cout << "Ortalama: " << n20.ogrenci[i] << endl;
		cout << "Harf Notu: " << harf(n20.ogrenci[i]) << endl;
		cout << "-----------------" << endl;

	}
	for (int i = 0; i < os * 0.5; i++)//%50 lik kýsmýn verilerinin gösterilmesi
	{
		cout << "-->ÖÐRENCÝ<--" << endl;
		cout << "-----------------" << endl;
		cout << "*" << o50.adi[i] << " " << o50.soyadi[i] << "*" << endl;
		cout << "Vize: " << n50.v[i] << endl;
		cout << "Ödev 1: " << n50.o1[i] << endl;
		cout << "Ödev 2: " << n50.o2[i] << endl;
		cout << "Kýsa Sýnav 1: " << n50.ks1[i] << endl;
		cout << "Kýsa Sýnav 2: " << n50.ks2[i] << endl;
		cout << "Final: " << n50.f[i] << endl;
		cout << "Ortalama: " << n50.ogrenci[i] << endl;
		cout << "Harf Notu: " << harf(n50.ogrenci[i]) << endl;
		cout << "-----------------" << endl;

	}
	for (int i = 0; i < os * 0.3; i++)//%30 lik kýsmýn verilerinin gösterilmesi
	{
		cout << "-->ÖÐRENCÝ<--" << endl;
		cout << "-----------------" << endl;
		cout << "*" << o30.adi[i] << " " << o30.soyadi[i] << "*" << endl;
		cout << "Vize: " << n30.v[i] << endl;
		cout << "Ödev 1: " << n30.o1[i] << endl;
		cout << "Ödev 2: " << n30.o2[i] << endl;
		cout << "Kýsa Sýnav 1: " << n30.ks1[i] << endl;
		cout << "Kýsa Sýnav 2: " << n30.ks2[i] << endl;
		cout << "Final: " << n30.f[i] << endl;
		cout << "Ortalama: " << n30.ogrenci[i] << endl;
		cout << "Harf Notu: " << harf(n30.ogrenci[i]) << endl;
		cout << "-----------------" << endl;

	}//Bütün notlar tek bir for döngüsü içinde de gösterilebilirdi ama baþta böyle yapýnca bir daha deðiþtirmedim.

	//son çýktýlar
	cout << "Sýnýfýn Ortalamasý" << setw(25) << "En Yüksek Ortalama" << setw(20) << "En Düþük Ortalama" << endl;
	cout << "----------------------------------------------------------------" << endl;
	cout << setw(10) << son.ort << setw(27) << enbuyuk << setw(20) << enkucuk << endl;
	cout << "----------------------------------------------------------------" << endl;
	cout << "AA alan kiþi sayýsý : " << toplam.AA << endl;
	cout << "BA alan kiþi sayýsý : " << toplam.BA << endl;
	cout << "BB alan kiþi sayýsý : " << toplam.BB << endl;
	cout << "CB alan kiþi sayýsý : " << toplam.CB << endl;
	cout << "CC alan kiþi sayýsý : " << toplam.CC << endl;
	cout << "DC alan kiþi sayýsý : " << toplam.DC << endl;
	cout << "DD alan kiþi sayýsý : " << toplam.DD << endl;
	cout << "FD alan kiþi sayýsý : " << toplam.FD << endl;
	cout << "FF alan kiþi sayýsý : " << toplam.FF << endl;
}

string harf(int x)//her öðrencinin harf notunu tek tek belirlememek için. float x alýnca aþýrý yükleme hatasý veriyordu o yüzden x i int aldým.
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