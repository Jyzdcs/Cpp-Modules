# Module 02 — Learning Guide

## Vue d'ensemble

Module 02 introduit la **Forme Canonique Orthodoxe** (_Orthodox Canonical Form_) et les nombres à virgule fixe (_fixed-point_). Tu vas apprendre à gérer correctement la copie d'objets, à surcharger les opérateurs, et à comprendre comment les classes doivent être conçues pour être sûres et prévisibles dans leurs opérations de copie et d'affectation.

**Objectif central :** Maîtriser la **Rule of Three** (constructeur par copie, opérateur d'affectation, destructeur) et comprendre comment manipuler des types numériques personnalisés avec surcharge d'opérateurs.

---

## Notions fondamentales du module

### 1. Orthodox Canonical Form (OCF)

**Résumé :** Toute classe qui gère des ressources (ou pour uniformité) doit définir quatre membres : constructeur par défaut, constructeur de copie, opérateur d'affectation, et destructeur.

**Principe OOP :** **Encapsulation de la sémantique de copie** — contrôler comment les objets sont copiés/affectés garantit l'invariance et évite les bugs subtils.

**Mapping C++98 :**

```cpp
class Fixed {
private:
    int _value;

public:
    Fixed();                              // Constructeur par défaut
    Fixed(Fixed const& src);              // Constructeur de copie
    Fixed& operator=(Fixed const& rhs);   // Opérateur d'affectation
    ~Fixed();                             // Destructeur
};
```

**Implémentation typique :**

- **Constructeur par défaut :** Initialise les membres à des valeurs sûres
- **Constructeur de copie :** Copie profonde (_deep copy_) des membres depuis `src`
- **Opérateur d'affectation :**
  1. Vérifier l'auto-affectation (`if (this != &rhs)`)
  2. Libérer les ressources existantes si nécessaire
  3. Copier les membres depuis `rhs`
  4. Retourner `*this`
- **Destructeur :** Libérer les ressources allouées

**Pièges courants :**

- Oublier la vérification d'auto-affectation dans `operator=` (peut causer corruption mémoire)
- Ne pas retourner `*this` dans `operator=` (empêche chaînage)
- Copie superficielle (_shallow copy_) au lieu de copie profonde pour ressources dynamiques
- Définir un membre sans définir les autres (incohérence)

**Glossaire :**

- **Orthodox Canonical Form (OCF)**: Forme standard des classes C++ avec les 4 membres essentiels
- **Rule of Three**: Si tu définis un destructeur, un constructeur de copie OU un opérateur d'affectation, tu dois définir les trois
- **Deep copy**: Copie complète incluant les ressources pointées
- **Shallow copy**: Copie uniquement les pointeurs, pas les ressources
- **Self-assignment**: Auto-affectation (`a = a`)

---

### 2. Fixed-Point Arithmetic

**Résumé :** Représenter des nombres décimaux en utilisant des entiers avec un nombre fixe de bits fractionnaires. Alternative aux `float`/`double` pour contrôle précis et performances prévisibles.

**Principe OOP :** **Abstraction** — cacher la représentation interne (entier) derrière une interface qui se comporte comme un nombre décimal.

**Mapping C++98 :**

```cpp
class Fixed {
private:
    int                 _rawBits;        // Stockage brut (int)
    static const int    _fractionalBits = 8;  // Nombre de bits fractionnaires

public:
    Fixed(int const n);      // Convertit int -> fixed-point
    Fixed(float const f);    // Convertit float -> fixed-point
    float toFloat() const;   // Convertit fixed-point -> float
    int toInt() const;       // Convertit fixed-point -> int
};
```

**Formules de conversion (8 bits fractionnaires) :**

- **Int → Fixed :** `_rawBits = value << 8` (décalage de 8 bits à gauche)
- **Float → Fixed :** `_rawBits = roundf(value * 256)` (256 = 2^8)
- **Fixed → Float :** `return _rawBits / 256.0f`
- **Fixed → Int :** `return _rawBits >> 8` (décalage de 8 bits à droite)

**Opérations arithmétiques :**

- **Addition/Soustraction :** Opérer directement sur `_rawBits`
  - `result._rawBits = a._rawBits + b._rawBits`
- **Multiplication :** Décaler après
  - `result._rawBits = (a._rawBits * b._rawBits) >> 8`
- **Division :** Décaler avant
  - `result._rawBits = (a._rawBits << 8) / b._rawBits`

**Pièges courants :**

- Oublier `roundf()` lors de la conversion float → fixed (perte de précision)
- Ne pas décaler lors de multiplication/division (résultats incorrects)
- Overflow/underflow non géré
- Confusion entre valeur brute et valeur réelle

**Glossaire :**

- **Fixed-point**: Représentation de nombres décimaux avec position de virgule fixe
- **Fractional bits**: Nombre de bits dédiés à la partie décimale
- **Raw bits**: Valeur entière brute représentant le nombre fixed-point
- **Shift operator**: `<<` (gauche) et `>>` (droite) pour décalage de bits
- **roundf()**: Fonction d'arrondi pour conversions float

---

### 3. Operator Overloading

**Résumé :** Redéfinir le comportement des opérateurs (`+`, `-`, `*`, `/`, `<<`, `==`, etc.) pour les types personnalisés.

**Principe OOP :** **Abstraction** — permettre à tes classes de se comporter comme des types natifs, rendant le code plus intuitif.

**Mapping C++98 :**

**Opérateurs arithmétiques (retournent nouvel objet) :**

```cpp
Fixed operator+(Fixed const& rhs) const {
    Fixed result;
    result._rawBits = this->_rawBits + rhs._rawBits;
    return result;
}
```

**Opérateurs de comparaison (retournent bool) :**

```cpp
bool operator>(Fixed const& rhs) const {
    return this->_rawBits > rhs._rawBits;
}
```

**Opérateurs d'incrémentation :**

```cpp
// Pré-incrémentation : ++a (retourne référence)
Fixed& operator++() {
    ++this->_rawBits;
    return *this;
}

// Post-incrémentation : a++ (retourne copie)
Fixed operator++(int) {
    Fixed old = *this;
    ++this->_rawBits;
    return old;
}
```

**Opérateur d'insertion de flux :**

```cpp
std::ostream& operator<<(std::ostream& os, Fixed const& fx) {
    os << fx.toFloat();
    return os;
}
```

**Règles importantes :**

- Opérateurs membres vs. non-membres : `operator<<` doit être non-membre
- Opérateurs de comparaison marqués `const` (ne modifient pas l'objet)
- Pré-incrémentation retourne référence, post-incrémentation retourne copie
- Opérateur `int` dans signature post-incrémentation est un marqueur (valeur ignorée)

**Pièges courants :**

- Oublier `const` sur opérateurs de comparaison
- Faire `operator<<` membre (le flux doit être à gauche)
- Ne pas retourner référence pour chaînage (`os << a << b`)
- Confondre pré/post incrémentation signatures

**Glossaire :**

- **Operator overloading**: Redéfinition du comportement des opérateurs pour types personnalisés
- **Member operator**: Opérateur défini comme méthode de la classe
- **Non-member operator**: Opérateur défini en dehors de la classe (souvent `friend`)
- **Pre-increment**: `++a` modifie puis retourne
- **Post-increment**: `a++` retourne puis modifie
- **Stream insertion operator**: `operator<<` pour affichage

---

## Notions par exercice

### ex00 — My First Class in Orthodox Canonical Form

**Ce que tu dois comprendre :**

#### OCF minimal

- Comment implémenter les **4 membres canoniques** même quand la classe est simple
- Différence entre constructeur par défaut et constructeur de copie
- Quand et comment l'opérateur d'affectation est appelé (`Fixed b = a;` vs `b = a;`)

#### Messages de debug

- Afficher des messages dans chaque constructeur/destructeur pour **tracer le cycle de vie**
- Comprendre l'ordre d'appel (construction, copie, affectation, destruction)
- Observer que les copies sont fréquentes (paramètres, retours)

#### Accesseurs raw bits

- `getRawBits()` et `setRawBits()` : accès direct à la représentation interne
- Marquer `getRawBits()` comme `const` (méthode de lecture)
- Logger les appels pour voir quand les données sont accédées

**Ce que l'exercice démontre :**

Le coût des copies en C++ et l'importance de bien comprendre la sémantique de copie. Chaque passage par valeur, chaque retour crée une copie.

**Sortie attendue (similaire à) :**

```
Default constructor called
Copy constructor called
Assignation operator called
getRawBits member function called
Default constructor called
Assignation operator called
getRawBits member function called
getRawBits member function called
0
getRawBits member function called
0
getRawBits member function called
0
Destructor called
Destructor called
Destructor called
```

---

### ex01 — Towards a more useful fixed-point number class

**Ce que tu dois comprendre :**

#### Constructeurs de conversion

- **Constructeur `int`** : Convertir entier en fixed-point (`value << 8`)
- **Constructeur `float`** : Convertir flottant en fixed-point avec `roundf(value * 256)`
- Ces constructeurs permettent d'initialiser directement : `Fixed a(42);` ou `Fixed b(42.42f);`

#### Méthodes de conversion

- **`toFloat()`** : Extraire la valeur flottante (`_rawBits / 256.0f`)
- **`toInt()`** : Extraire la partie entière (`_rawBits >> 8`)
- Marquer ces méthodes `const`

#### Surcharge `operator<<`

- Permettre l'affichage avec `std::cout << fixed;`
- **Fonction non-membre** prenant `std::ostream&` et `Fixed const&`
- Retourner le flux pour chaînage
- Appeler `toFloat()` pour afficher la valeur décimale

**Mathématiques fixed-point :**

- Comprendre pourquoi on décale de 8 bits (2^8 = 256)
- Avec 8 bits fractionnaires, la précision minimale est 1/256 ≈ 0.00390625

**Ce que l'exercice démontre :**

Comment créer un type qui se comporte comme un nombre, avec conversions automatiques depuis/vers types natifs.

**Sortie attendue (similaire à) :**

```
Default constructor called
Int constructor called
Float constructor called
Copy constructor called
Assignation operator called
Float constructor called
Assignation operator called
Destructor called
a is 1234.43
b is 10
c is 42.4219
d is 10
a is 1234 as integer
b is 10 as integer
c is 42 as integer
d is 10 as integer
Destructor called
Destructor called
Destructor called
```

---

### ex02 — Now we're talking

**Ce que tu dois comprendre :**

#### Opérateurs de comparaison (6 opérateurs)

- `>`, `<`, `>=`, `<=`, `==`, `!=`
- Comparer directement les `_rawBits` (plus simple et correct)
- Tous marqués `const`
- Retournent `bool`

#### Opérateurs arithmétiques (4 opérateurs)

- **Addition** : `a._rawBits + b._rawBits`
- **Soustraction** : `a._rawBits - b._rawBits`
- **Multiplication** : `(a._rawBits * b._rawBits) >> 8` ⚠️ décalage nécessaire
- **Division** : `(a._rawBits << 8) / b._rawBits` ⚠️ décalage nécessaire
- Tous retournent un nouvel objet `Fixed`

#### Incrémentation/Décrémentation (4 opérateurs)

- **Pré-incrémentation `++a`** :
  - Incrémenter `_rawBits` de 1 (plus petite valeur représentable)
  - Retourner `*this` (référence)
- **Post-incrémentation `a++`** :
  - Sauvegarder copie de l'objet actuel
  - Incrémenter `_rawBits`
  - Retourner la copie (valeur avant incrémentation)
- Idem pour `--a` et `a--`

**Pourquoi incrémenter de 1 et pas 256 ?**

- `_rawBits` représente `value * 256`
- Incrémenter de 1 représente `1/256` en valeur réelle
- C'est la plus petite unité représentable (epsilon)

#### Méthodes statiques min/max

- `static Fixed& min(Fixed& a, Fixed& b);`
- `static const Fixed& min(Fixed const& a, Fixed const& b);`
- Idem pour `max`
- Retourner référence (pas copie) pour efficacité
- Versions `const` et non-`const` pour différents contextes

**Ce que l'exercice démontre :**

Une classe qui se comporte exactement comme un type numérique natif, avec toutes les opérations attendues.

**Sortie attendue (similaire à) :**

```
0
0.00390625
0.00390625
0.0078125
10.1016
10.1016
```

**Explication du main :**

- `0` : valeur initiale de `a`
- `0.00390625` : `a` après `++a` (1/256)
- `0.00390625` : valeur retournée par `a++` (valeur avant incrémentation)
- `0.0078125` : valeur de `a` après `a++` (2/256)
- `10.1016` : valeur de `b`
- `10.1016` : max entre `a` et `b`

---

### ex03 — BSP (Binary Space Partitioning)

**Ce que tu dois comprendre :**

#### Classe Point avec membres const

```cpp
class Point {
private:
    Fixed const _x;
    Fixed const _y;

public:
    Point();                                    // (0,0)
    Point(float const x, float const y);        // Coordonnées
    Point(Point const& src);                    // Copie
    Point& operator=(Point const& rhs);         // Affectation
    ~Point();
};
```

**Membres `const` :**

- Doivent être initialisés dans **initializer list**
- Ne peuvent **jamais être modifiés** après construction
- `operator=` ne peut pas vraiment affecter les membres (déjà initialisés) mais doit exister pour OCF
- Représente l'immutabilité : un point ne change pas de position

#### Algorithme BSP (point dans triangle)

**Objectif :** Déterminer si un point P est **strictement à l'intérieur** d'un triangle ABC.

**Approche recommandée : Aires signées (barycentric method)**

Un point P est dans le triangle ABC si et seulement si :

- `sign(aire(P, A, B)) == sign(aire(P, B, C)) == sign(aire(P, C, A))`

**Formule aire signée :**

```
aire(P, Q, R) = ((Q.x - P.x) * (R.y - P.y) - (R.x - P.x) * (Q.y - P.y)) / 2
```

(Le `/2` peut être omis car on compare seulement les signes)

**Cas particuliers (doivent retourner `false`) :**

- Point **sur un sommet** (coïncide avec A, B ou C)
- Point **sur une arête** (aire d'un sous-triangle = 0)
- Point **à l'extérieur**

**Implémentation :**

```cpp
bool bsp(Point const a, Point const b, Point const c, Point const point);
```

- Calculer les trois aires signées
- Vérifier qu'aucune n'est nulle (éliminer arêtes/sommets)
- Vérifier que les trois ont le même signe

**Ce que l'exercice démontre :**

- Utilisation de `const` pour exprimer l'immutabilité
- Application pratique de fixed-point pour calculs géométriques
- Opérateurs surchargés permettent d'écrire formules naturellement

---

## Pièges communs du Module 02

1. **Auto-affectation non gérée** — Toujours vérifier `if (this != &rhs)` dans `operator=`
2. **Ne pas retourner `*this`** — L'opérateur d'affectation doit retourner référence
3. **Oublier `const` sur opérateurs de comparaison** — Ils ne doivent pas modifier l'objet
4. **Mauvais décalages dans arithmétique fixed-point** — Décaler après multiplication, avant division
5. **Confondre pré/post incrémentation** — Signatures et sémantiques différentes
6. **`operator<<` en méthode membre** — Doit être fonction non-membre
7. **Ne pas gérer les cas limites BSP** — Points sur arêtes/sommets doivent retourner `false`
8. **Membres `const` non initialisés dans initializer list** — Erreur de compilation
9. **Oublier `roundf()` dans conversion float** — Perte de précision
10. **Ne pas définir version `const` des méthodes statiques** — `min`/`max` nécessitent deux versions

---

## Ordre typique d'appel des constructeurs/opérateurs

### Déclaration et initialisation

```cpp
Fixed a;                    // Default constructor
Fixed b(10);                // Int constructor
Fixed c(42.42f);            // Float constructor
Fixed d(b);                 // Copy constructor
Fixed e = c;                // Copy constructor (pas operator= !)
```

### Affectation

```cpp
a = b;                      // operator= (a existe déjà)
```

### Passage/retour par valeur

```cpp
void func(Fixed f) { }      // Copy constructor lors de l'appel
Fixed getFixed() {
    Fixed tmp(5);
    return tmp;             // Copy constructor lors du retour (peut être optimisé)
}
```

### Destruction

```cpp
{
    Fixed tmp;
}                           // Destructor appelé en sortant du scope
```

---

## Checklist avant soumission Module 02

**Compilation :**

- [ ] Compile avec `c++ -Wall -Wextra -Werror -std=c++98`
- [ ] Pas d'erreurs, pas de warnings

**OCF (tous les exercices) :**

- [ ] Les 4 membres canoniques sont définis
- [ ] Constructeur de copie fait une copie profonde si nécessaire
- [ ] `operator=` vérifie l'auto-affectation
- [ ] `operator=` retourne `*this`
- [ ] Destructeur libère les ressources

**ex00 :**

- [ ] Messages de debug affichés pour chaque constructeur/destructeur
- [ ] `getRawBits()` et `setRawBits()` fonctionnent
- [ ] Sortie correspond à l'attendu

**ex01 :**

- [ ] Constructeurs `int` et `float` convertissent correctement
- [ ] `toFloat()` et `toInt()` retournent valeurs correctes
- [ ] `operator<<` affiche la valeur en flottant
- [ ] Valeurs affichées correspondent (ex: 42.4219)

**ex02 :**

- [ ] Les 6 opérateurs de comparaison fonctionnent
- [ ] Les 4 opérateurs arithmétiques donnent résultats corrects
- [ ] Pré/post incrémentation ont sémantiques correctes
- [ ] `min` et `max` existent en versions `const` et non-`const`
- [ ] Sortie correspond au main fourni

**ex03 :**

- [ ] `Point` avec membres `const` compile
- [ ] OCF de Point respecté (même si `operator=` ne fait rien)
- [ ] `bsp` retourne `true` pour points strictement intérieurs
- [ ] `bsp` retourne `false` pour sommets, arêtes, et extérieur
- [ ] Tests exhaustifs vérifient tous les cas

**Général :**

- [ ] Pas de `using namespace std;`
- [ ] Headers avec include guards
- [ ] Implémentations dans `.cpp`, pas dans headers
- [ ] Makefiles corrects (compilation, clean, fclean, re)

---

## Glossaire anglais — Module 02

**Forme canonique :**

- **Orthodox Canonical Form (OCF)**: Forme standard d'une classe C++ avec les 4 membres essentiels
- **Rule of Three**: Règle stipulant que si on définit un destructeur, copy constructor, ou copy assignment, on doit définir les trois
- **Default constructor**: Constructeur sans paramètres
- **Copy constructor**: Constructeur prenant référence constante à un objet du même type
- **Copy assignment operator**: `operator=` pour copier un objet existant
- **Destructor**: Fonction de nettoyage appelée lors de la destruction

**Copie :**

- **Deep copy**: Copie complète incluant toutes les ressources allouées
- **Shallow copy**: Copie superficielle (pointeurs copiés, pas les ressources)
- **Self-assignment**: Auto-affectation (`a = a`)

**Fixed-point :**

- **Fixed-point arithmetic**: Arithmétique à virgule fixe
- **Fractional bits**: Bits dédiés à la partie fractionnaire
- **Raw bits**: Représentation interne entière
- **Bit shift**: Décalage de bits (`<<` gauche, `>>` droite)
- **roundf()**: Fonction d'arrondi pour float

**Opérateurs :**

- **Operator overloading**: Surcharge d'opérateurs
- **Member operator**: Opérateur défini comme méthode
- **Non-member operator**: Opérateur défini hors de la classe
- **Pre-increment**: `++a` (incrémenter puis retourner)
- **Post-increment**: `a++` (retourner puis incrémenter)
- **Comparison operator**: Opérateur de comparaison (`>`, `<`, etc.)
- **Arithmetic operator**: Opérateur arithmétique (`+`, `-`, `*`, `/`)
- **Stream insertion operator**: `operator<<` pour flux de sortie

**Géométrie (ex03) :**

- **BSP (Binary Space Partitioning)**: Partitionnement binaire de l'espace
- **Barycentric coordinates**: Coordonnées barycentriques
- **Signed area**: Aire signée d'un triangle
- **Collinear**: Points alignés
- **Strictly inside**: Strictement à l'intérieur (pas sur bord)

**Divers :**

- **const member**: Membre constant (ne peut être modifié)
- **Initializer list**: Liste d'initialisation des membres
- **Static method**: Méthode de classe (pas d'instance)
- **Reference return**: Retour par référence
- **epsilon**: Plus petite valeur représentable

---

## Prochaines étapes

Après Module 02, tu seras prêt pour :

- **Module 03** : Héritage et polymorphisme
- **Module 04** : Classes abstraites et interfaces
- **Module 05** : Exceptions et casts
- Comprendre l'importance de la **Rule of Five** en C++11+ (move semantics)
- Explorer les **smart pointers** (même si indisponibles en C++98)
