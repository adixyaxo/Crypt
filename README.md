# 🔐 Project Crypto
> **A High-Performance GUI Secret Code Generator & Decryptor built in C**

[![Language](https://img.shields.io/badge/Language-C-blue.svg)](https://en.wikipedia.org/wiki/C_(programming_language))
[![License: MIT](https://img.shields.io/badge/License-MIT-yellow.svg)](https://opensource.org/licenses/MIT)
[![Build Status](https://img.shields.io/badge/Build-Passing-brightgreen.svg)]()

## 📖 Overview

**Project Crypto** is a lightweight, high-efficiency desktop application written in **C**. It leverages low-level memory management to perform cryptographic operations with speed and precision. 

This tool allows users to encrypt and decrypt text using a **Keyword-based Polyalphabetic Substitution** method. With a custom Graphical User Interface (GUI), it abstracts the complexity of C cryptography behind a user-friendly design.

---

## ✨ Key Features

* **⚡ C-Powered Performance:** Built for speed and minimal resource consumption.
* **🖥️ Native GUI:** A clean visual interface to interact with the encryption engine.
* **🔑 Keyword Logic:** Messages are secured using a unique pass-phrase (key) provided by the user.
* **🎚️ 3 Difficulty Levels:**
    * **Level 1 (Basic):** Simple shifting algorithms.
    * **Level 2 (Intermediate):** Combined substitution methods.
    * **Level 3 (Advanced):** Complex multi-layer transformation for maximum security.
* **🔄 Two-Way Conversion:** Encrypt plaintext to ciphertext and decrypt it back instantly.

---

## 📸 Screenshots

![App Interface Placeholder](https://via.placeholder.com/800x400?text=C+Application+GUI+Screenshot)

---

## ⚙️ How It Works

The core C logic iterates through the input string and modifies the ASCII values based on the "Key" string provided.

### Example Scenario:
1.  **Input:** `Hello World`
2.  **Key:** `secret`
3.  **Mode:** Encrypt (Level 2)
4.  **Output:** `Jgnnq"Yqtnf` (Example obfuscation)

---

## 🛠️ Tech Stack

* **Language:** C (Standard C99 or C11)
* **GUI Library:** [Insert Library Here, e.g., GTK+ 3.0, Raylib, or Windows API]
* **Compiler:** GCC / Clang / MSVC

---

## 🚀 Installation & Build

### Prerequisites
Ensure you have a C compiler installed.
* **Windows:** MinGW or Visual Studio
* **Linux/macOS:** GCC or Clang

### 1. Clone the Repository
```bash
git clone [https://github.com/yourusername/project-crypto.git](https://github.com/yourusername/project-crypto.git)
cd project-crypto
