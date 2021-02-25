#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void menuSort();
void insertionSort(int angka[], int size);
void bubbleSort(int angka[], int size);
void quickSort(int angka[],int terkecil,int terbesar);
void menuSearch();
double sequentialSearch(int angka[], int size, int angkaDicari);
double binarySearch(int angka[], int terkecil, int terbesar, int angkaDicari);
int clean();

int main(){
	char pilihan, enterCheck;
    system("cls");
    printf("\n\t\t\t\t------------PRAKTIKUM ALPROG MODUL 3------------");
    printf("\n\t\t\t\t-------------------KELOMPOK 2-------------------");
    printf("\n\t\t\t\t\t================================");
    printf("\n\t\t\t\t\tProgram 3.1 Sorting & Searching ");
    printf("\n\t\t\t\t\t================================");
	printf("\n\t\t\tPilih operasi yang diinginkan:     \n");
	printf("\t\t\t[1] Sorting                          \n");
	printf("\t\t\t[2] Searching                        \n");
	printf("\t\t\t[3] Tutup Program                    \n");

	do{
		printf("\t\t\tMasukkan pilihan: ");
		if(((scanf(" %c%c", &pilihan, &enterCheck)) != 2 || enterCheck != '\n') && clean()){
			printf("Inputan salah! Mohon hanya memasukkan angka dari 1 hingga 3\n\n");
		}
		else{
			if(pilihan == '1'){
				menuSort();
				break;
			}
			else if(pilihan == '2'){
				menuSearch();
				break;
			}
			else if(pilihan == '3'){
				exit(0);
				break;
			}
			else{
				printf("Inputan salah! Mohon hanya memasukkan angka dari 1 hingga 3\n\n");
			}
		}
	}while(1);

	return 0;
}

void menuSort(){
	clock_t waktu;
	double waktu_dibutuhkan[3];
	int i, size;
	char pilihan, enterCheck;
	system("cls");

	printf("\t\t\t+-------------------------------------------------+\n");
	printf("\t\t\t|                     SORTING                     |\n");
	printf("\t\t\t+-------------------------------------------------+\n\n\n");

	printf("\t\t\t    +----------------------------------------+\n");
	printf("\t\t\t    |                  MENU                  |\n");
	printf("\t\t\t    +----------------------------------------+\n");
	printf("\t\t\t    |           1. 1000 Data                 |\n");
	printf("\t\t\t    |           2. 16000 Data                |\n");
	printf("\t\t\t    |           3. 64000 Data                |\n");
	printf("\t\t\t    |           4. Kembali                   |\n");
	printf("\t\t\t    +----------------------------------------+\n\n\n");

	do{
		printf("\t\t\tMasukkan pilihan: ");
		if(((scanf(" %c%c", &pilihan, &enterCheck)) != 2 || enterCheck != '\n') && clean()){
			printf("\t\t\tInputan salah! Mohon hanya memasukkan angka dari 1 hingga 4\n\n");
		}
		else{
			if(pilihan == '1'){
				int angka[1000], temp[1000];

				system("cls");
				size = sizeof(angka) / sizeof(angka[0]);
				srand((unsigned) time(NULL));

				for(i=0; i<size; i++){
					angka[i] = rand();
					temp[i] = angka[i];
				}

				waktu = clock();
				insertionSort(temp, size);
				waktu = clock() - waktu;

				waktu_dibutuhkan[0] = (double)(waktu) / CLOCKS_PER_SEC;

				for(i=0; i<size; i++){
					if(i == size - 1){
						printf(" dan %d.", temp[i]);
					}
					else{
						printf(" %d,", temp[i]);
					}
					temp[i] = angka[i];
				}

				waktu = clock();
				bubbleSort(temp, size);
				waktu = clock() - waktu;

				waktu_dibutuhkan[1] = (double)(waktu) / CLOCKS_PER_SEC;

				for(i=0; i<size; i++){
					if(i == size - 1){
						printf(" dan %d.", temp[i]);
					}
					else{
						printf(" %d,", temp[i]);
					}
					temp[i] = angka[i];
				}

				waktu = clock();
				quickSort(temp, 0, size-1);
				waktu = clock() - waktu;

				waktu_dibutuhkan[2] = (double)(waktu) / CLOCKS_PER_SEC;

				for(i=0; i<size; i++){
					if(i == size - 1){
						printf(" dan %d.", temp[i]);
					}
					else{
						printf(" %d,", temp[i]);
					}
					temp[i] = angka[i];
				}

				printf("\n\nInsertion Sort Membutuhkan %f Detik Untuk Mensortir Data, Sedangkan\n", waktu_dibutuhkan[0]);
				printf("Bubble Sort Membutuhkan %f Detik Untuk Mensortir Data, dan\n", waktu_dibutuhkan[1]);
				printf("Quick Sort Membutuhkan %f Detik Untuk Mensortir Data\n", waktu_dibutuhkan[2]);


				if(waktu_dibutuhkan[0] <= waktu_dibutuhkan[1] && waktu_dibutuhkan[0] <= waktu_dibutuhkan[2]){
					printf("Maka Pada Pengurutan Data Kali Ini, Insertion Sort Lebih Cepat Dari Bubble Sort dan Quick Sort\n\n");
				}
				else if(waktu_dibutuhkan[1] <= waktu_dibutuhkan[0] && waktu_dibutuhkan[1] <= waktu_dibutuhkan[2]){
					printf("Maka Pada Pengurutan Data Kali Ini, Bubble Sort Lebih Cepat Dari Insertion Sort dan Quick Sort\n\n");
				}
				else{
					printf("Maka Pada Pengurutan Data Kali Ini, Quick Sort Lebih Cepat Dari Insertion Sort dan Bubble Sort\n\n");
				}

				printf("\nApakah Anda ingin mengurutkan data ulang?\nTekan Y untuk mengulang, N untuk kembali ke menu, dan K untuk menutup program.");
				do{
					printf("\nMasukkan pilihan: ");
					if(((scanf(" %c%c", &pilihan, &enterCheck)) != 2 || enterCheck != '\n') && clean()){
						printf("Inputan salah! Tekan Y untuk mengulang, N untuk kembali ke menu, dan K untuk menutup program.\n\n");
					}
					else{
						if(pilihan == 'Y' || pilihan == 'y'){
							menuSort();
							break;
						}
						else if(pilihan == 'N' || pilihan == 'n'){
							main();
							break;
						}
						else if(pilihan == 'K' || pilihan == 'k'){
							exit(0);
							break;
						}
						else{
							printf("Inputan salah! Tekan Y untuk mengulang, N untuk kembali ke menu, dan K untuk menutup program.\n\n");
						}
					}
				}while(1);

				break;
			}
			else if(pilihan == '2'){
				int angka[16000], temp[16000];

				system("cls");
				size = sizeof(angka) / sizeof(angka[0]);
				srand((unsigned) time(NULL));

				for(i=0; i<size; i++){
					angka[i] = rand();
					temp[i] = angka[i];
				}

				waktu = clock();
				insertionSort(temp, size);
				waktu = clock() - waktu;

				waktu_dibutuhkan[0] = (double)(waktu) / CLOCKS_PER_SEC;

				for(i=0; i<size; i++){
					if(i == size - 1){
						printf(" dan %d.", temp[i]);
					}
					else{
						printf(" %d,", temp[i]);
					}
					temp[i] = angka[i];
				}

				waktu = clock();
				bubbleSort(temp, size);
				waktu = clock() - waktu;

				waktu_dibutuhkan[1] = (double)(waktu) / CLOCKS_PER_SEC;

				for(i=0; i<size; i++){
					if(i == size - 1){
						printf(" dan %d.", temp[i]);
					}
					else{
						printf(" %d,", temp[i]);
					}
					temp[i] = angka[i];
				}

				waktu = clock();
				quickSort(temp, 0, size-1);
				waktu = clock() - waktu;

				waktu_dibutuhkan[2] = (double)(waktu) / CLOCKS_PER_SEC;

				for(i=0; i<size; i++){
					if(i == size - 1){
						printf(" dan %d.", temp[i]);
					}
					else{
						printf(" %d,", temp[i]);
					}
					temp[i] = angka[i];
				}

				printf("\n\nInsertion Sort Membutuhkan %f Detik Untuk Mensortir Data, Sedangkan\n", waktu_dibutuhkan[0]);
				printf("Bubble Sort Membutuhkan %f Detik Untuk Mensortir Data, dan\n", waktu_dibutuhkan[1]);
				printf("Quick Sort Membutuhkan %f Detik Untuk Mensortir Data\n", waktu_dibutuhkan[2]);


				if(waktu_dibutuhkan[0] <= waktu_dibutuhkan[1] && waktu_dibutuhkan[0] <= waktu_dibutuhkan[2]){
					printf("Maka Pada Pengurutan Data Kali Ini, Insertion Sort Lebih Cepat Dari Bubble Sort dan Quick Sort\n\n");
				}
				else if(waktu_dibutuhkan[1] <= waktu_dibutuhkan[0] && waktu_dibutuhkan[1] <= waktu_dibutuhkan[2]){
					printf("Maka Pada Pengurutan Data Kali Ini, Bubble Sort Lebih Cepat Dari Insertion Sort dan Quick Sort\n\n");
				}
				else{
					printf("Maka Pada Pengurutan Data Kali Ini, Quick Sort Lebih Cepat Dari Insertion Sort dan Bubble Sort\n\n");
				}

				printf("\nApakah Anda ingin mengurutkan data ulang?\nTekan Y untuk mengulang, N untuk kembali ke menu, dan K untuk menutup program.");
				do{
					printf("\nMasukkan pilihan: ");
					if(((scanf(" %c%c", &pilihan, &enterCheck)) != 2 || enterCheck != '\n') && clean()){
						printf("Inputan salah! Tekan Y untuk mengulang, N untuk kembali ke menu, dan K untuk menutup program.\n\n");
					}
					else{
						if(pilihan == 'Y' || pilihan == 'y'){
							menuSort();
							break;
						}
						else if(pilihan == 'N' || pilihan == 'n'){
							main();
							break;
						}
						else if(pilihan == 'K' || pilihan == 'k'){
							exit(0);
							break;
						}
						else{
							printf("Inputan salah! Tekan Y untuk mengulang, N untuk kembali ke menu, dan K untuk menutup program.\n\n"); // menampilkan error apabila inputan salah
						}
					}
				}while(1);

				break;
			}
			else if(pilihan == '3'){
				int angka[6400], temp[64000];

				system("cls");
				size = sizeof(angka) / sizeof(angka[0]);
				srand((unsigned) time(NULL));

				for(i=0; i<size; i++){
					angka[i] = rand();
					temp[i] = angka[i];
				}

				waktu = clock();
				insertionSort(temp, size);
				waktu = clock() - waktu;

				waktu_dibutuhkan[0] = (double)(waktu) / CLOCKS_PER_SEC;

				for(i=0; i<size; i++){
					if(i == size - 1){
						printf(" dan %d.", temp[i]);
					}
					else{
						printf(" %d,", temp[i]);
					}
					temp[i] = angka[i];
				}

				waktu = clock();
				bubbleSort(temp, size);
				waktu = clock() - waktu;

				waktu_dibutuhkan[1] = (double)(waktu) / CLOCKS_PER_SEC;

				for(i=0; i<size; i++){
					if(i == size - 1){
						printf(" dan %d.", temp[i]);
					}
					else{
						printf(" %d,", temp[i]);
					}
					temp[i] = angka[i];
				}

				waktu = clock();
				quickSort(temp, 0, size-1);
				waktu = clock() - waktu;

				waktu_dibutuhkan[2] = (double)(waktu) / CLOCKS_PER_SEC;

				for(i=0; i<size; i++){
					if(i == size - 1){
						printf(" dan %d.", temp[i]);
					}
					else{
						printf(" %d,", temp[i]);
					}
					temp[i] = angka[i];
				}

				printf("\n\nInsertion Sort Membutuhkan %f Detik Untuk Mensortir Data, Sedangkan\n", waktu_dibutuhkan[0]);
				printf("Bubble Sort Membutuhkan %f Detik Untuk Mensortir Data, dan\n", waktu_dibutuhkan[1]);
				printf("Quick Sort Membutuhkan %f Detik Untuk Mensortir Data\n", waktu_dibutuhkan[2]);


				if(waktu_dibutuhkan[0] <= waktu_dibutuhkan[1] && waktu_dibutuhkan[0] <= waktu_dibutuhkan[2]){
					printf("Maka Pada Pengurutan Data Kali Ini, Insertion Sort Lebih Cepat Dari Bubble Sort dan Quick Sort\n\n");
				}
				else if(waktu_dibutuhkan[1] <= waktu_dibutuhkan[0] && waktu_dibutuhkan[1] <= waktu_dibutuhkan[2]){
					printf("Maka Pada Pengurutan Data Kali Ini, Bubble Sort Lebih Cepat Dari Insertion Sort dan Quick Sort\n\n");
				}
				else{
					printf("Maka Pada Pengurutan Data Kali Ini, Quick Sort Lebih Cepat Dari Insertion Sort dan Bubble Sort\n\n");
				}

				printf("\nApakah Anda ingin mengurutkan data ulang?\nTekan Y untuk mengulang, N untuk kembali ke menu, dan K untuk menutup program.");
				do{
					printf("\nMasukkan pilihan: ");
					if(((scanf(" %c%c", &pilihan, &enterCheck)) != 2 || enterCheck != '\n') && clean()){
						printf("Inputan salah! Tekan Y untuk mengulang, N untuk kembali ke menu, dan K untuk menutup program.\n\n");
					}
					else{
						if(pilihan == 'Y' || pilihan == 'y'){
							menuSort();
							break;
						}
						else if(pilihan == 'N' || pilihan == 'n'){
							main();
							break;
						}
						else if(pilihan == 'K' || pilihan == 'k'){
							exit(0);
							break;
						}
						else{
							printf("Inputan salah! Tekan Y untuk mengulang, N untuk kembali ke menu, dan K untuk menutup program.\n\n");
						}
					}
				}while(1);

				break;
			}
			else if(pilihan == '4'){
				main();
				break;
			}
			else{
				printf("Inputan salah! Mohon hanya memasukkan angka dari 1 hingga 4\n\n");
			}
		}
	}while(1);
}

void insertionSort(int angka[], int size){
	int i,j,patokan;

	for(i=1; i<size; i++){
		patokan = angka[i];

		j = i - 1;

		while(j >= 0 && angka[j] > patokan){
			angka[j+1] = angka[j];
			j--;
		}

		angka[j+1] = patokan;
	}
}

void bubbleSort(int angka[], int size){
	int i,j,temp;

	for(i=0; i<size-1; i++){
		for(j=0; j<size-1-i; j++){
			if(angka[j] > angka[j+1]){
				temp = angka[j];
				angka[j] = angka[j+1];
				angka[j+1] = temp;
			}
		}
	}
}

void quickSort(int angka[],int terkecil,int terbesar){
	int i, j, patokan, temp;


	if(terkecil<terbesar){
		patokan = terkecil;
    	i = terkecil;
    	j = terbesar;

    	while(i < j){
    		while(angka[i] <= angka[patokan] && i < terbesar){
            	i++;
    		}
        	while(angka[j] > angka[patokan]){
            	j--;
            }
        	if(i < j){
        		temp = angka[i];
        		angka[i] = angka[j];
        		angka[j] = temp;
        	}
    	}

		temp = angka[patokan];
    	angka[patokan] = angka[j];
    	angka[j] = temp;
    	quickSort(angka, terkecil, j-1);
    	quickSort(angka, j+1, terbesar);
	}
}

void menuSearch(){
	int i, size, angkaDicari;
	char pilihan, enterCheck;
	double waktu_dibutuhkan[2];
	system("cls");

	printf("\t\t\t+-------------------------------------------------+\n");
	printf("\t\t\t|                    SEARCHING                    |\n");
	printf("\t\t\t+-------------------------------------------------+\n\n\n");

	printf("\t\t\t    +----------------------------------------+\n");
	printf("\t\t\t    |                  MENU                  |\n");
	printf("\t\t\t    +----------------------------------------+\n");
	printf("\t\t\t    |           1. 1000 Data                 |\n");
	printf("\t\t\t    |           2. 16000 Data                |\n");
	printf("\t\t\t    |           3. 64000 Data                |\n");
	printf("\t\t\t    |           4. Kembali                   |\n");
	printf("\t\t\t    +----------------------------------------+\n\n\n");

	do{
		printf("\t\t\tMasukkan pilihan: ");
		if(((scanf(" %c%c", &pilihan, &enterCheck)) != 2 || enterCheck != '\n') && clean()){
			printf("\t\t\tInputan salah! Mohon hanya memasukkan angka dari 1 hingga 4\n\n");
		}
		else{
			if(pilihan == '1'){
				int angka[1000];

				system("cls");
				size = sizeof(angka) / sizeof(angka[0]);
				srand((unsigned) time(NULL));

				for(i=0; i<size; i++){
					angka[i] = rand();
				}

				quickSort(angka, 0, size-1);

				do{
					printf("\t\t\tMasukkan Angka Yang Ingin Dicari: ");
					if(((scanf("%d%c", &angkaDicari, &enterCheck)) != 2 || enterCheck != '\n') && clean()){
						printf("\t\t\tInputan salah! Mohon hanya memasukkan angka mulai dari 0\n\n");
					}
					else{
						if(angkaDicari < 0){
							printf("\t\t\tInputan salah! Mohon hanya memasukkan angka mulai dari 0\n\n");
						}
						else{
							break;
						}
					}
				}while(1);

				waktu_dibutuhkan[0] = sequentialSearch(angka, size, angkaDicari);
				waktu_dibutuhkan[1] = binarySearch(angka, 0, size-1, angkaDicari);

				printf("\n\nSequential Search Membutuhkan %f Detik Untuk Mencari Data, Sedangkan\nBinary Search Membutuhkan %f Detik Untuk Mencari Data\n", waktu_dibutuhkan[0], waktu_dibutuhkan[1]);
				if(waktu_dibutuhkan[0] <= waktu_dibutuhkan[1]){
					printf("Maka Pada Pencarian Kali Ini, Sequential Search Lebih Cepat Dari Binary Search\n\n");
				}
				else{
					printf("Maka Pada Pencarian Kali Ini, Binary Search Lebih Cepat Dari Sequential Search\n\n");
				}

				printf("\nApakah Anda ingin mencari data ulang?\nTekan Y untuk mengulang, N untuk kembali ke menu, dan K untuk menutup program.");
				do{
					printf("\nMasukkan pilihan: ");
					if(((scanf(" %c%c", &pilihan, &enterCheck)) != 2 || enterCheck != '\n') && clean()){
						printf("Inputan salah! Tekan Y untuk mengulang, N untuk kembali ke menu, dan K untuk menutup program.\n\n");
					}
					else{
						if(pilihan == 'Y' || pilihan == 'y'){
							menuSearch();
							break;
						}
						else if(pilihan == 'N' || pilihan == 'n'){
							main();
							break;
						}
						else if(pilihan == 'K' || pilihan == 'k'){
							exit(0);
							break;
						}
						else{
							printf("Inputan salah! Tekan Y untuk mengulang, N untuk kembali ke menu, dan K untuk menutup program.\n\n");
						}
					}
				}while(1);

				break;
			}
			else if(pilihan == '2'){
				int angka[16000];

				system("cls");
				size = sizeof(angka) / sizeof(angka[0]);
				srand((unsigned) time(NULL));

				for(i=0; i<size; i++){
					angka[i] = rand();
				}

				quickSort(angka, 0, size-1);

				do{
					printf("\n\t\t\tMasukkan Angka Yang Ingin Dicari: ");
					if(((scanf("%d%c", &angkaDicari, &enterCheck)) != 2 || enterCheck != '\n') && clean()){
						printf("\t\t\tInputan salah! Mohon hanya memasukkan angka mulai dari 0\n\n");
					}
					else{
						if(angkaDicari < 0){
							printf("\t\t\tInputan salah! Mohon hanya memasukkan angka mulai dari 0\n\n");
						}
						else{
							break;
						}
					}
				}while(1);

				waktu_dibutuhkan[0] = sequentialSearch(angka, size, angkaDicari);
				waktu_dibutuhkan[1] = binarySearch(angka, 0, size-1, angkaDicari);

				printf("\n\nSequential Search Membutuhkan %f Detik Untuk Mencari Data, Sedangkan\nBinary Search Membutuhkan %f Detik Untuk Mencari Data\n", waktu_dibutuhkan[0], waktu_dibutuhkan[1]);
				if(waktu_dibutuhkan[0] <= waktu_dibutuhkan[1]){
					printf("Maka Pada Pencarian Kali Ini, Sequential Search Lebih Cepat Dari Binary Search\n\n");
				}
				else{
					printf("Maka Pada Pencarian Kali Ini, Binary Search Lebih Cepat Dari Sequential Search\n\n");
				}

				printf("\nApakah Anda ingin mencari data ulang?\nTekan Y untuk mengulang, N untuk kembali ke menu, dan K untuk menutup program.");
				do{
					printf("\nMasukkan pilihan: ");
					if(((scanf(" %c%c", &pilihan, &enterCheck)) != 2 || enterCheck != '\n') && clean()){
						printf("Inputan salah! Tekan Y untuk mengulang, N untuk kembali ke menu, dan K untuk menutup program.\n\n");
					}
					else{
						if(pilihan == 'Y' || pilihan == 'y'){
							menuSearch();
							break;
						}
						else if(pilihan == 'N' || pilihan == 'n'){
							main();
							break;
						}
						else if(pilihan == 'K' || pilihan == 'k'){
							exit(0);
							break;
						}
						else{
							printf("Inputan salah! Tekan Y untuk mengulang, N untuk kembali ke menu, dan K untuk menutup program.\n\n");
						}
					}
				}while(1);

				break;
			}
			else if(pilihan == '3'){
				int angka[64000];

				system("cls");
				size = sizeof(angka) / sizeof(angka[0]);
				srand((unsigned) time(NULL));

				for(i=0; i<size; i++){
					angka[i] = rand();
				}

				quickSort(angka, 0, size-1);

				do{
					printf("Masukkan Angka Yang Ingin Dicari: ");
					if(((scanf("%d%c", &angkaDicari, &enterCheck)) != 2 || enterCheck != '\n') && clean()){
						printf("Inputan salah! Mohon hanya memasukkan angka mulai dari 0\n\n");
					}
					else{
						if(angkaDicari < 0){
							printf("Inputan salah! Mohon hanya memasukkan angka mulai dari 0\n\n");
						}
						else{
							break;
						}
					}
				}while(1);

				waktu_dibutuhkan[0] = sequentialSearch(angka, size, angkaDicari);
				waktu_dibutuhkan[1] = binarySearch(angka, 0, size-1, angkaDicari);

				printf("\n\nSequential Search Membutuhkan %f Detik Untuk Mencari Data, Sedangkan\nBinary Search Membutuhkan %f Detik Untuk Mencari Data\n", waktu_dibutuhkan[0], waktu_dibutuhkan[1]);
				if(waktu_dibutuhkan[0] < waktu_dibutuhkan[1]){
					printf("Maka Pada Pencarian Kali Ini, Sequential Search Lebih Cepat Dari Binary Search\n\n");
				}
				else{
					printf("Maka Pada Pencarian Kali Ini, Binary Search Lebih Cepat Dari Sequential Search\n\n");
				}

				printf("\nApakah Anda ingin mencari data ulang?\nTekan Y untuk mengulang, N untuk kembali ke menu, dan K untuk menutup program.");
				do{
					printf("\nMasukkan pilihan: ");
					if(((scanf(" %c%c", &pilihan, &enterCheck)) != 2 || enterCheck != '\n') && clean()){
						printf("Inputan salah! Tekan Y untuk mengulang, N untuk kembali ke menu, dan K untuk menutup program.\n\n");
					}
					else{
						if(pilihan == 'Y' || pilihan == 'y'){
							menuSearch();
							break;
						}
						else if(pilihan == 'N' || pilihan == 'n'){
							main();
							break;
						}
						else if(pilihan == 'K' || pilihan == 'k'){
							exit(0);
							break;
						}
						else{
							printf("Inputan salah! Tekan Y untuk mengulang, N untuk kembali ke menu, dan K untuk menutup program.\n\n");
						}
					}
				}while(1);

				break;
			}
			else if(pilihan == '4'){
				main();
				break;
			}
			else{
				printf("Inputan salah! Mohon hanya memasukkan angka dari 1 hingga 4\n\n");
			}
		}
	}while(1);
}

double sequentialSearch(int angka[], int size, int angkaDicari){
	clock_t waktu;
	double waktu_dibutuhkan;
	int i, counter=0;

	waktu = clock();
	for(i=0; i<size; i++){
		if(i == size - 1){
			printf(" dan %d.", angka[i]);
		}
		else{
			printf(" %d,", angka[i]);
		}
		if(angka[i] == angkaDicari){
			counter++;
		}
	}
	waktu = clock() - waktu;
	waktu_dibutuhkan = (double)(waktu) / CLOCKS_PER_SEC;

	if(counter == 0){
		printf("\n\nTidak Ada Angka Yang Sesuai!");
	}
	else{
		int indexAngkaDicari[counter];
		counter = 0;

		for(i=0; i<size; i++){
			if(angka[i] == angkaDicari){
				indexAngkaDicari[counter] = i;
				counter++;
			}
		}

		printf("\n\nAngka Ditemukan Pada Index:");
		for(i=0; i<counter; i++){
			if(i == 0 && i == counter - 1 ){
				printf(" %d.", indexAngkaDicari[i]);
			}
			else{
				if(i == counter - 1 ){
					printf(" dan %d.", indexAngkaDicari[i]);
				}
				else{
					printf(" %d,", indexAngkaDicari[i]);
				}
			}
		}
	}

	return waktu_dibutuhkan;
}

double binarySearch(int angka[], int terkecil, int terbesar, int angkaDicari){
	clock_t waktu;
	double waktu_dibutuhkan;
	int i, counter=0;

	waktu = clock();
	while(terkecil <= terbesar){
		int tengah = terkecil + (terbesar - terkecil) / 2;

		if(angka[tengah] == angkaDicari){
			counter++;
			for(i = tengah + 1; i < terbesar + 1 && angka[i] == angkaDicari; i++){
				counter++;
			}
			for(i = tengah - 1; i < terbesar + 1 && angka[i] == angkaDicari; i++){
				counter++;
			}
			break;
		}
		else if(angka[tengah] > angkaDicari){
			terbesar = tengah - 1;
		}
		else{
			terkecil = tengah + 1;
		}
	}
	waktu = clock() - waktu;
	waktu_dibutuhkan = (double)(waktu) / CLOCKS_PER_SEC;

	if(counter == 0){
		printf("\n\nTidak Ada Angka Yang Sesuai!");
	}
	else{
		int indexAngkaDicari[counter];
		counter = 0;

		while(terkecil <= terbesar){
			int tengah = terkecil + (terbesar - terkecil) / 2;

			if(angka[tengah] == angkaDicari){
				indexAngkaDicari[counter] = tengah;
				counter++;
				for(i = tengah + 1; i < terbesar + 1 && angka[i] == angkaDicari; i++){
					indexAngkaDicari[counter] = i;
					counter++;
				}
				for(i = tengah - 1; i > 0 && angka[i] == angkaDicari; i--){
					indexAngkaDicari[counter] = i;
					counter++;
				}
				break;
			}
			else if(angka[tengah] > angkaDicari){
				terbesar = tengah - 1;
			}
			else{
				terkecil = tengah + 1;
			}
		}

		printf("\n\nAngka Ditemukan Pada Index:");
		bubbleSort(indexAngkaDicari, counter);
		for(i=0; i<counter; i++){
			if(i == 0 && i == counter - 1 ){
				printf(" %d.", indexAngkaDicari[i]);
			}
			else{
				if(i == counter - 1 ){
					printf(" dan %d.", indexAngkaDicari[i]);
				}
				else{
					printf(" %d,", indexAngkaDicari[i]);
				}
			}
		}
	}

	return waktu_dibutuhkan;
}

int clean(){
	while(getchar() != '\n');
	return 1;
}
