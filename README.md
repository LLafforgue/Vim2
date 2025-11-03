# Configuration Vim pour la Norminette (42)

Ce `.vimrc` est optimisé pour respecter les règles de la **Norminette** de l’école 42 et inclut des outils pratiques pour le développement en C.

---

## 🚀 Installation

1. **Copier le `.vimrc`** :
   ```bash
   cp chemin/vers/ce_fichier/.vimrc ~/.vimrc
   ```

2. **(Optionnel) Installer un thème de couleurs** :
   - Le thème `desert` est utilisé par défaut.
   - Pour en ajouter d’autres, placez-les dans `~/.vim/colors/`.

3. **Recharger la configuration** :
   - Ouvrez Vim et tapez :
     ```vim
     :source ~/.vimrc
     ```

4. **(Optionnel) Vérifier la Norminette** :
   - Installer la Norminette :
     ```bash
     pip install norminette
     ```
   - Vérifier un fichier :
     ```bash
     norminette mon_fichier.c
     ```

---

## ✨ Fonctionnalités principales

- ✅ **Indentation conforme Norminette**  
  - Utilise des **tabulations réelles** (`\t`) au lieu d’espaces.
  - Largeur des tabulations fixée à **4 colonnes**.

- ✅ **Limite visuelle à 80 colonnes**  
  - Affiche une barre verticale à la colonne 80.

- ✅ **Compilation rapide**  
  - Appuyez sur **F9** pour compiler et exécuter le fichier courant avec :
    ```bash
    gcc -Wall -Wextra -Werror fichier.c -o fichier && ./fichier
    ```

- ✅ **Insertion rapide d’un `main()` minimal**  
  - Tapez `:AddMain` pour insérer en haut du fichier :
    ```c
    #include <unistd.h>

    int	main(void)
    {
    	return (0);
    }
    ```

- ✅ **Autocomplétion des fonctions `ft_`**  
  - L’autocompléteur scanne les fonctions commençant par `ft_` dans le fichier courant.
  - En mode insertion, tapez le début d’une fonction puis **Ctrl+Space** pour compléter.

- ✅ **Copier-coller simplifié**  
  - **Ctrl+C** : copie la sélection dans le presse-papier système.  
  - **Ctrl+V** : colle le contenu du presse-papier (en mode normal ou insertion).

- ✅ **Affichage des espaces et tabulations**  
  - Met en évidence les tabulations (`»·`) et les espaces en fin de ligne (`·`).

---

## ⌨️ Raccourcis utiles

| Raccourci / Commande | Action |
|----------------------|--------|
| `F9`                 | Compile et exécute le fichier courant. |
| `:AddMain`           | Insère un squelette de `main()` conforme à la Norminette. |
| `Ctrl+X` ; `Ctrl+U`  | Autocomplète une fonction `ft_` (mode insertion). |
| `Ctrl+C`             | Copie la sélection dans le presse-papier système. |
| `Ctrl+V`             | Colle le contenu du presse-papier. |
| `:w`                 | Sauvegarde le fichier courant. |
| `:q`                 | Quitte Vim. |

---

## ⚙️ Personnalisation

- **Modifier le thème**  
  Éditez la ligne suivante dans le `.vimrc` :
  ```vim
  colorscheme desert
  ```

- **Adapter le squelette de `main()`**  
  Dans le `.vimrc`, trouvez la commande `:AddMain` et modifiez les includes ou le contenu selon vos besoins.

---

## 🧪 Vérification avec la Norminette

1. Installez la Norminette :
   ```bash
   pip install norminette
   ```
2. Vérifiez votre code :
   ```bash
   norminette mon_fichier.c
   ```

---

## ⚠️ Problèmes courants

- **Les couleurs ne s’affichent pas** : vérifiez que votre terminal supporte les couleurs 256 bits.
- **`F9` ne fonctionne pas** : assurez-vous que `gcc` est installé.
- **L’autocomplétion `ft_` ne trouve rien** : elle ne liste que les fonctions présentes dans le fichier courant.
