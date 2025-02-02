// Kargo Takip Otomasyonu.cpp: Konsol uygulamasının giriş noktasını tanımlar.
//

#include "stdafx.h"//Programın çalışması için gerekli temel kütüphane
#include <iostream>//cin,cout komutlarının tanımlı olduğu kütüphane
#include <locale.h>//Türkçe karakter kullanmak için gerekli kütüphane
#include <string>//string tanımlı değişkenler için gerekli kütüphane
#include <fstream>//Dosyalama işlemleri için gerekli kütüphane
using namespace std;//isim uzayı

void Menu();//Aşağıda yazdığım Menu fonksiyonunun çalışması için yukarıda tanımladım

//Kargo bilgisi değişkenlerinin oludğu class 
class Kargo {
public:
	string fatura_no;//Kayıt bulma,yazma,güncelleme,görüntüleme için baz aldığım temel değişken bunu kullanarak işlemleri gerçekleştireceğiz
	string gonderen_ad;
	string gonderen_soyad;
	string alici_ad;
	string alici_soyad;
	string gonderen_adres;
	string alici_adres;
	string gonderen_tel;
	string alici_tel;
	string gonderen_bayi;
	string alici_bayi;
	string gonderen_tarih;
	string teslimat_tarih;
	string kargo_adet;
	string kargo_kg;
	string kargo_cins;
	string kargo_bedel;

	//Dosyalam işlemleri fonksiyonları
	void KargoYaz();
	void KargoOku();
	void KargoGuncelle();
	void KargoSil();

}k;

//Kargo durumu değişkenlerinin olduğu class
class KargoNerede {
public:
	string nerede;
	string teslim;

	//Dosyalama işlemleri fonksiyonları
	void KargoNeredeYaz();
	void KargoNeredeOku();
	void KargoNeredeGuncelle();

}kn;

//Kargo bilgisi kayıt girme fonksiyonu
void Kargo::KargoYaz() {

	ofstream yaz("Kargo.txt", ios::app);//Kayıt dosyasını Kargo.txt adında oluşturacak komut
	cout << "-----------------------------------------------------------" << endl;
	cout << "Fatura No.........:";
	cin >> k.fatura_no;
	cout << "Gönderen Ad.......:";
	cin >> k.gonderen_ad;
	cout << "Gönderen Soyad....:";
	cin >> k.gonderen_soyad;
	cout << "Alıcı Ad..........:";
	cin >> k.alici_ad;
	cout << "Alıcı Soyad.......:";
	cin >> k.alici_soyad;
	cout << "Gönderen Adres....:";
	cin >> k.gonderen_adres;
	cout << "Alıcı Adres.......:";
	cin >> k.alici_adres;
	cout << "Gönderen Telefon..:";
	cin >> k.gonderen_tel;
	cout << "Alıcı Telefon.....:";
	cin >> k.alici_tel;
	cout << "Gönderen Bayi.....:";
	cin >> k.gonderen_bayi;
	cout << "Alıcı Bayi........:";
	cin >> k.alici_bayi;
	cout << "Gönderme Tarihi...:";
	cin >> k.gonderen_tarih;
	cout << "Teslimat Tarihi...:";
	cin >> k.teslimat_tarih;
	cout << "Kargo Adet........:";
	cin >> k.kargo_adet;
	cout << "Kargo Ağırlığı(KG):";
	cin >> k.kargo_kg;
	cout << "Kargo Cinsi.......:";
	cin >> k.kargo_cins;
	cout << "Kargo Bedeli......:";
	cin >> k.kargo_bedel;
	yaz << k.fatura_no << " " << k.gonderen_ad << " " << k.gonderen_soyad << " " << k.alici_ad << " " << k.alici_soyad << " " << k.gonderen_adres << " " << k.alici_adres << " " << k.gonderen_tel << " " << k.alici_tel << " " << k.gonderen_bayi << " " << k.alici_bayi << " " << k.gonderen_tarih << " " << k.teslimat_tarih << " " << k.kargo_adet << " " << k.kargo_kg << " " << k.kargo_cins << " " << k.kargo_bedel << endl;//Girdiğim verileri Kargo.txt dosyasına yazdırdığım komut
	yaz.close();//Kayıt yapılan dosyayı kapatan komut
	kn.KargoNeredeYaz();//Burada kargo durumu gireceğimiz fonksiyona devam ediyoruz ikisi bir birine bağlantılı olduğu için farklı zamanda yazmak hata yaratabilir

}

//Kargo bilgisi kayıtı okuma fonksiyonu
void Kargo::KargoOku() {
	int kontrol = 0;//Girilen fatura numarasının eşitliğini kontrol eden değişken ve ilk değeri
	char secim;//Menüye geçmek için kullandığım değişken
	ifstream oku("Kargo.txt");//Kayıtı okumak için gerekli olan kayıt okuma komutu
	string temp;//temp girilen fatura numarasını eşitlemek için kullanılan değişken
	cout << "-----------------------------------------------------------" << endl;
	cout << "Görüntülemek İstediğiniz Kayıtın Fatura No:";
	cin >> temp;
	while (!oku.eof())//Kargo.txt dosyasını açık olduğu süre boyunca gerçekleşecek işlemler
	{
		oku >> k.fatura_no >> k.gonderen_ad >> k.gonderen_soyad >> k.alici_ad >> k.alici_soyad >> k.gonderen_adres >> k.alici_adres >> k.gonderen_tel >> k.alici_tel >> k.gonderen_bayi >> k.alici_bayi >> k.gonderen_tarih >> k.teslimat_tarih >> k.kargo_adet >> k.kargo_kg >> k.kargo_cins >> k.kargo_bedel;//Kargo.txt'deki kayıtları okuyan komut
		if (temp == k.fatura_no)//temp ile fatura numarası eşit ise gerçekleşecek işlem
		{
			kontrol = 1;//temp ile fatura numarası eşit ise kontrol değişkeninin değerini değiştiriyorum
			cout << "-----------------------------------------------------------" << endl;
			cout << "Aradığınız Kayıt" << endl;
			cout << "-----------------------------------------------------------" << endl;
			cout << "Gönderen Ad.......:" << k.gonderen_ad << endl;
			cout << "Gönderen Soyad....." << k.gonderen_soyad << endl;
			cout << "Alıcı Ad..........:" << k.alici_ad << endl;
			cout << "Alıcı Soyad.......:" << k.alici_soyad << endl;
			cout << "Gönderen Adres....:" << k.gonderen_adres << endl;
			cout << "Alıcı Adres.......:" << k.alici_adres << endl;
			cout << "Gönderen Telefon..:" << k.gonderen_tel << endl;
			cout << "Alıcı Telefon.....:" << k.alici_tel << endl;
			cout << "Gönderen Bayi.....:" << k.gonderen_bayi << endl;
			cout << "Alıcı Bayi........:" << k.alici_bayi << endl;
			cout << "Gönderme Tarihi...:" << k.gonderen_tarih << endl;
			cout << "Teslimat Tarihi...:" << k.teslimat_tarih << endl;
			cout << "Kargo Adet........:" << k.kargo_adet << endl;
			cout << "Kargo Ağırlığı(KG):" << k.kargo_kg << endl;
			cout << "Kargo Cinsi.......:" << k.kargo_cins << endl;
			cout << "Kargo Bedeli......:" << k.kargo_bedel << endl;
			break;
		}
	}
	if (kontrol == 0)//temp ile fatura numarası eşit değilse gerçekleşecek işlem
	{
		cout << "-----------------------------------------------------------";
		cout << endl << "Kayıt Bulunamadı" << endl;
	}
	oku.close();//Okunan dosyayı kapatıyor
	cout << "-----------------------------------------------------------" << endl;
	cout << "Başka bir işlem yapmak ister misiniz?(E/H)--->";
	cin >> secim;
	if (secim == 'e' || secim == 'E') Menu();//Menüye devam etmek için gerekli yapı
	else exit(0);//Hazır fonksiyon uygulamadan çıkıyor
}

//Kargo kayıtı silme fonksiyonu
void Kargo::KargoSil() {
	int kontrol = 0;//Girilen fatura numarasının eşitliğini kontrol eden değişken ve ilk değeri
	char secim;//Menüye geçmek için kullandığım değişken
	string temp, temp1;//temp girilen fatura numarasını eşitlemek için kullanılan değişken, temp1 iki kere okumayı engellemek için kullanılan değişken
	cout << "-----------------------------------------------------------" << endl;
	cout << "Silmek İstediğiniz Kayıtın Fatura No:";
	cin >> temp;
	ofstream gecici("gecici.txt");//Kargo.txt'nin bilgilerini aktarmak için gecici.txt olarak oluşturduğum dosya ve yazdırma komutu
	ofstream gecici2("gecici2.txt");//Kargonerede.txt bilgilerini aktarmak için gecici2.txt olarak oluşturduğum dosya ve yazdırma komutu
	ifstream oku("Kargo.txt");//Kargo.txt'yi okumak için gerekli komut
	ifstream oku2("KargoNerde.txt");//KargoNerede.txt'yi okumak için gerekli komut
	while (!oku.eof())//Kargo.txt ve KargoNerede.txt açık olduğu süre boyunca gerçekleşecek işlemler
	{
		oku >> k.fatura_no >> k.gonderen_ad >> k.gonderen_soyad >> k.alici_ad >> k.alici_soyad >> k.gonderen_adres >> k.alici_adres >> k.gonderen_tel >> k.alici_tel >> k.gonderen_bayi >> k.alici_bayi >> k.gonderen_tarih >> k.teslimat_tarih >> k.kargo_adet >> k.kargo_kg >> k.kargo_cins >> k.kargo_bedel;//Kargo.txt'deki kayıtları okuyan komut
		oku2 >> kn.nerede >> kn.teslim >> k.fatura_no;//KargoNerede.txt'deki kayıtları okuyan komut
		if (temp1 != k.fatura_no)//temp1 ve fatura numarası farklıysa içerdeki işlemi gerçekleştirecek bunun amacı iki kere okumayı engelleme
		{
			if (temp == k.fatura_no)//temp ve fatura numarası eşit ise gerçekleşecek işlem
			{
				kontrol = 1;//temp ile fatura numarası eşit ise kontrol değişkeninin değerini değiştiriyorum
				cout << "-----------------------------------------------------------" << endl;
				cout << "Silmek İstediginiz Kayıt" << endl;
				cout << "-----------------------------------------------------------" << endl;
				cout << "Gönderen Ad.......:" << k.gonderen_ad << endl;
				cout << "Gönderen Soyad....:" << k.gonderen_soyad << endl;
				cout << "Alıcı Ad..........:" << k.alici_ad << endl;
				cout << "Alıcı Soyad.......:" << k.alici_soyad << endl;
				cout << "Gönderen Adres....:" << k.gonderen_adres << endl;
				cout << "Alıcı Adres.......:" << k.alici_adres << endl;
				cout << "Gönderen Telefon..:" << k.gonderen_tel << endl;
				cout << "Alıcı Telefon.....:" << k.alici_tel << endl;
				cout << "Gönderen Bayi.....:" << k.gonderen_bayi << endl;
				cout << "Alıcı Bayi........:" << k.alici_bayi << endl;
				cout << "Gönderme Tarihi...:" << k.gonderen_tarih << endl;
				cout << "Teslimat Tarihi...:" << k.teslimat_tarih << endl;
				cout << "Kargo Adet........:" << k.kargo_adet << endl;
				cout << "Kargo Ağırlığı(KG):" << k.kargo_kg << endl;
				cout << "Kargo Cinsi.......:" << k.kargo_cins << endl;
				cout << "Kargo Bedeli......:" << k.kargo_bedel << endl;
				cout << "Kargo Nerede......:" << kn.nerede << endl;
				cout << "Teslimat Durumu...:" << kn.teslim << endl;

			}
			else//temp ve fatura numarası eşit değilse gerçekleşecek işlem,burada Kargo.txt-KargoNerede.txt'deki diğer kayıtları gecici.txt-gecici2.txt olarak açtığımız diğer dosyalara yazacağız
			{

				gecici << k.fatura_no << " " << k.gonderen_ad << " " << k.gonderen_soyad << " " << k.alici_ad << " " << k.alici_soyad << " " << k.gonderen_adres << " " << k.alici_adres << " " << k.gonderen_tel << " " << k.alici_tel << " " << k.gonderen_bayi << " " << k.alici_bayi << " " << k.gonderen_tarih << " " << k.teslimat_tarih << " " << k.kargo_adet << " " << k.kargo_kg << " " << k.kargo_cins << " " << k.kargo_bedel << endl;//Kargo.txt dosyasındaki kayıtları gecici.txt dosyanı yazıyoruz
				gecici2 << k.fatura_no << " " << kn.nerede << " " << kn.teslim << endl;//KargoNerede.txt dosyasındaki kayıtları gecici2.txt dosyasına yazıyoruz

			}

			if (kontrol == 0)//Kontrol değişkeni değişmiş ise yapılacak işlem
			{

				cout << "-----------------------------------------------------------" << endl;
				cout << "Kayıt Bulunamadı" << endl;
			}
			else//Kontrol değişkeni değişmemiş ise yapılacak işlem
			{

				cout << "-----------------------------------------------------------" << endl;
				cout << "Kayıt Silindi" << endl;

			}

		}

		temp1 = k.fatura_no;//Bir kere eşitlenme olunca eşitlenen fatura numarasını temp1'e aktarıyorum

	}//Yaptığım bu işlem sonucu fatura numarası eşitlenen kayıt yeni açtığımız gecici.txt-gecici2.txt dosyalarına aktarılmıyor diğer kayıtlar aktarılıyor

	gecici.close();//Kargo.txt aktarmak için açtığım gecici.txt dosyayı kapatıyorum
	oku.close();//Okunan Kargo.txt dosyasını kapatıyorum
	gecici2.close();//KargoNerede.txt aktarmak için açtığım gecici2.txt dosyayı kapatıyorum
	oku2.close();//Okunan KargoNerede.txt dosyasını kapatıyorum
	remove("Kargo.txt");//Kargo.txt dosyasını siliyorum
	remove("KargoNerede.txt");//KargoNerede.txt dosyasını siliyorum
	rename("gecici.txt", "Kargo.txt");//Kargo.txt aktarmak için oluşturdugum gecici.txt dosyasının adını Kargo.txt yapıyorum
	rename("gecici2.txt", "KargoNerede.txt");//KargoNerede.txt aktarmak için oluşturdugum gecici2.txt dosyanın adını KargoNerede.txt yapıyorum
	cout << "-----------------------------------------------------------" << endl;
	cout << "Başka Bir İşlem Yapmak İstermisiniz?(E/H)--->";
	cin >> secim;
	if (secim == 'e' || secim == 'E') Menu();//Menüye devam etmek için gerekli yapı
	else exit(0);//Hazır fonksiyon uygulamadan çıkıyor
}

//Kargo bilgisi güncelleme fonksiyonu
void Kargo::KargoGuncelle() {
	int kontrol = 0;//Girilen fatura numarasının eşitliğini kontrol eden değişken ve ilk değeri
	char secim;//Menüye geçmek için kullandığım değişken
	string temp, temp1;//temp fatura numarasını eşlemek için kullanılan değişken, temp1 iki kere okumayı engellemek için kullanılan değişken
	cout << "-----------------------------------------------------------" << endl;
	cout << "Güncellemek İstediğiniz Kayıtın Fatura No:";
	cin >> temp;
	ofstream gecici("gecici.txt");//Kargo.txt nin bilgilerini aktarmak için gecici.txt olarak oluşturduğum dosya ve yazdırma komutu
	ifstream oku("Kargo.txt");//Kargo.txt'yi okumak için gerekli komut
	while (!oku.eof())//Kargo.txt dosyası açık olduğu süre boyunca gerçekleşecek işlem
	{
		oku >> k.fatura_no >> k.gonderen_ad >> k.gonderen_soyad >> k.alici_ad >> k.alici_soyad >> k.gonderen_adres >> k.alici_adres >> k.gonderen_tel >> k.alici_tel >> k.gonderen_bayi >> k.alici_bayi >> k.gonderen_tarih >> k.teslimat_tarih >> k.kargo_adet >> k.kargo_kg >> k.kargo_cins >> k.kargo_bedel;//Kargo.txt dosyasındaki kayıtları okuyan komut
		if (temp1 != k.fatura_no)// temp1 ve fatura numarası farklıysa içerdeki işlemi gerçekleştirecek bunun amacı iki kere bu işlemin gerçekleşmesini engelleme
		{
			if (k.fatura_no == temp)//temp ve fatura numarası eşit ise gerçekleşecek işlem
			{
				kontrol = 1;//temp ile fatura numarası eşit ise kontrol değişkeninin değerini değiştiriyorum
				cout << "-----------------------------------------------------------" << endl;
				cout << "Kayıttaki Bilgileriniz" << endl;
				cout << "-----------------------------------------------------------" << endl;
				cout << "Gonderen Ad.......:" << k.gonderen_ad << endl;
				cout << "Gonderen Soyad....:" << k.gonderen_soyad << endl;
				cout << "Alici Ad..........:" << k.alici_ad << endl;
				cout << "Alici Soyad.......:" << k.alici_soyad << endl;
				cout << "Gonderen Adres....:" << k.gonderen_adres << endl;
				cout << "Alici Adres.......:" << k.alici_adres << endl;
				cout << "Gonderen Telefon..:" << k.gonderen_tel << endl;
				cout << "Alici Telefon.....:" << k.alici_tel << endl;
				cout << "Gonderen Bayi.....:" << k.gonderen_bayi << endl;
				cout << "Alici Bayi........:" << k.alici_bayi << endl;
				cout << "Gonderme Tarihi...:" << k.gonderen_tarih << endl;
				cout << "Teslimat Tarihi...:" << k.teslimat_tarih << endl;
				cout << "Kargo Adet........:" << k.kargo_adet << endl;
				cout << "Kargo Kilogram....:" << k.kargo_kg << endl;
				cout << "Kargo Cinsi.......:" << k.kargo_cins << endl;
				cout << "Kargo Bedeli......:" << k.kargo_bedel << endl;
				cout << "-----------------------------------------------------------" << endl;
				cout << "Yeni Bilgileri Giriniz" << endl;
				cout << "-----------------------------------------------------------" << endl;
				cout << "Gonderen Ad.......:";
				cin >> k.gonderen_ad;
				cout << "Gonderen Soyad....:";
				cin >> k.gonderen_soyad;
				cout << "Alici Ad..........:";
				cin >> k.alici_ad;
				cout << "Alici Soyad.......:";
				cin >> k.alici_soyad;
				cout << "Gonderen Adres....:";
				cin >> k.gonderen_adres;
				cout << "Alici Adres.......:";
				cin >> k.alici_adres;
				cout << "Gonderen Telefon..:";
				cin >> k.gonderen_tel;
				cout << "Alici Telefon.....:";
				cin >> k.alici_tel;
				cout << "Gonderen Bayi.....:";
				cin >> k.gonderen_bayi;
				cout << "Alici Bayi........:";
				cin >> k.alici_bayi;
				cout << "Gonderme Tarihi...:";
				cin >> k.gonderen_tarih;
				cout << "Teslimat Tarihi...:";
				cin >> k.teslimat_tarih;
				cout << "Kargo Adet........:";
				cin >> k.kargo_adet;
				cout << "Kargo Kilogram....:";
				cin >> k.kargo_kg;
				cout << "Kargo Cinsi.......:";
				cin >> k.kargo_cins;
				cout << "Kargo Bedeli......:";
				cin >> k.kargo_bedel;
				gecici << k.fatura_no << " " << k.gonderen_ad << " " << k.gonderen_soyad << " " << k.alici_ad << " " << k.alici_soyad << " " << k.gonderen_adres << " " << k.alici_adres << " " << k.gonderen_tel << " " << k.alici_tel << " " << k.gonderen_bayi << " " << k.alici_bayi << " " << k.gonderen_tarih << " " << k.teslimat_tarih << " " << k.kargo_adet << " " << k.kargo_kg << " " << k.kargo_cins << " " << k.kargo_bedel << endl;//Yeni bilgileri gecici.txt dosyasına yazdırıyorum
			}
			else//temp ile fatura numarası eşit olmayan yani diğer kayıtları gecici.txt dosyasına yazdırıyorum
			{
				gecici << k.fatura_no << " " << k.gonderen_ad << " " << k.gonderen_soyad << " " << k.alici_ad << " " << k.alici_soyad << " " << k.gonderen_adres << " " << k.alici_adres << " " << k.gonderen_tel << " " << k.alici_tel << " " << k.gonderen_bayi << " " << k.alici_bayi << " " << k.gonderen_tarih << " " << k.teslimat_tarih << " " << k.kargo_adet << " " << k.kargo_kg << " " << k.kargo_cins << " " << k.kargo_bedel << endl;
			}
			if (kontrol == 0)//Kontrol değişkeni değişmemiş ise gerçekleşecek işlem
			{
				cout << "-----------------------------------------------------------" << endl;
				cout << "Kayıt Bulunamadı" << endl;
			}
			else //Kontrol değişkeni değişmiş ise gerçekleşecek işlem
			{
				cout << "-----------------------------------------------------------" << endl;
				cout << "Kayıt Güncellendi" << endl;
			}
		}
		temp1 = k.fatura_no;//Bir kere eşitlenme olup işlemler gerçekleşince temp1'e fatura numarasını aktarıyorum
	}//Burada gerçekleştirdiğim işlem fatura numarası eşitlenen kayıtın mevcut bilgilerini görüntülüyor ve yeni bilgileri girerek gecici.txt dosyasına yazdırıyoruz.Eşitlenme olmayan yani diğer kayıtlar direk gecici.txt dosyasına yazdırılıyor

	gecici.close();//Kargo.txt kayıtlarını aktarmak için açtığım gecici.txt dosyayı kapatıyorum
	oku.close();//Okunan Kargo.txt dosyasını kapatıyorum
	remove("Kargo.txt");//Kargo.txt dosyasını siliyorum
	rename("gecici.txt", "Kargo.txt");//Kargo.txt yerine açtığım gecici.txt dosyasının adını Kargo.txt yapıyorum
	cout << "-----------------------------------------------------------" << endl;
	cout << "Başka Bir İşlem Yapmak İstermisiniz?(E/H)--->";
	cin >> secim;
	if (secim == 'e' || secim == 'E') Menu();//Menüye devam etmek için gerekli yapı
	else exit(0);//Hazır fonksiyon uygulamadan çıkıyor
}

//Kargo durumu kayıt girme  fonksiyonu
void KargoNerede::KargoNeredeYaz() {
	char secim;//Menüye dönmek için kullandığım değişken
	ofstream yaz("KargoNerede.txt", ios::app);//Kayıt dosyasını KargoNerede.txt adında oluşturacak komut
	cout << "Kargo Nerede......:";
	cin >> kn.nerede;
	cout << "Teslimat Durumu...:";
	cin >> kn.teslim;
	yaz << kn.nerede << " " << kn.teslim << " " << k.fatura_no << endl;//Girdiğim bilgileri KargoNerede.txt dosyasına yazan komut
	yaz.close();//Kayıt yapılan dosyayı kapatıyor
	cout << "-----------------------------------------------------------" << endl;
	cout << "Kayıt Yazıldı" << endl;
	cout << "-----------------------------------------------------------" << endl;
	cout << "Başka Bir İşlem Yapmak İstermisiniz?(E/H)--->";
	cin >> secim;
	if (secim == 'e' || secim == 'E') Menu();//Menüye devam etmek için gerekli yapı
	else exit(0);//Hazır fonksiyon uygulamadan çıkıyor
}

//Kargo durumu kayıtı okuma fonksiyonu
void KargoNerede::KargoNeredeOku() {
	int kontrol = 0;//Girilen fatura numarasının eşitliğini kontrol eden değişken ve ilk değeri
	char secim;//Menüye dönmek için kullandığım değişken
	ifstream oku("KargoNerede.txt");//KargoNerede.txt dosyasını okumak için gerekli komut
	string temp;//temp fatura numarasını eşlemek için kullanılan değişken
	cout << "-----------------------------------------------------------" << endl;
	cout << "Görüntülemek İstediginiz Kargo Durumunun Fatura No:";
	cin >> temp;
	while (!oku.eof())//KargoNerede.txt dosyası açık olduğu süre boyunca blok içerisindeki işlemler gerçekleşecek
	{
		oku >> kn.nerede >> kn.teslim >> k.fatura_no;//KargoNerede.txt dosyasındaki kayıtları okuyan komut
		if (temp == k.fatura_no)//temp ve fatura numarası eşit ise gerçekleşecek işlem
		{
			kontrol = 1;//temp ile fatura numarası eşit ise kontrol değişkeninin değerini değiştiriyorum
			cout << "-----------------------------------------------------------" << endl;
			cout << "Aradığınız Kayıt" << endl;
			cout << "-----------------------------------------------------------" << endl;
			cout << "Kargo Nerede......:" << kn.nerede << endl;
			cout << "Teslimat Durumu...:" << kn.teslim << endl;
			break;
		}
	}
	if (kontrol == 0) //Kontrol değişkeni değişmemiş ise gerçekleşecek işlem
	{
		cout << "------------------------------------------------------" << endl;
		cout << "Kayıt Bulunamadı" << endl;
	}

	oku.close();//Okunan dosyayı kapatıyorum
	cout << "------------------------------------------------------" << endl;
	cout << "Başka Bir İşlem Yapmak İstermisiniz?(E/H)" << "--->";
	cin >> secim;
	if (secim == 'e' || secim == 'E') Menu();//Menüye devam etmek için gerekli yapı
	else exit(0);//Hazır fonksiyon uygulamadan çıkıyor
}

//Kargo durumu kayıtı güncelleme fonksiyonu
void KargoNerede::KargoNeredeGuncelle() {
	int kontrol = 0;//Girilen fatura numarasının eşitliğini kontrol eden değişken ve ilk değeri
	char secim;//Menüye dönmek için kullandığım değişken
	string temp, temp1;//temp fatura numarasını eşlemek için kullanılan değişken, temp1 iki kere işlemin gerçekleşmesini engellemek için kullanılan değişken
	cout << "-----------------------------------------------------------" << endl;
	cout << "Güncellemek İstediğiniz Kargo Durumunun Fatura No:";
	cin >> temp;
	ofstream gecici("gecici.txt");//KargoNerede.txt nin bilgilerini aktarmak için gecici.txt olarak oluşturdugum dosya ve yazdırma komutu
	ifstream oku("KargoNerede.txt");//KargoNerede.txt dosyasındaki kayıtları okumak için gerekli komut
	while (!oku.eof()) //KargoNerede.txt dosyası açık olduğu süre boyunca gerçeklşecek işlem
	{
		oku >> kn.nerede >> kn.teslim >> k.fatura_no;//KargoNerede.txt dosyasındaki kayıtları okuyan komut
		if (temp1 != k.fatura_no)// temp1 ve fatura numarası farklıysa içerdeki işlemi gerçekleştirecek bunun amacı iki kere bu işlemin gerçekleşmesini engelleme
		{
			if (k.fatura_no == temp) //temp ve fatura no eşleşirse bu blok içindeki işlem gerçekeleşecek 
			{
				kontrol = 1;//Kontrol değişkeninin değerini değiştiriyorum
				cout << "-----------------------------------------------------------" << endl;
				cout << "Kayıttaki Bilgileriniz" << endl;
				cout << "-----------------------------------------------------------" << endl;
				cout << "Kargo Nerede......:" << kn.nerede << endl;
				cout << "Teslimat Durumu...:" << kn.teslim << endl;
				cout << "-----------------------------------------------------------" << endl;
				cout << "Yeni Bilgileri Giriniz" << endl;
				cout << "-----------------------------------------------------------" << endl;
				cout << "Kargo Nerede......:";
				cin >> kn.nerede;
				cout << "Teslimat Durumu...:";
				cin >> kn.teslim;
				gecici << kn.nerede << " " << kn.teslim << " " << k.fatura_no << endl;//Yeni bilgileri dosyaya yazıyor
			}
			else {
				gecici << k.fatura_no << " " << kn.nerede << " " << kn.teslim << endl;//Dosyadaki diğer kayıtları gecici.txt dosyasına yazdırıyor
			}
			if (kontrol == 1) //Kontrol değişkeninin değeri değişmişse gerçekleşecek işlem
			{
				cout << "-----------------------------------------------------------" << endl;
				cout << "Kayıt Güncellendi" << endl;
				cout << "-----------------------------------------------------------" << endl;
			}
			else //Kontrol değişkeninin değeri değişmezse gerçekleşecek işlem
			{
				cout << "-----------------------------------------------------------" << endl;
				cout << "Kayıt Bulunamadı" << endl;
				cout << "-----------------------------------------------------------" << endl;
			}
		}
		temp1 = k.fatura_no;//Bir kere eşitlenme olup işlemler gerçekleşince temp1'e fatura numarasını aktarıyorum
	}//Burada gerçekleştirdiğim işlem fatura numarası eşitlenen kayıtın mevcut bilgilerini görüntülüyor ve yeni bilgileri girerek gecici.txt dosyasına yazdırıyorum.Eşitlenme olmayan yani diğer kayıtlar direk gecici.txt dosyasına yazdırılıyor

	gecici.close();//KargoNerede.txt'deki kayıtları aktarmak için açtığım gecici.txt adlı dosyayı kapatıyorum
	oku.close();//Okunan KargoNerede.txt adlı dosyayı kapatıyorum 
	remove("KargoNerede.txt");//KargoNerede.txt dosyasını siliyorum
	rename("gecici.txt", "KargoNerede.txt");//KargoNerede.txt yerine açtığım gecici.txt dosyasının adını KargoNerede.txt yapıyorum
	cout << "Başka Bir İşlem Yapmak İstermisiniz?(E/H)" << "--->";
	cin >> secim;
	if (secim == 'e' || secim == 'E') Menu();//Menüye devam etmek için gerekli yapı
	else exit(0);//Hazır fonksiyon uygulamadan çıkıyor
}

//Menü fonksiyonu
void Menu() {
	system("cls");//Ekran temizleme komutu her menüye geldiğimde ekranı temizliyor
	int secim;//Menüdeki işlemlerde seçim yapmak için tanımladğım değişken
	cout << "--------------------------------" << endl;
	cout << "-----Kargo Takip Otomasyonu-----" << endl;
	cout << "--------------------------------" << endl;
	cout << "Yapmak İstediğiniz İşlemi Seçin" << endl;
	cout << "--------------------------------" << endl;
	cout << "1-Kargo Kayıt Girişi" << endl;
	cout << "2-Kargo Bilgisi Görüntüleme" << endl;
	cout << "3-Kargo Bilgisi Güncelleme" << endl;
	cout << "4-Kargo Durumu Görüntüleme" << endl;
	cout << "5-Kargo Durumu Güncelleme" << endl;
	cout << "6-Kargo Kayıtı Silme" << endl;
	cout << "7-Uygulamadan Çıkış" << endl;
	cout << "--------------------------------" << endl;
	cout << "Seçiminiz:";
	cin >> secim;
	system("cls");//ekran temizleme komutu
	switch (secim)//Menüdeki seçim için swcith case yapısını kullandım
	{
	case 1: k.KargoYaz(); break;
	case 2: k.KargoOku(); break;
	case 3: k.KargoGuncelle(); break;
	case 4: kn.KargoNeredeOku(); break;
	case 5: kn.KargoNeredeGuncelle(); break;
	case 6: k.KargoSil(); break;
	case 7:exit(0); break;
	default:cout << "Yanlis secim yaptiniz listeden secim yapiniz" << endl; Menu();
		break;
	}
}

int main()
{
	setlocale(LC_ALL, "Turkish");//Türkçe karakter için yaptığım tanımlama

	Kargo k;//kargo class'ını tanıması için yaptığım tanımlama
	KargoNerede kn;//kargonerede class'ını tanıması için yaptığım tanımlama
	Menu();//Menu fonksiyonunun çalışması için yaptğım tanımlama

	system("pause");
	return 0;
}

