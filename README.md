# 📦 Inventory Management System (inv_1)

A desktop-based Inventory Management System built with **C++17**, **Qt (Qt 5 / Qt 6)**, and **CMake**. This application provides an intuitive graphical interface for tracking stock levels, categorizing products, updating inventory records in real-time, and importing/exporting data via CSV files.

---

## 📑 Table of Contents

- [Overview](#-overview)
- [Features](#-features)
  - [User Authentication & PIN Management](#user-authentication--pin-management)
  - [Inventory Dashboard](#inventory-dashboard)
  - [Product Categorization](#product-categorization)
  - [Data Persistence](#data-persistence-csv-support)
  - [In-App Tutorial & Help](#in-app-tutorial--help)
- [Tech Stack & Prerequisites](#️-tech-stack--prerequisites)
- [Project Structure](#-project-structure)
- [Building and Running](#️-building-and-running)
  - [Option 1: Using Qt Creator (Recommended)](#option-1-using-qt-creator-recommended)
  - [Option 2: Using CMake Command Line](#option-2-using-cmake-command-line)
- [How to Use](#-how-to-use)
- [CSV Format](#-csv-format)
- [Contributing](#-contributing)
- [License](#-license)

---

## 🔍 Overview

The **Inventory Management System** is designed for small to medium retail operations, personal asset tracking, or academic demonstration. It includes robust input validation, real-time item editing, duplicate detection with automatic quantity updates, and full offline persistence via CSV.

[⬆ Back to Top](#-table-of-contents)

---

## 🚀 Features

### User Authentication & PIN Management
- Simple login system with username support and numeric PIN protection.
- Default PIN: `1234`
- Built-in PIN reset / recovery option directly within the tutorial dialog.

### Inventory Dashboard
- Add new products with item name, quantity, unit price, and category.
- **Automatic merging:** Adding an existing item name updates its quantity and refreshes the timestamp automatically.
- Edit existing entries or remove obsolete inventory rows with confirmation safeguards.
- View comprehensive item details via dedicated row action popups.
- Automatically records the last modified timestamp (`yyyy-MM-dd hh:mm`).

### Product Categorization
- Built-in categories: 💡 *Electronics*, 🍗 *Food*, 👕 *Clothing*, ✏️ *Stationery*, and *Other*.

### Data Persistence (CSV Support)
- **Export / Save:** Save current inventory records to standard `.csv` format.
- **Import / Load:** Load inventory records seamlessly from existing CSV files.

### In-App Tutorial & Help
- Built-in guide explaining operations and buttons.

[⬆ Back to Top](#-table-of-contents)

---

## 🛠️ Tech Stack & Prerequisites

- **Language:** C++17
- **Framework:** Qt 6 (or Qt 5.15+) Widgets (`QtWidgets`)
- **Build System:** CMake (>= 3.16)
- **Supported Platforms:** Windows, macOS, Linux
- **IDE:** Qt Creator / Visual Studio 2022 / VS Code (with CMake Tools)

[⬆ Back to Top](#-table-of-contents)

---

## 📁 Project Structure

Click any file link below to view its source code in this repository:

| File | Description |
| :--- | :--- |
| [CMakeLists.txt](CMakeLists.txt) | CMake build definitions and Qt module linking |
| [main.cpp](main.cpp) | Application entry point and lifecycle manager |
| [login.h](login.h) / [login.cpp](login.cpp) | User authentication logic and credential verification |
| [login.ui](login.ui) | Qt Designer layout for the Login window |
| [mainwindow.h](mainwindow.h) / [mainwindow.cpp](mainwindow.cpp) | Core inventory dashboard logic, array data model & CSV I/O |
| [mainwindow.ui](mainwindow.ui) | Qt Designer layout for the Inventory table and input controls |
| [tutorial.h](tutorial.h) / [tutorial.cpp](tutorial.cpp) | Tutorial view and PIN update / reset implementation |
| [tutorial.ui](tutorial.ui) | Qt Designer layout for the Tutorial/Help dialog |
| [.gitignore](.gitignore) | Excludes build artifacts, binaries, and temporary files from git |

[⬆ Back to Top](#-table-of-contents)

---

## ⚙️ Building and Running

### Option 1: Using Qt Creator (Recommended)

1. Open **Qt Creator**.
2. Select **File** > **Open File or Project...** and choose [`CMakeLists.txt`](CMakeLists.txt).
3. Choose your configured Qt kit (e.g., *Desktop Qt 6.x.x MSVC 64-bit* or *MinGW*).
4. Click **Configure Project**.
5. Press `Ctrl + R` (or the green **Run** button) to build and launch.

### Option 2: Using CMake Command Line

Make sure CMake, your C++ compiler (MSVC / GCC / Clang), and Qt binaries are in your environment `PATH`.

```bash
# 1. Clone the repository
git clone https://github.com/lejh-02/assignment.git
cd assignment

# 2. Generate build files
cmake -B build -S . -DCMAKE_BUILD_TYPE=Release

# 3. Build the executable
cmake --build build --config Release

# 4. Run the executable
# On Windows:
./build/Release/inv_1.exe
# On Linux / macOS:
./build/inv_1
```

[⬆ Back to Top](#-table-of-contents)

---

## 📖 How to Use
Install the exe2 zip file , unzip and run the inv_1.exe file 

1. **Log in**:
   - Enter any **Username**.
   - Enter the default PIN: `1234`.
   - Click **Login** to enter the inventory dashboard.
2. **Add Products**:
   - Fill in *Name*, *Quantity*, *Price*, and select a *Category*.
   - Click **Add**. If the item already exists, its quantity will be incremented automatically.
3. **Edit / Delete Products**:
   - Enter the row number (1-indexed) in the Row field.
   - Click **Edit** after updating fields, or click **Remove** to delete the row.
4. **Export / Import CSV**:
   - Click **Save** to export your inventory table to a `.csv` file.
   - Click **Load** to import and populate existing inventory from a `.csv` file.

[⬆ Back to Top](#-table-of-contents)

---

## 📄 CSV Format

The exported and imported CSV files follow this structure:

```csv
ItemName,Quantity,Price,Category,LastUpdated
Laptop,10,899.99,💡Electronics,2026-10-18 21:30
T-Shirt,50,15.50,👕Clothing,2026-10-18 21:32
```

[⬆ Back to Top](#-table-of-contents)

---

## 🤝 Contributing

Contributions, issues, and feature requests are welcome!

1. Fork the Project
2. Create your Feature Branch (`git checkout -b feature/AmazingFeature`)
3. Commit your Changes (`git commit -m 'Add some AmazingFeature'`)
4. Push to the Branch (`git push origin feature/AmazingFeature`)
5. Open a Pull Request

[⬆ Back to Top](#-table-of-contents)

---

## 📜 License

This project is licensed under the [MIT License](LICENSE) 

[⬆ Back to Top](#-table-of-contents)
