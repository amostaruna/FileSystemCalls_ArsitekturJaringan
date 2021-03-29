#pragma once
#include<string>
using namespace std;

// class mahasiswa yang berisi data mahasiswa serta fungsi setter dan getter
class Mahasiswa {
private:
	int No;
	string NRP;
	string Nama;
	string JenisKelamin;
public:
	Mahasiswa()
	{
		No = 0;
		NRP = "";
		Nama = "";
		JenisKelamin = "";
	}
	Mahasiswa(int num, string nrp, string name, string gender)
	{
		No = num;
		NRP = nrp;
		Nama = name;
		JenisKelamin = gender;
	}
	int GetNo()
	{
		return No;
	}
	string GetNRP()
	{
		return NRP;
	}
	string GetNama()
	{
		return Nama;
	}
	string GetJenisKelamin()
	{
		return JenisKelamin;
	}
	void SetNo(int x)
	{
		No = x;
	}
	void SetNRP(string x)
	{
		NRP = x;
	}
	void SetName(string x)
	{
		Nama = x;
	}
	void SetJenisKelamin(string x)
	{
		JenisKelamin = x;
	}
};