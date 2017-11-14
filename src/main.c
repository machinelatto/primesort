/* Contador de palavras
 *
 * Este programa recebera uma serie de caracteres representando palavras em sua
 * entrada. Ao receber um caractere fim de linha ('\n'), deve imprimir na tela o
 * numero de palavras separadas que recebeu e, apos, encerrar.
 */

#include <stdio.h>
#include <sys/time.h>

int ehprimo(int n){
	int i;
	if(n==1 || n==0) return 0;
	if(n==2) return 1;
	if(n%2==0) return 0; //pares
	for(i=3;i<=n/2;i=i+2){  //testa os ímpares
		if(n%i==0){ //caso o resto de alguma divisão seja 0, encontro um divisor, ou seja ele não é primo
			return 0;
		}
	}
	return 1;
}

int main() {
	//struct timeval rt0, rt1, drt;
	//gettimeofday(&rt0, NULL);
	
	int num=0;
	FILE *fp; //crio o pipe

	fp = popen("sort -n -r","w"); //abro o pipe, w indica write

	while(num!=-1){
		scanf("%d",&num);
		if(!ehprimo(num) && (num!=-1)){
			fprintf(fp, "%d\n", num); //escrevo no pipe cada número nao primo, o pipe ja ordena eles
		}
	}

	pclose(fp); //fecho

	//gettimeofday(&rt1, NULL);
    //timersub(&rt1, &rt0, &drt);  
    //printf("Tempo: %ld.%06ld segundos\n", drt.tv_sec, drt.tv_usec);
}

