# Programmazione I (Introduction to Programming)

**Author**: Francesco Ferrillo  
**Year**: First-year University Project  
**Description**: A collection of assignments and exercises from the first programming course, implemented in C and HTML/CSS.

## Table of Contents

- [Overview](#overview)  
- [Technologies](#technologies)  
- [Repository Structure](#repository-structure)  
- [Features / Modules](#features--modules)  
- [Getting Started](#getting-started)  
- [Compilation and Running (C programs)](#compilation-and-running-c-programs)  
- [Viewing HTML Files](#viewing-html-files)  
- [How to Contribute](#how-to-contribute)  
- [License](#license)  

## Overview

This project is intended as a portfolio of coursework done during the “Programmazione I” (Programming I) class. It demonstrates fundamental skills in procedural programming (using C), as well as basic web document creation (HTML + CSS). The repository includes small projects, exercises, lab assignments, and documentation.

## Technologies

- **C** — for console / command‑line based programming tasks  
- **HTML / CSS** — for web document / presentation tasks  
- (Optionally) any shell / make tools for compilation  

## Repository Structure

Below is a rough outline of how this repository is organized:

```
/
├── Progetto/                  # Main project folder(s) in C
├── documenti_html/            # HTML and CSS files for web tasks
│   └── IDEX.html              # Example HTML file
├── Pr_Ferrillo_Francesco.pdf  # Documentation / writeups in PDF
└── README.md                  # (this file)
```

- **Progetto/** likely contains the C source (.c) and header (.h) files, plus test files  
- **documenti_html/** contains web pages or HTML assignments  
- **Pr_Ferrillo_Francesco.pdf** is a report or documentation file detailing the project goals, design decisions, usage, etc.

## Features / Modules

Each module or assignment in the “Progetto” folder typically addresses one specific problem or topic from the course, such as:

- Basic I/O and arithmetic operations  
- Control structures: conditionals, loops  
- Functions and modularization  
- Arrays, strings, pointers  
- File input/output  
- (Possibly) data structures & algorithms (depending on course)  

The `documenti_html` folder may contain a static HTML demonstration (e.g. **IDEX.html**) that illustrates concepts of web structure, styling, and layout.

## Getting Started

To explore or run this project on your local machine:

1. **Clone the repository**
   ```bash
   git clone https://github.com/FrancescoFerrillo/Programmazione-I.git
   cd Programmazione-I
   ```

2. **Browse the HTML files**  
   Open `documenti_html/IDEX.html` (or any HTML file) in a web browser to view it.

3. **Compile and run C programs**  
   See next section for instructions.

## Compilation and Running (C programs)

To build and run a C module:

```bash
# Example if file is named example.c
gcc -o example example.c      # compile
./example                     # run (on Unix-like systems)
```

If there are multiple `.c` files or dependencies:

```bash
gcc -o myprogram file1.c file2.c …  
./myprogram
```

If you prefer, you can create a `Makefile` for easier builds (e.g. `make all`, `make clean`).

## Viewing HTML Files

Simply open the `.html` files (e.g. `documenti_html/IDEX.html`) in your browser. These files are static and do not require a web server to run (unless you later integrate dynamic content).
