# ex01 — Notes Essentielles (20%)

## 📑 Table des Matières

- [🎯 Objectif de l'exercice](#-objectif-de-lexercice)
- [🔢 C'est quoi un Fixed-Point ?](#-cest-quoi-un-fixed-point-)
- [🔄 Les 4 Conversions Essentielles](#-les-4-conversions-essentielles)
- [🎨 Décalage vs Multiplication : Équivalence](#-décalage-vs-multiplication--équivalence)
- [💬 Surcharge d'opérateur : `operator<<`](#-surcharge-dopérateur--operator)
- [🔓 Le déclic : Le mot-clé `operator`](#-le-déclic--le-mot-clé-operator)
- [⚠️ Réflexion critique : Quand (ne pas) surcharger](#️-réflexion-critique--quand-ne-pas-surcharger)
- [📊 Tableau de valeurs (exemples)](#-tableau-de-valeurs-exemples)
- [🧪 Sortie attendue (main fourni)](#-sortie-attendue-main-fourni)
- [🔑 Concepts Clés](#-concepts-clés)
- [📝 Checklist Complète](#-checklist-complète)
- [💡 Pièges Courants](#-pièges-courants)
- [🧮 Mini-exercices de compréhension](#-mini-exercices-de-compréhension)
- [🚀 Pour la suite (ex02)](#-pour-la-suite-ex02)
- [🎓 Récap Final (en 30 secondes)](#-récap-final-en-30-secondes)

---

## 🎯 Objectif de l'exercice

**Comprendre les nombres à virgule fixe (fixed-point) et créer un type numérique utile avec conversions et affichage.**

Ce n'est plus juste de l'OCF — c'est maintenant un **vrai type numérique** qui peut :

1. Être créé depuis `int` et `float`
2. Être converti vers `int` et `float`
3. S'afficher naturellement avec `std::cout`

---

## 🔢 C'est quoi un Fixed-Point ?

### L'idée géniale en une phrase

**On stocke un nombre décimal dans un `int`, en multipliant tout par 256.**

### Pourquoi faire ça ?

| Type            | Avantages              | Inconvénients            |
| --------------- | ---------------------- | ------------------------ |
| `float`         | Grandes plages, facile | Imprécis, lent, complexe |
| `int`           | Rapide, précis         | Pas de décimales ❌      |
| **Fixed-point** | Rapide + décimales ✅  | Plage limitée            |

### Exemple concret : stocker 42.75

```
Nombre réel : 42.75
Calcul      : 42.75 × 256 = 10944
Stockage    : _fixedPoint = 10944 (un simple int !)

Pour récupérer :
10944 ÷ 256 = 42.75 ✅
```

**Pourquoi 256 ?** Parce qu'on utilise **8 bits fractionnaires**, et 2^8 = 256.

### Visualisation des bits

```
┌─────────────────────────┬──────────┐
│   24 bits (entier)       │  8 bits (fraction) │
│   42                     │  0.75 (192/256)    │
└─────────────────────────┴──────────┘
         10752                 +192 = 10944
```

---

## 🔄 Les 4 Conversions Essentielles

### Tableau récapitulatif

| De → Vers       | Formule                | Opérateur      | Pourquoi                         |
| --------------- | ---------------------- | -------------- | -------------------------------- |
| `int` → Fixed   | `value << 8`           | Décalage       | Multiplier par 256               |
| `float` → Fixed | `roundf(value * 256)`  | Multiplication | Float ne supporte pas `<<`       |
| Fixed → `int`   | `_fixedPoint >> 8`     | Décalage       | Diviser par 256 (partie entière) |
| Fixed → `float` | `_fixedPoint / 256.0f` | Division       | Obtenir valeur décimale          |

### 1. Constructeur depuis `int`

```cpp
Fixed::Fixed(int const value) : _fixedPoint(value << 8) {}
```

**Exemple :**

```
int = 42
42 << 8 = 10752
_fixedPoint = 10752
```

**Question :** Pourquoi `<< 8` et pas `* 256` ?

- **Réponse :** Les deux sont équivalents pour les entiers !
- `<< 8` est plus idiomatique (montre que c'est du bit manipulation)
- `<< n` = multiplier par 2^n

### 2. Constructeur depuis `float`

```cpp
Fixed::Fixed(float const value) : _fixedPoint(roundf(value * 256)) {}
```

**Exemple :**

```
float = 42.75
42.75 × 256 = 10944.0
roundf(10944.0) = 10944
_fixedPoint = 10944
```

**⚠️ ATTENTION :** On **DOIT** utiliser `* 256`, car les floats ne supportent **PAS** l'opérateur `<<` (bitwise operations uniquement sur entiers).

**Pourquoi `roundf()` ?**

- Sans arrondi : `42.75 × 256 = 10944.0` → casting en `int` = 10944 ✅
- Avec valeurs négatives ou imprécisions : `roundf()` garantit l'arrondi correct
- Requis par le sujet : `#include <cmath>`

### 3. Convertir vers `int`

```cpp
int Fixed::toInt() const {
    return _fixedPoint >> 8;
}
```

**Exemple :**

```
_fixedPoint = 10944
10944 >> 8 = 42
Retourne : 42 (partie entière uniquement)
```

**Ce qu'on perd :** La partie décimale (0.75 disparaît)

### 4. Convertir vers `float`

```cpp
float Fixed::toFloat() const {
    return _fixedPoint / 256.0f;
}
```

**Exemple :**

```
_fixedPoint = 10944
10944 / 256.0f = 42.75
Retourne : 42.75 ✅
```

**⚠️ IMPORTANT :** Utiliser `256.0f` (float) et pas `256` (int) pour forcer division flottante !

---

## 🎨 Décalage vs Multiplication : Équivalence

### Pour les entiers : IDENTIQUE ✅

```cpp
int value = 42;

int raw1 = value << 8;   // Décalage de 8 bits à gauche
int raw2 = value * 256;  // Multiplication par 256

// raw1 == raw2 (tous deux = 10752)
```

**Pourquoi ?** Décaler de `n` bits à gauche = multiplier par 2^n

### Visualisation binaire

```
42 en binaire :    00000000 00000000 00000000 00101010
42 << 8 :          00000000 00000000 00101010 00000000
                                      ↑ 8 zéros ajoutés
Résultat = 10752
```

### Pour les floats : OBLIGATION de multiplier ❌

```cpp
float value = 42.75f;

// ❌ ERREUR : value << 8;  // Impossible ! Erreur de compilation
// ✅ CORRECT : roundf(value * 256);
```

**Pourquoi ?** Les opérateurs bitwise (`<<`, `>>`, `&`, `|`) fonctionnent **uniquement sur les types entiers**. Les `float` ont une représentation IEEE 754 complètement différente.

---

## 💬 Surcharge d'opérateur : `operator<<`

### Le problème initial

```cpp
Fixed a(42.42f);

std::cout << a;           // ❌ Erreur : type inconnu
std::cout << a.toFloat(); // ✅ Marche mais lourd et pas intuitif
```

### La solution : surcharger `operator<<`

**Instruction du sujet :**

> "An overload of the insertion («) operator that inserts a floating-point representation of the fixed-point number into the output stream object."

**Traduction :** On définit comment afficher notre objet `Fixed` dans un flux de sortie.

### Implémentation

#### Dans `Fixed.hpp` (HORS de la classe) :

```cpp
std::ostream& operator<<(std::ostream& os, Fixed const& fixed);
```

#### Dans `Fixed.cpp` :

```cpp
std::ostream& operator<<(std::ostream& os, Fixed const& fixed) {
    os << fixed.toFloat();  // Insère la valeur float dans le flux
    return os;              // Retourne le flux pour chaînage
}
```

### Résultat magique ✨

```cpp
Fixed a(42.42f);
std::cout << a;  // Affiche : 42.4219 (affichage naturel !)
```

### Décortiquons la signature

```cpp
std::ostream& operator<<(std::ostream& os, Fixed const& fixed)
│             │          │                │
│             │          │                └─ Notre objet Fixed
│             │          └─ Le flux (std::cout, fichier, etc.)
│             └─ L'opérateur qu'on redéfinit
└─ Type de retour (référence au flux)
```

**Pourquoi fonction non-membre ?**

Si c'était une méthode de `Fixed`, on devrait écrire :

```cpp
a.operator<<(std::cout);  // 🤮 Syntaxe horrible
a << std::cout;           // 🤮 À l'envers !
```

En fonction libre :

```cpp
std::cout << a;  // ✅ Naturel et lisible
```

**Pourquoi retourner `std::ostream&` ?**

Pour permettre le **chaînage** :

```cpp
std::cout << "Value: " << a << " is " << b << std::endl;
//         └─ retourne cout ─┘  └─ retourne cout ─┘
```

---

## 🔓 Le déclic : Le mot-clé `operator`

### La révélation

**On peut redéfinir le comportement des opérateurs (`+`, `-`, `<<`, `==`, etc.) pour nos propres classes avec le mot-clé `operator` !**

```cpp
class Fixed {
public:
    // Ces deux lignes sont équivalentes :
    Fixed add(Fixed const& other);      // Méthode normale
    Fixed operator+(Fixed const& other); // Surcharge d'opérateur
};

// Utilisation :
Fixed c = a.add(b);  // Appel de méthode
Fixed c = a + b;     // Opérateur surchargé ✨
```

### Ce qui devient possible

```cpp
Fixed a(10.5f);
Fixed b(2.0f);

// Tout ça peut fonctionner avec des surcharges :
Fixed c = a + b;       // Addition
Fixed d = a * b;       // Multiplication
bool test = a > b;     // Comparaison
++a;                   // Incrémentation
std::cout << a;        // Affichage
```

**C'est comme si tes types personnalisés devenaient des citoyens de première classe du langage !**

---

## ⚠️ Réflexion critique : Quand (ne pas) surcharger

### ✅ Surcharge LÉGITIME

Pour des **types numériques** ou **valeurs mathématiques** :

```cpp
Fixed a(10), b(5);
Fixed c = a + b;       // ✅ Évident : addition mathématique

Vector v1(1,2,3), v2(4,5,6);
Vector v3 = v1 + v2;   // ✅ Évident : addition vectorielle

std::string s = "Hello" + " World";  // ✅ Évident : concaténation
```

### ❌ Surcharge PROBLÉMATIQUE

Pour des **objets complexes** ou **opérations ambiguës** :

```cpp
User u1("Alice"), u2("Bob");
User u3 = u1 + u2;     // ❌ WTF ?! Additionner des utilisateurs ?

Database db1, db2;
db1 - db2;             // ❌ Soustraire des bases de données ?!

Document doc;
doc++;                 // ❌ Incrémenter un document ?!
```

### Le problème de modularité

**Avec surcharge :**

```cpp
Fixed result = a / b;  // Qu'est-ce qui se passe ? Division simple ? Arrondi ?
```

**Sans surcharge (plus explicite) :**

```cpp
Fixed result = a.divide(b);              // Clair
Fixed result = a.divideWithRounding(b);  // Très clair
Fixed result = a.safeDivide(b);          // Ultra clair (vérifie division par 0)
```

**Trade-off :** Concision vs Clarté/Flexibilité

### Règle d'or

**Utilise la surcharge d'opérateurs SEULEMENT si :**

1. Le comportement est **universellement évident**
2. Tu respectes les **propriétés mathématiques** attendues
3. Le type représente une **valeur**, pas un **objet métier**

---

## 📊 Tableau de valeurs (exemples)

| Valeur réelle | `_fixedPoint` (raw) | Conversion               |
| ------------- | ------------------- | ------------------------ |
| `0`           | `0`                 | `0 × 256 = 0`            |
| `1`           | `256`               | `1 × 256 = 256`          |
| `0.5`         | `128`               | `0.5 × 256 = 128`        |
| `10`          | `2560`              | `10 × 256 = 2560`        |
| `42.42`       | `10860`             | `42.42 × 256 ≈ 10860`    |
| `42.75`       | `10944`             | `42.75 × 256 = 10944`    |
| `1234.43`     | `316014`            | `1234.43 × 256 ≈ 316014` |

**Précision minimale :** 1 raw bit = 1/256 ≈ 0.00390625

---

## 🧪 Sortie attendue (main fourni)

```
Default constructor called
Int constructor called
Float constructor called
Copy constructor called
Copy assignment operator called
Float constructor called
Copy assignment operator called
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
Destructor called
```

### Analyse ligne par ligne

```cpp
Fixed a;                    // Default constructor called
Fixed const b(10);          // Int constructor called
Fixed const c(42.42f);      // Float constructor called
Fixed const d(b);           // Copy constructor called
a = Fixed(1234.4321f);      // Float constructor + Copy assignment + Destructor
                            // (temporaire créé puis détruit)

std::cout << "a is " << a;  // Appelle operator<<, qui appelle toFloat()
// Affiche : a is 1234.43 (arrondi d'affichage)

std::cout << "a is " << a.toInt();
// Affiche : a is 1234 (partie entière uniquement)
```

**Note :** `42.42f` devient `42.4219` à cause de la précision du fixed-point (8 bits fractionnaires = 256 niveaux).

---

## 🔑 Concepts Clés

### `static_cast<float>` vs division par `256.0f`

```cpp
// Méthode 1 : Cast puis division
float toFloat() const {
    return static_cast<float>(_fixedPoint) / 256.0f;
}

// Méthode 2 : Division flottante directe
float toFloat() const {
    return _fixedPoint / 256.0f;  // Le 256.0f force la conversion
}
```

**Les deux sont valides**, mais la 2ème est plus simple. Le `f` dans `256.0f` force la division en `float`.

### Opérateurs membres vs non-membres

| Opérateur    | Type             | Pourquoi                   |
| ------------ | ---------------- | -------------------------- |
| `operator=`  | Membre           | Doit accéder à `this`      |
| `operator+`  | Membre (souvent) | Peut être membre           |
| `operator<<` | **Non-membre**   | Le flux doit être à gauche |
| `operator>>` | **Non-membre**   | Le flux doit être à gauche |

**Règle :** Si l'opérande de gauche est un objet externe (comme `std::ostream`), l'opérateur **doit** être non-membre.

### `const` correctness

```cpp
int toInt() const;    // ✅ Marque la méthode comme "lecture seule"
float toFloat() const; // ✅ Permet d'être appelée sur objets const

Fixed const c(42.42f);
std::cout << c.toFloat();  // ✅ Marche grâce à 'const'
```

Sans `const`, les méthodes ne pourraient **pas** être appelées sur des objets `const` !

---

## 📝 Checklist Complète

**Implémentation :**

- [ ] Constructeur `Fixed(int)` utilise `<< 8`
- [ ] Constructeur `Fixed(float)` utilise `roundf(value * 256)`
- [ ] `toInt()` utilise `>> 8`
- [ ] `toFloat()` utilise `/ 256.0f`
- [ ] `operator<<` déclaré **en dehors** de la classe
- [ ] `operator<<` retourne `std::ostream&`
- [ ] `operator<<` appelle `toFloat()`
- [ ] `#include <cmath>` pour `roundf()`
- [ ] Méthodes de conversion marquées `const`

**Compilation :**

- [ ] Compile sans warnings avec `-Wall -Wextra -Werror -std=c++98`
- [ ] Le main fourni produit la sortie attendue
- [ ] Les valeurs affichées sont correctes (ex: 42.4219)

**Compréhension :**

- [ ] Tu comprends **pourquoi** on multiplie/divise par 256
- [ ] Tu sais **quand** utiliser `<<` vs `*` (entiers vs floats)
- [ ] Tu comprends le rôle de `operator<<` (affichage naturel)
- [ ] Tu réalises que le mot-clé `operator` redéfinit des opérateurs
- [ ] Tu as une opinion critique sur **quand** surcharger (ou pas)

---

## 💡 Pièges Courants

### 1. Oublier `roundf()`

```cpp
// ❌ MAUVAIS
Fixed::Fixed(float value) : _fixedPoint(value * 256) {}
// Peut causer des erreurs d'arrondi subtiles

// ✅ BON
Fixed::Fixed(float value) : _fixedPoint(roundf(value * 256)) {}
```

### 2. Division entière au lieu de flottante

```cpp
// ❌ MAUVAIS
float toFloat() const {
    return _fixedPoint / 256;  // Division entière ! (retourne int)
}

// ✅ BON
float toFloat() const {
    return _fixedPoint / 256.0f;  // Division flottante
}
```

### 3. `operator<<` en méthode membre

```cpp
// ❌ MAUVAIS (dans la classe)
std::ostream& operator<<(std::ostream& os) { ... }

// ✅ BON (hors de la classe)
std::ostream& operator<<(std::ostream& os, Fixed const& fixed) { ... }
```

### 4. Ne pas retourner le flux

```cpp
// ❌ MAUVAIS
void operator<<(std::ostream& os, Fixed const& fixed) {
    os << fixed.toFloat();
    // Pas de return = pas de chaînage !
}

// ✅ BON
std::ostream& operator<<(std::ostream& os, Fixed const& fixed) {
    os << fixed.toFloat();
    return os;  // Permet : cout << a << b << c
}
```

---

## 🧮 Mini-exercices de compréhension

**Sans compiler, réponds mentalement :**

1. Si `_fixedPoint = 512`, quelle est la valeur réelle ?

   - **Réponse :** `512 / 256 = 2.0`

2. Si je veux stocker `10.5`, que vaut `_fixedPoint` ?

   - **Réponse :** `10.5 × 256 = 2688`

3. Pourquoi `42.42f` devient `42.4219` ?

   - **Réponse :** Perte de précision due aux 8 bits fractionnaires (256 niveaux discrets)

4. Que vaut `Fixed(42).toFloat()` ?

   - **Réponse :** `42.0` (pas de partie décimale)

5. `value << 8` est équivalent à quoi pour les `int` ?

   - **Réponse :** `value * 256`

6. Pourquoi utiliser `* 256` pour les `float` ?
   - **Réponse :** Les floats ne supportent pas l'opérateur `<<` (bitwise)

---

## 🚀 Pour la suite (ex02)

**Tu vas ajouter :**

- 6 opérateurs de comparaison (`>`, `<`, `>=`, `<=`, `==`, `!=`)
- 4 opérateurs arithmétiques (`+`, `-`, `*`, `/`)
- 4 opérateurs d'incrémentation (`++a`, `a++`, `--a`, `a--`)
- Fonctions statiques `min()` et `max()`

**Avec tes nouvelles connaissances, tu pourras :**

```cpp
Fixed a(5.5f);
Fixed b(2.0f);

if (a > b) {
    Fixed c = a * b + Fixed(1);
    std::cout << "Result: " << c << std::endl;
}
```

**Tout ça sera possible grâce à la surcharge d'opérateurs !** 🎨

---

## 🎓 Récap Final (en 30 secondes)

1. **Fixed-point** = Stocker un décimal dans un `int` en multipliant par 256
2. **8 bits fractionnaires** = 2^8 = 256 niveaux de précision
3. **`<< 8` = `× 256`** pour les entiers uniquement (pas pour float)
4. **Conversions** : Utiliser `roundf()`, `/`, et décalages
5. **`operator<<`** = Fonction non-membre qui rend l'objet "affichable"
6. **Mot-clé `operator`** = Superpouvoir pour redéfinir +, -, \*, <<, etc.
7. **Utiliser avec sagesse** = Surcharge légitime pour types numériques, risqué ailleurs

**Tu maîtrises maintenant un type numérique custom performant et élégant !** 💪✨
