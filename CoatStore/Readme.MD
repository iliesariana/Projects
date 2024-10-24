# Trench Coats Shop Management System

## Description

The Trench Coats Shop Management System is a GUI application designed for managing an inventory of trench coats. This application allows users to view, add, and manipulate coat data, offering both administrative and user modes. Users can choose to save data in CSV or HTML formats and visualize coat information through charts.

## Features

- **User and Admin Modes**: Toggle between user and admin functionalities to access different features.
- **Data Management**: Save coat data in CSV or HTML file formats.
- **Data Visualization**: Generate charts that represent coat color distribution.
- **Dynamic Table View**: View coats in a tabular format with the ability to add new entries.

## Technologies Used

- C++
- Qt Framework (for GUI development)
- CMake (for build management)
- Standard Template Library (STL)

## Project Structure

. ├── src/ │ ├── GUI.cpp # Main GUI class implementation │ ├── GUI.h # Header for GUI class │ ├── TableMode.cpp # Table view model for coats │ ├── TableMode.h # Header for TableMode class │ ├── UserGui.cpp # User interface for user mode │ ├── UserGui.h # Header for UserGui class │ ├── AdminGui.cpp # User interface for admin mode │ ├── AdminGui.h # Header for AdminGui class │ ├── Service.cpp # Business logic and data management │ ├── Service.h # Header for Service class │ ├── Repository.h # Data repository for coat data └── CMakeLists.txt # CMake build configuration
