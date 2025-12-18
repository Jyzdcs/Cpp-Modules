# ex00 — Notes Essentielles (20%)

## 📑 Table des Matières

- [🎯 Objectif de l'exercice](#-objectif-de-lexercice)
- [📋 Les 4 Membres de l'OCF](#-les-4-membres-de-locf)
- [🔧 Implémentation Fixed](#-implémentation-fixed)
- [🏗️ Constructeurs](#️-constructeurs)
  - [1. Constructeur par défaut](#1-constructeur-par-défaut)
  - [2. Constructeur de copie](#2-constructeur-de-copie)
  - [3. Opérateur d'affectation](#3-opérateur-daffectation)
  - [4. Destructeur](#4-destructeur)
- [🔑 Concepts Clés](#-concepts-clés)
  - [`this` en C++](#this-en-c)
  - [Membres `static`](#membres-static)
  - [Fixed-Point : Raw vs Interprété](#fixed-point--raw-vs-interprété)
- [💡 Points de Confusion Courants](#-points-de-confusion-courants)
- [🎨 Visualisation : `b = a`](#-visualisation--b--a)
- [📝 Checklist Rapide](#-checklist-rapide)
- [🔗 Ressources](#-ressources)
- [🚀 Pour la suite](#-pour-la-suite)

---

## 🎯 Objectif de l'exercice

**Apprendre l'Orthodox Canonical Form (OCF) et observer le cycle de vie des objets.**

Ce n'est PAS un exercice technique (un int simple marcherait sans OCF), c'est un exercice de **DISCIPLINE** pour acquérir les bonnes pratiques avant d'attaquer des classes complexes.

---

## 📋 Les 4 Membres de l'OCF

| Membre                      | Rôle                                     | Quand appelé                    |
| --------------------------- | ---------------------------------------- | ------------------------------- |
| **Constructeur par défaut** | Créer instance vide                      | `Fixed a;`                      |
| **Constructeur de copie**   | Créer NOUVELLE instance depuis existante | `Fixed b = a;` ou `Fixed b(a);` |
| **Opérateur d'affectation** | REMPLACER contenu d'instance existante   | `b = a;` (b existe déjà)        |
| **Destructeur**             | Nettoyer avant destruction               | Sortie de scope                 |

### ⚠️ Différence clé : Copie vs Affectation

```cpp
Fixed a(10);

Fixed b = a;     // ← Constructeur de copie (b n'existe pas)
Fixed c(20);
c = a;           // ← Opérateur d'affectation (c existe déjà)
```

**Astuce :** Si `=` est à la **déclaration** → copy constructor. Sinon → operator=.

---

## 🔧 Implémentation Fixed

### Membres de la classe

```cpp
class Fixed {
private:
    int _fixedPoint;                      // Valeur raw (entier)
    static const int _fractionalBits = 8; // Constant (8 bits = 256)
};
```

**Pourquoi `_fractionalBits` est `static` ?**

- Appartient à la CLASSE (partagé par toutes les instances)
- Existe AVANT toute instance
- Ne peut PAS être dans l'initializer list du constructeur

---

## 🏗️ Constructeurs

### 1. Constructeur par défaut

```cpp
Fixed::Fixed() : _fixedPoint(0) {
    std::cout << "Default constructor called\n";
}
```

**Initializer list (`: _fixedPoint(0)`) est MEILLEUR que corps** :

- Initialise directement (pas construction + affectation)
- Obligatoire pour `const` membres et références
- Convention C++98/42

---

### 2. Constructeur de copie

```cpp
Fixed::Fixed(Fixed const& src) : _fixedPoint(src._fixedPoint) {
    std::cout << "Copy constructor called\n";
}
```

**Pourquoi `const&` ?**

- **`&`** (référence) : évite copie infinie (sans référence → récursion)
- **`const`** : protection (ne modifie pas la source) + accepte objets const/temporaires

**Rôle :** Créer un NOUVEL objet en copiant un existant.

---

### 3. Opérateur d'affectation

```cpp
Fixed& Fixed::operator=(Fixed const& rhs) {
    std::cout << "Copy assignment operator called\n";

    if (this != &rhs) {                      // Protection auto-affectation
        this->_fixedPoint = rhs._fixedPoint; // Copie la valeur
    }

    return *this;                            // Permet chaînage (a = b = c)
}
```

**Décortiqué :**

- **`rhs`** (Right-Hand Side) = l'objet à droite de `=` dans `b = a` (a est le rhs)
- **`this`** = pointeur vers objet courant (celui qui reçoit)
- **`*this`** = l'objet lui-même (déréférencement)
- **`return *this`** = retourne l'objet pour permettre `a = b = c`

**Protection `if (this != &rhs)` :**

- Détecte auto-affectation (`a = a`)
- Critique pour classes avec pointeurs (évite double-free)
- Discipline pour Fixed (même si pas nécessaire techniquement)

**Pourquoi "rhs" ?**

- Décrit le RÔLE (position dans `a = b`), pas la NATURE de Fixed
- Convention C++ universelle pour opérateurs binaires
- Tom Hanks (identité) vs Le héros (rôle dans le film)

---

### 4. Destructeur

```cpp
Fixed::~Fixed() {
    std::cout << "Destructor called\n";
}
```

**Rôle :** Nettoyer avant destruction (ici juste un message de debug).

---

## 🔑 Concepts Clés

### `this` en C++

**`this` = pointeur implicite vers l'objet courant**

En C++, `this->` est presque toujours OPTIONNEL (contrairement à Python `self` ou JS `this`) :

```cpp
void setValue(int val) {
    _fixedPoint = val;        // Implicite (préféré)
    this->_fixedPoint = val;  // Explicite (équivalent)
}
```

**Quand `this` est OBLIGATOIRE :**

1. `return *this` (retourner l'objet)
2. `if (this != &rhs)` (comparaison d'adresses)
3. Conflit de noms (paramètre = membre)

---

### Membres `static`

**`static` = appartient à la CLASSE, pas aux instances**

```cpp
class Fixed {
    int _fixedPoint;              // Chaque objet a SA copie
    static const int _fractionalBits = 8;  // UNE seule copie pour tous
};
```

**Pourquoi pas dans l'initializer list ?**

- Le constructeur crée des INSTANCES
- `static` existe AVANT toute instance
- Exception C++98 : `static const int` peut être initialisé dans le header

---

### Fixed-Point : Raw vs Interprété

**Integer literal 8** = le chiffre 8 écrit directement dans le code

**Raw value** = valeur brute stockée en mémoire (int non interprété)

```cpp
Valeur réelle : 10.5
Raw value     : 2688  (10.5 × 256 = 2688)

getRawBits()  → retourne 2688 (brut, pas de conversion)
toFloat()     → retourne 10.5  (2688 / 256.0)
```

---

## 💡 Points de Confusion Courants

### 1. `std::endl` vs `\n`

```cpp
std::cout << "Message" << std::endl;  // Newline + flush (plus lent)
std::cout << "Message\n";             // Juste newline (rapide)
```

**Recommandation :** Utilise `\n` par défaut, `std::endl` seulement si flush nécessaire.

---

### 2. Pourquoi l'OCF pour un simple `int` ?

**Raisons :**

1. **Pédagogie** : Observer quand chaque fonction est appelée
2. **Discipline** : Réflexe à acquérir (Rule of Three)
3. **Préparation** : ex01-ex03 construisent sur ces bases

Sans les messages de debug, tu ne verrais PAS le cycle de vie des objets !

---

### 3. Protection auto-affectation avec `int` ?

Pour Fixed (int simple), `if (this != &rhs)` n'est pas critique.

**Mais pour une classe avec pointeurs :**

```cpp
String& operator=(String const& rhs) {
    delete[] _data;              // ⚠️ Détruit mes données
    _data = new char[...];       // Si rhs = moi, CRASH !
    strcpy(_data, rhs._data);    // Copie depuis mémoire détruite
}
```

**Avec protection, `s = s` ne fait rien → pas de crash.**

C'est une DISCIPLINE à prendre, même quand ce n'est pas nécessaire.

---

## 🎨 Visualisation : `b = a`

```
Fixed a(10);  // a._fixedPoint = 10
Fixed b(20);  // b._fixedPoint = 20

b = a;  // Appelle b.operator=(a)

Dans operator= :
┌────────────────────────┐
│ this → pointe vers 'b' │ (0x2000)
│ rhs  → référence à 'a' │ (0x1000)
└────────────────────────┘

if (this != &rhs)           // 0x2000 != 0x1000 ? OUI
    this->_fixedPoint = rhs._fixedPoint;
    // b._fixedPoint = a._fixedPoint
    // 20 devient 10

return *this;  // Retourne b (pour chaînage)
```

**Résultat :** `b._fixedPoint = 10` (copié depuis a)

---

## 📝 Checklist Rapide

**Avant de compiler :**

- [ ] Les 4 membres OCF définis ?
- [ ] Initializer list pour constructeurs ?
- [ ] `const&` sur paramètres constructeur copie / operator= ?
- [ ] `if (this != &rhs)` dans operator= ?
- [ ] `return *this` dans operator= ?
- [ ] Messages de debug présents ?
- [ ] `static const int` initialisé dans header ?

---

## 🔗 Ressources

**Convention de nommage :**

- `src` pour constructeur de copie (source de la copie)
- `rhs` pour opérateurs (Right-Hand Side de l'opération)
- `this` pour l'objet courant (toujours implicite)

**Règle d'or (Rule of Three) :**
Si tu définis UN parmi (destructeur, copy constructor, operator=), définis LES TROIS.

---

## 🚀 Pour la suite

**ex01 :** Ajoute constructeurs `int`/`float` et conversions  
**ex02 :** Surcharge d'opérateurs (+, -, \*, /, ==, etc.)  
**ex03 :** Point avec membres `const` (plus complexe)

L'OCF reste la BASE, tu construis dessus ! 💪
