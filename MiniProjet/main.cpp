#include <stdio.h>
#include <iostream>
#include <string>
#include <list>
#include "dirfilelist.h"
#include "filedialog.h"
#include "inputFile.h"
#include "CImg.h"
#include "image.h"
#include "App.h"


using namespace cimg_library;
using namespace std;


int main() {

	int number;

	cout << "************************************Indexation d'image***********************************" << endl<<endl;
	cout << "1. Importation de dossier/ fichiers" << endl;
	cout << "2. Visualisation" << endl;
	cout << "3. Recherche par mots cles" << endl;
	cout << "4. Quitter/ Sauvegarder" << endl;

	cin >> number;
	
	switch (number){
		case 1:
		{
			list<string> fileList;
			bool error = false;
			string nomDir = "";
			int choix;
			system("cls");
			cout << "1. Importer un dossier" << endl;
			cout << "2. Importer un fichier" << endl;
			cin >> choix;

			switch (choix){
			case 1:	
				cout << "Appel de la boite de selection de dossier" << endl;
				nomDir = browseFolder("Selectionner un dossier :");

				if (nomDir != "")
					cout << "Nom du dossier : " << nomDir << endl;
				else
					cout << "Abandon" << endl;

				error = getDirectoryFileList(nomDir, fileList);

				if (error) cout << "An error occured" << endl;
				else
				{
					fileList.sort();
					cout << "Number of files: " << fileList.size() << endl;
					cout << "File list: " << endl;
					for (list<string>::iterator it = fileList.begin(); it != fileList.end(); it++)
						cout << *it << endl;
				}
				system("pause");
				break;
			case 2: 
				cout << "Appel de la boite de selection de fichier" << endl;
				nomDir = browseFile();

				if (nomDir != "")
					cout << "Nom du fichier : " << nomDir << endl;
				else
					cout << "Abandon" << endl;

				showOneImage(nomDir);

				system("pause");	
				break;
			default:
				break;
			}			
			break;
		}

		case 2: {
			App appli;
			appli.displayWindow();

			break;
		}

		default:
			break;
			
	}

	return 0;
}