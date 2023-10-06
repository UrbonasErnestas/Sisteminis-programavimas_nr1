#include "mylib.h"

extern char skaiciavimo_Strategija;

studentas::studentas() {
		/*cout << "Ivesk varda:"; cin >> vard;
		cout << "Ivesk pavarde: "; cin >> pav;
		cout << "Kiek pazymiu buvo semetre? "; int n; cin >> n;
		for (int i = 0; i < n; i++) {
			int k;
			cout << "Ivesk " << i + 1 << " semestro pazymi: ";
			cin >> k; paz.push_back(k);
		}
		cout << "Ivesk egzamino pazymi :"; cin >> egz;
		skaiciavimo_Strategija == 'm' ? rezMed() : rezVid();*/

}
studentas::studentas(string v, string p, vector<int>pp, int e) {
	vard = v;
	pav = p;
	paz = pp;
	egz = e;
	skaiciavimo_Strategija == 'm' ? rezMed() : rezVid();
}
studentas::studentas(const studentas& temp) {  // 1. copy constructor
	vard = temp.vard;
	pav = temp.pav;
	paz = temp.paz;
	egz = temp.egz;
	skaiciavimo_Strategija == 'm' ? rezMed() : rezVid();
}
studentas& studentas::operator=(const studentas& temp) // 2. copy assignment
{
	if (this == &temp)
		return *this;
	vard = temp.vard;
	pav = temp.pav;
	paz = temp.paz;
	egz = temp.egz;
	skaiciavimo_Strategija == 'm' ? rezMed() : rezVid();
	return *this;
}
studentas::~studentas() {        // 3. destructor
	vard.clear();
	pav.clear();
	paz.clear();
	egz = 0;
	rez = 0;
}
void studentas::printas() {
	/*printf("|%-10s|%20s|", vard.c_str(), pav.c_str());
	for (auto& a : paz) printf("%3d|", a);
	printf("%10d|\n", egz);*/
}
void studentas::printasRez() {
	printf("|%-10s|%20s|", vard.c_str(), pav.c_str());
	printf("%10f|\n", egz);
}
void studentas::rezVid() {
	float sum = std::accumulate(paz.begin(), paz.end(), 0.0);
	rez = sum / paz.size() * 0.4 + egz * 0.6;
}
void studentas::rezMed() {
	rez = mediana(paz) * 0.4 + egz * 0.6;
}

double studentas::mediana(vector<int> vec) { // nukopijuoja vektoriu
	typedef vector<double>::size_type vecSize;
	vecSize size = vec.size();
	if (size == 0) // std::domain_error deklaruota <stdexcept>
		throw std::domain_error("negalima skaiciuoti medianos");
		sort(vec.begin(), vec.end()); //surusiuojame vektoriu i variacine
		vecSize vid = size / 2; // vidurinis vektoriaus elementas
		return size % 2 == 0 ? (vec[vid] + vec[vid - 1]) / 2.0 : vec[vid]/1.0;
}

std::istream& operator>>(std::istream& in, studentas& a) {
	in >> a.vard;
	in >> a.pav;

	for (int i = 0; i < 5; i++) {
		int k;
		in >> k; a.paz.push_back(k);
	}
	in >> a.egz;
	skaiciavimo_Strategija == 'm' ? a.rezMed() : a.rezVid();
	return in;
}

std::ostream& operator<<(std::ostream& out, const studentas& a) {
	out << a.vard << "; " << a.pav << "; ";
	for (auto& i : a.paz) out << i << " : ";
	out << a.egz << endl;
	return out;
}

/*double studentas::galBalas(double egzaminas, const vector<double>& nd,
	double (*kriterijus)(vector<double>) = mediana) {
	if(nd.size() == 0) // patikriname, ar atliko bent viena ND
		throw std::domain_error("studentas neatliko ne vieno namu darbo");
	return galBalas(egzaminas, kriterijus(nd));
}*/