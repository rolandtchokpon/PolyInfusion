# PolyInfusion — Code de départ du TP2

Projet console C++17 du cours LOG2400.

## Contenu fourni

- Configuration CMake et instructions de compilation.
- Choix du modèle au lancement : `compact` ou `pro`.
- Lecture et validation syntaxique des instructions de l’énoncé.
- Aide (`h`), sortie (`q`) et gestion de la fin de l’entrée.
- Emplacements `TODO` pour raccorder votre conception.

Les instructions métier affichent pour le moment « À implémenter ». Le choix du
modèle est validé, mais aucun composant de machine n’est encore créé.
Le programme ne reproduit donc pas encore les scénarios de l’énoncé.

## Travail à réaliser

Concevez et implémentez les classes et leurs collaborations selon l’énoncé :
profils d’infusion, composants des modèles, réserves et notifications.
Les règles métier (réserves initiales, seuils, pertes, sélection initiale,
validation des ressources, etc.) restent à implémenter.

Le `switch` du `main` sert uniquement à distribuer les instructions console.
Déléguez les comportements aux objets de votre conception plutôt que de les
implémenter dans cette boucle. Vous pouvez adapter ce point d’entrée.
La structure `Instruction` contient des données de saisie; ce n’est pas le patron
Commande. Aucun choix de classes métier ou de hiérarchie ne vous est imposé.

## Prérequis

- CMake 3.15 ou plus récent.
- Un compilateur C++17 : MSVC, GCC ou Clang.
- Un terminal prenant en charge UTF-8. Les fichiers sources sont encodés en UTF-8.

## Compiler et exécuter

Depuis le dossier contenant `CMakeLists.txt` :

### Windows — générateur Visual Studio

```powershell
cmake -S . -B build
cmake --build build --config Debug
.\build\Debug\PolyInfusion.exe compact
```

Pour le modèle Pro, remplacer `compact` par `pro`.
Avec un générateur à configuration unique (Ninja ou MinGW), l’exécutable se trouve
généralement dans `build` plutôt que dans `build/Debug`.

### Linux et macOS — générateur à configuration unique

```sh
cmake -S . -B build -DCMAKE_BUILD_TYPE=Debug
cmake --build build
./build/PolyInfusion compact
```

## Utilisation

Entrez `h` pour l’aide et `q` pour quitter. Une ligne vide est ignorée.
Les instructions sont en minuscules. `infuser` ne prend aucun argument.
Les quantités de remplissage doivent être strictement positives et finies;
utilisez un point pour les décimales, par exemple `remplir vert 1.5`.
`notifications désactiver` et `notifications desactiver` sont acceptées.
Les erreurs de syntaxe ne déclenchent aucune instruction métier.

## Organisation

```text
PolyInfusion/
├── CMakeLists.txt
├── README.md
├── include/
│   └── console/Console.h
└── src/
    ├── main.cpp
    └── console/Console.cpp
```

Ajoutez vos fichiers `.h` dans `include` et vos `.cpp` dans `src`, en choisissant
une organisation adaptée à votre conception. Ajoutez chaque nouveau `.cpp`
à la liste `add_executable` du fichier `CMakeLists.txt`, puis relancez
`cmake -S . -B build` et la compilation.
