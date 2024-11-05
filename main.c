#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>
// Struct para armazenar as propriedades da temperatura
struct user {
    char temp_property;
    float temp;
} user;

// Prototipação das funções
void welcome_msg();
void mainMenu_msg();
void menuConvert_msg(float temp, char temp_property);

// Funções de conversão
void Cfahrenheit(struct user *user_temp);
void Ckelvin(struct user *user_temp);
void FCelsius(struct user *user_temp);
void FKelvin(struct user *user_temp);
void KCelsius(struct user *user_temp);
void Kfahrenheit(struct user *user_temp);

// Função para validar a entrada de temperatura
bool is_valid_temperature(float temp, char temp_property);

int main() {
    char op; // Opção de conversão

    // Exibindo mensagem de boas-vindas
    welcome_msg();

    do {
        // Exibindo mensagem de menu
        mainMenu_msg();

        // Capturando opção do usuário (em lowecase)
        user.temp_property = tolower(getchar());

        // verificando o tipo de dado do input
        if (isdigit(user.temp_property)) {
            printf("\n\n<TIPO DE DADO INCORRETO>\n\n");
            exit(1);
        }

        // Limpando buffer da entrada padrão (teclado)
        while (getchar() != '\n');

        // Verificação de encerramento
        if (user.temp_property == 'e') {
            puts("===================================================");    
            printf("<CONVERSOR FINALIZADO>\n");
            puts("===================================================");
            break;
        }

        // Capturando temperatura do usuário
        printf("Digite a temperatura que deseja converter: ");
        if (scanf("%f", &user.temp) != 1 || !is_valid_temperature(user.temp, user.temp_property)) {

            puts("Temperatura inválida! Por favor, insira um número válido.");

            while (getchar() != '\n'); // Limpa o buffer em caso de entrada inválida

            continue; // Retorna ao início do loop
        }

        // Limpando buffer da entrada padrão (teclado)
        while (getchar() != '\n');

        // Exibindo mensagem de menu de conversão
        menuConvert_msg(user.temp, user.temp_property);

        // Capturando opção de conversão em letra minuscula
        op = tolower(getchar());

        // verificando o tipo de dado do input
        if (isdigit(op)) {
            printf("\n\n<TIPO DE DADO INCORRETO>\n\n");
            exit(1);
        }

        // Limpando buffer da entrada padrão (teclado)
        while (getchar() != '\n');

        // Fluxo de opções
        switch (user.temp_property) {
            case 'c':
                if (op == 'c') {
                    puts("===================================================");
                    printf("Sua temperatura já está em Celsius [%.2fºC]\n", user.temp);
                    puts("===================================================");
                } else if (op == 'f') {
                    Cfahrenheit(&user);
                    puts("===================================================");
                    printf("Sua temperatura foi convertida para Fahrenheit [%.2fºF]\n", user.temp);
                    puts("===================================================");
                } else if (op == 'k') {
                    Ckelvin(&user);
                    puts("===================================================");
                    printf("Sua temperatura foi convertida para Kelvin [%.2fºK]\n", user.temp);
                    puts("===================================================");
                }
                break;

            case 'f':
                if (op == 'f') {
                    puts("===================================================");
                    printf("Sua temperatura já está em Fahrenheit [%.2fºF]\n", user.temp);
                    puts("===================================================");
                } else if (op == 'c') {
                    FCelsius(&user);
                    puts("===================================================");
                    printf("Sua temperatura foi convertida para Celsius [%.2fºC]\n", user.temp);
                    puts("===================================================");
                } else if (op == 'k') {
                    FKelvin(&user);
                    puts("===================================================");
                    printf("Sua temperatura foi convertida para Kelvin [%.2fºK]\n", user.temp);
                    puts("===================================================");
                }
                break;

            case 'k':
                if (op == 'k') {
                    puts("===================================================");
                    printf("Sua temperatura já está em Kelvin [%.2fºK]\n", user.temp);
                    puts("===================================================");
                } else if (op == 'c') {
                    KCelsius(&user);
                    puts("===================================================");
                    printf("Sua temperatura foi convertida para Celsius [%.2fºC]\n", user.temp);
                    puts("===================================================");
                } else if (op == 'f') {
                    Kfahrenheit(&user);
                    puts("===================================================");
                    printf("Sua temperatura foi convertida para Fahrenheit [%.2fºF]\n", user.temp);
                    puts("===================================================");
                }
                break;

            default:
                puts("Opção inválida! Tente novamente.");
                break;
        }

        printf("Deseja converter mais alguma coisa? (Y para sim / N para não): ");
        op = tolower(getchar()); // capturando em letra minuscula

        // verificando o tipo de dado do input
        if (isdigit(op)) {
            printf("\n\n<TIPO DE DADO INCORRETO>\n\n");
            exit(1);
        }


        if (op == 'N') {
            puts("===================================================");    
            printf("<CONVERSOR FINALIZADO>\n");
            puts("===================================================");    
            return 0;
        }
        putchar('\n');
        while (getchar() != '\n'); // Limpa o buffer

    } while (1);

    return 0;
}

// Procedimentos

void welcome_msg() {
    // Exibe mensagem de boas-vindas
    puts("===================================================");
    puts("  Bem-vindo ao Conversor de Temperatura!");
    puts("  Escolha a escala e o valor que deseja converter.");
    puts("===================================================");
}

void mainMenu_msg() {
    // Exibe mensagem de menu para entrada
    puts("Escolha a escala de entrada da temperatura:\n");
    printf("C - Celsius\nF - Fahrenheit\nK - Kelvin\n\n");
    printf("Digite a letra da sua escolha (ou E para encerrar): ");
}

void menuConvert_msg(float temp, char temp_property) {
    // Exibe mensagem de menu para conversor
    puts("\nOpções de conversão disponíveis:\n");
    printf("[%.2fº%c] C -> Converter para Celsius\n", temp, temp_property);
    printf("[%.2fº%c] F -> Converter para Fahrenheit\n", temp, temp_property);
    printf("[%.2fº%c] K -> Converter para Kelvin\n\n", temp, temp_property);
    printf("Digite a letra da sua escolha: ");
}

// Funções de conversão

void Cfahrenheit(struct user* user_temp) {
    user_temp->temp = (user_temp->temp * 9 / 5) + 32;
}

void Ckelvin(struct user* user_temp) {
    user_temp->temp = user_temp->temp + 273.15; // Correção na lógica de conversão
}

void FCelsius(struct user * user_temp) {
    user_temp->temp = (user_temp->temp - 32) * 5 / 9;
}

void FKelvin(struct user * user_temp) {
    user_temp->temp = (user_temp->temp - 32) * 5 / 9 + 273.15;
}

void KCelsius(struct user * user_temp) {
    user_temp->temp = user_temp->temp - 273.15;
}

void Kfahrenheit(struct user * user_temp) {
    user_temp->temp = (user_temp->temp - 273.15) * 9 / 5 + 32;
}

// Função para validar a entrada de temperatura
bool is_valid_temperature(float temp, char temp_property) {

    char caracter_lower = tolower(temp_property);

    // Definindo limites mínimos e máximos para cada escala
    switch (caracter_lower) {
        case 'c':
            // Temperatura em Celsius: não pode ser menor que o zero absoluto
            return temp >= -273.15; 

        case 'f':
            // Temperatura em Fahrenheit: não pode ser menor que o zero absoluto
            return temp >= -459.67; 

        case 'k':
            // Temperatura em Kelvin: não pode ser menor que 0K
            return temp >= 0;

        default:
            // Se a propriedade de temperatura não for válida
            return false;
    }
}