# Libft

**Libft** est une bibliothèque C recodée à partir de fonctions standard et supplémentaires, dans le cadre du projet de l'école 42. Elle inclut des fonctions de manipulation de chaînes de caractères, de listes chaînées, de gestion de mémoire, et bien plus.

---

## Table des matières
- [Description](#description)
- [Fonctions](#fonctions)
  - [Fonctions de la libc](#fonctions-de-la-libc)
  - [Fonctions supplémentaires](#fonctions-supplementaires)
- [Installation](#installation)
- [Utilisation](#utilisation)
- [Norme 42](#norme-42)
- [Auteur](#auteur)

---

## Description
Ce projet consiste à recoder certaines fonctions de la bibliothèque standard C (`libc`), ainsi que des fonctions utilitaires supplémentaires. L'objectif est de comprendre le fonctionnement de ces fonctions et de les optimiser.

---

## Fonctions

### Fonctions de la libc
| Fonction | Description |
|----------|-------------|
| `ft_isalpha` | Vérifie si un caractère est alphabétique. |
| `ft_isdigit` | Vérifie si un caractère est un chiffre. |
| `ft_isalnum` | Vérifie si un caractère est alphanumérique. |
| `ft_isascii` | Vérifie si un caractère est ASCII. |
| `ft_isprint` | Vérifie si un caractère est imprimable. |
| `ft_strlen` | Calcule la longueur d'une chaîne de caractères. |
| `ft_memset` | Remplit une zone mémoire avec un octet donné. |
| `ft_bzero` | Met à zéro une zone mémoire. |
| `ft_memcpy` | Copie une zone mémoire vers une autre. |
| `ft_memmove` | Copie une zone mémoire vers une autre (version sécurisée). |
| `ft_strlcpy` | Copie une chaîne de caractères de manière sécurisée. |
| `ft_strlcat` | Concatène deux chaînes de caractères de manière sécurisée. |
| `ft_toupper` | Convertit un caractère en majuscule. |
| `ft_tolower` | Convertit un caractère en minuscule. |
| `ft_strchr` | Recherche la première occurrence d'un caractère dans une chaîne. |
| `ft_strrchr` | Recherche la dernière occurrence d'un caractère dans une chaîne. |
| `ft_strncmp` | Compare deux chaînes de caractères sur `n` octets. |
| `ft_memchr` | Recherche un octet dans une zone mémoire. |
| `ft_memcmp` | Compare deux zones mémoire. |
| `ft_strnstr` | Recherche une sous-chaîne dans une chaîne. |
| `ft_atoi` | Convertit une chaîne en entier. |
| `ft_calloc` | Alloue et initialise une zone mémoire. |
| `ft_strdup` | Duplique une chaîne de caractères. |

### Fonctions supplémentaires
| Fonction | Description |
|----------|-------------|
| `ft_substr` | Extrait une sous-chaîne d'une chaîne. |
| `ft_strjoin` | Concatène deux chaînes de caractères. |
| `ft_strtrim` | Supprime les caractères spécifiés au début et à la fin d'une chaîne. |
| `ft_split` | Découpe une chaîne en un tableau de sous-chaînes. |
| `ft_itoa` | Convertit un entier en chaîne de caractères. |
| `ft_strmapi` | Applique une fonction à chaque caractère d'une chaîne. |
| `ft_striteri` | Applique une fonction à chaque caractère d'une chaîne avec son index. |
| `ft_putchar_fd` | Écrit un caractère sur un descripteur de fichier. |
| `ft_putstr_fd` | Écrit une chaîne sur un descripteur de fichier. |
| `ft_putendl_fd` | Écrit une chaîne suivie d'un saut de ligne sur un descripteur de fichier. |
| `ft_putnbr_fd` | Écrit un entier sur un descripteur de fichier. |

---

## Installation
1. Clonez le dépôt :
   ```bash
   git clone <URL_DU_DEPOT>
   ```
2. Compilez la bibliothèque :
   ```bash
   make
   ```
3. Incluez le fichier d'en-tête `libft.h` dans votre projet et liez la bibliothèque lors de la compilation :
   ```bash
   gcc -Wall -Wextra -Werror main.c -L. -lft -o programme
   ```

---

## Utilisation
Incluez `libft.h` dans votre code et utilisez les fonctions comme suit :
```c
#include "libft.h"

int main(void)
{
    char *str = ft_strdup("Hello, 42!");
    ft_putendl_fd(str, 1);
    free(str);
    return (0);
}
```

---

## Norme 42
Ce projet respecte la **Norme 42** :
- Pas de fuites mémoire.
- Pas de fonctions interdites (comme `printf`, `malloc` sans `free`, etc.).
- Code lisible et bien indenté.
- Fichiers `.c` et `.h` correctement organisés.

---

## Auteur
Ludovic Lafforgue
