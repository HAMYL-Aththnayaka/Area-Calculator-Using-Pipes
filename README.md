# Area-Calculator-Using-Pipes
Area-Calculator-Using-Pipes and functions in Linux command terminal

# 🧮 Area Calculator using Pipes and Fork (C Language)

This project is a simple command-line based **area calculator** written in **C**, which demonstrates the use of **inter-process communication (IPC)** using `pipe()` and **process creation** using `fork()` in a Linux/UNIX environment.

It serves as a mini demonstration of **system-level programming concepts** such as:
- Parent-child process interaction
- Data exchange using pipes
- Handling user input in child processes
- Synchronization using `wait()`

---

## 📌 Features

- Calculate area of:
  - Circle
  - Triangle
  - Square
  - Rectangle
- Inter-process communication between parent and child using two unidirectional pipes
- Clean modular code structure with separate functions for each shape
- Demonstrates process synchronization using `wait()`

---

## 🔧 Technologies Used

- C Programming Language
- GCC Compiler
- System Calls: `pipe()`, `fork()`, `read()`, `write()`, `close()`, `wait()`

---

## 🧠 How It Works

- The **parent process** displays a menu and sends the user's shape choice to the **child process** via a pipe.
- The **child process** takes the necessary input (like radius, height, width), performs the calculation, and sends the result back to the parent via a second pipe.
- The **parent process** receives the result and displays it to the user.

---

## 🖥️ Sample Output

Please Choose What You Want to Calculate :
:: Options ::
1 : Calculate a Circle's Area
2 : Calculate a Triangle's Area
3 : Calculate a Square's Area
4 : Calculate a Rectangle's Area
1
Please Enter the Radius :
5
The Results Are : 78.500000

yaml
Copy
Edit

---

## 🚀 How to Compile & Run

Make sure you are using a UNIX/Linux environment with `gcc` installed.

### 🔨 Compile:
```bash
gcc -o area_calculator area_calculator.c
```

