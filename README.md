# LCA-Finder

This is a simple interactive website that allows users to input a binary tree in level-order format and two node values `p` and `q`, then find their **Lowest Common Ancestor** (LCA) using C++ logic.

---

## 📁 Project Structure

LCA-Binary-Tree/
├── index.html # Frontend structure (HTML)
├── style.css # Styling for the website
├── script.js # Handles user input and display (no logic)
├── main.cpp # C++ program that implements the LCA logic

##  How It Works

- The user inputs:
  - Binary Tree in **level-order** format (e.g., `3,5,1,6,2,0,8,null,null,7,4`)
  - Two nodes `p` and `q` for which the LCA needs to be found.
- The **frontend** collects input using simple JavaScript.
- The **LCA logic** is implemented in `main.cpp` using standard C++.
- You run the C++ program manually in the terminal with the same inputs.
