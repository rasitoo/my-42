#include "ft_printf.h"
#include <stdio.h>
#include <limits.h>

#define GREEN "\033[0;32m"
#define RED   "\033[0;31m"
#define CYAN  "\033[0;36m"
#define RESET "\033[0m"

static void	check_result(int ret_ft, int ret_og)
{
	if (ret_ft == ret_og)
		printf(GREEN " [OK] " RESET "(ft: %d | og: %d)\n\n", ret_ft, ret_og);
	else
		printf(RED " [KO] " RESET "(ft: %d != og: %d)\n\n", ret_ft, ret_og);
}

int	main(void)
{
	int		r_ft;
	int		r_og;
	char	*null_str = NULL;
	void	*null_ptr = NULL;
	int		dummy = 42;

	printf(CYAN "====================================================\n" RESET);
	printf(CYAN "             TEST SUITE: FT_PRINTF                  \n" RESET);
	printf(CYAN "====================================================\n\n" RESET);

	/* ----------------- 1. TEST %c ----------------- */
	printf(CYAN "--- 1. CARACTERES (%%c) ---\n" RESET);
	printf("[ft_printf] : ");
	fflush(stdout);
	r_ft = ft_printf("Char: %c, %c, %c\n", 'A', 'z', '9');
	printf("[   printf] : ");
	r_og = printf("Char: %c, %c, %c\n", 'A', 'z', '9');
	check_result(r_ft, r_og);

	printf("[ft_printf] (char nulo '\\0'): ");
	fflush(stdout);
	r_ft = ft_printf("%c\n", '\0');
	printf("[   printf] (char nulo '\\0'): ");
	r_og = printf("%c\n", '\0');
	check_result(r_ft, r_og);

	/* ----------------- 2. TEST %s ----------------- */
	printf(CYAN "--- 2. STRINGS (%%s) ---\n" RESET);
	printf("[ft_printf] : ");
	fflush(stdout);
	r_ft = ft_printf("Hola %s! Bienvenidos a %s.\n", "Mundo", "42 Madrid");
	printf("[   printf] : ");
	r_og = printf("Hola %s! Bienvenidos a %s.\n", "Mundo", "42 Madrid");
	check_result(r_ft, r_og);

	printf("[ft_printf] (string vacio): ");
	fflush(stdout);
	r_ft = ft_printf("%s\n", "");
	printf("[   printf] (string vacio): ");
	r_og = printf("%s\n", "");
	check_result(r_ft, r_og);

	printf("[ft_printf] (string NULL): ");
	fflush(stdout);
	r_ft = ft_printf("%s\n", null_str);
	printf("[   printf] (string NULL): ");
	r_og = printf("%s\n", null_str);
	check_result(r_ft, r_og);

	/* ----------------- 3. TEST %p ----------------- */
	printf(CYAN "--- 3. PUNTEROS (%%p) ---\n" RESET);
	printf("[ft_printf] (puntero a int): ");
	fflush(stdout);
	r_ft = ft_printf("Direccion: %p\n", &dummy);
	printf("[   printf] (puntero a int): ");
	r_og = printf("Direccion: %p\n", &dummy);
	check_result(r_ft, r_og);

	printf("[ft_printf] (puntero a funcion main): ");
	fflush(stdout);
	r_ft = ft_printf("Main ptr: %p\n", main);
	printf("[   printf] (puntero a funcion main): ");
	r_og = printf("Main ptr: %p\n", main);
	check_result(r_ft, r_og);

	printf("[ft_printf] (puntero NULL): ");
	fflush(stdout);
	r_ft = ft_printf("Ptr NULL: %p\n", null_ptr);
	printf("[   printf] (puntero NULL): ");
	r_og = printf("Ptr NULL: %p\n", null_ptr);
	check_result(r_ft, r_og);

	/* ----------------- 4. TEST %d e %i ----------------- */
	printf(CYAN "--- 4. ENTEROS CON SIGNO (%%d y %%i) ---\n" RESET);
	printf("[ft_printf] : ");
	fflush(stdout);
	r_ft = ft_printf("Pos: %d | Neg: %i | Cero: %d\n", 42, -42, 0);
	printf("[   printf] : ");
	r_og = printf("Pos: %d | Neg: %i | Cero: %d\n", 42, -42, 0);
	check_result(r_ft, r_og);

	printf("[ft_printf] (INT_MAX e INT_MIN): ");
	fflush(stdout);
	r_ft = ft_printf("MAX: %d | MIN: %d\n", INT_MAX, INT_MIN);
	printf("[   printf] (INT_MAX e INT_MIN): ");
	r_og = printf("MAX: %d | MIN: %d\n", INT_MAX, INT_MIN);
	check_result(r_ft, r_og);

	/* ----------------- 5. TEST %u ----------------- */
	printf(CYAN "--- 5. ENTEROS SIN SIGNO (%%u) ---\n" RESET);
	printf("[ft_printf] : ");
	fflush(stdout);
	r_ft = ft_printf("u: %u | Cero: %u\n", 4294967295U, 0);
	printf("[   printf] : ");
	r_og = printf("u: %u | Cero: %u\n", 4294967295U, 0);
	check_result(r_ft, r_og);

	printf("[ft_printf] (valor negativo como unsigned): ");
	fflush(stdout);
	r_ft = ft_printf("u negativo: %u\n", (unsigned int)-10);
	printf("[   printf] (valor negativo como unsigned): ");
	r_og = printf("u negativo: %u\n", (unsigned int)-10);
	check_result(r_ft, r_og);

	/* ----------------- 6. TEST %x y %X ----------------- */
	printf(CYAN "--- 6. HEXADECIMAL (%%x y %%X) ---\n" RESET);
	printf("[ft_printf] : ");
	fflush(stdout);
	r_ft = ft_printf("Hex min: %x | Hex MAY: %X | Cero: %x\n", 255, 255, 0);
	printf("[   printf] : ");
	r_og = printf("Hex min: %x | Hex MAY: %X | Cero: %x\n", 255, 255, 0);
	check_result(r_ft, r_og);

	printf("[ft_printf] (UINT_MAX en hex): ");
	fflush(stdout);
	r_ft = ft_printf("Hex max: %x | %X\n", UINT_MAX, UINT_MAX);
	printf("[   printf] (UINT_MAX en hex): ");
	r_og = printf("Hex max: %x | %X\n", UINT_MAX, UINT_MAX);
	check_result(r_ft, r_og);

	/* ----------------- 7. TEST %% ----------------- */
	printf(CYAN "--- 7. PORCENTAJE (%%%%) ---\n" RESET);
	printf("[ft_printf] : ");
	fflush(stdout);
	r_ft = ft_printf("100%% efectivo | Multiple: %%%%%%\n");
	printf("[   printf] : ");
	r_og = printf("100%% efectivo | Multiple: %%%%%%\n");
	check_result(r_ft, r_og);

	/* ----------------- 8. TEST MIXTO ----------------- */
	printf(CYAN "--- 8. TEST COMBINADO (TODOS LOS TIPOS) ---\n" RESET);
	printf("[ft_printf] :\n");
	fflush(stdout);
	r_ft = ft_printf("c: %c | s: %s | p: %p | d: %d | i: %i | u: %u | x: %x | X: %X | %%\n",
		'*', "Prueba 42", &dummy, -1234, 5678, 99999U, 0xabc, 0xABC);
	printf("[   printf] :\n");
	r_og = printf("c: %c | s: %s | p: %p | d: %d | i: %i | u: %u | x: %x | X: %X | %%\n",
		'*', "Prueba 42", &dummy, -1234, 5678, 99999U, 0xabc, 0xABC);
	check_result(r_ft, r_og);

	/* ----------------- 9. EDGE CASES ESPECIALES ----------------- */
	printf(CYAN "--- 9. CASOS LIMITE DE ERROR (FORMATOS INVALIDOS) ---\n" RESET);
	
	char *null_fmt = NULL;
	r_ft = ft_printf(null_fmt);
	printf("ft_printf(NULL) -> Retorno: %d %s\n", r_ft, (r_ft == -1) ? GREEN "[OK]" RESET : RED "[KO]" RESET);

	char *orphan_fmt = "Porcentaje huerfano %";
	printf("[ft_printf] : ");
	fflush(stdout);
	r_ft = ft_printf(orphan_fmt);
	printf("\nRetorno ft_printf(\"...\") -> %d %s\n", r_ft, (r_ft == -1) ? GREEN "[OK]" RESET : RED "[KO]" RESET);

	printf(CYAN "\n====================================================\n" RESET);
	printf(CYAN "                FIN DE LAS PRUEBAS                  \n" RESET);
	printf(CYAN "====================================================\n" RESET);

	return (0);
}

