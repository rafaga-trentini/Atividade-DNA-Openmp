#include <iostream>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <omp.h>
#include <time.h>

clock_t tInicio, tFim, tDecorrido;
using std::cout; using std::string; using std::endl;

string readFile(const string& path) {
    struct stat sb{};
    string res;

    FILE* file = fopen(path.c_str(), "r");
 
    stat(path.c_str(), &sb);
    res.resize(sb.st_size);
    fread(const_cast<char*>(res.data()), sb.st_size, 1, file);
    fclose(file);

    return res;
}


int main() {
    string filename("arquivos/DNA.txt");
    string content = readFile(filename);
    
	char fita[content.length()];
   	
	strcpy(fita,content.c_str());

	tInicio = clock();
	for (int i = 0; i < content.length(); i++) {		
		switch (toupper(fita[i])) {
			case 'A':
				fita[i] = 'T';
				break;
			case 'C':
				fita[i] = 'G';
				break;
			case 'T':
				fita[i] = 'A';
				break;
			case 'G':
				fita[i] = 'C';
				break;
		}
	}

	tFim = clock();
	tDecorrido = 0;
	tDecorrido = ((tFim - tInicio) / (CLOCKS_PER_SEC / 1000));

	printf("Tempo decorrido: %d\n", tDecorrido);
}
