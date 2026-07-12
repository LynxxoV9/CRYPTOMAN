# 🔐 CRYPTOMAN

**CRYPTOMAN** est un programme de chiffrement asymétrique développé en **langage C** à l'aide de la bibliothèque **OpenSSL** dans le cadre d'un projet académique. Il permet de générer une paire de clés RSA, de chiffrer un message avec une clé publique et de le déchiffrer avec la clé privée correspondante.
Licence 3 - Sécurité Informatique - Cybersécurité et Cybercriminalité
Ecole Supérieure des Affaires - ESA Togo

---

## Fonctionnalités

- Génération automatique d'une paire de clés RSA (2048 bits)
- Chiffrement d'un message avec la clé publique
- Déchiffrement du message avec la clé privée
- Sauvegarde des clés au format PEM
- Interface simple en ligne de commande

---

## 🛠️ Technologies utilisées

- **Langage :** C
- **Bibliothèque cryptographique :** OpenSSL

---

## Structure du projet

```
CRYPTOMAN/
│── crypto.c
│── public.pem
│── private.pem
│── encrypted.bin
└── README.md
```

---

## Installation

Installer la bibliothèque OpenSSL :

```bash
sudo apt install libssl-dev
```

Compiler le programme :

```bash
gcc cryptoman.c -o cryptme -lcrypto
```

Exécuter le programme :

```bash
./cryptme
```

---

## 🚀 Utilisation

Au lancement, le programme affiche le menu suivant :

```
1. Générer les clés
2. Chiffrer un message
3. Déchiffrer un message
4. Quitter
```

### Génération des clés

Cette option génère deux fichiers :

- `public.pem` : Clé publique utilisée pour le chiffrement.
- `private.pem` : Clé privée utilisée pour le déchiffrement.

### Chiffrement

Le programme chiffre un message à l'aide de la clé publique et enregistre le résultat dans :

```
encrypted.bin
```

### Déchiffrement

Le programme lit le fichier `encrypted.bin` puis restaure le message original grâce à la clé privée.

---

## 🔐 Principe de fonctionnement

```
Message clair
      │
      ▼
Clé publique
      │
      ▼
Message chiffré
      │
      ▼
Clé privée
      │
      ▼
Message original
```

---

## 👥 Membres du groupe 1

- FIABI Kokou Olivier
- DJIBU Nahum Davies
- MOUSSA Larba Falila
- MANGAMANA François
- SEBLE Hermann
- AFO Houdou

---

## 📚 Bibliothèque utilisée

Le projet utilise **OpenSSL** pour assurer les opérations cryptographiques (génération des clés RSA, chiffrement et déchiffrement).

---

## 📄 Licence

Projet académique réalisé dans le cadre d'un travail de recherche.
