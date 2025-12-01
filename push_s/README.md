*This project has been created as part of the 42 curriculum by llafforg, osasburg.*

# Push_swap

## Summary
- [Description](#description)
- [Instructions](#instructions)
  - [Commandes de base](#commandes-de-base)
  - [Instructions de liste](#instructions-de-liste)
  - [Commandes de tri](#commandes-de-tri)
- [Algorithms](#algorithms)
  - [Parsing → Gestion des données](#parsing--gestion-des-données)
  - [Algorithme simple](#algorithme-simple)
  - [Algorithme intermédiaire : Bucket Sort](#algorithme-intermédiaire-bucket-sort)
  - [Algorithme complexe : Radix Sort](#algorithme-complexe-radix-sort)
- [Ressources](#ressources)

---

## Description
**Push_swap** est un programme qui trie un ensemble de `n` nombres entiers différents en utilisant deux **piles** (A et B) et des **opérations** contraintes (`sa`, `sb`, `ss`, `ra`, `rb`, `rr`, `rra`, `rrb`, `rrr`, `pa`, `pb`).

L'objectif est d'obtenir l'ensemble des nombres triés dans l'ordre croissant dans la **pile A**, en utilisant le moins d'opérations possible.
Ce programme de tri s'adapte au degré de désordre initial de l'ensemble selon trois échelons : *simple* (n ≤ 5), *medium* (5 < n ≤ 100), *complex* (n > 100). La stratégie de tri est **adaptative** ou **prédéfinie** par l'utilisateur. Le programme évalue la qualité du tri par le nombre total d'**opérations** employées.

---

## Instructions

### Commandes de base
1. **Compiler le programme** :
   ```bash
   make
   ```
2. **Exécuter le programme** :
   ```bash
   ./push_swap <votre liste de nombres>
   ```
   Exemple :
   ```bash
   ./push_swap 3 1 2
   ```
   Sortie :
   ```
   sa
   ```

### Instructions de liste
L'ensemble des nombres donnés en argument, contigus ou non, seront pris en compte dans leur ordre d'apparition sur la ligne de commande.
Un nombre doit être séparé par un espace. Seuls les nombres entiers sont acceptés.
La liste de nombres ne peut pas contenir de doublons.

Pour obtenir un descriptif du degré de désordre de la liste donnée, la stratégie de tri et le descriptif des opérations, utilisez l'option `--bench` :
```bash
./push_swap --bench 0 2 5 1 10 3 -5 8
```
Exemple de sortie :
```
[bench] n:              8
[bench] disorder:       39.28%
[bench] strategy:       Adaptive / O(n²)
[bench] total ops:      23
[bench] sa: 0   sb: 0   ss: 0   pa: 6   pb: 6
[bench] ra: 7   rb: 0   rr: 0   rra: 4  rrb: 0  rrr: 0
```

### Commandes de tri
Pour visualiser les opérations appliquées, redirigez la sortie vers un visualiseur (ex: [push_swap_visualizer](https://github.com/o-reo/push_swap_visualizer)) :
```bash
./push_swap 3 1 2 | ./visualizer
```

---

## Algorithms

### Parsing → Gestion des données
Les données sont récupérées depuis la ligne de commande, vérifiées (pas de doublons, entiers valides), puis stockées dans une structure de pile (`t_stack`).
Le parsing inclut :
- Vérification des arguments.
- Conversion en entiers.
- Détection des doublons.
- Calcul du degré de désordre initial.

### Algorithme simple
Pour les petites listes (`n ≤ 5`), un **tri par insertion optimisé** est utilisé :
- **Stratégie** : Trouver la position optimale pour chaque élément et appliquer les rotations minimales.
- **Complexité** : O(n²) dans le pire cas, mais très efficace pour n ≤ 5.
- **Exemple** :
  ```bash
  ./push_swap 3 1 2
  ```
  Sortie :
  ```
  sa
  ```

### Algorithme intermédiaire : Bucket Sort
Pour les listes de taille moyenne (`5 < n ≤ 100`), un **tri par buckets** est utilisé :
- **Stratégie** :
  - Diviser la pile en √n buckets en utilisant des quantiles.
  - Transférer les éléments vers la pile B par buckets.
  - Trier chaque bucket dans B (tri par insertion pour les petits buckets).
  - Remonter les éléments triés dans A.
- **Complexité** : O(n × √n) en moyenne.
- **Exemple** :
  ```bash
  ./push_swap --bench 9 1 6 2 7 3 8 4 5
  ```
  Sortie :
  ```
  [bench] strategy:       Bucket Sort / O(n√n)
  [bench] total ops:      45
  ```

### Algorithme complexe : Radix Sort
Pour les grandes listes (`n > 100`), un **Radix Sort en base 2** est utilisé :
- **Stratégie** :
  - Trier les nombres bit par bit.
  - Utiliser la pile B comme support pour séparer les éléments selon chaque bit.
  - Remonter les éléments triés dans A.
- **Complexité** : O(n × nombre_de_bits) → O(n log n) pour des entiers 32 bits.
- **Exemple** :
  ```bash
  ./push_swap --bench \$(seq 0 99 | shuf | xargs)
  ```
  Sortie :
  ```
  [bench] strategy:       Radix Sort / O(n log n)
  [bench] total ops:      700
  ```

---

## Ressources
- **Documentation** :
  - [Sujet officiel 42](https://github.com/42School/norminette/blob/master/pdf/push_swap.fr.pdf)
  - [Visualiseur Push Swap](https://github.com/o-reo/push_swap_visualizer)
- **Algorithmes** :
  - [Bucket Sort (Wikipedia)](https://en.wikipedia.org/wiki/Bucket_sort)
  - [Radix Sort (Wikipedia)](https://en.wikipedia.org/wiki/Radix_sort)
- **Outils** :
  - [Norminette](https://github.com/42School/norminette) (pour vérifier la norme 42).
  - [Valgrind](https://valgrind.org/) (pour détecter les fuites mémoire).

---
**Auteurs** : [llafforg](https://github.com/llafforg), [osasburg](https://github.com/osasburg)
