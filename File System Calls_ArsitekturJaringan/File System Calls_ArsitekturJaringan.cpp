// File System Calls_ArsitekturJaringan.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include<fstream>
#include<string>
#include<vector>
#include"Mahasiswa.h"

using namespace std;

//fungsi untuk membaca file daftar-nama.txt 
vector<string> readTXT()
{
	string TempData;
	vector<string> LstTempData;

	ifstream TxtFile;
	TxtFile.open("daftar-nama.txt");

	while (!TxtFile.eof())
	{
		getline(TxtFile, TempData);		//mengambil satu baris data dan ditaruh di TempData
		LstTempData.push_back(TempData);	//menaruh TempData kedalam vector LstTempData
	}
	TxtFile.close();
	return LstTempData;
}

//fungsi membuat file csv
void CreateMahasiswaCSV()
{
	vector<string> LstDataMahasiswa = readTXT();
	vector<Mahasiswa> LstMahasiswa;

	//membuka file CSV yang telah dibuat sebelumnya
	ofstream MahasiswaCSV;
	MahasiswaCSV.open("4210191019_AmosTarunaSiahaan.csv");

	/*Fungsi for yang akan mengambil data dari vector TmpList
	* berupa nomor, NRP, nama, serta jenis kelamin, kemudian dimasukan kedalam 
	* parameter constructor Mahasiswa yang selanjutnya objek tersebut dimasukan kedalam
	* vector LstMahasiswa
	*/
	for (auto tmpList : LstDataMahasiswa)
	{
		string Num = tmpList.substr(0, tmpList.find('\t'));
		tmpList.erase(0, tmpList.find(Num) + tmpList.find('\t') + 1);

		string NRP = tmpList.substr(0, tmpList.find('\t'));
		tmpList.erase(0, tmpList.find(NRP) + tmpList.find('\t') + 1);

		string Name = tmpList.substr(0, tmpList.find('\t'));
		tmpList.erase(0, tmpList.find(Name) + tmpList.find('\t') + 1);

		string Gender = tmpList.substr(0, tmpList.find('\t'));
		tmpList.erase(0, tmpList.find(Gender) + tmpList.find('\t') + 1);

		Mahasiswa MHS = Mahasiswa(atoi(Num.c_str()), NRP, Name, Gender);

		LstMahasiswa.push_back(MHS);
	}

	//fungsi untuk memasukan data per baris dari LstMahasiswa ke file CSV
	for (auto& i : LstMahasiswa)
	{
		MahasiswaCSV << i.GetNo() << "," << i.GetNRP() <<","<< i.GetNama() << "," << i.GetJenisKelamin() << endl;
		cout<< i.GetNo() << "," << i.GetNRP() <<","<< i.GetNama() << "," << i.GetJenisKelamin() << endl;
	}
	MahasiswaCSV.close();

}
//fungsi membalik data dari file CSV yang telah dibuat
void ReverseMahasiswaCSV()
{
	string TempData;
	vector<Mahasiswa> LstMahasiswa;
	vector<Mahasiswa> LstReverseMahasiswa;
	vector<string> LstTempData;

	//membuka file CSV yang telah dibuat sebelumnya
	ifstream MahasiswaCSV;
	MahasiswaCSV.open("4210191019_AmosTarunaSiahaan.csv");
	//membuat file csv baru
	ofstream ReverseMahasiswaCSV; 
	ReverseMahasiswaCSV.open("4210191019_AmosTarunaSiahaan.csv", ios::app);

	//mengambil data per baris dari file csv 
	while (!MahasiswaCSV.eof())
	{
		getline(MahasiswaCSV, TempData);
		LstTempData.push_back(TempData);
	}

	/*Fungsi for yang akan mengambil data dari vector LstTempData
	* berupa nomor, NRP, nama, serta jenis kelamin, kemudian dimasukan kedalam
	* parameter constructor Mahasiswa yang selanjutnya objek tersebut dimasukan kedalam
	* vector LstMahasiswa;
	*/
	int i = 0;
	for (auto tmpList : LstTempData)
	{
		string Num = tmpList.substr(0, tmpList.find(','));
		tmpList.erase(0, tmpList.find(Num) + tmpList.find(',') + 1);

		string NRP = tmpList.substr(0, tmpList.find(','));
		tmpList.erase(0, tmpList.find(NRP) + tmpList.find(',') + 1);

		string Name = tmpList.substr(0, tmpList.find(','));
		tmpList.erase(0, tmpList.find(Name) + tmpList.find(',') + 1);

		string Gender = tmpList.substr(0, tmpList.find(','));

		Mahasiswa MHS = Mahasiswa(atoi(Num.c_str()), NRP, Name, Gender);

		if (i == 27) {
			break;
		}

		LstMahasiswa.push_back(MHS);
		i++;
	}

	/*fungsi yang akan membalik data dari vector LstMahasiswa
	* kemudian ditaruh kedalam vector LstReverseMahasiswa*/
	int x = 1;
	for (int i = LstMahasiswa.size()-1; i >=0;i--)
	{
		Mahasiswa MHS;
		MHS.SetNo(x+ LstMahasiswa.size());
		MHS.SetNRP(LstMahasiswa[i].GetNRP());
		MHS.SetName(LstMahasiswa[i].GetNama());
		MHS.SetJenisKelamin(LstMahasiswa[i].GetJenisKelamin());
		LstReverseMahasiswa.push_back(MHS);
		x++;
	}

	//fungsi yang akan menaruh data dari vector LstReverseMahasiswa kedelam file CSV
	for (auto& i : LstReverseMahasiswa)
	{
		ReverseMahasiswaCSV << i.GetNo() << "," << i.GetNRP() << "," << i.GetNama() << "," << i.GetJenisKelamin() << endl;
		cout << i.GetNo() << "," << i.GetNRP() << "," << i.GetNama() << "," << i.GetJenisKelamin() << endl;
	}
	ReverseMahasiswaCSV.close();
	MahasiswaCSV.close();
}
//fungsi main menu berisi tampilan serta pilihan yang dapat dipilih user
void MainMenu()
{
	int answer;
	cout << "Welcome!\n this program will read daftar-nama.txt and turn it into .csv file" << endl<<endl;
	cout << "Here's the data: " << endl;
	CreateMahasiswaCSV(); cout << endl;
	cout << "please choose the option below, \n 1: keep the data original \n 2: reverse the data\n";
	cout << "Your Answer(in number): "; cin >> answer;
	if (answer==1)
	{
		cout<<"\t\tAll is done, have a great day !" << endl;
	}
	else if (answer==2)
	{
		ReverseMahasiswaCSV();
	}
}

int main()
{
	MainMenu();
}

/*int main()
{
	const char comma = ',';
	string line, word;
	ifstream in("daftar-nama.txt");
	ofstream out("hasil.csv");
	getline(in, line);
	while (getline(in,line))
	{
		stringstream ss(line); //memisahkan kata dari dalam kalimat
		bool first = true;
		while (ss>>word)	//mengambil satu kata dari string
		{
			if (!first)out << comma;
			out << word;
			first = false;
		}
		out << '\n';

	}
	in.close();
	out.close();
}

*/
// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
