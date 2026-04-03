#pragma once
#include <math.h>
/* librairie IPSI1 */

typedef struct image {
	int   Nblig;
	int   Nbcol;
	unsigned char*  data;
	unsigned char** pixel;
} IMAGE;

typedef struct rgb {
	unsigned char R;
	unsigned char G;
	unsigned char B;
} RGB;

typedef struct imageRGB {
	int   Nblig;
	int   Nbcol;
	RGB*  data;
	RGB** pixel;
} IMAGERGB;

typedef struct signatures {
	int		min;
	int		max;
	double	moyenne;
	double	ecartType;
	int		mediane;
} SIGNATURES;

typedef struct signature_composantes_connexes {
	int surface;
	float perimetre;
	float compacite;
	int bord;
	float CGi;
	float CGj;
	int HGi;
	int HGj;
	int BDi;
	int BDj;
	IMAGE image;
	float rayon;
} SIGNATURE_COMPOSANTE_CONNEXE;

#define distance(ai,aj,bi,bj) sqrt(((ai-bi)*(ai-bi)+(aj-bj)*(aj-bj)))

IMAGE allocationImage(int Nblig, int Nbcol);
void initialisationAleatoireImage(IMAGE img, int ngMin, int ngMax);

void sauvegardeImage(IMAGE img, const char *type, const char *out);
void liberationImage(IMAGE *im);

IMAGE lectureImage(const char *nom);

IMAGERGB allocationImageRGB(int Nblig, int Nbcol);
IMAGERGB lectureImageRGB(const char *nom);

void sauvegardeImageRGB(IMAGERGB img, const char *type, const char *out);
void liberationImageRGB(IMAGERGB *im);

IMAGE planImage(IMAGERGB img, int plan);
IMAGE luminanceImage(IMAGERGB img, float r, float g, float b);
IMAGE inverseImage(IMAGE img);
IMAGE seuillageImage(IMAGE img, int sInf, int sSup);

IMAGE expansionImage(IMAGE img, int outMin, int outMax);
IMAGE egalisationImage(IMAGE img);
SIGNATURES statistiquesImage(IMAGE img);

IMAGE seuillageOtsu(IMAGE img);

IMAGE labelImage(IMAGE img, int *nbComp); /* image label + nb composantes connexes */

int* histogrammeImage(IMAGE img, int choix, int n);
int* histogrammeImageRGB(IMAGERGB img, int choix, int n);

SIGNATURE_COMPOSANTE_CONNEXE* signaturesImage(IMAGE img, int nbComp);
IMAGE dilatationImage(IMAGE img, int voisinage);
IMAGE erosionImage(IMAGE img, int voisinage);

IMAGE filtrageMoyenImage(IMAGE img, int N);
IMAGERGB filtrageMoyenImageRGB(IMAGERGB img, int N);

IMAGE filtrageTailleImage(IMAGE img, int nbComp, int taille);
IMAGE filtrageBordImage(IMAGE img, int nbComp);

IMAGERGB colorisationImage(IMAGE img, const char* table);
void sauvegardeSignaturesImage(SIGNATURE_COMPOSANTE_CONNEXE* tab, int nbComp, const char* nomFichier);
void liberationSignaturesImage(SIGNATURE_COMPOSANTE_CONNEXE** tab, int nbComp);

IMAGE bouchageTrousImage(IMAGE img);

IMAGE bruitAleatoireImage(IMAGE img, int amplitude);
IMAGERGB masqueImage(IMAGE img, IMAGERGB masque);

float  indiceIoUImage(IMAGE BW1, IMAGE BW2);
IMAGERGB comparaisonImage(IMAGE BW1, IMAGE BW2);

IMAGE normeGradientImage(IMAGE img);