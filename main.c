#include <stdio.h>
#include "matrixops.h"

void executeMenu(int **, int *, int *, int *, int *, int *); 
void showMenu();
int hasCharacter(char *); 

int main(int argc, char *argv[]){

   
    int row;        
    int column;     
    int direction;  
    int maxNumber;  
    int stepNumber;
    
    int *pRow = &row;
    int *pColumn = &column;
    int *pDirection = &direction;
    int *pMaxNumber = &maxNumber;
    int *pStepNumber = &stepNumber;
    //---------------------------------

    int commandLineSorunVarmi = 0; 
    if(argc != 6){ 
        printf("arguman sayisi uyusmuyor!\n");
        printf("menuden tekrar isleminizi yapabilirsiniz\n");
        commandLineSorunVarmi = 1;
        
    } 

    if (!commandLineSorunVarmi){ 
        int i; 
        char *argument; 
        for(i = 1; i < argc; i++){
            argument = *(argv + i); 
            if(i == 3){ 
          
                if(*(argument + 0) == '-' && hasCharacter(argument + 1)){
                    printf("lutfen sadece sayi kullaniniz!\n");
                    commandLineSorunVarmi = 1;
                    break;
                } else if(*(argument + 0) == '1' && hasCharacter(argument + 1)){
                    printf("lutfen sadece sayi kullaniniz!\n");
                    commandLineSorunVarmi = 1;
                    break;
                } else if(atoi(argument) != 1 && atoi(argument) != -1){
                    printf("yon bilgisi sadece 1 ve -1 olabilir!\n");
                    commandLineSorunVarmi = 1;
                    break;
                }

                continue;
            }

            if(hasCharacter(argument)){ 
                printf("lutfen karakter veya negatif sayi kullanmayiniz\n");
                printf("lutfen menuden isleminizi tekrar deneyiniz\n");
                commandLineSorunVarmi = 1;
                break;
            }
        }

    } 

    if(!commandLineSorunVarmi){ 
        if(atoi(*(argv + 1)) < 2 || atoi(*(argv + 2)) < 2){ 
            printf("sutun veya satir sayisi minimum 2 olmalidir.\n");
            printf("menude isleminizi tekrar gercklestirebilirsiniz\n");
            commandLineSorunVarmi = 1;
        }

    }
    
    if(!commandLineSorunVarmi){
     
        *pRow = atoi(*(argv + 1));
        *pColumn = atoi(*(argv + 2));
        *pDirection = atoi(*(argv + 3));
        *pMaxNumber = atoi(*(argv + 4));
        *pStepNumber = atoi(*(argv + 5));

        arr = crate2DMatrix(row, column, maxNumber);
        printf("olusturulan dizi: \n");
        printMatrix(arr, row, column);
        rotateMatrix(arr, row, column, direction, stepNumber); 
        printMatrix(arr, row, column); 
        deleteHeap(arr, row); 
    } 

    printf("menu aciliyor...\n");

    executeMenu(arr, pRow, pColumn, pMaxNumber, pDirection, pStepNumber); 
    return 0;
}

void executeMenu(int **array, int *row, int *column, int *maxNumber, int *direction, int *stepNumber){
    int islem2YapildiMi = 0;
    int islem3YapildiMi = 0;
    int islem4YapildiMi = 0;

    while(1){

        char girdi[1000]; 
        showMenu();
        scanf("%s", &girdi);
        
        if(hasCharacter(girdi)){ 
            printf("gecersiz islem.Lutfen tekrar deneyiniz!\n");
            continue;
        }

        if(atoi(girdi) == 1){ 

            if(!(islem2YapildiMi && islem3YapildiMi && islem4YapildiMi)){ 
                printf("uygulamayi calistirmak icin matris olusturup direction ve step number bilgilerini girmeniz gerek!\n");
                continue;
            }
            printf("olusturulan matris: \n");
            printMatrix(array, *row, *column);
            printf("dondurulen matris: \n");
            rotateMatrix(array, *row, *column, *direction, *stepNumber);
            printMatrix(array, *row, *column);
            deleteHeap(array, *row); 

            islem2YapildiMi = 0;
            islem3YapildiMi = 0;
            islem4YapildiMi = 0;

        } else if(atoi(girdi) == 2){

            if(islem2YapildiMi){
                
                deleteHeap(array, *row);
            }

     
            while(1){
                printf("Lutfen satir sayisini giriniz:\n");
                scanf("%s", girdi);
                if(hasCharacter(girdi)){ 
                    printf("satir sayisi karakter veya negatif bir sayi olamaz!\nLutfen tekrar deneyiniz!\n");
                    continue;
                } else if(atoi(girdi) < 2){
                    printf("satir sayisi 2 den kucuk olmamali!\nLutfen tekrar deneyiniz!\n");
                    continue;
                } else{
                    *row = atoi(girdi);
                    break;
                }
            }
            
         
            while(1){

                printf("Lutfen sutun sayisini giriniz:\n");
                scanf("%s", girdi);

                if(hasCharacter(girdi)){ 
                    printf("sutun sayisi karakter veya negatif bir sayi olamaz!\nLutfen tekrar deneyiniz!\n");
                    continue;
                } else if(atoi(girdi) < 2){ 
                    printf("sutun sayisi 2 den kucuk olmamali!\nLutfen tekrar deneyiniz!\n");
                    continue;
                } else {
                    *column = atoi(girdi);
                    break;
                }
            }

            while(1){

                printf("Matrisiniz 0 ile kac arasinda olsun:\n");
                scanf("%s", girdi);//girdi istenir

                if(hasCharacter(girdi)){ 
                    printf("girdi sayisi karakter veya negatif bir sayi olamaz!\nLutfen tekrar deneyiniz!\n");
                    continue;
                } else {
                    *maxNumber = atoi(girdi);
                    break;
                }
            }

        
            array = crate2DMatrix(*row, *column, *maxNumber);
            islem2YapildiMi = 1;
            printf("\n");
            printMatrix(array, *row, *column); 
            printf("matrisiniz olustruruldu!\n");
            
        } else if(atoi(girdi) == 3){ 

          
            while(1){
                printf("Lutfen yon bilgisini giriniz:\n");
                scanf("%s", girdi);

                if(*(girdi + 0) == '-' && hasCharacter(girdi + 1)){
                    printf("lutfen sadece sayi kullaniniz!\nYon bilgisi sadece 1 ve -1 olabilir!\n");
                    continue;
                } else if(*(girdi + 0) == '1' && hasCharacter(girdi + 1)){
                  
                    printf("lutfen sadece sayi kullaniniz!\nYon bilgisi sadece 1 ve -1 olabilir!\n");
                    continue;
                } else if(atoi(girdi) != 1 && atoi(girdi) != -1){ 
                    printf("yon bilgisi sadece 1 veya -1 olabilir!\nLutfen tekrar giriniz!\n");
                    continue;
                } else { 
                    *direction = atoi(girdi);
                    break;
                }
            }
            islem3YapildiMi = 1;
            printf("yon bilgisi girildi!\n");            

        } else if(atoi(girdi) == 4){ 
            while (1) {
                printf("Lutfen adim sayisini giriniz:\n");
                scanf("%s", girdi); 

                if(hasCharacter(girdi)){ 
                    printf("adim sayisi karakter veya negatif bir sayi olamaz!\nLutfen tekrar deneyiniz!\n");
                    continue;
                } else {
                    *stepNumber = atoi(girdi);
                    break;
                }
            }

            islem4YapildiMi = 1;
            printf("adim sayisi girildi!\n");

        } else if(atoi(girdi) == 5){ 
            if(islem2YapildiMi){
                deleteHeap(array, *row);
                printf("heap memory alani temizleniyor...\n");
            }

            printf("program kapatiliyor...\n");

            break;

        } else { 
            printf("gecersiz islem!\nLutfen tekrar deneyiniz!\n");
            continue;
        }
        
    }
}

void showMenu(){ 
	printf("Lutfen yapmak istediginiz islemi seciniz!\n");
	printf("1. Uygulamayi calistir\n");
	printf("2. Matris olustur\n");
	printf("3. Direction\n");
	printf("4. Step number\n");
	printf("5. Exit\n");
}

int hasCharacter(char *str){
	int i = 0;
	while(*(str + i) != '\0'){
		if(!(*(str + i) >= '0' && *(str + i) <= '9')){
			return 1;
		}
		i++;
	}

	return 0;
}