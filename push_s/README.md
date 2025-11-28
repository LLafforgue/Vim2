*This project has been created as part of the 42 curriculum by llafforg, osasburg.*

# Push_swap

## Summary
- [Description](#Description)
- [Instruction](#Instruction)
    - [Commandes de base]()
    - [instructions de liste]()
    - [Commandes de tri]()
- [Algorithms](#Algorithms)
- [Ressources](#Ressources)
___

## Description
**Push_swap** est un programme qui tri un ensemble de `n` nombres entiers differents en utilisant deux **piles** (A, et B) et des **operations** contraintes (sa, sb, ss, ra, rb, rr, rra, rrb, rrr, pa et pb).\
L'objectif est d'obtenir l'ensemble des nombres tries dans l'ordre croissant dans la **pile A**.\
Ce programme de tri s'adapte au degre de desordre initial de l'ensemble selon trois echelons : *simple* ; *medium* ; *complex*. La strategie de trie est adaptative ou predefinie par l'utilisateur lors de la commande. Le programme evalue la qualite du tri par le nombre total d'**operation** employees pour trier les donnees dans la **pile A**.
___

## Instructions
### Commandes de base
1. Compilez le programme :
```bash
make
```
2. Executer le programme :
```bash
./push_swap <votre liste de nombres>
```

### instructions de liste
   L'ensemble des nombres donnes en argument, contigues ou non, seront pris en compte dans leur ordre d'apparition sur la ligne de commande.
   Un nombre doit commencer et finir par un caractere de type *space*. Seul les nombres entiers sont acceptes.\
   La liste de nombre ne peut pas contenir de double.\
   Pour obtenir un descriptif du degre de desodre de la liste donnee, la strategie de trie et le descrptif des operations, utiliser la commande `--bench`.\
   ```bash
   ./push_swap --bench 0 2 5 1 10 3 -5 8

   [bench] n:              8
   [bench] disorder:       39.28%
   [bench] strategy:       Adaptive / O(n²)
   [bench] total ops:      23
   [bench] sa: 0   sb: 0   ss: 0   pa: 6   pb: 6
   [bench] ra: 7   rb: 0   rr: 0   rra: 4  rrb: 0  rrr: 0
   ```
___

## Algorithms
 - [parsing](#parsing)
 - [algorithme simple](#algorithme_simple)
 - [algorithme intermediaire](#bucket_sort)
 - [algorithme complexe](#radix)

    ### Parsing -> gestion des donnees
    Les donnees sont recuperees depuis la commande.

## Resources
**TODO**