#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "libProjet.h"
#define _CRT_SECURE_NO_WARNINGS


void main(void)
{
	FILE* F = NULL;
	char gt[] = "Data\\test_JPG\\";
	char images[] = "Data\\test_ppm\\";



	// listing images pgm/ppm dans un fichier
	//system("dir /S /B Database\\GT\\*.p*m > listeDesImages.txt");

	system("dir /S /B Data");

	IMAGE img = lectureImage("test_ppm\\HC1\\HC1_1.ppm");
	IMAGE img_roi = RoiImage(img, 50, 0);
	sauvegardeImage(img_roi, "P6", "res\\test.ppm");



	// traitement des images individuellement
	//F = fopen("listeDesImages.txt", "r");
	//while (fgets(ligne, 1000, F) != NULL) // fgets lit tous les caractères y compris les séparateurs contrairement à  fscanf.
	//{
	//	int size = 0;

	//	/* --- Calculer size --- */
	//	int i = strlen(ligne) - 2;
	//	while (ligne[i] != '\\') {
	//		size++;
	//		i--;
	//	}

	//	char* nomImg = malloc(size + 1); /* place pour caractère fin de chaîne */
	//	//printf("size = %d", size);

	//	for (int k = 0; k < size; k++) {
	//		nomImg[k] = ligne[i + 1 + k];
	//	}
	//	nomImg[size] = '\0';

	//	/* --- extraire le nom de l'image uniquement --- */
	//	printf("%s\n", nomImg);

	//	/* répertoire GT */
	//	char* cheminIn = malloc(size + sizeof(gt));
	//	for (int k = 0; k < sizeof(gt); k++)
	//		cheminIn[k] = gt[k];
	//	for (int k = 0; k <= size; k++)
	//		cheminIn[sizeof(gt) - 1 + k] = nomImg[k];

	//	IMAGE imgGT = lectureImage(cheminIn);


	//	/* répertoire Images */
	//	char* cheminImages = malloc(size + sizeof(images));
	//	for (int k = 0; k < sizeof(images); k++)
	//		cheminImages[k] = images[k];
	//	for (int k = 0; k <= size; k++)
	//		cheminImages[sizeof(images) - 1 + k] = nomImg[k];

	//	IMAGE img = lectureImage(cheminImages);

	//	IMAGE BWI = seuillageOtsu(inverseImage(img));

	//	float IoU = indiceIoUImage(imgGT, BWI);

	//	moy += IoU;
	//	med[idx] = IoU;
	//	idx += 1;


	//	free(cheminIn);
	//	liberationImage(&img);
	//	free(cheminImages);
	//	liberationImage(&img);
	//	//liberationImage(&compImg);

	//	free(nomImg);
	//}
	//triEchangeTableauFloat(med, 300);
	//printf("Moyenne IoU : %f \n", moy / 300);
	//printf("Mediane IoU : %f", med[149]);
	//fclose(F);

}