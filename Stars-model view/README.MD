# Celestial Information Management System

This project is a **Celestial Information Management System** designed with **Model-View architecture** in C++ and featuring a **Graphical User Interface (GUI)** built using **Qt**. The application manages information about stars and astronauts, including data about star positions and constellation associations. Users can view, filter, and add information about celestial objects through a responsive and interactive interface.

## Key Features

### 1. Model-View Architecture
   - The application follows the **Model-View architecture** pattern, which separates the data handling logic (Model) from the user interface (View). This structure improves the modularity, scalability, and testability of the code.
   - **Models** represent the data: `Star` and `Astronaut` classes define the data structure for celestial entities, while `starsModel` and `StarFilterModel` classes manage data display.
   - **Views** are Qt-based widgets that present and manage interactions with data, such as tables for displaying lists of stars and astronauts.

### 2. Qt Framework for GUI
   - The project’s GUI is built with **Qt**, offering a responsive, user-friendly interface that enables users to manage celestial information.
   - Users can interact with various Qt widgets, including `QTableView`, `QListWidget`, and custom widgets like the `Drawing` class to visualize stars in constellations.
   - **Event Handling**: Qt handles various events like button clicks, input field changes, and checkbox states, providing a dynamic and intuitive user experience.

### 3. Dynamic Filtering and Search
   - The application allows users to filter stars by constellation and search by name. The `StarFilterModel` class efficiently filters star data based on user input and checkboxes.
   - This filtering capability is seamlessly integrated with the GUI using Qt’s `QCheckBox` and `QLineEdit` widgets.

### 4. Custom Star Visualization
   - Using the **`QPainter` class**, the program provides a visual representation of constellations. The `Drawing` class renders an ellipse for each star, with size and color representing different star attributes.
   - This visualization enhances the user experience by providing a spatial perspective of stars within constellations.

## Project Structure

### 1. Core Data Classes
   - `Astronaut`: Defines astronaut data with attributes such as `name` and `constellation`.
   - `Star`: Defines star data, including `name`, `constellation`, right ascension (`ra`), and declination (`dec`).

### 2. Repository and Service Layer
   - `Repository`: Manages loading and storing data from text files (`stars.txt` and `astronauts.txt`). Methods are provided to filter and retrieve stars by constellation or name.
   - `Service`: Acts as an intermediary between the GUI and Repository, handling higher-level business logic such as adding new stars or retrieving filtered lists.

### 3. GUI and Models
   - `gui`: The main graphical interface, providing access to tables, buttons, and input fields for interacting with star and astronaut data.
   - `starsModel`: Implements Qt's `QAbstractTableModel`, providing a structured view of star data for tables.
   - `StarFilterModel`: Extends `QSortFilterProxyModel` to filter star data by constellation dynamically.

### 4. Main Function
   - The main entry point (`main.cpp`) initializes the Qt application and creates a window for each astronaut. Each window is bound to an astronaut, displaying only stars in their constellation.
   - Each window is an instance of the `gui` class, which connects to Qt's signal-slot mechanism for responsive interaction.

