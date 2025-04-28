// Random Password Generator - EN/US - V 1.0.0 Stable.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int Random (int a, int b, int c, int d, char Esp_Char[34]);

int main (void) {

    int Num_Of_Passwords = 0, Size_Passwords = 0, Choice = 0, Esp_Symb_Ask = 0;
    char Esp_Symb_Answer = 'A', End_Ask = 'A', Esp_Symb[34] = "AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA";

    puts ("Welcome to the Random Password Generator!\n");

    while (1) { Num_Of_Passwords = 0, Size_Passwords = 0, Choice = 0, Esp_Symb_Ask = 0, Esp_Symb_Answer = 'A', End_Ask = 'A';

        for (int i = 0; i < 33; i++) { Esp_Symb[i] = 'A'; }

        printf ("\nHow many passwords would you like to generate?: ");
        scanf ("%d", &Num_Of_Passwords);

        printf ("\nHow many characters should each password have?: ");
        scanf ("%d", &Size_Passwords);

        puts ("\nWhat types of characters would you like in your password(s)?:\n");

        puts ("1: Only numbers.");
        puts ("2: Only uppercase letters.");
        puts ("3: Only lowercase letters.");

        puts ("4: Numbers and uppercase letters.");
        puts ("5: Numbers and lowercase letters.");
        
        puts ("6: Uppercase and lowercase letters.");
        puts ("7: All they together.");
        puts ("8: Read the instructions (recommended before using it).\n");

        printf ("Your answer: ");
        scanf ("%d", &Choice);

        if (Choice == 8) { puts ("\nInstructions:\n");
        
            puts ("- Never enter invalid characters, otherwise an unexpected error might happen.");
            puts ("- It is recommended that you generate a password with at least 8 characters for your own safety.");
            puts ("- For security reasons, it is recommended compiling the source code of this program on your own computer (if available).");
            puts ("- This program supports only ASCII characters. Avoid using unusual characters.");
            puts ("\nRestarting...\n");
        
            continue;
        }

        printf ("\nWould you like to include special symbols in your password(s)? (Y/N): ");
        scanf (" %c", &Esp_Symb_Answer);

        if (Esp_Symb_Answer == 'Y' || Esp_Symb_Answer == 'y') { Esp_Symb_Ask = 1; printf ("\nSymbols (33 max): "); scanf ("%s", &Esp_Symb); }
        else if (Esp_Symb_Answer == 'N' || Esp_Symb_Answer == 'n') { Esp_Symb_Ask = 2; }
        else { puts ("\nERROR: Invalid option! - Restarting...\n"); continue; }

        if (Random (Num_Of_Passwords, Size_Passwords, Choice, Esp_Symb_Ask, Esp_Symb) == 0) {

            printf ("\nDone! Would you like to generate more passwords? (Y/N): ");
            scanf (" %c", &End_Ask);

            if (End_Ask == 'Y' || End_Ask == 'y') { puts ("\nRestarting...\n"); continue; }

            else if (End_Ask == 'N' || End_Ask == 'n') { puts ("\nClosing...\n");
            
                Num_Of_Passwords = 0, Size_Passwords = 0, Choice = 0, Esp_Symb_Ask = 0, Esp_Symb_Answer = 'A', End_Ask = 'A';
                for (int i = 0; i < 33; i++) { Esp_Symb[i] = 'A'; }

                return 0;
            }
        }

        else { continue; }
    }

    puts ("ERROR: An unknown error has occurred!\n\nClosing...\n");
    return 1;
}

// End of the main function.

int Random (int a, int b, int c, int d, char Esp_Char[34]) {

    puts ("\nWorking...\n");

    srand (time (NULL) ^ rand());

    char All_Characters[63] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789";
    char Upper_Lower[53] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
    char Numbers_Lower[37] = "abcdefghijklmnopqrstuvwxyz0123456789";
    char Numbers_Upper[37] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
    char Lowercase[27] = "abcdefghijklmnopqrstuvwxyz";
    char Uppercase[27] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    char Numbers[11] = "0123456789";

    if (d == 1) {

        switch (c) { case 1: { int Rand_Pos = 0, Rand_Symb = 0, Num_Of_Symb = rand() % 10, String_Length = strlen (Esp_Char);

                for (int i = 0; i < Num_Of_Symb; i++) {

                    Rand_Pos = rand() % 10, Rand_Symb = rand() % String_Length;
                    Numbers[Rand_Pos] = Esp_Char[Rand_Symb];
                }

                break;
            }

            case 2: { int Rand_Pos = 0, Rand_Symb = 0, Num_Of_Symb = rand() % 26, String_Length = strlen (Esp_Char);
            
                for (int i = 0; i < Num_Of_Symb; i++) {

                    Rand_Pos = rand() % 26, Rand_Symb = rand() % String_Length;
                    Uppercase[Rand_Pos] = Esp_Char[Rand_Symb];
                }

                break;
            }

            case 3: { int Rand_Pos = 0, Rand_Symb = 0, Num_Of_Symb = rand() % 26, String_Length = strlen (Esp_Char);
            
                for (int i = 0; i < Num_Of_Symb; i++) {

                    Rand_Pos = rand() % 26, Rand_Symb = rand() % String_Length;
                    Lowercase[Rand_Pos] = Esp_Char[Rand_Symb];
                }

                break;
            }

            case 4: { int Rand_Pos = 0, Rand_Symb = 0, Num_Of_Symb = rand() % 36, String_Length = strlen (Esp_Char);
            
                for (int i = 0; i < Num_Of_Symb; i++) {

                    Rand_Pos = rand() % 36, Rand_Symb = rand() % String_Length;
                    Numbers_Upper[Rand_Pos] = Esp_Char[Rand_Symb];
                }

                break;
            }

            case 5: { int Rand_Pos = 0, Rand_Symb = 0, Num_Of_Symb = rand() % 36, String_Length = strlen (Esp_Char);
            
                for (int i = 0; i < Num_Of_Symb; i++) {

                    Rand_Pos = rand() % 36, Rand_Symb = rand() % String_Length;
                    Numbers_Lower[Rand_Pos] = Esp_Char[Rand_Symb];
                }

                break;
            }

            case 6: { int Rand_Pos = 0, Rand_Symb = 0, Num_Of_Symb = rand() % 52, String_Length = strlen (Esp_Char);
            
                for (int i = 0; i < Num_Of_Symb; i++) {

                    Rand_Pos = rand() % 52, Rand_Symb = rand() % String_Length;
                    Upper_Lower[Rand_Pos] = Esp_Char[Rand_Symb];
                }

                break;
            }

            case 7: { int Rand_Pos = 0, Rand_Symb = 0, Num_Of_Symb = rand() % 62, String_Length = strlen (Esp_Char);
            
                for (int i = 0; i < Num_Of_Symb; i++) {

                    Rand_Pos = rand() % 62, Rand_Symb = rand() % String_Length;
                    All_Characters[Rand_Pos] = Esp_Char[Rand_Symb];
                }

                break;
            }

            default: { puts ("\nERROR: Invalid option! - Restarting...\n"); return 1; }
        }
    }

    else if (d < 1 || d > 2) { puts ("\nERROR: Invalid option! - Restarting...\n"); return 1; }

    switch (c) { case 1: { int Rand_Char = 0;

            for (int x = 0; x < a; x++) {
            
                for (int y = 0; y < b; y++) {

                    Rand_Char = rand() % 10;
                    printf ("%c", Numbers[Rand_Char]);
                }

                puts ("");
            }
            
            break;
        }

        case 2: { int Rand_Char = 0;

            for (int x = 0; x < a; x++) {
            
                for (int y = 0; y < b; y++) {

                    Rand_Char = rand() % 26;
                    printf ("%c", Uppercase[Rand_Char]);
                }

                puts ("");
            }
            
            break;
        }

        case 3: { int Rand_Char = 0;
            
            for (int x = 0; x < a; x++) {
            
                for (int y = 0; y < b; y++) {

                    Rand_Char = rand() % 26;
                    printf ("%c", Lowercase[Rand_Char]);
                }

                puts ("");
            }
            
            break;
        }

        case 4: { int Rand_Char = 0;
            
            for (int x = 0; x < a; x++) {
            
                for (int y = 0; y < b; y++) {

                    Rand_Char = rand() % 36;
                    printf ("%c", Numbers_Upper[Rand_Char]);
                }

                puts ("");
            }
            
            break;
        }

        case 5: { int Rand_Char = 0;
            
            for (int x = 0; x < a; x++) {
            
                for (int y = 0; y < b; y++) {

                    Rand_Char = rand() % 36;
                    printf ("%c", Numbers_Lower[Rand_Char]);
                }

                puts ("");
            }
            
            break;
        }

        case 6: { int Rand_Char = 0;
            
            for (int x = 0; x < a; x++) {
            
                for (int y = 0; y < b; y++) {

                    Rand_Char = rand() % 52;
                    printf ("%c", Upper_Lower[Rand_Char]);
                }

                puts ("");
            }
            
            break;
        }

        case 7: { int Rand_Char = 0;
            
            for (int x = 0; x < a; x++) {
            
                for (int y = 0; y < b; y++) {

                    Rand_Char = rand() % 62;
                    printf ("%c", All_Characters[Rand_Char]);
                }

                puts ("");
            }
            
            break;
        }

        default: { puts ("\nERROR: Invalid option! - Restarting...\n"); return 1; }
    }

    a = 0, b = 0, c = 0, d = 0;
    for (int i = 0; i < 33; i++) { Esp_Char[i] = 'A'; }

    return 0;
}

// End of the code.