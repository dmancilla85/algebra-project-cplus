#include "Matriz.h"
#include "Real.h"
#include "Natural.h"
#include <string>
#include <iostream>
#include <fstream>
#include <vector>
#include <ctime>

using namespace std;

#define TEST_PATH_IN  "./test/input/"
#define TEST_PATH_OUT "./test/output/"
#define TEST_EXT_IN	".in"
#define TEST_EXT_OUT	".out"

void testNatural(string);
void testEntero(const char*);
void testReal(const char*);
void testComplejo(const char*);
void testMatriz(const char*);
void testMatrizElemental(const char*);
void generaTestNatural(string testFile, int regs, int maxNum);
void generaTestEntero(const char*);
void generaTestReal(const char*);
void generaTestComplejo(const char*);
void generaTestMatriz(const char*);
void generaTestMatrizElemental(const char*);

class splitstring : public string {
    vector<string> flds;
public:
    splitstring(char *s) : string(s) { };
    vector<string>& split(char delim, int rep=0);
};

// split: receives a char delimiter; returns a vector of strings
// By default ignores repeated delimiters, unless argument rep == 1.
vector<string>& splitstring::split(char delim, int rep) {
    if (!flds.empty()) flds.clear();  // empty vector if necessary
    string work = data();
    string buf = "";
    int i = 0;
    while (i < (int) work.length()) {
        if (work[i] != delim)
            buf += work[i];
        else if (rep == 1) {
            flds.push_back(buf);
            buf = "";
        } else if (buf.length() > 0) {
            flds.push_back(buf);
            buf = "";
        }
        i++;
    }
    if (!buf.empty())
        flds.push_back(buf);
    return flds;
}

int main(int argv, char *argc)
{	
	time_t *hoy = NULL;
	tm *tiempoLocal = NULL;
	time(hoy);
	srand( ( unsigned int ) hoy );
	string nombreGenerado("PRUEBA_");

	/*tiempoLocal = localtime( hoy );
	nombreGenerado += tiempoLocal->tm_year;
	nombreGenerado += tiempoLocal->tm_mon;
	nombreGenerado += tiempoLocal->tm_mday;*/

	//generaTestNatural( "Natural_00", 200, 500);
	testNatural( "Natural_00" );

	system("pause");
	return EXIT_SUCCESS;
}

void testNatural(string testFile)
{
	ifstream file;
	Natural a, b;
	ofstream fileOut;
	char regs[10], line[21];
	int nreg = 0, i;
	string fileName(""), resultado(""), fileOutput("");

	fileName += TEST_PATH_IN;
	fileName += testFile;
	fileName += TEST_EXT_IN;
	fileOutput += TEST_PATH_OUT;
	fileOutput += testFile;
	fileOutput += TEST_EXT_OUT;

	cout << fileName << ": Evaluando registros generados..." << endl;

	file.open( fileName );
	fileOut.open( fileOutput );

	file.getline(regs, 10);

	nreg = atoi( regs );

	for( i = 0; i < nreg; i++)
	{
		file.getline(line, 21);
		splitstring split( line );

		vector<string> flds = split.split('\t');
		
		a = Natural( atoi( flds[0].c_str() ) );

		if( flds.size() > 2 )
			b = Natural( atoi( flds[2].c_str() ) );

		const char *op = flds[1].c_str();

		switch(op[0])
		{	
		case '+':
			fileOut << a << " " << op[0] << " " << b << " = " << a + b << endl;
			cout << a << " " << op[0] << " " << b << " = " << a + b << endl;
			break;

		case '-':
			fileOut << a << " " << op[0] << " " << b << " = " << a - b << endl;
			cout << a << " " << op[0] << " " << b << " = " << a - b << endl; 
			break;

		case '*':
			fileOut << a << " " << op[0] << " " << b << " = " << a * b << endl;
			cout << a << " " << op[0] << " " << b << " = " << a * b << endl;
			break;

		case '/':
			fileOut << a << " " << op[0] << " " << b << " = " << a / b << endl;
			cout << a << " " << op[0] << " " << b << " = " << a / b << endl;
			break;

		case '!':
			fileOut << a << op[0] << " = " << !a << endl;
			cout << a << op[0] << " = " << !a << endl;
		}

	}

	cout << fileOutput << ": Archivo de salida completo" << endl;

	file.close();
	fileOut.close();
}

void testEntero(const char* testFile)
{

}

void testReal(const char* testFile)
{

}

void testComplejo(const char* testFile)
{

}

void testMatriz(const char* testFile)
{

}

void testMatrizElemental(const char* testFile)
{

}

void generaTestNatural(string testFile, int regs, int maxNum)
{
	int i, a, b, op;
	ofstream file;
	string fileName("");

	fileName += TEST_PATH_IN;
	fileName += testFile;
	fileName += TEST_EXT_IN;

	cout << fileName << ": Generando archivo de prueba..." << endl;

	file.open( fileName );
	file << regs << endl;

	for(i = 0; i < regs; i++)
	{
		a = 1 + rand() % maxNum;
		b = 1 + rand() % maxNum;
		op = 1 + rand() % 5;

		switch(op)
		{
		case 1:
			file << a << "\t" <<  "+" << "\t" << b << endl;
			break;

		case 2:
			file << a << "\t" << "-" << "\t" << b << endl;
			break;

		case 3:
			file << a << "\t" << "*" << "\t" << b << endl;
			break;

		case 4:
			file << a << "\t" << "/" << "\t" << b << endl;
			break;

		case 5:
			file << a << "\t" << "!" << endl;
		}
	}

	cout << fileName << ": Operacion finalizada" << endl;
	file.close();
}

void generaTestEntero(const char* testFile)
{

}

void generaTestReal(const char* testFile)
{

}

void generaTestComplejo(const char* testFile)
{

}

void generaTestMatriz(const char* testFile)
{

}

void generaTestMatrizElemental(const char* testFile)
{

}