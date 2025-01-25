#include <stdio.h>
#include "platform.h"
#include "xil_printf.h"

#include "xil_io.h"
#include "xparameters.h"
#include "xil_types.h"
#include "sleep.h"
#include "counter_signal_generator_axi.h"

int generate(u32 N, u32 T1);

u32 getUserInput(const char *prompt) {
    // Deklaracja zmiennych
    char inputBuffer[12];   // Bufor na dane wejściowe
    int i = 0;
    char c;

    // Wyświetlanie komunikatu dla użytkownika
    xil_printf("\n\r%s", prompt);

    // Pętla do odczytu znaków od użytkownika
    while ((c = getchar()) != '\n' && c != '\r' && i < 11) {
        inputBuffer[i++] = c;    // Zapisz wprowadzony znak
        xil_printf("%c", c);      // Wyświetl wprowadzony znak
    }

    // Kończenie ciągu znaków
    inputBuffer[i] = '\0';

    // Konwertowanie wprowadzonego ciągu znaków na liczbę całkowitą
    // Jeżeli wprowadzona liczba zaczyna się od "0x", to rozpoznamy ją jako hex
    u32 inputValue;

    // Sprawdzamy, czy wprowadzony ciąg zaczyna się od "0x"
    if (inputBuffer[0] == '0' && (inputBuffer[1] == 'x' || inputBuffer[1] == 'X')) {
        inputValue = (u32)strtoul(inputBuffer, NULL, 16); // Podstawa 16 dla liczby hex
    } else {
        inputValue = (u32)strtoul(inputBuffer, NULL, 10); // Podstawa 10 dla liczby dziesiętnej
    }

    // Przełamanie linii po zakończeniu wprowadzania danych
    xil_printf("\n\r");

    // Zwrócenie wprowadzonej wartości jako liczby
    return inputValue;
}

int main()
{
	init_platform();

	u32 UserChoice;
	u32 N = 0x0; // Przykładowy wzór (8-bitowa liczba binarna)
	u32 T1 = 0;     // 32-bitowa liczba dziesiętna;
	u8 START = 0;

	xil_printf("HELLO \n\r");
	while(1)
	{
		UserChoice = getUserInput("Press 1 to start: ");
		if(UserChoice == 1)
		{
			N = getUserInput("Type N value (hex): ");
			T1 = getUserInput("Type T1 value (dec): ");

			xil_printf("\n\r");

			xil_printf("Signal parameters: %x\n\r", N);
			xil_printf("N: %x\n\r", N);
			xil_printf("T1: %d\n\r", T1);

			xil_printf("\n\r");

			START = getUserInput("Press 1 to generate signal: ");
			if (START == 1)
			{
				xil_printf("Generating... \n\r");
				generate(N, T1);
				usleep(25000);

				UserChoice = 0;
			}
			else
			{
				xil_printf("Generation failed \n\r");
			}
		}
	}


    cleanup_platform();
    return 0;
}


