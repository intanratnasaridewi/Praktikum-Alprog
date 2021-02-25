#include <stdio.h> //header input output

//deklarasi variabel
int menu, isbiner, isMenu, isReset;
int desimal=0, biner, base=1,rem,num; //base disini merupakan berat awalnya
int angkabiner=0;
int sisa, i=1;



int main(){

    menu_utama();
    return 0;
}
int input(int *select){
    char buff[1024];
    char term;
    if(fgets(buff, sizeof(buff), stdin) != NULL && sscanf(buff, "%d %c", select, &term) == 1){
    	if(isReset == 1){
    		return 1;
    	}else if(isMenu==1){
            if(*select<1 && *select>2){
                printf("Pilihan menu tidak tersedia!!!!");
            }
    	}//else if(isbiner==1){
         //   if(*select!=1 || *select!=0){
         //       printf("Masukkan angka dengan benar!!!");
         //   }
    //	}
        return 1;
    }
    printf("\t\t\tInputan Salah, Masukkan Angka!\n");
    return 0;
}


int inputInt(int *selectInt){
    char buff[1024];
    char term;
    if(fgets(buff, sizeof(buff), stdin) != NULL && sscanf(buff, "%d %c", selectInt, &term) == 1){ //pernnyataan sebuah kondisi yang dimana berfungsi sebagai penghandle eror
    	if(*selectInt < 0){
    		printf("\t\t\tTolong inputkan bilangan positif!\n");
    		return 0;
    	}
        return 1;
    }
    printf("\t\t\tInputan Salah, Masukkan Angka!\n");
    return 0;
}

int validationInt(int *varInt, char *promptInt){
    while(1){
        printf(promptInt);
        if(inputInt(varInt))
        break;
    }
}

int validation(int *variabel, char *statement){
    while(1){
        printf(statement);
        if(input(variabel))
        break;
    }
}

void menu_utama(void) {

    puts("\n1. Biner ke desimal");
    puts("2. Desimal ke biner");
    isMenu=1;
    validation(&menu,"Masukkan pilihan Anda");
    isMenu=0;
    if(menu==1){
        isbiner=1;
        validation(&biner,"Masukkan angka biner anda : "); //memasukkan angka biner yang ingin dikonversi
        isbiner=0;
        num=biner;

        while (biner !=0){ //angka biner tidak boleh 0
            rem = biner%10; //membagi sisa biner dengan 10, lalu disimpan pada remainder
            desimal=desimal+rem*base; //desimal akan bernilai 1, karena remainder yang bernilai 1 dikali dengan berat dengan nilai 1
            biner=biner / 10; //variabel biner berfungsi sebagai tempat menyimpan nilai dari pembagian sisa dengan 10
            base=base*2; //dikali 2 karena agar dapat memperoleh nilai desimal dan dilakukan perulangan

        }
        printf("Hasil dari pengkonversian bilangan biner %d anda adalah : %d", num, desimal);
    }else{
        int desimal;
        validationInt(&desimal,"Masukkan angka desimal anda : "); //menginput angka biner
        printf("%d pada bilangan desimal = %d dalam bilangan biner\n", desimal, deskebin(desimal));
    }
    restart();
}

int deskebin(int desimal){


    while (desimal!=0){
        //pengisian sekaligus sisa bagi
        sisa=desimal%2; //sisa dari nilai desimal akan dimodulus 2

        //pengisian sekaligus pembagian
        desimal /= 2; //sama artinya dengan desimal=desimal/2

        //pengisian sekaligus penjumlahan
        angkabiner += sisa*i; //artinya angkabiner= angkabinder+sisa*i

        //pengisian sekaligus perkalian
        i*=10; //artinya seperti i=i*10
    }
    return angkabiner;
}

void restart (void)
{
	int reset;
	isReset = 1;
	printf("\n\t\t\tIngin Mengecek Kembali?\n\n");
	printf("\t\t\t[1]. Kembali Mengecek\n");
	printf("\t\t\t[2]. Keluar\n");
	validation(&reset, "\t\t\tPilihan anda : ");
	if(reset==1)
	{
		system("cls");
		isReset = 0;
		menu_utama();
	}else if(reset==2)
	{
        system("cls");
		printf("\t\t\tTolong berikan bintang lima untuk program ini!!!!");
	}else{
		printf("\n\t\t\tPilihan Tidak Tersedia\n");
		restart();
	}
}
