#include <stdio.h>
#include <stdlib.h>
#include <conio.h>


/*Blok Define*/

#define boolean unsigned char
#define true 1
#define false 0
#define Row 6
#define Col 6
#define MaxQ 100
// #define Nil NULL

// typedef int infotype;
// typedef int address;

// typedef struct
// {
//     infotype *T;
//     address HEAD;
//     address TAIL;
//     int MaxEl;
// } Queue;

// #define Head(Q) (Q).T[(Q).HEAD]
// #define Tail(Q) (Q).T[(Q).TAIL]
// #define InfoHead(Q) (Q).T[(Q).HEAD]
// #define InfoTail(Q) (Q).T[(Q).TAIL]
// #define MaxEl(Q) (Q).MaxEl


/*Blok Deklarasi*/

int i, j, menupil, antri;
void enqueue();
void dequeue();
void display();
void jadwal();
void loket();
int queue_studio[MaxQ];
int Head = -1;
int Tail = -1;
int antri = 1;
int kursi[5][5] = {
    {80, 80, 80, 40, 40},
    {80, 80, 80, 40, 40},
    {80, 80, 80, 40, 40},
    {80, 80, 80, 40, 40},
    {80, 80, 80, 40, 40},
};


/*Blok Algoritma*/

void enqueue() {
    int item = antri;
    if(Tail == MaxQ - 1)
        printf("\nAntrian Penuh");
    else
    {
        if(Head== -1)
            Head = 0;
        printf("\nAntrian anda adalah %d", item);
        Tail = Tail + 1;
        queue_studio[Tail] = item;
        antri++;
    }
}

void dequeue() {
    if(Head == -1 || Head > Tail)
    {
        printf("\nAntrian Habis");
        return;
    }
    else
    {
        printf("\nAntrian yang maju adalah : %d", queue_studio[Head]);
        Head = Head + 1;
        loket();
    }
}

void display() {
    int i;
    if(Head == -1 || Head > Tail)
        printf("\nAntrian kosong");
    else
    {
        printf("\nIsi Nomor Antrian\n");
        for(i = Head; i <= Tail; i++)
        {
            printf("%d ", queue_studio[i]);
            printf("\n");
        }
    }
}

void jadwal() {
    int i, j;
    char *matrix[Row][Col] = {
        {"Jam  ", "Studio A", "Studio B", "Studio C", "Studio D", "Studio E"},
        {"10-12", "Film A  ", "Film B  ", "Film C  ", "Film D  ", "Film E  "},
        {"12-14", "Film B  ", "Film C  ", "Film D  ", "Film E  ", "Film A  "},
        {"14-16", "Film C  ", "Film D  ", "Film E  ", "Film A  ", "Film B  "},
        {"16-18", "Film D  ", "Film E  ", "Film A  ", "Film B  ", "Film C  "},
        {"18-20", "Film E  ", "Film A  ", "Film B  ", "Film C  ", "Film D  "},
    };
    printf("\n");
    for (i = 0; i < Row; i++)
    {
        for (j = 0; j < Col; j++)
        {
            printf("%s ", matrix[i][j]);
        }
        printf("\n");
    }
}

void loket() {
    int x, y, jam, studio, pesen, sisa, hasil;
    sisa = 0;
    pesen = 0;

    jadwal();

    printf("Pilih Jam\n");
    printf("1.10-12  2.12-14  3.14-16  4.16-18  5.18-20\n");
    scanf("%d", &jam);
    x = jam - 1;

    printf("Pilih Studio\n");
    printf("1.Studio A  2.Studio B  3.Studio C  4.Studio D  5.Studio E\n");
    scanf("%d", &studio);
    y = studio - 1;

    sisa = kursi[x][y];

    while (sisa == 0)
    {
        printf("Kursi habis, pilih jam atau studio yang lainnya\n");
        printf("Pilih Jam\n");
        printf("1.10-12  2.12-14  3.14-16  4.16-18  5.18-20\n");
        scanf("%d", &jam);
        x = jam - 1;

        printf("Pilih Studio\n");
        printf("1.Studio A  2.Studio B  3.Studio C  4.Studio D  5.Studio E\n");
        scanf("%d", &studio);
        y = studio - 1;

        sisa = kursi[x][y];
    }

    printf("Tersisa kursi sebanyak = %d\n", sisa);
    printf("Pesan kursi sebanyak: ");
    scanf("%d", &pesen);

    hasil = sisa - pesen;

    while ((sisa - pesen) < 0)
    {
        printf("Kursi tidak cukup\n");
        printf("Tersisa kursi sebanyak = %d\n", sisa);
        printf("Pesan kursi sebanyak: ");
        scanf("%d", &pesen);
        hasil = sisa - pesen;
    }
    kursi[x][y] = kursi[x][y] - pesen;
    printf("Pembelian Berhasil\n");
    return;
}

// boolean IsEmpty(Queue Q) {
//     return ((Head(Q) == Nil) && (Tail(Q) == Nil));
// }

// boolean IsFull(Queue Q) {
//     return((Head(Q) == 0) && (Tail(Q) == MaxEl(Q) - 1));
// }

// int NBElmt(Queue Q) {
//     return(Tail(Q) - Head(Q) + 1);
// }

// void CreateEmpty(Queue *Q, int Max) {
//     (*Q).T = (infotype *) malloc (Max * sizeof(infotype));
//     if ((*Q).T != NULL)
//     {
//         MaxEl(*Q) = Max;
//         Head(*Q) = Nil;
//         Tail(*Q) = Nil;
//     }
//     else
//     {
//         MaxEl(*Q) = 0;
//     }
// }

// void Dealokasi(Queue *Q) {
//     MaxEl(*Q) = 0;
//     free((*Q).T);
// }

// void Enqueue(Queue *Q, infotype X) {
//     address i, j;
//     if (IsEmpty(*Q))
//     {
//         Head(*Q)=0;
//     }
//     else
//     {
//         if (Tail(*Q)==MaxEl(*Q)-1)
//         {
//             i = Head(*Q); j = 0;
//             do
//             {
//                 *((*Q).T+j) = *((*Q).T+i);
//                 i++; j++;
//             } while (i<=Tail(*Q));
//             Tail(*Q) = NBElmt(*Q)-1; Head(*Q) = 0;
//         }
//     }
//     Tail(*Q)++;
//     InfoTail(*Q)=X;
// }

// void Dequeue(Queue *Q, infotype *X) {
//     *X = InfoHead(*Q);
//     if (Head(*Q)==Tail(*Q))
//     {
//         Head(*Q)=Nil;
//         Tail(*Q)=Nil;
//     }
//     else
//     {
//         Head(*Q)++;
//     }
// }


/*Blok Main*/

int main() {
    menupil = 0;
    while(menupil != 5)
    {
        system("CLS");
        printf("\nMenu\n");
        printf("1. Tambah Antrian\n");
        printf("2. Loket\n");
        printf("3. Cek Antrian\n");
        printf("4. Cek Jadwal Tayang\n");
        printf("5. Keluar\n");
        printf("Pilih: ");
        menupil = getche();
        printf("\n");
        switch (menupil)
        {
            case '1':
                enqueue();
                break;

            case '2':
                dequeue();
                break;

            case '3':
                display();
                break;

            case '4':
                jadwal();
                break;

            case '5':
                exit(0);
                break;

            default:
                printf("\nTry Again");
        }
        (void)getch();
    }
    return 0;
}
